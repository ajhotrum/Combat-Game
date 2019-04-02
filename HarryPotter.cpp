/************************************************************************************
** Author:       Alonso Torres-Hotrum
** Date:         11/18/18
** Assignment:   CS 162 Project 4
** Description:  This is the source file for the HarryPotter class.
************************************************************************************/

#include "HarryPotter.hpp"
#include <stdio.h>
#include <stdlib.h>

/******************************************************
Default constructor
*******************************************************/

HarryPotter::HarryPotter()
{
	setArmor(0);
	setStrength(10);
	setSpecial(2);
	setName("Harry Potter");
}

/******************************************************
Overload constructor
*******************************************************/

HarryPotter::HarryPotter(std::string str)
{
	setArmor(0);
	setStrength(10);
	setSpecial(2);
	setName(str);
}

/*************************************************************
Method to set armor
**************************************************************/
void HarryPotter::setArmor(int a)
{
	armor = a;
}

/*************************************************************
Method to set strength
**************************************************************/
void HarryPotter::setStrength(int b)
{
	strength = b;
}

/*************************************************************
Method to return strength
**************************************************************/
int HarryPotter::getStrength()
{
	return strength;
}

/*************************************************************
Method to return armor
**************************************************************/
int HarryPotter::getArmor()
{
	return armor;
}

/*************************************************************
Method to generate and return attack points
**************************************************************/
int HarryPotter::attack()
{
	attackPts = (rand() % 6 + 1) + (rand() % 6 + 1);

	return attackPts;
}

/*************************************************************
Method to generate and return defense points
**************************************************************/
int HarryPotter::defend()
{
	defendPts = (rand() % 6 + 1) + (rand() % 6 + 1);

	return defendPts;
}

/*************************************************************
Method to return special
**************************************************************/
int HarryPotter::getSpecial()
{
	return special;
}

/*************************************************************
Method to set special
**************************************************************/
void HarryPotter::setSpecial(int a)
{
	special = a;
}

/*************************************************************
Method to return if character is dead
**************************************************************/
bool HarryPotter::getDead()
{
	return dead;
}

/*************************************************************
Method to return if character is dead
**************************************************************/
void HarryPotter::setDead(bool ded)
{
	dead = ded;
}

/*************************************************************
Method to set name
**************************************************************/
void HarryPotter::setName(std::string str)
{
	name = str;
}

/*************************************************************
Method to get name
**************************************************************/
std::string HarryPotter::getName()
{
	return name;
}

/*************************************************************
Method to get original strength
**************************************************************/
int HarryPotter::getOriginalStrength()
{
	return originalStrength;
}