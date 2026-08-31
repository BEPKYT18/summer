#include "sorts.cpp"
#include "funcs.cpp"
#include <chrono>
#include <iostream>

int main(){
    srand(time(0));
    int size=1000000, min=-10000, max=10000, max_depth=0;

    int arr[size];
    Sorted_Reversed(arr,size,min,max, compareAsc);
    //printArr(arr,size);
    auto start = std::chrono::high_resolution_clock::now();
    
    BubbleSort(arr,size);

    auto end = std::chrono::high_resolution_clock::now();
    
    //printArr(arr,size);

    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "time: " << ms.count() << " ms\n";
}
