#ifndef TRINITY_DBEDIT_SEARCHTRAITS_H
#define TRINITY_DBEDIT_SEARCHTRAITS_H

#include "Define.h"
#include <utility>

struct LabeledSearchTag
{
    LabeledSearchTag(char const* label, char const* needle) : Label(label), LabeledNeedle(needle) {}
    char const* Label;
    char const* LabeledNeedle;
};

struct SpellEntry;

template <typename T>
struct SearchTraitsTypes
{
    using KeyType = bool;
};

template <>
struct SearchTraitsTypes<SpellEntry const*>
{
    using KeyType = uint32;
};

template <typename T>
struct SearchTraits
{
    using KeyType = typename SearchTraitsTypes<T>::KeyType;
    static bool CheckLabel(T obj, char const* label, char const* needle);
    static bool CheckLabel(KeyType key, char const* label, char const* needle);
};

template <typename T, typename V>
bool KeyMatchesLabel(std::pair<typename SearchTraits<T>::KeyType, V> const& pair, LabeledSearchTag tag)
{
    return SearchTraits<T>::CheckLabel(pair.first, tag.Label, tag.LabeledNeedle);
}

#endif
