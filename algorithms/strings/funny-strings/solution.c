#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const* argv[])
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        char s[10000];
        scanf("%s", s);

        int f = 1, b = strlen(s)-2, c = 1;
        while(f <= b) {
            if (abs(s[f] - s[f-1]) != abs(s[b] - s[b+1])) {
                c = 0;
                break;
            }
            f++; b--;
        }

        printf("%s\n", c ? "Funny" : "Not Funny");
    }

    return 0;
}
