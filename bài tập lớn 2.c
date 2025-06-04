#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct MonAn
{
	char ten[50];
	char ma[50];
	float gia;
	struct MonAn*tiep;
}Monan;
Monan*themmonan(){
	Monan*moi=(Monan*)malloc(sizeof(Monan));
	printf("Nhap ten mon an: ");
	getchar();
	fgets(moi->ten,sizeof(moi->ten),stdin);
	moi->ten[strcspn(moi->ten, "\n")]=0;
	printf("Nhap ma mon an: ");
	fgets(moi->ma,sizeof(moi->ma),stdin);
	moi->ma[strcspn(moi->ma, "\n")]=0;
	printf("Nhap gia mon an: ");
	scanf("%f",&moi->gia);
	return moi;
}
void hienthidanhsach(Monan*MA){
	int stt=1;
	if(MA==NULL){
		printf("CHUA CO MON AN!");
		return;}
	Monan*ma= MA;
	printf("\n==== DANH SACH MON AN ====\n");
	printf("STT\tTEN MON\t\t MA\tGIA\n");
	while(ma != NULL){
		printf("%d\t|%s\t\t| %s\t|%.2f\n",stt,ma->ten,ma->ma,ma->gia);
	ma=ma->tiep;
	stt++;
}
}
Monan*timmonantheoma(Monan*MA){
	char ma1[50];
	int kiemtra=0;
	printf("Nhap ma mon an can tim: ");
	getchar();
	fgets(ma1,sizeof(ma1),stdin);
	ma1[strcspn(ma1, "\n")]=0;
	Monan*ma=MA;
	while(ma != NULL){
		if(strcmp(ma->ma,ma1)==0){
			printf("CO TIM THAY MON AN: \n");
			printf("TEN MON\t\t MA\tGIA\n");
			printf("%s\t\t| %s\t|%.2f\n",ma->ten,ma->ma,ma->gia);
			kiemtra++;}
		ma=ma->tiep;
	}
	if(kiemtra==0){
	printf("Khong tim thay mon an!\n");
    return NULL;}
}
Monan*timmonantheogia(Monan*MA){
	float giamon;
	int kiemtra=0;
	printf("Nhap gia mon an can tim: ");
	scanf("%f",&giamon);
	getchar();
	Monan*ma=MA;
	while(ma != NULL){
		if(ma->gia==giamon){
			printf("CO TIM THAY MON AN: \n");
			printf("TEN MON\t\t MA\tGIA\n");
			printf("%s\t\t| %s\t|%.2f\n",ma->ten,ma->ma,ma->gia);
			kiemtra++;}
		ma=ma->tiep;
	}
	if(kiemtra==0){
	printf("Khong tim thay mon an!\n");
    return NULL;}
}
Monan*timmonantheokgia(Monan*MA){
	float giamonmin,giamonmax;
	int kiemtra=0;
	do{
	printf("Nhap gia mon an tu:  ");
	scanf("%f",&giamonmin);
	printf("Den: ");
	scanf("%f",&giamonmax);
	}while(giamonmin>=giamonmax);
	Monan*ma=MA;
	while(ma != NULL){
		if(ma->gia>=giamonmin && ma->gia<=giamonmax){
			printf("CO TIM THAY MON AN: \n");
			printf("TEN MON\t\t MA\tGIA\n");
			printf("%s\t\t| %s\t|%.2f\n",ma->ten,ma->ma,ma->gia);
			kiemtra++;}
		ma=ma->tiep;
	}
	if(kiemtra==0){
	printf("Khong tim thay mon an!\n");
    return NULL;}
}
Monan*timmonantheoten(Monan*MA){
	char ten1[50];
	int kiemtra=0;
	printf("Nhap ma mon an can tim: ");
	getchar();
	fgets(ten1,sizeof(ten1),stdin);
	ten1[strcspn(ten1, "\n")]=0;
	Monan*ma=MA;
	while(ma != NULL){
		if(strcmp(ma->ten,ten1)==0){
			printf("CO TIM THAY MON AN: \n");
			printf("TEN MON\t\t MA\tGIA\n");
			printf("%s\t\t| %s\t|%.2f\n",ma->ten,ma->ma,ma->gia);
			kiemtra++;}
		ma=ma->tiep;
	}
	if(kiemtra==0){
	printf("Khong tim thay mon an!\n");
    return NULL;}
}
Monan*monanmax(Monan*MA){
	float max= MA->gia;
	Monan*datnhat=MA;
	Monan*ma= MA->tiep;
	while(ma != NULL){
		if(ma->gia>max){
			max=ma->gia;
			datnhat=ma;}
			ma=ma->tiep;
	}
	printf("\n====  MON AN DAT NHAT  ====\n");
	printf("TEN MON\t\t MA\tGIA\n");
	printf("%s\t\t| %s\t|%.2f\n",datnhat->ten,datnhat->ma,datnhat->gia);
}
Monan*monanmin(Monan*MA){
	float min= MA->gia;
	Monan*renhat=MA;
	Monan*ma= MA->tiep;
	while(ma != NULL){
		if(ma->gia<min){
			min=ma->gia;
			renhat=ma;}
			ma=ma->tiep;
	}
	printf("\n====   MON AN RE NHAT   ====\n");
	printf("TEN MON\t\t MA\tGIA\n");
	printf("%s\t\t| %s\t|%.2f\n",renhat->ten,renhat->ma,renhat->gia);}
void xoamonantheoma(Monan*MA) {
	char macanxoa[50];
	printf("Nhap ma mon an can xoa: ");
	getchar();
	fgets(macanxoa,sizeof(macanxoa),stdin);
	macanxoa[strcspn(macanxoa, "\n")]=0;
    Monan* a = MA;
    Monan* b = NULL;
    if (strcmp(a->ma, macanxoa) == 0) {
        MA = a->tiep;
        free(a);
        printf("Da xoa mon an co ma: %s\n", macanxoa);
        return;
    }
    while (a != NULL){
    if(strcmp(a->ma, macanxoa) == 0) {
        break;}
        b = a;
        a = a->tiep;
    }
    if (a == NULL) {
        printf("Khong tim thay mon an co ma: %s\n", macanxoa);
        return;
    }
    b->tiep = a->tiep;
    free(a);
    printf("Da xoa mon an co ma: %s\n", macanxoa);
    return;
}
int main(){
	int luachon;
	Monan*MA = NULL;
	Monan*ma;
	while(1){
		printf("\n===== QUAN LY MON AN =====\n");
		printf("1. THEM MON AN\n");
		printf("2. HIEN THI CAC MON AN\n");
		printf("3. TIM MON AN THEO MA\n");
		printf("4. TIM MON AN THEO GIA\n");
		printf("5. TIM MON AN THEO KHOANG GIA\n");
		printf("6. TIM MON AN THEO TEN\n");
		printf("7. MON AN CO GIA CAO NHAT\n");
		printf("8. MON AN CO GIA CAO NHAT\n");
		printf("9. XOA MON AN THEO MA\n");
		printf("0. THOAT\n");
		printf("Chon chuc nang: ");
		scanf("%d",&luachon);
	switch(luachon){
		case 1:
		ma= themmonan();
		if(MA==NULL){
			MA=ma;}
		else{
			Monan*p=MA;
		while(p->tiep !=NULL){
			p=p->tiep;}
		p->tiep=ma;}
		break;
		case 2:
		hienthidanhsach(MA);
		break;
		case 3:
		if(MA==NULL){
		printf("Danh sach trong, khong tim thay mon an");}
		else{
		timmonantheoma(MA);}
		break;
		case 4:
		if(MA==NULL){
		printf("Danh sach trong, khong tim thay mon an");}
		else{
		timmonantheogia(MA);}
		break;
		case 5:
		if(MA==NULL){
		printf("Danh sach trong, khong tim thay mon an");}
		else{
		timmonantheokgia(MA);}
		break;
		case 6:
		if(MA==NULL){
		printf("Danh sach trong, khong tim thay mon an");}
		else{
		timmonantheoten(MA);}
		break;
		case 7:
			if(MA==NULL){
		printf("Danh sach trong, khong tim thay mon an");}
		else{
		monanmax(MA);}
		break;
		case 8:
		if(MA==NULL){
		printf("Danh sach trong, khong tim thay mon an");}
		else{
		monanmin(MA);}
		break;
		case 9:
		if(MA==NULL){
		printf("Danh sach trong, khong tim thay mon an");}
		else{
		xoamonantheoma(MA);}
		break;
		case 0:
		return 0;
	}
}
}