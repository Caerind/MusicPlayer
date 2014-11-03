#include <iostream>
#include "MusicPlayer.hpp"

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cout << "You need to give an argument..." << std::endl;
	}
	else if (argc > 1)
	{
		MusicPlayer m(argc,argv);
	}
	return 0;
}
