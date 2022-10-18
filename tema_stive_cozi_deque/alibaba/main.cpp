#include <iostream>
#include <fstream>
#include<deque>
#include<string>

using namespace std;
int n,k,i;
string num;
deque<char> d;
int main() {
    ifstream in("alibaba.in");
    ofstream out("alibaba.out");
    in>>n>>k;
    in>>num;
    for(i=0;i<num.size();i++)
    {
        while(!d.empty() && k>0 && d.back() < num[i])
        {
            k--;
            d.pop_back();
        }
        d.push_back(num[i]);
    }
    while(k>0)
    {
        k--;
        d.pop_back();
    }
    for(i=0;i<d.size();i++)
        out<<d[i];
}
