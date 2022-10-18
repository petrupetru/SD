#include <iostream>
#include <fstream>
#include <cmath>
#include <set>

using namespace std;
int n,nr;
double x,y;
set<pair<int,int>> puncte;
pair<int,int> crd[1005];
int main() {
    ifstream in("patrate3.in");
    ofstream out("patrate3.out");
    in>>n;
    for (int i = 0; i < n; ++i) {
        in>>x>>y;
        crd[i].first=round(x*10000);
        crd[i].second=round(y*10000);
        puncte.insert(crd[i]);

    }
    int x3, y3, x4, y4;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i!=j)
            {
                x3 = crd[i].second - crd[j].second + crd[j].first;
                y3 = crd[j].first - crd[i].first + crd[j].second;

                x4 = crd[i].second - crd[j].second + crd[i].first;
                y4 = crd[j].first - crd[i].first + crd[i].second;
                //cout<<x3<<' '<<y3<<'\n'<<x4<<' '<<y4<<"\n\n";

                if (puncte.find({ x3,y3 }) != puncte.end() && puncte.find({ x4,y4 }) != puncte.end())
                    nr++;
            }
        }
    }
    /*for(auto t:puncte)
        cout<<t.first<<' '<<t.second<<'\n';*/
    out<<nr/4;
}
