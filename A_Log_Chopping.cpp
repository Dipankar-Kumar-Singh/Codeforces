#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   int n ; cin >> n ;
   set<int,greater<>> s ; 
   int sum = 0 ;
   int moves = 0 ;
   for(int i = 0 ; i < n ; i++)
   {
       int x ;cin>> x; 
       s.insert(x) ;
       if(x>1) sum += x ;
       moves += (x-1) ;
   }

   if(moves&1)
   {
       cout << "errorgorn\n" ;
       return ;
   }

//    if(sum%2==0 and sum>0)
//    {
//        cout << "errorgorn\n" ;
//        return ;
//    }

   else {cout << "maomao90\n" ; return ;}


   int f = 0 ;

   while (s.size())
   {
      
      int x =  *s.begin() ; s.erase(s.begin()) ;
      if(x==1) break;
      f = !f ;
      s.insert(1) , s.insert((x-(1))) ;
   }

   if(f==1)
   {
       cout << "errorgorn\n" ;
       return ;
   }

   else cout << "maomao90\n" ;
   


}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

