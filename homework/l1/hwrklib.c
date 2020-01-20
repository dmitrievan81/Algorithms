#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <stddef.h>
#include <locale.h>
#include "hwrklib.h"
#include "hwrkaux.h"

int quickPow(int a, int b){
    int n, s, k;
    n = 1;
    s = a;
    k = b;
    while(k!=0){

        if(k%2==0){
            s=s*s;
            k/=2;
        } else{
            n=n*s;
            k--;
        }
    }
    return n;
}

int haveOddInNumber(const int N){
    int isodd, a;
    a=N;
    isodd=0;
    while(a != 0){
        if((a%10)%2==1){
            isodd = 1;
            break;
        }
        a/=10;
    }
}

int numberOfDigits(int a){
    int count=0;
    while(a>0){
        a=a/10;
        count++;
    }
    return count;
}

int div_r(int N, int K, int* q, int* r){
    int c=0;
    if (N<K){
        *q=0;
        *r=N;
    } else if(N==K){
        *q=1;
        *r=0;
    } else{
        int D = N;               
        while(D>K){
            D=D-K;
            c++;
        }
        *q=c;
        *r=N-K*c;
    }
}

int convertDecimal2Binary_r(int n){

    if(n==0)
        return 0;
    else
        return convertDecimal2Binary_r(n/2)*10 + n%2;
}

int convertDecimal2Binary(int n){
   int  result = 0;
    while(n!=0){
        result = result * 10 + n%2;
        n/=2;
    }
    return result;
}

int pow_i(int b, int p){
    int result = 1;
    while(p!=0){
        result*=b;
        p--;
    }
    return result;
}

int pow_i_r(int b, int p){

    if(p==0)
        return 1;
    else
        return b*pow_i_r(b,p-1);
}

int pow_i_rq(int b, int p){

    if(p==0)
        return 1;
    else if(p%2==1)
        return b*pow_i_rq(b,p-1);
    else
        return pow_i_rq(b,p/2)*pow_i_rq(b,p/2);
}

