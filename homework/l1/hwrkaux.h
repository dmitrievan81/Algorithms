#ifndef HWRKAUX_H
#define HWRKAUX_H

void inputInt(const char* descr_x, int* x);
void inputInt2(const char* descr_x, const char* descr_y, int* x, int* y);
void inputInt3(const char* descr_x, const char* descr_y, const char* descr_z, int* x, int* y, int* z);
void inputInt4(const char* descr_x, const char* descr_y, const char* descr_z, int* x1, int* x2, int* x3, int* x4);

void inputDouble(const char* descr_x, double* x);
void inputDouble2(const char* descr_x, const char* descr_y, double* x, double* y);
void inputDouble3(const char* descr_x, const char* descr_y, const char* descr_z, double* x, double* y, double* z);
#endif 
