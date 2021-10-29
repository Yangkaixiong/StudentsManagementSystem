#include<stdio.h>
#include<string.h>

typedef struct Student {
    char number[30];
    char name[30];
    float chinese_grade;
    float english_grade;
    float math_grade;
} Student;

Student array[100];
unsigned size = 0;

void DisplayMenu();
void AddStudent();
void DeleteStudent();
void FindStudent();
void PrintAllStudent();
void ChangeStudent();
void AddFromFile();
void PrintToFile();


int main()
{
    int choice = 10;
    
    do {
        DisplayMenu();
        scanf("%d", &choice);

      switch (choice) {
            case 1: 
                printf(">>增加学生信息,请按次序输入学号、姓名、语文成绩、英语成绩、数学成绩：\n");
                AddStudent();
                break;
           case 2: 
                printf(">>删除学生信息\n");
                DeleteStudent();
                break;
            case 3: 
                printf(">>查找学生信息，请输入要查找学生的学号：\n");
                FindStudent();
                break;
            case 4: 
                printf(">>打印所有学生信息\n");
                PrintAllStudent();
                break;
            case 5: 
                printf(">>修改学生信息，请按次序输入学号、姓名、语文成绩、英语成绩、数学成绩：\n");
                ChangeStudent();
                break;
            case 6:
                AddFromFile();
                printf(">>从文件增加学生信息\n");
                break;
            case 7:
                PrintToFile();
                printf(">>打印学生信息到文件\n");
                break;
            case 0:
                choice = 0;
                break;
        }

    } while(choice != 0);

    printf(">>已退出程序\n");

    return 0;
}

void DisplayMenu()
{
    printf("\t#===================菜单===================#\n");
    printf("\t#                                          #\n");
    printf("\t#               1.增加学生信息             #\n");
    printf("\t#                                          #\n");
    printf("\t#               2.删除学生信息             #\n");
    printf("\t#                                          #\n");
    printf("\t#               3.查找学生信息             #\n");
    printf("\t#                                          #\n");
    printf("\t#               4.打印所有学生信息         #\n");
    printf("\t#                                          #\n");
    printf("\t#               5.修改学生信息             #\n");
    printf("\t#                                          #\n");
    printf("\t#               6.从文件增加学生信息       #\n");
    printf("\t#                                          #\n");
    printf("\t#               7.打印学生信息到文件       #\n");
    printf("\t#                                          #\n");
    printf("\t#               0.退出程序                 #\n");
    printf("\t#==========================================#\n");
}

void AddStudent()
{
    Student student;

    scanf("%s", student.number);
    scanf("%s", student.name);
    scanf("%f", &student.chinese_grade);
    scanf("%f", &student.english_grade);
    scanf("%f", &student.math_grade);
    printf(">>输入完毕\n");

    array[size] = student;
    ++size;  
}
void DeleteStudent()
{
    char number[30] = "hello";
    scanf("%s", number);

    int flag = 0;
    while (strcmp(number, array[flag].number)) {
        flag++;
    }

    printf(">>已删除学号为：%s的学生：%s\n", array[flag].number, array[flag].name);

    for (; flag < size-1; flag++) {
        array[flag] = array[flag+1];
    }
    size--;

}

void FindStudent()
{
    char number[30] = "hello";
    scanf("%s", number);

    int flag = 0;
    while (strcmp(number, array[flag].number)) {
        flag++;
    }

    printf(">>找到学号为：%-3s的学生：%-8s 语文成绩：%-6.1f 英语成绩：%-6.1f 数学成绩：%-6.1f\n",
            array[flag].number, array[flag].name, array[flag].chinese_grade, 
            array[flag].english_grade, array[flag].math_grade);

    
}

void PrintAllStudent()
{
    for (int i = 0; i < size; i++) {
        printf("学号:%-3s 姓名:%-8s 语文成绩:%-4.1f 英语成绩:%-4.1f 数学成绩:%-4.1f\n", 
                array[i].number, array[i].name, 
                array[i].chinese_grade, array[i].english_grade, 
                array[i].math_grade);
    }

    printf(">>打印完毕\n");
}

void ChangeStudent()
{
    Student student;

    char number[30] = "hello";
    printf(">>请输入要修改的学号：\n");
    scanf("%s", number);

    int flag = 0;
    while (strcmp(number, array[flag].number)) {
        flag++;
    }

    scanf("%s", student.number);
    scanf("%s", student.name);
    scanf("%f", &student.chinese_grade);
    scanf("%f", &student.english_grade);
    scanf("%f", &student.math_grade);

    array[flag] = student;
    printf(">>输入完毕\n");

}

void PrintToFile()
{
    FILE *p_file = NULL;

    p_file = fopen("D:\\Projects\\StudentsSystem\\StudentsData.txt", "wb");
    
    if (!p_file) {
        printf("error!!!\n");
        return;
    }

    for (int i = 0; i < size-1; i++) {
        fprintf(p_file, "%s %s %f %f %f\n", array[i].number, array[i].name, 
                array[i].chinese_grade, array[i].english_grade, 
                array[i].math_grade);
        fflush(stdin);
    }

    if (size > 0) {
        fprintf(p_file, "%s %s %f %f %f", array[size-1].number, array[size-1].name, 
                array[size-1].chinese_grade, array[size-1].english_grade, 
                array[size-1].math_grade);
        fflush(stdin);
    }

    fclose(p_file);
}

void AddFromFile()
{
    FILE *p_file = NULL;

    p_file = fopen("D:\\Projects\\StudentsSystem\\StudentsData.txt", "r");
    
    if (!p_file) {
        printf("error!!!\n");
    }

    int i = 0;
    while (!feof(p_file)) {
        fscanf(p_file, "%s %s %f %f %f\n", array[i].number, array[i].name, 
                &array[i].chinese_grade, &array[i].english_grade, 
                &array[i].math_grade);
        i++;
    }

    size = i;

    printf(">>加载完毕\n");

    fclose(p_file);
}
