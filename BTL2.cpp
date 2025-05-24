#include<stdio.h>

#include<stdlib.h>

#include<string.h>
 //Cau truc sinh vien
typedef struct sinhVien {
  char mssv[10];
  char hoTen[50];
  float diem;
  struct sinhVien * next;
}
sinhVien;

//Goi ham
void themSV(sinhVien ** head);
void sapXepMSSV(sinhVien * head);
void hienThi(sinhVien * head);
void timKiem(sinhVien * head);
void giaiPhong(sinhVien * head);
void xoaSV(sinhVien ** head,
  const char * mssv);
void diemCaoNhat(sinhVien * head);

//Ham chinh
int main() {
  sinhVien * ds = NULL;
  int luaChon;

  do {
    printf("\n===== MENU =====\n");
    printf("1. Them sinh vien\n");
    printf("2. Hien thi danh sach\n");
    printf("3. Tim kiem theo MSSV\n");
    printf("4. Xoa sinh vien theo MSSV\n");
    printf("5. Sap xep theo MSSV\n");
    printf("6. Sinh vien co diem cao nhat\n");
    printf("0. Thoat\n");
    printf("Nhap lua chon: ");
    scanf("%d", & luaChon);
    getchar();

    switch (luaChon)
      case 1:
      themSV( & ds);
    break;
    case 2:
      hienThi(ds);
    break;
    case 3:
      timKiem(ds);
    break;
    case 4:
      xoaSV( & ds, "");
    break;
    case 5:
      sapXepMSSV(ds);
    printf("Da sap xep danh sach theo MSSV.\n");
    break;
    case 6:
      diemCaoNhat(ds);
    break;
    case 0:
      giaiPhong(ds);
    printf("Da thoat chuong trinh.\n");
    break;
    default:
    printf("Lua chon khong hop le.\n");
  }
}
while (luaChon != 0);

return 0;
}

//Ham them sinh vien
void themSV(sinhVien ** head) {
  sinhVien * newNode = (sinhVien * ) malloc(sizeof(sinhVien));
  if (!newNode) {
    printf("Khong du bo nho");
    return;
  }

  printf("Nhap MSSV: ");
  fgets(newNode -> mssv, sizeof(newNode -> mssv), stdin);
  newNode -> mssv[strcspn(newNode -> mssv, "\n")] = '\0';

  printf("Nhap ho va ten: ");
  fgets(newNode -> hoTen, sizeof(newNode -> hoTen), stdin);
  newNode -> hoTen[strcspn(newNode -> hoTen, "\n")] = '\0';

  printf("Nhap diem: ");
  scanf("%f", & newNode -> diem);
  getchar();

  newNode -> next = NULL;

  if ( * head == NULL) {
    * head = newNode;
  } else {
    sinhVien * temp = * head;
    while (temp -> next != NULL) {
      temp = temp -> next;
    }
    temp -> next = newNode;
  }
}
//Ham sap xep sinh vien
void sapXepMSSV(sinhVien * head) {
  if (head == NULL) return;
  for (sinhVien * p = head; p != NULL; p = p -> next) {
    for (sinhVien * q = p -> next; q != NULL; q = q -> next) {
      if (strcmp(p -> mssv, q -> mssv) > 0) {

        sinhVien temp = * p;
        * p = * q;
        * q = temp;
      }
    }
  }
}
//Ham hien thi danh sach
void hienThi(sinhVien * head) {
  printf("\n---Danh sach sinh vien---\n");
  sinhVien * temp = head;
  while (temp != NULL) {
    printf("%s | %s | Diem: %.2f \n", temp -> mssv, temp -> hoTen, temp -> diem);
    temp = temp -> next;
  }
}
//Tim kiem sinh vien theo mssv
void timKiem(sinhVien * head) {
  char masv[10];

  printf("Nhap MSSV can tim: ");
  fgets(masv, sizeof(masv), stdin);
  masv[strcspn(masv, "\n")] = '\0';

  sinhVien * temp = head;
  while (temp != NULL) {
    if (strcmp(temp -> mssv, masv) == 0) {
      printf("Tim thay: %s | %s | Diem: %.2f\n", temp -> mssv, temp -> hoTen, temp -> diem);
      return;
    }
    temp = temp -> next;
  }
  printf("Khong tim thay sinh vien");
}
//Ham xoa sinh vien
void xoaSV(sinhVien ** head,
  const char * dummy) {
  char mssv[10];
  printf("Nhap mssv can xoa: ");
  fgets(mssv, sizeof(mssv), stdin);
  mssv[strcspn(mssv, "\n")] = '\0';

  sinhVien * temp = * head, * prev = NULL;

  while (temp != NULL) {
    if (strcmp(temp -> mssv, mssv) == 0) {
      if (prev == NULL) {
        * head = temp -> next;
      } else {
        prev -> next = temp -> next;
      }
      free(temp);
      printf("Da xoa sinh vien co MSSV %s\n", mssv);
      return;
    }
    prev = temp;
    temp = temp -> next;
  }
  printf("Khong tim thay MSSV de xoa.\n");
}
//Ham sinh vien co diem cao nhat
void diemCaoNhat(sinhVien * head) {
  if (head == NULL) {
    printf("Danh sach rong.\n");
    return;
  }

  float max = head -> diem;
  sinhVien * temp = head;

  for (sinhVien * p = head; p != NULL; p = p -> next) {
    if (p -> diem > max) {
      max = p -> diem;
    }
  }

  printf("\nSinh vien co diem cao nhat (%.2f):\n", max);
  for (sinhVien * p = head; p != NULL; p = p -> next) {
    if (p -> diem == max) {
      printf("%s | %s | Diem: %.2f\n", p -> mssv, p -> hoTen, p -> diem);
    }
  }
}

//Giai Phong
void giaiPhong(sinhVien * head) {
  sinhVien * temp;
  while (head != NULL) {
    temp = head;
    head = head -> next;
    free(temp);
  }
}

