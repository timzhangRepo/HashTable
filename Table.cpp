// Name:Tianchen Zhang
// USC NetID:tzhang03
// CSCI 455 PA5
// Fall 2019

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
    numEntry = 0;
    hashSize = HASH_SIZE;
    dataLink = new ListType[hashSize]();

}

Table::Table(unsigned int hSize) {
    numEntry = 0;
    hashSize = hSize;
    dataLink = new ListType[hashSize]();
}


int * Table::lookup(const string &key) {
    unsigned int hashValue = hashCode(key);
    Node * p;
    if(!isEmpty(dataLink[hashValue])){  //checks if the list is empty, return NULL iff is empty.
        p = dataLink[hashValue];
        if(listContains(p,key)){    //checks if the list has the node, return NULL iff not
            while(p->key!=key){ //Iterating through the list until find teh value, since it must contains it
                p = p->next;
            }
            return &p->value;
        }else{
            return NULL;
        }
    }
    else{
        return NULL;
    }
}
bool Table::remove(const string &key) {
    //return false iff dataLink[hashValue] is null
    if(isEmpty(dataLink[hashCode(key)])){
        return false;
    }
    if(listRemove(dataLink[hashCode(key)], key)){
        numEntry--;
    }
    else{
        return false;
    }
}

bool Table::insert(const string &key, int value) {
    unsigned int index = hashCode(key);
    bool condition = listInsert(dataLink[index],key,value);
    if(condition){
        numEntry++;
        return true;
    }
    else{
        return false;
    }
}

int Table::numEntries() const {
   return numEntry;
}
void Table::printAll() const {
   for(int i=0;i<hashSize;i++){
       if(dataLink[i] != NULL){
           listPrintAll(dataLink[i]);
           cout<<"\n";
       }
   }
}
void Table::hashStats(ostream &out) const {
    out << "number of buckets: " << hashSize << endl;
    out << "number of entries: " << numEntry << endl;
    out << "number of non-empty buckets: " << numFilledBuckets(dataLink) << endl;
    out << "longest chain: " << maxChainLength(dataLink) << endl;
}
// put definitions for your private methods here
int Table::numFilledBuckets(ListType *data) const{
    int count=0;
    for(int i=0; i<hashSize;i++){
        if(data[i]!=NULL){
            count++;
        }
    }
    return count;
}
int Table::maxChainLength (ListType *data) const {
    int maxLength = 0;
    for(int i=0; i<hashSize;i++){
        if(dataLink[i]!=NULL){
            //compare the current maxLength with listSize
            maxLength = max(listSize(data[i]), maxLength);
        }
    }
    return maxLength;
}
