#include "../CHeaders.h"

static int MinimoRec(int* v, int v_size, int i){
    if(v_size-1 == i){
        return v[i];
    }
    int min = MinimoRec(v, v_size, i+1);
    if(v[i] < min){
        return v[i];
    } else {
        return min;
    }
}

int Minimo(int* v, int v_size){
    return MinimoRec(v, v_size, 0);
}

int Minimo2(int* v, int v_size){
    // printf("vsize: %i\n",v_size);
    if(v_size > 1){
        int* p = v + 1;
        printf("p: %i size -1: %i, m: %i\n", *p, v_size-1);
        int m = Minimo2(p, v_size-1);
        printf("v: %i size: %i, m: %i\n", *v, v_size, m);
        if(m > *v){
            printf("*v\n");
            return *v;
        } else {
            printf("m\n");
            return m;
        }
    } else {
        printf("*v2: %i\n", *v);
        return *v;
    }
}
