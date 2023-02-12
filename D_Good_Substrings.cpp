#include <bits/stdc++.h>
using namespace std;
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

/*
    Performance comp : 
    BEST TIME COMPLEXITY : 
    1) TRIES                 [   434 ms    ]  [ WORST MEMORY]
    2) STRING VIEW           [   1246 ms   ]  
    3) HASHING               [   1870 ms   ]  [ BEST MEMORY ]

    BEST SPACE COMPLEXITY :
    1) HASHING              [   52900 KB    ] 
    2) String View          [   64400 KB    ]
    3) TRIES                [   160100 KB   ]

    Easy to Impliment : all of them ..
    1) String view , 2) Tries , 3) Hashing 

    New Learning : All 3 Methods 
    🔥 String View use pointers insted of string ///
    🚩 hashing should be always done using DOUBLE HASH // To avoid collison 


*/

void sol_with_TRIE()
{

    vector<vector<int>> trie (1200005 , vector <int> (26,-1)) ;
   
    string s  ; cin >> s ;     int n = s.size() ;
    map< char , int > isBad ;    string seq ; cin >> seq ; 

    for(auto c = 'a' ;  c <= 'z' ; c++) if( seq[c - 'a'] == '0')  isBad[c] = 1 ;
    int limit ; cin >> limit ; 

    int ans = 0 ;
    int no_of_ties = 0  ;

     for(int i = 0 ; i < n ; i++)
    {
        int bad = 0 ;
        int loc_pointer = 0 ;
        for(int j = i ; j < n ; j++)
        {
            bad += isBad[s[j]] ;  if(bad > limit) break ;

            int  c = s[j] - 'a' ;

            if(trie[loc_pointer][c] == -1) 
            {
                ans++ ;
                ++no_of_ties ;

                trie[loc_pointer][c] = no_of_ties ;  // new trie open kiya hai ..
            }

            loc_pointer = trie[loc_pointer][c] ;
        }
    }

    cout << ans ;
    
}


void sol_WITH_HASHING()
{

    //  Eithr take VERY BIG BIG --> MOD to avoid colision ///
    // But still better to take 2 Hash /// 

    // MOD --> Defines the range of KEYS []
    // 1e9 + 7 Mod ->> 1e9 + 6 Keys ....

    //1e15 + 13 --> MOD --> RANGE OF KEYS [ 0 ---  1e15 + 12] --> Double the range -->
    // --> Half the collision .. but sitll ...
    // better to use double hashing if Don't want to get WA on main test after pretest 🥲 

    int const MOD1 = 1e9 + 7 , MOD2 = 1e9 + 13 ;
    int prime = 1999 ;

    string s  ; cin >> s ;     int n = s.size() ;
    map< char , int > isBad ;    string seq ; cin >> seq ;  set<pair<int,int>> ans ;

    for(auto c = 'a' ;  c <= 'z' ; c++) if( seq[c - 'a'] == '0')  isBad[c] = 1 ;
    int limit ; cin >> limit ; 

    for(int i = 0 ; i < n ; i++)
    {
        int h1{} , h2{} ;
        int bad = 0 ;
        int prime_power = 1 , prime_power2 = 1 ;

        for(int j = i ; j < n ; j++)
        {
            bad += isBad[s[j]] ;
            if(bad > limit) break ;

            char c = s[j] ;
            h1 = (h1 + ((c -'a' + 1) * prime_power)) % MOD1 ;
            h2 = (h2 + ((c -'a' + 1) * prime_power2)) % MOD2 ;
            prime_power = (prime_power * prime )% MOD1 ;
            prime_power2 = (prime_power2 * prime )% MOD2 ;
            ans.insert({h1,h2}) ;
        }
    }
    cout << ans.size() ;
}


void sol_with_STRING_VIEW_STL()
{


    string s  ; cin >> s ; 
    int n = s.size() ;
    map< char , int > isBad ;
    string seq ; cin >> seq ;
 
    for(auto c = 'a' ;  c <= 'z' ; c++)    
        if( seq[c - 'a'] == '0')  isBad[c] = 1 ;
 
    int limit ; cin >> limit ; 
    string  cp = s ; s = "a" ; s += cp ;
    set<string> ans ;
 
    unordered_set<string_view> st ;
    string_view v  = s  ;
 
    for(int back = 1 ; back <= n ; back++)
    {
        int bad = 0 ;
        for(int front = 0 ; back + front <= n ; ++front)
        {
            if(isBad[s[back+front]])
            {
                bad++ ;
                if(bad > limit) break ;
            }
            string_view s1 = v.substr(back,front+1) ;
            st.insert(s1) ;
        }
    }
 
    cout << st.size() << "\n" ;
}



signed main()
{
    FAST 

    // sol_with_STRING_VIEW_STL() ; 
    // sol_WITH_HASHING( ) ;
    sol_with_TRIE() ;
}

