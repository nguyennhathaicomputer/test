#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct sinhvien
{
    char first_name[100];
    char last_name[100];
    int mssv;
    float toan;
    float li;
    float hoa;
    float dtb;
};typedef struct sinhvien SV;



void read_data_from_file_sinhvien(SV ds[], int *n)
{
    FILE *f  ;
    f = fopen("sinhvien.txt","r");
    if(f == NULL)
        {
            printf("\nNo Such File Or Directory!");
            exit(1);
        }
    fscanf(f,"%d\n",&(*n));
    int i = 0;
    while(fscanf(f,"%s %s\n%d",&ds[i].first_name,&ds[i].last_name,&ds[i].mssv) != EOF)
    {
        i++;
    }
    fclose(f);

}


void read_data_from_file_diem(SV ds[], int *n)
{
    FILE *f;
    f = fopen("diem.txt","r");
    if(f == NULL)
        {
            printf("\nNo Such File Or Directory!");
            exit(1);
        }
    fscanf(f,"%d\n",&(*n));
    int i=0;
    while(fscanf(f,"%f %f %f %f\n",&ds[i].toan, &ds[i].li, &ds[i].hoa, &ds[i].dtb)!= EOF)
    {
        i++;
    }fclose(f);
}

void print_info(SV ds[], int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        printf("%d-%s %s-%.2f-%.2f-%.2f-%.2f\n",ds[i].mssv,ds[i].first_name, ds[i].last_name,ds[i].toan, ds[i].li, ds[i].hoa, ds[i].dtb);
    }
}

void sap_xep_theo_dtb(SV ds[], int n)
{
    for(int i = 0; i<n-1 ;i++)
        {
            for(int j = i+1 ; j < n ; j++)
                {
                    if(ds[i].dtb< ds[j].dtb)
                        {
                            SV temp = ds[i];
                            ds[i] = ds[j];
                            ds[j] = temp;
                        }
                }
        }
}

int main()
{
    SV ds[100];
    int n;
    read_data_from_file_diem(ds,&n);
    read_data_from_file_sinhvien(ds,&n);
    print_info(ds, n);
    sap_xep_theo_dtb(ds, n);
    printf("\n\n\t\t DANH SACH SINH VIEN THEO DIEM TRUNG BINH GIAM DAN\n");
    print_info(ds, n);



    return 0;
}