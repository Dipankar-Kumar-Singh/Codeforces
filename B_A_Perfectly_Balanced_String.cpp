#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
    string s; cin >> s; 
    set<char> present(all(s)) ; 
    
    map<char,int> firstseen , lastseen ;
    map<char,int> globalfr ;

    for(auto c = 'a' ; c <= 'z' ; c++ ) firstseen[c] = -1 ;
    for(int i = 0 ;  i < s.size() ; i++) 
    {
        globalfr[s[i]]++ ;
        if(firstseen[s[i]]==-1) firstseen[s[i]] = i ;
        lastseen[s[i]] = i ;
    }


    for(auto c = 'a' ; c <= 'z' ; c++ )
    {
        if(globalfr[c]>=2)
        {
            map<char,int> fr;

            for(auto cc = 'a' ; cc <= 'z' ; cc++ ) if(present.count(cc)) fr[cc] = 0 ;

            int st = firstseen[c];
            int ed = lastseen[c] ;
            for(int i = st ; i <= ed ; i++)
            {
                fr[s[i]]++ ;
            }

            int minfr = LONG_LONG_MAX , maxfr = LONG_LONG_MIN ;

            for(auto [ch,f] : fr )
            {
                minfr = min(minfr,f) ;
                maxfr = max(maxfr , f) ;
            }

            if(abs(maxfr-minfr)>1)
            {
                cout << "NO\n" ;
                return ;
            }
        }
    }

    cout << "YES\n" ; return ;

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

