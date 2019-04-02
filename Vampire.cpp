/************************************************************************************
** Author:       Alonso Torres-Hotrum
** Date:         11/18/18
** Assignment:   CS 162 Project 4
** Description:  This is the source file for the vampire class.
************************************************************************************/

#include "Vampire.hpp"
#include <stdio.h>
#include <stdlib.h>

/******************************************************
Default constructor
*******************************************************/
Vampire::Vampire()
{
	setArmor(1);
	setStrength(18);
	setSpecial(0);
	setName("Vampire");
}

/******************************************************
Overload constructor
*******************************************************/
Vampire::Vampire(std::string str)
{
	setArmor(1);
	setStrength(18);
	setSpecial(0);
	setName(str);
}

/*************************************************************
Method to set armor
**************************************************************/
void Vampire::setArmor(int a)
{
	armor = a;
}

/*************************************************************
Method to set strength
**************************************************************/
void Vampire::setStrength(int b)
{
	strength = b;
}

/*************************************************************
Method to return strength
**************************************************************/
int Vampire::getStrength()
{
	return strength;
}

/*************************************************************
Method to return armor
**************************************************************/
int Vampire::getArmor()
{
	return armor;
}

/*************************************************************
Method to generate and return attack points
**************************************************************/
int Vampire::attack()
{
	attackPts = rand() % 12 + 1;

	return attackPts;
}

/*************************************************************
Method to generate and return defense points
**************************************************************/
int Vampire::defend()
{
	defendPts = rand() % 6 + 1;

	//If roll is even, set the special
	if (defendPts % 2 == 0)
	{
		special = 1;
	}
	return defendPts;
}

/*************************************************************
Method to return special
**************************************************************/
int Vampire::getSpecial()
{
	return special;
}

/*************************************************************
Method to set special
**************************************************************/
void Vampire::setSpecial(int a)
{
	special = a;
}

/*************************************************************
Method to return if character is dead
**************************************************************/
bool Vampire::getDead()
{
	return dead;
}

/*************************************************************
Method to return if character is dead
**************************************************************/
void Vampire::setDead(bool ded)
{
	dead = ded;
}

/*************************************************************
Method to set name
**************************************************************/
void Vampire::setName(std::string str)
{
	name = str;
}

/*************************************************************
Method to get name
**************************************************************/
std::string Vampire::getName()
{
	return name;
}

/*************************************************************
Method to get original strength
**************************************************************/
int Vampire::getOriginalStrength()
{
	return originalStrength;
}