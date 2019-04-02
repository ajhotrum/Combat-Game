/************************************************************************************
** Author:       Alonso Torres-Hotrum
** Date:         11/18/18
** Assignment:   CS 162 Project 4
** Description:  This is the header file for the Medusa class.
************************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include <iostream>
#include <string>
#include "Character.hpp"

class Medusa : public Character
{
protected:
	int special = 0;
	std::string name;
	int originalStrength = 8;
	bool dead = false;
public:
	Medusa();
	Medusa(std::string str);
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