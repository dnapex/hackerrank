#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const* argv[])
{
    int a;
    long b;
    long long c;
    char d;
    float e;
    double f;
    cin >> a >> b >> c >> d >> e >> f;

    printf("%d\n%ld\n%lld\n%c\n%f\n%lf\n",
            a, b, c, d, e, f);
    return 0;
}
