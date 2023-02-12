#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

auto pass(vector<int> &v)
{
    map<int,int> m ; 
    for(auto x : v ) m[x]++ ;
    return m ;
}

void solve()
{
    int n;   cin >> n;
    int num ; cin >> num ;
    vector<int> v(n);  for (auto &x : v) cin >> x;
    sort(all(v)) ;

    auto m = pass(v) ;
    for(int i = 0 ; i < num ; i++)
    {
        if(m[i] % ( i +  1 ) != 0)
        {
            cout << "No" << nl ;
            return ;
        }
        m[i + 1] += m[i] / (i + 1);
    }
    cout << (m[num] >= 1 ? "Yes" : "No") << nl;
}
signed main(){   FAST   solve() ;  }



