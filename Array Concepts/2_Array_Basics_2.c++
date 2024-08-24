#include <iostream>
#include <vector>  // For dynamic arrays (vectors)
using namespace std;

// Function to print a 1D array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to perform Linear Search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;  // Return index of found element
    }
    return -1;  // Element not found
}

// Function to perform Binary Search (Array must be sorted)
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;  // Element not found
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to demonstrate 2D array
void print2DArray(int arr[][3], int rows, int cols) {
    cout << "\n2D Array Elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    // 1. Multi-dimensional Arrays (2D Array)
    int arr2D[2][3] = {{1, 2, 3}, {4, 5, 6}};
    print2DArray(arr2D, 2, 3);

    // 2. Passing 1D Array to Functions
    int arr1D[5] = {10, 20, 30, 40, 50};
    cout << "\nOriginal 1D Array: ";
    printArray(arr1D, 5);

    // 3. Linear Search
    int key = 30;
    int index = linearSearch(arr1D, 5, key);
    if (index != -1)
        cout << "\nElement " << key << " found at index " << index << " using Linear Search." << endl;
    else
        cout << "\nElement " << key << " not found using Linear Search." << endl;

    // 4. Sorting the Array using Bubble Sort
    bubbleSort(arr1D, 5);
    cout << "\nSorted Array: ";
    printArray(arr1D, 5);

    // 5. Binary Search (after sorting)
    key = 40;
    index = binarySearch(arr1D, 5, key);
    if (index != -1)
        cout << "\nElement " << key << " found at index " << index << " using Binary Search." << endl;
    else
        cout << "\nElement " << key << " not found using Binary Search." << endl;

    // 6. Dynamic Arrays (using vector)
    vector<int> dynArray;
    dynArray.push_back(100);
    dynArray.push_back(200);
    dynArray.push_back(300);
    dynArray.push_back(400);

    cout << "\nDynamic Array (vector) Elements: ";
    for (int i = 0; i < dynArray.size(); i++) {
        cout << dynArray[i] << " ";
    }
    cout << endl;

    return 0;
}
