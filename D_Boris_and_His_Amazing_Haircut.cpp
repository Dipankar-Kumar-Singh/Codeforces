#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

class SparseTable
{
    public : 
    int MAXN = 1e5 ;
    int LOG = 0 ;
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
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    int query(int L , int R)
    {
        int j = log2_floor(R - L + 1);
        return max(st[L][j], st[R - (1 << j) + 1][j]);
    }

    int log2_floor(unsigned long i) {
        return std::bit_width(i) - 1;
    }
};

vector<int> a , b ;
int n ; 

multiset<int> razers ;
void clean_up(int l , int r , int Height) ;

bool rec(int l , int r , SparseTable &lookup)
{
    int MAXX = lookup.query(l,r) ;
    auto it = razers.lower_bound(MAXX) ;
    if(it == razers.end()) return 0 ;
    if(*it != MAXX) return 0 ;

    // razers.erase(it) ;

    vector<pair<int,int>> rng ; 

    clean_up(l,r,MAXX) ;

    for(int i = 0 ; i < n; i++)
    {
        if(b[i] <  MAXX)
        {
            int st = i ;
            int ed = i ;

            int j = i ;

            int LOCALMAX = b[i];

            while (j < n and b[j] < ed)
            {
                LOCALMAX = max(LOCALMAX , b[j]) ;
                ed = j ;
                j++ ;
            }
            rng.push_back({st,ed}) ;
            i = j;
        }
    }

    for(auto& [ L , R ] : rng)
        if(rec(L, R, lookup) ==0 ) return 0 ;

    for(int i = 0 ; i < n;  i++)
        if(a[i] != b[i]) return 0 ;

    return 1 ;
}

void clean_up(int l , int r , int Height)
{
    for(int i = l ; i <= r ; i++)
        a[i] = min(a[i], Height);
}

void solve(int& __case__)
{
    cin >> n;
    a = b = vector<int> (n) ; 
    razers.clear() ;

    for(auto &x : a ) cin >> x ;
    for(auto &x : b ) cin >> x ;

    SparseTable lookup(b) ;

    int totalRazer = 0 ; cin >> totalRazer ;
    for(int i = 0 ; i < totalRazer; i++)
    {
        int x ; cin >> x ;
        razers.insert(x) ;
    }

    if (rec(0, n - 1, lookup))
        cout << "YES" << nl;
    else
        cout << "NO" << nl;
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}