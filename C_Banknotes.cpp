#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

#define ll long long
ll power(ll a, ll b){ll res=1;while(b>0){if(b&1){res=(res*a);}a=(a*a);b =b>>1;}return (res);}

signed main()
{
    FAST 
    t_case
    {
        int n , int k ; cin >> n >> k ;
        vector<int> notes(n) ; for(auto &x:notes) cin >> x ;

        sort(all(notes)) ;
        int l = 1, r = power(10 ,notes.back())   ;

        int ans = INF ;
        while (r-l>1)
        {   
            int m = midpoint(l,r) ;

            if( isPossible(notes,m) ) {
                r  = 
            }
           
        }
        
                                    
                                        
                                       
    }
}

