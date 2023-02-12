#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

int test = 0 ;
void put(int i , vector<int> &v , vector<pair<int,int>> &op)
{
    int n = v.size() ;
    int h = v.front() ;
    int sum = v[i] + h ;

    if (sum % 2 == 0)
        op.push_back({i,n - 1});
    else
        op.push_back({0, i});
}
void solve()
{
    int n ; cin >> n ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ; 
    
    vector<pair<int,int>> opration ;

    if (is_sorted(all(v)))
    {
        cout << 0 << nl;
        return;
    }

    if ((v.front() + v.back()) % 2 == 0)
    {
        v.front() = v.back() ;
        opration.push_back({0,n-1}) ;
    }

    else 
    {
        v.back() = v.front() ;
        opration.push_back({0,n-1}) ;
    }

    for(int i = 1 , hero = v.front() ; i < n - 1 ; i++)
    {
        put(i,v,opration) ;
    }

    cout << opration.size() << nl ;
    for(auto [ x , y] : opration) cout << ++x << " " << ++y << nl ;

}

signed main(){  FAST    TestCases    solve() ; }