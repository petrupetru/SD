#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream in("date.txt");

vector<long long> v;
vector<long long> c;
long long cnt[10000001];


unsigned long long llrand() {
    unsigned long long r = 0;

    for (long long i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return r & 0xFFFFFFFFFFFFFFFFULL;
}

void bubble_sort(vector<long long> &a){
    for(long long i=0; i<a.size();++i)
    {
        for(long long j=0; j<(a.size()-i-1);++j)
            if( a[j] > a[j+1])
            {
                swap(a[j],a[j+1]);
            }
    }
}

void count_sort(vector<long long> &a){
    vector<long long> e;
    long long maxim=0;
    for(long long i=0; i<a.size();++i)
    {
        cnt[a[i]]++;                              //construiesc vector de frecventa
        if(a[i]>maxim)                            //aflu maximul
            maxim=a[i];
    }


    for(long long i=0;i<=maxim;++i)
    {
        for(long long j=1;j<=cnt[i];++j)
        {
            e.push_back(i);                       //reconstruiesc vectorul intr-o copie
        }
    }
    a.clear();
    for(long long i=0;i<e.size();i++)             //trec inapoi in original
        a.push_back(e[i]);

}

void radix_sort_base1024(vector<long long> &a)
{
    vector<long long> b[1024],co;
    long long maxim=0, maxbit;
    for(long long i = 0; i < a.size(); i++)
    {
        if(a[i] > maxim)
            maxim = a[i];                                   //aflu maximul
    }
    maxbit = (log2(maxim)/10)+1;                            //numarul maxim de grupuri de 10 biti din care e format un nr
    for(long long i = 0; i < maxbit; i++)
    {
        for(long long j=0; j<a.size();j++)
        {
            long long y = (a[j] & (1023 << i*10)) >> i*10;    //al i-lea grup de 10 biti
            b[y].push_back(a[j]);                       //adaugare in bucket-uri
        }
        for(long long j = 0; j<1024 ;j++)
        {
            for(long long k=0; k<b[j].size();k++)
            {
                co.push_back(b[j][k]);                  //refac vectorul sortat LSD in copie
            }
        }
        a.clear();
        for(long long j = 0; j<co.size();j++)
        {
            a.push_back(co[j]);                         //mut in vector initial
        }
        co.clear();                                     //golesc copia
        for(long long j = 0; j<1024 ;j++)
        {
            b[j].clear();                               //golesc bucket-urile
        }
    }
}

void radix_sort_base16(vector<long long> &a)
{
    vector<long long> b[16],co;
    long long maxim=0, maxbit;
    for(long long i = 0; i < a.size(); i++)
    {
        if(a[i] > maxim)
            maxim = a[i];                                   //aflu maxim
    }
    maxbit = (log2(maxim)/4)+1;                            //numarul maxim de grupuri de 4 biti din care e format un nr
    for(long long i = 0; i < maxbit; i++)
    {
        for(long long j=0; j<a.size();j++)
        {
            long long y = (a[j] & (15 << i*4)) >> i*4;           //al i-lea grup de 4 biti
            b[y].push_back(a[j]);                       //adaugare in bucket-uri
        }
        for(long long j = 0; j<16 ;j++)
        {
            for(long long k=0; k<b[j].size();k++)
            {
                co.push_back(b[j][k]);                  //refac vectorul sortat LSD in copie
            }
        }
        a.clear();
        for(long long j = 0; j<co.size();j++)
        {
            a.push_back(co[j]);                         //mut in vector initial
        }
        co.clear();                                     //golesc copia
        for(long long j = 0; j<16 ;j++)
        {
            b[j].clear();                               //golesc bucket-urile
        }
    }
}


void merge_arr(vector<long long> &a, long long s,long long m, long long f)   //interclasare
{
    long long size1 = m-s+1;
    long long size2 = f-m;
    vector<long long> a1, a2;                       //2 vectori auxiliari care reprezinta cei 2 vectori de interclasat
    for(long long i = 0; i < size1; ++i)
        a1.push_back(a[s+i]);
    for(long long i = 0; i < size2; ++i)
        a2.push_back(a[m+1+i]);



    long long i1=0,i2=0,k=s;
    while(i1 < size1 && i2 < size2)                 //interclasare efectiva
    {
        if(a1[i1]<=a2[i2])
        {
            a[k] = a1[i1];
            i1++;
        }
        else
        {
            a[k] = a2[i2];
            i2++;
        }
        k++;
    }
    while(i1<size1)
    {
        a[k]=a1[i1];
        i1++;
        k++;
    }
    while(i2<size2)
    {
        a[k]=a2[i2];
        i2++;
        k++;
    }
}

void merge_sort(vector<long long> &a, long long s, long long f)
{
    if(s>=f)
        return;
    long long m = (s+f)/2;              //sparg in 2 jumatati pe care aplic merge sort recursiv pana la blocuri de un singur element
    merge_sort(a, s, m);
    merge_sort(a, m+1, f);
    merge_arr(a,s,m,f);                 //interclasez cei 2 vectori sortati
}

void quick_sort(vector<long long> &a, long long s, long long f)
{
    vector<long long> sm,bg,ev;
    if(s>=f)
        return;
    long long pv = llrand()%(f-s)+s;            //aleg pivot random
    for(long long i=s; i<f; i++)
    {
        if(a[i]<a[pv])                          //sm=smaller     ev=even    bg=bigger
        {
            sm.push_back(a[i]);
        }
        if(a[i] == a[pv])
        {
            ev.push_back(a[i]);
        }
        if(a[i]>a[pv])
        {
            bg.push_back(a[i]);
        }
    }

    for(long long i = 0; i<sm.size();i++)
    {
        a[s+i]=sm[i];
    }
    for(long long i = 0; i<ev.size();i++)
    {
        a[s+sm.size()+i]=ev[i];
    }
    for(long long i = 0; i<bg.size();i++)
    {
        a[s+sm.size()+ev.size()+i]=bg[i];                   //inlocuiesc in vector bucatile pe care s-a aplicat quick sort
    }

    quick_sort(a,s,s+sm.size());                            //aplic quick sort pe fiecare bucata ramasa
    quick_sort(a,s+sm.size()+ev.size(),f);

}

int main()
{

    long long t,n,m,o;
    in>>t;
    for(long long i = 1; i <= t; i++)                       //t teste
    {

        in>>n>>m;                                              //n numere cu valoare maxima m
        v.clear();
        c.clear();
        for(long long j=1;j<=n;j++)
        {
            in>>o;
            v.push_back(o);
        }
        using std::chrono::high_resolution_clock;
        using std::chrono::duration_cast;
        using std::chrono::duration;
        using std::chrono::milliseconds;
        cout<<"TEST "<<t<<'\n'<<"N = "<<n<<" MAX = "<<m<<'\n';
        if(n<=50000) // bubble sort
        {
            for(long long j=0;j<v.size();++j)
            {
                c.push_back(v[j]);
            }

            auto t1 = high_resolution_clock::now();
            bubble_sort(c);
            auto t2 = high_resolution_clock::now();
            duration<double, std::milli> ms_double = t2 - t1;
            cout<<"BUBBLE SORT TIME: "<<ms_double.count()<<"ms    ";
            if(is_sorted(c.begin(),c.end())==1)
                cout<<"SORTED\n";
            else
                cout<<"NOT SORTED\n";
            c.clear();
        }
        else
            cout<<"BUBBLE SORT TIME: -\n";

        if(m<=10000000) //count sort
        {
            for(long long j=0;j<v.size();++j)
            {
                c.push_back(v[j]);
            }

            auto t1 = high_resolution_clock::now();
            count_sort(c);
            auto t2 = high_resolution_clock::now();
            duration<double, std::milli> ms_double = t2 - t1;
            cout<<"COUNT SORT TIME: "<<ms_double.count()<<"ms    ";
            if(is_sorted(c.begin(),c.end())==1)
                cout<<"SORTED\n";
            else
                cout<<"NOT SORTED\n";
            c.clear();
        }
        else
            cout<<"COUNT SORT TIME: -\n";

        if(n<1000000000000) //radix sort 1024
        {
            for(long long j=0;j<v.size();++j)
            {
                c.push_back(v[j]);
            }

            auto t1 = high_resolution_clock::now();
            radix_sort_base1024(c);
            auto t2 = high_resolution_clock::now();
            duration<double, std::milli> ms_double = t2 - t1;
            /*for(long long i=0;i<c.size();i++)
                cout<<c[i]<<' ';
            cout<<' ';*/
            cout<<"RADIX SORT BASE 1024 TIME: "<<ms_double.count()<<"ms    ";
            if(is_sorted(c.begin(),c.end())==1)
                cout<<"SORTED\n";
            else
                cout<<"NOT SORTED\n";
            c.clear();
        }
        else
            cout<<"RADIX SORT BASE 1024 TIME: -\n";


        if(n<1000000000000) //radix sort 16
        {
            for(long long j=0;j<v.size();++j)
            {
                c.push_back(v[j]);
            }

            auto t1 = high_resolution_clock::now();
            radix_sort_base16(c);
            auto t2 = high_resolution_clock::now();
            duration<double, std::milli> ms_double = t2 - t1;
            cout<<"RADIX SORT BASE 16 TIME: "<<ms_double.count()<<"ms    ";
            if(is_sorted(c.begin(),c.end())==1)
                cout<<"SORTED\n";
            else
                cout<<"NOT SORTED\n";

            c.clear();
        }
        else
            cout<<"RADIX SORT BASE 16 TIME: -\n";


        if(n<10000000) //merge sort
        {
            for(long long j=0;j<v.size();++j)
            {
                c.push_back(v[j]);
            }

            auto t1 = high_resolution_clock::now();
            merge_sort(c, 0, c.size()-1);
            auto t2 = high_resolution_clock::now();
            duration<double, std::milli> ms_double = t2 - t1;
            cout<<"MERGE SORT TIME: "<<ms_double.count()<<"ms    ";
            if(is_sorted(c.begin(),c.end())==1)
                cout<<"SORTED\n";
            else
                cout<<"NOT SORTED\n";
            c.clear();
        }
        else
            cout<<"MERGE SORT TIME: -\n";

        if(n<10000000) //quick sort
        {
            for(long long j=0;j<v.size();++j)
            {
                c.push_back(v[j]);
            }
            srand((unsigned) time(0));  //random seed for true random selection
            auto t1 = high_resolution_clock::now();
            quick_sort(c, 0, c.size());
            auto t2 = high_resolution_clock::now();
            duration<double, std::milli> ms_double = t2 - t1;
            cout<<"QUICK SORT RANDOM TIME: "<<ms_double.count()<<"ms    ";
            if(is_sorted(c.begin(),c.end())==1)
                cout<<"SORTED\n";
            else
                cout<<"NOT SORTED\n";
            c.clear();
        }
        else
            cout<<"QUICK SORT RANDOM TIME: -\n";

        if(n<1000000000000) //quick sort
        {
            for(long long j=0;j<v.size();++j)
            {
                c.push_back(v[j]);
            }
            auto t1 = high_resolution_clock::now();
            sort(c.begin(),c.end());
            auto t2 = high_resolution_clock::now();
            duration<double, std::milli> ms_double = t2 - t1;
            cout<<"C++ NATIVE SORT RANDOM TIME: "<<ms_double.count()<<"ms    ";
            if(is_sorted(c.begin(),c.end())==1)
                cout<<"SORTED\n";
            else
                cout<<"NOT SORTED\n";

            c.clear();
        }
        else
            cout<<"C++ NATIVE SORT RANDOM TIME: -\n";
        cout<<'\n';
    }

}
