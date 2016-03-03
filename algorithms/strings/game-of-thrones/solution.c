#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

int main(int argc, char const* argv[])
{
    char input[100000];
    scanf("%s", input);

    int * k = (int *) calloc(26, sizeof(int));
    for (char * c = input; *c != 0; c++)
        k[*c%26] = !k[*c%26];

    int j = 0;
    for (int i = 0; i < 26; i++) {
       j += k[i];
    }

    printf("%s\n", j > 1 ? "NO":"YES");

    return 0;
}

