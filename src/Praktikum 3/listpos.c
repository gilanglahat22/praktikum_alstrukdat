/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer dengan elemen 
   positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */
#include <stdio.h>
#include "listpos.h"

void CreateListPos(ListPos *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
{
    int i;
    for (i = 0; i < CAPACITY; i++)
    {
        ELMT(*l, i) = VAL_UNDEF;
    }
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPos l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
/* ALGORITMA */
{
    int jumlah_elemen, i;
    i = 0;
    jumlah_elemen = 0;
    while (i <= CAPACITY - 1)
    {
        if (ELMT(l, i) == VAL_UNDEF)
        {
            return jumlah_elemen;
        }
        else
        {
            i++;
            jumlah_elemen++;
        }
    }
    return jumlah_elemen;
}
/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
/* ALGORITMA */
{
    return (i >= 0 && i < CAPACITY);
}
boolean isIdxEff(ListPos l, int i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
/* ALGORITMA */
{
    return (i >= 0 && i <= length(l) - 1);
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPos l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* ALGORITMA */
{
    return (length(l) == 0);
}
/* *** Test List penuh *** */
boolean isFull(ListPos l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
/* ALGORITMA */
{
    return (length(l) == CAPACITY);
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListPos *l)
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
/* ALGORITMA */
{
    int i, n;
    n = CAPACITY + 1;
    CreateListPos(l);
    while (n < 0 || n > CAPACITY)
    {
        scanf("%d \n", &n);
    }
    if (n > 0 && n <= CAPACITY)
    {
        for (i = 0; i <= n - 1; i++)
        {
            scanf("%d \n", &ELMT(*l, i));
        }
    }
}
void displayList(ListPos l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
/* ALGORITMA */
{
    int i;

    printf("[");
    for (i = 0; i <= length(l) - 1; i++)
    {
        if (i != 0)
        {
            printf(",");
        }
        printf("%d", ELMT(l, i));
    }
    printf("]");
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus)
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
/* ALGORITMA */
{
    int i;
    ListPos PlusMinus;
    CreateListPos(&PlusMinus);

    for (i = 0; (i <= length(l1) - 1); i++)
    {
        if ((ELMT(l1, i) != VAL_UNDEF) && (ELMT(l2, i) != VAL_UNDEF))
        {
            if (plus)
            {
                ELMT(PlusMinus, i) = ELMT(l1, i) + ELMT(l2, i);
            }
            else
            {
                ELMT(PlusMinus, i) = ELMT(l1, i) - ELMT(l2, i);
            }
        }
    }

    return PlusMinus;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListPos l1, ListPos l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
/* ALGORITMA */
{
    int i;
    boolean cek;
    i = 0;
    cek = true;
    if (length(l1) == length(l2))
    {
        while ((i <= length(l1) - 1) && (cek == true))
        {
            if (ELMT(l1, i) != ELMT(l2, i))
            {
                cek = false;
            }
            i++;
        }
        return cek;
    }
    else
    {
        return false;
    }
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListPos l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
/* ALGORITMA */
{
    int i;
    if (length(l) > 0)
    {
        for (i = 0; i <= length(l) - 1; i++)
        {
            if (val == ELMT(l, i))
            {
                return i;
            }
        }
    }
    return IDX_UNDEF;
}
/* ********** NILAI EKSTREM ********** */
void extremes(ListPos l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
/* ALGORITMA */
{
    int i;
    for (i = 0; i <= length(l) - 1; i++)
    {
        if (ELMT(l, i) != VAL_UNDEF)
        {
            if (i == 0)
            {
                *max = ELMT(l, i);
                *min = ELMT(l, i);
            }
            else
            {
                if (ELMT(l, i) >= *max)
                {
                    *max = ELMT(l, i);
                }
                if (ELMT(l, i) <= *min)
                {
                    *min = ELMT(l, i);
                }
            }
        }
    }
}
/* ********** OPERASI LAIN ********** */
boolean isAllEven(ListPos l)
/* Menghailkan true jika semua elemen l genap */
/* ALGORITMA */
{
    int i;
    for (i = 0; i <= length(l) - 1; i++)
    {
        if (ELMT(l, i) % 2 != 0)
        {
            return false;
        }
    }
    return true;
}
/* ********** SORTING ********** */
void sort(ListPos *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
/* ALGORITMA */
{
    int i, j, first, temp;

    first = 0;

    if (length(*l) > 1)
    {
        for (j = 0; j <= length(*l) - 2; j++)
        {
            first = j;
            for (i = j + 1; i <= length(*l) - 1; i++)
            {

                if (asc)
                {
                    if (ELMT(*l, i) < ELMT(*l, first))
                    {
                        first = i;
                    }
                }
                else
                {
                    if (ELMT(*l, i) > ELMT(*l, first))
                    {
                        first = i;
                    }
                }
            }

            temp = ELMT(*l, first);
            ELMT(*l, first) = ELMT(*l, j);
            ELMT(*l, j) = temp;
        }
    }
}
/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPos *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ALGORITMA */
{
    /* if (!(isFull(*l))) */
    ELMT(*l, length(*l)) = val;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListPos *l, ElType *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* ALGORITMA */
{
    *val = ELMT(*l, length(*l) - 1);
    ELMT(*l, length(*l) - 1) = VAL_UNDEF;
}