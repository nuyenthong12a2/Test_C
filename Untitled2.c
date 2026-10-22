#include <stdio.h>
#include <string.h>

#define MAX_SV 50

typedef struct {
    int maSV;
    char fullName[50];
    int age;
    float averageScore;
} Students;

void xoaBoDem(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int findmaSv(Students ds[], int n, int ma) {
    int i;
    for (i = 0; i < n; i++) {
        if (ds[i].maSV == ma) {
            return i;
        }
    }
    return -1;
}

int addStudent(Students ds[], int n) {
    Students sv;
    int len;
    if (n >= MAX_SV) {
        printf("\nDanh sach da day!\n");
        return n;
    }

    printf("\nNhap ma sinh vien : ");
    scanf("%d", &sv.maSV);
    xoaBoDem();

    if (findmaSv(ds, n, sv.maSV) != -1) {
        printf("\nMa sinh vien da ton tai!\n");
        return n;
    }

    printf("Nhap ho ten : ");
    fgets(sv.fullName, sizeof(sv.fullName), stdin);
    len = strlen(sv.fullName);
    if (len > 0 && sv.fullName[len - 1] == '\n') {
        sv.fullName[len - 1] = '\0';
    }

    printf("Nhap tuoi : ");
    scanf("%d", &sv.age);
    xoaBoDem();

    printf("Nhap diem TB : ");
    scanf("%f", &sv.averageScore);
    xoaBoDem();

    ds[n] = sv;
    printf("\nThem thanh cong !\n");
    return n + 1;
}

// Chuc nang 2 : Hien thi danh sach
void displayStudent(Students ds[],int n){
	if(n==0){
		printf("\nDanh sach hien dang trong !");
		return ;
	}
	printf ("\n================= DANH SACH SINH VIEN ====================\n");
	printf("%-5s|%-10s|%-25s|%-6s|%-8s\n","STT","Ma SV","Ho Ten","Tuoi","Diem TB");
	printf("-------------------------------------------------------------------\n");
	int i;
	for(i=0;i<n;i++){
		printf("%-5d|%-10d|%-25s|%-6d|%-8.2f\n",i+1,ds[i].maSV,ds[i].fullName,ds[i].age,ds[i].averageScore);
		
	}
	printf("================================================================\n");
	
}
// Chuc nang 3 : Cap nhat diem 
void updateScore(Students ds[],int n){
	if(n==0){
		printf("\nDanh sach hien dang trong !");
		return ; 
	} 
	int ma;
	printf("\nNhap ma sinh vien can cap nhat diem : ");
	scanf("%d",&ma);
	xoaBoDem();
	
	int position = findmaSv(ds,n,ma);
	if(position ==-1){
		printf("\nKhong tim thay sinh vien co ma %d\n",ma);
		return;
	}
	printf("\nTim thay : %s(Diem hien tai:%.2f\n)",ds[position].fullName,ds[position].averageScore);
	printf("\nNhap diem TB moi: ");
    scanf("%f", &ds[position].averageScore);
    xoaBoDem();

    printf("Cap nhat diem thanh cong!\n");
}
// Chuc nang 5 : Tim kiem sinh vien theo ma 
void searchStudent(Students ds[],int n){
	if(n==0){
		printf("\n Danh sach hien dang trong !");
		return ;
	}
	int ma;
	printf("\nNhap ma sinh vien can tim : ");
	scanf("%d",&ma);
	xoaBoDem();
	
	int Pos = findmaSv(ds,n,ma);
	if(Pos == -1){
		printf("\nKhong tim thay sinh vien co ma %d!\n",ma);
		return;
	}
	printf("\n-----THONG TIN SINH VIEN TIM THAY-----\n");
	printf("%-10s|%-25s|%-6s|%-8s\n","Ma SV","Ho Ten","Tuoi","Diem TB");
	printf("--------------------------------------------------------\n");
	printf("%-10d|%-25s|%-6d|%-8.2f\n",ds[Pos].maSV,ds[Pos].fullName,ds[Pos].age,ds[Pos].averageScore);
} 
int main() {
    Students ds[MAX_SV] = {
    {101,"Nguyen Van Thong ",19,3.84},
    {102,"Tran Thi Mai ",20,3.25},
    {103,"Le Hoang Nam",19,2.90},
    {104,"Nguyen Van Thanh",19,3.9},
    {105,"Le Hoang Nam",19,3.7}
   
		};
	
    int n = 5;
    int choice;

    do {
        printf("\n=========== QUAN LY SINH VIEN ==================");
        printf("\n1. Them sinh vien");
        printf("\n2. Hien thi danh sach");
        printf("\n3. Cap nhat diem");
        printf("\n4. Xoa sinh vien");
        printf("\n5. Tim kiem theo ma");
        printf("\n0. Thoat chuong trinh");
        printf("\n=================================");
        printf("\nNhap lua chon cua ban : ");
        scanf("%d", &choice);
        xoaBoDem();

        switch (choice) {
            case 1:
                n = addStudent(ds, n);
                break;
            case 2:
                displayStudent(ds, n);
                break;
            case 3:
                updateScore(ds,n);
                break;
            case 4:
                printf("\nChua lam\n");
                break;
            case 5:
            	searchStudent(ds,n);
                break;
            case 0:
                printf("\nKet thuc chuong trinh. Hen gap lai!\n");
                break;
            default:
                printf("\nLua chon cua ban khong hop le. Vui long thuc hien lai!\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
