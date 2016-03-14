#include <iostream>

using namespace std;

int fourmax(int a, int b, int c, int d)
{
    int n[] = {a, b, c, d};
    int m = a;

    for (int i : n)
        m = (m > i) ? m : i;

    return m;
}


int main(int argc, char const* argv[])
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << fourmax(a, b, c, d) << endl;

    return 0;
}
