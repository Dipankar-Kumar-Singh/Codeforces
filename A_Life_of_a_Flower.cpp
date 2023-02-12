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
        int  n ; cin >> n ;

        vector<int> v(n+1,0) ; 

        for(int i = 0 ; i < n ; i++)
        {
            cin >> v[i+1] ;
        }

        int h = 1;
        
        for(int i = 1 ; i <= n ; i++)
        {   
            if(v[i]==0 and v[i-1]==0 and i >= 2){ h = -1 ; break ;}
            if(v[i] == 1 and v[i-1] == 1){ h +=5  ;}
            else if( v[i] == 1 and v[i-1] == 0 ) { h += 1 ;}
            
        }

        cout << h << "\n" ;
        
                                  
                                        
                                       
    }
}

