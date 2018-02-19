#include "hashTable.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>


unsigned int HashTable::getSize()
{
    return this->size;


}

/*
HashTable::HashTable(unsigned long size){
     array.reserve(size);
 }

 HashTable:: ~HashTable(){
     array.clear();
 }
*/
//Array of Node?
//

HashTable::HashTable(unsigned int size){
    this->size = size;
    this->ht = new HashNode*[size]();
}

HashTable::~HashTable(){
    for (int i = 0; i < size; ++i){ delete this->ht[i];}
    delete[] this->ht;

}

/*
unsigned int HashTable::hashMap(string x){
    unsigned int value = 0;
                for(int i = 0; i<x.length();i++){
                        value = value*37+x[i];
                }
                return value;
}*/
unsigned int HashTable::hashMap(string x)
{
    unsigned int hash = 0;
    for (auto &character : x)
    {
        hash = hash * 31 + character;
    }   
    return hash % this->size;
}



bool HashTable::search(string x){
    unsigned int h = hashMap(x);
        unsigned int index = locateNode(x, h);
    
    HashNode*& pos = this->ht[index];
    if (pos != nullptr){
        return pos->word == x;
    }else{
            return false;
    }
}

void HashTable::insert(string x){
    unsigned int h = hashMap(x);
    unsigned int index = locateNode(x, h);
    
    HashNode*& pos = this->ht[index];
    
    if (pos == nullptr){
        pos = new HashNode(x, h);
    }else{
        ++pos->count;
    }
}

void HashTable::remove(string x){
        unsigned int h = hashMap(x);
    unsigned int pos = locateNode(x, h);


        if (ht[pos] != 0){
            if (ht[pos]->count > 1){
    
                --ht[pos]->count;
            }else{
                delete ht[pos];
                ht[pos] = 0;
            }
  for (unsigned int i=(pos+1)%size; ht[i] != 0; i =(++i)%this->size)
    {
      if ((i > pos && (ht[i]->myHash <= pos ||
          ht[i]->myHash > i))||
          (i < pos && (ht[i]->myHash <= pos && ht[i]->myHash > i))){
                    ht[pos] = ht[i];
                    ht[i] = 0;
                    pos = i;
      }
                
    }
       }
}


vector<std::string> HashTable::sort()
{
    vector<std::string> v;
  //  v.reserve(this->size);
    for (unsigned int i = 0; i < this->size; ++i) {
        if (this->ht[i] != 0)
            v.push_back(this->ht[i]->word);
    }
std::sort(v.begin(), v.end());
   
    return v;
}

//cout<< "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" <<endl;

void HashTable::rangeSearch(string a, string b){
    std::string lt;
    std::string rt;
    if(a>b){
        lt = b;
        rt = a;
    }else{
        lt = a;
        rt = b;
    }
    for (unsigned int i = 0; i < this->size; ++i){
        if (ht[i] != 0 && ht[i]->word >= lt && ht[i]->word <= rt)
            cout << this->ht[i]->word << '\n';
    }
}

unsigned int  HashTable::locateNode(string s, unsigned int hash){
    unsigned int index = hash;
/*    unsigned int offset =0;
    while (offset< this->size){
        if(ht[index] == 0 || ht[index]->word == s)
            break;
        offset = offset +1;
        index = (index+1) % this
*/
do {
   if (ht[index] == nullptr || ht[index]->word == s)
        break;
    else
      index = (index + 1) % this->size;
} while (index != hash);
/*

while(index !=hash){
        if (ht[index] == 0 || ht[index]->word == s)
            break;
        else
            index = (index + 1) % this->size;
    } 
*/
    return index;
}
