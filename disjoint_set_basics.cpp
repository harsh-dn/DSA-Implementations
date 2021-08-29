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

// Implementation of find and union in a dsu, basically to find cycle in undirected graph

vector<int>parents;
//find
int find(int v){
    if(parents[v]==-1) return v;
    return find(parents[v]);
}
//union
void union(int from ,int to){
    from=find(from);
    to=find(to);
    parents[from]=to;
}
//iscycle
bool isCycle(vector<pair<int,int>> &edges){
    for(auto p:edges){
        int from =find(p.first);
        int to=find(p.second);
        if(from==to) return true;
        union(from,to);
    }
    return false;
}

int main(){
    ios;
    int e,v;
    cin>>e>>v;                      // no of edges and vertices
    parents.resize(v,-1);
    vector<pair<int,int>> edges;
    for(int i=0;i<e;i++){
        int from,to;
        cin>>from>>to;
        edges.push_back({from,to});
    }
    if(isCycle(edges)) cout<<"Cycle Present"<<endl;
    else cout<<"No Cycle Present"<<endl;
    return 0;
}