#include <iostream>
#include <fstream>
using namespace std;

ifstream in("rmq.in");
ofstream out("rmq.out");

int arbint[400005];
int v;
int n, q, x, y;

void Update( int nod, int st, int dr, int pos, int val )
{
    if( st == dr )
    {
        arbint[nod] = val;
        return;
    }
    int mid = st + ( dr - st )/2;
    if(pos <= mid) Update( nod * 2, st, mid, pos, val );
    else Update( nod * 2 + 1, mid + 1, dr, pos, val );
    arbint[nod] = max( arbint[nod*2], arbint[nod*2+1] );
}

int Query( int nod, int st, int dr, int L, int R )
{
    if( L <= st && dr <= R )
        return arbint[nod];
    int mid = st + ( dr - st )/2;
    int ans1,ans2;
    ans1 = ans2 = -100005;
    if( L <= mid ) ans1 = Query( nod*2, st, mid, L, R );
    if( mid < R ) ans2 = Query( nod*2+1, mid+1, dr, L, R);
    return max(ans1, ans2 );
}

int main()
{
    in>>n>>q;
    for( int i=1;i<=n;++i)
    {
        in >> v;
        Update( 1, 1, n, i, -v );
    }
    for( int i=1;i<=q;++i)
    {
        in>> x >> y;
        out << -1*Query( 1, 1, n, x, y ) << '\n';

    }
}