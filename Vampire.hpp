/************************************************************************************
** Author:       Alonso Torres-Hotrum
** Date:         11/18/18
** Assignment:   CS 162 Project 4
** Description:  This is the header file for the vampire class.
************************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include <iostream>
#include <string>
#include "Character.hpp"

class Vampire : public Character
{
protected:
	std::string name;
	int originalStrength = 18;
	bool dead = false;
public:
	Vampire();
	Vampire(std::string str);
	void setArmor(int a);
	void setStrength(int b);
	int getStrength();
	int getArmor();
	int attack();
	int defend();
	int getSpecial();
	void setSpecial(int a);
	void setName(std::string str);
	std::string getName();
	bool getDead();
	void setDead(bool ded);
	int getOriginalStrength();
};
#endif