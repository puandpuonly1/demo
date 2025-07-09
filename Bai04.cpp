#include <iostream>
#include <numeric>
#include <math.h>

using namespace std;

struct PhanSo
{
    int TuSo;
    int MauSo;
};
void RutGon(PhanSo &x)
{
    int gcd = std::gcd(abs(x.TuSo), abs(x.MauSo));
    x.TuSo /= gcd;
    x.MauSo /= gcd;
}
void Nhap(PhanSo &x)
{
    cin >> x.TuSo >> x.MauSo;
    if(x.MauSo == 0)
        Nhap(x);
}
void Xuat(PhanSo x)
{
    if(x.MauSo < 0)
    {
        x.TuSo *= -1;
        x.MauSo *= -1;
    }
    if(x.MauSo == 1)
        cout << x.TuSo;
    else
        cout << x.TuSo << "/" << x.MauSo;
}
int SoSanh(PhanSo x, PhanSo y)
{
    if(x.TuSo*y.MauSo == y.TuSo*x.MauSo)
        return 0;
    if(x.TuSo*y.MauSo > y.TuSo*x.MauSo)
        return 1;
    return -1;
}
int main()
{
    PhanSo x[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        Nhap(x[i]);
        RutGon(x[i]);
    }
    for(int i = 1; i < n; i++)
        for(int j = i; j > 0; j--)
            if(SoSanh(x[j], x[j-1]) == -1)
                swap(x[j], x[j-1]);
    for(int i = 0; i < n; i++)
    {
        Xuat(x[i]);
        cout << " ";
    }
    cout << endl;
    for(int i = n-1; i >= 0; i--)
    {
        Xuat(x[i]);
        cout << " ";
    }
    return 0;
}