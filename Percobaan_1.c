#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Untuk fungsi strlen dan strtok

// Struktur untuk menyimpan informasi produk
struct produk {
    char kode;        // Kode untuk ukuran produk (S, M, L)
    char jenis[10];   // Jenis produk (Small, Medium, Large)
    int hrg_produk;   // Harga produk
};

// Struktur untuk menyimpan informasi pesanan
struct pesanan {
    char kode;        // Kode ukuran produk yang dipesan
    int jml;          // Jumlah produk yang dipesan
    int hrg_pesan;    // Total harga untuk pesanan tersebut
};

// Struktur mahasiswa untuk menghitung nilai akhir dan grade
struct mahasiswa {
    int nrp;          // NRP mahasiswa
    char nama[30];    // Nama mahasiswa
    int tugas;        // Nilai tugas
    int uts;          // Nilai UTS
    int uas;          // Nilai UAS
    int nilaiAkhir;   // Nilai akhir mahasiswa
    char grade;       // Grade mahasiswa
};

// Daftar produk yang tersedia
struct produk produk[3] = {{'S', "Small", 36000}, {'M', "Medium", 43000}, {'L', "Large", 62000}};

// Fungsi untuk menghitung harga pesanan berdasarkan jenis produk dan jumlah
int hitungHargaPesan(char jenis, int jmlOrder) {
    for (int i = 0; i < 3; i++) {
        if (produk[i].kode == jenis) {
            return produk[i].hrg_produk * jmlOrder;  // Mengembalikan total harga
        }
    }
    return 0;  // Jika jenis produk tidak ditemukan
}

// Fungsi untuk memasukkan data pesanan
void inputOrder(struct pesanan *pesan, int *numOrder) {
    char lanjut = 'y';  // Variabel untuk memeriksa apakah pelanggan ingin melanjutkan pesanan

    do {
        printf("Pesanan ke-%d\n", *numOrder + 1);

        fflush(stdin);

        // Memasukkan jenis produk yang dipesan
        printf("Ukuran [S/M/L]: ");
        scanf("%c", &pesan[*numOrder].kode);
        fflush(stdin);

        // Memasukkan jumlah produk yang dipesan
        printf("Jumlah: ");
        scanf("%d", &pesan[*numOrder].jml);

        // Menghitung total harga pesanan
        pesan[*numOrder].hrg_pesan = hitungHargaPesan(pesan[*numOrder].kode, pesan[*numOrder].jml);
        
        (*numOrder)++;  // Menambah nomor pesanan

        // Menanyakan apakah pelanggan ingin memesan lagi
        printf("Ada lagi (y/t)? ");
        scanf(" %c", &lanjut);  // Perhatikan spasi sebelum %c untuk mengatasi bug dengan input
    } while (lanjut == 'y' || lanjut == 'Y');  // Loop berlanjut jika jawaban 'Y' atau 'y'
}

// Fungsi untuk menghitung grade mahasiswa berdasarkan nilai akhir
void gradeMhs(struct mahasiswa *data_mhs, int jmlMhs) {
    for (int i = 0; i < jmlMhs; i++) {
        data_mhs[i].nilaiAkhir = (data_mhs[i].tugas * 0.2) + (data_mhs[i].uts * 0.4) + (data_mhs[i].uas * 0.4);
        
        // Menentukan grade berdasarkan nilai akhir
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

// Fungsi untuk memasukkan data mahasiswa
void inputDataMhs(struct mahasiswa *data_mhs, int jmlMhs) {
    for (int i = 0; i < jmlMhs; i++) {
        printf("Masukkan data mahasiswa %d\n", i + 1);
        printf("NRP: ");
        scanf("%d", &data_mhs[i].nrp);
        fflush(stdin);
        printf("Nama: ");
        fgets(data_mhs[i].nama, sizeof(data_mhs[i].nama), stdin);  // Menggunakan fgets untuk membaca nama

        // Menghapus karakter newline yang ada di akhir nama (jika ada)
        data_mhs[i].nama[strcspn(data_mhs[i].nama, "\n")] = '\0';

        printf("Nilai Tugas: ");
        scanf("%d", &data_mhs[i].tugas);
        printf("Nilai UTS: ");
        scanf("%d", &data_mhs[i].uts);
        printf("Nilai UAS: ");
        scanf("%d", &data_mhs[i].uas);
    }
}

// Fungsi utama program
int main() {
    struct mahasiswa data_mhs[30];  // Array untuk menyimpan data mahasiswa
    int jmlMhs;

    printf("MENGHITUNG NILAI AKHIR\nMATA KULIAH KONSEP PEMROGRAMAN\n\n");
    printf("Berapa jumlah Mahasiswa? ");
    scanf("%d", &jmlMhs);

    printf("Masukkan data Mahasiswa\n\n");
    inputDataMhs(data_mhs, jmlMhs);  // Memasukkan data mahasiswa
    gradeMhs(data_mhs, jmlMhs);  // Menghitung grade mahasiswa

    // Menampilkan daftar nilai mahasiswa
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
