// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#pragma once

#include <Types.h>

#include <algorithm>
#include <array>
#include <cstdint>
#include <format>
#include <ranges>
#include <string_view>

namespace ColorCodes::Utils {

constexpr std::string_view toString(const MajorColor color) noexcept
{
    return kMajorColorNames[static_cast<std::size_t>(color)];
}

constexpr std::string_view toString(const MinorColor color) noexcept
{
    return kMinorColorNames[static_cast<std::size_t>(color)];
}

constexpr auto generateColorPairs()
{
    constexpr auto kMajorsNumber = kMajorColorNames.size();
    constexpr auto kMinorsNumber = kMinorColorNames.size();
    constexpr auto kPairsNumber  = kMajorsNumber * kMinorsNumber;
    constexpr auto majors        = std::views::iota(0U, kMajorsNumber);
    constexpr auto minors        = std::views::iota(0U, kMinorsNumber);
    auto           pairs         = std::array<ColorPair, kPairsNumber>{};
    auto           it            = pairs.begin();
    for (const auto major : majors)
    {
        for (const auto minor : minors)
        {
            *it = ColorPair{static_cast<MajorColor>(major), static_cast<MinorColor>(minor)};
            ++it;
        }
    }
    return pairs;
}

constexpr auto generateColorPairs2()
{
    constexpr auto kMajorsNumber = kMajorColorNames.size();
    constexpr auto kMinorsNumber = kMinorColorNames.size();
    constexpr auto kPairsNumber  = kMajorsNumber * kMinorsNumber;
    constexpr auto majors        = std::views::iota(0U, kMajorsNumber);
    constexpr auto minors        = std::views::iota(0U, kMinorsNumber);

    auto pairs = std::array<ColorPair, kPairsNumber>{};

    std::ranges::for_each(majors, [&](const auto major) {
        std::ranges::for_each(minors, [&](const auto minor) {
            pairs[major * kMinorsNumber + minor] = ColorPair{
                .major = static_cast<MajorColor>(major), .minor = static_cast<MinorColor>(minor)};
        });
    });

    return pairs;
}

constexpr auto generateColorPairs3()
{
    constexpr auto kMajorsNumber = kMajorColorNames.size();
    constexpr auto kMinorsNumber = kMinorColorNames.size();
    constexpr auto kPairsNumber  = kMajorsNumber * kMinorsNumber;
    constexpr auto majors        = std::views::iota(0U, kMajorsNumber);
    constexpr auto minors        = std::views::iota(0U, kMinorsNumber);

    auto pairs = std::array<ColorPair, kPairsNumber>{};
    auto it    = pairs.begin();

    std::ranges::for_each(majors, [&](const auto major) {
        auto transformed_minors =
            minors | std::views::transform([&](const auto minor) {
                return ColorPair{static_cast<MajorColor>(major), static_cast<MinorColor>(minor)};
            });

        it = std::ranges::copy(transformed_minors, it).out;
    });

    return pairs;
}

constexpr auto generateColorPairs4()
{
    constexpr auto kMajorsNumber = kMajorColorNames.size();
    constexpr auto kMinorsNumber = kMinorColorNames.size();
    constexpr auto kPairsNumber  = kMajorsNumber * kMinorsNumber;
    constexpr auto indices       = std::views::iota(0U, kPairsNumber);

    auto result = std::array<ColorPair, kPairsNumber>{};
    std::ranges::transform(indices, result.begin(), [](const auto index) {
        const auto major = index / kMinorsNumber;
        const auto minor = index % kMinorsNumber;
        return ColorPair{.major = static_cast<MajorColor>(major),
                         .minor = static_cast<MinorColor>(minor)};
    });
    return result;
}

} // namespace ColorCodes::Utils
