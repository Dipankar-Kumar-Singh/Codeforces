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

        vector<int> v(n) ; 
        for(int &x : v) cin >> x ;
        sort(all(v)) ;


        vector<int> need(n+1,0) ;
        vector<int> h(n+1,0) ;

        for(int i = 0 ; i < n ; i++)
        {   
            
            need[i] =  i - v[i] ;

            if(n==7) cerr << i << " " << v[i] << "\n" ;

            if(need[i]<0)
            {   
                need[i] = 0 ;
                for(int j = i+1 ; j <= n ; j++)
                {
                    need[j] = -1 ;
                }

                break ;
            }
        }

        for(auto x:need)
            cout << x << " " ;
        cout << "\n" ;

        for(int i = 1 ; i <= n ; i++)
        {
            if(need[i-1] > 0){
                 h[i] = h[i-1] + need[i-1] ;
            }

            else {
                h[i] = -1 ;
            }
           
        }

        // for(auto x : h ) cout << x << " " ;

        cout << "\n" ;


        
                                  
                                        
                                       
    }
}

