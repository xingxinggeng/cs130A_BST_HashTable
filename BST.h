/* header file for BST implementation */
/*Author:Xingxing Geng, 2/17/2018*/
/*this BST has 5 main methods: search,insert,remove,sort,rangeSearch*/

#ifndef BST_H
#define BST_H
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

		class BST{
				public:
						BST();
						~BST();
						bool search(std::string & x);
						void insert(std::string & x);
						void remove(std::string & x);
						vector<std::string> sort();//what return type should sort method be ?
						void rangeSearch(std::string a, std::string b);// we do not know which is greater , need to consdier when implement
						
				private:
						struct Node{
								Node* left;
								Node* right;
								std::pair<std::string, int> key;
								/* from book do we need intialize list*/
                            //    Node(string ele):key(ele,1),left(0),right(0){}
								Node(std::string ele , Node* lt, Node* rt){
										key = make_pair(ele,1);
										left = lt;
										right = rt;
								}
						};
						Node *root;
						int size;//number of node , used for sort method

						bool search(std::string & x, Node* t);
						void insert(std::string & x, Node* & t);
						void remove(std::string & x, Node* & t);
					    void sort(vector<string> v, Node* t);
                        void rangeSearch(std::string a, std::string b,Node* t);
						void makeEmpty(Node* &t);
						Node* clone(Node* t);
		};


#endif



