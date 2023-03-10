#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void Merge(float array[], int start, int mid, int end)
{

    int length_n1 = mid - start + 1;
    int length_n2 = end - mid;
    auto *n1_array = new float[length_n1]; 
    auto *n2_array = new float[length_n2];
    for (int i = 0 ; i < length_n1 ; i++)
    {
        n1_array[i] = array[start + i];
    }
    for (int i = 0 ; i < length_n2 ; i++)
    {
        n2_array[i] = array[mid + i + 1];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    while (i < length_n1 && j < length_n2)
    {
        if (n1_array[i] <= n2_array[j])
        {
            array[k] = n1_array[i];
            ++i;
        }
        else
        {
            array[k] = n2_array[j];
            ++j;
        }
        ++k;
    }

    while (i < length_n1)
    {
        array[k] = n1_array[i];
        ++i;
        ++k;
    }

    while (j < length_n2)
    {
        array[k] = n2_array[j];
        ++j;
        ++k;
    }
}

void Merge_Sort(float array[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        Merge_Sort(array, start, mid);
        Merge_Sort(array, mid + 1, end);

        Merge(array, start, mid, end);
    }
}

int main()
{
    auto *array = new float[1000000];
    // Create a text string, which is used to output the text file
    string filename[] = {"Data_Input_Array_1.txt", "Data_Input_Array_2.txt", "Data_Input_Array_3.txt", "Data_Input_Array_4.txt", "Data_Input_Array_5.txt", 
    "Data_Input_Array_6.txt", "Data_Input_Array_7.txt", "Data_Input_Array_8.txt", "Data_Input_Array_9.txt", "Data_Input_Array_10.txt"};
    freopen("Runtime_Merge_Sort.txt", "w", stdout);
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
        Merge_Sort(array, 0, 1000000 - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        
        cout << "Time taken by function " << filename[i] << ": " << duration.count() << " microseconds" << endl;
    }
}