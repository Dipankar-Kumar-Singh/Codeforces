#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = numeric_limits<long long>::max();
#define F first      
#define S second     
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


signed main()
{
    FAST 
    t_case
    {
        
        int a , b ; 
        cin >> a >> b ; 


        // cout << "😂😂😂" <<  a << " " << b << "\n\n" ;


        int total_team = (a+b )/4 ;
        int p = min(a,b) ;

        total_team = min(total_team,p) ;

        a -= total_team ; b-=total_team ;

        int pairs = (a+b)/2  ;


        int ans = min(pairs,total_team) ;

        cout << ans << "\n" ;
                                  
                                        
                                       
    }
}

