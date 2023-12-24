#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

int n , m ;
vector<vector<int>> g ;

bool isVaild(int i , int j) {
    if(i < 0 or j < 0 ) return 0 ;
    if(i >= n or j >= m ) return 0 ;
    if(g[i][j] != 0 ) return 0 ;
    return 1 ;
}


void solve(int& __case__)
{
    vector<string> v(10) ;
    for(auto &x : v) cin >> x ;

    int sum = 0 ;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            sum += (( v[i][j] == 'X') ? g[i][j] : 0) ;
        }
    }

    cout <<  sum  << nl ;
}

void down(int val, int &i, int &j){
    while (isVaild(i,j))
    {
        g[i][j] = val ;
        i++ ;
    }
    i-- ;
}

void up(int val, int &i, int &j){
    while (isVaild(i,j))
    {
        g[i][j] = val ;
        i-- ;
    }
    i++ ;
}

void right(int val, int &i, int &j){
    while (isVaild(i,j))
    {
        g[i][j] = val ;
        j++ ;
    }
    j-- ;
}

void left(int val, int &i, int &j){
    while (isVaild(i,j))
    {
        g[i][j] = val ;
        j-- ;
    }
    j++ ;
}

void fillGrid(int val , int i , int j) {
    right(val,i,j) ;
    down(val,i,j) ;
    left(val,i,j) ;
    up(val,i,j) ;
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    n = 10 ; m = 10 ;
    g = vector<vector<int>> (10 , vector<int>(10)) ;

    fillGrid(1,0,0) ;
    fillGrid(2,1,1) ;
    fillGrid(3,2,2) ;
    fillGrid(4,3,3) ;
    fillGrid(5,4,4) ;


    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
