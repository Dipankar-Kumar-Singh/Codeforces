#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   int n ; cin >>n ;
   string s;  cin>> s ;

    if (n == 1)
    {
        if (s.front() == 'W')    cout << "YES\n";
        else   cout << "NO\n";
        return;
    }

    if(n==2)
    {
        if(s=="WW" or s=="RB" or s == "BR") cout << "YES\n" ;
        else cout << "NO\n" ;
        return ;
    }

    int f = 0 ;



    for(int i = 0 ; i < n ; i++)
    {
        int r{0} , c{0} ; 
        if(s[i]!='W')
        {
            while (s[i]!='W')
            {
                r += (s[i]=='R') ;
                c += (s[i]=='B') ;
                i++ ;
                if(i==n) break;
            }
            // i-- ;
            f += (r==0 or c==0)    ;    
        } 
    }

   if(f)
   {
       cout << "NO\n" ;
   }

   else cout << "YES\n" ;


}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

