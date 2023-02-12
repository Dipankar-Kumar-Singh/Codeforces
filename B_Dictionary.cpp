#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 




signed main()
{   FAST  

    set<string> s ;
    int n ; cin >> n ;
    vector<string> org ;

    for(auto c1 = 'a' ; c1 <=  'z' ; c1++)
    {
        for(auto c2 = 'a' ; c2 <= 'z' ; c2++)
        {
            if(c1==c2) continue;

            string t ;
            t+=c1 ;
            t+=c2 ;
            s.insert(t) ;
        }
    }

    vector<string> done(all(s)) ;

    for(int i = 0 ; i < n ; i++) 
    {
        string ss ; cin >> ss ;
        int id = lower_bound(all(done),ss) - done.begin() + 1;
        cout << id << nl ;
        
    }




}

