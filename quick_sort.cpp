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

// Quick_Sort and Randomized quick sort
// Bsically a divide and conquer algorithm
// worst case n^2 average nlogn 
// But better than other sorting as its inner loop is more suitable for real world problems

int partition(int arr[],int p,int q){
	int key = arr[p];			                                     //simply select 1st element as pivot
	int i=p+1,j=p;
	while(i<=q ){
		if(arr[i]<=key){ j++; swap(arr[j],arr[i]); }
		i++;
	}
	swap(arr[j],arr[p]);
	return j;
}

int rand_partition(int arr[],int p,int q){                           //to be used in randomized quick sort
	srand(time(NULL)); 				
	int ind = p + rand()%(q-p);                                     //choosing a random index between p and q
	swap(arr[ind],arr[p]);        
	int key = arr[p];			                                   // 1st element is selected as pivot	
	int i=p+1,j=p;				  
	while(i<=q ){ 
		if(arr[i]<=key){ j++; swap(arr[j],arr[i]);}              //less than key are at left, greater than key are at ringht
		i++;
	}
	swap(arr[j],arr[p]);
	return j;
}

void Quicksort(int arr[],int p,int q){
	if(p>=q) return ;
	int r = partition(arr,p,q);
	Quicksort(arr,p,r-1);
	Quicksort(arr,r+1,q);
}

void rand_quicksort(int arr[],int p, int q){
	if(p>=q) return ;					                 	//if 1 or 0 elements, return
	int r = rand_partition(arr,p,q);                       //generates a random partition of an 
	rand_quicksort(arr,p,r-1);			               	  //recursively sort the two parts, as r position is fixed
	rand_quicksort(arr,r+1,q);
}

int main(){
    ios;
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output2.txt", "w", stdout);
    #endif

	int n ; cin>>n;
	int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
	rand_quicksort(arr,0,n-1);      
	for(int i=0;i<n;i++) cout<<arr[i]<<' ';
    return 0;
}