#include <iostream>
#include <string>
#include <iomanip>
#include "Tree.hpp"
using namespace std;

struct Node{
	int data;
	Node* right;
	Node* left;
	Node* parent;
};


namespace ariel{

	Node* Root;
	int num;

	Tree::Tree(){
		Root = NULL;
		num = 0;
	}

	Tree::~Tree(){

	}


	void Tree::insert(int a){
		if (Root == NULL){
					Root = new Node;
					Root->data = a;
					Root->right = NULL;
					Root->left = NULL;
					Root->parent = NULL;
					num++;
				}
				else{
					try{
						Insert (a, Root);
					}catch(string s){
						cerr<<s;
					}
				}
	}

	void Tree::Insert(int a, Node* now){
			if(a == now->data){
				throw string("already here");
				return;
				}
				else{
					if(a > now->data){
						if(now->right == NULL){
							now->right = new Node;
							now->right->data = a;
							now->right->parent = now;
							now->right->right = NULL;
							now->right->left = NULL;
							num++;
						}
						else{
							Insert(a, now->right);
						}
					}
					else{
						if(now->left == NULL){
							now->left = new Node;
							now->left->data = a;
							now->left->right = NULL;
							now->left->parent = now;
							now->left->left = NULL;
							num++;
						}
						else{
							Insert(a, now->left);
						}
					}
				}
		}

	int Tree::size(){
		return num;
	}

	bool Tree::contains(int a){
		if(Contains(a, Root) == NULL){
			return false;
		}
		return true;
		}
	Node* Tree::Contains(int key, Node *leaf){
			if(leaf != NULL){
				if(key == leaf->data){
					return leaf;
				}
				if(key < leaf->data){
					return Contains(key, leaf->left);
				}else{
					return Contains(key, leaf->right);
				}
			}else{
				return NULL;
			}
		}

	int Tree::parent (int a){
		return Contains(a, Root)->parent->data;
	}
	int Tree::right (int a){
		return Contains(a, Root)->right->data;
	}
	int Tree::left (int a){
		return Contains(a, Root)->left->data;
	}

	void Tree::remove(int a){

		}


	/*void remove(int a){
		remove(root, a);
	}

	void remove(Node* leaf, int a){
		if (a == leaf->data){
			if(leaf->right == NULL && leaf->left == NULL){
				free(leaf);
				num--;
				return;
			}
			if(leaf->right != NULL && leaf->left == NULL){
				Node* temp = leaf->right;
				free(leaf);
				leaf = temp;
			}
			if(leaf->left != NULL && leaf->right == NULL){
				Node* temp = leaf->left;
				free(leaf);
				leaf = temp;
			}
			if(leaf->right != NULL && leaf->left != NULL){
				Node* tempR = leaf->right;
				Node* tempL = leaf->left;
				free(leaf);
				if()
			}
		}
		if (a > leaf->data){
			return remove(leaf->right, a);
		}
		if (a < leaf->data){
			return remove (leaf->left, a);
		}
	}*/


	void Tree::print(){

		}

	int Tree::root(){
		return Root->data;
	}



};

/*

int main(){
	ariel::Tree* abs = new ariel::Tree();
	abs->insert(5);
	abs->insert(6);
	abs->insert(4);
	cout<<abs->parent(6);
	//cout<<abs->parent(6);


	aba->insert(6);
	aba->insert(4);
	aba->insert(3);
	aba->insert(2);
	aba->insert(2);
	aba->remove(4);
	cout<<aba->left(5);
	aba->buildTree(aba->Root,100, 10);
	//cout<<aba->Root->left->left->parent->data;
	//cout<<aba->parent(3);



	return 0;
}
*/
