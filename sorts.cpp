#include <iostream>

template <class T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

int MaxInt(int* arr, size_t size){
    size_t MxId=0;
    for(int i=0;i<size;++i){
        if(arr[i]>arr[MxId])MxId=i;
    }
    return arr[MxId];
}

int MinInt(int* arr, size_t size){
     size_t MnId=0;
    for(int i=0;i<size;++i){
        if(arr[i]<arr[MnId])MnId=i;
    }
    return arr[MnId];
}

int compareAsc(const void* a, const void* b){
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int compareDesc(const void* a, const void* b){
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 > arg2) return -1;
    if (arg1 < arg2) return 1;
    return 0;
}

//n^2
void BubbleSort(int* arr,size_t size){
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);
        }
    }
}

void selectionSort(int* arr, size_t size){
    for (int i = 0; i < size - 1; ++i) {
        
        int min_idx = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
       
        swap(arr[i], arr[min_idx]);
    }
}

void insertionSort(int* arr,size_t size){
    for(int i=0;i<size;++i){
        int key=arr[i];
        int j=i-1;

        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            --j;
        }
        arr[j+1]=key;
        
    }
}

//nlogn

int partition(int* arr, int low, int high){
    int pivot = arr[high];    
    int i = low - 1;          
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
  
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i+1], arr[high]);
    
    return i + 1;
}

//int max_depth=0;

void quickSort(int* arr, int low, int high, int depth=1){
    //max_depth=std::max(max_depth,depth);
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1, depth+1);     
        quickSort(arr, pi + 1, high, depth+1);    
    }
}


void MyMerge(int* arr, size_t left, size_t mid, size_t right){
    size_t n1=mid-left+1;
    size_t n2=right-mid;

    int* L=new int[n1];
    int* R=new int[n2];

    for(int i=0;i<n1;++i){
        L[i]=arr[left+i];
    }
    for(int i=0;i<n2;++i){
        R[i]=arr[mid+1+i];
    }

    int i=0, j=0, k=left;

    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        }
    }

    while(i<n1)arr[k++]=L[i++];
    while(j<n2)arr[k++]=R[j++];

    delete[] L;
    delete[] R;

};

//int max_depth=0;

void MyMergeSort(int* arr, size_t left, size_t right, int depth=1){
    //max_depth=std::max(max_depth,depth);
    if(left>=right)return;

    int mid=(left+right)/2;

    MyMergeSort(arr,left,mid, depth+1);
    MyMergeSort(arr,mid+1,right, depth+1);
    MyMerge(arr,left,mid,right);
}

//int max_depth=0;

void heapify(int* arr, size_t size, int i, int depth=1){
   // max_depth=std::max(max_depth, depth);
    int largest = i;        
    int left = 2 * i + 1;   
    int right = 2 * i + 2;  


    if (left < size && arr[left] > arr[largest])
        largest = left;


    if (right < size && arr[right] > arr[largest])
        largest = right;


    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        heapify(arr, size, largest, depth+1);
    }
}

void buildHeap(int* arr, size_t size){

    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
}

void heapSort(int* arr, size_t size){
  
    buildHeap(arr, size);

    for (int i = size - 1; i > 0; i--) {

        std::swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}


//n

void countSort(int* arr, int size){

    int minVal = MinInt(arr, size);
    int maxVal = MaxInt(arr, size);

    int range = maxVal - minVal + 1;

    int* count = new int[range]();  

    for (int i = 0; i < size; i++) {
        count[arr[i] - minVal]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    int* output = new int[size];

    for (int i = size - 1; i >= 0; i--) {
        int num = arr[i];
        output[count[num - minVal] - 1] = num;
        count[num - minVal]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    delete[] count;
    delete[] output;
}


void CountSortByDigit(int* arr, size_t size, size_t exp){
    int* output = new int[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    delete[] output;
}

void radixSortPositive(int* arr, size_t size){
    if (size <= 1) return;

    int maxVal = MaxInt(arr, size);

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        CountSortByDigit(arr, size, exp);
    }
}

void RadixSort(int* arr, size_t size){
    if (size <= 1) return;

    int negCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) negCount++;
    }
    int posCount = size - negCount;

    int* negatives = new int[negCount];
    int* positives = new int[posCount];

    int negIdx = 0;
    int posIdx = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            negatives[negIdx++] = -arr[i];  
        } else {
            positives[posIdx++] = arr[i];
        }
    }

    if (negCount > 0) {
        radixSortPositive(negatives, negCount);

        for (int i = 0; i < negCount / 2; i++) {
            std::swap(negatives[i], negatives[negCount - 1 - i]);
        }
        for (int i = 0; i < negCount; i++) {
            negatives[i] = -negatives[i];
        }
    }

    if (posCount > 0) {
        radixSortPositive(positives, posCount);
    }

    int idx = 0;
    for (int i = 0; i < negCount; i++) {
        arr[idx++] = negatives[i];
    }
    for (int i = 0; i < posCount; i++) {
        arr[idx++] = positives[i];
    }

    delete[] negatives;
    delete[] positives;
}


void bucketSort(int* arr, size_t size){
    int minVal = MinInt(arr, size);
    int maxVal = MaxInt(arr, size);

    int bucketCount = size;

    int** buckets = new int*[bucketCount];
    int* bucketSizes = new int[bucketCount]();       
    int* bucketCapacity = new int[bucketCount];

    for (int i = 0; i < bucketCount; i++) {
        bucketCapacity[i] = 2;
        buckets[i] = new int[bucketCapacity[i]];
    }

    long long range = static_cast<long long>(maxVal) - minVal + 1;

    for (int i = 0; i < size; i++) {
        
        int idx = static_cast<int>((static_cast<long long>(arr[i] - minVal) * bucketCount) / range);
        if (idx >= bucketCount) idx = bucketCount - 1;

        if (bucketSizes[idx] == bucketCapacity[idx]) {
            bucketCapacity[idx] *= 2;
            int* newBucket = new int[bucketCapacity[idx]];
            for (int j = 0; j < bucketSizes[idx]; j++) {
                newBucket[j] = buckets[idx][j];
            }
            delete[] buckets[idx];
            buckets[idx] = newBucket;
        }

        buckets[idx][bucketSizes[idx]++] = arr[i];
    }

    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 1) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    for (int i = 0; i < bucketCount; i++) {
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucketSizes;
    delete[] bucketCapacity;
}