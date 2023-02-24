#include "../CHeaders.h"
//calcola tutte le possibili soluzioni
//n scelte da fare, i indice attuale che si sta considerando, k numero possibili risposte per livello
//ad ogni passo si definisce la posizione i del vetttore corrente
//nSol conta il numero totale di soluzioni

void backtrackAll(int n, int i, int k, int vCurr[], int* nSol){
//n indica le n scelte da fare, la lunghezza del vettore corrente, numero livelli albero
//indice attuale, risposta alla domanda i, livello i nell'albero
//i livello generico
//k è il numero delle risposte ad ogni livello
//vcurr è di dimensione n e ad ogni passo si definisce la posizione i di questo vettore. contiene 0 e 1.
//nSol conta il numero totale delle soluzioni
    printf("n:%i, i:%i, k:%i, nSol:%i\n",n, i, k, *nSol);
    int j = 0;
    if(i == n){
        // printf("%d", *nSol);
        (*nSol)++;
        for(int j = 0; j < n; j++){
            printf("\t%d\n", vCurr[j]);
        }
        printf("\n");
        return;
    }
    //questo ciclo viene ripetuto k volte. k è il numero di risposte ad una domanda.
    //la prossima chiamata sistema la posizione i+1.
    //quando i == n si sono termiante le scelte, e si è alle foglie.
    for(; j < k; j++){
        vCurr[i]= j;
        backtrackAll(n, i+1, k, vCurr, nSol);
    }
}
//k numero risposte ad una domanda, ad ogni livello ci sono k figli.
//k nel ciclo for è 2 perchè è binario
//////////////////////////////////////////////////////////////////////////////////////////////////
//tutti i sottoinsiemi di un insieme S di n elementi
void backtrackSubset(int n, int i, int vCurr[], int* nSol){
//la posizione i è la prossima che si definisce
//in vcurr, 1 significa che l'elemento è stato scelto, 0 che non lo è stato.
//k non è più un parametro ma è fisso e vale 2
    if(i == n){
        printf("Sol: %i", *nSol);
        (*nSol)++;
        for(int j = 0; j < n; j++){
            printf("\t%d\n", vCurr[j]);
        }
        printf("\n");
        return;
    }

    for(int j = 0; j < 2; j++){
        printf("livello albero:%i, , j:%i\n", i+1, j);
        vCurr[i]= j;
        //se vcurr[i] = 0 l'elemento non viene preso, se = 1 viene scelto.
        backtrackSubset(n, i+1, vCurr, nSol);
    }
}

void backtrackSubset2(int n, int i, int vCurr[], int* nSol){
    int j;
    if(i == n){
        printf("%d", *nSol);
        (*nSol)++;
        for(int j = 0; j < n; j++){
            printf("%d", vCurr[j]);
        }
        printf("\n");
        return;
    }

    vCurr[i] = 0;
    backtrackSubset2(n, i+1, vCurr, nSol);
    vCurr[i] = 1;
    backtrackSubset2(n, i+1, vCurr, nSol);
    
}
//////////////////////////////////////////////////////////////////////////////////////////////////

//elencare tutti i sottoinsiemi di dimensione k di un insieme S
//
void backtrackSubsetK(int n, int i, int k, int vCurr[], int count, int* nSol){
    int j = 0;
    printf("level: %i, elements to gather: %i, count: %i, j: %i\n", i, k, count, j);
    if(count == k){
        (*nSol)++;
        printf("nSol: %d\n", *nSol);
        for(j = 0; j < n; j++){
            printf("\t%d\n", vCurr[j]);
        }
        // for( j = i; j < n; j++){
        //     printf("0");
        // }
        printf("\n");
        return;
    }
    if(i == n) return;
    //siccome devono essere esplorate entrambe le soluzioni, prima si sceglie 0, poi al ritorno 1
    vCurr[i]= 0;
    printf("Not taking element at level %i\n", i);
    backtrackSubsetK(n, i+1, k, vCurr, count, nSol);
    //se vcurr[i] = 0 l'elemento non viene preso, se = 1 viene scelto.
    vCurr[i]= 1;
    printf("Preso elemento a livello %i\n", i);
    count++;
    backtrackSubsetK(n, i+1, k, vCurr, count, nSol);
    vCurr[i]= 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////

void Permutazioni(int n, int i, int vCurr[],  int* nSol){
    int j = 0,tmp = 0;
    printf("levels: %i, actual: %i\n", n, i);
    if(i == n){
        (*nSol)++;
        printf("nSol: %d\n", *nSol);
        for(j = 0; j < n; j++){
            printf("\tj: %i, vCurr[j]: %d ", j, vCurr[j]);
        }
        printf("\n");
        printf("----------------------------------------------\n");

        return;
    }
    for(j = i; j < n; j++){
        printf("count: %i\n",*nSol);
        printf("Pre-change i: %i, j: %i, vCurr[i]: %i, vCurr[j]: %i\n\n", i, j, vCurr[i], vCurr[j]);
        tmp = vCurr[i]; vCurr[i] = vCurr[j]; vCurr[j] = tmp;  //SCAMBIO
        Permutazioni(n, i+1, vCurr,  nSol);
        tmp = vCurr[i]; vCurr[i] = vCurr[j]; vCurr[j] = tmp;  //RISCAMBIO
        printf("Post-change i: %i, j: %i, vCurr[i]: %i, vCurr[j]: %i\n\n", i, j, vCurr[i], vCurr[j]);
    }
}
//Se l'i-esima componente del vettore vcurr è 1 l'elemento appartiene all'insieme soluzione se è 0 no.
//
void subsetSum(int n, int i, int vCurr[], int w[], int obiettivo, int currentSum, int rimanenza, int* nSol){
    int j,tmp;
    if(i == n) return;
    if(currentSum == obiettivo){
        printf("%d\n", *nSol);
        (*nSol)++;
        for(int j = 0; j < n; j++){
            printf("\t%d\n", vCurr[j]);
        }
        printf("\n");
        return;
    } 

    rimanenza -= w[i];
    if((currentSum + rimanenza >= obiettivo) && (i == n-1 || (i < n-1 && currentSum + w[i+1] <= obiettivo))){
        vCurr[i] = 0;
        subsetSum(n, i+1, vCurr, w, obiettivo, currentSum, rimanenza, nSol);
    }
    if(currentSum + w[i] <= obiettivo){
        vCurr[i] = 1;
        subsetSum(n, i+1, vCurr, w, obiettivo, currentSum + w[i], rimanenza, nSol);
    }
}


int main(){
    int nSol = 0, count = 0, obiettivo = 3, currentSum = 0, rimanenza = 0 ;
    const int n = 2, k = 2, elementi = (k^n + 1);
    int vCurr[5] = {0,0,0,0};
    int w[5] = {1,2,3,4,5};
    // subsetSum( n, 0, vCurr,  w,  obiettivo,  currentSum,  rimanenza,  &nSol);
    // backtrackSubsetK(n, 0, k, vCurr, count, &nSol);  //FUNZIONA
    Permutazioni(n, 0, w,  &nSol);
    // backtrackSubsetK(n, 0, k, vCurr, count, &nSol);
    // backtrackAll(n, 0, k, vCurr, &nSol);
}