#include <stdio.h>

int main(int argc, char const *argv[])
{
    int list[6] = {1, 2, 3, 4, 5};

    void supprimerR()
    {
        for (int i = 0; i < 5; i++)
        {
            if (list[i] == list[i + 1])
            {
                for (int i = 0; i < i - 1; i++)
                {
                    list[i] = list[i + 1];
                }
            }
        }
    }
    supprimerR();
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", list[i]);
    }
    return 0;
}
