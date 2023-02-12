#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int n ;
vector<int> v ;


bool isPossible(int t)
{
    int s = t ;
    int e = v.size() - 1 ;

    while (s>=0)
    {
        if(v[e] <= 2*v[s]) return 1 ; 
        s-- ; e-- ;
    }

    return 0 ;
}

signed main()
{

    FAST 

    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    cin >> n ; 

    v.resize(n) ; 
    for(int &x : v ) cin >> x ; 
    ranges::sort(v) ;

    if(n==2)
    {
        cout << (v.back() <= v.front()*2 ? 0 : 1) ;
        return 0 ;
    }

    int l = -1 , r = max(n-2, 2LL) ;

    int ans = INF ; 

    while (r-l>1)
    {
        int m = midpoint(l,r) ;

        if(isPossible(m))
        {
            r = m ;
            ans = min(m,ans) ;
        }

        else l = m ;
    }

    cout << ans ;
    
}

