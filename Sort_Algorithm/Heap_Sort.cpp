#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
 
// Function to swap the position of two elements
 
void swap(float* a, float* b)
{
 
    float temp = *a;
    *a = *b;
    *b = temp;
}
 
// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(float array[], int N, int i)
{
    // Find largest among root, left child and right child
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int left = 2 * i + 1;
 
    // right = 2*i + 2
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < N && array[left] > array[largest])
 
        largest = left;
 
    // If right child is larger than largest
    // so far
    if (right < N && array[right] > array[largest])
 
        largest = right;
 
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {
 
        swap(&array[i], &array[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(array, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(float array[], int N)
{
 
    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)
 
        heapify(array, N, i);
 
    // Heap sort
    for (int i = N - 1; i >= 0; i--) {
 
        swap(&array[0], &array[i]);
 
        // Heapify root element to get highest element at
        // root again
        heapify(array, i, 0);
    }
}

int main()
{
    auto *array = new float[1000000];
    // Create a text string, which is used to output the text file
    string filename[] = {"Data_Input_Array_1.txt", "Data_Input_Array_2.txt", "Data_Input_Array_3.txt", "Data_Input_Array_4.txt", "Data_Input_Array_5.txt", 
    "Data_Input_Array_6.txt", "Data_Input_Array_7.txt", "Data_Input_Array_8.txt", "Data_Input_Array_9.txt", "Data_Input_Array_10.txt"};
    freopen("Runtime_Heap_Sort.txt", "w", stdout);
    for (int i = 0 ; i < 10 ; i++)
    {
        // Read from the text file
        ifstream MyReadFile(filename[i]);

        // Use a while loop together with the getline() function to read the file line by line
        for (int i = 0 ; (MyReadFile.get()) && i < 1000000 ; ++i) 
        {
            MyReadFile >> array[i];
        }
        // Close the file
        MyReadFile.close();
        
        auto start = high_resolution_clock::now();
        heapSort(array, 1000000);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        
        cout << "Time taken by function " << filename[i] << ": " << duration.count() << " microseconds" << endl;
    }
}