cmake_minimum_required(VERSION 3.10)
project(2DGraphics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main executable
add_executable(render_2d 
    src/main.cpp 
    src/Scene.cpp
)
target_include_directories(render_2d PRIVATE include)

# Test executable
add_executable(test_shapes
    tests/test_shapes.cpp
    src/Scene.cpp
)
target_include_directories(test_shapes PRIVATE include)

# Enable testing
enable_testing()
add_test(NAME ShapeTests COMMAND test_shapes)
