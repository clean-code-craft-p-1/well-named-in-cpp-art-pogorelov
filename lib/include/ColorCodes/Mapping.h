// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#pragma once

#include "Types.h"

#include <cstdint>
#include <optional>
#include <string>

namespace ColorCodes {

[[nodiscard]] std::optional<ColorPair> colorPair(std::uint8_t number);
[[nodiscard]] std::uint8_t             number(const ColorPair& pair);
[[nodiscard]] std::string              name(const ColorPair& pair);
[[nodiscard]] std::string              printManual();
} // namespace ColorCodes
