#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n" 

int const N = 1e5 + 1e3 ;

vector<int> segx(4*N) ;
vector<int> segy(4*N) ;

void updatex(int n , int s , int e , int id , int val)
{
    if(e==s)
    {
        segx[n] = (val) ;
        return ;
    }

    int mid = (s+e)/2 ;

    if(id<=mid)
    {
        updatex(2 * n + 1, s, mid, id, val);
    }

    else
    {
        updatex(2 * n + 2, mid + 1, e, id, val);
    }


    if(s!=e)
    {
        segx[n] = segx[2 * n + 1] + segx[2 * n + 2];
    }

}

int queryx(int n , int s ,int e , int l , int r)
{
    if(r<s or l>e)
    {
        return 0 ;
    }

    if (l <= s and r >= e)
    {
        return segx[n] ;
    }

    int mid  = (s+e)/2 ;

    int q1 = queryx(2 * n + 1, s, mid, l, r);
    int q2 = queryx(2 * n + 2, mid + 1, e, l, r);

    return (q1+q2) ;
}

void updatey(int n , int s , int e , int id , int val)
{
    if(e==s)
    {
        segy[n] = val ;
        return ;
    }

    int mid = (s+e)/2 ;

    if(id<=mid)
    {
        updatey(2 * n + 1, s, mid, id, val);
    }

    else
    {
        updatey(2 * n + 2, mid + 1, e, id, val);
    }


    if(s!=e)
    {
        segy[n] = segy[2 * n + 1] + segy[2 * n + 2];
    }

}

int queryy(int n , int s ,int e , int l , int r)
{
    if(r<s or l>e)
    {
        return 0 ;
    }

    if (l <= s and r >= e)
    {
        return segy[n] ;
    }

    int mid  = (s+e)/2 ;

    int q1 = queryy(2 * n + 1, s, mid, l, r);
    int q2 = queryy(2 * n + 2, mid + 1, e, l, r);

    return (q1+q2) ;
}

signed main()
{   FAST  

    int n , q ; 
    cin >> n >> q ;
    vector<int> a(n) , b(n) ; 

    while(q--)
    {
        int t ; cin >> t ; 
        if(t==1)
        {
            int x, y;
            cin >> x >> y;

            x-- , y-- ;

            a[x]++ ;
            b[y]++ ;

            updatex(0,0,n-1,x,1) ;
            updatey(0,0,n-1,y,1) ;
        }

        else if(t==2)
        {
            int x , y ; 
            cin >> x >> y ;

            x-- , y-- ;

            a[x]-- ;
            b[y]-- ;

            if(a[x]==0)
                updatex(0, 0, n - 1, x, 0);
            if (b[y] == 0)
                updatey(0, 0, n - 1, y, 0);

        }

        else if(t==3)
        {

            int x1 , y1 ; 
            cin >> x1 >> y1 ;

            int x2 , y2 ;
            cin >> x2 >> y2 ;

            x1-- , y1-- , x2-- , y2-- ;

            int qx = queryx(0, 0, n - 1, x1, x2);
            int qy = queryy(0, 0, n - 1, y1, y2);

            int lenx = x2 - x1;
            int leny = y2 - y1;

            if (((qx == lenx+1)) or ((qy == leny+1) ))
            {
                cout << "Yes" << nl;
            }

            else
            {
                cout << "No" << nl;
            }
        }
    }
}

