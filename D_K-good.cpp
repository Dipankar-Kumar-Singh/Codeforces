#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

pair<int,int> findRoots(int a, int b, int c)
{	
	int d = b * b - 4 * a * c;
	double sqrt_val = sqrt(abs(d));

	if (d > 0) {
        int r1 = (double)(-b + sqrt_val) / (2 * a)  ;
        int r2 =(double)(-b - sqrt_val) / (2 * a) ;
        return {r1,r2} ;
	}
	else if (d == 0) {
        int root1 = -(double)b / (2 * a) ;
		return {root1,-1} ;
	}
	else 
	{
        return {-1,-1} ;
		// cout << "Roots are complex \n";
		// cout << -(double)b / (2 * a) << " + i" << sqrt_val
		// 	<< "\n"
		// 	<< -(double)b / (2 * a) << " - i" << sqrt_val;
	}
}



bool check(int r1 , int n)
{
    
    int eq = r1*r1 - r1 - 2*n ;
    return (eq==0) ;

}


void solve()
{
   
    int n ; cin >> n ;

    int a = 1 , b = -1 , c = -(2*n) ;

	auto [r1,r2] = findRoots(a, b, c);

    if(r1<2 and r2<2) 
    {
        cout << -1 ; return ;
    }

    else 
    {
        if(check(r1,n)==0 and check(r1,n)==0)
        {
            cout << -1 << "\n" ;
        } 

        else if(check(r1,n))
        {
           cout << r1 << "\n" ;
           return ;
        }

        else 
        {
            cout << r2 << "\n" ;
            return ;
        }
    }

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

