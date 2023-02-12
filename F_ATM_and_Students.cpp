#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


int const INF  = 1e18 ;
int test = 0 ;

class SparseTable
{
    public : 
    int MAXN = 2e5 + 10 ;
    int LOG = 0 ;
    vector<int> lg ;
    vector<vector<int>> st ; 

    SparseTable(vector<int> &vec)
    {
        MAXN = vec.size() ;
        LOG = log2_floor(MAXN) ;
        st = vector<vector<int>>(MAXN, vector<int>(LOG + 1));

        /* ------------------------------- base layer ------------------------------- */
        for (int i = 0; i < MAXN; i++) st[i][0] = vec[i];

        /* ------------------------------ pre computing ----------------------------- */
        for (int j = 1; j <= LOG; j++)
            for (int i = 0; i + (1 << j) <= MAXN; i++)
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    int query(int L , int R)
    {
        int j = log2_floor(R - L + 1);
        return min(st[L][j], st[R - (1 << j) + 1][j]);
    }

    int log2_floor(unsigned long i) {
        return std::bit_width(i) - 1;
    }

};



void solve()
{
 
    int ans = 0 ; 
    int n ; cin >> n ;
    int initialMoney = 0 ;
    cin >> initialMoney ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ;

    vector<int> p(n + 2);
    partial_sum(all(v), p.begin() + 1);
    SparseTable tree(p);

    pair<int,int> point {-1,-1};

    for (int i = 0; i < n; i++)
    {
        if (v[i] + initialMoney < 0)
            continue;

        int l = i, r = n + 1;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (tree.query(i + 1, mid) - p[i] + initialMoney >= 0)
                l = mid;
            else
                r = mid;
        }

        int L = i + 1, R = l;
        //  One Based Indexing ..
        int range = R - L + 1;

        auto [ s , e ] = point ;
        if(e - s < range)
        {
            point = {L, R};
        }
      
    }

    if(point.first == -1)
    {
        cout << -1 << nl ;
    }

    else 
    {
        cout << point.first << " " << point.second << nl ;
    }

}

signed main(){  FAST    TestCases    solve() ; }