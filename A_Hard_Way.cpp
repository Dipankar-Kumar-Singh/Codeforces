#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

void solve()
{
    vector<pair<int,int>> points(3) ;  
    for(auto &[x,y] : points) { cin >> x >> y ;swap(x,y) ;}
    sort(all(points)) ; reverse(all(points)) ;

    auto &[y1, x1] = points[0];
    auto &[y2, x2] = points[1];
    auto &[y3, x3] = points[2];

    cout << ((y1==y2 and y3<y1) ? abs(x2-x1) : 0)  << "\n" ; 
}

signed main(){   FAST      TestCases      solve() ;  }