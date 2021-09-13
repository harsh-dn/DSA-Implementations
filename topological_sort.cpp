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

// topological sort in a directed graph
// if we can not find it means graph conytains a cycle
// topological sort of a graph is not unique always

const int N=100005;
vector<vector<int>>graph(N);
vector<int>indeg(N,0);

int main(){
    ios;
    int n,m,u,v,cnt=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        u-->v;
        graph[u].push_back(v);
        indeg[v]++;
    }
    queue<int>q;
    for(int i=1;i<n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        cnt++;
        int x=q.front();
        q.pop();
        cout<<x<<" ";
        for(auto i:graph[x]){
            indeg[i]--;
            if(indeg[i]==0) q.push(i);
        }
    }
    return 0;
}