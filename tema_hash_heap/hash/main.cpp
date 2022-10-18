#include <iostream>
#include <fstream>
#include <list>
using namespace std;
int i,j,n,c,nr,hindex;
list<int> h[1000000];

int main() {
    ifstream in("hashuri.in");
    ofstream out("hashuri.out");

    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>c>>nr;
        hindex = nr % 1000000;
        if(c==1)
        {
            int ok = 0;
            for(auto itr = h[hindex].begin(); itr != h[hindex].end(); itr++)
            {
                if(*itr == nr)
                    ok=1;
            }
            if(ok==0)
            {
                h[hindex].push_back(nr);
            }

        }
        if(c==2)
        {
            h[hindex].remove(nr);
        }
        if(c==3)
        {
            int ok = 0;
            for(auto itr = h[hindex].begin(); itr != h[hindex].end(); itr++)
            {
                if(*itr == nr)
                    ok=1;
            }
            if(ok==0)
            {
                out<<"0\n";
            }
            else
            {
                out<<"1\n";
            }
        }
    }
}
