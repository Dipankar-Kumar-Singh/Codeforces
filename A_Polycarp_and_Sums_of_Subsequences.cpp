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
        vector<int> v(7) ; for(int &x:v) cin >> x ;

        sort(all(v)) ;

        int a = v.front() , b = v[1] ;

        int c = v.back() - (a+b) ;

        cout << a << " " << b << " " << c << "\n" ;
        
                                  
                                        
                                       
    }
}

