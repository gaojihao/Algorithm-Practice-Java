//
//  Array.cpp
//  AlgorithmPractice
//
//  Created by lizhi54 on 2018/11/7.
//  Copyright © 2018年 com.lizhi1026. All rights reserved.
//

#include "Array.hpp"

//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数
bool LZArray::bFind(int target, vector<vector<int> > array){
    
    unsigned long height = array.size();
    unsigned long width = array[0].size();
    
    
    unsigned long i = height - 1;
    unsigned long j = 0;
    
    while (i > 0 && j < width) {
        if (target < array[i][j]) {
            i--;
        }else if (target < array[i][j]){
            j++;
        }else {
            return true;
        }
    }
    
    return false;
}

//交换数组中的两个数
void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}


void LZArray::BubbleSort(int *A, const int n){
    
    int left = 0;
    int right = n-1;
    
    while (left < right) {
        
        for (int i = left; i < right; i++) {// 前半轮,将最大元素放到后面
            if (A[i] > A[i+1]) {
                Swap(A, i, i+1);
            }
        }
        
        right--;
        
        for (int i = right; i > left; i--) {// // 后半轮,将最小元素放到前面
            
            if (A[i-1] > A[i]) {
                Swap(A, i-1, i);
            }
        }
        
        left++;
        
    }
}

void LZArray::SelectionSort(int *A, int n){
    for (int i = 0; i < n - 1; i++){// i为已排序序列的末尾
        int min = i;
        
        for (int j = i + 1; j < n; j++) {
            
            if (A[j] < A[min])              //找出未排序序列中的最小值
            {
                min = j;
            }
            
            if (min != i)
            {
                Swap(A, min, i);    //放到已排序序列的末尾，该操作很有可能把稳定性打乱，所以选择排序是不稳定的排序算法
            }
        }
    }
}
