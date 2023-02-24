//la ricorsione tail da luogo a un processo computazionale di tipo iterativo, computa in avnati e non richiede di 
//conservare lo stato. L'occupazione di memoria è la stessa di un ciclo che faccia la stessa computazione, non c'è
//bisogno di allocare nuova memoria per i parametri di ogni chiamata.
//portare l'operazione all'interno della prossima chiamata e aggiungere una variabile di stato.

int tailFactorial(int n, int res){
    if(n == 1){
        return res;
    } else {
        return tailFactorial(n-1, res*n);
    } 
}

int tailSum(int n,int res){
    if(n == 1){
        return res + n;
    } else {
        return tailSum(n-1, res+n);
    }
}