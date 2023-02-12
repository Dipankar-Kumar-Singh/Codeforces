#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;


class Matrix
{
    public : 
    int n ;
    vector<vector<int>> v ;
    vector<vector<int>> mat  ; 
    int N ;

    Matrix(vector<vector<int>> &vec)
    {
        N = n;
        n = vec.size() ;
        v = vec ;
        mat = vec ;
    }

    void rotateMatrix()
    {
        for(int i = 0 ; i < n/2 ; i++)
        {
            for(int j = i ; j < n-i-1 ; j++)
            {
                int temp = v[i][j] ;
                v[i][j] = v[n-1-j][i] ;
                v[n-1-j][i] = v[n-1-i][n-1-j] ;
                v[n-1-i][n-1-j] = v[j][n-1-i] ;
                v[j][n-1-i] = temp ;
            }
        }
    }

};


 
bool compareall(int a , int b , int c , int d)
{
    if(a==b && b==c && c==d && a==d)
    {
        return true ;
    }

    return false ;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v  = vector<vector<int>> (n,vector<int>(n)) ;

    for(int i = 0 ; i < n;  i++)
    {
        string s;  cin >> s ;
        for(int j = 0 ; j < n ; j++)
        {
            int x = s[j] - '0' ;
            v[i][j] = (s[j] - '0') ;
        }
    }


    Matrix m(v);

    auto v1 = m.v;
    m.rotateMatrix();
    auto v2 = m.v;
    m.rotateMatrix();
    auto v3 = m.v;
    m.rotateMatrix();
    auto v4 = m.v;

    int ans = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            int a = v1[i][j] ;
            int b = v2[i][j] ;
            int c = v3[i][j] ;
            int d = v4[i][j] ;
            
            int res = a + b + c + d ;
            
            ans += min(4-res,res) ;
        }
    }


    ans = ans/4 ;

    cout << ans << nl ;

}


signed main(){   FAST      TestCases      solve() ;  }



