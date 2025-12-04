#pragma once
#include "../include/Artist.h"
#define MAX_ARTISTS 100

class ArtistManager {
private:
    Artist* dense[MAX_ARTISTS];
    int sparse[MAX_ARTISTS];
    int n;

public:
    ArtistManager();

    bool insert(Artist* artist);

    bool remove(int id);

    Artist* find_artist_by_id(int id);

    Artist* find_artist_by_name(const std::string& name);

    void print_all();
};

