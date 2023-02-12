#include <bits/stdc++.h>
using namespace std;

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
        int n ; cin>> n ; 
        string s ; cin >> s ;
        
        if(n>2)
        {
            cout << "NO\n " ;
        }

        else 
        {

            int a{} , b{} ;

            for(auto c : s){ if(c=='1')a++ ; else b++ ;}

            if(n==2)
            {
                if(s.front() == s.back())
                {
                    cout << "NO\n" ;

                }

                else cout <<  "YES\n" ;
            }

            else if(n==1)
            {
                cout << "YES\n" ;
            }
            
        }


                                  
                                        
                                       
    }
}

