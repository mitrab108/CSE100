#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

//Got help from the textbook and GITHUB
int Key (int x, int size) 
{
    return (x % size);
}

void Insert(list<int> *llist, int i, int val)
{
    llist[i].push_front(val);
}
void Delete(list<int> *llist, int index, int val, int x)
{
    list<int>::iterator i;
    for(i = llist[index].begin(); i != llist[index].end(); i++)
    {
        if(*i == val)
        {
            llist[index].erase(i);
            cout<<val<<" : DELETED"<<endl;
            cout<<"++++++++++++++++++++"<<endl;
            return;
        }
    }
    cout<<val<<" : DELETE FAILED"<<endl;
    cout<<"++++++++++++++++++++"<<endl;      
}
void Search(list<int> *llist, int index, int val, int x)
{
    int count = 0;

    list<int>::iterator i;
    for(i = llist[index].begin(); i != llist[index].end(); i++)
    {
        if(*i == val)
        {
            cout<<val<<" : FOUND AT "<<index<<","<<count<<endl;
            cout<<"++++++++++++++++++++"<<endl;
            return;
        }
        count++;
    }
    cout<<val<<" : NOT FOUND"<<endl;
    cout<<"++++++++++++++++++++"<<endl;
} 
void Print(list<int> *llist, int x)
{
    for (int i = 0; i < x; i++)
    {
        cout<<i<<" : ";
        list<int>::iterator j;
        for (j = llist[i].begin(); j != llist[i].end(); j++)
        {
            cout << *j;
            list<int>::iterator k = j;
            if (k++ != llist[i].end())
            {
                if (llist[i].size() != 0)
                {
                    if(k != llist[i].end())
                        cout << "->";
                }
            }
        }
        cout<<endl;
   
    }
    cout<<"++++++++++++++++++++"<<endl;
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
        }
        if(command == "pre")
        {
            preOrder(node);
        }
        if(command = "post")
        {
            postOrder(node);
        }
        cin>>command;
    }
    return 0;
}