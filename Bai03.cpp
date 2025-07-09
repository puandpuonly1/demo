#include <iostream>
#include <numeric>
#include <math.h>

using namespace std;
struct PhanSo
{
    int TuSo;
    int MauSo;
};
PhanSo Cong, Tru, Nhan, Chia;
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
void Tong(PhanSo x, PhanSo y)
{
    Cong.TuSo = x.TuSo*y.MauSo + y.TuSo*x.MauSo;
    Cong.MauSo = x.MauSo*y.MauSo;
}
void Hieu(PhanSo x, PhanSo y)
{
    Tru.TuSo = x.TuSo*y.MauSo - y.TuSo*x.MauSo;
    Tru.MauSo = x.MauSo*y.MauSo;
}
void Tich(PhanSo x, PhanSo y)
{
    Nhan.TuSo = x.TuSo*y.TuSo;
    Nhan.MauSo = x.MauSo*y.MauSo;
}
void Thuong(PhanSo x, PhanSo y)
{
    Chia.TuSo = x.TuSo*y.MauSo;
    Chia.MauSo = x.MauSo*y.TuSo;
}
int main()
{
    PhanSo x, y;
    Nhap(x);
    Nhap(y);
    Tong(x, y);
    Hieu(x, y);
    Tich(x, y);
    Thuong(x, y);
    RutGon(Cong);
    RutGon(Tru);
    RutGon(Nhan);
    RutGon(Chia);
    Xuat(Cong);
    cout << " ";
    Xuat(Tru);
    cout << " ";
    Xuat(Nhan);
    cout << " ";
    Xuat(Chia);
    return 0;
}