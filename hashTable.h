/* header file for HT implementation */
/*Author:Xingxing Geng,Sameul Fu 2/17/2018*/
/*this HT has 5 main methods: search,insert,remove,sort,rangeSearch*/


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

struct HashNode
{
    string word;
    unsigned int count;
    unsigned int myHash;

    HashNode(const string &s , unsigned int hash){
        word = s;
        count = 1;
        myHash = hash;
    }

};

class HashTable
{
public:
    HashTable(unsigned int size);
    ~HashTable();
    bool search(string x);
    void insert(string x);
    void remove(string x);
    vector<string> sort();
    void rangeSearch(string a, string b);
    unsigned int getSize();

private:
    unsigned long size;
    HashNode** ht;
    unsigned int hashMap(string x);
    unsigned int locateNode(string s, unsigned int hash);
};

#endif
