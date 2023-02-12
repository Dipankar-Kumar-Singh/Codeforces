#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

int  n, m, rb, cb, rd, cd ;

signed main()
{
    FAST 
    t_case
    {
        int  n, m, rb, cb, rd , cd ;

        cin >> n >> m >> rb >> cb >> rd >> cd ;

        int v = rd - rb ;

        int h = cd - cb ;

        if(v<0)
        {
            int dv = (n - rb) ;

            v =  abs(v) + 2*dv  ; 
        }

        if(h<0)
        {
            int dh = (m - cb) ;

            h =  abs(h) + 2*dh  ; 
        }


        cout << min(v,h) << "\n" ;









        
                                  
                                        
                                       
    }
}

