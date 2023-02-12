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

        int w , h ; cin >> w >> h ;

        vector<int> ax , bx , cy , dy ;

        int k1 ; cin >> k1 ;
        for(int i = 0 ; i < k1 ; i++) { int x ; cin >> x ; ax.push_back(x) ;}

        cin >> k1 ;
        for(int i = 0 ; i < k1 ; i++) { int x ; cin >> x ; bx.push_back(x) ;}

        cin >> k1 ;
        for(int i = 0 ; i < k1 ; i++) { int x ; cin >> x ; cy.push_back(x) ;}

        cin >> k1 ;
        for(int i = 0 ; i < k1 ; i++) { int x ; cin >> x ; dy.push_back(x) ;}


        sort(all(ax)), sort(all(bx)), sort(all(cy)), sort(all(dy)) ;

        int ans = 0 ;

        
        int a1 = ax.front() , a2 = ax.back() ; int d = abs(a1-a2) ;

        d = max(d , abs(bx.front() - bx.back())) ;


        ans = (d*h) ;


        d = max( abs( cy.back()  - cy.front())   , abs( dy.back() - dy.front() ) )  ;

        ans = max( ans ,   (d*w)) ;

        cout << ans << "\n" ;





        
        
                                  
                                        
                                       
    }
}

