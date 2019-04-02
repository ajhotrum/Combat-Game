/************************************************************************************
** Author:       Alonso Torres-Hotrum
** Date:         11/18/18
** Assignment:   CS 162 Project 4
** Description:  This is the source file for the Blue Men class.
************************************************************************************/

#include "BlueMen.hpp"
#include <stdio.h>
#include <stdlib.h>

/******************************************************
Default constructor
*******************************************************/
BlueMen::BlueMen()
{
	setArmor(3);
	setStrength(12);
	setSpecial(0);
	setName("Blue Men");
}

/******************************************************
Overload constructor
*******************************************************/
BlueMen::BlueMen(std::string str)
{
	setArmor(3);
	setStrength(12);
	setSpecial(0);
	setName(str);
}

/*************************************************************
Method to set armor
**************************************************************/
void BlueMen::setArmor(int a)
{
	armor = a;
}

/*************************************************************
Method to set strength
**************************************************************/
void BlueMen::setStrength(int b)
{
	strength = b;
}

/*************************************************************
Method to return strength
**************************************************************/
int BlueMen::getStrength()
{
	return strength;
}

/*************************************************************
Method to return armor
**************************************************************/
int BlueMen::getArmor()
{
	return armor;
}

/*************************************************************
Method to generate and return attack points
**************************************************************/
int BlueMen::attack()
{
	attackPts = (rand() % 10 + 1) + (rand() % 10 + 1);

	return attackPts;
}


/*************************************************************
Method to generate and return defense points
**************************************************************/
int BlueMen::defend()
{
	//if strength is 4 or less, only one dice
	if (strength < 5)
	{
		defendPts = (rand() % 6 + 1);
	}
	//If strength is between 8-4, two die
	else if (strength < 9)
	{
		defendPts = (rand() % 6 + 1) + (rand() % 6 + 1);
	}
	//If strength is between 12-8, three die
	else 
	{
		defendPts = (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1);
	}
	

	return defendPts;
}


/*************************************************************
Method to return special
**************************************************************/
int BlueMen::getSpecial()
{
	return special;
}

/*************************************************************
Method to set name
**************************************************************/
void BlueMen::setName(std::string str)
{
	name = str;
}

/*************************************************************
Method to get name
**************************************************************/
std::string BlueMen::getName()
{
	return name;
}

/*************************************************************
Method to return if character is dead
**************************************************************/
bool BlueMen::getDead()
{
	return dead;
}

/*************************************************************
Method to return if character is dead
**************************************************************/
void BlueMen::setDead(bool ded)
{
	dead = ded;
}

/*************************************************************
Method to set special
**************************************************************/
void BlueMen::setSpecial(int a)
{
	special = a;
}

/*************************************************************
Method to get original strength
**************************************************************/
int BlueMen::getOriginalStrength()
{
	return originalStrength;
}