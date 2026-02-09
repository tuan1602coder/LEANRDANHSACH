#include <stdio.h>
#include <string.h>
typedef struct {
    char ho_ten[50];
    char mssv[20];
    int nam_sinh;
    float diem_gpa;
} SinhVien;
void in_danh_sach(SinhVien ds[], int n) {
    printf("\n--- DANH SACH SINH VIEN ---\n");
    for (int i = 0; i < n; i++) {
        printf("MSSV: %s | Ten: %s | Nam sinh: %d | GPA: %.2f\n", 
               ds[i].mssv, ds[i].ho_ten, ds[i].nam_sinh, ds[i].diem_gpa);}
}
int tinh_chieu_dai(int n) {
    return n;}
int dem_sinh_vien_gpa_cao(SinhVien ds[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].diem_gpa > 3.2) {
            dem++; }
    }
    return dem;
}
void sap_xep_tang_dan(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diem_gpa > ds[j].diem_gpa) {
                SinhVien tam = ds[i];
                ds[i] = ds[j];
                ds[j] = tam;
            }}}}
void chen_sinh_vien_dung_thu_tu(SinhVien ds[], int *n, SinhVien sv_moi) {
    int i = *n - 1;
    while (i >= 0 && ds[i].diem_gpa > sv_moi.diem_gpa) {
        ds[i + 1] = ds[i];
        i--;
    }
    ds[i + 1] = sv_moi;
    (*n)++;
}
int main() {
    SinhVien ds_sinh_vien[100] = {
        {"Nguyen Van A", "SV001", 2003, 3.5},
        {"Tran Thi B", "SV002", 2003, 2.1},
        {"Le Van C", "SV003", 2002, 3.8},
        {"Pham Van D", "SV004", 2004, 3.0}
    };
    int so_luong = 4;
    in_danh_sach(ds_sinh_vien, so_luong);
    printf("\nChieu dai danh sach: %d\n", tinh_chieu_dai(so_luong));
    printf("So luong sinh vien co GPA > 3.2: %d\n", dem_sinh_vien_gpa_cao(ds_sinh_vien, so_luong));
    sap_xep_tang_dan(ds_sinh_vien, so_luong);
    SinhVien sv_moi = {"Sinh Vien Moi", "SV005", 2005, 2.4};
    chen_sinh_vien_dung_thu_tu(ds_sinh_vien, &so_luong, sv_moi);
    in_danh_sach(ds_sinh_vien, so_luong);
    return 0;
}