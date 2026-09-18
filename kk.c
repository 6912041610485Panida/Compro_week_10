#include <stdio.h>

int main(void) {
    /* แถว = นักศึกษา, คอลัมน์ = คะแนนสอบ 3 ครั้ง */
    int scores[3][3] = {
        {80, 75, 90},
        {68, 85, 72},
        {95, 88, 91}
    };

    printf("คะแนนของนักศึกษาคนที่ 2 ในการสอบครั้งที่ 3 = %d\n\n", scores[1][2]);

    for (int row = 0; row < 3; row++) {
        int sum = 0;
        printf("นักศึกษาคนที่ %d: ", row + 1);
        for (int column = 0; column < 3; column++) {
            printf("%d ", scores[row][column]);
            sum += scores[row][column];
        }
        printf("| รวม = %d\n", sum);
    }

    return 0;
}