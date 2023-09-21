#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    char list[26][25] = {"abdelkjagdyajkdhagdj"};
    char la = 'a';
    for (int i = 0; i < 26; i++)
    {
        if (strcmp(list[i], la) == 0)
        {
            printf("%c\n", toupper(list[i]));
        }
    }

    return 0;
}