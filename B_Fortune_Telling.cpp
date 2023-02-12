#include <bits/stdc++.h>
using namespace std;
#define int long long
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


signed main()
{
    FAST 
    t_case
    {
        int n ,  start ,end ; cin >> n >> start >> end ;
        vector<int> v(n) ; for(int &i  : v) cin >> i ;

        bool parity_same = (start&1)  ==  (end&1) ;

        if(accumulate(all(v),0)&1)
            cout << ( parity_same ? "Bob\n" : "Alice\n" ) ; 
        
        else 
            cout << ( parity_same ? "Alice\n" : "Bob\n" ); 
    }
}

