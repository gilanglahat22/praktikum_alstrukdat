/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* Listdinpos.c */

#include <stdio.h>
#include "listdinpos.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */
{
    CAPACITY(*l) = capacity;
    BUFFER(*l) = (int *)malloc(capacity * sizeof(int));
    for (int i = 0; i < capacity; i++)
    {
        ELMT(*l, i) = VAL_UNDEF;
    }
}
void dealocate(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0 */
{
    CAPACITY(*l) = 0;
    free(BUFFER(*l));
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
{
    int i = 0;
    while (i < CAPACITY(l) && ELMT(l, i) != VAL_UNDEF)
    {
        i++;
    }
    return i;
}
/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return (length(l) - 1);
}
/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >= 0 && i < CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..getLastIdx(l) */
{
    return (i >= 0 && i <= getLastIdx(l));
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
    return length(l) == 0;
}
/* *** Test list penuh *** */
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    return length(l) == CAPACITY(l);
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    int N;
    while (true)
    {
        scanf("%d\n", &N);
        if (N >= 0 && N <= CAPACITY(*l))
        {
            break;
        }
    }

    if (N > 0)
    {
        IdxType i;
        for (i = 0; i < N; i++)
        {
            scanf("%d\n", &(ELMT(*l, i)));
        }
    }
}
void displayList(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    printf("[");
    if (!isEmpty(l))
    {
        for (int i = 0; i <= getLastIdx(l); i++)
        {
            printf("%d", ELMT(l, i));

            if (i != getLastIdx(l))
            {
                printf(",");
            }
        }
    }
    printf("]");
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki nEff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen l1-l2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
    ListDin L;
    CreateListDin(&L, CAPACITY(l1));
    for (int i = 0; i <= getLastIdx(l1); i++)
    {
        if (plus)
        {
            ELMT(L, i) = ELMT(l1, i) + ELMT(l2, i);
        }
        else
        {
            ELMT(L, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return L;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
    if (length(l1) != length(l2))
    {
        return false;
    }
    else
    {
        for (int i = 0; i <= getLastIdx(l1); i++)
        {
            if (ELMT(l1, i) != ELMT(l2, i))
            {
                return false;
            }
        }
    }
    return true;
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen list l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan nilai tak terdefinisi (IDX_UNDEF) jika list l kosong */
/* Skema Searching yang digunakan bebas */
{
    if (isEmpty(l))
    {
        return IDX_UNDEF;
    }

    int i, RESULT = IDX_UNDEF;
    for (i = 0; i <= getLastIdx(l); i++)
    {
        if (ELMT(l, i) == val)
        {
            RESULT = i;
            break;
        }
    }
    return RESULT;
}
/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for (int i = 0; i <= getLastIdx(l); i++)
    {
        if (*max <= ELMT(l, i))
        {
            *max = ELMT(l, i);
        }
        if (*min >= ELMT(l, i))
        {
            *min = ELMT(l, i);
        }
    }
}
/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan Capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
    CreateListDin(lOut, CAPACITY(lIn));
    for (int i = 0; i < length(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}
ElType sumList(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
    int jumlah = 0;
    if (length(l) == 0)
    {
        return jumlah;
    }
    else
    {
        for (int i = 0; i <= length(l) - 1; i++)
        {
            jumlah = jumlah + ELMT(l, i);
        }
        return jumlah;
    }
}
int countVal(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
    int kemunculan = 0;
    if (length(l) == 0)
    {
        return kemunculan;
    }
    else
    {
        for (int i = 0; i <= length(l) - 1; i++)
        {
            if (ELMT(l, i) == val)
            {
                kemunculan = kemunculan + 1;
            }
        }
        return kemunculan;
    }
}
boolean isAllEven(ListDin l)
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
{
    for (int i = 0; i <= length(l) - 1; i++)
    {
        if (ELMT(l, i) % 2 != 0)
        {
            return false;
        }
    }
    return true;
}
/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    IdxType idx;
    ElType temp;

    if (!asc)
    {
        for (int i = 0; i < length(*l) - 1; i++)
        {
            idx = i;
            for (int j = i; j <= length(*l) - 1; j++)
            {
                if (ELMT(*l, j) > ELMT(*l, idx))
                {
                    idx = j;
                }
            }
            if (idx != i)
            {
                temp = ELMT(*l, idx);
                ELMT(*l, idx) = ELMT(*l, i);
                ELMT(*l, i) = temp;
            }
        }
    }
    else
    {
        for (int i = 1; i <= length(*l) - 1; i++)
        {
            temp = ELMT((*l), i);
            int j = i - 1;
            while ((j >= 0) && (ELMT(*l, j) > temp))
            {
                ELMT(*l, (j + 1)) = ELMT(*l, j);
                j--;
            }
            ELMT(*l, (j + 1)) = temp;
        }
    }
}
/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
/* Proses: Menambahkan X sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    ELMT(*l, length(*l)) = val;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMT(*l, length(*l) - 1);
    ELMT(*l, length(*l) - 1) = VAL_UNDEF;
}
/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num)
/* Proses : Menambahkan kapasitas sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    CAPACITY(*l) += num;
    BUFFER(*l) = (int *)realloc(BUFFER(*l), CAPACITY(*l));
}
void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi kapasitas sebanyak num */
/* I.S. List sudah terdefinisi, ukuran Capacity > num, dan nEff < Capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    CAPACITY(*l) -= num;
    if (length(*l) > CAPACITY(*l))
    {
        int selisih = length(*l) - CAPACITY(*l);
        int buang;
        for (int i = 0; i < selisih; ++i)
        {
            deleteLast(l, &buang);
        }
    }
    BUFFER(*l) = (int *)realloc(BUFFER(*l), CAPACITY(*l));
}
void compactList(ListDin *l)
/* Proses : Mengurangi kapasitas sehingga nEff = Capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran Capacity = nEff */
{
    CAPACITY(*l) = length(*l);
}