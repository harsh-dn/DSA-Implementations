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

// cycle detection in directed graph

const int N=100005;
vector<vector<int>>graph(N);
vector<int>vis(N,0),stak(N,0);


bool isCycle(int src, vector<vector<int>>graph, vector<int>vis, vector<int>stak){
    stak[src]=1;
    if(vis[src]==0){
        vis[src]=1;
        for(auto i:graph[src]){
            if(vis[i]==0 && isCycle(i,graph,vis,stak)) return true;
            if(stak[i]==1) return true;
        }
    }
    stak[src]=0;
    return false;
}

int main(){
    ios;
    int n,m,u,v,cnt=0;
    cin>>n>>m;
    bool ans =false;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        graph[u].push_back(v);
    }
    for(int i=0;i<n;i++){
        if(vis[i]==0 && isCycle(i,graph,vis,stak)){
            ans=true;
        }
    }
    if(ans) cout<<"cycle is present"<<endl;
    else cout<<"cycle is not present"<<endl;
    return 0;
}