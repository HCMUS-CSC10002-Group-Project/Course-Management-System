cmake_minimum_required(VERSION 3.10)

# Set the project name and specify the C++ standard
project(CourseManagementSystem VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the main ImGui source files
file(GLOB IMGUI_SOURCES 
    ${PROJECT_SOURCE_DIR}/external/imgui/*.cpp
    ${PROJECT_SOURCE_DIR}/external/imgui/backends/imgui_impl_glfw.cpp
    ${PROJECT_SOURCE_DIR}/external/imgui/backends/imgui_impl_opengl3.cpp
)

add_library(ImGui ${IMGUI_SOURCES})

target_include_directories(ImGui PUBLIC 
    ${PROJECT_SOURCE_DIR}/external/imgui
    ${PROJECT_SOURCE_DIR}/external/imgui/backends
    ${PROJECT_SOURCE_DIR}/external/glfw/include # Add GLFW include directory
)

# Define IMGUI_IMPL_OPENGL_LOADER_GLAD if you're using GLAD
target_compile_definitions(ImGui PRIVATE IMGUI_IMPL_OPENGL_LOADER_GLAD)

# Add your source files
file(GLOB PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/entities/*.cpp
    ${PROJECT_SOURCE_DIR}/src/services/*.cpp
)


add_executable(CourseManagementSystem ${PROJECT_SOURCES})

# Include directories for your project
target_include_directories(CourseManagementSystem PRIVATE
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/entities
    ${PROJECT_SOURCE_DIR}/src/services
)

find_package(OpenGL REQUIRED)


# Link Dear ImGui with your project
target_link_libraries(CourseManagementSystem PRIVATE ImGui glfw GLAD OpenGL::GL)

# If you're using GLFW, OpenGL, or other libraries, link them here as well
# e.g., target_link_libraries(CourseManagementSystem PRIVATE glfw OpenGL ...)
add_subdirectory(external/glfw)
add_library(GLAD external/localGlad/src/glad.c)
target_include_directories(GLAD PUBLIC external/localGlad/include)
target_include_directories(CourseManagementSystem PRIVATE
    ${PROJECT_SOURCE_DIR}/external/glfw/include
)

# For MSVC (Microsoft Visual C++)
# if(MSVC)
#     # MSVC-specific flags here
#     if(MSVC)
#     # Example: Use static runtime libraries
#     set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
#     set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
# endif()

#     # Example: set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
# else()
#     # GCC/Clang-specific flags here
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
#     set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -static-libstdc++")
#     set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -static-libstdc++")
# endif()


set(gtest_force_shared_crt OFF CACHE BOOL "" FORCE)  # For static linking (/MT, /MTd)

enable_testing()
# Add Google Test as a subdirectory
add_subdirectory(${PROJECT_SOURCE_DIR}/external/googletest)

# Add the tests directory
add_subdirectory(tests)
