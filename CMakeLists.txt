cmake_minimum_required(VERSION 3.10)

# Set the project name and specify the C++ standard
project(CourseManagementSystem VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Interface library for template-based data structures
add_library(data_structures INTERFACE)
target_include_directories(data_structures INTERFACE ${PROJECT_SOURCE_DIR}/src/data_structures)

# Entity library
file(GLOB ENTITY_SOURCES ${PROJECT_SOURCE_DIR}/src/entities/*.cpp)
add_library(entity_lib ${ENTITY_SOURCES})
target_include_directories(entity_lib PUBLIC ${PROJECT_SOURCE_DIR}/src/entities)

# Service library
file (GLOB SERVICE_SOURCES ${PROJECT_SOURCE_DIR}/src/services/*.cpp)
add_library(service_lib ${SERVICE_SOURCES})
target_include_directories(service_lib PUBLIC ${PROJECT_SOURCE_DIR}/src/services)

# Utility library
file(GLOB UTILITY_SOURCES ${PROJECT_SOURCE_DIR}/src/utils/*.cpp)
add_library(utility_lib ${UTILITY_SOURCES})
target_include_directories(utility_lib PUBLIC ${PROJECT_SOURCE_DIR}/src/utils)

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
target_compile_definitions(ImGui PRIVATE IMGUI_IMPL_OPENGL_LOADER_GLAD)

# Main executable
add_executable(CourseManagementSystem ${PROJECT_SOURCE_DIR}/src/main.cpp)
find_package(OpenGL REQUIRED)
target_link_libraries(CourseManagementSystem PRIVATE entity_lib service_lib bcrypt utility_lib ImGui glfw GLAD OpenGL::GL)

# If you're using GLFW, OpenGL, or other libraries, link them here as well
# e.g., target_link_libraries(CourseManagementSystem PRIVATE glfw OpenGL ...)
add_subdirectory(external/glfw)
add_library(GLAD external/localGlad/src/glad.c)
target_include_directories(GLAD PUBLIC external/localGlad/include)
target_include_directories(CourseManagementSystem PRIVATE ${PROJECT_SOURCE_DIR}/external/glfw/include)

# bcrypt library
add_subdirectory(external/libbcrypt-master)
target_include_directories(CourseManagementSystem PRIVATE external/libbcrypt-master/include)
# Unit testing
enable_testing()
add_subdirectory(${PROJECT_SOURCE_DIR}/external/googletest)
add_subdirectory(tests)
