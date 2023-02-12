#include <bits/stdc++.h>

// ETNA ATTITUDE TOH BANDI MAI BHI NAHI HOTA ....
// Accept kar le mera ....
// Dikkat toh bata 

using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

long long power(long long a, long long b){long long res=1;while(b>0){if(b&1){res=(res*a);}a=(a*a);b =b>>1;}return (res);}


vector<int> pw(20,1) ;

void solve()
{
    /* 
        R23C55    ==> good ;
        BC23     ==> bad ;
    */

    string data ; cin >> data ;

    // cout << "data =" << data << nl ;

    // cerr << data << nl; 

    if(data[0]=='R' and isdigit(data[1]))
    {
        // good ;   R23C55


        // cout << "data = " << data << "     " ;

        int rloc = 0 ; 
        int cloc = find(all(data),'C') - data.begin() ;

        // string rowstring = data.substr(rloc+1,(cloc-rloc-1)) ;
        // string colstring = data.substr(cloc + 1 , data.size() - cloc -1) ;

        string rowstring ,colstring ;
        for(int i = 1 ; i < data.size() ; i++)
        {
            if(data[i]=='C')
            {
                for(int j = i + 1 ; j < data.size() ; j++)
                {
                    colstring += data[j] ;
                }
                break;
            }

            rowstring  += data[i] ; 
        }

        // for(int i = 0 ; i < rowstring.size() ; i++)  assert(isdigit(rowstring[i])) ;
        // for(int i = 0 ; i < colstring.size() ; i++)  assert(isdigit(colstring[i])) ;

        int colno = stoll(colstring) ;
        string compressedCol ;

        while(colno)
        {
            --colno ;
            
            int d = colno%26 ;

            assert(colno>=0) ;
            if(colno<0) break; else colno/=26 ;
   
            char x = ( d + 'A') ;

            assert(isalpha(x)) ;
            assert(isupper(x)) ;

            compressedCol.push_back((x)) ;
        }

        reverse(all(compressedCol)) ;
        cout << compressedCol << rowstring << nl ;
    }

    else 
    {
        // bad ;    BC23 ;

        int temp = 0 ;
        while(!isdigit(data[temp]))  temp++ ;
        
        string coldata ; 
        string rowdata ;


        for(int i = 0 ; i < temp ; i++) coldata += data[i] ;
        for(int i = temp ; i < data.size() ; i++) rowdata += data[i] ;


        reverse(all(coldata)) ;



        // cerr << coldata << nl ;

        for(int i = 0 ; i < coldata.size() ; i++)
        {
            assert(isalpha(coldata[i])) ;
        }

        assert(coldata.size()<=6) ;

        // cerr << rowdata << nl ;
        
        int col = 0 ;
        for (int i = 0; i < coldata.size(); i++)
        {
            // col += (pw[i]*(coldata[i]-'A'+1)) ;
            col +=  power(26,i) * (coldata[i]-'A'+1) ;
            assert(col<1e7) ;
        }

        cout << "R" << rowdata  << "C" << col << nl ;
    }



}
signed main()
{
    FAST

    for (int i = 1; i <= 7 ; i++){ pw[i] = 26 * pw[i - 1];}
    TestCases      solve() ;  
}



