/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITY_FUZZYFIND_H
#define TRINITY_FUZZYFIND_H

namespace Trinity
{
    namespace Containers
    {
        template <typename HayIterator, typename NeedleContainer, typename ContainsOperator>
        size_t FuzzyFindIn_CountMatched(HayIterator obj, NeedleContainer const& needles, ContainsOperator const& contains)
        {
            size_t c = 0;
            for (auto it = std::begin(needles), end = std::end(needles); it != end; ++it)
                if (contains(*obj, *it))
                    ++c;
            return c;
        }

        template <typename Container, typename NeedleContainer, typename ContainsOperator = bool(std::string const&, std::string const&), typename T = void>
        auto FuzzyFindIn(Container const& container, NeedleContainer const& needles, ContainsOperator const& contains = StringContainsStringI, int(*bonus)(T const*) = nullptr)
        {
            std::multimap<size_t, advstd::remove_cvref_t<decltype(*std::begin(container))> const*, std::greater<size_t>> results;

            for (auto it = std::begin(container), end = std::end(container); it != end; ++it)
            {
                size_t count = FuzzyFindIn_CountMatched(it, needles, contains);
                if (!count)
                    continue;

                if (bonus)
                    count += bonus(&*it);

                results.emplace(count, &*it);
            }

            return results;
        }

        template <typename HayIterator, typename Needles, typename ContainsOperator>
        size_t FuzzyFindInMulti_CountMatched(HayIterator it, Needles const& needles, ContainsOperator const& op)
        {
            return FuzzyFindIn_CountMatched(it, needles, op);
        }

        template <typename HayIterator, typename Needles, typename ContainsOperator, typename... Pairs>
        std::enable_if_t<sizeof...(Pairs) != 0, size_t> FuzzyFindInMulti_CountMatched(HayIterator it, Needles const& needles, ContainsOperator const& op, Pairs&&... tail)
        {
            return FuzzyFindInMulti_CountMatched(it, needles, op) + FuzzyFindInMulti_CountMatched(it, std::forward<Pairs>(tail)...);
        }

        template <typename Container, typename... Pairs>
        auto FuzzyFindInMulti(Container const& container, Pairs&&... pairs)
        {
            std::multimap<size_t, advstd::remove_cvref_t<decltype(*std::begin(container))> const*, std::greater<size_t>> results;

            for (auto it = std::begin(container), end = std::end(container); it != end; ++it)
            {
                size_t count = FuzzyFindInMulti_CountMatched(it, std::forward<Pairs>(pairs)...);
                if (count)
                    results.emplace(count, &*it);
            }

            return results;
        }
    }
}

#endif
