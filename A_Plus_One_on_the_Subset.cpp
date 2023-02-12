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
    t_case
    {
        int n ; cin >> n ; 
        vector<int> v(n) ; for(auto &x : v ) cin >> x ;


        sort(all(v)) ;

        cout << abs(v.back() - v.front()) ;
        cout << "\n" ;
        
                                  
                                        
                                       
    }
}

