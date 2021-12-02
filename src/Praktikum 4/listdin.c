/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* 14 September 2021 */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include <stdio.h>
#include "listdin.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    int *sementara = malloc(capacity * sizeof(int));
    if (sementara != NULL)
    {
        CAPACITY(*l) = capacity;
        NEFF(*l) = 0;
        BUFFER(*l) = sementara;
    }
}
void dealocate(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    return NEFF(l);
}
/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return (NEFF(l) - 1);
}
/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >= 0 && i < CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
    return (i >= 0 && i <= NEFF(l) - 1);
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{

    return NEFF(l) == 0;
}
/* *** Test list penuh *** */
boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    return (NEFF(l) == CAPACITY(l));
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
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    int i, n;
    scanf("%d", &n);
    while (n < 0 || n > CAPACITY(*l))
    {
        scanf("%d", &n);
    }
    if (n > 0 && n <= CAPACITY(*l))
    {
        for (i = 0; i <= n - 1; i++)
        {
            scanf("%d", &ELMT(*l, i));
        }
    }
    NEFF(*l) = n;
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
    int i;

    printf("[");
    for (i = 0; i <= NEFF(l) - 1; i++)
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
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
    int i;
    ListDin PlusMinus;
    CreateListDin(&PlusMinus, CAPACITY(l1));
    for (i = 0; i <= NEFF(l1) - 1; i++)
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
    NEFF(PlusMinus) = NEFF(l1);
    return PlusMinus;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
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
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
    int i;
    if (length(l) > 0)
    {
        for (i = 0; i <= length(l) - 1; i++)
        {
            if (ELMT(l, i) == val)
            {
                return i;
            }
        }
    }
    return IDX_UNDEF;
}
/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
    int i;
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for (i = 1; i <= NEFF(l) - 1; i++)
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
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
    int i;
    CreateListDin(lOut, CAPACITY(lIn));
    for (i = 0; i < NEFF(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
    NEFF(*lOut) = NEFF(lIn);
}
ElType sumList(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
    int i;
    int jumlah;
    jumlah = 0;
    if (NEFF(l) == 0)
    {
        return 0;
    }
    else
    {
        for (i = 0; i <= NEFF(l) - 1; i++)
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
    int i;
    int kemunculan;
    kemunculan = 0;
    if (NEFF(l) == 0)
    {
        return 0;
    }
    else
    {
        for (i = 0; i <= NEFF(l) - 1; i++)
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
    int i;
    for (i = 0; i <= NEFF(l) - 1; i++)
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
void insertLast(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l) += 1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List lidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMT(*l, NEFF(*l) - 1);
    NEFF(*l) -= 1;
}
/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    ElType *newBuffer = realloc(BUFFER(*l), (CAPACITY(*l) + num) * sizeof(int));
    if (newBuffer)
    {
        CAPACITY(*l) += num;
        BUFFER(*l) = newBuffer;
    }
}
void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    ListDin LNew;
    int shrinked = (CAPACITY(*l)) - num;
    CreateListDin(&LNew, shrinked);
    NEFF(LNew) = (NEFF(*l) < shrinked ? NEFF(*l) : shrinked);
    for (int i = 0; i <= getLastIdx(LNew); i++)
    {
        ELMT(LNew, i) = ELMT((*l), i);
    }
    dealocate(l);
    *l = LNew;
}
void compactList(ListDin *l)
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
{
    ElType *newBuffer = realloc(BUFFER(*l), NEFF(*l) * sizeof(int));
    if (newBuffer)
    {
        CAPACITY(*l) = NEFF(*l);
        BUFFER(*l) = newBuffer;
    }
}