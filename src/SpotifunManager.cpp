#include "../include/SpotifunManager.h"

#include <string>
#include <iostream>
#include <limits>

SpotifunManager::SpotifunManager() {}

void SpotifunManager::handle_command(const std::string &command) {
    if (command == "adds") {
        add_artist();
        return;
    }
    if (command == "dels") {
        delete_artist();
        return;
    }
    if (command == "finds") {
        delete_artist();
        return;
    }
    if (command == "prints") {
        artist_manager.print_all();
        return;
    }
    if (command == "addms") {
        add_music();
        return;
    }
    if (command == "get_max_rated") {
        print_maxRatedMusic();
    }
    if (command == "get_min_rated") {
        print_minRatedMusic();
    }
}

void SpotifunManager::add_artist() {
    int artist_id;
    std::cin >> artist_id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string artist_name;
    std::getline(std::cin, artist_name);
    Artist* artist = new Artist(artist_id, artist_name);
    if (!artist_manager.insert(artist)) {
        std::cout << "Failed to insert artist!\n";
        delete artist;
    } else std::cout << "Artist inserted successfully!\n";
}

void SpotifunManager::delete_artist() {
    int artist_id;
    std::cin >> artist_id;
    artist_manager.remove(artist_id);
}

void SpotifunManager::find_artist() {
    int artist_id;
    std::cin >> artist_id;
    Artist* artist = artist_manager.find_artist_by_id(artist_id);
    if (artist != nullptr) {
        artist->print_info();
        artist->print_musics();
    } else std::cout << "Artist not found.\n";
}

void SpotifunManager::add_music() {
    std::string music_name, artist_name;
    std::cin >> music_name;
    int year, rating;
    std::cin >> year, rating;
}

void SpotifunManager::print_maxRatedMusic() {
    Music* music = max_rating_heap.peek();
    if (music == nullptr) {
        std::cout << "Error: No music available." << std::endl;
    } else {
        std::cout << "Max Rated Music:\n";
        music->print_details();
    }
}

void SpotifunManager::print_minRatedMusic() {
    Music* music = min_rating_heap.peek();
    if (music == nullptr) {
        std::cout << "Error: No music available." << std::endl;
    } else {
        std::cout << "Min Rated Music:\n";
        music->print_details();
    }
}

void SpotifunManager::undo_playMusic() {
    if (history.isEmpty()) {
        std::cout << "Error: History is empty. Cannot undo." << std::endl;
        return;
    }
    Music* lastPlayed = history.pop();
    lastPlayed->print_details();
}