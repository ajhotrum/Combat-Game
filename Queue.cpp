/************************************************************************************
** Author:       Alonso Torres-Hotrum
** Date:         11/17/18
** Assignment:   CS 162 Project 4
** Description:  This is the source file for the Queue class.
************************************************************************************/

#include <iostream>
#include "Queue.hpp"


/******************************************************
Default constructor, sets head pointer to NULL
*******************************************************/
Queue::Queue()
{
	head = NULL;
	tail = NULL;
}

/******************************************************
Destructor
*******************************************************/
Queue::~Queue()
{
	//If the queue is empty
	if (head == NULL)
	{

	}
	//To delete single node
	else if (head->prev == NULL)
	{
		delete head;
	}
	//If there are 2 or more nodes.
	else
	{
		//Create dummy pointer
		QueueNode *nodePtr = head;

		//make last node point to NULL next
		(head->prev)->next = NULL;

		/*While next pointer is not NULL, traverse queue
		and delete previous nodes*/
		while ((nodePtr->next) != NULL)
		{
			head = head->next;
			nodePtr->next = NULL;
			delete nodePtr;
			nodePtr = head;
		}
		delete head;
	}

}

/******************************************************
Adds value to the rear of the queue.
*******************************************************/
void Queue::addBack(int player, std::string name)
{
	Character *char1;

	if(player == 1)
		char1 = new Vampire(name);
	else if (player == 2)
		char1 = new Barbarian(name);
	else if (player == 3)
		char1 = new BlueMen(name);
	else if (player == 4)
		char1 = new Medusa(name);
	else
		char1 = new HarryPotter(name);



	//if empty, create head node
	if (isEmpty())
	{
		head = new QueueNode(char1);
		tail = head;
	}
	else
	{
		//Create a new pointer that points to the tail
		QueueNode *nodePtr = tail;
		//Make a new node where the tail points to next
		nodePtr->next = new QueueNode(char1);
		//Point the tail to the new node
		tail = nodePtr->next;
		//Set the tail's prev pointer to point to the previous node
		tail->prev = nodePtr;
	}
}

/******************************************************
Adds value to the head of the queue.
*******************************************************/
void Queue::addFront(Character * char2)
{
	//check if list is empty
	if (head == NULL)
	{
		//create first node
		head = new QueueNode(char2);
		tail = head;
	}
	else
	{
		//Create a new pointer that points to the head
		QueueNode *nodePtr = head;
		//Make a new node where the head points to prev
		nodePtr->prev = new QueueNode(char2);
		//Point the head to the new node
		head = nodePtr->prev;
		//Set the head's next pointer to point to the next node
		head->next = nodePtr;

	}
}

/******************************************************
Method to remove the node at the head of the list
*******************************************************/
void Queue::removeFront()
{
	//check if it is the last node
	if (tail == head)
	{
		//create dummy pointer equal tail
		QueueNode *nodePtr = tail;
		//make tail point to null
		tail = NULL;
		//make head point to null
		head = NULL;
		//free NULL memory
		delete nodePtr;

	}
	else
	{
		//make dummy pointer equal head
		QueueNode *nodePtr = head;
		//move head to next node
		head = head->next;
		//move prev pointer to null
		head->prev = NULL;
		//free nodePtr memory
		delete nodePtr;
	}

}


void Queue::frontToBack()
{
	//only perform if there are multiple nodes
	if (tail != head)
	{
		//make dummy pointer equal head
		QueueNode *nodePtr = head;
		//move head to next node
		head = head->next;
		//move prev pointer to null
		head->prev = NULL;
		//move tail next to nodePtr
		tail->next = nodePtr;
		nodePtr->prev = tail;
		tail = tail->next;
		tail->next = NULL;
		//free nodePtr memory
		//delete nodePtr;
	}
}

/******************************************************
Method to display the list forward
*******************************************************/
void Queue::displayFwd()
{
	//create dummy pointer
	QueueNode *nodePtr = head;

	//Check if the list is empty
	if (nodePtr == NULL)
	{
		std::cout << "Your linked list is empty!" << std::endl;
	}

	else
	{
		//cycle through nodes and print them
		while (nodePtr)
		{
			std::cout << nodePtr->characters->getName() << std::endl;
			nodePtr = nodePtr->next;
		}
		std::cout << std::endl << std::endl;

	}
	//free nodePtr memory
	delete nodePtr;
}

std::string Queue::getCharName()
{
	return tail->characters->getName();
}

/******************************************************
Returns Character Strength
*******************************************************/
int Queue::getCharStrength()
{
	return tail->characters->getStrength();
}

/******************************************************
Returns current head pointer
*******************************************************/
Character* Queue::getHeadPtr()
{
	return head->characters;
}

/******************************************************
Checks if queue is empty.
*******************************************************/
bool Queue::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

