#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int fav_int;
    float fav_float;
    char *name;
} Urjit;
int main()
{
    Urjit *u1;
    u1 = (Urjit *)malloc(sizeof(Urjit));
    u1->name = (char *) malloc(sizeof(char));

    u1->name = 'c';
    for (int i = 0; i < u1->name['\0']; i++)
    {
        printf("%c",u1->name);

    }
    
    free(u1);

    return 0;
}