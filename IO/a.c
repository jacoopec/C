#include "../CHeaders.h"



int main(){
    int result;
    const char* path = "text3.txt";
    char *phrase = "mit skifahren";
    FILE *f = fopen(path, "w");
    int c = 532, i =320;
    double d = 0.00000005462564563;
    printf("writing:\n");
    fprintf(stdout, "something\n");
    fprintf(stdout, "ottale %#o %o\n", i, c);
    fprintf(stdout, "esadecimale %#x %X\n", i, c);
    fprintf(stdout, "double %.8f %le %e\n", d, d, d);

    fclose(f);
}