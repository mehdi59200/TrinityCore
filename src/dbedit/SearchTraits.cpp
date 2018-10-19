#include "SearchTraits.h"
#include "advstd.h"
#include "DBCStructure.h"
#include "Log.h"
#include "SpellAccessor.h"
#include <cstring>
#include <sstream>

enum Operators  // we only need positive operators - you can always invert with prefixed !
{               // SEQUENCE         TRUE IFF
    OP_EQUAL,   //  =               val == needle
    OP_BANDEQ,  //  &=              val & needle == needle
    OP_BANDNZ,  //  &               val & needle != 0
    OP_LT,      //  <               val < needle
    OP_GT,      //  >               val > needle
    OP_LEQ,     // <=               val <= needle
    OP_GEQ      // >=               val >= needle
};

template <typename I>
bool IntegerCheckOp(Operators op, I val, I needle)
{
    switch (op)
    {
        case OP_EQUAL:
            return (val == needle);
        case OP_BANDEQ:
            return (val & needle) == needle;
        case OP_BANDNZ:
            return (val & needle) != 0;
        case OP_LT:
            return (val < needle);
        case OP_GT:
            return (val > needle);
        case OP_LEQ:
            return (val <= needle);
        case OP_GEQ:
            return (val >= needle);
        default:
            ASSERT(false);
            return false;
    }
}

struct Operation
{
    Operation(bool invert, Operators op) : Inverted(invert), Operator(op) {}
    bool const Inverted;
    Operators const Operator;
};

static Operators stripOperator(char const*& needle)
{
    ASSERT(*needle);
    switch (*(needle++))
    {
        case '=':
            return OP_EQUAL;
        case '&':
            if (*needle == '=')
            {
                ++needle;
                return OP_BANDEQ;
            }
            return OP_BANDNZ;
        case '<':
            if (*needle == '=')
            {
                ++needle;
                return OP_LEQ;
            }
            return OP_LT;
        case '>':
            if (*needle == '=')
            {
                ++needle;
                return OP_GEQ;
            }
            return OP_GT;
        default:
            --needle;
            return OP_EQUAL;
    }
}

static Operation stripPrefix(char const*& needle)
{
    bool invert;
    if ((invert = (*needle == '!')))
        ++needle;
    return { invert, stripOperator(needle) };
}

template <typename I>
static inline std::enable_if_t<std::is_unsigned_v<I>, bool> parseStringAs(char const* needle, I& value)
{
    char* ptr;
    value = std::strtoumax(needle, &ptr, 0);
    return (ptr != needle);
}

template <typename I>
static inline std::enable_if_t<std::is_signed_v<I>, bool> parseStringAs(char const* needle, I& value)
{
    char* ptr;
    value = std::strtoimax(needle, &ptr, 0);
    return (ptr != needle);
}

template <typename I>
static bool IntegerCheck(char const* needle, I value)
{
    static_assert(advstd::is_integral_v<I>, "IntegerCheck must be passed integral value");

    Operation op = stripPrefix(needle);

    I needleI;
    if (!parseStringAs<I>(needle, needleI))
    {
        TC_LOG_WARN("dbedit", "Invalid search needle '%s' for integral label ignored", needle);
        return false;
    }

    return IntegerCheckOp(op.Operator, value, needleI) != op.Inverted;
}

static inline void UnknownLabelWarn(char const* label) { TC_LOG_WARN("Unknown label '%s' ignored", label); }

bool SearchTraits<SpellEntry const*, void>::CheckLabel(SpellEntry const* obj, char const* label, char const* needle)
{
    ASSERT(obj && needle);
    if (!label)
        return StringContainsStringI(obj->SpellName[0], needle);

    if (!stricmp(label, "id"))
        return IntegerCheck(needle, obj->Id);
    if (!stricmp(label, "powertype"))
        return StringContainsStringI(EnumUtils<Powers>::ToTitle(Powers(obj->powerType)), needle);

    UnknownLabelWarn(label);
    return false;
}

bool SearchTraits<SpellEntry const*, void>::CheckLabel(uint32 spellId, char const* label, char const* needle)
{
    if (SpellEntry const* entry = SpellAccessor::GetDBSpellEntry(spellId))
        if (CheckLabel(entry, label, needle))
            return true;
    if (SpellEntry const* entry = SpellAccessor::GetDBCSpellEntry(spellId))
        if (CheckLabel(entry, label, needle))
            return true;
    return false;
}

bool SearchTraits<SpellFamilyNames, void>::CheckLabel(SpellFamilyNames v, char const* label, char const* needle)
{
    ASSERT(needle);
    if (!label)
        return StringContainsStringI(EnumUtils<SpellFamilyNames>::ToTitle(v), needle);

    UnknownLabelWarn(label);
    return false;
}

bool SearchTraits<Powers, void>::CheckLabel(Powers v, char const* label, char const* needle)
{
    if (!label)
        return StringContainsStringI(EnumUtils<Powers>::ToTitle(v), needle);

    UnknownLabelWarn(label);
    return false;
}

uint32 SearchTraits<SpellRuneCostEntry const*, void>::ToKey(SpellRuneCostEntry const* entry) { return entry->ID; }

std::string SearchTraits<SpellRuneCostEntry const*, void>::GetTitle(SpellRuneCostEntry const* entry)
{
    if (!entry)
        return "<none>";
    std::stringstream v;
    if (entry->NoRuneCost())
        v << "<no runes>";
    else
    {
        if (uint32 blood = entry->RuneCost[0])
            v << blood << " blood, ";
        if (uint32 frost = entry->RuneCost[1])
            v << frost << " frost, ";
        if (uint32 unholy = entry->RuneCost[2])
            v << unholy << " unholy, ";
        v.seekp(-2, std::ios_base::end); // overwrite trailing ', '
    }

    v << " (+" << entry->runePowerGain << " RP)";
    return v.str();
}

bool SearchTraits<SpellRuneCostEntry const*, void>::CheckLabel(SpellRuneCostEntry const* entry, char const* label, char const* needle)
{
    if (!label)
        return StringContainsStringI(GetTitle(entry), needle);
    if (*label == 'b' || *label == 'B')
        return IntegerCheck(needle, entry->RuneCost[0]);
    if (*label == 'f' || *label == 'F')
        return IntegerCheck(needle, entry->RuneCost[1]);
    if (*label == 'u' || *label == 'U')
        return IntegerCheck(needle, entry->RuneCost[2]);
    if (*label == 'r' || *label == 'R')
        return IntegerCheck(needle, entry->runePowerGain);

    UnknownLabelWarn(label);
    return false;
}


