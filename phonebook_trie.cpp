#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll                    long long int
#define ull                   unsigned long long
#define pb                    push_back
#define ff                    first
#define ss                    second
#define mp                    make_pair
#define MOD                   1000000007
#define vi                    vector<int>
#define vll                   vector<ll>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define mii                   map<int,int>
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)

// author - Harsh Vardhan

//Trie is the most suitable data structure to implement a dictionary or phonebook
//this is basically a DFS traversal of tree
//to add mobile number corresponing to a name use a hashmap in node structure

struct TrieNode{
	TrieNode* child[26]; 	                            //creating all its 26 child nodes
	bool isend;     			
	public:
	TrieNode(){	                                        // default constructor
		for(int i=0;i<26;i++) child[i]=NULL;
		isend = false;
	}
};

void insert(TrieNode* root,string s){                //insert function
	TrieNode* temp = root;
	for(int i=0;i<s.length();i++){    				               //corresponding index of the child character
		if(temp->child[s[i]-'a']==NULL){	                       //if child is not present, then create one
			temp->child[s[i]-'a'] = new TrieNode();
		}	
		temp = temp->child[s[i]-'a'];                          //visit next node
	}
	temp->isend = true;                                  //a word ends here
}

bool search(TrieNode* root,string s){
	TrieNode* temp = root;
	for(int i=0;i<s.length(); i++){	                     // corresponding index child character
		if(temp->child[s[i]-'a']==NULL) return false;			//not present
		temp = temp->child[s[i]-'a'];
	}
	return temp->isend;			                            //a word ends here at last char?
}

bool isempty(TrieNode* root){	                            //check leaf node or not
	for(int i=0;i<26;i++) if(root->child[i]) return false;
	return true;
}

TrieNode* del(TrieNode* root, string s,int depth){	      
	if(depth==0){ 
		if(!search(root,s))  return root;                 //word present or not
	}
	if(depth==s.length()){	                                      //At leaf node
		root->isend = false;		                      //same prefix words
		if(isempty(root)){
			delete root;                                     //delete leaf node
			return NULL;
		}
		return root;
	}
	root->child[s[depth]-'a'] = del(root->child[s[depth]-'a'],s,depth+1);	            //visit next character
	if(!root->isend && isempty(root)){
		delete root;			                           //word dont end at leaf node then delete
		root = NULL;			                           
	}
	return root;
}


int main(){
    ios;
    int t=1;
    //cin>>t;
    while(t--){
        int n;cin>>n;
		vector<string>s(n);
		for(int i=0;i<n;i++) cin>>s[i];
		TrieNode* root = new TrieNode();
		for(int i=0;i<n;i++) insert(root,s[i]);                   //constructing the trie
		int q; string a;

		cin>>q; 
		while(q--){                                                	//search 
			cin>>a;
			if(search(root,a)) cout<<"FOUND!"<<endl;
			else cout<<"NOT FOUND!"<<endl;
		}

		cin>>q;
		while(q--){                                          // delete
			cin>>a;
			root = del(root,a,0);
		}

		cin>>q;
		while(q--){
			cin>>a;                                                    //check deleted or not
			if(search(root,s)) cout<<"PRESENT"<<endl;
			else cout<<"NOT PRESENT"<<endl;
		}
		return 0; 
    }
}