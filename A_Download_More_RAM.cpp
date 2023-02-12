#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" ;


signed main()
{
    FAST 
    t_case
    {
        int n ; cin >> n ;
        int ram ; cin >> ram  ;
        vector< pair < int , int >> v (n) ; 

        vector<int> a , b ;
        for(int i = 0 ; i < n ; i++)
        {
            int x ; cin >> x ; a.push_back(x) ;
        }
         for(int i = 0 ; i < n ; i++)
        {
            int x ; cin >> x ; b.push_back(x) ;
        }


        for(int i = 0 ; i < n ; i++)
        {
            v[i] = {a[i] , b[i]} ;

        }

        sort(all(v)) ;

        for(auto &[x,y] : v)
        {
            if(x <= ram )
            {
                ram += y ; 

            }

            else break ;
        }


        cout << ram << nl ;


        
                                  
                                        
                                       
    }
}

