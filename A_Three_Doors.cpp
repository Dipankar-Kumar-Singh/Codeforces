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
    vector<int> v(4);

    for (int i = 1; i <= 3; i++)
    {
        cin >> v[i];
    }

    int currKey = n;
    set<int> s;
    while (s.size() != 3)
    {
        // if (currKey == 0)
            // break;
        s.insert(currKey);
        currKey = v[currKey];
        if (currKey == 0)
            break;
    }

    bool f = 1;
    for (int i = 1; i <= 3; i++)
        if (s.count(i) == 0)
            f = 0;

    if (f)
    {
        cout << "YES\n";
    }

    else
        cout << "NO\n";
}
signed main(){   FAST      TestCases      solve() ;  }



