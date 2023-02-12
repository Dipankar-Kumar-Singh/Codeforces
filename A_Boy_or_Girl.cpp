#include <bits/stdc++.h>
using namespace std;
#define all(x)  (x).begin() , (x).end()

signed main()
{
    string s; cin >> s ; set<char> st(all(s)) ;
    if((st.size()&1)) cout << "IGNORE HIM!\n" ;
    else cout << "CHAT WITH HER!\n" ;
}
