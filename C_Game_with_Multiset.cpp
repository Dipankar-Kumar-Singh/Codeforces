#include <bits/stdc++.h>
using namespace std;
#define nl      "\n" 

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    vector<int> m = vector<int>(32) ;
    int q ; cin >> q ;
    while(q--){
        int t , x ; cin >> t >> x ;
        if(t == 1){
            m[x]++ ;
        } else if(t == 2){
            bitset<32> b = x ;
            int carry = 0 ; 
            for(int bit = 29 ; bit >= 0 ; bit--){
                carry *= 2 ;
                if(b[bit] == 1){
                    carry++ ;
                }
                carry -= min( carry, m[bit]);
            }

            if(carry){
                cout << "NO" << nl ;
            } else {
                cout << "YES" << nl ;
            }
        } 
    }
}
