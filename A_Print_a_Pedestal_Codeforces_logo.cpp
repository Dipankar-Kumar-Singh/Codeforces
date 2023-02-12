#include <bits/stdc++.h>
using namespace std;
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

void solve()
{
    int n ; cin >> n; 
    int a {} , b{} , c{} ;

    int x = n/3 ;
    if(n%3==0)      a = x ,     b = x + 1 ,     c = x - 1 ;
    else if(n%3==1) a = x ,     b = x +2 ,      c = x - 1 ;
    else if(n%3==2) a = x + 1 , b = x + 2 ,     c = x - 1 ;

   cout << a << " " << b << " " << c << "\n"  ;
}

signed main(){   FAST      TestCases      solve() ; }

