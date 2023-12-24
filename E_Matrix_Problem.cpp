#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

void solve()
{
    int n , m  ;
    cin >> n >> m ;

    vector<vector<int>> actual , expected ; 
    actual = expected = vector<vector<int>>(n,vector<int>(m)) ;

    for(auto &row : actual){
        for(auto &x : row){
            cin >> x ;
        }
    }

    vector<int> A(n) , B(m) ;
    for(auto &x : A) cin >> x ;
    for(auto &x : B) cin >> x ;

    set<pair<int,int>, greater<>> row , col ;

    for(int i = 0 ; i < n ; i++)  { 
        row.insert({A[i] , i}) ;
    }

    for(int i = 0 ; i < m ; i++)  { 
        col.insert({B[i] , i}) ;
    }

    for(int i = 0 ; i < n ; i++){
        if(row.empty()) break ;
        auto [val , idx] = *row.begin() ;
        row.erase(row.begin()) ;

        set<pair<int,int>> re_insert ;

        bool possible = true ;

        while(val > 0){
            if(col.empty()) {
                possible = false ;
                break ;
            } ;
            auto [val2 , idx2] = *col.begin() ;
            col.erase(col.begin()) ;
            if(val2 > 0)
                re_insert.insert({val2 - 1 , idx2}) ;
            expected[idx][idx2] = 1 ;
            val-- ;
        }

        if(possible == false){
            cout << -1 << nl ;
            return ;
        }

        for(auto &p : re_insert){
            col.insert(p) ;
        }
    }

    for(int i = 0 ; i < n ; i++){
        // count the number of 1's in the row
        int cnt = 0 ;
        for(int j = 0 ; j < m ; j++){
            if(expected[i][j] == 1) cnt++ ;
        }
        if(cnt != A[i]){
            cout << -1 << nl ;
            return ;
        }
    }

    for(int i = 0 ; i < m ; i++){
        // count the number of 1's in the row
        int cnt = 0 ;
        for(int j = 0 ; j < n ; j++){
            if(expected[j][i] == 1) cnt++ ;
        }
        if(cnt != B[i]){
            cout << -1 << nl ;
            return ;
        }
    }

  
    int ans = 0 ;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(actual[i][j] != expected[i][j]){
                ans++ ;
            }
        }
    }

    cout << ans << nl ;

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
}
