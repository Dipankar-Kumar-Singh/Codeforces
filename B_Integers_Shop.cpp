#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()



signed main()
{
    FAST 
    t_case
    {

        int n ; cin >> n ;

        int lm {INF} , rm {-1} , cost_lm {INF} , cost_rm{INF};
        int big_lm {INF}  , big_rm {INF} , cost_big{INF};


        for(int k = 0 ; k < n ; k++)
        {
            int l , r , c ;
            cin >> l >> r >> c ;

            if(l < lm)
            {
                // clearning the old mess .. if new value is found
                cost_big = INF ;
                cost_lm = INF ;
                lm = l ;
            }


            if(r > rm)
            {
                // clearing up old records .... 
                cost_big = INF ;
                cost_rm = INF ;
                rm = r ;
            }

            if(l == lm)
            {
                // chosing min value ... 
                // if same max is found , data will not be earased in earlier oprations 
                // as we are using greater than (>) rathern than greater and eqal [>=]
                cost_lm =  min(c,cost_lm) ;

            }

            if(r == rm )
            {
                cost_rm = min(c,cost_rm) ;
            }

            if( (r == rm) and (l == lm))
            {
                cost_big  = min(c,cost_big) ;
            }

            long long c1 = cost_big ;
          
            long long c2 = cost_rm + cost_lm ;
           

            cout << min(c1, c2 ) << "\n";


         
        }
    }
}
