#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

priority_queue<int> heap;

int lastStoneWeight(vector<int>& stones) {
        for(int i = 0; i<stones.size(); i++)
        {
            heap.push(stones[i]);
        }
        while(heap.size()>1)
        {
            int a = heap.top();
            heap.pop();
            int b = heap.top();
            heap.pop();
            if(a!=b)
            {
                a=abs(a-b);
                heap.push(a);
            }

        }
        cout<<heap.size();
        if(heap.size()>0)
        return heap.top();
        else
            return 0;
    }
int main()
{
    vector<int> a;
    a.push_back(2);
    a.push_back(2);
    cout<<lastStoneWeight(a);
}
