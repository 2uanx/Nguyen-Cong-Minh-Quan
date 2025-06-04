#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct SinhVien{
	char ten[50];
	char mssv[20];
	int namsinh;
	float diem;
}SinhVien;
void nhap(int n, SinhVien *SV){
	getchar();
	for(int i=0; i<n; i++){
		printf("\n===Sinh vien thu %d===\n",i+1);
		printf("Nhap ma so sinh vien: ");
		fgets(SV[i].mssv, sizeof(SV[i].mssv),stdin);
    SV[i].mssv[strcspn(SV[i].mssv, "\n")] = 0;
		printf("Nhap ten sinh vien: ");
		fgets(SV[i].ten, sizeof(SV[i].ten),stdin);
    SV[i].ten[strcspn(SV[i].ten, "\n")] = 0;
    	printf("Nhap nam sinh: ");
    	scanf("%d",&SV[i].namsinh);
    	getchar();
    	printf("Nhap diem trung binh: ");
    	scanf("%f",&SV[i].diem);
    	getchar();
	}
}
void xuat(int n,SinhVien *SV){
	printf("\n===DANH SACH SINH VIEN===\n");
	printf("STT |\t HO TEN \t\t|MSSV |\t NAM SINH |\tDIEM\n");
		for(int i=0 ; i<n; i++){
			printf("%-4d|\t%-8s\t\t|%-5s|\t%-10d|\t%.2f\n",i+1,SV[i].ten,SV[i].mssv,SV[i].namsinh,SV[i].diem);
	}
}
void timkiemtheoma(int n, SinhVien*SV){
	char mssv[20];
	int kiemtra=0;
	printf("Nhap ma sinh vien can tim: ");
	getchar();
	fgets(mssv, sizeof(mssv),stdin);
    mssv[strcspn(mssv, "\n")] = 0;
	for(int i=0; i<n; i++){
	if(strcmp(SV[i].mssv,mssv)==0){
		printf("Co tim duoc sinh vien \n",mssv);
			printf("HO TEN \t\t|MSSV |\t NAM SINH |\tDIEM\n");
			printf("%-8s\t\t|%-5s|\t%-10d|\t%.2f\n",SV[i].ten,SV[i].mssv,SV[i].namsinh,SV[i].diem);
		kiemtra=1;}}
	if(kiemtra==0){
			printf("Khong tim thay sinh vien\n");		
	}
	}
void timkiemtheoten(int n, SinhVien*SV){
	char ten[50];
	int kiemtra=0;
	printf("Nhap ten sinh vien can tim: ");
	getchar();
	fgets(ten, sizeof(ten),stdin);
    ten[strcspn(ten, "\n")] = 0;
	for(int i=0; i<n; i++){
	if(strcmp(SV[i].ten,ten)==0){
		printf("Co tim duoc sinh vien \n");
			printf("HO TEN \t\t|MSSV |\t NAM SINH |\tDIEM\n");
			printf("%-8s\t\t|%-5s|\t%-10d|\t%.2f\n",SV[i].ten,SV[i].mssv,SV[i].namsinh,SV[i].diem);
		kiemtra=1;
	}}
	if(kiemtra==0){
			printf("Khong tim thay sinh vien\n");		
	}
	}
void themsinhvien(int n, SinhVien*SV){
SV = (SinhVien*)realloc(SV,(n+1)* sizeof(SinhVien));
	printf("Nhap thong tin sinh vien can them: \n");
	getchar();
	printf("Nhap ma so sinh vien: ");
		fgets(SV[n].mssv, sizeof(SV[n].mssv),stdin);
    SV[n].mssv[strcspn(SV[n].mssv, "\n")] = 0;
		printf("Nhap ten sinh vien: ");
		fgets(SV[n].ten, sizeof(SV[n].ten),stdin);
    SV[n].ten[strcspn(SV[n].ten, "\n")] = 0;
    	printf("Nhap nam sinh: ");
    	scanf("%d",&SV[n].namsinh);
    	getchar();
    	printf("Nhap diem trung binh: ");
    	scanf("%f",&SV[n].diem);
    	getchar();
    	n++;
	}
void timsinhvientheodiem(int n,SinhVien*SV){
	float diem;
	int kiemtra=0;
	printf("Nhap diem can tim: ");
	scanf("%f",&diem);
	getchar();
	for(int i=0; i<n; i++){
	if(SV[i].diem==diem){
		printf("Co tim duoc sinh vien \n");
			printf("HO TEN \t\t|MSSV |\t NAM SINH |\tDIEM\n");
			printf("%-8s\t\t|%-5s|\t%-10d|\t%.2f\n",SV[i].ten,SV[i].mssv,SV[i].namsinh,SV[i].diem);
		kiemtra=1;}}
	if(kiemtra==0){
			printf("Khong tim thay sinh vien\n");		
	}
		}
void timsinhvientheonam(int n,SinhVien*SV){
	int ns;
	int kiemtra=0;
	printf("Nhap nam sinh can tim: ");
	scanf("%d",&ns);
	getchar();
	for(int i=0; i<n; i++){
	if(SV[i].namsinh==ns){
		printf("Co tim duoc sinh vien \n");
			printf("HO TEN \t\t|MSSV |\t NAM SINH |\tDIEM\n");
			printf("%-8s\t\t|%-5s|\t%-10d|\t%.2f\n",SV[i].ten,SV[i].mssv,SV[i].namsinh,SV[i].diem);
		kiemtra=1;}}
	if(kiemtra==0){
			printf("Khong tim thay sinh vien\n");		
	}
		}
void sinhvienmax(int n, SinhVien*SV){
	float max=SV[0].diem;
	for(int i=0; i<n; i++){
		if(SV[i].diem>max){
			max=SV[i].diem;
			}}
	printf("Sinh vien co diem cao nhat bang: %.2f",max);
}
void sinhvienmin(int n, SinhVien*SV){
	float min=SV[0].diem;
	for(int i=0; i<n; i++){
		if(SV[i].diem<min){
			min=SV[i].diem;}}
	printf("Sinh vien co diem thap nhat bang: %.2f",min);
	}
void xoasinhvien(int n, SinhVien*SV){
	char mssv[50];
	int vitri=-1;
	printf("Nhap ma so sinh vien can xoa: ");
	getchar();
	fgets(mssv, sizeof(mssv),stdin);
    mssv[strcspn(mssv, "\n")] = 0;
    for(int i=0; i<n; i++){
    	if(strcmp(SV[i].mssv,mssv)==0){
    		vitri=i;}}
    	if(vitri==-1){
    		printf("Khong tim thay sinh vien can xoa\n") ;
    		return;}
    	for(int i =vitri; i<n-1;i++){
    		SV[i]=SV[i+1];}
    n--;
    SV = (SinhVien*)realloc(SV,(n)* sizeof(SinhVien));
      printf("Da xoa");		
	}								
int main(){
	int luachon;
	int n=0;
	SinhVien *SV=NULL;
    while (1) {
        printf("\n===== QUAN LY SINH VIEN =====\n");
        printf("1. NHAP THONG TIN SINH VIEN\n");
        printf("2. XEM DANH SACH SINH VIEN\n");
        printf("3. TIM KIEM SINH VIEN THEO MA\n");
        printf("4. TIM KIEM SINH VIEN THEO TEN\n");
        printf("5. THEM SINH VIEN VAO DANH SACH\n"); 
        printf("6. TIM KIEM SINH VIEN THEO DIEM\n");
        printf("7. TIM KIEM SINH VIEN THEO NAM SINH\n"); 
        printf("8. SINH VIEN CO DIEM CAO NHAT\n");  
        printf("9. SINH VIEN CO DIEM THAP NHAT\n");
        printf("10. XOA SINH VIEN THEO MA KHOI DANH SACH\n");            
        printf("11. THOAT\n");
        printf("Chọn chức năng: ");
        scanf("%d", &luachon);
    switch (luachon) {
            case 1:
            if (SV != NULL){
                free(SV);
            }
                do{
		printf("Nhap so luong sinh vien: ");
		scanf("%d",&n);
	}while(n<=0 || n>100);
	SV = (SinhVien*)malloc(n* sizeof(SinhVien));
	nhap(n,SV);
                break;
             case 2:
             xuat(n,SV);
             break;
             case 3:
             timkiemtheoma(n,SV);
             break;
             case 4:
             timkiemtheoten(n,SV);
             break;
             case 5:
             SV = (SinhVien*)realloc(SV,(n+1)* sizeof(SinhVien));
             themsinhvien(n++,SV);
             break;
             case 6:
             timsinhvientheodiem(n,SV);
             break;
             case 7:
             timsinhvientheonam(n,SV);
             break;
             case 8:
             sinhvienmax(n,SV);
             break;
             case 9:
             sinhvienmin(n,SV);
             break;
             case 10:
             xoasinhvien(n--,SV);
             break;
           case 11:
           free(SV);
            	return 0;
    
}
}
}