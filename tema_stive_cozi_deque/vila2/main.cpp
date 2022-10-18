#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

int difmax,i,n,k,cn;
deque<pair<int,int>> dmin, dmax;   //first = val, second = pozitia

int main() {
    ifstream in("vila2.in");
    ofstream out("vila2.out");
    in>>n>>k;
    for(i=0;i<n;i++)
    {
        in>>cn;
        while(!dmin.empty() && dmin.back().first > cn)
            dmin.pop_back();
        dmin.push_back(make_pair(cn,i));
        while(!dmin.empty() && dmin.front().second < i-k)
            dmin.pop_front();


        while(!dmax.empty() && dmax.back().first < cn)
            dmax.pop_back();
        dmax.push_back((make_pair(cn,i)));
        while(!dmin.empty() && dmax.front().second < i-k)
            dmax.pop_front();

        //cout<<dmax.front().first<<"   "<<dmin.front().first<<'\n';
        if(dmax.front().first - dmin.front().first > difmax)
        {
            difmax = dmax.front().first - dmin.front().first;
        }
    }
    out<<difmax;
}
