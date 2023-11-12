

#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node* next;
	int data;
	
    Node()
    {
        data = 0;
        next = nullptr;
    };

    // takes in basic title and author information
    // assigns next pointer to nullptr
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    };

    // takes in basic title and author information
    // assigns next pointer to a taken in Node
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    };
};

#endif // NODE_H