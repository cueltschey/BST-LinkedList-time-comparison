#pragma once

#include <iostream>
#include "Leaf.h"
using namespace std;
class BST
{
private:
	Leaf* root;
	bool insert(Leaf*& node, int data);
	bool remove(Leaf*& node, int data);
	bool find(Leaf* node, int data);
	void inOrder(Leaf* node, ostream& os);
	void preOrder(Leaf* node, ostream& os);
	void postOrder(Leaf* node, ostream& os);
public:
	BST() : root(nullptr) {}
	~BST();
	bool insert(int data);
	bool remove(int data);
	bool find(int data);
	void inOrder(ostream& os);
	void preOrder(ostream& os);
	void postOrder(ostream& os);
};

