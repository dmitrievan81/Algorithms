#include <stdio.h>
#include <stdlib.h>

void inputInt(const char* descr_x, int* x){
    printf("Input %s: ", descr_x);
    scanf("%i", x);
}

void inputInt2(const char* descr_x, const char* descr_y, int* x, int* y){
    inputInt(descr_x, x);
    inputInt(descr_y, y);
}

void inputInt3(const char* descr_x, const char* descr_y, const char* descr_z, int* x, int* y, int* z){

    inputInt(descr_x, x);
    inputInt(descr_y, y);
    inputInt(descr_z, z);
}

void inputDouble(const char* descr_x, double* x){
    printf("Input %s: ", descr_x);
    scanf("%lf", x);
}

void inputDouble2(const char* descr_x, const char* descr_y, double* x, double* y){
    inputDouble(descr_x, x);
    inputDouble(descr_y, y);
}

void inputDouble3(const char* descr_x, const char* descr_y, const char* descr_z, double* x, double* y, double* z){

    inputDouble(descr_x, x);
    inputDouble(descr_y, y);
    inputDouble(descr_z, z);
}

