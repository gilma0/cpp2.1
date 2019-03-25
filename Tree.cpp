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
					Insert (a, Root, NULL);
				}
	}

	void Tree::Insert(int a, Node* now, Node* par){
			if(a == now->data){
					cout<<"already here\n";
					return;
				}
				else{
					if(a > now->data){
						if(now->right == NULL){
							now->right = new Node;
							now->right->data = a;
							now->parent = par;
							now->right->right = NULL;
							now->right->left = NULL;
							num++;
						}
						else{
							Insert(a, now->right, now);
						}
					}
					else{
						if(now->left == NULL){
							now->left = new Node;
							now->left->data = a;
							now->left->right = NULL;
							now->parent = par;
							now->left->left = NULL;
							num++;
						}
						else{
							Insert(a, now->left, now);
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
		return 0;//Contains(a, Root)->parent->data;
	}
	int Tree::right (int a){
		return 0;//Contains(a, Root)->right->data;
	}
	int Tree::left (int a){
		return 0;//Contains(a, Root)->left->data;
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
	Tree *aba = new Tree();
	aba->insert(5);
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
}*/
