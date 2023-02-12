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
    int n, k, b, s;
    cin >> n >> k >> b >> s;

    vector<int> v(n);


    v = vector<int>(10) ;

    v.front() = s;
    int currb = s / k;

    if(n==1 ) {cout << (currb == b ? s : -1) << nl;   return;   }
    if (currb == b){  for (auto x : v)  cout << x << " " ;  cout << nl; }
    else if (currb < b) cout << -1 << nl;  
    else if(currb > b)
    {
        int extra = s -  (((b+1) * k) - 1);
        v.front() -= extra;

        int rem = n - 1;
    
        for (int i = 1; i < n; i++)
        {
            int toremove = min(k-1,extra) ;
            extra -= toremove ;
            v[i] += toremove;
            if (extra <= 0)  break;
        }

        if(extra!=0)
        {
            cout << - 1 << nl ;
            return ;
        }

        for (auto x : v)  cout << x << " ";
            cout << nl;
    }
}
signed main(){   FAST      TestCases      solve() ;  }



