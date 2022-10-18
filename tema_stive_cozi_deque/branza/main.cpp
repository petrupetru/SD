#include <iostream>
#include <fstream>
#include<deque>
using namespace std;
int n,s,t,i,c[100005],p;
long long rez;
deque<int>d;

int main() {
    ifstream in("branza.in");
    ofstream out("branza.out");
    in>>n>>s>>t;
    for(i=1;i<=n;i++)
    {
        in>>c[i]>>p;
        while(!d.empty() && c[i] < c[d.back()] + (i-d.back())*s)
            d.pop_back();
        while(!d.empty() && d.front() < i-t)
            d.pop_front();
        d.push_back(i);
        rez += (long long)((long long)p * (c[d.front()] + (long long)(i-d.front()) * s));
    }
    out<<rez;
}
