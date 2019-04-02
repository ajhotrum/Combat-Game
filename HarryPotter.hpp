/************************************************************************************
** Author:       Alonso Torres-Hotrum
** Date:         11/18/18
** Assignment:   CS 162 Project 4
** Description:  This is the header file for the Harry Potter class.
************************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include <iostream>
#include <string>
#include "Character.hpp"

class HarryPotter : public Character
{
protected:
	std::string name;
	int originalStrength = 10;
	bool dead = false;
public:
	HarryPotter();
	HarryPotter(std::string str);
	void setArmor(int a);
	void setStrength(int b);
	int getStrength();
	int getArmor();
	int attack();
	int defend();
	int getSpecial();
	void setName(std::string str);
	std::string getName();
	void setSpecial(int a);
	bool getDead();
	void setDead(bool ded);
	int getOriginalStrength();
};
#endif