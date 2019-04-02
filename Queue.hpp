/************************************************************************************
** Author:       Alonso Torres-Hotrum
** Date:         11/17/18
** Assignment:   CS 162 Project 4
** Description:  This is the header file for the Queue class.
************************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <string>
#include "Game.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

class Queue
{
protected:
	//QueueNode struct definition
	struct QueueNode
	{
		Character * characters;
		QueueNode *next;
		QueueNode *prev;

		//QueueNode object definition
		QueueNode(Character *char1, QueueNode *next1 = NULL, QueueNode *prev1 = NULL)
		{
			characters = char1;
			next = next1;
			prev = prev1;
		}
	};

	//pointers to the head
	QueueNode *head;
	QueueNode *tail;
public:
	//Constructor and destructor
	Queue();
	~Queue();

	//Member functions
	bool isEmpty();
	void addFront(Character * char2);
	void addBack(int player, std::string name);
	void frontToBack();
	void displayFwd();
	void removeFront();
	Character * getHeadPtr();
	std::string getCharName();
	int getCharStrength();
};
#endif