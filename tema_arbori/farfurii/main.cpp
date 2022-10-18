#include <iostream>
#include <fstream>

using namespace std;

int n,v[100005],i,idx;
long long k,inv;

int main() {
    ifstream in("farfurii.in");
    ofstream out("farfurii.out");
    in>>n>>k;
    for(i=1;i<=n;i++)
        v[i]=n-i+1;
    inv=(1LL*n*(n-1))/2-k;
    idx=n;
    while(inv)
    {
        if(idx-1<=inv)
        {
            out<<v[idx]<<' ';
            v[idx]=0;
            idx--;
            inv-=idx;
        }
        else
        {
            out<<v[inv+1]<<' ';
            v[inv+1]=0;
            inv=0;
        }
    }
    for(i=1;i<=n;++i)
    {
        if(v[i])
            out<<v[i]<<' ';
    }
}
