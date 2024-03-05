#include <iostream>
using namespace std;
int visited[5] = {0};

int a[][5] = {
    {0, 1, 1, 1, 0},
    {1, 0, 1, 0, 0},
    {1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0}};
void dfs(int i)
{
    printf("%d ", i);
    visited[i] = 1;
    int j;
    for (j = 0; j < 5; j++)
    {
        if (a[i][j] == 1 && visited[j] == 0)
        {

            dfs(j);
        }
    }
}
int main()
{
    int i;
    scanf(" %d ", &i);
    dfs(i);
    return 0;
}