// Name:Tianchen Zhang
// USC NetID:tzhang03
// CSCI 455 PA5
// Fall 2019


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to not put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  

struct Node {
   std::string key; //Student name
   int value; //value for that integer

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//put function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.


//insert a new node to the list with the given key and val;
//if the node already exists in the list(checks key),
// do nothing and return false, otherwise return true.
bool listInsert(ListType &list, std::string key, int val);

//print the entire list, skips NULL
//print key followed by its value.
//Sample output:
// Tim  98
// Dave 99
// Mary 76
void listPrintAll(ListType list);

//return the total number of entries in the list
//does not count NULL value towards the size.
int listSize(ListType list);

//checks if the list is empty and return true iff contains no node.
bool isEmpty(ListType list);

//checks if the list contains the node with given key value.
//return true iff the list has the node, vise versa.
bool listContains(ListType list, std::string theKey);

//removes the node that has the given key value.
//if the list does not contain the node, return false.
//return true after the node has been removed.
bool listRemove(ListType & list, std::string theKey);

//helper method for ListRemove method, only remove the first
//node of the list iff it is the target.
//Return true iff node is being removed, vise versa.
bool removeHead(ListType & list, std::string theKey);

// keep the following line at the end of the file
#endif
