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
    int n;
    cin >> n;
    int k;
    cin >> k;

    if ((k & 1))
    {
        cout << "YES\n" ;

        for (int i = 1; i <= n; i += 2)
        {
            cout << i << " " << i + 1 << nl;
        }
    }

    else 
    {
        if((2+k)%4==0)
        {
            cout << "YES\n" ;

            for(int i = 4 ; i <= n ; i+=4)
            {
                cout << i - 1 << " " << i << nl ;
            }

            for(int i = 1 ; i <= n ; i+=4)
            {
                cout << i + 1 << " " << i << nl ;
            }
        }

        else 
        {
            cout << "NO\n" ;
        }
    }
}
signed main(){   FAST      TestCases      solve() ;  }



