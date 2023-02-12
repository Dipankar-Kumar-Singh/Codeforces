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
    int n;    cin >> n;
    int m;    cin >> m;

    int ones = 0;
    int first{-1}, last{-1};

    string s;  cin >> s;

    for (int i = 0; i < n; i++) 
    {
        if(s[i]=='1')
        {
            ones++ ;
            if(first==-1) first = i ;
            last = i ;
        }
    }

    if(ones==0)
    {
        cout << n*m << nl ;
        return ;
    }

    if(m&1)
    {
        if(ones&1)
        {
            cout << 0 << nl ;
            return ;
        }

        else 
        {
            // 00010001000
            int target = ones/2 ;

            int c1 = 0 ;
            int x = -1 , y = -1 ;

            for(int i = 0 ; i < n;  i++)
            {
                if(s[i] == '1')
                {
                    c1++ ;
                    if(c1==target)
                    {
                        x = i;
                        break;
                    }
                }
            }

            for (int i = x + 1  ; i < n; i++)
            {
                if (s[i] == '1')
                {
                    y = i;
                    break;
                }
            }

            int ans = y - x ;
            cout << ans << nl ;
        }
    }

    else 
    {
        int ans = n - last + first ;
        cout << ans << nl ;
    }

}
signed main(){   FAST      TestCases      solve() ;  }



