/************************************************************************************
** Author:       Alonso Torres-Hotrum
** Date:         11/18/18
** Assignment:   CS 162 Project 4
** Description:  This is the source file for the Medusa class.
************************************************************************************/

#include "Medusa.hpp"
#include <stdio.h>
#include <stdlib.h>

/******************************************************
Default constructor
*******************************************************/

Medusa::Medusa()
{
	setArmor(3);
	setStrength(8);
	setName("Medusa");
}

/******************************************************
Overload constructor
*******************************************************/

Medusa::Medusa(std::string str)
{
	setArmor(3);
	setStrength(8);
	setName(str);
}

/*************************************************************
Method to set armor
**************************************************************/
void Medusa::setArmor(int a)
{
	armor = a;
}

/*************************************************************
Method to set strength
**************************************************************/
void Medusa::setStrength(int b)
{
	strength = b;
}

/*************************************************************
Method to return strength
**************************************************************/
int Medusa::getStrength()
{
	return strength;
}

/*************************************************************
Method to return armor
**************************************************************/
int Medusa::getArmor()
{
	return armor;
}

/*************************************************************
Method to generate and return attack points
**************************************************************/
int Medusa::attack()
{
	attackPts = (rand() % 6 + 1) + (rand() % 6 + 1);

	if (attackPts == 12)
	{
		special = 3;
	}

	return attackPts;
}

/*************************************************************
Method to generate and return defense points
**************************************************************/
int Medusa::defend()
{
	defendPts = (rand() % 6 + 1) + (rand() % 6 + 1);

	return defendPts;
}

/*************************************************************
Method to return special
**************************************************************/
int Medusa::getSpecial()
{
	return special;
}

/*************************************************************
Method to set special
**************************************************************/
void Medusa::setSpecial(int a )
{
	special=a;
}

/*************************************************************
Method to return if character is dead
**************************************************************/
bool Medusa::getDead()
{
	return dead;
}

/*************************************************************
Method to return if character is dead
**************************************************************/
void Medusa::setDead(bool ded)
{
	dead = ded;
}

/*************************************************************
Method to set name
**************************************************************/
void Medusa::setName(std::string str)
{
	name = str;
}

/*************************************************************
Method to get name
**************************************************************/
std::string Medusa::getName()
{
	return name;
}

/*************************************************************
Method to get original strength
**************************************************************/
int Medusa::getOriginalStrength()
{
	return originalStrength;
}