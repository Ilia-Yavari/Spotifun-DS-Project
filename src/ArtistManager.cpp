#include "../include/ArtistManager.h"

ArtistManager::ArtistManager() : n(0) {};

bool ArtistManager::insert(Artist *artist) {
    if (n >= MAX_ARTISTS) return false;
    int id = artist->get_id();
    if (!(0 <= id && id < MAX_ARTISTS)) return false;
    if (find_artist_by_id(id)) return false;
    dense[n] = artist;
    sparse[artist->get_id()] = n;
    n++;
    return true;
}

Artist* ArtistManager::find_artist_by_id(int id) {
    if (id >= MAX_ARTISTS || id < 0) return nullptr;

    int idx = sparse[id];
    if (idx < n && dense[idx]->get_id() == id) {
        return dense[idx];
    }
    return nullptr;
}

bool ArtistManager::remove(int id) {
    Artist* targetArtist = find_artist_by_id(id);
    if (targetArtist == nullptr) return false;

    int idx = sparse[id];
    Artist* lastArtist = dense[n - 1];
    dense[idx] = lastArtist;
    sparse[lastArtist->get_id()] = idx;
    --n;
    return true;
}

Artist* ArtistManager::find_artist_by_name(const std::string& name) {
    for (int i = 0; i < n; ++i) {
        if (dense[i]->get_name() == name) return dense[i];
    }
    return nullptr;
}

void ArtistManager::print_all() {
    for (int i = 0; i < n; ++i) {
        dense[i]->print_info();
    }
}
