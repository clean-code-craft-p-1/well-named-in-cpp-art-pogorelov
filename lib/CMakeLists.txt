project(ColorCodes.Lib)

add_library(
        ${PROJECT_NAME}
        include/ColorCodes/Mapping.h
        include/ColorCodes/Types.h
        src/Mapping.cpp
        src/Utils.h)

target_include_directories(${PROJECT_NAME} PUBLIC include PRIVATE src include/ColorCodes)

enable_testing()
add_subdirectory(test)
