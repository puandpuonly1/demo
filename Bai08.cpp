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
int ThuTrongTuan(Ngay x)
{
    if (x.thang < 3)
    {
        x.thang += 12;
        x.nam -= 1;
    }
    int k = x.nam % 100;
    int j = x.nam / 100;
    int f = x.ngay + 13 * (x.thang + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    int res = f % 7;
    return res;
}
void Xuat(Ngay x)
{
    switch(ThuTrongTuan(x))
    {
        case 0:
            cout << "Thu Bay";
            break;
        case 1:
            cout << "Chu Nhat";
            break;
        case 2:
            cout << "Thu Hai";
            break;
        case 3:
            cout << "Thu Ba";
            break;
        case 4:
            cout << "Thu Tu";
            break;
        case 5:
            cout << "Thu Nam";
            break;
        case 6:
            cout << "Thu Sau";
            break;
    }
}
int main()
{
    Ngay x;
    Nhap(x);
    Xuat(x);
    return 0;
}