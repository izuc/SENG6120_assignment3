// Filename: BTNode.h
// Date Created: 26/10/2012
// Author: Lance Baker
// Course: SENG6120
// Student Number: c3128034

#ifndef LANCE_BTNODE_H
#define LANCE_BTNODE_H
namespace lance_project {
	template <class T>
	class BTNode {
		public:
			// The default constructor for the BTNode.
			BTNode();
			// The constructor recieves the data.
			BTNode(T* data);
			// The constructor recieves the data, left, and right node.
			BTNode(T* data, BTNode<T>* left, BTNode<T>* right);
			// The destructor destroys the object.
			~BTNode();
			// The remove object is a recursive method, which removes a specific
			// node matching the received item based on the compareTo method.
			BTNode<T>* remove(BTNode<T>* parent, T* item);
			// Setter for the data.
			void setData(T* data);
			// Setter for the left node.
			void setLeft(BTNode<T>* left);
			// Setter for the right node.
			void setRight(BTNode<T>* right);
			// Getter for the data.
			T* getData();
			// Getter for the left node.
			BTNode<T>* getLeft();
			// Getter for the right node.
			BTNode<T>* getRight();
		private:
			T* data; // The node data.
			BTNode<T>* left; // The left branch.
			BTNode<T>* right; // The right branch.
			// A private method used to locate the smallest node, which is
			// used by the remove method.
			T* min(); 
	};
}
#include "BTNode.template"
#endif
