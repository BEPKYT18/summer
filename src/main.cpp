#include "sorts.cpp"
#include "funcs.cpp"
#include <chrono>
#include <iostream>

int main(){
    srand(time(0));
    int size=1000, min=-10000, max=10000, max_depth=0;

    int arr[size];
    Random(arr,size,min,max);
    //printArr(arr,size);
    auto start = std::chrono::high_resolution_clock::now();
    
    selectionSort(arr,size);

    auto end = std::chrono::high_resolution_clock::now();
    
    //printArr(arr,size);

    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "time: " << ms.count() << " ms\n";
}
