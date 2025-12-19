#include <cstdio> // printf를 사용하기 위해 필요

int main() {
    printf("%-15s%-15s%-11s%-10s\n", "SHIP NAME", "CLASS", "DEPLOYMENT", "IN SERVICE");
    printf("%-15s%-15s%-11s%-10s\n", "N2 Bomber", "Heavy Fighter", "Limited", "21");
    printf("%-15s%-15s%-11s%-10s\n", "J-Type 327", "Light Combat", "Unlimited", "1");
    printf("%-15s%-15s%-11s%-10s\n", "NX Cruiser", "Medium Fighter", "Limited", "18");
    printf("%-15s%-15s%-11s%-10s\n", "N1 Starfighter", "Medium Fighter", "Unlimited", "25");
    printf("%-15s%-15s%-11s%-10s\n", "Royal Cruiser", "Light Combat", "Limited", "4");

    return 0;
}

/*
    %-15s := 문자열(s)을 총 15자리로 출력하되, 내용은 **왼쪽(-)**에 정렬하고 남는 공간은 공백으로 채우라는 의미입니다.
*/