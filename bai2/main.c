#include <stdio.h>

int main(void) {
    long long gia_co_so = 0;
    char size;
    int so_topping = 0;
    int member = 0;
    int don_hop_le = 0, don_loi = 0;
    long long tong_doanh_thu = 0;
    long long don_lon_nhat = 0;
    int N;

    printf("Nhap so luong hoa don: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        printf("\n--- Hoa don %d ---\n", i);

        printf("Nhap gia co so: ");
        scanf("%lld", &gia_co_so);

        printf("Nhap loai size: ");
        scanf(" %c", &size);

        printf("Nhap so topping: ");
        scanf("%d", &so_topping);

        printf("Nhap loai member (1: GOLD | 0: THUONG): ");
        scanf("%d", &member);

        if (gia_co_so <= 0 ||
            (size != 'S' && size != 'M' && size != 'L' &&
             size != 's' && size != 'm' && size != 'l')) {

            printf("Loi: Vui long nhap dung gia va size!\n");
            don_loi++;
            continue;
        }

        if (so_topping < 0) {
            printf("So topping khong the am!\n");
            break;
        }

        long long tong_tien;

        if (size == 'M' || size == 'm') {
            gia_co_so += 6000;
        } else if (size == 'L' || size == 'l') {
            gia_co_so += 10000;
        }

        tong_tien = gia_co_so + so_topping * 8000;

        if (member == 1) {
            tong_tien = tong_tien * 90 / 100;
        }

        printf("Tong tien hoa don: %lld VND\n", tong_tien);

        don_hop_le++;
        tong_doanh_thu += tong_tien;

        if (tong_tien > don_lon_nhat) {
            don_lon_nhat = tong_tien;
        }
    }

    printf("\n===== KET QUA CA BAN HANG =====\n");
    printf("So don hop le: %d\n", don_hop_le);
    printf("So don loi: %d\n", don_loi);
    printf("Tong doanh thu: %lld VND\n", tong_doanh_thu);
    printf("Don hang lon nhat: %lld VND\n", don_lon_nhat);

    return 0;
}