#include <iostream>
#include <string>
using namespace std;

namespace ariel{

struct Node{
	int data;
	Node* right;
	Node* left;
	Node* parent;
};


class Tree{
public:
	Tree();
	void insert(int a);
	void Insert(int a, Node* now, Node* par);
	int size();
	bool contains(int a);
	Node *Contains(int key, Node *leaf);
	int parent (int a);
	int right (int a);
	int left (int a);
	void remove(int a);
	void print();
	int root();

	Node *Root;
	int num;
};
}
