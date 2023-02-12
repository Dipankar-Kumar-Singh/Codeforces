#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

bool isMoreImposeter(bool x)
{
    return !x ;
}

int n {};

int get_response(int i , int j , int k)
{   
    i = i % n , j = j % n , k = k % n ;
    cout <<  "? " << ++i << ' ' << ++j << ' ' << ++k << endl ; 
    int rr ; cin >> rr ;
    return rr ;
}

signed main()
{
    FAST 
    t_case
    {
        n= 0  ; 
        cin >> n; 
        vector<int> A(n) ;

        for(int i = 0 ; i < n ; i++)
        {   
            A[i] = get_response(i,i+1,i+2) ; 
        }

        vector<int> m(n,-1) ;

        int IMP  = -1 ;
        int CRW = -1 ;

        for(int i = 1 ; i <= n; i++)
        {   
            if (    A[i-1]   !=  A[i % n]   )
            {
                int  a = A[i%n] , b = A[i-1] ;
                if(a== 0 and b == 1)
                {   
                    m[i-1] = 2 ; 
                    CRW = i-1 ;
                } 

                else if(a==1 and b == 0 )
                { 
                    m[i-1] = 1 ;
                    IMP  = i-1 ;
                }
            }

            else m[i-1] = -1 ;
        }


        int aa = IMP , 
            bb = CRW ;

        for(int i  = 0 ; i < n ; i++)
        {
            if(m[i]>=0) continue ;
            
            int res  =  get_response(     aa   ,  bb ,    i    ) ;
            if(res == 0 ){ m[i] =  1 ;}
            else if(res == 1 ) { m[i] = 2  ;}

        }

        set<int> s ;

        for(int i = 0 ; i < n ;i++)
        {
            if(m[i]==1) s.insert(i) ;
        }

        cout << "! " ;
        cout <<  s.size() << " " ;
        for(int i : s)  cout << ++i << " " ;
        cout << endl ;              
                                       
    }
}

