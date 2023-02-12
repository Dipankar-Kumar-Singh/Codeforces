#include <bits/stdc++.h>
using namespace std;

int const N = 2e5 + 10 ;
int visited[N];
// This array stores which element goes to which position
int goesTo[N];

map<int,vector<int>> cycle ; // Any One elemet is parent of cyles [ simialr to DSU ]
 
int dfs(int node , int source)
{
    if (visited[node] == 1)    return 0;

    cycle[source].push_back( node ) ;

    visited[node] = 1;
    int x = dfs(goesTo[node] , source);
    return (x + 1); // length of cycles depth including itself 
}

auto noOfTranspositions(vector<int> &P, int n)
{
    // Initializing visited[] array
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
 
    // building the goesTo[] array
    for (int i = 0; i < n; i++)
        goesTo[P[i]] = i + 1;
 
    int transpositions = 0;
    int goodPairFound = 0 ;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            int ans = dfs(i, i);
            auto &c = cycle[i];

            set<int> s(begin(c), end(c));

            for (auto x : s)
                if (s.count(x + 1))
                    goodPairFound = 1;

            transpositions += ans - 1;
        }
    }

    return pair{transpositions, goodPairFound};
}

void solve(int& __case__)
{
    cycle.clear() ;

    int n;  cin >>  n ;
    vector<int> v(n) ;
    for(int &x : v) cin >> x ;

    auto [ transpose , goodPairPresent ] = noOfTranspositions(v,n) ;

    int ans = transpose + 1; // general case 

    if (goodPairPresent)  ans -= 2 ;

    cout << ans << "\n" ;
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
