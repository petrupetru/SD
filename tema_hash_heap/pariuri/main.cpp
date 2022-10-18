#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;
int n,m,i,j,timp,bani,s;
unordered_map<int,int> h;
int main() {
    ifstream in("pariuri.in");
    ofstream out("pariuri.out");
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>m;
        for(j=1;j<=m;j++)
        {
            in>>timp>>bani;
            h[timp]+=bani;
        }
    }
    for(auto i:h)
        s++;
    out<<s<<'\n';
    for(auto i:h)
        out<<i.first<<' '<<i.second<<' ';
}
