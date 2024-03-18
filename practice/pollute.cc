#include <iostream>
#define SIZE 10000 
using namespace std;

int *arr = new int[SIZE];
    // int *Duplicate = (int *) malloc((size +1) * sizeof(int));

void pollute () {
	for (int i = 0 ;i < SIZE ; ++i)
	{
		arr[i] = rand() % 1000 ;
	}
}
void traverse()
{
    for (int i = 0; i < (sizeof(arr)/sizeof(int)); i+=500)
    {
        printf("%3d [%d]\n", arr[i],i);
    }
    printf("\n");
}
void free_arr(){
	free (arr);
}
int main () {
		pollute();
		traverse();
		free_arr();
		cout << "MEMOERY FREED\n";
		traverse();
	return 01;
}
