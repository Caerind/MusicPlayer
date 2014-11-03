#include "MusicPlayer.hpp"

MusicPlayer::MusicPlayer(int argc, char* argv[])
{
	mApp = argv[0];
	std::string test = argv[1];
	if (argc == 2)
	{
		if (test == "help")
		{
			help();
		}
		else if (test == "stop")
		{
			stop();
		}
		else if (test == "play")
		{
			play();
		}
	}
	else if (argc == 3)
	{
		if (test == "add")
		{
			add(argv[2]);
		}
		else if (test == "play")
		{
			play(argv[2]);
		}
		else if (test == "hiddenplay")
		{
			hiddenPlay(argv[2]);
		}
	}
}

void MusicPlayer::add(std::string const& newFilename)
{
	std::ofstream file("/usr/local/bin/musicplayer.list", std::ios::app);
	if (file)
	{
		file << newFilename << std::endl;
		std::cout << "Addded to the list ! " << std::endl;
		file.close();
	}
	else
	{
		std::cout << "Can't find /usr/local/bin/musicplayer.list" << std::endl;
	}
}

void MusicPlayer::play()
{
	std::vector<std::string> lines;
	std::ifstream file("/usr/local/bin/musicplayer.list");
	if (file)
	{
		std::random_device rd;
        std::mt19937 gen(rd());
		std::string line;
		while (std::getline(file,line))
		{
			lines.push_back(line);
		}
		std::uniform_int_distribution<unsigned int> dist(0,lines.size()-1);
		initPlayer(lines[dist(gen)]);
	}
	else
	{
		std::cout << "Can't open /usr/local/bin/musicplayer.list" << std::endl;
	}
}

void MusicPlayer::play(std::string const& filename)
{
	initPlayer(filename);
}

void MusicPlayer::help()
{
	std::cout << "Music Player by Cmdu76" << std::endl << std::endl;
	std::cout << "--> help : See the list of commands" << std::endl;
	std::cout << "--> add yourfile : Add yourfile to the songs list" << std::endl;
	std::cout << "--> play : Play a random song of the list" << std::endl;
	std::cout << "--> play yourfile : Play the song you want" << std::endl;
	std::cout << "--> stop : Stop the player" << std::endl << std::endl;
}

void MusicPlayer::stop()
{
	std::cout << "Stopping..." << std::endl;
	std::string app = mApp.substr(mApp.rfind("/")+1, mApp.size());
	std::string cmd = "killall " + app;
	system(cmd.c_str());
}

void MusicPlayer::initPlayer(std::string const& filename)
{
	if (mMusic.openFromFile(filename))
	{
		std::cout << "Starting : " << filename << std::endl;
		std::string cmd = mApp + " hiddenplay " + filename + "&";
		system(cmd.c_str());
	}
	else
	{
		std::cout << "Can't find : " << filename << std::endl;
	}
}

void MusicPlayer::hiddenPlay(std::string const& filename)
{
	mMusic.openFromFile(filename);
	mMusic.play();
	while (mMusic.getStatus() == sf::Music::Playing)
	{
	}
	mMusic.stop();
}
