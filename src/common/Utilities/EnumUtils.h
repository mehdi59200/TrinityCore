#ifndef TRINITY_ENUMUTILS_H
#define TRINITY_ENUMUTILS_H

#include "IteratorPair.h"

struct EnumText
{
    explicit operator bool() { return !!Constant; }
    EnumText(nullptr_t) : Constant(nullptr), Title(nullptr), Description(nullptr) {}
    EnumText(char const* n, char const* t = nullptr, char const* d = nullptr) : Constant(n), Title(t ? t : n), Description(d ? d : Title) {}
    // Name of the value constant in the core
    char const* const Constant;
    // Human-readable title of the value
    char const* const Title;
    // Human-readable description of the value
    char const* const Description;
};

template <typename E>
class EnumUtils
{
    public:
        class iterator
        {
            public:
                iterator(E value) : _value(value) {}
                E operator*() const { return _value; }
                iterator& operator++() { _value = increment(_value); return *this; }
                iterator operator++(int) { iterator i(_value); operator++(); return i; }
                bool operator==(iterator other) { return _value == other._value; }
                bool operator!=(iterator other) { return _value != other._value; }
            private:
                E _value;
        };
        static Trinity::IteratorPair<iterator> Iterate() { return { iterator(begin()), iterator(end()) }; }
        static EnumText ToString(E value);
        static bool IsValue(E value) { return static_cast<bool>(ToString(value)); }
        static char const* ToConstant(E value) { return ToString(value).Constant; }
        static char const* ToTitle(E value) { return ToString(value).Title; }
        static char const* ToDescription(E value) { return ToString(value).Description; }
      
    private:
        static E begin();
        static E increment(E value);
        static E end();
};

#define ENUM_POSSIBLE_VALUE(v, ...) case v: return { #v , ##__VA_ARGS__ };

#endif
