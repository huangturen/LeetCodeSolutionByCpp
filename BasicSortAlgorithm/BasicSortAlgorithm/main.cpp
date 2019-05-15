//
//  main.cpp
//  BasicSortAlgorithm
//
//  Created by mabaoyan on 2019/5/15.
//  Copyright © 2019 mabaoyan. All rights reserved.
//

#include <iostream>


//冒泡排序
int* BuBBleSort(int arr[], int length){
    if (!arr) {
        return NULL;
    }
    
    if (length < 2) {
        return arr;
    }
    
    for (int i=1; i<length; i++) {
        bool flag = true;
        for (int j=0; j<length-i; j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                flag = false;
            }
        }
        
        if (flag) {
            break;
        }
    }
    return arr;
}

//选择排序
int *selectSort(int arr[], int length){
    if (!arr) {
        return NULL;
    }
    
    if (length < 2) {
        return arr;
    }
    
    for (int i=0; i<length; i++) {
        int minIndex = i;
        for (int j=i; j<length; j++) {
            if (arr[i]>arr[j]) {
                minIndex = j;
            }
        }
        
        if (i != minIndex) {
            int tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
    
    return arr;
}

int* insertSort(int arr[], int length){
    if (!arr) {
        return NULL;
    }
    
    if (length < 2) {
        return arr;
    }
    
    for (int i=1; i<length; i++) {
        int tmp = arr[i];
        int j = i;
        while (j>0 && tmp < arr[j-1]) {
            arr[j] = arr[j-1];
            j--;
        }
        
        if (j != i) {
            arr[j] = tmp;
        }
    }
    return arr;
}

int *shellSort(int arr[], int length){
    if (!arr) {
        return NULL;
    }
    
    if (length < 2) {
        return arr;
    }
    
    int gap = 1;
    
    while (gap < length) {
        gap = gap * 3 + 1;
    }
    
    while (gap > 0) {
        for (int i=gap; i<length; i++) {
            int tmp = arr[i];
            int j = i - gap;
            while (j>=0 && arr[j] > tmp) {
                arr[j+gap] = arr[j];
                j -= gap;
            }
            arr[j+gap] = tmp;
        }
        gap = gap/3;
    }
    
    return arr;
}

int* merge(int left[], int leftLen, int right[], int rightLen){
    int *ret = new int[leftLen + rightLen]();
    int i=0;
    while (leftLen > 0 && rightLen >0) {
        if (left[0] <= right[0]) {
            ret[i++] = left[0];
            left++;
            leftLen--;
        }
        else{
            ret[i++] = right[0];
            right++;
            rightLen--;
        }
    }
    
    while (leftLen > 0) {
        ret[i++] = left[0];
        left++;
        leftLen--;
    }
    
    while (rightLen > 0) {
        ret[i++] = right[0];
        right++;
        rightLen--;
    }
    return ret;
}


int *mergeSort(int arr[], int length){
    if (!arr) {
        return NULL;
    }
    
    if (length < 2) {
        return arr;
    }
    
    int middle = length/2;
    
    int *left = arr;
    int *right = arr+middle;
    
    return merge(mergeSort(left, middle),middle, mergeSort(right, length-middle), length-middle);
}

void swap(int arr[], int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int partition(int arr[], int left, int right){
    int pivot = left;
    int index = pivot + 1;
    for (int i=index; i<=right; i++) {
        if (arr[i] < arr[pivot]) {
            swap(arr, index, i);
            index++;
        }
    }
    swap(arr, pivot, index-1);
    return index-1;
}

int *quickSortRaw(int arr[], int left, int right){
    if (left < right) {
        int partionIndex = partition(arr, left, right);
        quickSortRaw(arr, left, partionIndex-1);
        quickSortRaw(arr, partionIndex+1, right);
    }
    return arr;
}

int *quickSort(int arr[], int length){
    return quickSortRaw(arr, 0, length-1);
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a[] = {5,3,4,2,6};
    int a1[] = {5,3,4,2,6};
    int a2[] = {5,3,4,2,6};
    int a3[] = {5,3,4,2,6,1,7,5,4,3,8,10,9,20};
    int a4[] = {5,3,4,2,6,1,7,5,4,3,8,10,9,20};
    int a5[] = {5,3,4,2,6,1,7,5,4,3,8,10,9,20};

    int *retBuBBle = BuBBleSort(a, 5);
    int *retSelect = selectSort(a1, 5);
    int *retInsert = insertSort(a2, 5);
    int *retshell = shellSort(a3, 14);
    int *retMerge = mergeSort(a4, 14);
    int *retQuick = quickSort(a5, 14);

    for (int i=0; i<5; i++) {
        printf("%d,%d,%d\n",retBuBBle[i], retSelect[i],retInsert[i]);
    }
    printf("#-------------------------#\n");
    for (int i=0; i<14; i++) {
        printf("%d,%d,%d\n",retshell[i],retMerge[i],retQuick[i]);
    }
    std::cout << "Hello, World!\n";
    return 0;
}
