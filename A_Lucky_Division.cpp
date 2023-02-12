#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 



signed main()
{   FAST  

    int n ; 
    cin >> n;

    vector<int> luckNumbers = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    for (auto num : luckNumbers)
    {
        if(n%num==0)
        {
            cout << "YES" << nl ;
            return 0; 
        }
    }

    cout << "NO\n" ;
}
