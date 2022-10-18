#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,d,x,y;
vector<pair<int,int>> v;

int main() {
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());

    int l=0, r=-1;
    long long maxim = 0,c=0,ok=0;
    while(ok==0){
        while(r<n-1 && abs(v[l].first - v[r+1].first) < d)
        {
            r++;
            c+=v[r].second;
        }
        maxim = max(maxim,c);
        if(r==n-1) ok=1;
        c-=v[l].second;
        l++;
    }
    cout<<maxim<<'\n';

}
