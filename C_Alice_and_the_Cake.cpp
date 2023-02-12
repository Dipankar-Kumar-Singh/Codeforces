#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

void solve()
{
    int n{0} , summ{0} ; cin >> n ;   vector<int> v(n) ;
    for(auto &x : v ) cin >> x , summ+= x ;

    multiset<int> s (all(v)) ;    queue<int> q ;    q.push(summ) ;

    while ((!q.empty()) and q.size()<=s.size())
    {
        int x = q.front() ; q.pop() ;
        if(s.count(x)) s.erase(s.find(x)) ;
        else
        {
            int a = ceil((x/2.0)) , b = floor((x/2.0)) ;
            q.push(a) , q.push(b) ;
        }
    }
    cout << ((q.size() or s.size()) ?  "NO" :  "YES") << "\n" ;
}
signed main(){   FAST      TestCases      solve() ;  }