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
        int n ; cin >> n ;
        vector<int> a(n) , b(n) ;
        for(int &i:a) cin >> i ;
        for(int &i:b) cin >> i ;


        for(int i = 0 ; i < n ; i++)
        {
            if(a[i] > b[i]) swap(a[i],b[i]) ;
        }

        cout << *max_element(all(a)) * (*max_element(all(b)))  << nl ;
        
                                  
                                        
                                       
    }
}

