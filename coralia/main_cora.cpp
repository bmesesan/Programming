// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int partition(int *arr, int start, int end) {
    int i = -1;
    int j = start;
    int aux;
    int pivot = arr[end];
    while ( j < end) {
        if (arr[j] < pivot) {
            i++;
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
        j++;
    }
    i++;
    aux = arr[i];
    arr[i] = arr[end];
    arr[end] = aux;
    return i;
}

void quickSort(int *arr, int start, int end) {
    if (start >= end || end == (start + 1)) {
        return;
    }
    int p = partition(arr, start, end);
    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
}

int main() {
    int size = 9;
    int arr[9] = {5, 12, 7, 1, 13, 2 ,23, 11, 18};
    cout << "Unsorted array : ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    printf("\n");
 
    quickSort(&arr[0], 0, size - 1);
    cout << "Sorted array : ";
    for (int i = 0; i < size; i++) {
       cout << arr[i] << " ";
    }
    return 0;
}