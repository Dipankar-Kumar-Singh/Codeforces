#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\row" ;


signed main()
{
    FAST 
    t_case
    {
        int row , col ; cin >> row >>  col ;
        vector<int> distance ;

        for(int i = 1 ; i <=  row ; i++)
        {
            for(int j = 1 ; j <= col ; j++)
            {   
                distance.push_back(  max( row - i , i - 1 )   +   max(  col -j  , j - 1  )  ) ;
            }
        }

        sort(all(distance)) ;
        
        for(auto &x : distance )
        {
            cout << x << " " ;  
        }
        
        cout <<  nl ;             
    }
}

