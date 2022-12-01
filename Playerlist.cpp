#include "Playerlist.h"
#include <iostream>
#include <string>


BST::BST() 
{

}

BST::BST(Player *player) {
	size = 0;
	val = player;
	left = nullptr;
	right = nullptr;
}


//Add player into list
BST* BST::insertPlayer(BST* currentNode, Player* val) {
	if (!currentNode)
	{
		BST(val);
		return;
	}
	if (val->getFName() + val->getLName() > currentNode->val->getFName() + currentNode->val->getLName())
	{
		currentNode->right = insertPlayer(currentNode->right, val);

	}
	else if (val->getFName() + val->getLName() < currentNode->val->getFName() + currentNode->val->getLName())
	{
		currentNode->left = insertPlayer(currentNode->left, val);
	}
	return currentNode;
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
	if (currentNode == nullptr) return;
	getCount(currentNode->left);
	getCount(currentNode->right);
	size++;
}

std::string BST::print(BST* currentNode) {
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


