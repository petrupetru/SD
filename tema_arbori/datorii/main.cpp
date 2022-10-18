#include <iostream>
#include <fstream>
using namespace std;

ifstream in("datorii.in");
ofstream out("datorii.out");

int arbint[400005];
int v;
int n, q, op, x, y;

void Update( int nod, int st, int dr, int pos, int val )
{
    /*cout<<"update\n";*/
    if( st == dr )
    {
        arbint[nod] += val;
        return;
    }
    int mid = (st+dr)/2;
    if(pos <= mid) Update( nod * 2, st, mid, pos, val );
    else Update( nod * 2 + 1, mid + 1, dr, pos, val );
    arbint[nod] =  arbint[nod*2] + arbint[nod*2+1];
}

int Query(int nod, int st, int dr, int l, int r)
{
    /*cout<<"query\n";*/
    if(l <= st && dr <= r) return arbint[nod];
    int mid = (st + dr) / 2;
    int ans1=0, ans2=0;
    if(l <= mid) ans1 = Query(nod * 2, st, mid, l, r);
    if(r > mid) ans2 = Query(nod * 2 + 1, mid + 1, dr, l, r);
    return ans1 + ans2;
}

int main()
{
    in>>n>>q;
    cout<<n<<' '<<q<<' ';
    for( int i=1;i<=n;++i)
    {
        in >> v;
        Update(1, 1, n, i, v);
    }
    for( int i=1;i<=q;++i)
    {
        in>>op>>x>>y;
        if(op==1)
            out<<Query(1, 1, n, x, y) << '\n';
        else
            Update(1, 1, n, x, -y);
    }
}