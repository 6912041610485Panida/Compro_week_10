#include <stdio.h>
#include <string.h>

int main() {
      // กำหนดจำนวนนักศึกษาและวิชาตามโจทย์
    int num_students = 3; 
    int num_subjects = 3;
    
    // อาร์เรย์สำหรับเก็บชื่อนักศึกษา (สูงสุด 50 ตัวอักษร)
    char students[3][50];
    
    // อาร์เรย์ 2 มิติสำหรับเก็บคะแนน [นักศึกษา][วิชา] 
    // วิชา: 0 = Math, 1 = Phy, 2 = Chem
    float scores[3][3];
    
    // อาร์เรย์สำหรับเก็บคะแนนเฉลี่ยของแต่ละวิชา
    float subject_average[3] = {0.0, 0.0, 0.0};
    
    // ชื่อวิชาสำหรับใช้ตอนแสดงผลและรับค่า
    char subjects[3][10] = {"Math", "Phy", "Chem"};

    // รับค่าชื่อและคะแนนของนักศึกษาทีละคน ทีละวิชา
    for (int i = 0; i < num_students; i++) {
        printf("กรอกชื่อนักศึกษาคนที่ %d: ", i + 1);
        scanf("%s", students[i]);
        
        for (int j = 0; j < num_subjects; j++) {
            printf("  กรอกคะแนนวิชา %s: ", subjects[j]);
            scanf("%f", &scores[i][j]);
        }
        printf("\n");
    }

    // คำนวานหาค่าเฉลี่ยของแต่ละวิชา
    for (int j = 0; j < num_subjects; j++) {
        float sum = 0;
        for (int i = 0; i < num_students; i++) {
            sum += scores[i][j];
        }
        subject_average[j] = sum / num_students;
    }

    // แสดงผลลัพธ์ในลักษณะตารางตามตัวอย่าง
    printf("==================================================\n");
    printf("%-20s %-10s %-10s %-10s\n", "Student (length)", "Math", "Phy", "Chem");
    printf("--------------------------------------------------\n");

    // แสดงข้อมูลนักศึกษาแต่ละคน (ชื่อ, ความยาวชื่อ, คะแนนทศนิยม 2 ตำแหน่ง)
    for (int i = 0; i < num_students; i++) {
        // ใช้ strlen() หาความยาวของชื่อนักศึกษา
        int length = strlen(students[i]);
        
        // จัดรูปแบบการแสดงผลชื่อพร้อมความยาว เช่น Ann (3)
        char name_with_len[60];
        sprintf(name_with_len, "%s (%d)", students[i], length);
        
        printf("%-20s %-10.2f %-10.2f %-10.2f\n", 
               name_with_len, scores[i][0], scores[i][1], scores[i][2]);
    }
    
    printf("--------------------------------------------------\n");
    // แสดงค่าเฉลี่ยของแต่ละวิชา (ทศนิยม 2 ตำแหน่ง)
    printf("%-20s %-10.2f %-10.2f %-10.2f\n", 
           "Subject average", subject_average[0], subject_average[1], subject_average[2]);
    printf("==================================================\n");

    return 0;
}
