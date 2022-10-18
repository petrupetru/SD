#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <chrono>
using namespace std;
ifstream in("q.in");
ofstream out("date.txt");

unsigned long long llrand() {    //generator random long long
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return r & 0xFFFFFFFFFFFFFFFFULL;
}

void generate_random(long long a, long long b){   //generator a numere mai mici decat b
    for (long long i = 1; i <= a; i++) {
        out<<(llrand()%b)<<' ';
    }

}

int main()
{
    srand((unsigned) time(0));
    long long t,n,m;
    in>>t;
    out<<t<<'\n';
    for(int i=1;i<=t;i++)
    {
        in>>n>>m;
        out<<n<<' '<<m<<'\n';
        generate_random(n,m);
        out<<'\n';
    }
}
