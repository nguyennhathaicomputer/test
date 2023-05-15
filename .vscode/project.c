#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct Date
{
    int ngay;
    int thang;
    int nam;
};typedef struct Date date;

struct SinhVien
{
    int id;
    char ten[50];
    char gioitinh[50];
    date ngaysinh;
    int tuoi;
    float diem_mon_1;
    float diem_mon_2;
    float diem_mon_3;
    float diem_trung_binh;
    char hoc_luc[50];
    char ma_lop[50];


};typedef struct SinhVien SV;

void xoa_xuong_dong(char x[])
{
    size_t len = strlen(x);
    if(x[len-1] == '\n')
        {
            x[len-1] = '\0';
        }
    
}
// nhập thông tin 1 sinh viên
void nhap_sinh_vien(SV *sv)
{
    printf("\nnhap ID: "); scanf("%d", &sv->id);
    printf("\nnhap ten: ");fflush(stdin);fgets(sv->ten, sizeof(sv->ten), stdin);xoa_xuong_dong(sv->ten);
    printf("\nnhap gioi tinh: ");fflush(stdin);fgets(sv->gioitinh, sizeof(sv->gioitinh), stdin); xoa_xuong_dong(sv->gioitinh);
    printf("\nnhap ngay thang nam sinh: ");scanf("%d%d%d",&sv->ngaysinh.ngay,&sv->ngaysinh.thang,&sv->ngaysinh.nam);
    printf("\nnhap diem mon 1: "); scanf("%f",&sv->diem_mon_1);
    printf("\nnhap diem mon 1: "); scanf("%f",&sv->diem_mon_2);  
    printf("\nnhap diem mon 3: "); scanf("%f",&sv->diem_mon_3);  
    printf("\nnhap ma lop: ");fflush(stdin);fgets(sv->ma_lop,sizeof(sv->ma_lop), stdin);xoa_xuong_dong(sv->ma_lop);
}

// xuất thông tin một sinh viên
void in_sinh_vien(SV *sv)
{
    printf("%d\t%s\t%s\t%d/%d/%d\t%d\t%.2f\t%.2f\t%.2f\t%.2f\t%s\t%s",sv->id,sv->ten,sv->gioitinh,sv->ngaysinh.ngay,sv->ngaysinh.thang,sv->ngaysinh.nam,sv->tuoi,sv->diem_mon_1,sv->diem_mon_2,sv->diem_mon_3,sv->diem_trung_binh,sv->hoc_luc,sv->ma_lop);
}

// hàm tính tuổi của sinh viên
void tinhtuoi(SV *sv)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int nam_hien_tai = tm.tm_year + 1900;
    sv->tuoi = nam_hien_tai - sv->ngaysinh.nam;

}

// hàm tính điểm trung bình của sinh viên
void tinh_diem_trung_binh(SV *sv)
{
    sv->diem_trung_binh = (float)(sv->diem_mon_1 + sv->diem_mon_2 + sv->diem_mon_3)/3;
}


// hàm xếp loại sinh viên theo điểm trung bình
void xep_loai_sinh_vien(SV *sv)
{
    if(sv->diem_trung_binh > 8)
        {
            strcpy(sv->hoc_luc,"Gioi");
        }
    else if(sv->diem_trung_binh > 7)
        {
            strcpy(sv->hoc_luc,"Kha");
        }
    else if(sv->diem_trung_binh > 5)
        {
            strcpy(sv->hoc_luc,"Trung Binh");
        }
    else
        {
            strcpy(sv->hoc_luc,"Yeu");
        }
}

// hàm thực hiện các thao tác 
 void cap_nhat_sinh_vien(SV *sv)
 {
    nhap_sinh_vien(sv);
    tinhtuoi(sv);
    tinh_diem_trung_binh(sv);
    xep_loai_sinh_vien(sv);
 }

// hàm nhập dnah sách sinh viên
void nhap_danh_sach_sinh_vien(SV ds[], int *n)
{
    
    for(int i=0; i<(*n); i++)
        {
            printf("\nnhap thong tin sinh vien thu %d: ",i+1);
            cap_nhat_sinh_vien(&ds[i]);
        }
}


// hàm xuất danh sách sinh viên
void xuat_danh_sach_sinh_vien(SV ds[], int n)
{   
    for(int i=0; i<n; i++)
    {
        printf("\n%d: ", i+1);
        in_sinh_vien(&ds[i]);
    }
}

// hàm tìm điểm trung bình cao nhất của sinh viên
float tim_max_diem_trung_binh(SV ds[], int n)
{
    float max = ds[0].diem_trung_binh;
    for(int i=0; i<n; i++)
        {
            if(max < ds[i].diem_trung_binh)
                {
                    max = ds[i].diem_trung_binh;
                }
        }
    return max;
}


// hàm tìm tuổi thấp nhất của sinh viên
int tim_min_tuoi(SV ds[], int n)
{
    int min = ds[0].tuoi;
    for(int i=0; i<n; i++)
        {
            if(min > ds[i].tuoi)
                {
                    min = ds[i].tuoi;
                }
        }
    return min;

}


// hàm tìm danh sách sinh viên có học lực giỏi
void danh_sach_sinh_vien_loai_gioi(SV ds[], int n)
{
    printf("\nDanh sach sinh vien xep loai gioi: \n");
    for(int i=0; i<n; i++)
        {
            if(strcmp(ds[i].hoc_luc,"GIOI"))
            {
                in_sinh_vien(&ds[i]);
            }
        }
}



// hàm xuất danh sách sinh viên theo lớp
void xuat_danh_sach_sinh_vien_theo_lop(SV ds[], int n, char lop[50])
{
    printf("\nDanh sinh vien theo lop: ");
    for( int i=0; i<n; i++)
        {
            if(strcmp(ds[i].ma_lop,lop))
                {
                    in_sinh_vien(&ds[i]);
                }
        }
}


// hàm trả về 0 hoặc 1 nếu tìm thấy tên sinh viên trong danh sách
int tim_sinh_vien_theo_ten(SV ds[], int n, char ten[50])
{
    for(int i=0; i<n; i++)
        {
            if(strstr(ds[i].ten, ten))
                {
                    return 1;
                }
        }
    return 0;
}


// hàm sắp xếp sinh viên theo điểm trung bình
void sap_xep_sinh_vien_theo_diem_trung_binh(SV ds[], int n)
{
    for(int i = 0; i <n-1 ; i++)
        {
            for(int j = i+1 ; j<n ; j++)
                {
                    if(ds[i].diem_trung_binh > ds[j].diem_trung_binh)
                        {
                            SV tam = ds[i];
                            ds[i] = ds[j];
                            ds[j] = tam; 
                        }
                }
        }
}

void xuat_vao_file(SV ds[], int n)
{
    char tenfile[100];
    printf("\nnhap ten file:");fflush(stdin);
    fgets(tenfile, sizeof(tenfile), stdin);xoa_xuong_dong(tenfile);

    FILE *f ;
    f = fopen(tenfile,"wb");
    if(f == NULL)
        {
            printf("\nNo such file or directory!");
            exit(1);
        }
    fwrite(&n, sizeof(n),1, f);
    for(int i=0; i<n; i++)
        {
            fwrite(&ds[i],sizeof(SV),1,f);
        }
        fclose(f);
}


void nhap_tu_file(SV ds[], int *n)
{
    char tenfile[100];
    FILE *f;
    printf("\nnhap ten file: ");fflush(stdin);
    fgets(tenfile, sizeof(tenfile), stdin);xoa_xuong_dong(tenfile);
    f = fopen(tenfile,"rb");
    if(f == NULL)
        {
            printf("\nNo such file or directory!");
            exit(1);
        }
    fread(&(*n), sizeof((*n)), 1 ,f);
    
    for(int i=0; i<(*n); i++)
        {
            fread(&ds[i],sizeof(SV),1,f);
        }    
    fclose(f);


}

int main()
{
    SV ds[100];
    int n;
    // do
    // {
    //     printf("\nnhap so luong sinh vien: ");
    //     scanf("%d",&n);
    // } while ((n)<=0);
    nhap_tu_file(ds,&n);
    xuat_danh_sach_sinh_vien(ds, n);  

    return 0;
}