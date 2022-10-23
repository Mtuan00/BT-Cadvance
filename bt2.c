#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{
    DO,
    VANG,
    XANH
}VO;

typedef struct {
    VO *ptr;
    int size;
}typeBox;

void nhapthongtin(typeBox *value){
    
    char name[5];

    printf("nhap chieu dai mang: ");

    scanf("%d",&(value->size));

    value->ptr = (VO*)malloc((value->size) * sizeof(VO)); 

    printf("== nhap mau tat ==\n");

    for (int i = 0; i < value->size; i++)
    {
        label:
        printf("nhap gia tri [%d]: ",i);
        scanf("%s", name);
        if(strcmp(name,(char*)"DO") == 0)
        {
            value->ptr[i] = DO;
        }
        else if(strcmp(name,(char*)"VANG") == 0)
        {
           value->ptr[i] = VANG;
        }
        else if(strcmp(name,(char*)"XANH") == 0)
        {
            value->ptr[i] = XANH;
        }
        else
        {
            printf("ban nhap sai !!!\n");
            goto label;
        }
    }
}

void xapxeptulondenbe(typeBox *value)
{
	int tg;
    for(int i = 0; i < value->size; i++){
        for(int j = i + 1; j < value->size; j++){
            if(value->ptr[i] < value->ptr[j]){
                // Hoan vi 2 so a[i] va a[j]
                tg = value->ptr[i];
                value->ptr[i] = value->ptr[j];
                value->ptr[j] = tg;        
            }
        }
    }
}
void sodoitat(typeBox *value)
{	
    float doo = 0, vang = 0, xanh =0;

	for(int i=0; i < value->size; i++)
	{

		if(value->ptr[i]  == XANH){
            xanh++;
        } 
        
        else if(value->ptr[i] == DO){
            doo ++;
        } 
        else{
             vang++;
        }
	}
	printf("So doi mau xanh: %.2f\n", xanh/2);

    printf("So doi mau do: %.2f\n", doo/2);

    printf("So doi mau vang: %.2f\n", vang/2);

    printf("Tong so doi tat la: %.2f",(doo + vang + xanh)/2);

}
void xuatthongtin(typeBox *value)
{
	for (int i = 0; i < value->size; i++)
    {
        printf("xuat[%d]: %d\n",i,value->ptr[i]);
    }
    
}

int main(int argc, char const *argv[])
{
    typeBox value;

    nhapthongtin(&value);

    //xapxeptulondenbe(&value);

    sodoitat(&value);

    //xuatthongtin(&value);
   
    return 0;

}
