#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;


void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    set<char> st(all(s));

    int duplicate = n - st.size();

    cout << (st.size() * 2) + duplicate << nl;
}
signed main(){   FAST      TestCases      solve() ;  }



