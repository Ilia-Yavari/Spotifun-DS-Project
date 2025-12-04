#pragma once
#include <string>
#include "../include/Music.h"

struct Artist {
public:
    struct MusicNode {
        Music* music;
        MusicNode* next;
        MusicNode(Music* m) : music(m), next(nullptr) {}
    };

    Artist( int id, const std::string& name);

    ~Artist();

    int get_id() const;

    const std::string& get_name() const;

    void add_music(Music* m);

    bool remove_music();

    Music* find_music();

    void print_info() const;

    void print_musics() const;

private:
    int id;
    std::string name;
    MusicNode* head;
};
