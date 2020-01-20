#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <stddef.h>
#include <locale.h>
#include "hwrkaux.h"
#include "hwrklib.h"

struct ChessPoint {int x; int y; int collor;}; 

void menu();
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();
void task10();
void task11();
void task12();
void task13();
void task14();
void task15();
void task16();

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
            case 5:
                task5();
                break;
            case 6:
                task6();
                break;
            case 7:
                task7();
                break;
            case 8:
                task8();
                break;
            case 9:
                task9();
                break;
            case 10:
                task10();
                break;
            case 11:
                task11();
                break;
            case 12:
                task12();
                break;
            case 13:
                task13();
                break;
            case 14:
                task14();
                break;
            case 15:
                task15();
                break;
            case 16:
                task16();
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

void task1(){
    int weight;
    int height;
    double l;
    inputInt2("weight(kg)","height(m)", &weight, &height);
    double result = weight*weight/height;
    printf("Your BMI is: %g\n", result);
}
void task2(){

    double x1, x2, x3, x4;

    inputDouble2("x1", "x2", &x1, &x2);
    inputDouble2("x3", "x4", &x3, &x4);
    double xl = (x1>x2)?x1:x2;
    double xr = (x3>x4)?x3:x4;
    printf("max(%lf,%lf,%lf,%lf)=%lf\n", x1,x2,x3,x4, (xl>xr)?xl:xr);

}
void task3(){

    double x1, x2, x3;
    inputDouble2("x1", "x2", &x1, &x2);
    x3=x1;
    x2=x1;
    x1=x2;
    printf("x1=%lf, x2=%lf\n", x1, x2);

}

void task4(){
    double x1, x2, x3;

    inputDouble2("x1", "x2", &x1, &x2);
    scanf("%lf",&x2);

    x3=x2;
    x2=x1;
    x1=x3;
    printf("x1=%lf, x2=%lf\n", x1, x2);

}
void task5(){

    double a, b, c, d, x1, x2;

    inputDouble3("a","b","c", &a, &b, &c);

    if(a==0 && b==0){
        printf("There's not any roots!");
    }
    else if(a==0 && b!=0){
        printf("x=%lf", -c/b);
    }
    else if(a!=0 && b==0 && c==0){
        printf("x=%lf", 0.0);
    }
    else if(a!=0 && b!=0 && c==0){
        printf("x1=%lf, x2=%lf", 0.0, -b);
    }
    else if(a!=0 && b==0 && c!=0){
        double x = -c/a;
        if(x>0){
            x = sqrt(x);
            printf("x1=%lf, x2=%lf", x, -x);
        }else{
            printf("Ther is not any roots in R area");
        }
    }
    else if(a!=0 && b!=0 && c!=0){

        d = b*b - 4*a*c;

        if (d > 0){
            x1 = (-b + sqrt(d))/(2*a);
            x2 = (-b - sqrt(d))/(2*a);
            printf("x1=%lf, x2=%lf\n", x1, x2);
        }else if(d ==0){
            printf("x1=%lf\n", -b/2*a);
        }else{
            printf("Discriminant < 0. There are not roots in R");
        }
    }
}
void task6(){

    int numberOfMonth;
    char* seasons[4] = {"Winter", "Spring", "Summer", "Autumn"};
    inputInt("number of month", &numberOfMonth); 
    printf("The season is: %s\n", seasons[numberOfMonth%4]);

}
void task7(){

    int age;
    printf("Введите важ возраст от 1 до 150: ");
    scanf("%i", &age);
    char* year[3] ={"год", "года", "лет"};
    int num = 0; 

    if(age == 1)
        num = 0;
    else if(age >= 2 && age <= 4)
        num = 1;
    else
        num = 2;

    printf("Человекочитаемый возраст: %i %s\n", age, year[num]);

}

void SetCollorForChessSquare(struct ChessPoint p){

    p.collor = (p.x%2==0)?p.y%2:1-p.y%2;
}

void task8(){


    struct ChessPoint p1;
    struct ChessPoint p2;
    inputInt2("p1.x", "p1.y", &p1.x, &p1.y);
    inputInt2("p2.x", "p2.y", &p2.x, &p2.y);
    SetCollorForChessSquare(p1);
    SetCollorForChessSquare(p2);
    printf("The collor of p1 is: %s\n", (p1.collor==0)?"Black":"white");
    printf("The collor of p2 is: %s\n", (p2.collor==0)?"Black":"white");

    if(p1.collor == p2.collor)
        printf("The chess point's collor is equal\n");
    else
        printf("The cehss point's collor isn't equal\n");

}
void task9(){
    int a,b;
    inputInt2("a","b", &a, &b);
    for(int i=a; i<=b; i++){
        printf("%i^2 = %i; ", i, pow_i_rq(i,2));
    }
    printf("\n");
    for(int i=a; i<=b; i++){
        printf("%i^3 = %i; ", i, pow_i_rq(i,3));
    }
    printf("\n");
}

void task10(){

    int N, K, D, q, r;
    inputInt2("N","K", &N, &K);
    div_r(N, K, &q, &r);
    printf("%i=%i*%i+%i\n", N, K, q, r);
}

void task11(){

    int n;
    inputInt("n", &n);
    if(haveOddInNumber(n))
        printf("True\n");
    else
        printf("False\n");
}

void task12(){
    int sum, n, x, q, r, sel;
    n=0;
    do{
        inputInt("x", &x);
        div_r(x, 10, &q, &r);
        if(x > 0 && r == 8){
            sum += x;
            n++;
        }
    }while(x!=0);
    printf("avrg=%d\n", sum/n);

}

void task13(){
    int a, b, c;
    inputInt3("a", "b", "c", &a, &b, &c);

    int max =  (((a>b)?a:b)<c)?c:((a>b)?a:b);
    printf("Max(%i, %i, %i) = %i", a, b, c, max);

}

void task14(){

}

void task15(){

}

void task16(){

    int a, a1, n;

    inputInt("a", &a);
    for(int i = 1; i < a; i++){
        a1 = i*i;
        n = numberOfDigits(i);
        if(i==(a1%(quickPow(10,n))))
           printf("%i^2 = %i\n",i, a1);
    }
}


void menu(){


    printf("0-exit\n");
    printf("1-task 1 (BMI)\n");
    printf("2-task 2 (max of 4th numbers)\n");
    printf("3-task 3 (swap with tmp)\n");
    printf("4-task 4 (swap without tmp)\n");
    printf("5-task 5 (a*x**2+b*x+c=0)\n");
    printf("6-task 6 (get season)\n");
    printf("7-task 7 (get a human (from 1 to 150 year) readable designation of year)\n");
    printf("8-task 8 (get a collor of chess square)\n");
    printf("9-task 9 (get a x**2, x**3, where is x in [a,b])\n");
    printf("10-task 10 (get a quatient and rest (q,r): a = b*q + r )\n");
    printf("11-task 11 (find out if there are odd numbers in number)\n");
    printf("12-task 12 (get an average numbers ending in 8)\n");
    printf("13-task 13 (max(x1,x2,x3))\n");
    printf("14-task 14 (not relized)(rand(1,100) with standart function rand())\n");
    printf("15-task 15 (not realized)(rand(1,100) without standart function rand())\n");
    printf("16-task 16 automorphic numbers\n");

}
