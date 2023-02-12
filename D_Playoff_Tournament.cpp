#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

// MAAZAA AAGYA .... PURA PURA KHUD SEY .. BINA TITORIAL KI EK LINE DEKHEY ...  : )
// DIN SAFAL KAR DIYA ESS QUESTION NEY ....

int N = 0 ;
vector<int> v ;
string s ;
int K ;

void update(int node)
{
    int x = N - node;

    if (node + 1 <= (1 << (K - 1)))
    {
        if(node < N and node >= 0) 
        {
            if(s[node]=='?') v[node] = 2 ;
            else v[node] = 1 ;
        }
        if ((x / 2) >= 1)  update(N - (x/2));
        return;
    }

    v[node] = 0 ;

    int lc = v[N - (2 * x + 1)];
    int rc = v[N - (2 * x)];

    if (lc == -1 or rc == -1) {  v[node] = 1  ;   return ;}

    if(s[node] == '?')  v[node] += (lc + rc) ;

    else if (s[node] == '0')     v[node] += lc;

    else if (s[node] == '1')     v[node] += rc;

    int upnode = N - (x/2); 

    if ((x / 2) >= 1)  update(upnode);
}


void solve()
{
    cin >> K ;
    N = (1 << K) - 1 ;
    cin >> s ;

    v = vector<int>(N,-1) ;

    for(int i = 0 ; i < N ; i++) v[i] = 0 ;
    for(int i = 0 ; i < N ; i++) update(i) ;

    int q ; cin >> q ;
    while(q--)
    {
        int node ; cin >> node ;
        char val ; cin >> val ;
        s[--node] = val ;
        update(node) ;
        cout << v[N-1] << nl ;
    }

}
signed main(){   FAST   solve() ;  }



