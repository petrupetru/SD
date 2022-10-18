#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,m,k,a,b,i,j,smin;
priority_queue<int> pq;
vector<pair<int, int>> v;
int main() {
    ifstream in("timbre.in");
    ofstream out("timbre.out");
    in>>n>>m>>k;
    for(i=0;i<m;i++)
    {
        in>>a>>b;
        v.push_back(make_pair(a,b));
    }
    j = v.size() - 1;
    sort(v.begin(),v.end());
    while(n>0)
    {
        while(j>=0 && v[j].first >= n)
        {

                //cout<<v[j].first<<' '<<v[j].second<<'\n';
                pq.push(-v[j].second);

            j--;
        }
        smin += -pq.top();
        pq.pop();
        n = n-k;
    }
    out<<smin;

}
