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

} // namespace ColorCodes::Utils
