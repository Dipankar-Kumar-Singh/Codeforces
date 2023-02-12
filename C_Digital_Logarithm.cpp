#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int trimLight(vector<int> &a);
int trimHard(vector<int> &a);
void removeDuplicate(vector<int> &a , vector<int> &b ) ;

void solve()
{
   int n;   cin >> n;
   vector<int> a(n) , b(n) ;
   int ans = 0 ;

   for(int &i : a) cin >> i ;
   for(int &i : b) cin >> i ;

   removeDuplicate(a,b) ;
   ans += trimLight(a) ;
   ans += trimLight(b) ;

   removeDuplicate(a,b) ;
   ans += trimHard(a) ;
   ans += trimHard(b) ;

   cout << ans  << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }



void removeDuplicate(vector<int> &a , vector<int> &b )
{
    multiset<int> m1(all(a)) ;
    multiset<int> m2(all(b)) ;

   for(auto x : a)
   {
       if ((m1.find(x) != m1.end()) and (m2.find(x) != m2.end()))
       {
            m1.erase(m1.find(x)) ;
            m2.erase(m2.find(x)) ;
       }
   }

   a = vector<int>(all(m1)) ;
   b = vector<int>(all(m2)) ;

}

int trimHard(vector<int> &a)
{
    int ans = 0;
    for (int &i : a)
    {
        if (i > 1)
        {
            i = 1;
            ans++;
        }
    }
    return ans ;
}

int trimLight(vector<int> &a)
{
    int ans = 0;
    for (int &i : a)
    {
        if (i > 9)
        {
            i = to_string(i).size();
            ans++;
        }
    }
    return ans ;
}





