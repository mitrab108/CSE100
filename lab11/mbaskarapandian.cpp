#include <iostream>
#include<string.h> 
#include<stdlib.h>
#include<stdio.h>
#include <string>
#include <sstream>
using namespace std;

//Got help from Github, textbook, and TA
//Was helped by TA here
struct BST
{
    int data;
    int key;
    struct BST *l;
    struct BST *r;
};
struct BST *newNode(int x)
{
    struct BST* temp = (struct BST*)malloc(sizeof(struct BST));
    temp->key = x;
    temp->l = temp->r = nullptr;
    return temp;
}
struct BST *min(struct BST *node)
{
    if(node == nullptr)
    {
        return nullptr;
    }
    struct BST *temp = node;
    while(temp && temp ->l != nullptr)
    {
        temp = temp->l;
    }
    return temp;
}
struct BST* Insert(BST *node, int z)
{
    
    if(node ==nullptr)
    {
        return newNode(z);
    }
    if(z<node->key)
    {
        node->l = Insert(node->l, z);
    }
    else
    {
        node->r = Insert(node->r, z);
    }
    return node;
}
struct BST* Delete(BST *node, int z)
{
    if(node == nullptr)
    {
        return node;
    }
    if(z < node->key)
    {
        node->l = Delete(node->l, z);
    }
    else if(z > node->key)
    {
        node->r = Delete(node->r, z);
    }
    else
    {
        if(node->l == nullptr)
        {
            struct BST *temp = node->l;
            free(node);
            return temp;
        }
        else if (node->r == nullptr) 
        {
            struct BST* temp = node->l;
            free(node);
            return temp;
        }
        struct BST *x = min(node->r);
        node->key = x->key;
        node->r = Delete(node->r, x->key);
    }
    return node;
}
void inOrder(BST *node) 
{
    if(node != nullptr)
    {
        inOrder(node->l);
        cout << node->key <<endl;
        inOrder(node->r);
    }
}
void preOrder(struct BST *node)
{
    if(node != nullptr)
    {
        cout<<node->key<<endl;
        preOrder(node->l);
        preOrder(node->r);
    }
}
void postOrder(struct BST *node)
{
    if(node != nullptr)
    {
        postOrder(node->l);
        postOrder(node->r);
        cout<<node->key<<endl;
    }
}
int main()
{
    struct BST* node = nullptr;
    string command;
    int val;
    int index = 0;
    cin>> command;
    while(command != "e")
    {
        if(command == "i")
        {
            cin>>val;
            node = Insert(node, val);
        }
        if(command == "d")
        {
            cin>>val;
            node = Delete(node, val);
        }
        if(command == "in")
        {
            inOrder(node);
            cout<<"++++++++++++++++++++"<<endl;
        }
        if(command == "pre")
        {
            preOrder(node);
            cout<<"++++++++++++++++++++"<<endl;
        }
        if(command == "post")
        {
            postOrder(node);
            cout<<"++++++++++++++++++++"<<endl;
        }
        cin>>command;
    }
    return 0;
}