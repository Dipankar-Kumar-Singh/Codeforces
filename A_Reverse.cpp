#include <bits/stdc++.h>
using namespace std;

// #include"debugging.h"
// #define print(x) cout << (#x) << " = "<< x << " " ;

#define int long long
#define inf 1e18 
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
        
        int n ;  cin >> n ;  vector<int> v(n) ;  for(int &i : v ) cin >> i ; 
        vector<int> s  =  v;   sort(all(s)) ;

        if(is_sorted(all(v)))
        {
            for(auto x : v)   cout << x << " " ;  cout << nl ;
            continue ;
        }
        
        int a = 0 , b = 0 ;  vector<int> v1 , v2 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i]!=v[i])
            {
                a = i ;
                break ;
            }
        } 

        b = find(all(v),s[a]) - v.begin();

        for(int i = a ; i <= b ; i++)
        {
            v1.push_back(v[i]) ;
        }

        reverse(all(v1)) ;
     
        for(int i = 0 ; i <a ; i++ ) cout << v[i] << ' ' ; 
        for(auto x : v1) cout  << x << " " ;
        for(int i = b+1 ; i < n ; i++ ) cout << v[i] << ' ' ; 
        
        cout << nl ;
                              
    }
}

