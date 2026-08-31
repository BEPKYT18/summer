#include <iostream>

template<class T>
void printArr(T* arr, size_t size){
    for(int i=0; i<size; ++i){
        std::cout<<arr[i]<<' ';
    }
    std::cout<<'\n';
}

void RightShift(int* arr, size_t k, size_t size){
    k%=size;

    for(int i=0;i<k;++i){
        int temp=arr[size-1];
        for(int j=size-1;j>0;--j){
            arr[j]=arr[j-1];
        }
        arr[0]=temp;
    }
}

int randint(int min, int max){
    return rand()%(max-min+1)+min;
}

void Random(int* arr, size_t size, int min, int max){
    for(int i=0;i<size;++i){
        arr[i]=randint(min,max);
    }
}

void Sorted_Reversed(int* arr, size_t size, int min, int max, int(*comparator)(const void*, const void*)){
    Random(arr,size,min,max);
    qsort(arr,size,sizeof(int), comparator);
}

void Almost_Sorted(int* arr, size_t size, int min, int max, int(*comparator)(const void*, const void*)){
    Random(arr,size,min,max);
    qsort(arr,size,sizeof(int), comparator);
    int swaps=static_cast<int>(size*0.05/2.0);
    if (swaps<1)swaps=1;
    for(int i=0;i<swaps;++i){
        size_t Id1=rand()%size;
        size_t Id2=rand()%size;

        while(Id1==Id2)Id2=rand()%size;

        swap(arr[Id1], arr[Id2]);
    }
}

