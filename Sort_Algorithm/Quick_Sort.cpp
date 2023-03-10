#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int partition(float arr[], int low, int high)
{
    // pivot
    float pivot = arr[high];
   
    // Index of smaller element
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller
        // than or equal to pivot
        if (arr[j] <= pivot) {
 
            // increment index of
            // smaller element
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 
int partition_r(float arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    return partition(arr, low, high);
}
 

void quickSort(float arr[], int low, int high)
{
    if (low < high) 
    {
 
        int pi = partition_r(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    auto *array = new float[1000000];
    // Create a text string, which is used to output the text file
    string filename[] = {"Data_Input_Array_1.txt", "Data_Input_Array_2.txt", "Data_Input_Array_3.txt", "Data_Input_Array_4.txt", "Data_Input_Array_5.txt", 
    "Data_Input_Array_6.txt", "Data_Input_Array_7.txt", "Data_Input_Array_8.txt", "Data_Input_Array_9.txt", "Data_Input_Array_10.txt"};
    freopen("Runtime_Quick_Sort.txt", "w", stdout);
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
        quickSort(array, 0, 1000000 - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        
        cout << "Time taken by function " << filename[i] << ": " << duration.count() << " microseconds" << endl;
    }
}