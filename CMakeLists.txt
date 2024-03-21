cmake_minimum_required(VERSION 3.10)

# Set the project name and specify the C++ standard
project(CourseManagementSystem VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add entity library
file(GLOB ENTITY_SOURCES
    ${PROJECT_SOURCE_DIR}/src/entities/*.cpp
)

add_library(entity_lib ${ENTITY_SOURCES})

target_include_directories(entity_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/src/entities
)

# Add service library
file (GLOB SERVICE_SOURCES 
    ${PROJECT_SOURCE_DIR}/src/services/*.cpp)

add_library(service_lib ${SERVICE_SOURCES})

target_include_directories(service_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/src/services
)

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


add_executable(CourseManagementSystem ${PROJECT_SOURCE_DIR}/src/main.cpp)

find_package(OpenGL REQUIRED)

# Link Dear ImGui with your project
target_link_libraries(CourseManagementSystem PRIVATE entity_lib service_lib ImGui glfw GLAD OpenGL::GL)

# If you're using GLFW, OpenGL, or other libraries, link them here as well
# e.g., target_link_libraries(CourseManagementSystem PRIVATE glfw OpenGL ...)
add_subdirectory(external/glfw)
add_library(GLAD external/localGlad/src/glad.c)
target_include_directories(GLAD PUBLIC external/localGlad/include)
target_include_directories(CourseManagementSystem PRIVATE
    ${PROJECT_SOURCE_DIR}/external/glfw/include
)

enable_testing()
# Add Google Test as a subdirectory
add_subdirectory(${PROJECT_SOURCE_DIR}/external/googletest)

# Add the tests directory
add_subdirectory(tests)
