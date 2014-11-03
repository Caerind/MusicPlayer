#include <iostream>
#include <fstream>
#include <random>
#include <unistd.h>
#include <string>
#include <SFML/Audio/Music.hpp>

class MusicPlayer
{
    public:
        MusicPlayer(int argc, char* argv[]);

    private:
        void add(std::string const& newFilename);
        void addFolder(std::string const& path);
        void play();
        void play(std::string const& filename);
        void help();
        void stop();

    private:
        void initPlayer(std::string const& filename);

    private:
        void hiddenPlay(std::string const& filename);

    private:
        sf::Music mMusic;
        std::string mApp;
};
