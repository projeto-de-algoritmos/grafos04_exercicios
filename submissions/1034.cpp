#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#define N 1000002

int pd[N];

int blocos(int valores[], int n, int m) {
    int k;
    
    if(m%valores[n-1] == 0) {
        return m/valores[n-1];
    }
    
    memset(pd,999999,sizeof(pd));

    pd[0] = 0;
    
    for(int i=0; i < n; i++){
        k = valores[i];
        for(int j = k; j <= m; j++){
             pd[j] = std::min(pd[j], pd[j-k]+1);
        }
    }
    
    return pd[m];
}

int compara (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int main() {
    int valores[26];
    int t, n, m;
    
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++){
          scanf("%d %d", &n, &m);
          
          for (int j = 0; j < n; j++) {
              scanf("%d", &valores[j]);
          }
          
          qsort(valores, n, sizeof(int), compara);
          printf("%d\n", blocos(valores,n,m));
    }

    return 0;
}