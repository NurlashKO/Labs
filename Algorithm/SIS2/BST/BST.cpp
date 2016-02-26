/*
 * BST.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: kathrine
 */
#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using namespace std;

const int INF = int(2e9);

class Node{

public:
	int data;
		Node * left;
		Node * right;
		Node * parent;
    Node(int d){
		data = d;
		left=NULL;
		right=NULL;
		parent=NULL;
    };
    Node(){

       };
};
class OperationsBST{

public:
	Node * ROOT;
	OperationsBST(){
		ROOT = NULL;
	};

    Node *deleteNode(Node *&node, int data)
    {
        if (node == NULL) return NULL;
        if (node -> data == data)
        {
            Node *Right = node -> right;
            Node *Left = node -> left;
            if (!Left && !Right)
            {
                node = NULL;
                return node;
            }
            if (!Left)
            {
                node = NULL;
                return Right;
            }
            if (!Right)
            {
                node = NULL;
                return Left;
            }

                node = Left;
                Node *cur = Right;
                while (cur -> left)
                    cur = cur -> left;
                cur -> left = node -> right;
                node -> right = Right;
    
                return node;
        }
        else
        if (data < node -> data)
        {
            node -> left = deleteNode(node -> left, data);
            return node;
        }
        else
        {
            node -> right = deleteNode(node -> right, data);
            return node;
        }
    }

void insertNode(Node *node, int data){
	if (node == NULL)
	        {


	            ROOT = new Node(data);
	            cout<<"Root initialized \n";
	        }
	        else if (data < node->data && node->left == NULL)
	        {

	            node->left = new Node(data);
	            node->left->parent = node;
	            cout<<"left initialized \n";
	        }
	        else if (data >= node->data && node->right == NULL)
	        {

	            node->right = new Node(data);
	            node->right->parent = node;
	            cout<<"right initialized \n";
	        }
	        else
	        {
	            if (data < node->data)
	            {
	                insertNode(node->left, data);
	            }
	            else
	            {
	                insertNode(node->right, data);
	            }
}
}

   void printPreOrder(Node * node)
    {
        if (node != NULL)
        {
            cout<<node->data<< " - ";
            printPreOrder(node->left);
            printPreOrder(node->right);
        }
    }
   void printPostOrder(Node * node)
    {
        if (node != NULL)
        {
            printPostOrder(node->left);
            printPostOrder(node->right);
            cout << node -> data << " - "; 
        }
    }
   void printInOrder(Node * node)
    {
        if (node != NULL)
        {
            printInOrder(node->left);
            cout<<node->data<< " - ";
            printInOrder(node->right);
        }
    }
   bool search(Node *node, int data)
      {
          if (node == NULL)
          {
              return false;
          }
          else if (node->data == data)
          {
              return true;
          }
          else
          {
              if (data < node->data)
              {
                  return search(node->left, data);
              }
              else
              {
                  return search(node->right, data);
              }
          }
      }
    int find_max(Node *node)
    {
        while (node -> right)
            node = node -> right;
        return node -> data;
    }
    int find_min(Node *node)
    {
        while (node -> left)
            node = node -> left;
        return node -> data;
    }
};

int main(){
	OperationsBST *bst = new OperationsBST();
	int n;
	cout<<"Print number of nodes \n";
	cin>>n;
	int tmp;



	//node *first = new node(tmp);
	for(int i=0;i<n;i++){
		tmp = rand()%100;
		cout<<tmp<<", ";
	bst->insertNode(bst->ROOT,tmp);

	}
	cout<<endl;
	bst->printInOrder(bst->ROOT);
	cout<<endl;
	cout<<(bst->search(bst->ROOT, 83) ? "Found" : "Not Found");
    cout << endl;
    bst -> ROOT = bst->deleteNode(bst -> ROOT, 7);
    bst -> ROOT = bst->deleteNode(bst -> ROOT, 30);
    bst->printInOrder(bst->ROOT);
    cout << endl;
    bst->printPreOrder(bst -> ROOT);
    cout << endl;
    bst->printPostOrder(bst -> ROOT);
    cout << endl;
    cout << "Max : " << bst -> find_max(bst -> ROOT) << endl;
    cout << "MIN : " << bst -> find_min(bst -> ROOT) << endl;
	return 0;
}


