#include <bits/stdc++.h>
using namespace std;

#define int long long
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"

    //  🤯🤯🤯 NEW AMAZING TRICK .... 

/* -------------------------------------------------------------------------- */
/* ---------------------------------- LOGIC --------------------------------- */
/* -------------------------------------------------------------------------- */


/*
          1         2          3           4
        [ a _______ a ________ a _________ a ]
        [ xxxxxxxxx zzzzzzzzzz nnnnnnnnnnnnn]
        [rrrrrrrrrrrrrrrrrrrrrr ]
        
        if(we have seen xxxxxx --> good ... we store in map )
        ...when we go to 2nd 'a' --> we see xxx + zzz --> rrrr
        we check if we have seen rrrr before ....
        but rrrr is brand new .. how can we see rrrrr before ? 
        it is because ... if zzzzz == 0 then value of rrrr = xxx ;
        so seeeing rrrr means ... 
        zzzzz == 0 and xxxxx != 0 [ only xxxxx is present in our fr map]

        seeing rrrrr ==> rrrrr = xxxxxxx and  zzzzz = 0 ;

        so if zzzz = 0 --> ans++ ; [ we wanted to see a segment whoes sum is zero ]
        and because we are just doing it for only a single character possitions ... 
        we can be sure .. that fr map only  contains fr of prefix sum of 'a' ...


*/


void AC_SOLUTION()
{
    map<char , int > cost ;
    for(auto c = 'a' ; c <= 'z' ; c++ ){  cin >> cost[c] ;}
    
    string s ; cin >> s ;

    vector<int> sum(s.size() + 2 ,0) ;
    map<char,vector<int>> location ;

    for(int i = 0 ; i < s.size() ; i++)
    {
        char c = s[i];
        sum[i+1] = (sum[i]  + cost[c]) ;
        location[c].push_back(i+1) ; 
        // i+1 => to make 1 based index in loc arry
    }

    int ans = 0 ;

    for(char c = 'a' ; c <= 'z' ; c++)
    {
        map<int,int> fr ; 
        // temp frequency map for storing frequnecy of each prefix s
        for(auto index : location[c])
        {
            ans += fr[sum[index - 1]] ;
            fr[sum[index]]++ ;
        }
    }

    cout << ans << nl ;
}


signed main()
{
    FAST 
    AC_SOLUTION() ;
}

