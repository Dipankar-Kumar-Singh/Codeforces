#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
int _case = 1 ;

void solve()
{
    int n;   cin >> n;

    vector<int> val(n+10)  ;
    vector<int> v(n);
    vector< vector<int> >  loc(n+10) ;

    for (int i = 0 ; i < n ; i++)
    {
        cin >> v[i];
        loc[v[i]].push_back(i) ;
        val[v[i]] = v[i] ;
    }

    if (n == 1)
    {
        cout << 0 << "\n";
        return;
    }

    int moves = 0  ;

    while (!is_sorted(all(v)))
    {
        int currmin = v.back();
        for (int i = n - 2; i >= 0; i--)
        {
            v[i] = val[v[i]];

            if (v[i] == currmin)
            {
                if (v[i + 1] == v[i])  continue;
                val[v[i]] = 0;
                moves++;
            }

            else if (v[i] < currmin)
            {
                currmin = v[i];
                continue;
            }

            else if (v[i] > currmin)
            {
                for (int j = i ; j >= 0; j--)
                {
                    v[j] = val[v[j]] ;

                    if (v[j] == 0)   continue;

                    auto &vec = loc[v[j]] ;
                    moves++ ;
                    for(auto &k : vec)  v[k] = 0;
                    val[v[j]] = 0 ;
                }
                break;
            }
        }
    }

    cout << moves << "\n" ;
}
signed main(){   FAST      TestCases      solve() ;  }



