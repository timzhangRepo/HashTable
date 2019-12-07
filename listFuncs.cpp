// Name:Tianchen Zhang
// USC NetID:tzhang03
// CSCI 455 PA5
// Fall 2019


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;
Node::Node(const std::string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}

//*************************************************************************
// put the function definitions for your list functions below
bool listInsert(ListType &list, string key, int val){
    if(listContains(list,key)){
        return false;
    }
    else{
        Node * node = new Node(key, val, list);
        list = node;
        return true;
    }
}
void listPrintAll(ListType list){
    Node *p = list;
    while(p->next!=NULL)
    {
        cout<<p->key<<"   "<<p->value<<"  \n";
        p = p->next;
    }
    cout<<p->key<<"   "<<p->value<<" ";
}

int listSize(ListType list){
    ListType p = list;
    int counter = 0;
    while(p->next!=NULL){
       counter++;
       p = p->next;
    }
    return counter+1;
}
bool listContains(ListType list, std::string theKey){
    Node *p = list;
    while(p!=NULL){
        if(p->key==theKey){
            return true;
        }
        p = p->next;
    }
    return false;
}
bool listRemove(ListType & list, string thekey){
    if(isEmpty(list)) return false;//for empty list, return false;
    if(removeHead(list, thekey )==true){return true;}
    Node * p = list;//Pointer pointed to the first node of the list.
    Node *save;
    while (p->next!=NULL) {
        save = p->next;
        if (p->next->key == thekey){
            if(p->next->next!=NULL){
                p->next = p->next->next;//remove node that are neither head nor tail.
            }
            else{
                p->next = NULL;//remove the tail node'.
            }
            delete save; //reclaiming memory space for deleted node.
            return true;
        }
        p = p -> next;
    }
    return false;
}

bool removeHead(ListType & list, std::string theKey){
    if(list->next==NULL) { //For list only has one node,checks if node match and delete the list.
        if (list->key == theKey){
            delete(list);
            return true;
        }
        else{
            return false;
        }
    }
    Node * p = list;//Pointer pointed to the first node of the list.
    if(list->key == theKey){  //For list has more than one node
        list = list->next; //remove the first element of the list;
        delete p; //reclaiming memory used by first node.
        return true;
    }
    else{
        return false;
    }
}
bool isEmpty(ListType list){
    if(list==NULL){
        return true;
    }
    else{
        return false;
    }
}





