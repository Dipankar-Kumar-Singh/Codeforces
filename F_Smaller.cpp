#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
int test = 0 ;

void MERGE_MAPS(map<char,int> &m , map<char,int> &mx , int k)
{
    for(auto c = 'a' ; c <= 'z' ; c++) 
    {
        m[c] += (k * mx[c]);
    }
}

int getSize(map<char, int> &m)
{
    int sz = 0;
    for (auto c = 'a'; c <= 'z'; c++)
        sz += m[c];
    return sz;
}

char largestElement(map<char, int> &m)
{
    for (char c = 'z'; c >= 'a'; c--)
        if (m[c] != 0)
            return c;

    return 'a' ;
}

void solve()
{
    string s = "a" ; string t = "a" ;

    map<char,int> ms , mt ;
    ms['a']++ ; mt['a']++ ;

    int q;
    cin >> q;
    while (q--)
    {
        int d;        cin >> d;
        int k;        cin >> k;
        string x;     cin >> x;
        map<char, int> mx;

        for (auto c : x)
        {
            mx[c]++;
        }

        if (d == 1)
        {
            MERGE_MAPS(ms, mx, k);
        }

        else if (d == 2)
        {
            MERGE_MAPS(mt, mx, k);
        }

        bool possible = 0;

        char smallestS = 'a' ;
        char biggestT = 'a' ;

        for (char c = 'z'; c >= 'a'; c--)
        {
            if (mt[c] != 0)
            {
                biggestT = c ; 
                break;
            }
        }

        if(smallestS < biggestT)
        {
            cout << "YES" << nl ;
            continue;
        }
        else 
        {
            if(getSize(ms) < getSize(mt))
            {
                if (largestElement(ms) == 'a')   possible = 1 ;
                else   possible = 0;
            }

            else if(getSize(ms) == getSize(mt))
            {
                possible = 0 ;
            }

            else if(getSize(ms) > getSize(mt))
            {
                possible = 0;
            }

            if (possible)
                cout << "YES" << nl;
            else
                cout << "NO" << nl;
        }
    }
}

signed main(){  FAST    TestCases    solve() ; }