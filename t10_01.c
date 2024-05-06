// 12S23019 - Clarasia L. Simanjuntak
// 12S23029 - Sintong Hutapea

#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

int main(int _argc, char **_argv)
{
    struct dorm_t *dormitories  = malloc(50 * sizeof(struct dorm_t));
    struct student_t *students = malloc(50 * sizeof(struct student_t));
    char str[100];
    char id[12];
    char name[40];
    char year[6];
    char asrama[40];
    unsigned short capacity;
    char *teks_sementara;
    int index_siswa, index_asrama;
    int count_siswa = 0;
    int count_asrama = 0;
    
    FILE *mahasiswa; 
    FILE *asrama;
    asrama = fopen("storage/dorm-repository.txt", "r");
    mahasiswa = fopen("storage/student-repository.txt", "r");
    
    char order1[10];
    strcpy(order1, "student-print-all-detail");
    char order2[10];
    strcpy(order2, "student-add");
    char order3[10];
    strcpy(order3, "dorm-print-all-detail");
    char order4[10];
    strcpy(order4, "dorm-add");
    char order5[10];
    strcpy(order5, "assign-student");
    char order6[10];
    strcpy(order6, "move-student");
    char order7[10];
    strcpy(order7, "dorm-print-all"); 
    char order8[10];
    strcpy(order8, "student-print-all");

    while(1){
        fscanf(mahasiswa, "%[^\n]\n", str);
        teks_sementara = strtok(str, "|");
        strcpy(id, teks_sementara);
        teks_sementara = strtok(NULL, "|");
        strcpy(name, teks_sementara);
        teks_sementara = strtok(NULL, "|");
        strcpy(year, teks_sementara);
        teks_sementara = strtok(NULL, "|");
        // printf("%s\n", teks_sementara);
        if(strcmp(teks_sementara, "male") == 0){
        }
            student->gender == GENDER_MALE;
    }

    return 0;
}
