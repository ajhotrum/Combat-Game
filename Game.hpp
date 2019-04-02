/************************************************************************************
** Author:       Alonso Torres-Hotrum
** Date:         11/18/18
** Assignment:   CS 162 Project 4
** Description:  This is the header file for the game class.
************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "Character.hpp"

class Game
{
protected:
	//generate array of characters
	bool charm;
	bool glare;
	bool over;
	bool hogwarts;
	int currentStrength;
	int attack;
	int defend;
	int damage;
public:
	Game();
	void play(Character *char1, Character *char2);
	int check(int a, int b);
	~Game();
};
#endif