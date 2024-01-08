/* 
            ~~~~~~~~~~~~{ after 1 Year of Pause, I am back : ) }~~~~~~~~~~ 
    I will fall .... Yep free fall  : ) .... I will go up again ! ... 
    Always proud of my efforts in past - 2nd Year(Start of cp) -- 3rd Year(till 1st sem)
    Last 6 month of college ... want to look back and smile : ) , No Regret 
*/

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{
    int n; cin >> n ;
    string s ; cin >> s ; 

    map<char,vector<int>,greater<>> locs ;  

    for(int i = 0 ; i < n ; i++){
        locs[s[i]].push_back(i) ;
    }

    vector<int> takenIds ;

    int r = -1 ;

    for(auto &[c , ids] : locs){
        auto it = lower_bound(begin(ids),end(ids),r) ;
        while(it != ids.end()) {
            takenIds.push_back(*it) ;
            r = *it++ ;
        }
    }

    vector<char> takenChars; 
    for(auto &i : takenIds) takenChars.push_back(s[i]) ;

    set<char,greater<>> st (all(takenChars)) ;

    int biggestCount = count(all(takenChars),*st.begin()) ;
    

    sort(all(takenChars)) ;

    if(is_sorted(all(s))) {
        cout << 0 << nl ;
        return ;
    }

    int put = 0 ;
    for(int i : takenIds){
        s[i] = takenChars[put++] ;
    }

    if(is_sorted(all(s))){
        cout << takenChars.size() - biggestCount << nl ;
    } else {
        cout << -1 << nl ;
    }

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}

/*
            ██████╗ ██╗██████╗  █████╗ ███╗   ██╗██╗  ██╗ █████╗ ██████╗ 
            ██╔══██╗██║██╔══██╗██╔══██╗████╗  ██║██║ ██╔╝██╔══██╗██╔══██╗
            ██║  ██║██║██████╔╝███████║██╔██╗ ██║█████╔╝ ███████║██████╔╝
            ██║  ██║██║██╔═══╝ ██╔══██║██║╚██╗██║██╔═██╗ ██╔══██║██╔══██╗
            ██████╔╝██║██║     ██║  ██║██║ ╚████║██║  ██╗██║  ██║██║  ██║
            ╚═════╝ ╚═╝╚═╝     ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
*/                                                          
