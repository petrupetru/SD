#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
ifstream in("sea.in");
ofstream out("sea.out");
struct p
{
    double x,y,d;
};
bool cmp (p a, p b)
{
    return a.x < b.x;
}
int n, m, fn;
double fx, vx, vy;
vector<p> v;
int main() {
    in>>n>>m;
    for (int c = 0; c < n; c++) {
        in >> vx >> vy;
        v.push_back({vx, vy, 0});
    }
    sort(v.begin(), v.end(), cmp);
    for (int c = 0; c < m; c++) {
        in >> fx >> fn;
        int j;
        for (j = 0; j < n && v[j].x < fx; j++) {
            v[j].d = (v[j].x - fx) * (v[j].x - fx) + v[j].y * v[j].y;
        }
        int ok = 1;
        while (ok) {
            ok = 0;
            for (int e = 0; e < j - 1; e++) {
                if (v[e].d > v[e + 1].d) {
                    ok = 1;
                    swap(v[e], v[e + 1]);
                }
            }
        }
        out << fixed << setprecision(4) << sqrt(v[fn - 1].d) << "\n";
    }
    return 0;
}