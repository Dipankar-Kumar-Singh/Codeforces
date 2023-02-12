#include <bits/stdc++.h>
using namespace std;
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

vector<string> v ;
int n , m ;

void pt() ;
void nullify_colum(int till)
{

    int k = till ;
    // for(int k = 0 ; k <= min(till,m-1) ; k++)
    // ERROR because of int k for loop .... 
    
    for(int i = 0 ; i < n ; i++)
    {
        v[i][k] = 'a' ;
    }


    // NOTE 
    
    // we don't need to nullify all colums till k ,
    // becuse maybe a a a b b c  c 
    //              b a a a b a  c

    //              1 2 3 4 5 6  7

    //              | if first B was cleaned ... becuse of 4th Index ...
    //              so latter ... at 6 ... that first B was making second string bigger
    //              will be gone thus .... wrong answer 
    


    // pt() ;

}

void pt()
{
    for(auto x : v) cerr << x << "\n" ;
                cerr << "\n" ;
}


bool all_good()
{

  for(int i = 0 ; i < n -1 ; i++)
  {
      if (v[i]>v[i+1]) return false ;
  }

  return true ;

}


signed main()
{
    
    FAST 
    cin >> n >> m ;
    v.resize(n) ;
    for(auto &t:v) cin >> t ;

    int r{} ;

   
    
    while (!all_good())
    {
        pt() ;
    
        bool fd =  0 ;
        for(int i = 1 ; i < n ; i++)
        {

            if(v[i-1]>v[i])
            {
                int loc = 0 ;
                r++ ;
        
                for(int j = 0 ; j < m ; j++)
                {
                    if(v[i-1][j] > v[i][j]) 
                    {
                        loc = j ; 
                        break ;
                    }
                }

                nullify_colum(loc) ; 
                break ;
            } 
            
        }

    }

    

    cout << r ;
  
}

