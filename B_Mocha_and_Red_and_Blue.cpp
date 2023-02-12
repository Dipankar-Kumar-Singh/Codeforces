#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ll long long 
 //            < -- L - O - O - P - S -- >
#define fl(a,b) for (ll i = a; i <= b; i++)

#define t_case   int t {} ; cin >> t ; while(t--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

signed main()
{
    FAST 
    t_case
    {
        int n ; cin >> n ;
        vector<char> v (n) ; fl(0,n-1) { cin >> v[i] ;} ;

        // filling last element of vector
        if(v.size()>1)
        {   
            if((v[n-2]=='?') and (v[n-1]=='?')) {v[n-1]='B';}
            else if ((v[n-2]=='R') and (v[n-1]=='?')) {v[n-1]='B';}
            else if ((v[n-2]=='B') and (v[n-1]=='?')) {v[n-1]='R';}
        }
        else if(v.size()==1 and (v[0]=='?'))   {v[0]='B' ;   cout << v[0] << endl ; continue ;}
        else if(v.size()==1 and (v[0]!='?')){ cout << v[0] << endl ; continue ;}   
        

        // if vec has more than 1 elemen
        //  In situation of a,b,c,d  .... d alredy filled if (d was empty ) ... 
        //  a,b,c,d ..... if d --> R , c --> opp of d i.e 'B' , 
        // and so on .... we fill opp till index = 0
        if(v.size()>1)
        {
            for(int i = n-2 ; i >= 0 ; i--)
            {   
                if(v[i]!='?'){ continue; }
                else if(v[i+1]=='R'){v[i]='B'; continue;}
                else if (v[i+1]=='B'){v[i]='R'; continue;}
                else if(v[i+1]=='?') {v[i]='B'; continue;}
            }
        }

        for(auto &x:v) { cout << x  ;} cout << endl;
        
    
           
        
    }
}

