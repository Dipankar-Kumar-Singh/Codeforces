#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

void solve(int& __case__)
{
    int n ; cin >> n ;
    int m ; cin >> m ;

    string str ; cin >> str ;

    vector<int> ones ; 
    vector<int> zeros ; 

    ones.push_back(-1) , zeros.push_back(-1) ;

    for(int i = 0 ; i < n ; i++){
        ( str[i] == '1' ? ones : zeros ).push_back(i);
    }
    // adding n / -1 is amazing trick to handle corrner cases in set (not found cases ) 
    ones.push_back(n) ; zeros.push_back(n) ;
    set<pair<int,int>> s ;

    while (m--){
        int l , r ; cin >> l >> r ;
        l-- ; r-- ;

        int firstOne = *lower_bound(begin(ones),end(ones) , l) ;
        int lastZero = *prev(lower_bound(begin(zeros),end(zeros), r + 1)) ;

        if( firstOne > lastZero ) {
            // 00000011111 ( all sorted )
            s.insert({-1, -1});
        } else {
            s.insert({firstOne,lastZero}) ;
        }

    }
    
    cout << s.size() << nl;
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
