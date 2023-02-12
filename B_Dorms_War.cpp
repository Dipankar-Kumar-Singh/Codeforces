#include <bits/stdc++.h>
using namespace std;

// #include"C:\Users\dipan\OneDrive\ProCode\CP\debugging.h" 
// #define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
// void err(istream_iterator<string> it) {}
// template<typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " ; cerr << (a)  << "  " ; err(++it, args...);}
// #define dbg error


#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{

    cerr << nl << nl << nl ; 

    int n ; cin >> n; 
    string s ; cin >> s;
    int nn ; cin >> nn ;
    vector<int> special(26) ;
    for (int i = 0; i < nn; i++)
    {
        char c;
        cin >> c;
        special[(c - 'a')]++;
    }

    // dbg(n,s,nn,special) ; cerr << nl ;
    // dbg(s) ; cerr << nl ;

    // cout << s << " " ;

    int moves = 0 ;

    while (1)
    {
        vector<int> todel ;
        for(int i  = 0 ; i < s.size() ; i++)
        {
            if(special[s[i]-'a'])
            {
                // cerr << i << " " ;
                todel.push_back(i-1) ;
            }
        }

        set<int> del(all(todel)) ;


        // dbg(del) ; cerr <<  nl ;

        if(todel.size()==0)
        {
            cout << moves << nl ;
            return ;
        }

        if(todel.front()==-1 and todel.size()==1){
            cout << moves << nl ;
            return ;
        }


        string temp ;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(del.count(i)) continue;
            temp += s[i] ;
        }

        // cerr << temp << nl ;
        s = temp ;
        moves++ ;
    }

    // cerr << nl << nl ;
    cout << moves << nl ;
    
}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

