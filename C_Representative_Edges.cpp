#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


int get_dif(int i , int j , vector<int> v )
{
    vector<double> clean(v.size(),0) ;
    int ai = v[i] , aj = v[j] ;
    int pos_dif  = j - i ;
    int N = v.size() ;

    if(pos_dif==0)
    {
        int fr = count(all(v),ai) ;
        return (N - fr) ;
    }

    double val_dif = aj - ai ;

    double D =  val_dif / pos_dif ;

    int ct = 1 ;

    for(int k = i - 1 ; k >= 0 ; k--)
    {   
        clean[k] = v[i] - (double)(ct*D) ;  
        ct++ ;
    }

    ct =  1 ;

    for(int k = i + 1 ; k < v.size() ; k++)
    {
        clean[k] = v[i] + (double)ct*D ;
        ct++ ;
    }

    clean[i] = v[i] ; 

    int to_remove = 0 ;

    for(int k = 0 ; k < v.size() ; k++)
    {   
        double a = clean[k] , b = v[k] ;

        if( abs(a-b) > 0.00000001 )
        {
            to_remove++ ;
        }

    }

    return to_remove ;

}


signed main()
{
    FAST 
    t_case
    {
        
        int n ; cin >> n ;

        vector<int> v(n) ;
        for(int &x : v) cin >> x ;

        int ans  = INF  ;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i ; j < n ; j++)
            {
                int r =  get_dif(i , j , v) ;
                ans = min( r ,ans) ;
            }
        }

        cout << ans << "\n" ;                                                              
                                       
    }
}

