#include <stdio.h>

// Function to find the maximum element in an array
void maxElement() {
    int n = 7; 
    int arr[] = {3, 10, 20, 2, 7, 14, 8};
    int max = arr[0]; 

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("The maximum value in the array is: %d\n", max);
}


// Bubble Sort function to sort an array
void bubbleSort(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


// Function to find the second maximum element in an array
void secondMax() {
    int n = 7; 
    int arr[] = {3, 10, 20, 2, 7, 14, 8};

    bubbleSort(arr, n);
    printf("The second maximum value in the array is: %d\n", arr[n-2]);
}

// Function to find the k-th largest element in an array
void kthLargest(int k) {
    int n = 7; 
    int arr[] = {3, 10, 20, 2, 7, 14, 8};

    bubbleSort(arr, n);
    printf("The %d-th largest value in the array is: %d\n", k, arr[n-k]);
}


// Function to find a missing number in a sequence using sorting
void missingNumber1() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            printf("Missing element: %d\n", i + 1);
            break;
        }
    }
}

// Function to find a missing number by comparing sums
void missingNumber2() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max = arr[0], sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        sum += arr[i];
    }
    int expectedSum = (max * (max + 1)) / 2;
    printf("The missing number is %d\n", expectedSum - sum);
}

int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }
    
// Function to check if a number is a Strong Number
void strongNumber() {
    int number, originalNumber, digit, fact = 0;
    printf("Enter a number: ");
    scanf("%d", &number);

    originalNumber = number;

    while (number != 0) {
        digit = number % 10;
        fact += factorial(digit);
        number /= 10;
    }

    if (fact == originalNumber) {
        printf("The number is a Strong Number\n");
    } else {
        printf("The number is not a Strong Number\n");
    }
}

// Function to find the median in an array (assuming odd number of elements)
void findMedian() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    printf("The median is %d\n", arr[n/2]);
}

int main() {
    // Uncomment the function you want to run
    // maxElement();
    // secondMax();
    // kthLargest(4);
    // missingNumber1();
    // missingNumber2();
    // strongNumber();
    findMedian();

    return 0;
}
