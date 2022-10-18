#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string x, string y){
    return x+y>y+x;
}

string largConcat(vector<string> &v){
    sort(v.begin(),v.end(),cmp);
    string r="";
    for(auto s:v)
    {
        r+=s;
    }
    if(r.front()=='0') return "0";
    return r;
}

int n;
vector<string> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    cout << largConcat(v) << '\n';
}
