#include <bits/stdc++.h>
using namespace std;
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void solve()
{
    int n ;  cin >> n;
    map<char, int> m1, m2;
    string s;    cin >> s;
    string t;    cin >> t;

    for (auto &x : s)  m1[x]++;
    for (auto &x : t)  m2[x]++;

    if (m1['a'] != m2['a'] or m1['b'] != m2['b'] or m1['c'] != m2['c'])
    {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        char &target = t[i];

        if (s[i] == target)  continue;

        if (target == 'a')
        {
            if (s[i] != 'a')
            {
                cout << "NO\n";
                return;
            }
        }

        else if (target == 'b')
        {
            for (int j = i; j < n; j++)
            {
                if (s[j] == 'c')
                {
                    cout << "NO\n";
                    return;
                }

                if (s[j] == 'b')
                {
                    swap(s[j], s[i]);
                    break;
                }
            }
        }

        else if (target == 'c')
        {
            for (int j = i; j < n; j++)
            {
                if (s[j] == 'a')
                {
                    cout << "NO\n";
                    return;
                }

                if (s[j] ==  'c')
                {
                    swap(s[j], s[i]);
                    break;
                }
            }
        }
    }

    if(s==t)
    {
        cout << "YES\n" ;
    }

    else 
    {
        cout << "NO\n" ;
    }
}
signed main(){   FAST      TestCases      solve() ;  }
