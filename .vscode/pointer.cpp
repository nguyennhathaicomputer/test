#include<iostream>
using namespace std;

void nhap_mang(int *a,int n)
{
    for(int i = 0 ; i<n ;i++)
    {
        cout <<"\nnhap gia tri cho phan tu a["<<i<<"] = ";
        cin >> a[i];
    }
}


void xuat_mang(int *a,int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        cout <<a[i]<<" ";
    }
}


// tạo hàm cấp phát lại vùng nhớ tương tự realloc() bên C
void cap_phat_vung_lai_nho(int *&a, int vung_nho_moi, int vung_nho_cu)
{
int *temp = new int[vung_nho_cu] ;// tạo mảng phụ để gán các giá trị của mảng a qua cho mảng phụ
    for(int i = 0 ; i<vung_nho_cu ; i++)
    {
        temp[i] = a[i];// bỏ các phần tử từ mảng a sang cho mảng phụ temp

    }
    // bước 2: giải phóng vùng nhớ cũ của a trước 
    delete [] a;
    // bước 3: cấp phát lại vùng nhớ mới
    a = new int[vung_nho_moi];  
    // bước 4: đổ tất cả các phần từ của mảng temp[] về lại cho mảng a[]
    for(int i=0 ; i<vung_nho_moi ; i++) 
    { 
          a[i]= temp[i];
    }
    delete [] temp;
}


void them(int a[], int &n, int vt, int x)
{   
    
    cap_phat_vung_lai_nho(a,n+1,n);
    
    for(int i = n-1 ; i>=vt ; i--)
        {
            a[i+1] = a[i];
        }
    a[vt] = x;
    n++;
    
}

void xoa(int a[], int &n, int vt)
{   
    // xóa phần tử tại vị trí vt
    for(int i=vt+1 ; i<n ; i++)
        {
            a[i-1]= a[i];
        }
    n--;

    cap_phat_vung_lai_nho(a,n,n);
}



int main()
{
    
   int n;
   do
   {
    cout<<"\nnhap so luong phan tu mang : ";
    cin >> n;

   }while(n<=0);

   
   int *a = new int[n]; // cấp phát mảng động có n ô nhớ
    cout<<"\n\n\t\t NHAP MANG \n";
    nhap_mang(a,n);
    cout<<"\n\n\t\t XUAT MANG \n";
    xuat_mang(a,n);



    // int x,vt;
    // cout<<"\nnhap phan tu can them : ";
    // cin >> x;
    // cout<<"\nnhap vi tri can them : ";
    // cin >> vt;  
    // them(a,n,vt,x);
    // cout<<"\nmang sau khi them : \n";
    // xuat_mang(a,n);

    int vt;
    cout<<"\nnhap vi tri can xoa : ";
    cin >> vt;
    xoa(a,n,vt);
    cout<<"\nmang sau khi xoa : ";
    xuat_mang(a,n);
 

    delete [] a;
    system("pause");
    return 0;
}