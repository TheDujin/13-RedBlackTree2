/*
 * RedBlackBinaryNode.cpp
 *
 *  Created on: May 2, 2017
 *      Author: 293359
 */

#include <iostream>
#include "RedBlackBinaryNode.h"
using namespace std;

//Constructs a Node
RedBlackBinaryNode::RedBlackBinaryNode(RedBlackBinaryNode* newParent, int newData, bool isItBlack) {
  data = newData;
  left = NULL;
  right = NULL;
  parent = newParent;
  isBlack = isItBlack;
}
//Return left
RedBlackBinaryNode* RedBlackBinaryNode::getLeft() {
  return left;
}
//Return right
RedBlackBinaryNode* RedBlackBinaryNode::getRight() {
  return right;
}
//Return parent
RedBlackBinaryNode* RedBlackBinaryNode::getParent() {
  return parent;
}
//Return data
int RedBlackBinaryNode::getData() {
  return data;
}
//Return whether the node is black or red
bool RedBlackBinaryNode::getIsBlack() {
	return isBlack;
}
//Sets left RedBlackBinaryNode
void RedBlackBinaryNode::setLeft(RedBlackBinaryNode* newLeft) {
  left = newLeft;
}
//Sets right RedBlackBinaryNode
void RedBlackBinaryNode::setRight(RedBlackBinaryNode* newRight) {
  right = newRight;
}
//Sets parent RedBlackBinaryNode
void RedBlackBinaryNode::setParent(RedBlackBinaryNode* newParent) {
	parent = newParent;
}
//Sets isBlack property
void RedBlackBinaryNode::setIsBlack(bool newIsBlack) {
	isBlack = newIsBlack;
}
//Return grandparent
RedBlackBinaryNode* RedBlackBinaryNode::grandparent() {
  if (getParent() != NULL)
	  return getParent()->getParent();
  else return NULL;
}
//Return uncle
RedBlackBinaryNode* RedBlackBinaryNode::uncle() {
  RedBlackBinaryNode* gp = grandparent();
  if (gp == NULL) return NULL;
  else if (getParent() == gp->getLeft()) return gp->getRight();
  else return gp->getLeft();
}
//Return sibling
RedBlackBinaryNode* RedBlackBinaryNode::sibling() {
  if (getParent() == NULL) return NULL;
  if (this == getParent()->getLeft()) return getParent()->getRight();
  else return getParent()->getLeft();
}
//Destructs the RedBlackBinaryNode
RedBlackBinaryNode::~RedBlackBinaryNode() {
}




