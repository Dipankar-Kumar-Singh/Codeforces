#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

const int INF = 1e18 + 10 ;
vector<int> v1 ;
vector<int> v2 ; 

int const N = 5e3 + 10 ;
vector<vector<int>> DP(N,vector<int>(N,-1) ) ;

int dp(int i , int j)
{
    if(i == v1.size()) return 0 ;
    if(j == v2.size()) return INF ;

    if(DP[i][j]!=-1) return DP[i][j] ;

    return DP[i][j] = min( dp(i+1,j+1) + abs(v1[i]-v2[j]) , dp(i,j+1) ) ;

}


void clean()
{
    v1.clear();  v2.clear();

    for (int i = 0; i < 5001; i++)
        for (int j = 0; j < 5001; j++)
            DP[i][j] = -1;
}

void solve()
{
    clean();

    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &x : v)   cin >> x;

    for(int i = 0 ; i < n ; i++)
    {
        if(v[i]==1) v1.push_back(i) ;
        else v2.push_back(i) ;
    }

   int n1 = v1.size() ;
   int n2 = v2.size() ;


   sort(begin(v1),end(v1)) ;
   sort(begin(v2),end(v2)) ;

   cout << dp(0,0) << nl ;

}
signed main(){   FAST    solve() ;  }



