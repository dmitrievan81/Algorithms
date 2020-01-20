#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <stddef.h>
#include <locale.h>
#include "hwrkaux.h"
#include "hwrklib.h"

void menu();

void task1();
void task2();
void task3();
void task4();

int main(){

    setlocale(LC_ALL, "ru_RU.utf8");

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

}

void menu(){

    printf("0-exit\n");
    printf("1-task 1 Convert decimal to binary using recursion.\n");
    printf("2-task 2 a) Raise to power number not using recurtion. \n");
    printf("3-task 2 b) Raise to power number using recurtion.\n");
    printf("4-task 2 c) Raise to power number using the parity property.\n");
    //printf("5-task 3 a)--\n");
    //printf("6-task 3 b)\n");
}

void task1(){
    
    int x, res;
    inputInt("x", &x);
    res = convertDecimal2Binary_r(x);
    printf("%i_2 = %i", x, res);
}

void task2(){
    
    int x,y, res;
    inputInt("x (base)", &x);
    inputInt("y (power)",&y);
    res = pow_i(x, y);
    printf("pow(%i,%i) = %i", x, y, res);
}

void task3(){
    
    int x,y, res;
    inputInt("x (base)", &x);
    inputInt("y (power)",&y);
    res = pow_i_r(x, y);
    printf("pow(%i,%i) = %i", x, y, res);
}

void task4(){
    
    int x,y, res;
    inputInt("x (base)", &x);
    inputInt("y (power)", &y);
    res = pow_i_rq(x, y);
    printf("pow(%i,%i) = %i", x, y, res);
}









