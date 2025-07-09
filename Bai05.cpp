#include <iostream>
#include <string>

using namespace std;

struct ThongTinHocSinh
{
    char HoTen[50];
    float DiemToan, DiemVan;
};
void Nhap(ThongTinHocSinh &x)
{
    cin.getline(x.HoTen, 50);
    cin >> x.DiemToan >> x.DiemVan;
}
float DiemTrungBinh(ThongTinHocSinh x)
{
    return (x.DiemToan + x.DiemVan)/2;
}
void Xuat(ThongTinHocSinh x)
{
    cout << DiemTrungBinh(x);
}
int main()
{
    ThongTinHocSinh x;
    Nhap(x);
    DiemTrungBinh(x);
    Xuat(x);
    return 0;
}
