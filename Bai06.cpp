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
    cin.ignore();
    cin.getline(x.HoTen, 50);
    cin >> x.DiemToan >> x.DiemVan;
}
float DiemTrungBinh(ThongTinHocSinh x)
{
    return (x.DiemToan + x.DiemVan)/2;
}
void Xuat(ThongTinHocSinh x)
{
    cout << x.HoTen << " " << DiemTrungBinh(x);
}
int main()
{
    ThongTinHocSinh x[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        Nhap(x[i]);
        DiemTrungBinh(x[i]);
    }
    float maxDTB = DiemTrungBinh(x[0]), minDTB = DiemTrungBinh(x[0]);
    for(int i = 1; i < n; i++)
    {
        if(DiemTrungBinh(x[i]) > maxDTB)
            maxDTB = DiemTrungBinh(x[i]);
        if(DiemTrungBinh(x[i]) < minDTB)
            minDTB = DiemTrungBinh(x[i]);
    }
    for(int i = 0; i < n; i++)
    {
        if(DiemTrungBinh(x[i]) == maxDTB)
        {
            Xuat(x[i]);
            cout << " ";
        }
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        if(DiemTrungBinh(x[i]) == minDTB)
        {
            Xuat(x[i]);
            cout << " ";
        }
    }
    return 0;
}
