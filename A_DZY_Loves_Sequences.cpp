#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

const int N = 1e5 + 5;
int arr[N];
int l[N];
int r[N];

void solve()
{
    int n;   cin >> n;
    vector<int> v(n);  for (auto &x : v) cin >> x;

    int curr = -1 ;

    vector<pair<int,int>> a ;

    for(int i = 0 ; i < n ; i++)
    {
        curr =  -1 ;
        int s = i ;
        int e = -1 ;

        int j = i ;
         
        for( j = i ; j < n ; j++)
        {
            
            if(v[j]>curr)
            {
                curr = v[j] ;
                e = j ;
            }

            else 
            {
                i = j - 1 ;
                break;
            }
        }

        i = j - 1 ;
        a.push_back({s,e}) ;
    }

    int ans = 0 ;

    if(a.size()==1) ans = n ;

    int maxsegsize = -1 ;
    for (auto &[x, y] : a)
        maxsegsize = max(maxsegsize,(y - x + 1));

    for(int i = 0 ; i + 1 < a.size() ; i++)
    {
        auto &[s1, e1] = a[i];
        auto &[s2, e2] = a[i + 1];

        if(i + 2 <  a.size())
        {
            auto &[s3, e3] = a[i + 2];
            if ((s3 - e1 == 2) and (v[s3] > v[e1] + 1))
            {
                ans = max(e3 - s1 + 1 , ans ) ;
            }
        }


        if(e1 > 0  and e1 + 1 < n)
        {
            auto cp = v[e1] ;
            v[e1] = v[e1-1] + 1 ;

            if( e1 and v[e1 + 1] > v[e1-1] + 1)
            {
                if( e1+1 <= e2 )  ans = max(e2 - s1 + 1 , ans) ;
                else  ans = max(e1 + 1 - s1 + 1 , ans) ;
            }

            v[e1] = cp ;
        }

        if(v[s2+1]  <= v[e1] + 1 ) continue;
        ans = max(e2 - s1 + 1 , ans ) ;
    }

    if (ans < 1 + maxsegsize)
        ans = min(1 + maxsegsize, n);

    cout << ans << nl ;
}
signed main(){   FAST            solve() ;  }



