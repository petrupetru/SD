#include <iostream>
#include<fstream>
#include<set>
using namespace std;
int n,i,c,x,j,t,v[200002],poz;
set<int> heap;
int main() {
    ifstream in("heapuri.in");
    ofstream out("heapuri.out");
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>c;
        if(c==1)
        {
            in>>x;
            heap.insert(x);
            v[++poz] = x;
        }
        if(c==2)
        {
            in>>x;
            heap.erase(v[x]);

        }
        if(c==3)
        {
            out<<*heap.begin()<<'\n';
        }
    }
}
