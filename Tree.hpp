#include <iostream>
#include <string>

namespace ariel{

struct Node{
	int data;
	Node* right;
	Node* left;
	Node* parent;
};


class Tree{

	Node *Root;
	int num;

	void Insert(int a, Node* now);
	Node *Contains(int key, Node *leaf);

public:
	Tree();
	~Tree();
	void insert(int a);
	int size();
	bool contains(int a);
	int parent (int a);
	int right (int a);
	int left (int a);
	void remove(int a);
	void print();
	int root();


};
}
