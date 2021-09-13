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

// bfs in an un directed graph
// graph starts from 1 only

const int N=100005;
vector<vector<int>>graph(N);
vector<int>vis(N,-1);

int main(){
    ios;
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<int>q;
    vis[1]=1;
    q.push(1);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout<<x<<" ";
        for(auto y:graph[x]){
            if(vis[y]==-1) q.push(y);
            vis[y]=1;
        }
    }
    return 0;
}