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

        set<int> s ;

        set<int> s2 ;

        map<int,int> mp ;

        int ans = 1 ;

        for(int i = 0 ; i < n ; i++)
        {
            int x ; cin >> x ; 
            
            mp[x]++ ;

            s.insert(x) ;

            if(mp[x]>1) s.insert(-x) ;

            // s2.insert(x) ;


        } 

        cout << s.size() << "\n" ;
        
                                  
                                        
                                       
    }
}

