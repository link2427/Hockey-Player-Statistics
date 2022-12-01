// Jacob Neel
// Programming Assignment 4
// CS 221: Data Structures
// 12/1/2022
// This program will use a binary search tree to read players from an input data file.
// All of the players will be stored in the tree and have each player's average computed.
// The user has the option to remove one of these players from the list.
// The results will be written to a file.


#include "Playerlist.h"
#include <iostream>
#include <cmath>
//Function Declarations
void welcomeUser();
std::string getInputFileName();
std::string getOutputFileName(); 


//Main
int main() {
	//Create a player list
	BST* playerTree = new BST();

	welcomeUser();
	char userInput = NULL;
	std::string firstName;
	std::string lastName;
	std::string inFileName = getInputFileName();
	std::string outFileName = getOutputFileName();

	
	std::cout << std::endl << "Reading Players from: " << inFileName << std::endl;
	
	

	// Construct Tree
	playerTree->getPlayers(playerTree, inFileName);

	// Print Tree
	playerTree->print(playerTree);
	playerTree->writeData(outFileName, playerTree);

	// Ending
	std::cout << "The data has been written to you output file: " << outFileName << std::endl << std::endl;
	std::cout << "End of Program 3" << std::endl;
	delete playerTree;
}


//Welcomes the user
void welcomeUser() {
	std::cout << "Welcome to the player statistics calculator test program."
		<< std::endl << "I am going to read players from an input data file. You will tell me the names of your input and output files."
		<< std::endl << "I will store all of the players in a list, compute player's stats and then write the resulting team report to your output file."
		<< std::endl;
}


//Get input file name
std::string getInputFileName() {
	std::cout << "Enter the name of your input file: ";

	std::string inFileName;
	std::cin >> inFileName;
	return inFileName;
}


//Get output file name
std::string getOutputFileName() {
	std::cout << "Enter the name of your output file: ";

	std::string outFileName;
	std::cin >> outFileName;
	return outFileName;
}

