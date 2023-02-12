#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;


class minTree
{
    public : 
    int MAXN = 1e5 ;
    int LOG = 0 ;
    vector<int> lg ;
    vector<vector<int>> st ; 

    minTree(vector<int> &vec)
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

    void computeLog()
    {
        lg = vector<int>(MAXN + 1) ;
        lg[1] = 0;
        for (int i = 2; i <= MAXN; i++)
            lg[i] = lg[i/2] + 1;
    }

    int log2_floor(unsigned long i) {
        return std::bit_width(i) - 1;
    }

};



void solve()
{
    int n ; cin >> n ;
    vector<int> v(n) ;
    for(int &x : v) cin >> x ;
    bool ans = 1 ;

    minTree tree(v) ;

    for(int i = 1 ; i + 1 < n ; i++)
    {
        int left = tree.query(0, i - 1)  ;
        int right = tree.query(i + 1 , n - 1) ;

        if (v[i] > left and v[i] > right)
        {
            ans = 0 ;
        }
    }

    cout << (ans ? "YES" : "NO") << nl;
}

signed main() { FAST TestCases solve(); }
