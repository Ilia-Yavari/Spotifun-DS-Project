#pragma once
#include "../include/ArtistManager.h"
#include "../include/DataStructures.h"
#include "../include/PlaylistManager.h"

#include <string>

class SpotifunManager {
private:
    ArtistManager artist_manager;
    PlaylistManager playlistManager;
    MaxHeap max_rating_heap;
    MinHeap min_rating_heap;
    HistoryStack history;

public:
    SpotifunManager();
    // ~SpotifunManager();

    void handle_command(const std::string& command);

    void add_artist();
    void delete_artist();
    void find_artist();
    void add_music();
    void print_maxRatedMusic();
    void print_minRatedMusic();
    void play_music();
    void undo_playMusic();

};