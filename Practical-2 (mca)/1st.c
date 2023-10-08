#include <stdio.h>
#include <stdlib.h>
void Traverse(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \n", arr[i]);
    }
    printf("\n");
}
void Ques1(int n)
{
    // print upto 10
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", i + 1);
    }
}
void Ques2(int n)
{
    // print series 2, 4 , 6 , 8
    for (int i = 2; i < n; i += 2)
    {
        printf("%d \n", i);
    }
}
void Ques3(int n)
{
    //  Print series 2, 4, 16,……n*n (Using While,do..while and for loop)
    for (int i = 2; i < n; i += n * i)
    {
        printf("%d \n", i);
    }
}
int Ques4(int arr[], int size)
{
    // find average of n
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    int ave = sum / size;
    return ave;

    // int arr[] = {5,10,15,20};
    // printf("%d \n",Ques4(arr,4));
}
int *fibonnacci(int size)
{
    int n1 = 0, n2 = 1, n3;
    int fibo[] = {};
    for (int i = 0; i < size; i++)
    {
        n3 = n1 + n2;
        // printf("%d \n",n3);
        fibo[i] = n3;
        n1 = n2;
        n2 = n3;
    }
    return fibo;
}
int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
    //  int a = factorial(5);
    // printf("fact of 5 is %d \n",a);
}
void Ques8(int n)
{
    //  Write a program to print all the numbers and sum of all the integers that are
    // greater than 100 and less than 200 and are divisible by 7.
    int sum = 0;
    for (int i = 100; i < n; i++)
    {
        if (i % 7 == 0)
        {
            printf("%d \n", i);
            sum += i;
        }
    }
    printf("Total sum is : %d \n", sum);
}
void Ques9(int n1, int n2)
{
    char choice;
    int ShouldEnd = 0;

    do
    {
        printf("Enter your choice + - / * or Q to exit\n");
        scanf("%c", &choice);

        switch (choice)
        {
        case '+':
            printf("%d \n", n1 + n2);
            break;
        case '-':
            printf("%d \n", n1 - n2);
            break;
        case '/':
            printf("%d \n", n1 / n2);
            break;
        case '*':
            printf("%d \n", n1 * n2);
            break;
        default:
            printf("INVALID CHOICES \n");
        }
    } while (!ShouldEnd);
}
void Patterns()
{
    char choice;
    int ShouldQuit = 0;

    do
    {
        printf("1 for Block , 2 for Left Triange , 3 for left inverted triangle , 4 for  hollow box ,5 for right side invered triangle OR type Q to exit  \n");
        scanf("%c", &choice);
        switch (choice)
        {
        case '1':
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    printf("* ");
                }
                printf("\n");
            }
            break;
        case '2':
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    printf("* ");
                }
                printf("\n");
            }
            break;
        case '3':
            for (int i = 0; i < 5; i++)
            {
                for (int j = i; j < 5; j++)
                {
                    printf("* ");
                }
                printf("\n");
            }
            break;
        case '4':
            for (int i = 1; i <= 5; i++)
            {
                for (int j = 1; j <= 5; j++)
                {
                    if (i == 1 || i == 5 || j == 1 || j == 5)
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            break;
        case '5':
            for (int i = 5; i >= 1; i--)
            {
                for (int j = 1; j <= 5; j++)
                {
                    printf("* ");
                }
                printf("\n");
            }
            break;
        default:
            printf("invalid choice \n");
            break;
        }
    } while (!ShouldQuit);
}
Ques11(int *arr, int size)
{
    /*To find largest from a 1-d array*/
    int largest = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}
void Ques12(int *arr, int size)
{
    // . Write a program to sort given array in ascending order
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int *Ques13(int *arrA,int Asize, int *arrB, int Bsize)
{
    // Given the two 1-D arrays A and B, which are sorted in ascending order. Write a program to
    // merge them into a single sorted array C that contains every item from arrays A and B, in
    // ascending order.
    int *REarray = (int *)malloc((Asize + Bsize) * sizeof(int));

    int j = 1;
    for (int i = 0; i < Asize; i++)
    {
        REarray[i] = arrA[i];
        j++;
    }
    for (int i = 0; i < Bsize; i++)
    {
        REarray[i + Asize] = arrB[i];
    }

    return REarray;
    // int A[] = {10, 20, 30};
    // int B[] = {40, 50};
    // int sizeA = sizeof(A) / sizeof(int);
    // int sizeB = sizeof(B) / sizeof(int);
    // Ques12(A, sizeA);
    // Ques12(B, sizeB);
    // int *res = Ques13(A,sizeA, B,sizeB);
    // int size = sizeof(res) / sizeof(int);

    // Traverse(res, size);
}
int main()
{
   int a = 1 ;
   do {
       printf("%d \n",a);
   } while(a > 100);
    return 0;
}