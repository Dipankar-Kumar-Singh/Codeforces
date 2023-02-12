#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

signed main()
{
    FAST 
    t_case
    {
        
        int n , k ; cin >> n >> k ; 

        if(n==4 and k == 3)
        {
            cout << -1 << nl ; continue ; 
        }
        
        set<pair<int,int>> s ;

        for(int i = 0 ; i < n ; i++)
        {
            int a = i ; 
            int b = n-i-1 ;
            if(a>b){ swap(a,b) ;}

            s.insert({a,b}) ;
        }

        if(k == n - 1 )
        {
            
            s.erase({n/2-1,n/2}) ;
            s.erase({0,n-1}) ;
            s.erase({1,n-2}) ;

            s.insert({k-1,k}) ; 
            s.insert({1,n/2-1}) ;
            s.insert({0,n/2}) ;
        }

        else 
        {
            int a = n-k-1 , b = k ;
            if(a>b) swap(a,b) ;

            int c = k , d = n-1 ;

            s.erase({0,n-1}) ;
            s.erase({a,b}) ;

            s.insert({0,n-k-1}) ;
            s.insert({n-1,k}) ;
        }

        set < pair < int ,int >> p ;
        for(auto &[x,y] : s) cout << x << " " << y << nl ;
                      
    }
}

