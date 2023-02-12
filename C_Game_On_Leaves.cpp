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
    int n ; cin >> n ;
    int x ; cin >> x ;

    vector<int> deg(n+10) ;

    for(int i = 1; i <= n - 1; i++)
    {
        int a; int b ;
        cin >> a >> b ;
        deg[a]++ ; deg[b]++ ;
    }

    if (deg[x] <= 1)
    {
        cout << "Ayush\n";
        return;
    }

    if (n % 2)
        cout << "Ashish" << endl;
    else
        cout << "Ayush" << endl;
}
signed main(){   FAST      TestCases      solve() ;  }



