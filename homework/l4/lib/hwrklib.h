//
// Created by admitriev on 22.01.2020.
//

#ifndef L4_HWRKLIB_H
#define L4_HWRKLIB_H

typedef int T;

typedef struct array2{
    int SizeRows;
    int SizeCols;
    T** val;
} array2;

typedef struct array{int Size; T* val;} array;
typedef struct arrayOfCharString{int Size; char* val;} arrayOfCharString;

void getArray(array*, int);
void getArray2(array2*, int m, int n);
void getRandomArray(array* arr, int n, int min, int max);

void freeArray2(array2*);
void freeArray(array*);
void freearrayOfCharString(arrayOfCharString*);

void printArray2(array2*);
void printArray(array*);
void printfArray(array* arr, char* FileName);

void swap(T* a, T* b);
void cpyArray(array* a, array* b);
void AllocArray(array* newArray, array* InitArray, int Size);

int LinearSearch(array* arr, T SearchValue, int* CountOperation);
int LinearWithBorderSearch(array* arr, T SearchValue, int* CountOperation);
int BinarySearch(array* arr, T SearchValue, int* CountOperation);
int InterpolationSearch(array *arr, int SearchValue, int* CountOperation);

void BubbleSortNotOptimized(array* arr, int* CountOperation);
void BubbleSortOptimized(array* arr, int* CountOperation);
void ShakerSort(array* arr, int* CountOperation);
void SelectionSort(array* arr, int* CountOperation);
void InsertionSort(array* arr, int* CountOperation);

int LCS(array2* lcs, array* x, array* y);

void inputInt(char* str, int* n);
void inputInt2(char* str1, char* str2, int* n1, int* n2);

#endif //L4_HWRKLIB_H
