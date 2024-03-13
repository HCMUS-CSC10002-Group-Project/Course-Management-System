# Assuming this CMakeLists.txt is in the tests/ directory

# Specify the C++ standard, inheriting from the parent CMake settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define your test executable and list all the test source files
add_executable(runUnitTests test1.cpp)  # Adjust with your test files

# Include Google Test's headers
target_include_directories(runUnitTests PRIVATE
    ${PROJECT_SOURCE_DIR}/external/googletest/googletest/include
)

# Link the test executable against Google Test
target_link_libraries(runUnitTests gtest gtest_main)

# Optionally, register your test executable with CTest
add_test(NAME AllTests COMMAND runUnitTests)
