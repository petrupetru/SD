#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

struct trei{
    int x,y,z;
};

int n,s,v[105],i,j,k;
unordered_map<int, trei> h;
bool ok;

int main() {
    ifstream in("loto.in");
    ofstream out("loto.out");

    in>>n>>s;
    for(i=1;i<=n;i++)
        in>>v[i];
    for (i = 1; i <= n; i++)
        for (j = i; j <= n; j++)
            for (k = j; k <= n; k++)
                h[v[i]+v[j]+v[k]] = {v[i],v[j],v[k]};


    ok=0;
    for(auto it : h)
    {
        if(h.find(s - it.first) != h.end())
        {
            out<<it.second.x<<' '<<it.second.y<<' '<<it.second.z<<' '
            <<h[s - it.first].x<<' '<<h[s - it.first].y<<' '<<h[s - it.first].z<<'\n';
            ok=1;
            break;
        }


    }
    if(ok==0)
        out<<-1;
}
