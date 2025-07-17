/*
Nama        : Zelda Keyzia Nauli Br Sianipar
NIM         : 43324020
Prodi       : D3 Teknologi Komputer
Program     : Modifikasi program Insertion 
*/

void tampilkanArray(int array[], int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertionSort(int array[], int ukuran) {
    int i, j, kunci;
    
    for (i = 1; i < ukuran; i++) {
        kunci = array[i]; 
        j = i - 1; 

        while (j >= 0 && array[j] > kunci) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        
        array[j + 1] = kunci;

        printf("Pass-%d: ", i);
        tampilkanArray(array, ukuran);
    }
}

void masukkanArray(int array[], int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        scanf("%d", &array[i]);
    }
}

int main() {
    int Nama[100]; 
    int NIM;

    printf("Masukkan jumlah siswa: ");
    scanf("%d", &NIM);

    printf("Masukkan %d elemen Nama: ", NIM);
    masukkanArray(Nama, NIM);

    printf("Urutan Asli: ");
    tampilkanArray(Nama, NIM);

    printf("Diurutkan menggunakan Insertion Sort:\n");
    insertionSort(Nama, NIM);

    return 0;
}