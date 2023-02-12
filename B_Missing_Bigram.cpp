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

        vector<string> v(n-2) ;

        for(auto &x : v) cin >> x ;

        string s ;
        s.push_back(v[0][0]) ;


        for(int i = 1 ; i < v.size( ) ; i++ )
        {   
            char a = v[i-1][1] ;
            char b = v[i][0] ;

            if(a==b) s.push_back(a) ;
            else if(a!=b) s.push_back(a) , s.push_back(b) ;
        } 


        s.push_back(v.back()[1]) ;

        if(s.size()<n){s.push_back(v.back()[1]);}

        cout << s << "\n" ;
        
                                  
                                        
                                       
    }
}

