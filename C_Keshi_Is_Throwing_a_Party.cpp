#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = numeric_limits<long long>::max();
#define F first      
#define S second     
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


class Person 
{   
    public :
    int rich = 0;   // RICH Tolerance 
    int poor = 0;   // POOR Tolerance 
};



bool isPossible(vector<Person> v , int t)
{
    int before = 0 ;
    int tt = t ;

    for(int i = 0 ; i < v.size() ; i++ ){

        int after = t - 1 ;
        int rich_tolerence = v[i].rich ;
        int poor_tol = v[i].poor ;

        if(after > rich_tolerence) continue ;
        else if(before > poor_tol ) continue ;

        before++ ; t-- ;
    } 

    return (t<=0 ) ;

}

signed main()
{
    FAST 
    t_case
    {

        int n ; cin >> n ; 
        vector<Person> v(n) ; 
        for(auto &[rich,poor]:v){ cin >> rich >> poor ;}

        // for(auto &P:v){ cout  << P.rich << " " << P.poor << "\n";}

        int l = -1 , r = n+1 ;
        while (  r - l > 1)
        {
            int mid = (l+r)/2 ;

            if(isPossible(v,mid)){l= mid ; }
            else{ r = mid ;}

        }

        cout << l  << "\n";
                                                          
    }
}

