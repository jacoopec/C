int Prodotto(int a, int b){
    while(b > 0){
        return (a + Prodotto(a, b-1));
    }
    return 0;
}