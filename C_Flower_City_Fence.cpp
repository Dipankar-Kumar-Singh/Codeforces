#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"




void solve(int& __case__)
{

    int n ; cin >> n; 
    vector<int> v(n) ;

    vector<int>  h(n + 2) ;

    bool possible = 1 ;
    for(int &x : v) {
        cin >> x ;
        if(x > n) {
            possible = 0 ;
        }
    }

    if(!possible){
        cout << "NO" << nl ;
        return ;
    }

    for(int i = 0 ; i < n ; i++){
        int height = v[i] ;
        h[1]++ ;
        h[height + 1]-- ;
    }

    for(int i = 1 ; i < n + 2 ; i++){
        h[i] += h[i - 1] ;
    }


    for(int i = 0 ; i < n;  i++){
        if(h[i + 1] != v[i]){
            cout << "NO"<< nl ;
            return ;
        }
    }


    cout << "YES" << nl ;

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
