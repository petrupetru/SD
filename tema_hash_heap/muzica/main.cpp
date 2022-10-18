#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;
long long n,m,i,a,b,c,d,e,s,nr,r;
unordered_set<long long> q(100001);
int main() {
    ifstream in("muzica.in");
    ofstream out("muzica.out");
    in>>n>>m>>a>>b>>c>>d>>e;
    for(i=1;i<=n;i++)
    {
        in>>s;
        q.insert(s);
    }

    for(i=0;i<m;i++)
    {
        if(q.count(a))
        {
            q.erase(a);
            nr++;
        }
        r=b;
        b=(c*r+d*a)%e;
        a=r;
    }
    out<<nr;
}
