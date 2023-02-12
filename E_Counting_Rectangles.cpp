#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int N = 1010 ;
int MAXN = 1e5 + 10 ;

int h1 , w1 , h2 , w2 ;

int areaSum(int h , vector<int>& widht , vector<int> &prefix)
{
    
    int n = widht.size() ;
    if(widht.empty()) return 0 ;

    auto it = upper_bound(all(widht),w1) ;
    int ans = 0 ;

    int l = it - widht.begin() ;
    int r = (--lower_bound(all(widht),w2)) - widht.begin() ;

    if(l > r) return 0 ;
    if (r < 0 or l == n or r == n)
        return 0;

    r++ , l++ ;

    ans += prefix[r] - prefix[l-1] ;

    return ans ;
}

void solve()
{
    int n;    cin >> n;
    int q;    cin >> q;

    vector<vector<int>> H(N) ;

    for (int h{} , w{} , i = 0 ; i < n; i++)
        cin >> h >> w , H[h].push_back(w);

    for(auto &r : H) sort(all(r)) ;

    vector<vector<int>> prefix(N+10) ;

    for(int i = 0 ; i < N ; i++)
    {
        int sz = H[i].size() ;
        prefix[i] = vector<int>(sz+10) ;

        partial_sum(all(H[i]), prefix[i].begin() + 1);
    }

    while (q--)
    {
        cin >> h1 >> w1 >> h2 >> w2 ;
        int ans =  0 ;

        for (int h = h1 + 1; h < h2; h++)
            ans += h * areaSum(h, H[h], prefix[h]);

        cout << ans << nl ;
    }

    cerr << nl << nl ;
}
signed main(){   FAST      TestCases      solve() ;  }



