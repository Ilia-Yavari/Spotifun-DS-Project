#include <iostream>
#include <string>
#include "../include/Artist.h"
#include "../include/ArtistManager.h"
#include "../include/SpotifunManager.h"

int main() {
    SpotifunManager manager;
    std::string line;

    while (true) {
        std::cout << " >";
        std::getline(std::cin, line);
        if (line == "exit") break;
        else manager.handle_command(line);
    }

    return 0;
}