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
                printf(">>����ѧ����Ϣ,�밴��������ѧ�š����������ĳɼ���Ӣ��ɼ�����ѧ�ɼ���\n");
                AddStudent();
                break;
           case 2: 
                printf(">>ɾ��ѧ����Ϣ\n");
                DeleteStudent();
                break;
            case 3: 
                printf(">>����ѧ����Ϣ��������Ҫ����ѧ����ѧ�ţ�\n");
                FindStudent();
                break;
            case 4: 
                printf(">>��ӡ����ѧ����Ϣ\n");
                PrintAllStudent();
                break;
            case 5: 
                printf(">>�޸�ѧ����Ϣ���밴��������ѧ�š����������ĳɼ���Ӣ��ɼ�����ѧ�ɼ���\n");
                ChangeStudent();
                break;
            case 6:
                AddFromFile();
                printf(">>���ļ�����ѧ����Ϣ\n");
                break;
            case 7:
                PrintToFile();
                printf(">>��ӡѧ����Ϣ���ļ�\n");
                break;
            case 0:
                choice = 0;
                break;
        }

    } while(choice != 0);

    printf(">>���˳�����\n");

    return 0;
}

void DisplayMenu()
{
    printf("\t#===================�˵�===================#\n");
    printf("\t#                                          #\n");
    printf("\t#               1.����ѧ����Ϣ             #\n");
    printf("\t#                                          #\n");
    printf("\t#               2.ɾ��ѧ����Ϣ             #\n");
    printf("\t#                                          #\n");
    printf("\t#               3.����ѧ����Ϣ             #\n");
    printf("\t#                                          #\n");
    printf("\t#               4.��ӡ����ѧ����Ϣ         #\n");
    printf("\t#                                          #\n");
    printf("\t#               5.�޸�ѧ����Ϣ             #\n");
    printf("\t#                                          #\n");
    printf("\t#               6.���ļ�����ѧ����Ϣ       #\n");
    printf("\t#                                          #\n");
    printf("\t#               7.��ӡѧ����Ϣ���ļ�       #\n");
    printf("\t#                                          #\n");
    printf("\t#               0.�˳�����                 #\n");
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
    printf(">>�������\n");

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

    printf(">>��ɾ��ѧ��Ϊ��%s��ѧ����%s\n", array[flag].number, array[flag].name);

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

    printf(">>�ҵ�ѧ��Ϊ��%-3s��ѧ����%-8s ���ĳɼ���%-6.1f Ӣ��ɼ���%-6.1f ��ѧ�ɼ���%-6.1f\n",
            array[flag].number, array[flag].name, array[flag].chinese_grade, 
            array[flag].english_grade, array[flag].math_grade);

    
}

void PrintAllStudent()
{
    for (int i = 0; i < size; i++) {
        printf("ѧ��:%-3s ����:%-8s ���ĳɼ�:%-4.1f Ӣ��ɼ�:%-4.1f ��ѧ�ɼ�:%-4.1f\n", 
                array[i].number, array[i].name, 
                array[i].chinese_grade, array[i].english_grade, 
                array[i].math_grade);
    }

    printf(">>��ӡ���\n");
}

void ChangeStudent()
{
    Student student;

    char number[30] = "hello";
    printf(">>������Ҫ�޸ĵ�ѧ�ţ�\n");
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
    printf(">>�������\n");

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

    printf(">>�������\n");

    fclose(p_file);
}
