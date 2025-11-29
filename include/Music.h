#ifndef Spotifun_MUSIC_H
#define Spotifun_MUSIC_H

#include <string>

struct Music {
    int id;
    int year;
    int rating;
    std::string name;
    std::string artist_name;
    std::string lyrics;

    Music(int id, int year, int rating, const std::string& name, const std::string& artist_name, const std::string& lyrics);
};

#endif //Spotifun_MUSIC_H
