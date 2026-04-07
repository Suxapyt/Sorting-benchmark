#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell_sort(int arr[], int n);
void merge_sort(int arr[], int temp[], int left, int right);

void random_array(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }
}
void copy_array(int a[], int b[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        b[i] = a[i];
    }
}
int main()
{
    int n;
    srand(time(NULL));
    for (n = 5000; n <= 50000; n += 5000) {
        int *a = malloc(n * sizeof(int));
        int *b = malloc(n * sizeof(int));
        int *temp = malloc(n * sizeof(int));
        clock_t start;
        double shell_time;
        double merge_time;

        random_array(a, n);
        copy_array(a, b, n);

        start = clock();
        shell_sort(a, n);
        shell_time = (double)(clock() - start) / CLOCKS_PER_SEC;

        start = clock();
        merge_sort(b, temp, 0, n - 1);
        merge_time = (double)(clock() - start) / CLOCKS_PER_SEC;

        printf("n = %d\n", n);
        printf("shell sort: %.6f s\n", shell_time);
        printf("merge sort: %.6f s\n\n", merge_time);

        free(a);
        free(b);
        free(temp);
    }

    return 0;
}
