/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* 28 Oktober 2021 */
#include <stdio.h>
#include "list_linked.h"

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    FIRST(*l) = NULL;
}
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong */
{
    return (FIRST(l) == NULL);
}
/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
    int count = 0;
    Address p = FIRST(l);
    while (count < idx)
    {
        count++;
        p = NEXT(p);
    }
    return INFO(p);
}
void setElmt(List *l, int idx, ElType val)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
{
    int count = 0;
    Address p = FIRST(*l);
    while (count < idx)
    {
        count++;
        p = NEXT(p);
    }
    INFO(p) = val;
}
int indexOf(List l, ElType val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
    Address p = FIRST(l);
    boolean ketemu = false;
    int indeks = 0;
    while ((p != NULL) && (!ketemu))
    {
        if (INFO(p) == val)
        {
            ketemu = true;
        }
        else
        {
            indeks++;
            p = NEXT(p);
        }
    }
    if (ketemu)
    {
        return indeks;
    }
    else
    {
        return IDX_UNDEF;
    }
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    Address newfirst = newNode(val);
    if (newfirst != NULL)
    {
        NEXT(newfirst) = FIRST(*l);
        FIRST(*l) = newfirst;
    }
}
void insertLast(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    Address P = newNode(val);
    if (P != NULL)
    {
        Address last;
        if (isEmpty(*l))
        {
            NEXT(P) = FIRST(*l);
            FIRST(*l) = P;
        }
        else
        {
            last = FIRST(*l);
            while (NEXT(last) != NULL)
            {
                last = NEXT(last);
            }
            NEXT(P) = NEXT(last);
            NEXT(last) = P;
        }
    }
}
void insertAt(List *l, ElType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    Address p = newNode(val);
    Address lokasi;
    int count;
    if (idx == 0)
    {
        insertFirst(l, val);
    }
    else
    {
        p = newNode(val);
        if (p != NULL)
        {
            count = 0;
            lokasi = FIRST(*l);
            while (count < idx - 1)
            {
                count++;
                lokasi = NEXT(lokasi);
            }
            NEXT(p) = NEXT(lokasi);
            NEXT(lokasi) = p;
        }
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
    Address p = FIRST(*l);
    FIRST(*l) = NEXT(FIRST(*l));
    NEXT(p) = NULL;
    *val = INFO(p);
    free(p);
}
void deleteLast(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
    Address p = FIRST(*l);
    Address lokasi = NULL;
    while (NEXT(p) != NULL)
    {
        lokasi = p;
        p = NEXT(p);
    }
    if (lokasi == NULL)
    {
        FIRST(*l) = NULL;
    }
    else
    {
        NEXT(lokasi) = NULL;
    }
    *val = INFO(p);
    free(p);
}
void deleteAt(List *l, int idx, ElType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
    Address p, lokasi;
    int count;
    if (idx == 0)
    {
        deleteFirst(l, val);
    }
    else
    {
        count = 0;
        lokasi = FIRST(*l);
        while (count < idx - 1)
        {
            count++;
            lokasi = NEXT(lokasi);
        }
        p = NEXT(lokasi);
        *val = INFO(p);
        NEXT(lokasi) = NEXT(p);
        free(p);
    }
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!(isEmpty(l)))
    {
        Address now = FIRST(l);
        while (now != NULL)
        {
            printf("%d", INFO(now));
            now = NEXT(now);

            if (now != NULL)
                printf(",");
        }
    }
    printf("]");
}
int length(List l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    Address P = FIRST(l);
    while (P != NULL)
    {
        count++;
        P = NEXT(P);
    }
    return count;
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    Address Now = FIRST(L);
    while (Now != NULL)
    {
        if (P == Now)
        {
            return true;
        }
        Now = NEXT(Now);
    }
    return false;
}
Address searchPrec(List L, ElType X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    Address Prec, P;
    boolean found;

    Prec = NULL;
    P = FIRST(L);
    while ((P != NULL) && (!found))
    {
        if (INFO(P) == X)
        {
            found = true;
        }
        else
        {
            Prec = P;
            P = NEXT(P);
        }
    }
    if (found)
    {
        return Prec;
    }
    else
    {
        Prec = NULL;
        return Prec;
    }
}
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
ElType max(List l)
/* Mengirimkan nilai info(P) yang maksimum */
{
    ElType Maks;
    Address P;
    Maks = INFO(FIRST(l));
    P = NEXT(FIRST(l));
    while (P != NULL)
    {
        if (Maks < INFO(P))
        {
            Maks = INFO(P);
        }
        P = NEXT(P);
    }
    return Maks;
}
Address adrMax(List l)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    Address Max = FIRST(l);
    Address CP = FIRST(l);
    while (CP != NULL)
    {
        if (INFO(CP) > INFO(Max))
        {
            Max = CP;
        }

        CP = NEXT(CP);
    }
    return Max;
}
ElType min(List l)
/* Mengirimkan nilai info(P) yang minimum */
{
    ElType min;
    Address P;

    min = INFO(FIRST(l));
    P = NEXT(FIRST(l));
    while (P != NULL)
    {
        if (min > INFO(P))
        {
            min = INFO(P);
        }
        P = NEXT(P);
    }
    return min;
}
Address adrMin(List l)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    Address Min = FIRST(l);
    Address CP = FIRST(l);
    while (CP != NULL)
    {
        if (INFO(CP) < INFO(Min))
        {
            Min = CP;
        }
        CP = NEXT(CP);
    }
    return Min;
}
float average(List l)
/* Mengirimkan nilai rata-rata info(P) */
{
    double sum;
    Address P;
    if (length(l) != 0)
    {
        P = FIRST(l);
        sum = INFO(P);
        P = NEXT(P);
        while (P != NULL)
        {
            sum += INFO(P);
            P = NEXT(P);
        }
        return (sum / length(l));
    }
    else
    {
        return 0;
    }
}
/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2)
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    List l3;
    Address p;
    CreateList(&l3);
    p = FIRST(l1);
    while (p != NULL)
    {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p != NULL)
    {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}
void delAll(List *l)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
    ElType temp;
    while (!isEmpty(*l))
    {
        deleteFirst(l, &temp);
    }
    CreateList(l);
}
void inverseList(List *l)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    Address P, Prec, Last;

    P = FIRST((*l));
    Prec = NULL;
    while (P != NULL)
    {
        Last = P;
        P = NEXT(P);
        NEXT(Last) = Prec;
        Prec = Last;
    }
    FIRST(*l) = Last;
}
List fInverseList(List l)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    // Create temporary list
    List TempL;
    CreateList(&TempL);
    // Create duplicate of original list
    List TempOrg;
    CreateList(&TempOrg);
    TempOrg = fCopyList(l);
    ElType temp;
    Address tempAdr;
    while (!isEmpty(TempOrg))
    {
        deleteFirst(&TempOrg, &temp);
        tempAdr = newNode(temp);
        if (tempAdr != NULL)
        {
            insertFirst(&TempL, INFO(tempAdr));
        }
        else
        {
            delAll(&TempL);
            return TempL;
        }
    }
    return TempL;
}
void copyList(List *l1, List *l2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
    FIRST(*l2) = FIRST(*l1);
}
List fCopyList(List l)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    List TempL;
    CreateList(&TempL);
    Address CP = FIRST(l);
    Address tempAdr;
    while (CP != NULL)
    {
        tempAdr = newNode(INFO(CP));
        if (tempAdr != NULL)
        {
            insertLast(&TempL, INFO(tempAdr));
            CP = NEXT(CP);
        }
        else
        {
            delAll(&TempL);
            return TempL;
        }
    }
    return TempL;
}
void cpAllocList(List lIn, List *lOut)
/* I.S. lIn sembarang. */
/* F.S. Jika semua alokasi berhasil,maka lOut berisi hasil copy lIn */
/* Jika ada alokasi yang gagal, maka lOut=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* lOut adalah list kosong jika ada alokasi elemen yang gagal */
{
    CreateList(lOut);
    *lOut = fCopyList(lIn);
}
void splitList(List *l1, List *l2, List l)
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */
{
    int repeat = length(l) / 2;
    int repeat2 = length(l) - repeat;
    Address tempAdr;
    ElType temp;
    Address CP = FIRST(l);
    CreateList(l1);
    CreateList(l2);
    while (repeat > 0)
    {
        temp = INFO(CP);
        tempAdr = newNode(temp);
        if (tempAdr != NULL)
        {
            insertLast(l1, INFO(tempAdr));
            CP = NEXT(CP);
            repeat--;
        }
    }

    while (repeat2 > 0)
    {
        temp = INFO(CP);
        tempAdr = newNode(temp);
        if (tempAdr != NULL)
        {
            insertLast(l2, INFO(tempAdr));
            CP = NEXT(CP);
            repeat2--;
        }
    }
}
