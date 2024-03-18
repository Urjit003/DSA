#include <stdio.h>
#include <stdlib.h>
void FizzBuzz(int length)
{
    for (int i = 1; i <= length; i++)
    {
        printf("%d %s \n", i, ((i % 5 == 0) && (i % 3 == 0)) ? "BuzzFizz" : (i % 3 == 0) ? "Buzz"
                                                                        : (i % 5 == 0)   ? "Fuzz"
                                                                                         : "");
    }
}
int main()
{
    FizzBuzz(20);
    return 0;
}