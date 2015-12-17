#include <stdio.h>
#include <ctype.h>

int main(int argc, char const* argv[])
{
    char input[1000];

    fgets(input, sizeof(input), stdin);

    for (int i = 0; i < 26; i++) {
        int found = 0;
        for (char * cursor = input; *cursor != 0; cursor++) {
            if (tolower(*cursor) == 'a'+i) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("not pangram");
            return 0;
        }
    }

    printf("pangram");
    return 0;
}
