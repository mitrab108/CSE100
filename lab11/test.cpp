#include<string.h> 
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<cmath> 
#include <list>
#include <vector>
using namespace std; 

/**
 * Worked closely with Rohit Vemuri
 * by Sidharth Babu
 * 
 * */
 
struct node {
    int data; 
    int key;
    struct node *left, *right;
};
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);
 
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
struct node* minValueNode(struct node* node) {
    if (node == nullptr){
        return nullptr;
    }
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
struct node* deleteNode(struct node* root, int key) {
    if (root == nullptr) {
        return root;
    }
    if (key < root->key) {  
        root->left = deleteNode(root->left, key);
    }
   
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
 
void printPostorder(struct node* node) { 
    if (node == nullptr) {
        return; 
    }
    printPostorder(node->left); 
    printPostorder(node->right); 
    cout << node->key << " "<<endl;  
} 
void printPreorder(struct node* node) { 
    if (node == nullptr) {
        return; 
    }
    cout << node->key << " "<<endl; 
    printPreorder(node->left);  
    printPreorder(node->right); 
}  
void inorder(node *root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->key << " "<<endl;
    inorder(root->right);
}
int main() {
    int key; 
    struct node* root = NULL;  
    while(true) {
        string c; 
        cin>>c; 
        if (c == "e") {
            break; 
        }
        else if(c == "i") { 
            cin>>key; 
            root = insert(root, key); 
        }
        else if(c == "d") {
            int num; 
            cin>>num; 
            root = deleteNode(root, num); 
        } 
        else if(c == "post") {
            printPostorder(root); 
            cout<<"++++++++++++++++++++"<<endl;  
        }
        else if(c == "pre") {
            printPreorder(root); 
            cout<<"++++++++++++++++++++"<<endl; 
        }
        else if(c == "in") {
            inorder(root); 
            cout<<"++++++++++++++++++++"<<endl;
        }

    } 
}
