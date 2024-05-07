// 12S23019 - Clarasia L. Simanjuntak
// 12S23029 - Sintong Hutapea

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/gender.h"
#include "./libs/repository.h"

int main(int argc, char **argv)
{
    struct dorm_t *dorms = malloc(100 * sizeof(struct dorm_t));
    struct student_t *students = malloc(100 * sizeof(struct student_t));
    char string[100];
    char nim[12];
    char nama_siswa[50];
    char tahun[6];
    char nama_asrama[50];
    unsigned short capacity;
    char *teks_sementara;
    int sisw_a = 0, asram_a = 0;

    FILE *Mahasiswa;
    FILE *Asrama;
    Asrama = fopen("storage/dorm-repository.txt", "r");
    Mahasiswa = fopen("storage/student-repository.txt", "r");

    while (fgets(string, sizeof(string), Asrama) != NULL)
    {
        string[strcspn(string, "\n")] = '\0'; 
        dorms[asram_a] = create_dorm_repository(string);
        asram_a++;
    }

    while (fgets(string, sizeof(string), Mahasiswa) != NULL)
    {
        string[strcspn(string, "\n")] = '\0'; 
        teks_sementara = strtok(string, "|");
        strcpy(nim, teks_sementara);
        teks_sementara = strtok(NULL, "|");
        strcpy(nama_siswa, teks_sementara);
        teks_sementara = strtok(NULL, "|");
        strcpy(tahun, teks_sementara);
        teks_sementara = strtok(NULL, "|");

        if (strcmp(teks_sementara, "male") == 0)
        {
            students[sisw_a] = create_student_repository(nim, nama_siswa, tahun, GENDER_MALE);
        }
        else if (strcmp(teks_sementara, "female") == 0)
        {
            students[sisw_a] = create_student_repository(nim, nama_siswa, tahun, GENDER_FEMALE);
        }
        sisw_a++;
    }

    while (1)
    {
        fflush(stdout);
        if (fgets(string, sizeof(string), stdin) == NULL)
        {
            break;
        }
        string[strcspn(string, "\n")] = '\0';

        teks_sementara = strtok(string, "#");
        if (strcmp(teks_sementara, "---") == 0)
        {
            break;
        }
        else if (strcmp(teks_sementara, "student-print-all") == 0)
        {
            print_student(students, sisw_a);
        }
        else if (strcmp(teks_sementara, "student-add") == 0)
        {
            teks_sementara = strtok(NULL, "#");
            strcpy(nim, teks_sementara);
            teks_sementara = strtok(NULL, "#");
            strcpy(nama_siswa, teks_sementara);
            teks_sementara = strtok(NULL, "#");
            strcpy(tahun, teks_sementara);
            teks_sementara = strtok(NULL, "#");

            if (strcmp(teks_sementara, "male") == 0)
            {
                students[sisw_a] = create_student_repository(nim, nama_siswa, tahun, GENDER_MALE);
            }
            else if (strcmp(teks_sementara, "female") == 0)
            {
                students[sisw_a] = create_student_repository(nim, nama_siswa, tahun, GENDER_FEMALE);
            }
            sisw_a++;
        }
        else if (strcmp(teks_sementara, "dorm-print-all") == 0)
        {
            print_dorm(dorms, asram_a);
        }
        else if (strcmp(teks_sementara, "dorm-add") == 0)
        {
            teks_sementara = strtok(NULL, "#");
            strcpy(nama_asrama, teks_sementara);
            teks_sementara = strtok(NULL, "#");
            capacity = atoi(teks_sementara);
            teks_sementara = strtok(NULL, "#");
            if (strcmp(teks_sementara, "male") == 0)
            {
                dorms[asram_a] = create_dorm(nama_asrama, capacity, GENDER_MALE);
            }
            else if (strcmp(teks_sementara, "female") == 0)
            {
                dorms[asram_a] = create_dorm(nama_asrama, capacity, GENDER_FEMALE);
            }
            asram_a++;
        }
        else if (strcmp(teks_sementara, "student-print-all-detail") == 0)
        {
            print_student_detail(students, sisw_a);
        }
        else if (strcmp(teks_sementara, "dorm-print-all-detail") == 0)
        {
            print_dorm_detail(dorms, asram_a);
        }
    }
    fclose(Mahasiswa);
    fclose(Asrama);
    return 0;
}
