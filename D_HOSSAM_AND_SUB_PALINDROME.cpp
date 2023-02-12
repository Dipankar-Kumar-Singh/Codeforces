#include <bits/stdc++.h>
using namespace std;

#include"/home/dk/Code/debug/debugging.h"
#define nl "\n"

int const N = 1e1 ;

// int parents[N][N];
// vector<int> edges[N];

vector<vector<int>> parents(N , vector<int>(N)) ;
vector<vector<int>> dp(N , vector<int>(N)) ;
vector<vector<int>> edges(N) ;

void DFS(int node, int parent, int ori)
{
    parents[ori][node] = parent;

    // int ORG = ori + 1 ;
    // int NODE = node + 1 ;
    // int PARENT = parent  + 1;
    // dbg(ORG , NODE  , PARENT) ;

    for (int child : edges[node])
    {
        if (child == parent)
            continue;

        DFS(child, node, ori);
    }
}

string word;

// int dp[N][N];

int rec(int a, int b)
{
    if (a > b)
        swap(a, b); 

    if (dp[a][b] != -1)
        return dp[a][b];

    if (parents[a][b] == a)
    {
        dp[a][b] = (word[a] == word[b]) ? 2 : 1;
        return dp[a][b];
    }

    if (word[a] == word[b])
        dp[a][b] = 2 + rec(parents[b][a], parents[a][b]);
    else
        dp[a][b] = max(rec(a, parents[a][b]), rec(parents[b][a], b));
    return dp[a][b];
}

void prob()
{
    int n;
    cin >> n;

    dp = vector<vector<int>>(n +  1 , vector<int> (n + 1)) ;

    for (int i = 0; i < n; i++)
    {
        edges[i].clear();
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    cin >> word;
 
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u - 1].push_back(v - 1);
        edges[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < n; i++)
    {
        cerr << "SOURCE : " << i + 1 << nl ;
        DFS(i, -1, i);
        cerr << nl ;
    }

    cerr << "\n" ;
    for(int i = 0 ; i <  n; i++)
    {
        for(int j = 0 ; j < n ;  j++)
        {
            cerr << parents[i][j] << "  " ;
        }

        cerr << "\n" ;
    }

    int max_p = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (dp[i][j] != -1)
                continue;

            max_p = max(max_p, rec(i, j));
        }
    }

    cout << max_p << '\n';
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        prob();

    return 0;
}           