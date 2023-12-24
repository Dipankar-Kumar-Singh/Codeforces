#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
#include"/home/dk/debugging.h"

//  g++ 2.cpp && ./a.out

vector<int> giveCount(vector<int> &fr , int n ) {
    
    vector<int> count (n + 10) ; 

    for(int i = 1 ; i <= n ; i++){
        for(int j = i ; j <= n ; j += i){
            count[j] += fr[i] ;
        }
    }

    return count ;
}


void solve(int& __case__)
{   
    cout << "Case #" << __case__ << ": " ;

    int n; cin >> n ;
    string s ; cin >> s ;

    vector<int> fr(n + 1) ;

    int q ; cin >> q ;
    while (q--)
    {
        int x ; cin >> x ;
        fr[x]++ ;
    }

    auto count = giveCount(fr,n) ;

    for(int i = 1 ; i <= n ; i++){
        if(count[i] % 2 == 0) continue; 
        s[i - 1 ] ^= 1 ;
    }

    int ans = 0 ;

    for(int i = 1 ; i <= n ; i++){
        if(s[i - 1] == '1') {
            ans++ ;
            for(int j = i ; j <= n ; j += i ) {
                s[ j - 1 ] ^= 1 ;
            }
        }
    }

    cout << ans << nl ;
    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
