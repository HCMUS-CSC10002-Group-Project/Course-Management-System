# Assuming this CMakeLists.txt is in the tests/ directory

# Specify the C++ standard, inheriting from the parent CMake settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define your test executable and list all the test source files
add_executable(runUnitTests TestMain.cpp DynamicArrayTest.cpp LinkedListTest.cpp DoublyLinkedListTest.cpp StackTest.cpp QueueTest.cpp)

# Include Google Test's headers
target_include_directories(runUnitTests PRIVATE
    ${PROJECT_SOURCE_DIR}/external/googletest/googletest/include
)

# Include the directory where your DynamicArray.h and DynamicArrayImpl.h are located
target_include_directories(runUnitTests PRIVATE
    ${PROJECT_SOURCE_DIR}/src/data_structures  # Adjust this path as necessary
)

# Link the test executable against Google Test
target_link_libraries(runUnitTests gtest gtest_main)

# Optionally, register your test executable with CTest
add_test(NAME AllTests COMMAND runUnitTests)
