#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char const* argv[])
{
    char t[11];
    scanf("%s", t);

    char h[2] = {t[0], t[1]};
    printf("%02d%.6s",
            (t[8] == 'A') ? atoi(h)%12 : (atoi(h) == 12) ? 12 : atoi(h)+12,
            t+2);

    return 0;
}
