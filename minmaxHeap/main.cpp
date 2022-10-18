#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
//plec cu index de la 1
using namespace std;

void pushDownMin(vector<int> &h, int index){
    if(h.size() > 2*index) //daca nodul index are copii
    {
        //verific toti copiii si nepotii si-l aleg pe cel mai mic
        int desc[6] = {2*index , 2*index+1, 4*index, 4*index+1, 4*index+2, 4*index+3};
        int minDesc = 1000000001,minI,minIndex;

        for(int i = 0; i<6; i++)
        {
            if(desc[i] < h.size() && h[desc[i]]<minDesc)
            {
                minDesc = h[desc[i]];
                minI = i;
                minIndex = desc[i];
            }
        }
        if(minI >= 2) //nepot
        {
            if(h[minIndex] < h[index])
            {
                swap(h[minIndex], h[index]);
                if(h[minIndex] > h[minIndex/2]) //verific cu parintele
                {
                    swap(h[minIndex], h[minIndex/2]);
                }
                pushDownMin(h,minIndex);
            }
        }
        else //parinte
        {
            if(h[minIndex] < h[index])
            {
                swap(h[minIndex],h[index]);
            }
        }
    }
}


void pushDownMax(vector<int> &h, int index){
    if(h.size() > 2*index) //daca nodul index are copii
    {
        //verific toti copiii si nepotii si-l aleg pe cel mai mare
        int desc[6] = {2*index , 2*index+1, 4*index, 4*index+1, 4*index+2, 4*index+3};
        int maxDesc = -1,maxI,maxIndex;

        for(int i = 0; i<6; i++)
        {
            if(desc[i] < h.size() && h[desc[i]]>maxDesc)
            {
                maxDesc = h[desc[i]];
                maxI = i;
                maxIndex = desc[i];
            }
        }
        if(maxI >= 2) //nepot
        {
            if(h[maxIndex] > h[index])
            {
                swap(h[maxIndex], h[index]);
                if(h[maxIndex] < h[maxIndex/2]) //verific cu parintele
                {
                    swap(h[maxIndex], h[maxIndex/2]);
                }
                pushDownMax(h,maxIndex);
            }
        }
        else //parinte
        {
            if(h[maxIndex] > h[index])
            {
                swap(h[maxIndex],h[index]);
            }
        }
    }
}

void pushDown(vector<int> &h, int index)
{
    int level = log2(index);
    if(level%2 == 0)   //nivel de minim
    {
        pushDownMin(h,index);
    }
    else               //nivel de maxim
    {
        pushDownMax(h,index);
    }
}

void pushUpMin(vector<int> &h, int index)
{
    if(log2(index)>=2 && h[index] < h[index/4])
    {
        swap(h[index], h[index/4]);
        pushUpMin(h,index/4);
    }
}
void pushUpMax(vector<int> &h, int index)
{
    if(log2(index)>=2 && h[index] > h[index/4])
    {
        swap(h[index], h[index/4]);
        pushUpMax(h,index/4);
    }
}
void pushUp(vector<int> &h, int index)
{
    if(index>1)
    {
        int level = log2(index);
        if(level%2==0) //nivel de minim
        {
            if(h[index] > h[index/2]) //mai mare decat parintele
            {
                swap(h[index],h[index/2]);
                pushUpMax(h,index/2);
            }
            else
            {
                pushUpMin(h,index);
            }
        }
        else           //nivel de maxim
        {
            if(h[index] < h[index/2]) //mai mic decat parintele
            {
                swap(h[index], h[index/2]);
                pushUpMin(h,index/2);
            }
            else
            {
                pushUpMax(h,index);
            }
        }
    }
}


void build(vector<int> &h)
{
    for(int i=(h.size()-1)/2; i>0; i--)
        pushDown(h,i);
}


int main() {
    int n;
    vector<int> heap;
    ifstream in("date.in");
    ofstream out("date.out");
    in>>n;
    for(int i=0;i<100000;i++)
    {
        int c;
        in>>c;
        if(c==1)
        {
            //insert
            int e;
            in>>e;
            heap.push_back(e);
            pushUp(heap,heap.size()-1);
            /*for(auto k:heap)
                cout<<k<<' ';
            cout<<'\n';*/
        }
        if(c==2)
        {
            //delete min
            heap[1] = heap[heap.size()-1];
            heap.pop_back();
            pushDown(heap,1);
            /*for(auto k:heap)
                cout<<k<<' ';
            cout<<'\n';*/
        }
        if(c==3)
        {
            //delele max
            int indexMax;
            if(heap[2] > heap[3])
                indexMax=2;
            else
                indexMax=3;
            heap[indexMax] = heap[heap.size()-1];
            heap.pop_back();
            pushDown(heap,indexMax);
            /*for(auto k:heap)
                cout<<k<<' ';
            cout<<'\n';*/
        }
        if(c==4)
        {
            //print min
            cout<<"min: "<<heap[1]<<'\n';
        }
        if(c==5)
        {
            //print max
            cout<<"max: "<<max(heap[2],heap[3])<<'\n';
        }
        if(c==6)
        {
            //build
            heap.clear();
            heap.push_back(0);
            int m;
            in>>m;
            for(int j=0;j<m;j++)
            {
                int e;
                in>>e;
                heap.push_back(e);
            }
            build(heap);
            /*for(auto k:heap)
                cout<<k<<' ';
            cout<<'\n';*/
        }
    }
}
