#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int n,m,i,s,d;
priority_queue<int> liber;
priority_queue<pair<int,int>> task;

int main() {
    ifstream in("proc2.in");
    ofstream out("proc2.out");
    in>>n>>m;
    for(i=1;i<=n;i++)
        liber.push(-i);
    for(i=0; i<m; i++)
    {
        in>>s>>d;
        /*if(!task.empty())
            cout<<(-task.top().first)<<' '<<s<<'\n';*/
        while(!task.empty() && -task.top().first < s)
        {
            liber.push(-1 *(task.top().second));
            task.pop();
        }
        out<<-liber.top()<<'\n';
        task.push(make_pair(-(s+d-1),-liber.top()));
        liber.pop();
    }
}
