#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int f(int &min , int &mid , int &max)
{
    return abs(max - min) + abs(max - mid);
}

int get(vector<int> &v , int len)
{
    int n = v.size() ;
    vector<int> minv , maxv ;

    for(int i = 0 ; i < len ; i++)
        minv.push_back(v[i]) ;

    for(int i = n - 1 ; i >= n - len ; i--)
        maxv.push_back(v[i]) ;

    reverse(all(minv)) ; 

    multiset<int> s ;

    for(int i =  len ; i < n - len ; i++) s.insert(v[i]) ;

    int ans = 0 ;

    for(int i = 0 ; i < len ; i++)
    {
        int M = maxv[i] ;
        int m = minv[i] ;       

        pair<int,int> best = { numeric_limits<int>::max() , - 1} ;

        for(auto x : s)
        {
            int a =  f(m,x,M) ;

            if( a < best.first )
            {
                best = { a , x } ;
            }
        }

        ans += best.first ;
        s.erase(s.find(best.second)) ;

    }

    return ans ;
}

void solve()
{
    int n;   cin >> n;
    vector<int> v(n);  for (auto &x : v) cin >> x;

    
    sort(all(v)) ;
    int ans = -1 ;


    for(int len = n/3 ; len >= 1 ;  len--)
    {
        ans = max(ans, get(v, len));
    }
    cout << ans << nl ;
    
}
signed main(){   FAST      TestCases      solve() ;  }



