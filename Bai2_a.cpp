#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

void NhapN(int &n)
{
    do
    {
        printf("Nhap n");
        scanf("%d", &n);
    } while (n < 0);
}
void NhapMang(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap pt %d", i);
        scanf("%d", &A[i]);
        for (int j = 0; j < i; j++)
        {
            if (A[j] == A[i])
            {
                printf("Nhap lai pt %d", i);
                scanf("%d", &A[i]);
            }
        }
    }
}
void XuatMang(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
}
bool KT_Chinh_Phuong(int CP)
{
    if (CP < 2)
        return false;
    int sqrt_CP = sqrt(CP);
    if (sqrt_CP * sqrt_CP == CP)
        return true;
    else
        return false;
}
void PT_Chinh_Phuong(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0 && KT_Chinh_Phuong(A[i]))
            printf("%d\t", A[i]);
    }
}
void VT_Lon_Nhat(int A[], int n)
{
    int vt, max = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
            vt = i;
        }
    }
    printf("Vi tri %d co so lon nhat", vt);
}
void PT_Am_MAX_Duong_MIN(int A[], int n)
{
    int MAX_Am, DuongMin;
    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0)
            MAX_Am = A[i];
            break;
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] > MAX_Am && A[i] < 0)
            MAX_Am = A[i];
    }
    // Duong nho nhat
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0)
            DuongMin = A[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] < DuongMin && A[i] > 0)
            DuongMin = A[i];
    }
    printf("Phan tu am lon nhat la %d\n", MAX_Am);
    printf("Phan tu duong nho nhat la  %d", DuongMin);
}
void Tong_PT_Duong(int A[], int n)
{
    int S = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            S += A[i];
    }
    printf("Tong cac phan tu o vi tri chan la %d", S);
}
int SapXep(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n, A[MAX];
    NhapN(n);
    NhapMang(A, n);
    XuatMang(A, n);
    printf("\n");
    PT_Chinh_Phuong(A, n);
    printf("\n");
    VT_Lon_Nhat(A, n);
    printf("\n");
    PT_Am_MAX_Duong_MIN(A, n);
    printf("\n");
    Tong_PT_Duong(A, n);
    printf("\n");
    qsort(A, n, sizeof(int), SapXep);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}