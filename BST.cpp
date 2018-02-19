/*#include <fstream>
ifstream infile

infile.open("data");
assert(infile);

string i;
infile >> i;
infile.close();*/

#include "BST.h"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

using namespace std;
 


		BST::BST(){//input is array of words
				root = NULL;
				size = 0;
		}

/*		BST::BST(const BST& rhs){
				if(this != &rhs){
						makeEmpty(root);
						root = clone(rhs.root);
				}
		}

		struct Node* BST::clone(Node *t){
				if(t == NULL)
						return NULL;
				return new Node((t->key).first,clone(t->left),clone(t->right));
		}*/

		void BST::makeEmpty(Node* &t){
				if(t != NULL){
						makeEmpty(t->left);
						makeEmpty(t->right);
						delete t;
				}
				t = NULL;
		}

		BST:: ~BST(){
				makeEmpty(root);
		}


		/*return true if x is found in BST*/
		bool BST:: search(std::string & x){
				return search(x,root);
		}
		bool BST:: search(std::string & x, Node* t){
				if(t == NULL)
						return false;
				else if( x < (t->key).first)
						return search(x, t->left);
				else if( x > (t->key).first)
						return search(x, t->right);
				else
						return true;
		}

		/*insert a new word or increment the counter if x already exist*/
		void BST::insert(std::string & x){
				insert(x,root);
		}

		void BST::insert(std::string & x, Node* & t){
				if(t == NULL){
						size += 1;
						t = new Node(x,NULL,NULL);}
				else if(x < (t->key).first)
						insert(x, t->left);
				else if(x > (t->key).first)
						insert(x, t->right);
				else{// x = (t->key).first
						(t->key).second += 1;//counter +1
				}
		}

		/*remove a specific string x*/
		void BST::remove(std::string & x){
				remove(x,root);
		}

		void BST::remove(std::string & x, Node* & t){
				if(t == NULL)
						return; //not found , should we break here?
				else if( x < (t->key).first)
						remove(x , t->left);
				else if( x > (t->key).first)
						remove(x, t->right);
				else{//find x
						(t->key).second -= 1;
						if((t->key).second == 0){//counter = 0;node need to be deleted
								if(t->left != NULL && t->right != NULL){//have two children
										std::pair<std::string, int> tmp;
										Node* findMin;
										findMin = t->right;
										while(findMin->left != NULL){
												findMin = findMin->left;
										}//find the smallest key in t->right
										tmp = findMin->key;
										t->key = tmp;//replace the deleted key with smallest ele in right subtree
										Node* deleNode = findMin;
										findMin = findMin->right;
										delete deleNode;
										size -=1;
								}
								else{//have one child or no child
										Node* oldNode = t;
										t = (t->left != NULL) ? t->left : t->right;
										delete oldNode;
										size -= 1;
								}
						}
				}
		}

		vector<std::string> BST::sort(){
            vector <string> s;
            this->sort(s,this->root);
            return s;
            
		}

        void BST::sort(vector<string> v, Node* t){
            if(t){
                 sort(v,t->left);
                 v.push_back((t->key).first);
                 sort(v,t->right);
            }
         //   std::sort(v->begin(),v->end());
        }

        
		/*rangeSearch , print all word in the range*/
		void BST::rangeSearch(std::string a, std::string b){
				rangeSearch(a, b, root);
		}

		void BST::rangeSearch(std::string a, std::string b,Node* t){
				std::string lt;
				std::string rt;
				if(a > b){
						lt = b;
						rt = a;
				}
				else{
						lt = a;
						rt = b;
				}

                if(t==NULL)
                    return;
                if(lt <(t->key).first)
                    rangeSearch(a,b,t->left);
                if ( lt <= (t->key).first && rt >= (t->key).first)
                    cout << (t->key).first <<endl;
                if(rt> (t->key).first)
                    rangeSearch(a,b,t->right);
        }


		/*		if(t != NULL){
						if((t->key).first >= lt && (t->key).first <= rt){
								rangeSearch(a,b,t->left);
								cout<<(t->key).first<<endl;
								rangeSearch(a,b,t->right);
						}
		        }

        */
        
	
						

































