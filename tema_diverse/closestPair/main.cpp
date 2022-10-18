/* Burdusa Petru-Robert - 152
                  Tutore laborator
                  MingW w64 6.0  */

#include <iostream>
#include <vector>
using namespace std;

int closestPair(vector<int>& first, vector<int>& second) {
    int min = 1000000000;
    for(auto i:first)
    {
        for(auto j:second)
        {
            if(abs(i-j)<min)
                min=abs(i-j);
        }
    }
    return min;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
