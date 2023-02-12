#include <bits/stdc++.h>
using namespace std;
#define all(x)  (x).begin() , (x).end()

void solve()
{
    string a , b ; cin >> a >> b ;

    int oneA = count(all(a),'1') ;
    int oneB = count(all(b),'1') ;

    if ((a.size() != b.size()) or (oneA and !oneB) or (!oneA and oneB))
    {
        cout << "NO\n" ;
    }

    else cout << "YES\n" ;

}
signed main(){ solve() ;}



