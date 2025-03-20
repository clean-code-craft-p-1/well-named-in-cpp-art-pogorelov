project(ColorCodes.Example)

add_executable(
        ${PROJECT_NAME}
        src/main.cpp)

target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE ColorCodes.Lib)
