#include <stdio.h>
#include <stdlib.h>

void nhapMang(float* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%f", &a[i]);
    }
}

void xuatMang(float* a, int n) {
    printf("Mang: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");
}

float timMax(float* a, int n) {
    float max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max) max = a[i];
    return max;
}

float timMin(float* a, int n) {
    float min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min) min = a[i];
    return min;
}

float tinhTong(float* a, int n) {
    float tong = 0;
    for (int i = 0; i < n; i++)
        tong += a[i];
    return tong;
}

void demPhanTu(float* a, int n, int* duong, int* am, int* khong) {
    *duong = *am = *khong = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) (*duong)++;
        else if (a[i] < 0) (*am)++;
        else (*khong)++;
    }
}

int timViTri(float* a, int n, float x) {
    for (int i = 0; i < n; i++)
        if (a[i] == x) return i;
    return -1;
}

void sapXepTang(float* a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                float t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}

void menu() {
    printf("\n========== MENU ==========\n");
    printf("1. Nhap mang\n");
    printf("2. Xuat mang\n");
    printf("3. Tim MAX, MIN\n");
    printf("4. Tinh tong, trung binh\n");
    printf("5. Dem so duong/am/0\n");
    printf("6. Tim vi tri phan tu x\n");
    printf("7. Sap xep tang dan\n");
    printf("0. Thoat\n");
    printf("==========================\n");
    printf("Chon chuc nang: ");
}

int main() {
    int n = 0, luaChon;
    float* a = NULL;

    do {
        menu();
        scanf("%d", &luaChon);

        switch (luaChon) {
        case 1:
            printf("Nhap so phan tu: ");
            scanf("%d", &n);
            a = (float*)malloc(n * sizeof(float));
            nhapMang(a, n);
            break;

        case 2:
            if (a) xuatMang(a, n);
            else printf("Chua co du lieu. Vui long nhap mang truoc!\n");
            break;

        case 3:
            if (a)
                printf("MAX = %.2f, MIN = %.2f\n", timMax(a, n), timMin(a, n));
            else
                printf("Chua co du lieu!\n");
            break;

        case 4:
            if (a)
                printf("Tong = %.2f, Trung binh = %.2f\n", tinhTong(a, n), tinhTong(a, n) / n);
            else
                printf("Chua co du lieu!\n");
            break;

        case 5:
            if (a) {
                int d, am, k;
                demPhanTu(a, n, &d, &am, &k);
                printf("Duong: %d, Am: %d, 0: %d\n", d, am, k);
            } else
                printf("Chua co du lieu!\n");
            break;

        case 6:
            if (a) {
                float x;
                printf("Nhap gia tri can tim: ");
                scanf("%f", &x);
                int vt = timViTri(a, n, x);
                if (vt != -1)
                    printf("Tim thay tai vi tri %d\n", vt);
                else
                    printf("Khong tim thay!\n");
            } else
                printf("Chua co du lieu!\n");
            break;

        case 7:
            if (a) {
                sapXepTang(a, n);
                printf("Da sap xep tang dan.\n");
            } else
                printf("Chua co du lieu!\n");
            break;

        case 0:
            printf("Ket thuc chuong trinh.\n");
            break;

        default:
            printf("Lua chon khong hop le!\n");
        }

    } while (luaChon != 0);

    free(a);
    return 0;
}
