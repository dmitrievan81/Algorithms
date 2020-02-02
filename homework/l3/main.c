#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/hwrklib.h"
#include "lib/test.h"
#include <locale.h>

void menu(){

    printf("0-Exit\n");
    printf("1-task 1 Comparision of buble sort (optimized and not optimized)\n");
    printf("2-task 2 Shaker sort\n");
    printf("3-task 3 Binary search\n");
    printf("4-task 4 Searche's test\n");
}

void task3submenu1()
{
    printf("Enter: ");
    printf("0 - Exit\n");
    printf("1 - A new search value\n");
    printf("2 - Print sorted array\n");
}

void task3Submenu1_point1(array* sample) {
    printf("Enter a new search value:");
    T SearchValue = 0;
    int CountOpeeration = 0;
    scanf("%i", &SearchValue);

    int Index = BinarySearch(sample, SearchValue, &CountOpeeration);
    if(Index == -1){
        printf("Value not fount\n");
        printf("Number of operation %i\n", CountOpeeration);
    } else {
        printf("Inded of founded value is %i\n", Index);
        printf("Number of operation %i\n", CountOpeeration);
    }

}

void task3Submenu1_point2(array* sample) {
    printArray(sample);
}

void task1(){

    array sample;
    getRandomArray(&sample, 10, 1, 100);
    array tmp;
    AllocArray(&tmp, &sample, sample.Size);
    printf("before \n");
    printArray(&tmp);

    int CountOperationBblsrtNO = 0;
    // 1. BubbleSortNotOptimized
    printf("BubbleSortNotOptimized\n");
    BubbleSortNotOptimized(&tmp, &CountOperationBblsrtNO);
    printf("after BubbleSortNotOptimized\n");
    printArray(&tmp);
    cpyArray(&tmp, &sample);

    int CountOperationBblsrt = 0;
    // 2. BubbleSortOptimized
    printf("BubbleSortOptimized\n");
    BubbleSortOptimized(&tmp, &CountOperationBblsrt);
    printf("after BubbleSortOptimized\n");
    printArray(&tmp);
    cpyArray(&tmp, &sample);
    freeArray(&tmp);
    freeArray(&sample);

    printf("Number of operations not optimized sorting  : %i\n", CountOperationBblsrtNO);
    printf("Number of operations optimized sorting: %i\n", CountOperationBblsrt);
}

void task2(){

    // Два массива только для унификации
    array sample;
    getRandomArray(&sample, 10, 1, 100);
    array tmp;
    AllocArray(&tmp, &sample, sample.Size);
    printf("before \n");
    printArray(&tmp);

    int CountShkrSrt = 0;
    // 1. ShakerSort
    printf("ShakerSort\n");
    ShakerSort(&tmp, &CountShkrSrt);
    printf("after ShakerSort\n");
    printArray(&tmp);
    cpyArray(&tmp, &sample);
    printf("Number of operations: %i\n", CountShkrSrt);
    freeArray(&tmp);
    freeArray(&sample);
}

void task3(){

    // Два массива только для унификации
    array sample;
    getRandomArray(&sample, 10, 1, 100);
    array tmp;
    AllocArray(&tmp, &sample, sample.Size);
    printf("before \n");
    printArray(&tmp);

    int CountShkrSrt = 0;
    // 1. ShakerSort
    printf("ShakerSort\n");
    ShakerSort(&tmp, &CountShkrSrt);
    printf("after ShakerSort\n");
    printArray(&tmp);
    printf("Number of operations: %i\n", CountShkrSrt);
    freeArray(&sample);
    int sel = 0;
    do {
        task3submenu1();
        scanf("%i", &sel);
        switch (sel) {
            case 1:
                task3Submenu1_point1(&tmp);
                break;
            case 2:
                task3Submenu1_point2(&tmp);
                break;
            case 0:
                break;
            default:
                printf("Wrong selected\n");

        }
    }while(sel!=0);
}

void task4(){
    PrintTest();
}

int main() {

    srand(time(NULL));
    setlocale (LC_ALL, "С");

    int sel = 0;
    do{
        printf("\n\n");

        menu();
        scanf("%i", &sel);
        switch(sel)
        {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 0:
                printf("Bye-bye\n");
                break;
            default:
                printf("Wrong selected\n");
        }
    }while(sel!=0);
    return 0;

    printf("Hello, World!\n");
    return 0;
}
