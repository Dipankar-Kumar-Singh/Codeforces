#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int inf = LONG_LONG_MAX - 1 ;

map<int,int> m ;
map<int,int> vis ; 

int solve(string &s , int target )
{
    int num = stoll(s) ;
    int len = s.size() ;

    if(len==target)
    {
        return 0;
    }

    if(len > target) return inf ;

    if(vis[num]) return m[num] ;
    vis[num] = 1 ;

    int currAns = inf ;
    vector<int> vis(11) ;

    for(int i = 0 ; i < s.size() ; i++)
    {
        int curr = num ;
        int d = s[i] - '0';

        if(vis[d]) continue;
        vis[d] = 1 ;
        if(d<2) continue;


        int newNum =  (num * d );
        auto newS =  to_string(newNum) ;

        currAns = min(currAns, 1 + solve(newS, target));
    }

    return m[num] = currAns ;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    auto s = to_string(x);

    int res = solve(s, n);

    if (res == inf)
    {
        cout << -1;
        return;
    }

    cout << res << nl ;
}
signed main(){   FAST   solve() ;  }



