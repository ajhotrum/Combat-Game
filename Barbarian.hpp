/************************************************************************************
** Author:       Alonso Torres-Hotrum
** Date:         11/18/18
** Assignment:   CS 162 Project 4
** Description:  This is the header file for the Barbarian class.
************************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include <iostream>
#include <string>
#include "Character.hpp"

class Barbarian : public Character
{
protected:
	std::string name;
	int originalStrength = 12;
	bool dead = false;
public:
	Barbarian();
	Barbarian(std::string str);
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