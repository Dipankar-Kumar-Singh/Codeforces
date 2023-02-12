#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


signed main()
{
    FAST 
    int r , c ; cin >> r >> c ;
    vector<string> v(r) ;
    for(auto &x : v ) cin >> x ;
    set<char> s[c] ;

    for(int slow = 0 ; slow < c ;slow++){

        for(int fast = 0 ; fast < r ; fast++){

            char cc = v[fast][slow] ;
            s[slow].insert(cc) ;
        }
    }

    int res = 1  ;

    for(auto ss : s){
        res =  (res%MOD * ss.size()%MOD)%MOD ;
    }

    cout << res ;

}


