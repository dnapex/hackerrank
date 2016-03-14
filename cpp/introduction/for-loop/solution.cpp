#include <iostream>
#include <string>

using namespace std;

string ntw(int n)
{
    if (n == 1) {
        return "one";
    } else if (n == 2) {
        return "two";
    } else if (n == 3) {
        return "three";
    } else if (n == 4) {
        return "four";
    } else if (n == 5) {
        return "five";
    } else if (n == 6) {
        return "six";
    } else if (n == 7) {
        return "seven";
    } else if (n == 8) {
        return "eight";
    } else {
        return "nine";
    }
}

int main(int argc, char const* argv[])
{
    int s, e;
    cin >> s >> e;

    for (int i = s; i <= e; i++) {
        if ((i >= 1) && (i <= 9)) {
            cout << ntw(i) << endl;
        } else {
            cout << ((i % 2 == 0) ? "even" : "odd") << endl;
        }
    }
    
    return 0;
}
