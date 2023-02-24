char g;

int main(){
    char *i;
    char h = 0;
    char *u = malloc(1);
    printf("global: %p\n", &g);
    printf("heap:   %p\n", u);
    printf("stack:  %p\n", &h);
    free(u);
   
}