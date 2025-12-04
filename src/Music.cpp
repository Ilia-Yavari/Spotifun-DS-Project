#include "../include/Music.h"
#include <iostream>

Music::Music(int id, int year, int rating, const std::string& name, const std::string& artist_name, const std::string& lyrics)
    : id(id), year(year), rating(rating), name(name), artist_name(artist_name), lyrics(lyrics) {}

void Music::print_details() const {
    std::cout << "ID: " << id << " | Name: " << name << " | Artist: " << artist_name << "\n";
    std::cout << "Year: " << year << " | Rating: " << rating << "\n";
}