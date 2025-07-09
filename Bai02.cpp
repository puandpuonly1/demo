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
    PhanSo x, y;
    Nhap(x);
    Nhap(y);
    RutGon(x);
    RutGon(y);
    if(SoSanh(x, y) == 1)
        Xuat(x);
    else 
        if(SoSanh(x, y) == -1)
            Xuat(y);
        else
        {
            Xuat(x);
            cout << endl;
            Xuat(y);
        }
    return 0;
}