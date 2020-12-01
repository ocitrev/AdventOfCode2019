#pragma once
#include <algorithm>
#include <numeric>
#include <vector>

template <typename T>
inline auto insert_sorted(std::vector<T> &container, T const &item)
{
    auto hint = std::lower_bound(begin(container), end(container), item);

    if (hint == end(container) || item < *hint)
    {
        return std::make_pair(container.insert(hint, item), true);
    }

    return std::make_pair(hint, false);
}

template <typename T>
inline auto insert_sorted(std::vector<T> &container, T &&item)
{
    auto hint = std::lower_bound(begin(container), end(container), item);

    if (hint == end(container) || item < *hint)
    {
        return std::make_pair(container.insert(hint, std::move(item)), true);
    }

    return std::make_pair(hint, false);
}

template <typename T, typename FuncT>
inline void CombinationsWithReplacement(std::vector<T> const &list, std::size_t length, FuncT &&func)
{
    std::size_t const nb = list.size();

    if (length > nb)
        return;

    std::vector<T> values(length);
    std::vector<std::size_t> indices(length);

    for (std::size_t i = 0; i < length; ++i)
        values[i] = list[indices[i]];

    func(values);

    while (true)
    {
        std::size_t i = length - 1;
        for (; i < length; --i)
        {
            if (indices[i] != nb - 1)
                break;
        }

        if (i > length)
            return;

        std::size_t const nextIdx = indices[i] + 1;
        for (std::size_t j = i; j < length; ++j)
        {
            indices[j] = nextIdx;
            values[j] = list[nextIdx];
        }

        func(values);
    }
}

template <typename IterT, typename FuncT>
inline bool Combinations(IterT first, IterT last, std::size_t length, FuncT &&func)
{
    auto const nb = static_cast<std::size_t>(std::distance(first, last));

    if (length > nb)
        return true;

    std::vector<std::decay_t<decltype(*first)>> values(length);
    std::vector<std::size_t> indices(length);
    std::iota(begin(indices), end(indices), 0);

    for (std::size_t i = 0; i < length; ++i)
        values[i] = *std::next(first, static_cast<std::ptrdiff_t>(i));

    if (not func(values))
        return false;

    while (true)
    {
        std::size_t i = length - 1;
        for (; i < length; --i)
        {
            if (indices[i] != i + nb - length)
                break;
        }

        if (i > length)
            break;

        indices[i] += 1;
        values[i] = *std::next(first, static_cast<std::ptrdiff_t>(indices[i]));

        for (std::size_t j = i + 1; j < length; ++j)
        {
            auto const newIdx = indices[j - 1] + 1;
            indices[j] = newIdx;
            values[j] = *std::next(first, static_cast<std::ptrdiff_t>(newIdx));
        }

        if (not func(values))
            return false;
    }

    return true;
}

template <typename ContainerT, typename FuncT>
inline bool Combinations(ContainerT const &container, std::size_t length, FuncT &&func)
{
    return Combinations(begin(container), end(container), length, std::forward<FuncT>(func));
}

// https://stackoverflow.com/questions/9028250/generating-all-permutations-excluding-cyclic-rotations
// https://stackoverflow.com/questions/960557/how-to-generate-permutations-of-a-list-without-reverse-duplicates-in-python-us
// http://www.cis.uoguelph.ca/~sawada/papers/alph.pdf
template <typename IterT>
inline bool next_necklace(IterT first, IterT last)
{
    auto const n = std::next(first);
    return std::next_permutation(n, last) && *n <= *std::prev(last);
}
