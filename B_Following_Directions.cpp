#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

void solve(int& __case__)
{

    int n ; cin >> n  ;
    string moves ; cin >> moves ;

    int x = 0 , y = 0 ;

    for(auto c : moves)
    {
        if(x == 1 and y==1)
        {
            cout << "YES\n" ;
            return ;
        }

        if(c == 'U')
        {
            y++ ;
        }

        else if( c == 'D')
        {
            y-- ;
        }

        else if(c == 'L')
        {
            x-- ;
        }

        else if(c == 'R')
        {
            x++ ;
        }

        if(x == 1 and y==1)
        {
            cout << "YES\n" ;
            return ;
        }
    } 


    cout << "NO" << nl ;

    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
