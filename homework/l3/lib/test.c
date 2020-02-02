//
// Created by Anton on 02.02.2020.
//

#include "test.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hwrklib.h"

int getIDOfOperation(char* NameOfFunction) {

    if (!strcmp(NameOfFunction, "BubbleSortNotOptimized"))
        return 0;
    else if (!strcmp(NameOfFunction,"BubbleSortOptimized"))
        return 1;
    else if (!strcmp(NameOfFunction,"ShakerSort"))
        return 2;
    else if (!strcmp(NameOfFunction, "SelectionSort"))
        return 3;
    else if (!strcmp(NameOfFunction, "InsertionSort"))
        return 4;
    else if (!strcmp(NameOfFunction, "LinearSearch"))
        return 5;
    else if (!strcmp(NameOfFunction, "LinearSearchWithBorder"))
        return 6;
    else if (!strcmp(NameOfFunction, "BinarySearch"))
        return 7;
    else if (!strcmp(NameOfFunction, "InterpolationSearch"))
        return 8;
    else
        return -1;
}

void getTestArray(array* arr)
{
    arr->Size = 4;
    arr->val = (T*) calloc(arr->Size, sizeof(T));
    arr->val[0] = 5;
    arr->val[1] = 3;
    arr->val[2] = 2;
    arr->val[3] = 1;
//    arr->val[4] = 67;
//    arr->val[5] = 4;
//    arr->val[6] = 6;
//    arr->val[7] = 8;
//    arr->val[8] = 7;
//    arr->val[9] = 9;
}

void PrintTest()
{
    int LeftBorderArraySize = 0;
    int RightBorderArraySize = 10000;
    int StepSize = 100;
    int LeftBorderValue = 0;
    int RightBorderValue = 1000000;

    const char* ListOfOperation[] = {
            "BbleNO",
            "Bble",
            "Shkr",
            "Slctn",
            "Insrtn",
            "LnrSrch",
            "LnrSrchWB",
            "BnrSrch",
            "IntrpltnSrch"
    };

    int i = LeftBorderArraySize;
    int NumberOfRows = (RightBorderArraySize - LeftBorderArraySize) / StepSize;
    int NumberOfCols = 9;

    array2 ResultOfTesting;
    getArray2(&ResultOfTesting, NumberOfRows, NumberOfCols);

    for (int NumberOfRow = 0; NumberOfRow < 1; NumberOfRow++){

        int NumberOfColumn = 0;
        array sample;
        int SizeOfArray = LeftBorderArraySize + (NumberOfRow+1)*StepSize;
        //getRandomArray(&sample, SizeOfArray, LeftBorderValue, RightBorderValue);
        getTestArray(&sample);

        array tmp;
        AllocArray(&tmp, &sample, sample.Size);
        int CountOperation = 0;
        // 1. BubbleSortNotOptimized
        //printf("BubbleSortNotOptimized\n");
        //printf(" before BubbleSortNotOptimized\n");
        //printArray(&tmp);
        BubbleSortNotOptimized(&tmp, &CountOperation);
        NumberOfColumn = getIDOfOperation("BubbleSortNotOptimized");
        ResultOfTesting.val[NumberOfRow][NumberOfColumn] = CountOperation;
        //printf(" after BubbleSortNotOptimized\n");
        //printArray(&tmp);
        cpyArray(&tmp, &sample);

        // 2. BubbleSortOptimized
        BubbleSortOptimized(&tmp, &CountOperation);
        NumberOfColumn = getIDOfOperation("BubbleSortOptimized");
        ResultOfTesting.val[i][NumberOfColumn] = CountOperation;
        cpyArray(&tmp, &sample);

        // 3. ShakerSort
        ShakerSort(&tmp, &CountOperation);
        NumberOfColumn = getIDOfOperation("ShakerSort");
        ResultOfTesting.val[NumberOfRow][NumberOfColumn] = CountOperation;
        cpyArray(&tmp, &sample);

        // 4. SelectionSort
        SelectionSort(&tmp, &CountOperation);
        NumberOfColumn = getIDOfOperation("SelectionSort");
        ResultOfTesting.val[NumberOfRow][NumberOfColumn] = CountOperation;
        cpyArray(&tmp, &sample);

        // 5. SelectionSort
        InsertionSort(&tmp, &CountOperation);
        NumberOfColumn = getIDOfOperation("InsertionSort");
        ResultOfTesting.val[NumberOfRow][NumberOfColumn] = CountOperation;
        cpyArray(&tmp, &sample);

        freeArray(&tmp);
        freeArray(&sample);
    }

    for(int i = 0; i < 9; i++)
        printf("%12s", ListOfOperation[i]);

    printf("\n");

    printArray2(&ResultOfTesting);
    freeArray2(&ResultOfTesting);

}
