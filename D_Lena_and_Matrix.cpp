#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int median(vector<int> &v)
{
    sort(all(v)) ;
    int n = v.size() ;
    if(n%2 == 0)
    {
        return  (v[n/2] + v[n/2 - 1])/2 ;
    }
    else
    {
        return v[n/2] ;
    }
}

void solve()
{
   int n ; cin >> n ; int m ; cin >> m ;
   vector< vector<char >> matrix (n , vector<char> (m)) ;

   for(auto &row : matrix) for(auto &x : row) cin >> x ;

   vector<int> xx , yy ;

   for(int i = 0; i < n ; i++)
   {
        for(int j = 0; j < m ; j++)
        {
            if(matrix[i][j] == 'B')
            {
                xx.push_back(i) ;
                yy.push_back(j) ;
            }
        }
   }

   sort(all(xx)) ; sort(all(yy)) ;

//    int x  = accumulate(all(xx),0)/xx.size() ;
//    int y  = accumulate(all(yy),0)/yy.size() ;
   int x  = median(xx) + 1 ;
   int y  = median(yy) + 1 ;

  

   cout << x << " " << y << nl ;
 



}
signed main(){   FAST      TestCases      solve() ;  }
