#include<iostream>
#include<fstream>
using namespace std;

struct phanso
{
    int tuso;
    int mauso;
};
typedef struct phanso PHANSO;

void nhap_phan_so(PHANSO &x)
{
    cout<<"\nnhap tu so: ";
    cin >> x.tuso;
    cout<<"\nnhap mau so: ";
    cin >> x.mauso;
}

void xuat_phan_so(PHANSO x)
{
    cout<<x.tuso<<"/"<<x.mauso;
}

// nap chong toan tu >> de nhap du lieu tu ban phim
istream& operator >>(istream& is, PHANSO &ps)
{
    cout<<"\nnhap tu so: ";
    is >> ps.tuso;
    cout<<"\nnhap mau so: ";
    is >> ps.mauso;

    return is;
}

// nap chong toan tu << de xuat du lieu ra man hinh

ostream& operator <<(ostream& os, PHANSO ps)
{
   cout<<ps.tuso<<"/"<<ps.mauso;
   return os;
}

// ham cong hai phan so
PHANSO cong(PHANSO x, PHANSO y)
{
    PHANSO tam;
    tam.tuso = (x.tuso * y.mauso) + (y.tuso * x.mauso);
    tam.mauso = (x.mauso * y.mauso);

    return tam;
}

// nạp chồng toán tử + để cộng trực tiếp kiểu dữ liệu cấu trúc hai phân sô
PHANSO operator +(PHANSO x, PHANSO y)
{
     PHANSO tam;
    tam.tuso = (x.tuso * y.mauso) + (y.tuso * x.mauso);
    tam.mauso = (x.mauso * y.mauso);

    return tam;
}

int main()
{
    PHANSO x;
    PHANSO y;

    cout<<"\nnhap phan so x: ";
    cin >>x;
    cout<<"\nnhap phan so y: ";
    cin >>y;


    cout<<"\nxuat phan so x: ";
    cout<<x;
    cout<<"\nxuat phan so y: ";
    cout<<y;
    
    cout<<"\ntong hai phan so la: "<<x+y;
    
    system("pause");
    return 0;
}