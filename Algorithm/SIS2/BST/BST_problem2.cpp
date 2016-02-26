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
	string data;
		Node * left;
		Node * right;
		Node * parent;
    Node(string d){
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

    Node *deleteNode(Node *&node, string data)
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

void insertNode(Node *node, string data){
	if (node == NULL)
	        {


	            ROOT = new Node(data);
	        }
	        else if (data < node->data && node->left == NULL)
	        {

	            node->left = new Node(data);
	            node->left->parent = node;
	        }
	        else if (data >= node->data && node->right == NULL)
	        {

	            node->right = new Node(data);
	            node->right->parent = node;
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
            cout<<node->data<< " , ";
            printInOrder(node->right);
        }
    }
   bool search(Node *node, string data)
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
};

int main(){
	OperationsBST *bst = new OperationsBST();
    string op;
    while (cin >> op) {
        string data;
        if (op != "print")
            cin >> data;
        if (op == "add")
	        bst->insertNode(bst->ROOT,data);
        if (op == "find")
            cout << (bst -> search(bst -> ROOT, data) ? "YES" : "NO") << endl;
	    if (op == "print")
        {
            bst -> printInOrder(bst -> ROOT);
            cout << endl;
        }
    }

    return 0;
}

