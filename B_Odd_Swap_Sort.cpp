#include <bits/stdc++.h>
using namespace std;

#include"debugging.h"
#define print(x) cout  << (#x) << " = " << x << "\n" ; 
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " ; cerr << (a) << '\n' ; err(++it, args...);}
#define dbg error


#define int long long
#define inf 1e18 
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

bool solve()
{

    int n;  cin >> n;    vector<int> v(n);
    vector<int> odd , even ;

    map<int,vector<int>> fr ;

    for (int &i : v)
    {
        cin >> i;  ((i & 1) ? odd : even).push_back(i);
        fr[i].push_back({i}) ;
    }


    // PRT(v,odd,even) ;

    dbg(v,odd,even,fr) ;


    if(is_sorted(all(v))) return 1 ;
    return (!is_sorted(all(odd)))  or (!is_sorted(all(even))) ? 0 : 1 ;

}

signed main()
{
    FAST 
    t_case
    {
        cout << (solve() ? "Yes\n" : "No\n");
    }
}

