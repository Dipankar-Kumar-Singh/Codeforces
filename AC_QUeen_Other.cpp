#include<bits/stdc++.h>
using namespace std ;
vector<int> ans ;
int cnt ;
int n ;

vector<string> board ;
bool check(int row , int col){
    if(board[row][col] == '*')
        return 0;
    for(int i=0; i <ans.size() ; i++){
        if(ans[i] == col)
            return 0;
        if(abs(i-row)==abs(ans[i]-col))
            return 0;
    }
    return 1;
}
void rec(int level){
    //cout<<level<<'\n';
    if(level==n){
        if(ans.size()==8)
        	cnt++;
        return ;
    }
    for(int col =0 ; col< 8 ; col++){  // columns for that row
        if(check(level,col)){
            ans.push_back(col);
            rec(level+1);
            ans.pop_back();
        }
    }
}
void solve(){

	for(int i=0 ; i<8 ; i++){
        string s ;
        cin>>s;
        board.push_back(s);
    }
    n = 8;
    rec(0);
    cout<<cnt;
}

signed main(){
    solve();
}