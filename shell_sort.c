void shell_sort(int arr[], int n) {
    int gap;

    for (gap = n / 2; gap > 0; gap /= 2) {
        int i;

        for (i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}
