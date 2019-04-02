/************************************************************************************
** Author:       Alonso Torres-Hotrum
** Date:         11/18/18
** Assignment:   CS 162 Project 4
** Description:  This is the source file for the game class.
************************************************************************************/

#include "Game.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

/******************************************************
Default constructor
*******************************************************/

Game::Game()
{
	charm = false;
	glare = false;
	over = false;
	hogwarts = false;
}


/*************************************************************
Method to play the game
**************************************************************/
void Game::play(Character * charP1, Character *charP2)
{
	//Get special and current strength
	int dSpecial = charP2->getSpecial();
	currentStrength = charP2->getStrength();
	//Get attacker special
	int aSpecial = charP1->getSpecial();
	//get attacker attack and defender defend points
	attack = charP1->attack();
	defend = charP2->defend();
	//Calculate damage
	damage = attack - defend - charP2->getArmor();

	switch (dSpecial)
	{
	//No special
	case 0: {
			break;
			}
	//Set charm to true
	case 1: {
			charm = true;
			break;
			}
	//Harry Potter
	case 2: {
			hogwarts = true;
			break;
			}
		}

	if (aSpecial == 3)
	{
		glare = true;
	}
	
		//if charm is activated, skip the damage
		if (charm)
		{
			//Reset Vampire special
			charP2->setSpecial(0);
		}
		//Medusa uses glare
		else if (glare)
		{
			//Check if charm is in effect
			if (!charm)
			{
				//reset Medusa special
				charP1->setSpecial(0);
			}
			//charm is in effect
			else
			{
				//Reset Vampire special
				charP2->setSpecial(0);
				//Reset Medusa special
				charP1->setSpecial(0);
			}
		}
		//Total damage is less than one
		else if (damage < 1)
		{
		}
			
		//Normal execution
		else
		{
			//Update strength
			charP2->setStrength(currentStrength - damage);
		}

		//check if player 2 is dead or if glare without charm happened
		if (charP2->getStrength() < 1 || (glare && !charm))
		{
			//Check to see if Harry Potter still has hogwarts resurection
			if (hogwarts)
			{
				//Set up double health
				charP2->setStrength(20);
				//Reset special to zero
				charP2->setSpecial(0);
				hogwarts = false;
			}
			//Display death message, free the memory of the characters
			else
			{
				charP2->setDead(true);
			}
		}

		//Reset charm and glare
		charm = false;
		glare = false;

}


/*************************************************************
Method to validate user input
**************************************************************/
int Game::check(int a, int b)
{

	int decision;

	while (!(std::cin >> decision) || std::cin.get() != '\n' || ((decision <a) || (decision >b))) {
		std::cout << "Error. Please enter a number between " << a << " and " << b << ":" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}

	//return user input
	return decision;

}

/*************************************************************
Destructor
**************************************************************/
Game::~Game()
{

}