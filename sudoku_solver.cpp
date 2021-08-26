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

// Sudoku solver using backtracking

// Helper function for valid sudoku

bool isValidSudoku(vector<vector<char>>& board) {
    int x[9][9]={0},y[9][9]={0},z[9][9] ={0};
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(board[i][j]!='.'){
                int num = board[i][j]-'0'-1,k=i/3*3+j/3;
                if(x[i][num]||y[j][num]||z[k][num]) return false;
                x[i][num]=y[j][num]=z[k][num]=1;
            }
    return true;
}

// helper function to check a valid entry
bool check(vector<vector<char>>& board, int i, int j, char val) {
    for(int h=0;h<9;h++){
        if(board[i][h]==val) return false;
        if(board[h][j]==val) return false;
        if(board[i-i%3+h/3][j-j%3+h%3]==val)return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board, int i, int j){
    if(i==9) return true;
    if(j==9) return solve(board,i+1,0);
    if(board[i][j]!='.') return solve(board,i,j+1);
    for(char c='1';c<='9';c++){
        if(check(board,i,j,c)){
            board[i][j]=c;
            if(solve(board,i,j+1)) return true;
            board[i][j]='.';
        }
    }
    return false;
}


int main(){
    ios;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);                       // input.txt file given
    freopen("output2.txt", "w", stdout);                    // for write answer to output.txt
    #endif
    vector<vector<char>> board;
    board = [["5","3",".",".","7",".",".",".","."],
             ["6",".",".","1","9","5",".",".","."],
             [".","9","8",".",".",".",".","6","."],
             ["8",".",".",".","6",".",".",".","3"],
             ["4",".",".","8",".","3",".",".","1"],
             ["7",".",".",".","2",".",".",".","6"],
             [".","6",".",".",".",".","2","8","."],
             [".",".",".","4","1","9",".",".","5"],
             [".",".",".",".","8",".",".","7","9"]]
            
    solve(board,0,0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}