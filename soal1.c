#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[101];
    char kategori[101];
    int tahun;
    int nilai;
} Artefak;

// fungsi pembanding untuk qsort
int compare(const void *a, const void *b) {
    Artefak *x = (Artefak *)a;
    Artefak *y = (Artefak *)b;

    // kategori ascending
    int cmp = strcmp(x->kategori, y->kategori);
    if (cmp != 0) return cmp;

    // tahun ascending
    if (x->tahun != y->tahun)
        return x->tahun - y->tahun;

    // nilai descending
    if (x->nilai != y->nilai)
        return y->nilai - x->nilai;

    // nama ascending
    return strcmp(x->nama, y->nama);
}

int main() {
    int N;
    scanf("%d", &N);

    Artefak arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%s %s %d %d",
              arr[i].nama,
              arr[i].kategori,
              &arr[i].tahun,
              &arr[i].nilai);
    }

    qsort(arr, N, sizeof(Artefak), compare);

    for (int i = 0; i < N; i++) {
        printf("%s %s %d %d\n",
               arr[i].nama,
               arr[i].kategori,
               arr[i].tahun,
               arr[i].nilai);
    }

    return 0;
}
