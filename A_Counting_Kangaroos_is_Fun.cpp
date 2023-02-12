#include <bits/stdc++.h>

using namespace std;

#define ar array
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define f(x,v) for(auto &x:v)
#define all(x)  (x).begin() , (x).end()

//  <  ---- vectors ---- >
#define vi vector<int>

signed main()
{
    FAST 
    int n ; cin >> n; 
    vi v (n,0) ; f(x,v){cin >> x ;}

    sort(all(v), greater<int>() ) ;

    vi h(n,0) ;

    int ans = 0 ;
    int vis = n ;
    int prev = n/2 ;

    for(int i = 0 ; i <= n/2 ; i++){

        for(int j = prev ; j < n ; j++)
        {       
           
            if( (v[j]*2 <= v[i]) and (h[j]==0 and h[i] == 0)  and( i != j))
            { 
                h[i] = 1 ; h[j] = -1 ;  
                prev = j+1 ;
                vis--;   
                break ;      
            }
            
            if(j==n-1){ cout << vis ; return 0 ;}
        }
    }


   cout << vis ; 

    
}

