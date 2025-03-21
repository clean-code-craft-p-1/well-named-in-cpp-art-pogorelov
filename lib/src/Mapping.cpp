// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include "Utils.h"
#include <Mapping.h>
#include <numeric>

#include <optional>
#include <string>

namespace ColorCodes {

using Utils::generateColorPairs;
using Utils::toString;

namespace {
constexpr auto kColorPairs = generateColorPairs();
}

std::optional<ColorPair> colorPair(const std::uint8_t number)
{
    const auto index = number - 1;
    if (index >= kColorPairs.size()) return std::nullopt;

    return kColorPairs[index];
}

std::uint8_t number(const ColorPair& pair)
{
    const auto     major         = static_cast<std::uint8_t>(pair.major);
    const auto     minor         = static_cast<std::uint8_t>(pair.minor);
    constexpr auto kMinorsNumber = kMinorColorNames.size();
    return major * kMinorsNumber + minor + 1;
}

std::string name(const ColorPair& pair)
{
    return std::format("{} {}", toString(pair.major), toString(pair.minor));
}

std::string printManual()
{
    return std::accumulate(
        kColorPairs.begin(), kColorPairs.end(), std::string{}, [](auto&& manual, const auto& pair) {
            return std::format("{}{:2} : [{}]\n", manual, number(pair), name(pair));
        });
}

} // namespace ColorCodes
