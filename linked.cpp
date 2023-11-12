#include "linked.h"
#include <iostream>

using namespace std;

Linked::Linked() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

Linked::~Linked() {

}

bool Linked::remove(int detract) {
	Node* temp = head;
	Node* prev = nullptr;
	if (head->data == detract) {
		head = head->next;
		delete temp;
		return true;
	}
	temp = temp->next;
	prev = head;
	while (temp != nullptr) {
		if (temp->data == detract) {
			prev->next = temp->next;
			delete temp;
			return true;
		}
		prev = temp;
		temp = temp->next;
	}
	return false;
}

void Linked::append(int item) {
	Node* temp = new Node(item);
	if (size == 0) {
		head = temp;
	}
	else if(size == 1) {
		head->next = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
	size++;
}

void Linked::display() {
	Node* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

bool Linked::find(int q){
  Node* temp = head;
  while(temp->next != nullptr){
    if(temp->data == q){
      return true;
    }
    temp = temp->next;
  }
  return false;
}
