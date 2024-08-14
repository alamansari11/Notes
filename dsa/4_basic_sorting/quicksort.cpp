#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choosing the last element as the pivot
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}
int partitionNew(vector<int>& arr,int start,int end){
    int pivot = arr[end];
    int position_of_pivot = start-1;
    for(int iter = start;iter<end;++iter)
    {
        if(arr[iter]<pivot){
            ++position_of_pivot;
            swap(arr[position_of_pivot],arr[iter]);
        }
    }
    swap(arr[position_of_pivot+1],arr[end]);
    return position_of_pivot+1;
}

// Function to implement quicksort
void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionNew(arr, low, high);

        quicksort(arr, low, pi - 1);  // Recursively sort elements before partition
        quicksort(arr, pi + 1, high);  // Recursively sort elements after partition
    }
}

// Function to print the array
void printArray(const std::vector<int>& arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {3, 6, 8, 10, 1, 2, 1};

    std::cout << "Original array: ";
    printArray(arr);

    quicksort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
