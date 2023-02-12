#include <bits/stdc++.h>
using namespace std;
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int const N = 2e6 + 1e4 ;
vector<int> present(N) ;
vector<int> p(N);

void solve()
{
    int n , c  ; cin >> n >> c ;
    for(int i = 0 ; i <= 2*c + 10 ; i++)  p[i] = present[i] = 0 ;

    vector<int> v(n);
    for (auto &x : v)
    {
        cin >> x;     
        present[x] = 1;
    }

    sort(all(v)); v.resize(unique(all(v)) - v.begin());

    for (int i = 1; i <= 2 * c + 10; i++)
        p[i] = (p[i - 1] + present[i] );
    
    for (auto &y : v)
    {
        for (int m = 1 ; m * y <= c ; m++)
        {
            int numerator_present =  p[(m+1)*y - 1] - p[(m)*y -1 ] ;
            if (numerator_present and !present[m])
            {
                cout << "No\n";
                return;
            }
        }
    }

    cout <<  "Yes"  << nl ;
}

signed main(){   FAST      TestCases      solve() ; }

