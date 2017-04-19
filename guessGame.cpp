#include <iostream>
#include <ctime>
#include <cstdlib>

//gets the random number to be guessed
int getRand(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

//lets users choose if they want yo keep playing
bool getPlay()
{
	char play;
	while(true)
	{
		std::cout << "keep playing? [y/n]" << '\n';
		std::cin >> play;
		std::cin.ignore(32767, '\n');
		
		if(play == 'y')
			return true;
		else if(play == 'n')
			return false;
		else if(play != 'y' || 'n')
			std::cout << "INVALID INPUT"<<'\n';
	}
}

int main()
{
	srand(time(0));
	bool play(true);
	do
	{
		std::cout << "I'm thinking of a number from 1 to 100" << '\n';
		
		int target = getRand(1, 2);
		int guess(0);
		
		//game loop
		for(int attempt = 0; attempt <= 7; ++attempt)
		{
			std::cout << "guess #" << attempt << ": ";
			std::cin >> guess;
			
			//error correction for non integer input
			if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cout << "INVALID INPUT" << '\n';
				}
				
			//checks if the guesd is correct
			else if(guess < target)
				std::cout << "too low" << '\n';
			else if(guess > target)
				std::cout << "too high" << '\n';
			else if(guess == target)
				{
					std::cout << "YOU WIN!" << '\n';
					break;
				}
			
			//let's player know they lost after 7 attempts
			else if(attempt == 7)
				std::cout << "You loose" << '\n';
		}
	
		play = getPlay();
	
	}
	while(play);
	
	std::cout << "Thanks for playing!";
	
	return 0;
}
