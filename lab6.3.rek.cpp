#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;


void generateArray(int arr[], int n, int index = 0) {
    if (index >= n) return; 
    arr[index] = 1 + rand() % 15;
    generateArray(arr, n, index + 1);
}

int countElements(int arr[], int n, int index = 0) {
    if (index >= n) return 0; 
    if (arr[index] % 2 == 0) { 
        return 1 + countElements(arr, n, index + 1);
    }
    else {
        return countElements(arr, n, index + 1); 
    }
}

void Print(int* a, const int size, int index = 0) {
    if (index >= size) { 
        cout << endl;
        return;
    }
    cout << a[index] << setw(4); 
    Print(a, size, index + 1); 
}

template <typename T>
void generateArrayTemplate(T arr[], int n, int index = 0) {
    if (index >= n) return; 
    arr[index] = 1 + rand() % 15;
    generateArrayTemplate(arr, n, index + 1);
}


template <typename T>
int countElementsTemplate(T arr[], int n, int index = 0) {
    if (index >= n) return 0;
    if (arr[index] % 2 == 0) {
        return 1 + countElementsTemplate(arr, n, index + 1);
    }
    else {
        return countElementsTemplate(arr, n, index + 1);
    }
}

template <typename T>
void PrintTemplate(T* a, const int size, int index = 0) {
    if (index >= size) {
        cout << endl;
        return;
    }
    cout << a[index] << setw(4);
    PrintTemplate(a, size, index + 1);
}

int main() {
    srand((unsigned)time(NULL));

    int a[5]; 
    generateArray(a, 5); 
    Print(a, 5); 
    cout << "Count (rec): " << countElements(a, 5) << endl << endl; 

    int b[5];
    generateArrayTemplate(b, 5);
    PrintTemplate(b, 5);
    cout << "Count (template rec): " << countElementsTemplate(b, 5) << endl;

    return 0;
}
