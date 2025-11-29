#include "../include/Music.h"

Music::Music(int id, int year, int rating, const std::string& name, const std::string& artist_name, const std::string& lyrics)
    : id(id), year(year), rating(rating), name(name), artist_name(artist_name), lyrics(lyrics) {}