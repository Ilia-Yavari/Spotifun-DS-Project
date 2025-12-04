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
        include/ArtistManager.h
        src/ArtistManager.cpp
        src/DataStructures.cpp
        src/Stack.cpp
        include/SpotifunManager.h
        src/SpotifunManager.cpp
        include/Playlist.h
        src/Playlist.cpp
        include/PlaylistManager.h
        src/PlaylistManager.cpp
)
