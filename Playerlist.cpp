#include "Playerlist.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


BST::BST() 
{
	val = nullptr;
	left = nullptr;
	right = nullptr;
}


BST::BST(Player *player) {
	val = player;
	left = nullptr;
	right = nullptr;
}


BST::~BST() {
	delete left;
	delete right;
	//std::cout << this << std::endl; ***DEBUG***
}


//Add player into list
void BST::insertPlayer(BST* currentNode, Player* val) {
	if (currentNode->val == nullptr)
	{
		currentNode->val = val;
		return;
	}
	if ((val->getLName() + val->getFName()) < (currentNode->val->getLName() + currentNode->val->getFName()))
	{
		if (currentNode->left == nullptr) {
			currentNode->left = new BST(val);
		}
		else {
			insertPlayer(currentNode->left, val);
		}
	}
	else if ((val->getLName() + val->getFName()) > (currentNode->val->getLName() + currentNode->val->getFName()))
	{
		if (currentNode->right == nullptr) {
			currentNode->right = new BST(val);
		}
		else {
			insertPlayer(currentNode->right, val);
		}
	}
}


//Clear list
void BST::free(BST* currentNode) {
	if (currentNode == nullptr) return;
	free(currentNode->left);
	free(currentNode->right);
	delete currentNode;
}


//Get list size
int BST::getCount(BST* currentNode) {
	if (currentNode == nullptr) return 0;
	int left = getCount(currentNode->left);
	int right = getCount(currentNode->right);
	return(left + right + 1);
}


void BST::print(BST* currentNode) {
	if (currentNode == nullptr) return;

	if (currentNode->right != nullptr)
	{
		print(currentNode->right);
	}

	std::cout << currentNode->val->getFName() << " " << currentNode->val->getLName() << std::endl;

	if (currentNode->left != nullptr)
	{
		print(currentNode->left);
	}
}


//Get total calories burned
double BST::getTotalCaloriesBurned() {
	double total = 0;
	Player* currentNode = val;
	while (currentNode != nullptr) {
		total += currentNode->getCaloriesBurned();
		currentNode = currentNode->next;
	}
	return total;
}


void BST::getPlayers(BST* currentNode, std::string inFileName) 
{
	std::ifstream inFile;
	inFile.open(inFileName);

	std::string firstName;
	std::string lastName;
	int age;
	int shotsTargetFor;
	int shotsTargetAgainst;
	int missedShotsFor;
	int missedShotsAgainst;
	int met;
	int bodyWeight;
	while (!inFile.eof()) {
		inFile >> firstName;
		inFile >> lastName;
		inFile >> age;
		inFile >> shotsTargetFor;
		inFile >> shotsTargetAgainst;
		inFile >> missedShotsFor;
		inFile >> missedShotsAgainst;
		inFile >> met;
		inFile >> bodyWeight;
		Player* newPlayer = new Player(firstName, lastName, age, shotsTargetFor, shotsTargetAgainst, missedShotsFor, missedShotsAgainst, met, bodyWeight);
		currentNode->insertPlayer(currentNode, newPlayer);
	}
	//Closes the file and returns players
	inFile.close();
}


void BST::writeData(std::string outFileName, BST *players) {
	//Creates ofstream of outfile
	std::ofstream outFile;
	outFile.open(outFileName);
	//Writing to outfile
	outFile << "BASKETBALL TEAM REPORT --- " << players->getCount(players) << " PLAYERS FOUND IN FILE" << std::endl
		<< "TOTAL CALORIES BURNED: " << players->getTotalCaloriesBurned() << std::endl << std::endl
		<< std::string(6, ' ') << "PLAYER NAME" << std::string(6, ' ') << " :"
		<< std::string(7, ' ') << "FF%" << std::string(4, ' ')
		<< std::string(4, ' ') << "Calories burned" << std::endl
		<< std::string(58, '-') << std::endl;

		writePlayersData(players, outFile);
		outFile.close();
	}


void BST::writePlayersData(BST* currentNode, std::ostream& outfile)
{
	if (currentNode == nullptr) return;

	if (currentNode->left != nullptr) {
		writePlayersData(currentNode->left, outfile);
	}
	outfile << std::setw(23) << (currentNode->val->getLName() + ", " + currentNode->val->getFName()) << " :"
		<< std::setw(11) << (currentNode->val->getFenwick() * 100)
		<< std::setw(17) << currentNode->val->getCaloriesBurned() << std::endl;

	if (currentNode->right != nullptr) {
		writePlayersData(currentNode->right, outfile);
	}
}





