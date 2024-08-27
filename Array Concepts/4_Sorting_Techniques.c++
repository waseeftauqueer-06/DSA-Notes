#include<bits/stdc++.h>
using namespace std;


/* Selection sort repeatedly selects the minimum element from the 
   unsorted portion of an array and swaps it with the first unsorted element,
   progressively sorting the array.

   https://takeuforward.org/sorting/selection-sort-algorithm/

   TC : O(n^2)


   Iteration 1 (i = 0):

   Initial mini = 0 (assume the first element is the minimum).
   Inner loop (j from 1 to 5):
   j = 1: arr[j] = 46 > arr[mini] = 13, no change in mini.
   j = 2: arr[j] = 24 > arr[mini] = 13, no change in mini.
   j = 3: arr[j] = 52 > arr[mini] = 13, no change in mini.
   j = 4: arr[j] = 20 > arr[mini] = 13, no change in mini.
   j = 5: arr[j] = 9 < arr[mini] = 13, update mini = 5.
   Swap: arr[0] and arr[mini] (i.e., arr[0] and arr[5]).

*/


void selection_sort(int arr[], int n) {
  for(int i = 0; i <= n; i++)
  {
    int mini = i;
    int temp = 0;
    // find the minimum element's index in the iteration
    for(int j = i+1; j < n; j++){
        if(arr[j] < arr[mini]){
            mini = j;
        }
    }
    // swap it with the starting unsorted index
    temp = arr[i];
    arr[i] = arr[mini];
    arr[mini] = temp;
  }

  cout << "After selection sort: " << "\n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";

}


/* Bubble sort repeatedly compares and swaps adjacent elements in an array,
   moving the largest unsorted element to its correct position in each pass.

   https://takeuforward.org/data-structure/bubble-sort-algorithm/

   TC : O(n^2)

   pass 1 (i = 5):
   Comparison 1: arr[0] (5) and arr[1] (2) → Swap because 5 > 2.
   Comparison 2: arr[1] (5) and arr[2] (9) → No swap because 5 < 9.
   Comparison 3: arr[2] (9) and arr[3] (1) → Swap because 9 > 1.
   Comparison 4: arr[3] (9) and arr[4] (5) → Swap because 9 > 5.
   Comparison 5: arr[4] (9) and arr[5] (6) → Swap because 9 > 6.
   Pass 2 (i = 4):
   Comparison 1: arr[0] (2) and arr[1] (5) → No swap because 2 < 5.
   Comparison 2: arr[1] (5) and arr[2] (1) → Swap because 5 > 1.
   Comparison 3: arr[2] (5) and arr[3] (6) → No swap because 5 < 6.
   Comparison 4: arr[3] (6) and arr[4] (9) → No swap because 6 < 9.
*/

void bubble_sort(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "After bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


/* Insertion Sort repeatedly takes each element from the unsorted part of the array
   and places it into the correct position in the sorted part of the array.

   https://takeuforward.org/data-structure/insertion-sort-algorithm/

   TC : O(n^2)

   Iteration 1 (i = 1):
   Current Element: 46
   Sorted Portion: {13}
   Unsorted Portion: {46, 24, 52, 20, 9}
   Action: 46 is already greater than 13, so no changes are needed.
   Array: {13, 46, 24, 52, 20, 9}

   Iteration 2 (i = 2):
   Current Element: 24
   Sorted Portion: {13, 46}
   Unsorted Portion: {52, 20, 9}
   Action:
   Compare 24 with 46: 24 is less than 46, so move 46 to the right.
   Compare 24 with 13: 24 is greater than 13, so insert 24 in the correct position.
   Array: {13, 24, 46, 52, 20, 9}

*/

void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

//TC : O(N log N)
//Recursively divides the array into halves, sorts each half, and then merges the sorted halves.
void merge(int arr[], int l, int m, int r) {
    vector<int> temp;
    int low = l;
    int high = m + 1;

    while (low <= m && high <= r) {
        if (arr[low] <= arr[high]) {
            temp.push_back(arr[low]);
            low++;
        } else {
            temp.push_back(arr[high]);
            high++;
        }
    }

    while (low <= m) {
        temp.push_back(arr[low]);
        low++;
    }

    while (high <= r) {
        temp.push_back(arr[high]);
        high++;
    }

    for (int i = l; i <= r; i++) {
        arr[i] = temp[i - l];
    }
}

// Function for Merge Sort
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

//Recursively sorts the array by partitioning it and sorting the subarrays around the pivot.
//TC : O(N log N)
// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partIndex = partition(arr, low, high);
        quickSort(arr, low, partIndex - 1);  // Recursively sort the left part
        quickSort(arr, partIndex + 1, high); // Recursively sort the right part
    }
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choosing the first element as pivot
    int i = low;
    int j = high;
    
    while (i < j) {
        // Move the `i` index to the right if the element is less than or equal to the pivot
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        // Move the `j` index to the left if the element is greater than the pivot
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        // Swap elements if `i` is less than `j`
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    // Swap the pivot element with the element at `j` to place the pivot in its correct position
    swap(arr[low], arr[j]);
    return j; // Return the partition index
}

int main() {
  int arr[] = {13,46,24,52,20,9};
  int n = sizeof(arr) / sizeof(arr[0]);
   cout << "Before selection sort: " << "\n";
   for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  bubble_sort(arr, n);
  return 0;
}