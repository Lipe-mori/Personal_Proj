#include <SFML/Audio.hpp>
#include <iostream>
#include <filesystem>
#include <vector>
//needed directories

namespace fs = std::filesystem;

int main() {

    std::string musD = "music_file"; //this is our folder name
    std::vector<std::string> songs;

    std::cout << "Looking for music files in: " <<  musD << "\n";

    //where we find the files
    for (const auto &entry: fs::directory_iterator(musD)){
        if(entry.is_regular_file()){
            std::string path = entry.path().string();
            std::string ext = entry.path().extension().string();
        
            if (ext == ".mp3" || ext == ".wav")
                songs.push_back(path);
        }
    }

    if (songs.empty()){
        std::cout << "No musuc files found. \n";
        return 0;
    }

    //listing song files
    std::cout << "\n Songs list: \n";
    for (size_t i = 0; i < songs.size(); ++i){
        std::cout << "[" << i + 1 << "]" << fs::path(songs[i]).filename().string() << "\n";
    }

    //selecting choice of song
    int sel; //selecting via #'s
    std::cout << "Enter corresponding number of song to play: ";
    std::cin >> sel;

    std::string selected = songs[sel - 1];
    std::cout << "Now playing: " << fs::path(selected).filename().string() << "\n";

    //play song
    sf::Music music;
    if(!music.openFromFile(selected)){
        std::cerr << "Failed to open: " << selected << "\n";
    return 1;
    }

    music.play();

    //playback ends or fails
    std::cout << "Press ENTER to stop track... \n";
    std::cin.ignore();
    std::cin.get();

    music.stop();
    std::cout << "Song has stopped. \n";


}