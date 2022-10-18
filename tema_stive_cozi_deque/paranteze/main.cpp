#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int n,i,cl=0,clmax=0;
char c;
stack<char> stiva;

int main() {
    ifstream in("paranteze.in");
    ofstream out("paranteze.out");
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>c;
        cout<<c;
        if(c=='(' || c=='[' || c=='{')
        {
            stiva.push(c);
        }
        else
        {
            if((stiva.top()=='(' && c==')') ||
            (stiva.top()=='(' && c==')') ||
            (stiva.top()=='(' && c==')'))
            {
                cout<<stiva.top()<<c<<'\n';
                cl+=2;
                stiva.pop();
            }
            else
            {
                cout<<cl<<" ";
                if(cl>clmax)
                    clmax=cl;
                cl=0;
                while(!stiva.empty())
                    stiva.pop();
            }
        }
    }
    cout<<clmax;
}
