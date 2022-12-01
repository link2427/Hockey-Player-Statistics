#pragma once

#include "Player.h"

class BST {
private:
	Player* val;

	BST* right;
	BST* left;
public:
	void writePlayersData(BST* currentNode, std::ostream& outfile);
	~BST();
	BST();
	BST(Player *player);
	void insertPlayer(BST* currentNode, Player *player); // function to add a player to list
	int getCount(BST* currentNode); // function to get size
	void print(BST* currentNode);
	double getTotalCaloriesBurned(); // function to get total calories burned
	void getPlayers(BST* currentNode, std::string inFileName);
	void writeData(std::string outFileName, BST *players);
	void free(BST* currentNode); // function to clear list
};