#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;


int const MOD = 1e9 + 7 ;
bool isprime(long long n){for(long long i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}
long long factorial(long long n){return (n==1 || n==0) ? 1:n*factorial(n-1);}
long long power_Mod(long long a, long long b){long long res=1;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b =b>>1;}return (res)%MOD;}
bool ispow2(int i) { return i && (i & -i) == i; }
long long digitsum(long long n){long long ret=0;while(n){ret+=n%10;n/=10;}return ret;}
long long ceil(long long a, long long b) {    if (a == 0) return 0;    return (a - 1)/b + 1;}


void print(vector<int> &v , int n ) 
{
    for(int i = 1 ; i <= n ;  i++)   cout << v[i] << " " ;
    cout << nl ;
    

}

void solve()
{
   int n;   cin >> n;
   vector<int> v(n+1);  
   iota(all(v),0) ;

    if((n%2)==0)
    {
        cout << n << nl ;
        print(v,n) ;

        int pivot = n ; 
    
        for(int i = 1 ; i <= n; i++)
        {
            if(i==pivot) continue;
            swap(v[i],v[pivot]) ;
            print(v,n) ;
        }
        
    }

    else 
    {
        cout << n <<  nl ;
        print(v,n) ;

        int pivot = n ; 
    
        for(int i = 1 ; i <= n; i++)
        {
            if(i==pivot) continue;
            swap(v[i],v[pivot]) ;
            print(v,n) ;
        }

    }

}
signed main(){   FAST      TestCases      solve() ;  }



