/*
 * Main.cpp
 *
 *  Created on: May 2, 2017
 *      Author: Kevin Jin
 */
//Import everything I need
#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include "RedBlackBinaryNode.h"

using namespace std;

//Function prototypes, wow there's a lot.
void add(RedBlackBinaryNode* & root, int newNode);
void print(RedBlackBinaryNode* root);
void remove(RedBlackBinaryNode* & root, int target);
void search(RedBlackBinaryNode* root, int target);
void case1(RedBlackBinaryNode* addedNode, RedBlackBinaryNode* & root);
void case2(RedBlackBinaryNode* addedNode, RedBlackBinaryNode* & root);
void case3(RedBlackBinaryNode* addedNode, RedBlackBinaryNode* & root);
void case4(RedBlackBinaryNode* addedNode, RedBlackBinaryNode* & root);
void case5(RedBlackBinaryNode* addedNode, RedBlackBinaryNode* & root);
void rotateLeft(RedBlackBinaryNode* target, RedBlackBinaryNode* & root);
void rotateRight(RedBlackBinaryNode* target, RedBlackBinaryNode* & root);
void deleteOneChild(RedBlackBinaryNode* & target, RedBlackBinaryNode* & root);
void deleteCase1(RedBlackBinaryNode* & target, RedBlackBinaryNode* & root);
void deleteCase2(RedBlackBinaryNode* & target, RedBlackBinaryNode* & root);
void deleteCase3(RedBlackBinaryNode* & target, RedBlackBinaryNode* & root);
void deleteCase4(RedBlackBinaryNode* & target, RedBlackBinaryNode* & root);
void deleteCase5(RedBlackBinaryNode* & target, RedBlackBinaryNode* & root);
void deleteCase6(RedBlackBinaryNode* & target, RedBlackBinaryNode* & root);



//Main method which does pretty much everything
int main () {
	//Checks for valid input ("file", "console", or "quit").
 	bool running = true;
	while (running) {
		//Initializing an empty tree
		RedBlackBinaryNode* root = NULL;
		char choose;
		//Input the first char of what the user types. If it's a c, f, or q, choose console, file, or quit respectively.
		cout << "Do you want to enter the numbers through the \"console\", through a \"file\", or \"quit\" the program?" << endl << "Choose: ";
		cin >> choose;
		cin.ignore(256, '\n');
		//They gave us valid input, so we ask them for the file.
		if (choose == 'f' || choose == 'F') {
			char fileIn[81];
			cout << "Input the path to the input file." << endl << "Path: ";
			cin >> fileIn;
			//Attempt to open file. If it opens, read contents and create heap. Otherwise, program kills itself.
			ifstream input (fileIn);
			if (input.is_open()) {
				char* nums = new char[501];
				//If file isn't empty, get and print contents.
				if (!input.eof()) {
					input.getline(nums, 500);
					cout << "File contents:" << endl;
					cout << nums;
					//We walk through the input from the file and add numbers as we find them to the BST.
					int temp = 0;
					bool isNum = false;
					//If it's a digit, multiply temp (the preexisting portion of the number) by 10 then add the digit.
					for (int i = 0; i < strlen(nums); i++) {
						if (isdigit(nums[i])) {
							temp *= 10;
							temp += nums[i] - '0';
							isNum = true;
						}
						//Otherwise if it's whitespace, add the number to the BST.
						else if (nums[i] != '\0' && nums[i] != '\n'){
							add(root, temp);
							temp = 0;
							isNum = false;
						}
					}
					//This here is a workaround to deal with loose zeroes being appended to input.
					if (isNum) {
						add(root, temp);
						temp = 0;
					}
					//Print the BST.
					cout << endl << "This is the binary search tree:" << endl;
					print(root);
					bool isFinished = false;
					//While they haven't typed "c" (for continue), we ask them what they want to do with the tree
					while (!isFinished) {
						cout << "Would you like to \"print\" the tree, \"add\" a node to the tree, \"search\" for a value, \"delete\" a node, or \"continue\"?" << endl << "Input: ";
					  cin >> choose;
					  cin.ignore(256, '\n');
					  if (choose == 'p' || choose == 'P') print(root);
					  else if (choose == 'a' || choose == 'A') {
						  int target;
						  //Prompt for a target for addition
						  cout << "Please enter the value of the Node you want to add." << endl << "Target: ";
						  cin >> target;
						  add(root, target);

					  }
					  //Search for a number
					  else if (choose == 's' || choose == 'S') {
						  int target;
						  cout << "Please enter the value of the Node you want to search for." << endl << "Target: ";
						  cin >> target;
						  search(root, target);

					  }
					  //Delete a number, if it exists
					  else if (choose == 'd' || choose == 'D') {
						  int target;
						  cout << "Please enter the value of the Node you want to delete." << endl << "Target: ";
						  cin >> target;
						  remove(root, target);

					  }
					  else if (choose == 'c' || choose == 'C') isFinished = true;
					  else cout << "That input is invalid. Please try again." << endl;
					}
				}
				//Close input
				input.close();
			}
			else cout << "Unable to open file" << endl;
		}
		//If they want to input from console, read their input from console then proceed the exact same way as in file.
		else if (choose == 'c' || choose == 'C') {
			char* nums = new char[501];
			cout << "Input the numbers, each separated by a space." << endl << "Numbers: ";
			cin.getline(nums, 500);
			cout << "Your input:" << endl;
			cout << nums;
			//Creates the BST the same way as if input was from file.
			int temp = 0;
			bool isNum = false;
			for (int i = 0; i < strlen(nums); i++) {
				if (isdigit(nums[i])) {
					temp *= 10;
					temp += nums[i] - '0';
					isNum = true;
				}
				else if (nums[i] != '\0' && nums[i] != '\n'){
					add(root, temp);
					temp = 0;
					isNum = false;
				}
			}
			if (isNum) {
				add(root, temp);
				temp = 0;
			}
			cout << endl << "This is the binary search tree:" << endl;
			print(root);
			bool isFinished = false;
			while (!isFinished) {
			  cout << "Would you like to \"print\" the tree, \"add\" a node to the tree, \"search\" for a value, \"delete\" a node, or \"continue\"?" << endl << "Input: ";
			  cin >> choose;
			  cin.ignore(256, '\n');
			  if (choose == 'p' || choose == 'P') print(root);
			  else if (choose == 'a' || choose == 'A') {
				  int target;
				  cout << "Please enter the value of the Node you want to add." << endl << "Target: ";
				  cin >> target;
				  add(root, target);

			  }
			  else if (choose == 's' || choose == 'S') {
				  int target;
				  cout << "Please enter the value of the Node you want to search for." << endl << "Target: ";
				  cin >> target;
				  search(root, target);

			  }
			  else if (choose == 'd' || choose == 'D') {
				  int target;
				  cout << "Please enter the value of the Node you want to delete." << endl << "Target: ";
				  cin >> target;
				  remove(root, target);

			  }
			  else if (choose == 'c' || choose == 'C') isFinished = true;
			  else cout << "That input is invalid. Please try again." << endl;
			}

		}
		//If user wants to, quit the program.
		else if (choose == 'q' || choose == 'Q') {
			running = false;
			cout << "Ending program..." << endl << "Thanks for using this program!" << endl;
		}
		else
			cout << "That input is invalid." << endl;
	}
	return 0;
}

//Add the node to the tree.
void add(RedBlackBinaryNode* & root, int newNode) {
	RedBlackBinaryNode* current = root;
	RedBlackBinaryNode* addedNode;
	//If tree is empty, root equals the new node
	if (root == NULL)
		root = new RedBlackBinaryNode(NULL, newNode, true);
	else {
		//Otherwise, shift left if node is equal to or less than current and shift right otherwise until the end of the tree is reached
		bool hasAdded = false;
		while (!hasAdded) {
			if (newNode > current->getData()) {
				if (current->getRight() == NULL) {
					current->setRight(new RedBlackBinaryNode(current, newNode, false));
					addedNode = current->getRight();
					hasAdded = true;
				}
				else
					current = current->getRight();
			}
			else {
				if (current->getLeft() == NULL) {
					current->setLeft(new RedBlackBinaryNode(current, newNode, false));
					addedNode = current->getLeft();
					hasAdded = true;
				}
				else
					current = current->getLeft();
			}
		}
		//Walk through the red-black cases and deal with them
		case1(addedNode, root);


	}
}

//Prints the BST. Prints each node and its children
void print(RedBlackBinaryNode* root) {
	//The function is recursive
	bool left = false;
	bool right = false;
	if (root != NULL) {
		cout << "Node: " << root->getData() << endl;
		if (root->getLeft() != NULL) {
			cout << "Left child: " << root->getLeft()->getData() << endl;
			left = true;
		}
		else
			cout << "Left child: None" << endl;
		if (root->getRight() != NULL) {
			cout << "Right child: " << root->getRight()->getData() << endl;
			right  = true;
		}
		else
			cout << "Right child: None" << endl;
		if (root->getIsBlack()) cout << "Color: Black" << endl;
		else cout << "Color: Red" << endl;
		cout << endl;
		if (left)
			print(root->getLeft());
		if (right)
			print(root->getRight());
	}
	else cout << "The tree is empty." << endl;
}

//Deletes the targeted node, if its exists.
void remove(RedBlackBinaryNode* & root, int target) {
	//TODO Make deletion preserve red-black property
	RedBlackBinaryNode* current = root;
	RedBlackBinaryNode* parent = NULL;
	bool targetIsLeftChild = false;
	bool hasLeft = false;
	bool hasRight = false;
	//There are just a whole lotta conditions to check. We check all unique ones.
	while (current->getData() != target) {
		if (target > current->getData()) {
			if (current->getRight() == NULL) {
			  cout << "A node with value of \"" << target << "\" does not exist in the tree." << endl;
				return;
			}
			else {
				parent = current;
				current = current->getRight();
			}
		}
		else {
			if (current->getLeft() == NULL) {
			  cout << "A node with value of \"" << target << "\" does not exist in the tree." << endl;
				return;
			}
			else {
				parent = current;
				current = current->getLeft();
			}
		}
	}
	cout << "A node with value of \"" << target << "\" was removed from the tree." << endl;
	//If the node we are deleting only has one child, go ahead and call "deleteOneChild" on it.
	//Otherwise, find the predecessor and call "deleteOneChild" on it after overriding the target with predecessor's data.
	if (current->getLeft() != NULL) hasLeft = true;
	if (current->getRight() != NULL) hasRight = true;
	if (parent != NULL)
		if (parent->getLeft() == current) targetIsLeftChild = true;

	if (hasLeft) {
		if (!hasRight) {
			deleteOneChild(current, root);
		}
		else {
			RedBlackBinaryNode* rightmost = current->getLeft();
			RedBlackBinaryNode* rightmostParent = current;
			while (rightmost->getRight() != NULL){
				rightmostParent = rightmost;
				rightmost = rightmost->getRight();
			}
			current->setData(rightmost->getData());
			deleteOneChild(rightmost, root);
		}
	}
	else if (hasRight) {
		deleteOneChild(current, root);
	}
	else {
		deleteOneChild(current, root);
	}

}

//Searches for the given node and prints whether or not it's in the tree
void search(RedBlackBinaryNode* root, int target) {
	RedBlackBinaryNode* current = root;
	if (root == NULL) {
		cout << "The root is null. There is nothing in this tree, especially not " << target << "." << endl;
		return;
	}
	//Shifts left if the target is less than the current node data, shifts right otherwise.
	while (current != NULL) {
		if (target == current->getData()) {
			cout << "The value " << target << " exists in this tree." << endl;
			return;
		}
		if (target <= current->getData()) {
			current = current->getLeft();
		}
		else current = current->getRight();
	}
	cout << "The value " << target << " does not exist in this tree." << endl;
}

//Case 1 of insertion: The node is the root, so set it to black.
void case1(RedBlackBinaryNode* addedNode, RedBlackBinaryNode* & root) {
	if (addedNode->getParent() == NULL) addedNode->setIsBlack(true);
	else case2(addedNode, root);
}

//Case 2 of insertion: The parent is black.
void case2(RedBlackBinaryNode* addedNode, RedBlackBinaryNode* & root) {
	if (addedNode->getParent()->getIsBlack()) return;
	else case3(addedNode, root);
}

//Case 3 of insertion: Both the parent and uncle are red, so the parent/uncle are set to black and the grandparent is
//set to red
void case3(RedBlackBinaryNode* addedNode, RedBlackBinaryNode* & root) {
	RedBlackBinaryNode* uncle = addedNode->uncle();
	if (uncle != NULL && !uncle->getIsBlack()) {
		addedNode->getParent()->setIsBlack(true);
		uncle->setIsBlack(true);
		addedNode->grandparent()->setIsBlack(false);
		case1(addedNode->grandparent(), root);
	}
	else case4(addedNode, root);
}

//Case 4 of insertion: Uncle is NULL and node is either the left child of parent which is the right child grandparent
//or vice versa. Perform the proper rotation so that they are both left-left or both right-right.
void case4(RedBlackBinaryNode* addedNode, RedBlackBinaryNode* & root) {
	RedBlackBinaryNode* grandparent = addedNode->grandparent();
	if (addedNode == addedNode->getParent()->getRight() && addedNode->getParent() == grandparent->getLeft()) {
		rotateLeft(addedNode->getParent(), root);
		addedNode = addedNode->getLeft();
	}
	else if (addedNode == addedNode->getParent()->getLeft() && addedNode->getParent() == grandparent->getRight()) {
			rotateRight(addedNode->getParent(), root);
			addedNode = addedNode->getRight();
	}
	case5(addedNode, root);
}

//Case 5 of insertion: Both node and its parent are left-left or right-right. Perform the proper rotation
//on grandparent and switch the colors of parent and grandparent. Now the tree is balanced for sure.
void case5(RedBlackBinaryNode* addedNode, RedBlackBinaryNode* & root) {
	RedBlackBinaryNode* grandparent = addedNode->grandparent();
	addedNode->getParent()->setIsBlack(true);
	grandparent->setIsBlack(false);
	if (addedNode == addedNode->getParent()->getLeft()) rotateRight(grandparent, root);
	if (addedNode == addedNode->getParent()->getRight()) rotateLeft(grandparent, root);
}

//Rotate left. Target becomes the left child of its right child.
void rotateLeft(RedBlackBinaryNode* target, RedBlackBinaryNode* & root) {
	RedBlackBinaryNode* tParent = target->getParent();
	RedBlackBinaryNode* tSwitch = target->getRight();
	RedBlackBinaryNode* tSChildLeft = tSwitch->getLeft();
	if (tParent != NULL) {
		if (target == tParent->getLeft()) tParent->setLeft(tSwitch);
		else tParent->setRight(tSwitch);
		tSwitch->setParent(tParent);
		tSwitch->setLeft(target);
		target->setParent(tSwitch);
		target->setRight(tSChildLeft);
		if (tSChildLeft != NULL) tSChildLeft->setParent(target);
	}
	else {
		root = tSwitch;
		tSwitch->setParent(NULL);
		tSwitch->setLeft(target);
		target->setParent(tSwitch);
		target->setRight(tSChildLeft);
		if (tSChildLeft != NULL) tSChildLeft->setParent(target);
	}
}

//Rotate right. Target becomes the right child of its left child.
void rotateRight(RedBlackBinaryNode* target, RedBlackBinaryNode* & root) {
	RedBlackBinaryNode* tParent = target->getParent();
		RedBlackBinaryNode* tSwitch = target->getLeft();
		RedBlackBinaryNode* tSChildRight = tSwitch->getRight();
		if (tParent != NULL) {
			if (target == tParent->getLeft()) tParent->setLeft(tSwitch);
			else tParent->setRight(tSwitch);
			tSwitch->setParent(tParent);
			tSwitch->setRight(target);
			target->setParent(tSwitch);
			target->setLeft(tSChildRight);
			if (tSChildRight != NULL) tSChildRight->setParent(target);
		}
		else {
			root = tSwitch;
			tSwitch->setParent(NULL);
			tSwitch->setRight(target);
			target->setParent(tSwitch);
			target->setLeft(tSChildRight);
			if (tSChildRight != NULL) tSChildRight->setParent(target);
		}
}

//Deletes the target node, which must only have one child.
void deleteOneChild(RedBlackBinaryNode* & target, RedBlackBinaryNode* & root) {
	cout << "Delete one child" << endl;
	RedBlackBinaryNode* child = target->getLeft() != NULL ? target->getLeft() : target->getRight();
	//We basically cut the target node out of the tree and move its child (if it has one) up to where it was.
	//If target has no children, create a (temporary) node with data NULL (0).
	if (target->getParent() != NULL && target == target->getParent()->getLeft()) {
		if (child == NULL) {
			if (target->getParent() != NULL) {
				target->getParent()->setLeft(new RedBlackBinaryNode(target->getParent(), NULL, true));
				child = target->getParent()->getLeft();
			}
			else root = NULL;
		}
		else {
			if (target->getParent() != NULL) {
				target->getParent()->setLeft(child);
			}
			else root = child;
		}
	}
	else {
		if (child == NULL) {
			if (target->getParent() != NULL) {
				target->getParent()->setRight(new RedBlackBinaryNode(target->getParent(), NULL, true));
				child = target->getParent()->getRight();
			}
			else root = NULL;
		}
		else {
			if (target->getParent() != NULL) {
				target->getParent()->setRight(child);
			}
			else root = child;
		}

	}
	//Sets child's parent pointer, redundantly checking that child is actually a node and not just NULL.
	if (child != NULL) child->setParent(target->getParent());
	//If the target is black and its child is red, change child to black and we're done. Otherwise, things get messier...
	if (target->getIsBlack()) {
		if (child != NULL && !child->getIsBlack()) child->setIsBlack(true);
		else if (child != NULL){
			//Start doing red-black delete cases.
			deleteCase1(child, root);
		}
	}
	//The delete cases were used to rebalance the tree. Now we can remove the NULL node we created (if we needed to create one).
	if (child->getData() == NULL) {
		if (child->getParent() == NULL) {
			delete child;
			root = NULL;
		}
		else if (child->getParent()->getLeft() == child) {
			RedBlackBinaryNode* temp = child->getParent();
			delete child;
			temp->setLeft(NULL);
		}
		else {
			RedBlackBinaryNode* temp = child->getParent();
			delete child;
			temp->setRight(NULL);
		}
	}
	//Destruct the target
	delete target;
}

//Deletion case 1: If target is the new root, we're done. Otherwise, do deletion case 2.
void deleteCase1(RedBlackBinaryNode* & target, RedBlackBinaryNode* & root) {
	cout << "Delete case 1" << endl;
	if (target->getParent() != NULL) deleteCase2(target, root);
}

//Deletion case 2: If target's sibling is red, rotate the tree. Then call case 3.
void deleteCase2(RedBlackBinaryNode* & target, RedBlackBinaryNode* & root) {
	cout << "Delete case 2" << endl;
	RedBlackBinaryNode* sibling = target->sibling();
	if (sibling != NULL && !sibling->getIsBlack()) {
		target->getParent()->setIsBlack(false);
		sibling->setIsBlack(true);
		if (target == target->getParent()->getLeft()) rotateLeft(target->getParent(), root);
		else rotateRight(target->getParent(), root);
	}
	deleteCase3(target, root);
}

//Deletion case 3: If target's parent, sibling, and nephews are black, we repaint sibling to red and recursively call
//case 1 on parent. Otherwise, proceed to case 4.
void deleteCase3(RedBlackBinaryNode* & target, RedBlackBinaryNode* & root) {
	cout << "Delete case 3" << endl;
	RedBlackBinaryNode* sibling = target->sibling();
	if (target->getParent()->getIsBlack() && sibling->getIsBlack()
			&& (sibling->getLeft() == NULL || sibling->getLeft()->getIsBlack())
			&& (sibling->getRight() == NULL || sibling->getRight()->getIsBlack())) {
		sibling->setIsBlack(false);
		RedBlackBinaryNode* parent = target->getParent();
		deleteCase1(parent, root);
	}
	else deleteCase4(target, root);
}

//Deletion case 4: If target's parent is red and its sibling and nephews are black, swap colors of parent and sibling.
//Else, call case 5.
void deleteCase4(RedBlackBinaryNode* & target, RedBlackBinaryNode* & root) {
	cout << "Delete case 4" << endl;
	RedBlackBinaryNode* sibling = target->sibling();
	if (!target->getParent()->getIsBlack() && sibling->getIsBlack()
			&& (sibling->getLeft() == NULL || sibling->getLeft()->getIsBlack())
			&& (sibling->getRight() == NULL || sibling->getRight()->getIsBlack())) {
		sibling->setIsBlack(false);
		target->getParent()->setIsBlack(true);
	}
	else deleteCase5(target, root);
}

//Deletion case 5: If target's sibling is black and one of its nephews is red while the other is black, rotate
//sibling so that the red nephew goes on top. Then call case 6.
void deleteCase5(RedBlackBinaryNode* & target, RedBlackBinaryNode* & root) {
	cout << "Delete case 5" << endl;
	RedBlackBinaryNode* sibling = target->sibling();
	if (sibling->getIsBlack()) {
		if (target == target->getParent()->getLeft() && sibling->getRight()->getIsBlack() && !sibling->getLeft()->getIsBlack()) {
			sibling->setIsBlack(false);
			sibling->getLeft()->setIsBlack(true);
			rotateRight(sibling, root);
		} else if (target == target->getParent()->getRight() && sibling->getLeft()->getIsBlack() && !sibling->getRight()->getIsBlack()) {
			sibling->setIsBlack(false);
			sibling->getRight()->setIsBlack(true);
			rotateLeft(sibling, root);
		}
	}
	deleteCase6(target, root);
}

//Deletion case 6: Set target's sibling's color to target's parent's color then rotate so that the sibling is on top,
//then set one of the sibling's red children (left or right depends on the direction of tree rotate)
void deleteCase6(RedBlackBinaryNode* & target, RedBlackBinaryNode* & root) {
	cout << "Delete case 6" << endl;
	RedBlackBinaryNode* sibling = target->sibling();
	sibling->setIsBlack(target->getParent()->getIsBlack());
	target->getParent()->setIsBlack(true);
	if (target == target->getParent()->getLeft()) {
		sibling->getRight()->setIsBlack(true);
		rotateLeft(target->getParent(), root);
	}
	else {
		sibling->getLeft()->setIsBlack(true);
		rotateRight(target->getParent(), root);
	}

}
