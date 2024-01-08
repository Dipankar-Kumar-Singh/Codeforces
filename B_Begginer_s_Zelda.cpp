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
    int n ; cin >> n ;
    vector<int> indeg(n + 1) ;
    for(int i = 1 ; i <= n - 1 ; i++) { 
        int x , y ;
        cin >> x >> y ; 
        indeg[x]++ ; indeg[y]++ ;
    }

    int res = count(all(indeg),1LL) ;

    cout << (res + 1) / 2 << nl;
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
