#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = 0;

    int x = a*d ; 
    int y = c*b ;

    if(x==0 )
    {
        if(y)
        {
            cout << 1 << nl ;
        }

        else cout << 0 << nl ;

        return ;
    }

    else if( y==0 )
    {
        if(x)
        {
            cout << 1 << nl ;
        }

        else cout << 0 << nl ;

        return ;
    }

    if(x==y)
    {
        cout << 0 << nl ;
        return ;
    }

    else 
    {   
        int l = lcm(x,y) ;
        if(x==l or y==l) cout << 1 << nl ;
        else cout << 2 << nl ;
    }

}
signed main(){   FAST      TestCases      solve() ;  }



