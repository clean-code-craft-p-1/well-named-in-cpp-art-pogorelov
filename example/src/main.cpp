// Copyright(c), Philips Medical Systems Nederland B.V., IGT-Devices

#include <ColorCodes/Mapping.h>
#include <ColorCodes/Types.h>

#include <format>
#include <iostream>

void printColorPairInfo(const auto number)
{
    const auto colorPair = ColorCodes::colorPair(number);
    if (!colorPair)
    {
        constexpr auto kMessage = "Invalid color pair number: {}\n Manual:\n{}";
        std::cerr << std::format(kMessage, number, ColorCodes::printManual());
        return;
    }
    const auto name = ColorCodes::name(*colorPair);
    std::cout << std::format("Mapping: color pair number {} is [{}]\n", number, name);

    const auto result = ColorCodes::number(*colorPair);
    std::cout << std::format("Backwards mapping: color pair [{}] is number {}\n", name, result);
}

int main()
{
    constexpr auto kValidNumber   = 23;
    constexpr auto kInvalidNumber = 29;
    printColorPairInfo(kValidNumber);
    printColorPairInfo(kInvalidNumber);
    return 0;
}
