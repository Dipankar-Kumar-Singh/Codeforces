#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void fill_up(vector<int> &v , int mx_size , int val )
{
    for (int i = v.size() - 1; i >= 0; i--)
    {
        v[i] = v.back();      
        mx_size--;
        if (mx_size == 0)  break;
    }
}

signed main()
{
    FAST 
    t_case
    {
        int n ; cin >> n ;

        vector<int> v(n) ;
        for(int &i : v) cin >> i ;
        int move = 0 ;

        if (count(all(v),v.back()) == v.size())
        {
            cout << 0 << nl;  continue;
        }

        while (count(all(v),v.back()) != v.size())
        {
            move++ ;
            int mx_size = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (v[i] == v.back())   mx_size++;
                else   break;
            }
            fill_up(v,mx_size*2,v.back()) ;
        }
        cout << move << nl ;
    
    }
}

