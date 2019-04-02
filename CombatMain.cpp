/************************************************************************************
** Author:       Alonso Torres-Hotrum
** Date:         11/18/18
** Assignment:   CS 162 Project 4
** Description:  This program creates multiple linked lists of user defined nodes 
**				 that point to different characters. The characters from each list 
**				 battle each other until one list runs out of characters.
************************************************************************************/

#include <iostream>
#include "Game.hpp"
#include "Queue.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>


int main() {

	//instantiate game
	Game g1;

	srand(time(NULL));
	
	std::cout << "Welcome to the Fantasy Combat Game!" 
		<< std::endl << std::endl;

	bool playAgain = false;

	//Prompt the user to play or exit
	std::cout << "What would you like to do?" << std::endl << "1: Play" 
		<< std::endl << "2: Exit" << std::endl;

	//validate input
	int choice = g1.check(1, 2);
	
	if (choice == 1)
	{
		playAgain = true;
	}
	
	//begin the game
	while (playAgain)
	{
		//instantiate queues for each player and one fore losers
		Queue p1;
		Queue p2;
		Queue losers;

		//Prompt the user for the number of fighters on each team
		std::cout << "How many fighters on each team? ";
		int fighters = g1.check(1, 1000);
		
		std::cout <<std::endl<< "Team 1:" << std::endl;

		//Create Player 1's team
		for (int x = 0; x < fighters; x++)
		{
			//Display menu
			std::cout <<std::endl << "Choose from the following character types:" 
				<< std::endl<< "1: Vampire" << std::endl << "2: Barbarian" 
				<< std::endl<< "3: Blue Men" << std::endl << "4: Medusa" 
				<< std::endl<< "5: Harry Potter" << std::endl << std::endl;


			//Get first character type
			std::cout << "Team 1 Fighter Number " << (x+1) << " type: ";
			int player1 = g1.check(1, 5);

			//Get character name
			std::cout << "Team 1 Fighter Number " << (x + 1) << " name: ";
			std::string name;
			getline(std::cin, name);
			std::cout << std::endl;

			//add the character to the end of the queue
			p1.addBack(player1, name);
		}


		std::cout << "Team 2:" << std::endl;
		//Create Player 1's team
		for (int x = 0; x < fighters; x++)
		{
			//Display menu
			std::cout << std::endl << "Choose from the following character types:"
				<< std::endl << "1: Vampire" << std::endl << "2: Barbarian"
				<< std::endl << "3: Blue Men" << std::endl << "4: Medusa"
				<< std::endl << "5: Harry Potter" << std::endl << std::endl;


			//Get first character type
			std::cout << "Team 2 Fighter Number " << (x + 1) << " type: ";
			int player2 = g1.check(1, 5);

			//Get character name
			std::cout << "Team 2 Fighter Number " << (x + 1) << " name: ";
			std::string name;
			getline(std::cin, name);
			std::cout << std::endl;

			//add character to the end of the queue
			p2.addBack(player2, name);
		}

		//create pointers to the head poitners for each queue
		Character * defender = p2.getHeadPtr();
		Character * attacker = p1.getHeadPtr();

		//initiate loop check and count
		bool over = false;
		int count = 1;
	
		std::cout << "Round 1: " << attacker->getName() << " vs " << defender->getName() << ", ";

		//loop until one side is completely gone
		while (!over)
		{
			//Initiate game play
			g1.play(attacker, defender);

			

			if (defender->getDead())
			{
				//Add health to the attacker
				int newStrength = attacker->getStrength() + .1*(rand() % 9 + 1)*(attacker->getOriginalStrength() - attacker->getStrength());
				attacker->setStrength(newStrength);


				if (p2.getHeadPtr()->getDead())
				{
					std::cout << p1.getHeadPtr()->getName() << " wins!" << std::endl;
					//Send attacker to back of list
					p1.frontToBack();
					//move dead to dead list
					losers.addFront(p2.getHeadPtr());
					//delete defender and point to next
					p2.removeFront();
					//if the list is not empty, move the new head to defender
					if (!p2.isEmpty())
					{
						defender = p2.getHeadPtr();
						count++;
						std::cout << "Round " << count <<": " << p1.getHeadPtr()->getName()
							<< " vs " << p2.getHeadPtr()->getName() << ", ";
					}
				}
				else
				{
					std::cout << p2.getHeadPtr()->getName() << " wins!" << std::endl;
					//Send attacker to back of list
					p2.frontToBack();
					//move dead to dead list
					losers.addFront(p1.getHeadPtr());
					//delete defender
					p1.removeFront();

					//if the list is not empty, move the new head to defender
					if (!p1.isEmpty())
					{
						defender = p1.getHeadPtr();
						count++;
						std::cout << "Round " << count << ": " << p1.getHeadPtr()->getName()
							<< " vs " << p2.getHeadPtr()->getName() << ", ";
					}

				}

				
				if (p1.isEmpty())
				{
					//display winner and prompt to exit
					std::cout << "Player 2 wins!" << std::endl << std::endl;
					over = true;

					//prompt the user to display loser list.
					std::cout << "Display list of losers?" << std::endl << "1: Yes"
						<< std::endl << "2: No" << std::endl;

					int displayL = g1.check(1, 2);

					//Display list of fallen charcters
					if (displayL == 1)
					{
						losers.displayFwd();
					}
				}
				else if (p2.isEmpty())
				{
					//display winner and prompt to exit
					std::cout << "Player 1 wins!" << std::endl << std::endl;
					over = true;

					//prompt the user to display loser list.
					std::cout << "Display list of losers?" << std::endl << "1: Yes"
						<< std::endl << "2: No" << std::endl;

					int displayL = g1.check(1, 2);

					//Display list of fallen charcters
					if (displayL == 1)
					{
						std::cout<< std::endl << "Characters that lost:" << std::endl;
						losers.displayFwd();
					}
				}
			}
			else
			{
				//No deaths occured, switch the attacker and defender.
				Character *temp = attacker;
				attacker = defender;
				defender = temp;

			}

		}



		//ask if player wants to exit
		std::cout << "Play again?" << std::endl;
		std::cout << "1: Yes" << std::endl;
		std::cout << "2: No" << std::endl;
		int lastChoice = g1.check(1, 2);

		//If exit, set PlayAgain to false
		if (lastChoice == 2)
		{
			playAgain = false;
		}
	}

	return 0;
}