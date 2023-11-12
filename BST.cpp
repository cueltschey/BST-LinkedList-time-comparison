#include "BST.h"
#include "Leaf.h"
bool BST::insert(Leaf*& node, int data)
{
	if (node == nullptr) {
		node = new Leaf(data);
		return true;
	}
	if (data < node->data)
		return insert(node->left, data);
	if (data > node->data)
		return insert(node->right, data);
	return false;
}

bool BST::remove(Leaf*& node, int data)
{
	if (node == nullptr)
		return false;
	if (data < node->data)
		return remove(node->left, data);
	if (data > node->data)
		return remove(node->right, data);
	int deg = node->degree();
	if (deg == 0)
	{
		delete node;
		node = nullptr;
	}
	else if (deg == 1)
	{
		Leaf* tmp = node;
		if (node->left != nullptr) {
			node = node->left;
		}
		else {
			node = node->right;
		}
		delete tmp;
	}
	else
	{
		Leaf* tmp = node->left;
		while (tmp->right != nullptr)
		{
			tmp = tmp->right;
		}
		node->data = tmp->data;
		remove(node->left, tmp->data);
	}
	return true;
}
bool BST::find(Leaf* node, int data) {
	if (node == nullptr) { return false; }
	if (data == node->data) { return true; }
	if (data < node->data)
		return find(node->left, data);
	if (data > node->data)
		return find(node->right, data);
	return false;

}
void BST::postOrder(Leaf* node, ostream& os)
{
	if (node == nullptr) return;
	postOrder(node->left, os);
	postOrder(node->right, os);
	os << node->data << " ";
}
BST::~BST()
{
}
void BST::inOrder(Leaf* node, ostream& os) {

	if (node == nullptr) return;
	inOrder(node->left, os);
	os << node->data << " ";
	inOrder(node->right, os);
}
void BST::preOrder(Leaf* node, ostream& os) {
	if (node == nullptr) return;
	os << node->data << " ";
	preOrder(node->left, os);
	preOrder(node->right, os);

}

bool BST::insert(int data) {
	return insert(root, data);
}
bool BST::remove(int data) {
	return remove(root, data);
}
bool BST::find(int data) {
	return find(root, data);
}
void BST::inOrder(ostream& os){
	inOrder(root, os);
}
void BST::preOrder(ostream& os) {
	preOrder(root, os);
}
void BST::postOrder(ostream& os) {
	postOrder(root, os);
}
