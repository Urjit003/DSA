#include "stdio.h"
#include "stdlib.h"

struct myArray {
    int total_size;
    int used_size;
    int *ptr;
} ;
void createarray(struct myArray *a,int MaxSize , int UsingSize); 
void showarray(struct myArray *a);
void setvalues(struct myArray *a);
void createarray(struct myArray *a,int MaxSize , int UsingSize) {
    a->total_size= MaxSize;
    a->used_size=UsingSize;
    a->ptr= (int *) malloc(MaxSize*sizeof(int));
}
void showarray(struct myArray *a){
    for (int i = 0; i < a->used_size; i++)
    {
       printf("%d and their memory address is %d: \n",(a->ptr)[i],&(a->ptr)[i]);
    }
}
void setvalues(struct myArray *a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter value for elemet %d: ",i+1);
        scanf("%d",&n);
        (a->ptr)[i]= n;
    }
}


int main () {
    struct myArray marks;
    createarray(&marks,10,5);
    setvalues(&marks);
    showarray(&marks);
    // printf("HELLO WORLD");
    return 1;
}