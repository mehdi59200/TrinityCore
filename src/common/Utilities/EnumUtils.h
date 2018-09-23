#ifndef TRINITY_ENUMUTILS_H
#define TRINITY_ENUMUTILS_H

#include "IteratorPair.h"

struct EnumText
{
    EnumText(char const* n = nullptr, char const* d = nullptr) : Name(n), Description(d && *d ? d : n) {}
    char const* const Name;
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
        static char const* ToName(E value) { return ToString(value).Name; }
        static char const* ToDescription(E value) { return ToString(value).Description; }
      
    private:
        static E begin();
        static E increment(E value);
        static E end();
};

#define ENUM_POSSIBLE_VALUE(v, d) case v: return { #v, d };

#endif
