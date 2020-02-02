//
// Created by admitriev on 22.01.2020.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "hwrklib.h"

int getRandomNumber(int min, int max)
{
    int max_range = max-min+1;
    int result = (rand() % (max_range)) + min;
    return result;
}

void getArray(array* arr, int n){

    arr->Size = n;
    arr->val = (T*)calloc(arr->Size, sizeof(T));

}

void freeArray(array* arr){
    if(!arr->val)
        free(arr->val);
}

void freeHeaderOfTable(arrayOfCharString* header){
    free(header->val);
}

void printArray(array* arr){
    for(int i=0; i<arr->Size; i++){
        printf("%12i\n", arr->val[i]);
    }
}

void printfArray(array* arr, char* FileName)
{
    FILE* p = fopen(FileName, "w");

    if (!p)
        return;
    for(int i = 0; i < arr->Size; i++);
        ///fprintf("%i", arr->val[i]);
    fclose(p);

}

void getArray2(array2* arr, int SizeRows, int SizeCols){
    arr->SizeRows = SizeRows;
    arr->SizeCols = SizeCols;
    arr->val = (T**)malloc(sizeof(T)*arr->SizeRows*arr->SizeCols);
    for(int i=0; i<arr->SizeRows; i++){
        arr->val[i] = (T*)malloc(sizeof(T)*arr->SizeCols);
        for(int j=0;j<SizeCols;j++)
            arr->val[i][j]=0;
    }
}

void freeArray2(array2* arr){
    if(!arr->val) {
        for (int i = 0; i < arr->SizeRows; i++) {
            if (!arr->val[i])
                free(arr->val[i]);
        }
        free(arr->val);
    }
}

void printArray2(array2* arr){

    for(int i = 0; i < arr->SizeRows; i++){
        for(int j = 0; j < arr->SizeCols; j++){
            printf("%12i", arr->val[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void getRandomArray(array* arr, int n, T min, T max){

    getArray(arr, n);

    arr->Size = n;
    for(int i=0; i<arr->Size; i++)
        arr->val[i] = getRandomNumber(min, max);
}

void swap(T* a, T* b){
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

void cpyArray(array* a, array* b) {
    for (int i = 0; i < a->Size; i++)
        a->val[i] = b->val[i];
}

void AllocArray(array* newArray, array* InitArray, int Size) {
    int RightBorder = (Size < InitArray->Size) ? Size: InitArray->Size;
    newArray->Size = Size;
    newArray->val = (T*) calloc(Size, sizeof(T));
    for(int i = 0; i < RightBorder; i++)
        newArray->val[i] = InitArray->val[i];
}

int LinearSearch(array* arr, T SearchValue, int* CountOperation){

    int LeftBorderArray = 0;
    int RightBorderArray = arr->Size - 1;

    int i = 0;
    for(int i = LeftBorderArray; i < RightBorderArray + 1  && arr->val[i] != SearchValue; i++)
        (*CountOperation)++;
    return  (i != RightBorderArray + 1) ? i : -1;
}

int LinearWithBorderSearch(array* arr, T SearchValue, int* CountOperation)
{
    array tmp;
    tmp.Size = arr->Size + 1;
    tmp.val = (T *) calloc(tmp.Size, sizeof(T));
    tmp.Size = tmp.Size;
    cpyArray(&tmp, arr);
    tmp.val[tmp.Size] = SearchValue;

    int isFound = 0;
    int LeftBorderArray = 0;

    int i=0;
    for(int i = LeftBorderArray; arr->val[i] != SearchValue; i++)
        (*CountOperation)++;

    return (i != arr->Size)? i : -1;
}

int BinarySearch(array* arr, T SearchValue, int* CountOperation)
{
    int isFound = 0;
    int LeftBorderArray = 0;
    int RightBorderArray = arr->Size - 1;

    int MiddleBorderArray = LeftBorderArray + (RightBorderArray - LeftBorderArray) / 2;

    while(LeftBorderArray <= RightBorderArray
        && arr->val[MiddleBorderArray] != SearchValue) {
        (*CountOperation)++;
        if (arr->val[MiddleBorderArray] < SearchValue)
            LeftBorderArray = MiddleBorderArray + 1;
        else
            RightBorderArray = MiddleBorderArray - 1;

        MiddleBorderArray = LeftBorderArray + (RightBorderArray - LeftBorderArray) / 2;
    }
    return (arr->val[MiddleBorderArray] == SearchValue) ? MiddleBorderArray : -1;
}

int InterpolationSearch(array *arr, int SearchValue, int* CountOperation)
{
    int isFound = 0;
    int LeftBorderArray = 0;
    int RightBorderArray = arr->Size - 1;

    if (arr->val[LeftBorderArray] > SearchValue || arr->val[RightBorderArray] < SearchValue)
        return -1;

    while (LeftBorderArray <= RightBorderArray)
    {
        int MiddleBorderArray = LeftBorderArray + (RightBorderArray - LeftBorderArray) * (SearchValue - arr->val[LeftBorderArray]) / (arr->val[RightBorderArray] - arr->val[LeftBorderArray]);
        if (arr->val[MiddleBorderArray] == SearchValue) {
            (*CountOperation)++;
            return MiddleBorderArray;
            break;
        } else if (arr->val[MiddleBorderArray] < SearchValue) {
            (*CountOperation)++;
            LeftBorderArray = MiddleBorderArray + 1;
        }
        else if (arr->val[MiddleBorderArray] > SearchValue) {
            RightBorderArray = MiddleBorderArray - 1;
            (*CountOperation)++;
        }
        (*CountOperation)++;
    }
    return -1;
}

void BubbleSortNotOptimized(array* arr, int* CountOperation) {

    int MinIndex = 0;
    int MaxIndex = arr->Size-1;

    for(int i = MinIndex; i < MaxIndex; i++){
        for(int j = MinIndex; j < MaxIndex - i; j ++ )
        {
            if(arr->val[j]>arr->val[j+1]){
                swap(&arr->val[j],&arr->val[j+1]);
                (*CountOperation)++;
            }
            (*CountOperation)++;
        }
    }
}

void BubbleSortOptimized(array* arr, int* CountOperation) {

    int MinIndex = 0;
    int MaxIndex = arr->Size-1;

    for(int i = MinIndex; i < MaxIndex; i++) {
        int IsItSorted = 1;
        for(int j = MinIndex; j < MaxIndex - i; j ++ ) {
            (*CountOperation)++;
            if (arr->val[j] > arr->val[j + 1]) {
                swap(&arr->val[j], &arr->val[j + 1]);
                IsItSorted = 0;
                (*CountOperation)++;
            }
        }
        if (IsItSorted) {
            (*CountOperation)++;
            break;
        }
    }
}

void ShakerSort(array* arr, int* CountOperation) {

    int LeftBorder = 0;
    int RightBorder = arr->Size - 1;

    while(LeftBorder < RightBorder) {
        
        int IsItSorted = 1;

        for(int idx_j = LeftBorder; idx_j < RightBorder; idx_j ++ ) {
            (*CountOperation)++;
            if (arr->val[idx_j] > arr->val[idx_j + 1]) {
                swap(&arr->val[idx_j], &arr->val[idx_j + 1]);
                IsItSorted = 0;
                (*CountOperation)++;
            }
        }
        
        if (IsItSorted) {
            (*CountOperation)++;
            break;
        }

        RightBorder--;

        for(int idx_k = RightBorder; idx_k > LeftBorder; idx_k-- ) {
            (*CountOperation)++;
            if (arr->val[idx_k] < arr->val[idx_k - 1]) {
                swap(&arr->val[idx_k], &arr->val[idx_k - 1]);
                IsItSorted = 0;
                (*CountOperation)++;
            }
        }

        LeftBorder++;

        if (IsItSorted) {
            (*CountOperation)++;
            break;
        }

    }
}

void SelectionSort(array* arr, int* CountOperation) {

    int LeftBorder = 0;
    int RightBorder = arr->Size;

    for(int idx_i = LeftBorder; idx_i < RightBorder; idx_i++){
        int idx_min = idx_i;
        for(int idx_j = idx_i + 1; idx_j < RightBorder; idx_j++) {
            if (arr->val[idx_j] < arr->val[idx_min]) {
                idx_min = idx_j;
                (*CountOperation)++;
            }
        }
        if(idx_min != idx_i){
            swap(&arr->val[idx_min], &arr->val[idx_i]);
            (*CountOperation)++;
        }
    }
}

void InsertionSort(array* arr, int* CountOperation) {

    int LeftBorderArray = 0;
    int RightBorderArray = arr->Size;

    for(int idx_i = LeftBorderArray; idx_i < RightBorderArray; idx_i++){
        int idx_j = idx_i;
        T tmp = arr->val[idx_i];
        while(idx_j > 0 && arr->val[idx_j-1] > tmp) {
            swap(&arr->val[idx_j], &arr->val[idx_j-1]);
            (*CountOperation)++;
            (*CountOperation)++;
        }
    }
}

// lcs->SizeRow == x->Size + 1; lcs->SizeCol == y->Size + 1;
int LCS(array2* lcs, array* x, array* y)
{
    int m = x->Size;
    int n = y->Size;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(x->val[i-1] == y->val[j-1]) {
                lcs->val[i][j] = lcs->val[i-1][j-1] + 1;
            } else {
                if (lcs->val[i - 1][j] >= lcs->val[i][j - 1])
                    lcs->val[i][j] = lcs->val[i - 1][j];
                else
                    lcs->val[i][j] = lcs->val[i][j-1];
            }
        }
    }
    return lcs->val[m][n];
}

void inputInt(char* str, int* n){
    printf("Input %s : ", str);
    scanf("%i");
}

void inputInt2(char* str1, char* str2, int* n1, int* n2){
    printf("Input %s : ", str1);
    scanf("%i");
    printf("Input %s : ", str2);
    scanf("%i");
}

void inputDouble(char* str, double* d){
    printf("Input %lf : ", str);
    scanf("%lf");
}

void inputDouble2(char* str1, char* str2, double* n1, double* n2){
    printf("Input %lf : ", str1);
    scanf("%lf");
    printf("Input %lf : ", str2);
    scanf("%lf");
}
