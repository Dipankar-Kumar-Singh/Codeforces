#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void solve()
{
   int n;   cin >> n;
   vector<string> v1(n);  for (auto &x : v1) cin >> x;
   vector<string> v2(n);  for (auto &x : v2) cin >> x;
   vector<string> v3(n);  for (auto &x : v3) cin >> x;


   map<string,int> m1 , m2 , m3 , m;

   int a =  0 , b = 0 , c =  0 ;

   
   set<string> st ;

   for(auto &s : v1)
       m1[s]++, st.insert(s) , m[s]++ ;
   for (auto &s : v2)
       m2[s]++, st.insert(s) , m[s]++;
   for (auto &s : v3)
       m3[s]++, st.insert(s) , m[s]++ ;

    for(auto &s : st)
    {
        if(m[s]==1)
        {
            a += (m1[s]*3) ;
            b += (m2[s]*3) ;
            c += (m3[s]*3) ;
        }

        else if(m[s]==2)
        {
            a += (m1[s]*1) ;
            b += (m2[s]*1) ;
            c += (m3[s]*1) ;
        }
    }

    cout << a << " " << b << " " << c << nl ;
}
signed main(){   FAST      TestCases      solve() ;  }



