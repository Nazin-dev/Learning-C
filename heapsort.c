#include <stdio.h>

void heapficador(int a[], int p, int u) {
    while(p <= u) {
        int f = 2*p + 1;
        if (f <= u) {
            if (f + 1 <= u && a[f + 1] > a[f]) {
                f++;
            }
            if (a[p] < a[f]) {
                int tmp = a[p];
                a[p] = a[f];
                a[f] = tmp;
                p = f;
            } else {
                return;
            }
        } else {
            return;
        }
    }   
}

void heap(int a[], int n) {
    // Fase 1
    for (int i = n / 2; i >= 0; i--) {
        heapficador(a, i, n - 1);
    }
    // Fase 2
    for (int i = n - 1; i > 0; i--) {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        heapficador(a, 0, i - 1);
    }
}

int main() {
    int vet[10] = {  1, 82, 26, 56, 95, 15, 84, 29, 3, 85};

    heap(vet, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d ", vet[i]);
    }
    
    return 0;
}