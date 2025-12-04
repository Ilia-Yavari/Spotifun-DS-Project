#include "../include/Artist.h"
#include <iostream>

Artist::Artist( int id, const std::string& name) :  id(id), name(name) {};

Artist::~Artist() {

}

int Artist::get_id() const {
    return id;
}

const std::string& Artist::get_name() const {
    return name;
}

void Artist::add_music(Music *m) {

}

bool Artist::remove_music() {

}

Music* Artist::find_music() {

}

void Artist ::print_info() const {
    std::cout << "-----------------------------\n";
    std::cout << "Artist Name: " << name << " | ID: " << id << std::endl;
}

void Artist::print_musics() const {
    if (head == nullptr) {
        std::cout << "No musics found." << std::endl;
        return;
    }

    MusicNode* current = head;
    while (current != nullptr) {
        current->music->print_details();
        current = current->next;
    }
}