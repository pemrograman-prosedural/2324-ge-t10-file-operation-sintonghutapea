#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "student.h"

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender){
    struct student_t siswa;
    strcpy(siswa.id, _id);
    strcpy(siswa.name, _name);
    strcpy(siswa.year, _year);
    siswa.gender = _gender;
    siswa.dorm = malloc(sizeof(struct dorm_t));
    siswa.dorm = NULL;  
    return siswa;
}

void print_student(struct student_t *mahasiswa, int count){
    char type1[10];
    strcpy(type1, "male");
    char type2[10];
    strcpy(type2, "female");
    for(int i = 0; i < count; i++){
        if(mahasiswa[i].gender == 0){
        printf("%s|%s|%s|%s\n", mahasiswa[i].id, mahasiswa[i].name, mahasiswa[i].year, type1);
        }else if(mahasiswa[i].gender == GENDER_FEMALE){
        printf("%s|%s|%s|%s\n", mahasiswa[i].id, mahasiswa[i].name, mahasiswa[i].year, type2);}
    }
}

void print_student_detail(struct student_t *mahasiswa, int count){
    char type1[10];
    strcpy(type1, "male");
    char type2[10];
    strcpy(type2, "female");
    char type3[10];
    strcpy(type3, "unassigned");

    for(int i = 0; i < count; i++){
        if(mahasiswa[i].dorm == NULL){
            if(mahasiswa[i].gender == 0){
            printf("%s|%s|%s|%s|%s\n", mahasiswa[i].id, mahasiswa[i].name, mahasiswa[i].year, type1, type3);
            }
            else if(mahasiswa[i].gender == 1){
            printf("%s|%s|%s|%s|%s\n", mahasiswa[i].id, mahasiswa[i].name, mahasiswa[i].year, type2, type3);
            }
        }else{
            if(mahasiswa[i].gender == 0){
            printf("%s|%s|%s|%s|%s\n", mahasiswa[i].id, mahasiswa[i].name, mahasiswa[i].year, type1, mahasiswa[i].dorm->name);
            }else if(mahasiswa[i].gender == 1){
            printf("%s|%s|%s|%s|%s\n", mahasiswa[i].id, mahasiswa[i].name, mahasiswa[i].year, type2, mahasiswa[i].dorm->name);
            }
        }
    }
}

void assign_student(struct student_t *mahasiswa, struct dorm_t *dormitories, struct dorm_t *old_dorm, char *id, char *dorm_name){
    if(dormitories->residents_num < dormitories->capacity){
        if(mahasiswa->gender == dormitories->gender){
            mahasiswa->dorm = dormitories;
            dormitories->residents_num++;
        }
    }
}
void move_student(struct student_t *mahasiswa, struct dorm_t *dormitories, struct dorm_t *old_dorm, char *id, char *dorm_name){
    if(dormitories->residents_num < dormitories->capacity){
    if(mahasiswa->gender == dormitories){
        mahasiswa->dorm = dormitories;
        dormitories->residents_num++;
        old_dorm->residents_num--;
        }
    }
}