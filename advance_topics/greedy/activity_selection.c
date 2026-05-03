#include <stdio.h>
#include <stdlib.h>

// Swap rows (3 columns: activity, start, finish)
void swap(float A[][3], int r1, int r2)
{
    for(int i = 0; i < 3; i++)
    {
        float temp = A[r1][i];
        A[r1][i] = A[r2][i];
        A[r2][i] = temp;
    }
}

// Partition based on finish time (A[][2])
int partition(float A[][3], int low, int high)
{
    float pivot = A[high][2]; // finish time
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(A[j][2] <= pivot)
        {
            i++;
            swap(A, i, j);
        }
    }

    swap(A, i + 1, high);
    return i + 1;
}

// Randomized partition
int RandomPartition(float A[][3], int low, int high)
{
    int k = low + rand() % (high - low + 1);
    swap(A, k, high);
    return partition(A, low, high);
}

// QuickSort
void QuickSort(float A[][3], int low, int high)
{
    if(low < high)
    {
        int q = RandomPartition(A, low, high);
        QuickSort(A, low, q - 1);
        QuickSort(A, q + 1, high);
    }
}

// Print activities
void printActivity(float A[][3], int n)
{
    printf("\nActivity  Start  Finish\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t %.0f\t %.0f\n", (int)A[i][0], A[i][1], A[i][2]);
    }
}

// Greedy Activity Selection
int GreedyASP(float A[][3], int n, int X[])
{
    QuickSort(A, 0, n - 1);   // sort by finish time

    printf("\nSorted Activities:\n");
    printActivity(A, n);

    int k = 0;
    X[k++] = 0;   // select first activity

    int d = 0;    // last selected index

    for(int i = 1; i < n; i++)
    {
        if(A[i][1] >= A[d][2])   // start >= last finish
        {
            X[k++] = i;
            d = i;
        }
    }

    return k; // number of selected activities
}

int main()
{
    int n;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    float A[n][3];

    printf("Enter start time of activities:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &A[i][1]);
        A[i][0] = i + 1; // activity number
    }

    printf("Enter finish time of activities:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &A[i][2]);
    }

    int X[n];

    int k = GreedyASP(A, n, X);

    printf("\nFinal Activities Selected:\n");
    printf("Act  Start  Finish\n");

    for(int i = 0; i < k; i++)
    {
        int idx = X[i];
        printf("%d\t %.0f\t %.0f\n",
               (int)A[idx][0],
               A[idx][1],
               A[idx][2]);
    }

    return 0;
}