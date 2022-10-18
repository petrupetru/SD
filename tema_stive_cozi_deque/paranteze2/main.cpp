#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int n,i,l,lmax;
char c;
stack<char> stiva;
stack<int> poz;
bool corecte[1000005];



int main() {
    ifstream in("paranteze.in");
    ofstream out("paranteze.out");
    in>>n;
    for(i=0;i<n;i++)
    {
        in>>c;
        if(c=='(' || c=='[' || c=='{')
        {
            stiva.push(c);
            poz.push(i);
        }
        else
        {
            if(!stiva.empty() && ((c==')' && stiva.top()=='(') ||
                    (c==']' && stiva.top()=='[') ||
                    (c=='}' && stiva.top()=='{')))
            {
                corecte[poz.top()]=1;
                corecte[i]=1;
                stiva.pop();
                poz.pop();
            }
            else
            {
                while(!stiva.empty())
                {
                    stiva.pop();
                    poz.pop();
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(corecte[i]==1)
        {
            l++;
            if(l>lmax)
                lmax=l;
        }
        else
        {
            l=0;
        }
    }
    out<<lmax;


}
