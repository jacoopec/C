#include "../CHeaders.h"
#include "tailRec.h"

int lungSeq(int seq[10], int index){
    if(index > 1){
        index--;
        return (1+lungSeq(seq,index));
    }else{
        return 1;
    }
}

int minimum(int seq[10], int index, int min){
    if(index > 0){
        index--;
        if(min > seq[index]){min = seq[index];}
        return minimum(seq,index,min);
    }else{
        return min;
    }
}

int sum(int seq[10], int index){
    if(index > 0){
        index--;
        return seq[index] + sum(seq, index);
    } else {
        return 0;
    }
}

int sum2(int n){
    if(n > 0){
        return (n+sum2(n-1));
    } else {
        return 0;
    }
}

int fattoriale(int n){
    if(n >0){
        return n*fattoriale(n-1);
    } else {
        return 1;
    }
}

int mcd(int m, int n){
    if(m == n){
        return m;
    } else if(m > n){
        return mcd(m-n,n);
    } else {
        return mcd(m,n-m);
    }
}

int main(){
    // int array[10] = {1,1,1,1,1,1,1,1,1,1};
    // printf("%i", mcd(40,4));
    printf("%i", tailFactorial(4, 0, 0));

}