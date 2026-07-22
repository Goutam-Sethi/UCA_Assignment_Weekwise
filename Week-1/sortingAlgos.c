#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }

        swap(&arr[i], &arr[min]);
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right)
{
    int temp[40000];
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void quickSortWrapper(int arr[], int n) { 
    quickSort(arr, 0, n - 1); 
}
void mergeSortWrapper(int arr[], int n) { 
    mergeSort(arr, 0, n - 1); 
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void generateRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

void generateAscending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void generateDescending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

typedef void (*SortFunction)(int[], int);

double measureExecutionTime(SortFunction sortFunc, int arr[], int n) {
    clock_t start = clock();
    sortFunc(arr, n);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

// this part of code is done with the help of chatgpt for the ease of test case checking

int main() {
    srand((unsigned int)time(NULL));
    int sizes[] = {8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000};
    int num_sizes = 8;

    SortFunction sorts[] = {bubbleSort, insertionSort, selectionSort, quickSortWrapper, mergeSortWrapper, heapSort};
    const char* sortNames[] = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Quick Sort", "Merge Sort", "Heap Sort"};
    int num_sorts = 6;

    const char* orderNames[] = {"Random", "Ascending", "Descending"};

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        printf("Array Size: %d\n", n);

        int* originalRandom = (int*)malloc(n * sizeof(int));
        int* originalAscending = (int*)malloc(n * sizeof(int));
        int* originalDescending = (int*)malloc(n * sizeof(int));
        int* testArray = (int*)malloc(n * sizeof(int));

        generateRandom(originalRandom, n);
        generateAscending(originalAscending, n);
        generateDescending(originalDescending, n);

        int* originals[] = {originalRandom, originalAscending, originalDescending};

        for (int o = 0; o < 3; o++) {
            printf("  Order: %s\n", orderNames[o]);
            for (int alg = 0; alg < num_sorts; alg++) {
                copyArray(originals[o], testArray, n);
                double time_taken = measureExecutionTime(sorts[alg], testArray, n);
                printf("    %-15s: %.2f ms\n", sortNames[alg], time_taken);
            }
        }


        free(originalRandom);
        free(originalAscending);
        free(originalDescending);
        free(testArray);
        printf("\n");
    }

    return 0;
}