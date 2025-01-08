#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Untuk fungsi strcspn

struct mahasiswa {
    int nrp;
    char nama[50];
    int tugas;
    int uts;
    int uas;
    int nilaiAkhir;
    char grade;
} data_mhs[30];

void inputDataMhs(struct mahasiswa *data_mhs, int jmlMhs) {
    for (int i = 0; i < jmlMhs; i++) {
        printf("Mahasiswa ke-%d\n", i + 1);
        printf("NRP\t\t: ");
        scanf("%d", &data_mhs[i].nrp);
        fflush(stdin);

        printf("Nama\t\t: ");
        // Menggunakan fgets untuk menghindari penggunaan gets yang tidak aman
        fgets(data_mhs[i].nama, sizeof(data_mhs[i].nama), stdin);
        
        // Menghapus karakter newline yang mungkin muncul setelah input nama
        data_mhs[i].nama[strcspn(data_mhs[i].nama, "\n")] = '\0';

        printf("Nilai tugas\t: ");
        scanf("%d", &data_mhs[i].tugas);

        printf("Nilai UTS\t: ");
        scanf("%d", &data_mhs[i].uts);

        printf("Nilai UAS\t: ");
        scanf("%d", &data_mhs[i].uas);
        fflush(stdin);
        printf("\n\n");
    }
}

void gradeMhs(struct mahasiswa *data_mhs, int jmlMhs) {
    for (int i = 0; i < jmlMhs; i++) {
        data_mhs[i].nilaiAkhir = (data_mhs[i].tugas * 0.2) + (data_mhs[i].uts * 0.4) + (data_mhs[i].uas * 0.4);
        if (data_mhs[i].nilaiAkhir >= 80)
            data_mhs[i].grade = 'A';
        else if (data_mhs[i].nilaiAkhir >= 70)
            data_mhs[i].grade = 'B';
        else if (data_mhs[i].nilaiAkhir >= 60)
            data_mhs[i].grade = 'C';
        else if (data_mhs[i].nilaiAkhir >= 50)
            data_mhs[i].grade = 'D';
        else
            data_mhs[i].grade = 'E';
    }
}

int main() {
    int jmlMhs;
    printf("MENGHITUNG NILAI AKHIR\nMATA KULIAH KONSEP PEMROGRAMAN\n\n");
    printf("Berapa jumlah Mahasiswa? ");
    scanf("%d", &jmlMhs);

    printf("Masukkan data Mahasiswa\n\n");
    inputDataMhs(data_mhs, jmlMhs);
    gradeMhs(data_mhs, jmlMhs);
    printf("%c", data_mhs[0].grade);

    printf("\t\t\t\t\tDAFTAR NILAI\n\t\t\tMATA KULIAH KONSEP PEMROGRAMAN\n");
    printf("------------------------------------------------------------------------------------\n");
    printf("%-5s %-10s %-30s %-10s %-10s %-10s %-10s %-5s\n", "No", "NRP", "Nama Mahasiswa", "Tugas", "UTS", "UAS", "Akhir", "Grade");
    printf("------------------------------------------------------------------------------------\n");
    for (int i = 0; i < jmlMhs; i++) {
        printf("%-5d %-10d %-30s ", i + 1, data_mhs[i].nrp, data_mhs[i].nama);
        printf("%-10d %-10d %-10d ", data_mhs[i].tugas, data_mhs[i].uts, data_mhs[i].uas);
        printf("%-10d %-5c\n", data_mhs[i].nilaiAkhir, data_mhs[i].grade);
    }
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("Total Mahasiswa = %d", jmlMhs);

    return 0;
}
