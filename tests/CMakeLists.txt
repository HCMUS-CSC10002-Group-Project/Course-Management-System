# Assuming this CMakeLists.txt is in the tests/ directory

# Specify the C++ standard, inheriting from the parent CMake settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include Google Test's headers
include_directories(runUnitTests PRIVATE ${PROJECT_SOURCE_DIR}/external/googletest/googletest/include)

# Organize test source files by subdirectories
file(GLOB DATA_STRUCTURES_TESTS ${PROJECT_SOURCE_DIR}/tests/data_structures/*.cpp)
file(GLOB ENTITIES_TESTS ${PROJECT_SOURCE_DIR}/tests/entities/*.cpp)
file(GLOB SERVICES_TESTS ${PROJECT_SOURCE_DIR}/tests/services/*.cpp)

# Define your test executable and list all the test source files
add_executable(
    runUnitTests 
    TestMain.cpp 
    ${DATA_STRUCTURES_TESTS}
    ${ENTITIES_TESTS}
    ${SERVICES_TESTS}
)

# Link the test executable against Google Test
target_link_libraries(runUnitTests PRIVATE entity_lib service_lib data_structures gtest gtest_main)

# Optionally, register your test executable with CTest
add_test(NAME AllTests COMMAND runUnitTests)
