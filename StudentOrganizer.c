#include <stdio.h>
#include <string.h>

typedef struct{
        char name[15];
        float grades[10];
        float presence;
        float average;
        int tests;
}student;

void ShowUsers(int students, student Students[]){
    for(int n = 0; n < students; n++){
        int tests = Students[n].tests;
        printf("\n\n%s : %d | %c%f | %f \n", Students[n].name, tests, '%', Students[n].presence, Students[n].average);
        printf("\nGrades: ");
        for(int i = 0; i < tests; i++){
            printf("\nTest %d: %f ", i + 1,Students[n].grades[i]);
        }
    }
}
void OrderCheck(int students, student Students[]){
    printf("\nOrders:\nShowUsers(S)\nName Alphabet Organize(A)\nGrade Average Organize(G)\n");
    char order;
    scanf(" %c", &order);
    while (getchar() != '\n');
    switch(order){
        case 'S':
            ShowUsers(students, Students);
            break;
        case 'A':
            for(int i = 1; i < students; i++){
                if(Students[i].name[0] > Students[i - 1].name[0]){
                    student temp;
                    temp = Students[i];
                    Students[i] = Students[i - 1];
                    Students[i - 1] = temp;
                }
            }
            break;
        case 'G':
            for(int i = 1; i < students; i++){
                if(Students[i].average > Students[i - 1].average){
                    student temp;
                    temp = Students[i];
                    Students[i] = Students[i - 1];
                    Students[i - 1] = temp;
                }
            }
            break;
        default:
            printf("\nInvalid order");
            break;
    }
}

void CreateStudentsUser(int students, student Students[]){
    for(int i = 0; i < students;i++){
        Students[i] = (student){"", {0}, 0.0, 0.0, 0};
        student stud;
        stud.average = 0;
        int cul;
        printf("Student %d \n", i + 1);
        printf("Name of the student: ");
        scanf(" %14s", stud.name);
        printf("How many tests did he have: ");
        scanf(" %d", &stud.tests);
        for(int i = 0; i < stud.tests; i++){
            printf("%d• Grade: ", i + 1);
            scanf(" %f", &stud.grades[i]);
            stud.average += stud.grades[i];
        }
        stud.average = stud.average / (float) stud.tests;
        printf("\nWhats his presence: %c", '%');
        scanf(" %f", &stud.presence);
        Students[i] = stud;
        if(i == students - 1){
            ShowUsers(students, Students);
            OrderCheck(students, Students);
        }
        else{
            continue;
        }
    }
}

int main(){
    int students;
    int programa = 1;
    char name[15];
    printf("Welcome to the Students Organizer\nHere you gonna organize yours students by attributing them informations");
    printf("\nHow many students do you have?\n");
    scanf("%d", &students);
    student Students[students];

    
    CreateStudentsUser(students, Students);

    while(programa){
        char KeepG;
        printf("\nDo you want to continue? (y/n) \n");
        scanf(" %c", &KeepG);
        switch(KeepG){
            case 'y':
                ShowUsers(students, Students);
                OrderCheck(students, Students);
                break;
            case 'n':
                programa = 0;
                break;
            default:
                printf("Invalid option.");
                break;
        }
    }

    return 0;
}
