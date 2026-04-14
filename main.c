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

int is_sorted(int arr[], int n)
{
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i-1] > arr[i]) return 0;
    }
    return 1;
}

int main()
{
    int n, i;
    srand(time(NULL));

    for (n = 5000; n <= 50000; n += 5000) {

        double shell_sum = 0;
        double merge_sum = 0;

        for (i = 0; i < 3; i++) {

            int *a = malloc(n * sizeof(int));
            int *b = malloc(n * sizeof(int));
            int *temp = malloc(n * sizeof(int));

            clock_t start;
            double t1, t2;

            random_array(a, n);
            copy_array(a, b, n);

            start = clock();
            shell_sort(a, n);
            t1 = (double)(clock() - start) / CLOCKS_PER_SEC;

            start = clock();
            merge_sort(b, temp, 0, n - 1);
            t2 = (double)(clock() - start) / CLOCKS_PER_SEC;

            if (!is_sorted(a, n) || !is_sorted(b, n)) {
                printf("ERROR\n");
            }

            shell_sum += t1;
            merge_sum += t2;

            free(a);
            free(b);
            free(temp);
        }

        printf("n = %d\n", n);
        printf("shell avg: %.6f s\n", shell_sum / 3);
        printf("merge avg: %.6f s\n\n", merge_sum / 3);
    }

    return 0;
}
