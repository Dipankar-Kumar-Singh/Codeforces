#include <bits/stdc++.h>
using namespace std;

/*

    ▓█████▄     ██▓    ██▓███      ▄▄▄          ███▄    █     ██ ▄█▀    ▄▄▄          ██▀███     
    ▒██▀ ██▌   ▓██▒   ▓██░  ██▒   ▒████▄        ██ ▀█   █     ██▄█▒    ▒████▄       ▓██ ▒ ██▒   
    ░██   █▌   ▒██▒   ▓██░ ██▓▒   ▒██  ▀█▄     ▓██  ▀█ ██▒   ▓███▄░    ▒██  ▀█▄     ▓██ ░▄█ ▒   
    ░▓█▄   ▌   ░██░   ▒██▄█▓▒ ▒   ░██▄▄▄▄██    ▓██▒  ▐▌██▒   ▓██ █▄    ░██▄▄▄▄██    ▒██▀▀█▄     
    ░▒████▓    ░██░   ▒██▒ ░  ░    ▓█   ▓██▒   ▒██░   ▓██░   ▒██▒ █▄    ▓█   ▓██▒   ░██▓ ▒██▒   
    ▒▒▓  ▒    ░▓     ▒▓▒░ ░  ░    ▒▒   ▓▒█░   ░ ▒░   ▒ ▒    ▒ ▒▒ ▓▒    ▒▒   ▓▒█░   ░ ▒▓ ░▒▓░   
    ░ ▒  ▒     ▒ ░   ░▒ ░          ▒   ▒▒ ░   ░ ░░   ░ ▒░   ░ ░▒ ▒░     ▒   ▒▒ ░     ░▒ ░ ▒░   
    ░ ░  ░     ▒ ░   ░░            ░   ▒         ░   ░ ░    ░ ░░ ░      ░   ▒        ░░   ░    
    ░        ░                       ░  ░            ░    ░  ░            ░  ░      ░        
 ░    

*/                                                                                      



// #define int long long
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = numeric_limits<long long>::max();
#define F first      
#define S second     
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

bool isPal(vector<int> &v)
{
    int i = 0 ; int j = v.size()-1 ; 
    while (i <= j )
    {
        if(v[i]!=v[j]) {  return false ;}
        i++ ; j--; 
    }
    return true;
}

bool cond = true ;

bool remove_and_check(vector<int> org , int x){
    vector<int> nv ;
    for(auto &e:org){if(e!=x){nv.push_back(e) ;}}   
    return cond = isPal(nv) ;
}

void ans(bool c){  cout << ( c ? "YES\n" : "NO\n") ;   }

signed main()
{
    FAST 
    t_case
    {
        cond = true ;

        int n ; cin >> n ;  
        map<int,int> m ;

        vector<int> v(n,0) ; for(auto &i:v) {cin >> i ; m[i]++ ;}

        if(isPal(v)==true or m.size()<=2) { cout << "YES\n" ; continue ;}

        else if(m.size()==v.size()){ cout << "NO\n" ; continue ;}

        
        int e1 = 0 , e2 = 0 ; 

       
        for(int i = 0 ;  i < n ; i++)
        {
            if(v[i] != v[ n - i - 1 ])
            {   
                cond = false ; 
                e1 = v[i] ; 
                e2 = v[ n - i - 1 ] ;  
                break ;
            }
        }

        if(cond == true) ans(cond) ;
        else 
        {
            cond = remove_and_check(v,e1) or remove_and_check(v,e2)  ;
            ans(cond) ;
        }                       
    }
}

