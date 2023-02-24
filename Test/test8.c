#include "../CHeaders.h"

typedef void*(*malloc_like_func)(size_t);
typedef void*(*free_like_func)(void*);

static malloc_like_func sysmalloc = NULL;
static free_like_func sysfree = NULL;

void* malloc(size_t size){
    void* result = sysmalloc(size);
    return result;
}

void free(void* p){
    sysfree(p);
}

int main(){

}