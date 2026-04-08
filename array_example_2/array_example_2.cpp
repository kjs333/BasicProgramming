
#include <cstdio>

int main(int argc, char* argv[])
{
    int arr[3][2] = {{0, 1}, {2, 3}, {4, 5}}; // 2차원 배열(array)
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
