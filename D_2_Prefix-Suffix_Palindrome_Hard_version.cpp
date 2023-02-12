#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

string solve_palindrome(const string &s)
{
    string a = s;
    vector<int> pref(2 * s.size() + 1000);
    int c = 0 ;
    reverse(a.begin(), a.end());
    a = s + "#" + a;
    c = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        while (c != 0 && a[c] != a[i])  c = pref[c - 1];
        if (a[c] == a[i]) c++;
        pref[i] = c;
    }
    return s.substr(0, c);
}

void solve()
{
    string s ;
    cin >> s ;
    int n = s.size();

    int l = 0, r = n - 1;
    int commonLength = 0;
   
    while (l < r)
    {
        if (s[l] != s[r])  break;
        commonLength++;
        l++, r--;
    }

    string middle;
    for (int i = commonLength; i < n - commonLength; i++)
        middle += s[i];
    
    string a , b ;

    for(int i = 0 ; i < commonLength ; i++) a += s[i] ;
    
    b = a ;    reverse(all(b)) ;

    string ans1 = a + solve_palindrome(middle) + b;

    string reversed_Middle = middle ;
    reverse(all(reversed_Middle)) ;

    string ans2 = a + solve_palindrome(reversed_Middle) + b;

    cout << (ans1.size() > ans2.size() ? ans1 : ans2) << nl;
}

signed main()
{
    FAST;
    TestCases
    solve();
}
