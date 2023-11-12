#pragma once

#include "Node.h"
class Linked
{
private:
	Node* head;
	Node* tail;
	int size;
public:
	Linked();
	~Linked();
	bool remove(int detract);
	void append(int item);
	void display();
  bool find(int q);
};

