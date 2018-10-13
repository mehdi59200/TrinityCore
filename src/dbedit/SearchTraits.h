#ifndef TRINITY_DBEDIT_SEARCHTRAITS_H
#define TRINITY_DBEDIT_SEARCHTRAITS_H

#include "advstd.h"
#include "Define.h"
#include "EnumUtils.h"
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
    using KeyType = T;
};

template <>
struct SearchTraitsTypes<SpellEntry const*>
{
    using KeyType = uint32;
};

template <typename T, typename D = void> struct SearchTraitsIteration;

template <typename T>
struct SearchTraitsIteration<T, std::enable_if_t<advstd::is_enum_v<T>>>
{
    static auto Iterate() { return EnumUtils<T>::Iterate(); }
};

template <typename T>
struct SearchTraits
{
    using KeyType = typename SearchTraitsTypes<T>::KeyType;
    using AlternateKeyTypeIfExists = std::conditional_t<advstd::is_same_v<T, KeyType>, bool, KeyType>;

    template <bool C = advstd::is_enum_v<T> && advstd::is_same_v<KeyType, T>>
    static std::enable_if_t<!C, char const*> GetTitle(KeyType k);

    template <bool C = advstd::is_enum_v<T> && advstd::is_same_v<KeyType, T>>
    static std::enable_if_t<C, char const*> GetTitle(KeyType k) { return EnumUtils<T>::ToTitle(k); }

    static bool CheckLabel(T obj, char const* label, char const* needle);
    static bool CheckLabel(AlternateKeyTypeIfExists key, char const* label, char const* needle);
    static auto Iterate() { return SearchTraitsIteration<T>::Iterate(); }
};

template <typename T>
bool MatchesLabel(T val, LabeledSearchTag tag)
{
    return SearchTraits<T>::CheckLabel(val, tag.Label, tag.LabeledNeedle);
}

template <typename T>
bool KeyMatchesLabel(typename SearchTraits<T>::KeyType key, LabeledSearchTag tag)
{
    return SearchTraits<T>::CheckLabel(key, tag.Label, tag.LabeledNeedle);
}

template <typename T, typename V>
bool KeyMatchesLabel(std::pair<typename SearchTraits<T>::KeyType, V> const& pair, LabeledSearchTag tag)
{
    return SearchTraits<T>::CheckLabel(pair.first, tag.Label, tag.LabeledNeedle);
}

#endif
