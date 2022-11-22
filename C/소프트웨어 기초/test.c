#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Data_List{
    char name[100];
    char lab[100];
    char call[100];
    char Email[100];
    char classes[2000];
    char memo[1000];

}DL;

DL Professor[100];
int count = 0;


void load_txt(FILE* fp){
    int i = 0;
    char str[2000] = {0, };

    
    if(fp != NULL){
        //
        while (fgets(str, sizeof(str), fp) != NULL)
        {
            str[strlen(str) - 1] = '\0';
            if(i == 0){
                strcat(Professor[count].name, str);
                i++;
            }
            else if(i == 1){
                strcat(Professor[count].lab, str);
                i++;
            }
            else if(i == 2){
                strcat(Professor[count].call, str);
                i++;
            }
            else if(i == 3){
                strcat(Professor[count].Email, str);
                i++;
            }
            else if(i == 4){
                strcat(Professor[count].classes, str);
                i++;
            }
            else{
                strcat(Professor[count].memo, str);
                i = 0;
                count++;
            }
        }

        fclose(fp);
    } 
}
void print_Data(){
    //
    printf("\n================교수 목록================\n");
    for (int x=0; x< count; x++){
        printf("\n[ %s ]\n\n", Professor[x].name);
        printf("연구실: %s\n", Professor[x].lab);
        printf("전화번호: %s\n", Professor[x].call);
        printf("이메일: %s\n", Professor[x].Email);
        printf("수업: %s\n", Professor[x].classes);
        printf("메모사항: %s\n", Professor[x].memo);
        
    }

}
void search_Data(){
    //
    int tf;
    printf("\n================교수 검색================\n");
    while (1)
    {
        int check;
        char Nam[100] = {0, };
        printf("\n교수 정보를 검색하시겠습니까? (Yes: 1): ");
        scanf("%d",&check);
        if(check==1){
            
            printf("\n교수님의 이름을 입력해주세요. : ");
            getc(stdin);
            fgets(Nam, sizeof(Nam), stdin);
            Nam[strlen(Nam) - 1] = '\0';
            for (int x=0; x< count; x++){
                tf = strcmp(Professor[x].name, Nam);
                if (tf == 0){
                    printf("\n[ %s ]\n\n", Professor[x].name);
                    printf("연구실: %s\n", Professor[x].lab);
                    printf("전화번호: %s\n", Professor[x].call);
                    printf("이메일: %s\n", Professor[x].Email);
                    printf("수업: %s\n", Professor[x].classes);
                    printf("메모사항: %s\n", Professor[x].memo);
                    break;
                }
            }
            if (tf != 0){
                printf("%s가 없습니다.\n",Nam);
            }
        }
        else{
            printf("<검색을 종료합니다.>\n");
            break;
        }
    }
}
void input_Data(){
    printf("\n================교수 입력================\n");
    while (1)
    {
        int check;
        printf("\n교수 정보를 추가하시겠습니까? (Yes: 1): ");
        scanf("%d",&check);
        if(check==1){
            printf("이름: ");
            getc(stdin);
            fgets(Professor[count].name, sizeof(Professor[count].name), stdin);
            Professor[count].name[strlen(Professor[count].name) - 1] = '\0';
            
            printf("연구실: ");
            fgets(Professor[count].lab, sizeof(Professor[count].lab), stdin);
            Professor[count].lab[strlen(Professor[count].lab) - 1] = '\0';

            printf("전화번호: ");
            fgets(Professor[count].call, sizeof(Professor[count].call), stdin);
            Professor[count].call[strlen(Professor[count].call) - 1] = '\0';

            printf("이메일: ");
            fgets(Professor[count].Email, sizeof(Professor[count].Email), stdin);
            Professor[count].Email[strlen(Professor[count].Email) - 1] = '\0';

            printf("수업: ");
            fgets(Professor[count].classes, sizeof(Professor[count].classes), stdin);
            Professor[count].classes[strlen(Professor[count].classes) - 1] = '\0';

            printf("메모사항: ");
            fgets(Professor[count].memo, sizeof(Professor[count].memo), stdin);
            Professor[count].memo[strlen(Professor[count].memo) - 1] = '\0';

            count++;
            printf("<입력 완료!>\n");
        }
        else{
            printf("<입력을 종료합니다.>\n");
            break;
        }
    }
}
void Professor_code(){
    //
    FILE* ff = fopen("C:/Users/qaz00/OneDrive - 전주대학교/바탕 화면/교수 정보.txt", "r");
    load_txt(ff);
    while (1){
        //
        int choise;
        printf("\n [ 교수 목록 출력: (1) ]\n [ 교수 정보 입력: (2) ]\n [ 교수 정보 검색: (3) ]\n무엇을 하시겠습니까? : ");
        scanf("%d",&choise);
        if(choise==1){
            print_Data();
        }
        else if (choise==2)
        {
            input_Data();
        }
        else if (choise==3)
        {
            search_Data();
        }
        else{
            printf("<종료합니다.>\n");
            break;
        }
    }
}

int main(){
    Professor_code();

    return 0;
}