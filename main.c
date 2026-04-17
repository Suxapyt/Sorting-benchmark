#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell_sort(int arr[], int n);
void merge_sort(int arr[], int temp[], int left, int right);

void random_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}
void copy_array(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}
int is_sorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i-1] > arr[i]) return 0;
    }
    return 1;
}

int main()
{
    srand(time(NULL));
    printf("Shell vs Merge\n");

    for (int n = 1000000; n <= 10000000; n += 1000000)
    {

        int *a = malloc(n * sizeof(int));
        int *b = malloc(n * sizeof(int));
        int *temp = malloc(n * sizeof(int));

        if (!a || !b || !temp)
        {
            break;
        }
        random_array(a, n);
        copy_array(a, b, n);

        clock_t start;
        double t1, t2;

        start = clock();
        shell_sort(a, n);
        t1 = (double)(clock() - start) / CLOCKS_PER_SEC;

        start = clock();
        merge_sort(b, temp, 0, n - 1);
        t2 = (double)(clock() - start) / CLOCKS_PER_SEC;

        printf("n = %d\n", n);
        printf("shell: %.6f s\n", t1);
        printf("merge: %.6f s\n\n", t2);

        free(a);
        free(b);
        free(temp);
    }
    return 0;
}
