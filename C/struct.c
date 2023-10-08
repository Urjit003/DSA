#include <stdio.h>
#include <stdlib.h>
struct Student
{
    int id;
    char name[100];
    float per;
};

int main() {
    struct Student s1[3];
    int size= sizeof(s1)/sizeof(struct Student);
    for (int i = 0; i < size; i++)
    {
        s1[i].id = i+1;
        printf("Enter name of student %d \n",i+1);
        scanf("%s",&s1[i].name);
        printf("Enter percent of student %d \n",i+1);
        scanf("%f",&s1[i].per);
    }
        printf("ID\t\tName\t\tper\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t\t%s\t\t%.2f\t\t\n",s1[i].id,s1[i].name,s1[i].per);
    }
    
return 0 ;
}