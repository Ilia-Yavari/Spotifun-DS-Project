cmake_minimum_required(VERSION 4.0)
project(Spotifun)

set(CMAKE_CXX_STANDARD 20)

add_executable(Spotifun
        include/Music.h
        include/Artist.h
        include/DataStructures.h
        src/Artist.cpp
        src/main.cpp
        src/Music.cpp
)
