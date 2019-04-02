/************************************************************************************
** Author:       Alonso Torres-Hotrum
** Date:         11/18/18
** Assignment:   CS 162 Project 4
** Description:  This is the source file for the Barbarian class.
************************************************************************************/

#include "Barbarian.hpp"
#include <stdio.h>
#include <stdlib.h>

/******************************************************
Default constructor
*******************************************************/

Barbarian::Barbarian()
{
	setArmor(0);
	setStrength(12);
	setSpecial(0);
	setName("Barbarian");
}

/******************************************************
Overload constructor
*******************************************************/

Barbarian::Barbarian(std::string str)
{
	setArmor(0);
	setStrength(12);
	setSpecial(0);
	setName(str);
}

/*************************************************************
Method to set armor
**************************************************************/
void Barbarian::setArmor(int a)
{
	armor = a;
}

/*************************************************************
Method to set strength
**************************************************************/
void Barbarian::setStrength(int b)
{
	strength = b;
}

/*************************************************************
Method to return strength
**************************************************************/
int Barbarian::getStrength()
{
	return strength;
}

/*************************************************************
Method to return armor
**************************************************************/
int Barbarian::getArmor()
{
	return armor;
}

/*************************************************************
Method to generate and return attack points
**************************************************************/
int Barbarian::attack()
{
	attackPts = (rand() % 6 + 1)+ (rand() % 6 + 1);

	return attackPts;
}

/*************************************************************
Method to generate and return defense points
**************************************************************/
int Barbarian::defend()
{
	defendPts = (rand() % 6 + 1) + (rand() % 6 + 1);

	return defendPts;
}

/*************************************************************
Method to return special
**************************************************************/
int Barbarian::getSpecial()
{
	return special;
}

/*************************************************************
Method to set special
**************************************************************/
void Barbarian::setSpecial(int a)
{
	special = a;
}

/*************************************************************
Method to set name
**************************************************************/
void Barbarian::setName(std::string str)
{
	name = str;
}

/*************************************************************
Method to return if character is dead
**************************************************************/
bool Barbarian::getDead()
{
	return dead;
}

/*************************************************************
Method to return if character is dead
**************************************************************/
void Barbarian::setDead(bool ded)
{
	dead = ded;
}

/*************************************************************
Method to get name
**************************************************************/
std::string Barbarian::getName()
{
	return name;
}

/*************************************************************
Method to get original strength
**************************************************************/
int Barbarian::getOriginalStrength()
{
	return originalStrength;
}