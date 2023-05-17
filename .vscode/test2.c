#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Employees 
{
    char id[100];
    char first_name[100];
    char last_name[100];
    char sex[100];
    char day_birth[100];
    char value[100];
    char country[100];

};typedef struct Employees  NV;

void remove_newline(char x[])
{
    if(x[strlen(x)-1] == '\n')
        {
            x[strlen(x)-1] = '\0';
        }
}

void load_data_from_txt(NV ds[])
{
    FILE *f = fopen("employees.txt","r");
    if(f == NULL)
        {
            printf("\nNo Such File Or Directory!");
            exit(1);
        }
    int i = 0;
    while(fscanf(f,"%s %s %s %s %s %s %s\n",&ds[i].id,&ds[i].first_name,&ds[i].last_name,&ds[i].sex,&ds[i].day_birth,&ds[i].value,&ds[i].country)!= EOF)
    {
        i++;
    }
    fclose(f);
}

void count_male(NV ds[])
{
    int count = 0;
    for( int i = 0; i< 201 ;i++)
        {
            if(strcmp(ds[i].sex , "Male") == 0)
                {
                    count++;
                }
        }    
    printf("\nQuantity male in file is: %d",count);
}

void count_female(NV ds[])
{
    int count = 0;
    for( int i = 0; i< 201 ;i++)
        {
            if(strcmp(ds[i].sex , "Female") == 0)
                {
                    count++;
                }
        }
    printf("\nQuantity female in file is: %d",count);
}

// function find nationality
void find_nationality(NV ds[])
{
    char nation[100];
    printf("\nenter nationality need to find: ");fflush(stdin);
    fgets(nation,sizeof(nation), stdin);remove_newline(nation);
    int count = 0;
    for(int i = 0; i < 201; i++)
        {
            if(strcmp(ds[i].country,nation) == 0)
                {
                    printf("%s-%s-%s-%s-%s-%s-%s\n",ds[i].id,ds[i].first_name,ds[i].last_name,ds[i].sex,ds[i].day_birth,ds[i].value,ds[i].country);
                    count++;
                }
        }
    printf("\nHave %d nationalities %s", count,nation);

}


void find_id(NV ds[])
{
    char id[100];
    printf("\nenter ID: ");fflush(stdin);
    fgets(id,sizeof(id), stdin);remove_newline(id);
    for( int i = 0; i < 201; i++)
        {
            if( strcmp(ds[i].id , id) == 0)
                {
                    printf("%s-%s-%s-%s-%s-%s-%s\n",ds[i].id,ds[i].first_name,ds[i].last_name,ds[i].sex,ds[i].day_birth,ds[i].value,ds[i].country);
                }
        }
}



int main()
{
    NV ds[300];
    load_data_from_txt(ds);
    find_nationality(ds);    

    return 0;
}