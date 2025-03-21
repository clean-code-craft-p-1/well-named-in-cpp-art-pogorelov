// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#pragma once

#include <array>
#include <cstdint>

namespace ColorCodes {

enum class MajorColor : std::uint8_t
{
    White = 0,
    Red,
    Black,
    Yellow,
    Violet
};

enum class MinorColor : std::uint8_t
{
    Blue = 0,
    Orange,
    Green,
    Brown,
    Slate
};

struct ColorPair
{
    MajorColor major;
    MinorColor minor;
};

constexpr auto kMajorColorNames = std::array{"White", "Red", "Black", "Yellow", "Violet"};
constexpr auto kMinorColorNames = std::array{"Blue", "Orange", "Green", "Brown", "Slate"};

} // namespace ColorCodes
