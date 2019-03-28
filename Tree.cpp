#include <iostream>
#include <string>
#include <iomanip>
#include "Tree.hpp"
using namespace std;


namespace ariel{

	Node* Root;
	int num;

	Tree::Tree(){
		Root = NULL;
		num = 0;
	}


	Tree::~Tree(){
		destroyTree(Root);
		delete(this);
	}
	void Tree::destroyTree(Node* leaf){
		if (leaf == NULL) {
			return;
		}
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete(leaf);
	}




	void Tree::insert(int a){
		if (Root == NULL){
			Root = new Node;
			Root->data = a;
			Root->right = NULL;
			Root->left = NULL;
			Root->parent = NULL;
			num++;
		}else{
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
		}else{
			if(a > now->data){
				if(now->right == NULL){
					now->right = new Node;
					now->right->data = a;
					now->right->parent = now;
					now->right->right = NULL;
					now->right->left = NULL;
					num++;
				}else{
					Insert(a, now->right);
				}
			}else{
				if(now->left == NULL){
					now->left = new Node;
					now->left->data = a;
					now->left->right = NULL;
					now->left->parent = now;
					now->left->left = NULL;
					num++;
				}else{
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
		Node* temp = Contains(a, Root);
		remove(a, temp);
		num--;
		return;
		}

	void Tree::remove(int a, Node* leaf){
		if (leaf->right == NULL && leaf->left == NULL){
			if (leaf->data == Root->data){
				Root = NULL;
				delete(leaf);
				return;
			}
			if (leaf->parent->right->data == leaf->data){
				leaf->parent->right = NULL;
			}else{
				leaf->parent->left = NULL;
			}
			delete(leaf);
			return;
		}
		if (leaf->right == NULL){
			if (leaf->data == Root->data){
				Root = leaf->left;
				delete(leaf);
				return;
			}
			if (leaf->parent->right->data == leaf->data){
				leaf->parent->right = leaf->left;
			}else{
				leaf->parent->left = leaf->left;
			}
			delete(leaf);
			return;
		}
		if (leaf->left == NULL){
			if (leaf->data == Root->data){
				Root = leaf->right;
				delete(leaf);
				return;
			}
			if (leaf->parent->right->data == leaf->data){
				leaf->parent->right = leaf->right;
			}else{
				leaf->parent->left = leaf->right;
			}
			delete(leaf);
			return;
		}
		Node* temp = closest(leaf->right);
		if (temp->right != NULL){
			leaf->right = temp->right;
		}
		leaf->data = temp->data;
		delete(temp);
		return;
	}



	Node* Tree::closest(Node* now){
		if (now->left == NULL && now->right == NULL){
			now->parent->left = NULL;
			return now;
		}else{
			if (now->left != NULL){
				closest(now->left);
			}else{
				return now;
			}
		}
	}

	void Tree::print(){
			print(Root);
			}
	void Tree::print(Node* leaf){
			if(leaf==NULL){
				return;
			}
			print(leaf->left);
			cout<<leaf->data<<",";
			print(leaf->right);
		}


	int Tree::root(){
		return Root->data;
	}

	void Tree::buildTree(Node* root, int scrWidth, int itemWidth)
		// breadth-first traversal with depth limit based on screen width and output field width for one elemet
		{
		    bool notFinished = false;
		    // check the root
		    if (root)
		    {
		        notFinished = true;
		    }
		    // calculate maximum possible depth
		    int depth = 1;
		    int field = scrWidth;
		    while (field > itemWidth)
		    {
		        depth++;
		        field /= 2;
		    }
		    // check result
		    if (depth < 1)
		    {
		        cout << " -= erroneous output options =-" << endl;
		        return;
		    }
		    Node** pItems = new Node*[1];
		    *pItems = root; // pointer to item on the first level
		    int itemCnt = 1;
		    int divWidth = 1;
		    // loop for output not more than depth levels until the data is not finished
		    // where level is current depth of tree, and root is on the first level
		    for (int level = 1; level <= depth && notFinished; level++)
		    {
		        itemCnt = (level == 1) ? 1 : (itemCnt * 2);
		        divWidth *= 2;
		        // make list of pointers to refer items on next level
		        Node** list = new Node*[itemCnt * 2];
		        // output all utems of that level
		        int nextCnt = 0;
		        notFinished = false;
		        for (int i = 0; i < itemCnt; i++, nextCnt += 2)
		        {
		            int curWidth = (scrWidth / divWidth) * ((i > 0) ? 2 : 1);
		            cout << setw((curWidth>=itemWidth) ? curWidth:(itemWidth/(1+(i==0))));
		            if (pItems[i])
		            {
		                cout << pItems[i]->data;
		                list[nextCnt] = pItems[i]->left;
		                list[nextCnt + 1] = pItems[i]->right;
		                if (list[nextCnt] || list[nextCnt + 1])
		                    notFinished = true;
		            }
		            else
		            {
		                cout << ".";
		                list[nextCnt] = NULL;
		                list[nextCnt + 1] = NULL;
		            }
		        }
		        cout << endl;
		        // free the memory allocated for list of pointers
		        if (pItems)
		            delete[] pItems;
		        pItems = list; // and shift to new one (for next level)
		    }
		    delete[] pItems;
		}

};



int main(){
	ariel::Tree* abs = new ariel::Tree();
	abs->insert(10);
	abs->insert(9);
	abs->insert(11);
	abs->insert(13);
	abs->insert(12);
	abs->insert(15);
	abs->buildTree(abs->Root,100, 10);
	abs->remove(10);
	//cout<<abs->size();
	//abs->insert(5);
	abs->buildTree(abs->Root,100, 10);
	cout<<endl;
	abs->print();
	return 0;
}
