#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  


int const INF  = 1e18 ;
int test = 0 ;

int const MOD = 1e9 + 7 ;
bool isprime(long long n){for(long long i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}
long long factorial(long long n){return (n==1 || n==0) ? 1:n*factorial(n-1);}
long long power_Mod(long long a, long long b){long long res=1;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b =b>>1;}return (res)%MOD;}
long long power(long long a, long long b){long long res=1;while(b>0){if(b&1){res=(res*a);}a=(a*a);b =b>>1;}return (res);}
bool ispow2(int i) { return i && (i & -i) == i; }
long long digitsum(long long n){long long ret=0;while(n){ret+=n%10;n/=10;}return ret;}
long long ceil(long long a, long long b) {    if (a == 0) return 0;    return (a - 1)/b + 1;}



void solve()
{
    int a , b  ; cin >> a >> b ;
    int x = power(a,b) ; 
    int y = power(b,a) ;

    if(x > y)
    {
        cout <<  "First" ; 
    }
    else if( x < y)
    {
        cout << "Second" ;
    }
    else 
    {
        cout << "Equal" ;
    }
}

signed main(){  FAST        solve() ; }