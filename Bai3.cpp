#define MAX 100
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef int Matran[MAX][MAX];
void NhapMatran(Matran mt, int n)
{
    time_t t;
    srand((unsigned)time(&t));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mt[i][j] = rand() % 50;
        }
    }
}
void XuatMT(Matran mt, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mt[i][j]);
        }
        printf("\n");
    }
}
void Xuat_PT_DCheo_Chinh(Matran mt, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                printf("%d ", mt[i][j]);
            else
                printf("  ");
        }
        printf("\n");
    }
}
void Xuat_PT_DCheo_Phu(Matran mt, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n - 1)
                printf("%d ", mt[i][j]);
            else
                printf("  ");
        }
        printf("\n");
    }
}
void Tong_PT_Dong_K(Matran mt, int n)
{
    int k, S = 0;
    printf("Nhap dong thu k");
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        if (i == k - 1)
            for (int j = 0; j < n; j++)
            {
                S += mt[i][j];
            }
    }
    printf("Tong dong %d la %d", k, S);
}
void Tong_PT_Moi_Dong(Matran mt, int n)
{
    int S = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            S += mt[i][j];
        }
        printf("Tong phan tu dong %d la %d", i + 1, S);
        printf("\n");
        S = 0;
    }
}
void Cac_Dong_Max(Matran mt, int n, int Tong)
{
    int S = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            S += mt[i][j];
        }
        if (Tong == S)
            printf("Dong %d co gia tri lon nhat", i + 1);
        S = 0;
    }
}
void Dong_MAX(Matran mt, int n)
{
    int S = 0;
    int Dem = 0, temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            S += mt[i][j];
        }
        if (S > temp)
            temp = S;
        S = 0;
    }
    Cac_Dong_Max(mt, n, temp);
}
int main()
{
    int n;
    Matran mt;
    printf("Nhap cap cua ma tran");
    scanf("%d", &n);
    NhapMatran(mt, n);
    XuatMT(mt, n);
    printf("\n");
    Xuat_PT_DCheo_Chinh(mt, n);
    printf("\n");
    Xuat_PT_DCheo_Phu(mt, n);
    printf("\n");
    Tong_PT_Dong_K(mt, n);
    printf("\n");
    Tong_PT_Moi_Dong(mt, n);
    printf("\n");
    Dong_MAX(mt, n);
}