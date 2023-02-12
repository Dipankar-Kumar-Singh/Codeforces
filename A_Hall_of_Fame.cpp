#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

void solve(int& __case__)
{

    // cout << "case :" << __case__ << " " ;  

    int n ; cin >> n ;
    string s ; cin >> s ; 

    int firstR = -1 ;
    int firstL = -1 ;

    for(int i = 0 ; i < n; i++)
    {
        if(s[i] == 'R')
        {
            firstR = i ;
            break ;
        }
    }

    for(int i = n - 1 ; i >= 0 ; i-- )
    {
        if(s[i] == 'L')
        {
            firstL = i ;
            break ;
        }
    }


    if(firstL == -1 or firstR == -1)
    {
        cout << -1 << nl ;
        return ;
    }

    if(firstR < firstL)
    {
        cout << 0 << nl ;
        return ;
    }


    for(int i = 0 ; i + 1 <  n ; i++)
    {
        swap(s[i] , s[i+1]) ;

        if(s[i] == 'R' and s[i + 1] == 'L')
        {
            cout << i + 1 << nl ;
            return ;
        }

        swap(s[i] , s[i + 1] ) ;

    }

    cout << -1 << nl ;
    

    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
