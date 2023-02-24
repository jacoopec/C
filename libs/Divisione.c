int Divisione(int a, int b){
    if(b <= 0 || a < 0){
        return -1;
    } else if (a == 0 && b >= 0){
        return 0;
    } else {
        return (1 + Divisione(a, b-1));
    }
}