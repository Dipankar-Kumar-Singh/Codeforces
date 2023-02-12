    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
#include <bits/stdc++.h>
using namespace std;
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;



// K M P --> Prefix Function 
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// Z Algo 
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}


void solve()
{
    string s ; cin >> s;
    auto KMP = prefix_function(s) ;
    int prefixLength = KMP.back() ;

    multiset<int> mt(all(KMP)) ;
    mt.erase(mt.find(KMP.back()));

    if(prefixLength == 0 )
    {
        cout << "Just a legend" ;
        return  ;
    }
    if (mt.count(prefixLength)) 
    {
        cout << s.substr(0,prefixLength)  ;
        return ;
    }
    if(KMP[prefixLength - 1] == 0 ) // due to Zero Based Index --> i = index - 1
    {
        cout << "Just a legend" ;
        return ;
    }

    int l = KMP[prefixLength - 1] ;
    cout << s.substr(0,l) << nl   ;
}

signed main() { FAST  solve(); }