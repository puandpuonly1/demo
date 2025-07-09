#include <iostream>

using namespace std;

struct Ngay
{
    int ngay;
    int thang;
    int nam;
};
void Nhap(Ngay &x)
{
    cin >> x.ngay >> x.thang >> x.nam;
}
bool KiemTra(Ngay x)
{
    if(x.ngay <= 0 || x.ngay > 31 || x.thang <= 0 || x.thang > 12 || x.nam <= 0)
        return false;
    else
        {
        if(x.thang == 2)
            if(x.ngay > 29)
                return false;
            else
                if(x.nam%4 == 0 && x.nam%100 != 0)
                    return true;
                else
                    if(x.ngay <= 28)
                        return true;
                    else
                        return false;
            if(x.thang == 1 || x.thang == 3 || x.thang == 5 || x.thang == 7 || x.thang == 8 || x.thang == 10 || x.thang == 12)
                return true;
            else
                if(x.ngay > 30)
                    return false;
                else
                    return true;
        }
}
void Xuat(Ngay x)
{
    if(KiemTra(x) == true)
        cout << "Hop Le";
    else
        cout << "Khong Hop Le";
    cout << endl;
    if(KiemTra(x) == true)
    {
        if(x.thang == 1 || x.thang == 3 || x.thang == 5 || x.thang == 7 || x.thang == 8 || x.thang == 10)
            if(x.ngay == 31)
                {
                    x.ngay = 1;
                    x.thang++;
                }
            else
                x.ngay++;
        if(x.thang == 12)
            if(x.ngay == 31)
            {
                x.ngay = 1;
                x.thang = 1;
                x.nam++;
            }
            else
                x.ngay++;
        if(x.thang == 4 || x.thang == 6 || x.thang == 9 || x.thang == 11)
            if(x.ngay == 30)
                {
                    x.ngay = 1;
                    x.thang++;
                }
            else
                x.ngay++;
        if(x.thang == 2)
            if(x.nam%4 == 0 && x.nam%100 != 0)
                if(x.ngay == 29)
                {
                    x.ngay = 1;
                    x.thang++;
                }
                else
                    x.ngay++;
            else
                if(x.ngay == 28)
                {
                x.ngay = 1;
                x.thang++;
                }
                else
                    x.ngay++;
        cout << x.ngay << "/" << x.thang << "/" << x.nam;
    }
}
int main()
{
    Ngay x;
    Nhap(x);
    Xuat(x);
    return 0;
}