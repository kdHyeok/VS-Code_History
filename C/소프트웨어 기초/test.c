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
    printf("\n================���� ���================\n");
    for (int x=0; x< count; x++){
        printf("\n[ %s ]\n\n", Professor[x].name);
        printf("������: %s\n", Professor[x].lab);
        printf("��ȭ��ȣ: %s\n", Professor[x].call);
        printf("�̸���: %s\n", Professor[x].Email);
        printf("����: %s\n", Professor[x].classes);
        printf("�޸����: %s\n", Professor[x].memo);
        
    }

}
void search_Data(){
    //
    int tf;
    printf("\n================���� �˻�================\n");
    while (1)
    {
        int check;
        char Nam[100] = {0, };
        printf("\n���� ������ �˻��Ͻðڽ��ϱ�? (Yes: 1): ");
        scanf("%d",&check);
        if(check==1){
            
            printf("\n�������� �̸��� �Է����ּ���. : ");
            getc(stdin);
            fgets(Nam, sizeof(Nam), stdin);
            Nam[strlen(Nam) - 1] = '\0';
            for (int x=0; x< count; x++){
                tf = strcmp(Professor[x].name, Nam);
                if (tf == 0){
                    printf("\n[ %s ]\n\n", Professor[x].name);
                    printf("������: %s\n", Professor[x].lab);
                    printf("��ȭ��ȣ: %s\n", Professor[x].call);
                    printf("�̸���: %s\n", Professor[x].Email);
                    printf("����: %s\n", Professor[x].classes);
                    printf("�޸����: %s\n", Professor[x].memo);
                    break;
                }
            }
            if (tf != 0){
                printf("%s�� �����ϴ�.\n",Nam);
            }
        }
        else{
            printf("<�˻��� �����մϴ�.>\n");
            break;
        }
    }
}
void input_Data(){
    printf("\n================���� �Է�================\n");
    while (1)
    {
        int check;
        printf("\n���� ������ �߰��Ͻðڽ��ϱ�? (Yes: 1): ");
        scanf("%d",&check);
        if(check==1){
            printf("�̸�: ");
            getc(stdin);
            fgets(Professor[count].name, sizeof(Professor[count].name), stdin);
            Professor[count].name[strlen(Professor[count].name) - 1] = '\0';
            
            printf("������: ");
            fgets(Professor[count].lab, sizeof(Professor[count].lab), stdin);
            Professor[count].lab[strlen(Professor[count].lab) - 1] = '\0';

            printf("��ȭ��ȣ: ");
            fgets(Professor[count].call, sizeof(Professor[count].call), stdin);
            Professor[count].call[strlen(Professor[count].call) - 1] = '\0';

            printf("�̸���: ");
            fgets(Professor[count].Email, sizeof(Professor[count].Email), stdin);
            Professor[count].Email[strlen(Professor[count].Email) - 1] = '\0';

            printf("����: ");
            fgets(Professor[count].classes, sizeof(Professor[count].classes), stdin);
            Professor[count].classes[strlen(Professor[count].classes) - 1] = '\0';

            printf("�޸����: ");
            fgets(Professor[count].memo, sizeof(Professor[count].memo), stdin);
            Professor[count].memo[strlen(Professor[count].memo) - 1] = '\0';

            count++;
            printf("<�Է� �Ϸ�!>\n");
        }
        else{
            printf("<�Է��� �����մϴ�.>\n");
            break;
        }
    }
}
void Professor_code(){
    //
    FILE* ff = fopen("C:/Users/qaz00/OneDrive - ���ִ��б�/���� ȭ��/���� ����.txt", "r");
    load_txt(ff);
    while (1){
        //
        int choise;
        printf("\n [ ���� ��� ���: (1) ]\n [ ���� ���� �Է�: (2) ]\n [ ���� ���� �˻�: (3) ]\n������ �Ͻðڽ��ϱ�? : ");
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
            printf("<�����մϴ�.>\n");
            break;
        }
    }
}

int main(){
    Professor_code();

    return 0;
}