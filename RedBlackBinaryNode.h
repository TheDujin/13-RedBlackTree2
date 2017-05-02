/*
 * RedBlackBinaryNode.h
 *
 *  Created on: May 2, 2017
 *      Author: 293359
 */

#ifndef REDBLACKBINARYNODE_H_
#define REDBLACKBINARYNODE_H_

#include <iostream>
using namespace std;
//TODO Rewrite this
/** -- Class RedBlackBinaryNode --
  * The RedBlackBinaryNode object is a component that, in conjunction with other binary nodes,
  * can form red-black binary trees (self-balancing).
  * The RedBlackBinaryNode can be used to store and access integers.
  *
  * Members:
  * private int data
  * - The int value that the Node holds.
  *    The data of a RedBlackBinaryNode cannot be changed after construction.
  * private RedBlackBinaryNode* left
  * - The RedBlackBinaryNode pointer that represents the left child in the tree.
  * private RedBlackBinaryNode* right
  * - The RedBlackBinaryNode pointer that represents the right child in the tree.
  * private RedBlackBinaryNode* parent
  * - The RedBlackBinaryNode pointer that represents the parent of this RedBlackBinaryNode (root's parent should be null).
  * private bool isBlack
  * - The RedBlackBinaryNode pointer that represents whether or not the node is black (true for black, false for red).
  *
  * Methods:
  * RedBlackBinaryNode(int newData, RedBlackBinaryNode* newParent, bool isItBlack)
  * - Constructs a new RedBlackBinaryNode object
  *    Parameters: newData - the int value that the member data is set to.
  *                newParent - the RedBlackBinaryNode* value that the member parent is set to.
  *                isItBlack - the bool value that the member isBlack is set to.
  * RedBlackBinaryNode* getLeft()
  * - Returns the RedBlackBinaryNode pointer that is the left child of this RedBlackBinaryNode;
  *    returns the value in the member left.
  * RedBlackBinaryNode* getRight()
  * - Returns the RedBlackBinaryNode pointer that is the right child of this RedBlackBinaryNode;
  *    returns the value in the member right.
  * char* getData()
  * - Returns the int value that this RedBlackBinaryNode contains;
  *    returns the value in the member data.
  * bool getIsBlack()
  * - Returns the bool value that is the red-black status of this node;
  *    returns the value in the member isBlack.
  * void setLeft(RedBlackBinaryNode* newLeft)
  * - Sets the value for the member left.
  *    Parameters: newLeft - the RedBlackBinaryNode pointer that the member left is set to.
  * void setRight(RedBlackBinaryNode* newRight)
  * - Sets the value for the member right.
  *    Parameters: newRight - the RedBlackBinaryNode pointer that the member right is set to.
  * void setParent(RedBlackBinaryNode* newParent)
  * - Sets the value for the member parent.
  *    Parameters: newParent - the RedBlackBinaryNode pointer that the member parent is set to.
  * void setIsBlack(bool newIsBlack)
  * - Sets the value for the member isBlack.
  *    Parameters: newIsBlack - the bool value that the member isBlack is set to.
  * RedBlackBinaryNode* grandparent()
  * - Returns the RedBlackBinaryNode pointer that is the grandparent of this RedBlackBinaryNode;
  *    returns the parent of this node's parent.
  * RedBlackBinaryNode* uncle()
  * - Returns the RedBlackBinaryNode pointer that is the uncle of this RedBlackBinaryNode;
  *    returns the child of this node's grandparent that is not this node's parent.
  * ~RedBlackBinaryNode()
  * - Destructs the RedBlackBinaryNode.
  *
  **/
class RedBlackBinaryNode {
 public:
  RedBlackBinaryNode(RedBlackBinaryNode* parent, int newData, bool isItBlack);
  RedBlackBinaryNode* getLeft();
  RedBlackBinaryNode* getRight();
  RedBlackBinaryNode* getParent();
  int getData();
  bool getIsBlack();
  void setLeft(RedBlackBinaryNode* newLeft);
  void setRight(RedBlackBinaryNode* newRight);
  void setParent(RedBlackBinaryNode* newParent);
  void setIsBlack(bool newIsBlack);
  RedBlackBinaryNode* grandparent();
  RedBlackBinaryNode* uncle();
  RedBlackBinaryNode* sibling();
  ~RedBlackBinaryNode();

 private:
  int data;
  RedBlackBinaryNode* left;
  RedBlackBinaryNode* right;
  RedBlackBinaryNode* parent;
  bool isBlack;
};



#endif /* REDBLACKBINARYNODE_H_ */
