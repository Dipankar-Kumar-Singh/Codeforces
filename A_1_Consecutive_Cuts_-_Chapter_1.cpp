#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

vector<int> rotate_(vector<int> v , int id )
{
    // ..... | ........
    vector<int> a  = vector<int>( begin(v) + id , end(v)) ;
    for(int i = 0 ; i < id ; i++) a.push_back(v[i]) ;
    return a ;
}

void solve()
{
    int n ; cin >> n;
    int k ; cin >> k ;
    vector<int> a(n);  for (auto &x : a) cin >> x;
    vector<int> b(n);  for (auto &x : b) cin >> x;

    int id = find(all(a),b.front()) - a.begin() ;

    // cout << "index = " << id << nl ;
    // for(auto x : rotate_(a,id)) cout << x << " " ; cout << nl ;

    if(k==0)
    {
        cout << ((a == b) ? "YES" : "NO") << nl; 
        return ;
    }

    if(rotate_(a,id) == b)cout << "YES\n" ;  
    else cout << "NO\n" ;

}
signed main()
{
    // #ifndef ONLINE_JUDGE
    freopen("C:/Users/dipan/OneDrive/ProCode/CP/FunSolve/META/Input.txt", "r", stdin);
    freopen("C:/Users/dipan/OneDrive/ProCode/CP/FunSolve/META/error.txt", "w", stderr);
    freopen("C:/Users/dipan/OneDrive/ProCode/CP/FunSolve/META/output.txt", "w", stdout);
    // #endif

    FAST TestCases solve();
}
