#include <bits/stdc++.h>
using namespace std;

signed main()
{
   string a , b ; cin >> a >>  b ;

   if (a.size() > b.size())  swap(a, b);

   string curr;

   int g = gcd(a.size(),b.size()) ;
   int ans = 0 ;

    for (int i = 0; i < a.size() ; i++)
    {
        curr += a[i] ;
        string s ;

        if(g%(i+1)==0) ;
        else if ((i + 1) % g) continue;

        while(s.size()< a.size()) s += curr ; 

        if(s==a) 
        {
            while(s.size()<b.size()) s+=curr ;
            if(s==b) ans++ ;
        } 

        else 
        {
            continue;
        }
    }

   cout << ans << endl ;

}




