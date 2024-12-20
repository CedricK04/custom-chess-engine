cmake_minimum_required(VERSION 3.30)
project(custom_chess_engine)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the source files
set(SOURCE_FILES
        src/main.cpp
        src/board.cpp
        src/display.cpp
)

# Create the executable target
add_executable(custom_chess_engine ${SOURCE_FILES})

# Specify the include directories
target_include_directories(custom_chess_engine PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Fetch SFML using FetchContent
include(FetchContent)
set(BUILD_SHARED_LIBS OFF) # Use static libraries
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.2
)
FetchContent_MakeAvailable(SFML)

# Link SFML libraries
target_link_libraries(custom_chess_engine sfml-graphics sfml-window sfml-system)
