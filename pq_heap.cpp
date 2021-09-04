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

// Implementation of heap using priority queue

int leftchild(int i) {return 2*i;} 
int rightchild(int i) {return 2*i+1;}                       //functions returning parents and children of a given node
int parent(int i) {return i/2;}


void down(int arr[],int i,int size){                                    //stub function for building max heap
	int mx=i;
	int l=leftchild(i), r=rightchild(i);
	if(l<=size && arr[l]>arr[mx]) mx=l;
	if(r<=size & arr[r]>arr[mx]) mx=r;                         //finding its maximum child
	if(i!=mx){                                                   //if a child has greater value then this node, then swap
		swap(arr[i],arr[mx]); 
		down(arr,mx,size);
	}
}


void heapify(int arr[],int size){                       // builds a max heap out of the given array
	for(int i=size/2;i>=1;i--){
		down(arr,i,size);
	}
}

void heapSort(int arr[],int size){
	//from 1 to size
	heapify(arr,size);  //converts the given array into a heap
	int tempsize = size;
	for(int i=1;i<size;i++){
		swap(arr[1],arr[tempsize]);
		tempsize--;                      //sorting the array in O(1) space
		down(arr,1,tempsize);
	}
}


int main(){
    ios;
    #ifndef ONLINE_JUDGE                              // for getting input from input.txt
    freopen("input.txt", "r", stdin);                // for writing output to output.txt
    freopen("output2.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    int a[n+1]={-1};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n+1;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    heapSort(a,n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}