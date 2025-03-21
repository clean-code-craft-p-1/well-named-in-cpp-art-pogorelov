#include <ColorCodes/Mapping.h>
#include <ColorCodes/Types.h>

#include <cstdint>
#include <gtest/gtest.h>

namespace ColorCodes::Test {

class MappingTest
    : public ::testing::TestWithParam<std::tuple<std::uint8_t, MajorColor, MinorColor>>
{
};

TEST_P(MappingTest, testNumberToPair)
{
    auto [pairNumber, expectedMajor, expectedMinor] = GetParam();

    const auto pair = colorPair(pairNumber);
    EXPECT_TRUE(pair.has_value());

    ASSERT_EQ(pair->major, expectedMajor);
    ASSERT_EQ(pair->minor, expectedMinor);
}

TEST_P(MappingTest, testPairToNumber)
{
    auto [expectedPairNumber, major, minor] = GetParam();

    const auto result = number(ColorPair{.major = major, .minor = minor});
    ASSERT_EQ(result, expectedPairNumber);
}

INSTANTIATE_TEST_SUITE_P(
    MappingTest,
    MappingTest,
    ::testing::Values(std::make_tuple(4, MajorColor::White, MinorColor::Brown),
                      std::make_tuple(5, MajorColor::White, MinorColor::Slate),
                      std::make_tuple(12, MajorColor::Black, MinorColor::Orange),
                      std::make_tuple(25, MajorColor::Violet, MinorColor::Slate)));

} // namespace ColorCodes::Test
