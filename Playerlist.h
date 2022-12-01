#pragma once

#include "Player.h"

class BST {
private:
	Player* val;
	BST* left;
	BST* right;
	int size;

public:
	BST();
	BST(Player *player);
	BST* insertPlayer(BST* currentNode, Player *player); // function to add a player to list
	void free(BST* currentNode); // function to clear list
	int getCount(BST* currentNode); // function to get size
	std::string print(BST* currentNode);
	double getTotalCaloriesBurned(); // function to get total calories burned
};