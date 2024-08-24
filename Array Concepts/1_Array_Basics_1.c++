#include <iostream>
using namespace std;

int main() {
    // 1. Array Declaration and Initialization
    int arr[5] = {10, 20, 30, 40, 50};  // Array of 5 integers

    // 2. Accessing Array Elements
    cout << "Accessing Array Elements:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "Element at index " << i << " is " << arr[i] << endl;
    }

    // 3. Modifying Array Elements
    arr[2] = 35;  // Changing the value of the 3rd element (index 2)
    cout << "\nAfter modifying the 3rd element:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "Element at index " << i << " is " << arr[i] << endl;
    }

    // 4. Array Length
    int length = sizeof(arr) / sizeof(arr[0]);  // Calculate array length
    cout << "\nLength of the array: " << length << endl;

    // 5. Array Traversal (Using a Range-based For Loop)
    cout << "\nArray Traversal using Range-based For Loop:" << endl;
    for(int element : arr) {
        cout << element << " ";
    }
    cout << endl;

    // 6. Array Input from User
    int userArray[5];
    cout << "\nEnter 5 elements for the array:" << endl;
    for(int i = 0; i < 5; i++) {
        cin >> userArray[i];
    }

    // 7. Displaying User Input Array
    cout << "\nUser Input Array:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "Element at index " << i << " is " << userArray[i] << endl;
    }

    // 8. Finding the Maximum and Minimum Elements in an Array
    int maxElement = userArray[0];
    int minElement = userArray[0];
    
    for(int i = 1; i < 5; i++) {
        if(userArray[i] > maxElement) {
            maxElement = userArray[i];
        }
        if(userArray[i] < minElement) {
            minElement = userArray[i];
        }
    }

    cout << "\nMaximum Element in the Array: " << maxElement << endl;
    cout << "Minimum Element in the Array: " << minElement << endl;

    // 9. Array Reversal
    cout << "\nArray after Reversal:" << endl;
    for(int i = 0; i < length / 2; i++) {
        int temp = userArray[i];
        userArray[i] = userArray[length - i - 1];
        userArray[length - i - 1] = temp;
    }
    
    for(int i = 0; i < 5; i++) {
        cout << "Element at index " << i << " is " << userArray[i] << endl;
    }

    return 0;
}
