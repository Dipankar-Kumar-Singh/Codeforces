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
        int mx = 0 ,  mx_pos = 0 ;
        vector<int> v(n) ; 
        for(int i = 0 ; i < n ; i++) 
        {
            cin >> v[i] ; int x = v[i] ;
            if(x>mx) mx = x , mx_pos = i ;
        }

        int cur = v.back() ;
        int ci = n-1 ;
        int jump = 0 ;

        while (cur != mx)
        {
            int i = ci ;
            while ( i >= 0 )
            {
                if( v[i] > cur )
                {
                    ci = i ;
                    cur = v[i] ;
                    jump++ ;
                    break ;
                }
                i--;
            }
        }

        cout << jump << "\n" ;
                          
    }
}

