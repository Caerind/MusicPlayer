#!/bin/bash

g++ -std=c++11 MusicPlayer.hpp MusicPlayer.cpp main.cpp -o musicplayer -lsfml-audio -lsfml-system
sudo mv musicplayer /usr/local/bin/musicplayer
touch m.list
sudo mv m.list /usr/local/bin/musicplayer.list

