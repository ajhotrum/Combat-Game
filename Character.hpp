/************************************************************************************
** Author:       Alonso Torres-Hotrum
** Date:         11/18/18
** Assignment:   CS 162 Project 4
** Description:  This is the header file for the character class.
************************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

class Character
{
protected:
	int armor;
	int strength;
	int attackPts;
	int defendPts;
	int special = 0;
	bool dead = false;
	int originalStrength;
public:
	Character();
	virtual void setArmor(int a) =0;
	virtual void setStrength(int b)=0;
	virtual int getStrength() = 0;
	virtual int getArmor() = 0;
	virtual int attack()=0;
	virtual int defend()=0;
	virtual int getSpecial() = 0;
	virtual void setSpecial(int a) = 0;
	virtual void setName(std::string str) =0;
	virtual int getOriginalStrength() =0;
	virtual bool getDead() =0;
	virtual void setDead(bool ded) =0;
	virtual std::string getName()=0;
	virtual ~Character();
};
#endif