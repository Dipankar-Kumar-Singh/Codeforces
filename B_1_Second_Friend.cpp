#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void print(bool ans , vector<vector<char>> &v)
{
    cout << "Case #" << _case << ": " << (ans ? "Possible" : "Impossible") << nl;
    for(auto& row : v) {
        for(auto &c : row)  cout << c ;   cout << nl ;
    }
}


void solve()
{
   int n;  cin >> n;  int m ; cin >> m ;
   bool Tree = 0 ;
   vector<vector<char>> v(n, vector<char>(m));

   for (auto &r : v)
       for (auto &x : r)
           cin >> x, Tree |= (x == '^');

    auto AllTree = v ;
    for(auto &r : AllTree) for(auto &c : r) c = '^' ;

   if(Tree){

        if(min(m,n)==1) {
            cout << "Case #" << _case << ": " << "Impossible"<< nl;
        }
        else print(1,AllTree) ;
   }
   else   print(1,v) ;
   
}
signed main() { 
    // #ifndef ONLINE_JUDGE
    freopen("C:/Users/dipan/OneDrive/ProCode/CP/FunSolve/META/Input.txt", "r", stdin);
    // freopen("C:/Users/dipan/OneDrive/ProCode/CP/FunSolve/META/error.txt", "w", stderr);
    freopen("C:/Users/dipan/OneDrive/ProCode/CP/FunSolve/META/output.txt", "w", stdout);
    // #endif
    FAST TestCases solve(); 
}
