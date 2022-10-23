#include<stdio.h>
#include<stdlib.h>

typedef struct typeArr{
	int *arr;
	int size;
}typeArr;

void xapxeptubedenlon( typeArr *value)
{
	int tg;
    for(int i = 0; i < value->size; i++){
        for(int j = i + 1; j < value->size; j++){
            if(value->arr[i] > value->arr[j]){
                // Hoan vi 2 so a[i] va a[j]
                tg = value->arr[i];
                value->arr[i] = value->arr[j];
                value->arr[j] = tg;        
            }
        }
    }
}
void xapxeptulondenbe( typeArr *value)
{
	int tg;
    for(int i = 0; i < value->size; i++){
        for(int j = i + 1; j < value->size; j++){
            if(value->arr[i] < value->arr[j]){
                // Hoan vi 2 so a[i] va a[j]
                tg = value->arr[i];
                value->arr[i] = value->arr[j];
                value->arr[j] = tg;        
            }
        }
    }
}
void solonnhat( typeArr *value)
{
	int max = value->arr[0];
	for(int i=0;i<value->size;i++)
	{
		if(max < value->arr[i])
		{
			max = value->arr[i];
		}
	}
	printf("so lon nhat la: %d\n",max);
}
void nhapthongtin( typeArr *value)
{
    printf("nhap chieu dai cua mang: ");
    
    scanf("%d",&(value->size));
    
    value->arr = (int*)malloc((value->size) * sizeof(int)); 
    

    for (int i = 0; i < value->size; i++)
    {
        /* code */
        printf("nhap[%d]:", i);
		scanf("%d", &value->arr[i]);

    }
    
    printf("Test size: %d\n",value->size);
    
}
void xuatthongtin(typeArr *value)
{
	for (int i = 0; i < value->size; i++)
    {
        printf("xuat[%d]: %d\n",i,value->arr[i]);
    }
    
}
int main()
{
	int stt;
    struct typeArr test;

//    test = nhapthongtin();
//    
//    xapxeptubedenlon(*test);
//    
//    xapxeptulondenbe(*test);
//    
//    solonnhat(*test);
//    
//    xuatthongtin(*test);
//    
//	
//    free(test);
	printf("// -- NHAN 0 DE NHAP THONG TIN MANG --  // \n");
	printf("// -- NHAN 1 DE XAP XEP TU LON DEN BE --  // \n");
	printf("// -- NHAN 2 DE XAP XEP TU BE DEN LON --  // \n");
	printf("// -- NHAN 3 DE TIM SO LON NHAT --  // \n");
	printf("// -- NHAN 4 DE THOAT CHUONG TRINH --  // \n");
	printf("\n");
    do
	{
	    printf("moi nhap lua chon: "); scanf("%d",&stt);
	    printf("\n");
	    	
	    switch(stt)
	    	{
	    		case (0):
	    			printf("-> MOI BAN NHAP VAO THONG TIN MANG <-\n");
	    			nhapthongtin(&test);
	    			break;
	    		case(1):
	    			printf("-> ban chon sap xep tu lon den be <- \n");
	    			xapxeptulondenbe(&test);
	    			xuatthongtin(&test);
	    			break;
	    			
	    		case(2):
	    			printf("-> ban chon sap xep tu be den lon <-  \n");
	    			xapxeptubedenlon(&test);
	    			xuatthongtin(&test);
	    			break;
	    			
	    		case(3):
	    			printf("-> ban chon tim so lon nhat <- \n");
	    			solonnhat(&test);
	    			printf("\n");
	    			break;
	    			
	    		case(4):
	    			printf("-> !! ban chon thoat chuong trinh !! <-");
	    			break;
	    			
	    		default:
	    			printf("chon sai moi chon lai\n");
			}
	}while(stt != 4);
	//free(test);	
    return 0;
}
