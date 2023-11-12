#pragma once


#ifndef LEAF_H
#define LEAF_H

class Leaf
{
public:
	int data;
	Leaf* left;
	Leaf* right;
	Leaf() : data(0), left(nullptr), right(nullptr) {}
	Leaf(int data) : data(data), left(nullptr), right(nullptr) {}
  int degree() const{
    int res = 0;
	  if (left != nullptr) {
		  res += 1;
	  }
	  if (right != nullptr) {
		  res += 1;
	  }
	return res;

  };
};
#endif


