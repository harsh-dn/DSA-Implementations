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

// Implementation of merge sort

void merge(vector<int>&v, int l, int m , int r);

void merge_sort(vector<int>&v,int l, int r){
	if(l<r){ 					
		int m = (l+r)/2;
		merge_sort(v, l, m);		// divide the current vector into left and right halves
		merge_sort(v, m+1,r);
		merge(v,l,m,r);			// merge the sorted left and right halves
	}
}
void merge(vector<int>&v,int l,int m,int r){
	int t1[m-l+1],t2[r-m],ans[r-l+1];						// making two vectors
	for(int i=l;i<=m;i++) t1[i-l] = v[i];					// from l to m and from m+1 to r
	for(int i=m+1;i<=r;i++) t2[i-(m+1)] =v[i];			
	int i=0,j=0,k=0;
	while(i<sizeof(t1)/4 && j < sizeof(t2)/4){                  // merge the two sorted vectors
		if(t1[i] < t2[j]) {ans[k]=t1[i]; i++;}								
		else {ans[k]=t2[j]; j++;}
		k++;
	}
	while(i<sizeof(t1)/4 )  {ans[k]=t1[i]; i++; k++;}				// if one vector is completed before other
	while(j < sizeof(t2)/4) {ans[k] = t2[j]; j++; k++;}
	for(int i=0;i<sizeof(ans)/4;i++) v[l+i] = ans[i];					// copying the sorted vector into our main vector
}

int main(){
    ios;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);                       // input.txt file given
    freopen("output2.txt", "w", stdout);                    // for write answer to output.txt
    #endif

	int n;cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	merge_sort(v,0,n-1);                     //calling merge_sort function
	for(int i=0;i<n; i++) cout<<v[i]<<' ';
	return 0;
}