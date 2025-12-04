#pragma once
#include "../include/Music.h"
#include <string>

class Playlist {
public:
    struct PlayNode {
        Music* music;
        PlayNode* next;
        PlayNode(Music* m) : music(m), next(nullptr) {}
    };
    Playlist(int id, const std::string& name);
    ~Playlist();
    int getId() const;
    const std::string& getName() const;
    void addMusic(Music* music);
    bool removeMusic(int musicId);
    void printSortedByYear();

private:
    int id;
    std::string name;
    PlayNode* head;
    PlayNode tail;
};