#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main()
{
    auto *array = new float[1000000];
    // Create a text string, which is used to output the text file
    string filename[] = {"Data_Input_Array_1.txt", "Data_Input_Array_2.txt", "Data_Input_Array_3.txt", "Data_Input_Array_4.txt", "Data_Input_Array_5.txt", 
    "Data_Input_Array_6.txt", "Data_Input_Array_7.txt", "Data_Input_Array_8.txt", "Data_Input_Array_9.txt", "Data_Input_Array_10.txt"};
    freopen("Runtime_Build_in_Sort.txt", "w", stdout);
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
        sort(array, array + 1000000);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        
        cout << "Time taken by function " << filename[i] << ": " << duration.count() << " microseconds" << endl;
    }
}