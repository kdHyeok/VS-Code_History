#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define _CRT_SECURE_NO_WARNINGS


//=======================================================================================================================================�ټ� ��Ʈ
//������ȹ

#define Max 1000
#define Years 12

int year; // ����� �Է� ����
int month; // ����� �Է� ����

struct plan
{
    char content[Max];
};

struct plan p2020[Years], p2021[Years], p2022[Years];

int leapYear(int a) {
    if ((a % 4 == 0) && !(a % 100 == 0) || (a % 400 == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

void calender()
{
    int k;
    int sum = 365;
    int check = 0;
    int CalenderYear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    printf("������� �޷��� ��,���� �Է����ּ���.\nex)  2021 12 : ");
    scanf("%d %d%*c", &year, &month); 
    // %*c�� �ؾ� �ڿ� ���ۿ� ���� ���Ͱ��� ���� �ڿ� ���� gets���� ���Ͱ��� ���а� �Ѵ�. ���� �Ⱦ��� gets���� �׳� �Ѿ����!

    // �������� Ȯ��
    if (leapYear(year)) 
    {
        check = 1;
        CalenderYear[1] = 29;
    }
    else
    {
        check = 0;
    }

    //0����� �۳���� �������� ����.
    for (int i = 1; i < year; i++)
    {
        if (leapYear(i))
        {
            sum += 366;
        }

        else
        {
            sum += 365;
        }
    }

    //�Է��� �ޱ��� ��ĥ���� 
    for (int i = 0; i < month - 1; i++) 
    {
        sum += CalenderYear[i];
    }

    //�Է��� ���� 1���� ���� �������� ���
    k = sum % 7;

    //���
    printf("\n\t\t  %d��\t%d��\n", year, month);
    printf("===================================================\n");
    printf("��\t��\tȭ\t��\t��\t��\t��\n");
    printf("===================================================\n");


    //���� ���Ͽ� ���� ����
    for (int j = 0; j < k; j++) 
    {
        printf("\t");
    }

    for (int i = 1; i <= CalenderYear[month - 1]; i++) 
    {
        printf("%d\t", i);
        if (k == 6) 
        {
            k = -1;
            printf("\n");
        }
        k++;
    }
    printf("\n\n");
}


int scheduleRead()
{
    FILE* f;

    char days[20] = { 0x00, };
    //char line[300];

    sprintf(days, "%d %d.txt", year, month);

    if (year == 2021)
    {
        int number = 0;

        f = fopen(days, "r");

        if (f == NULL)
        {
            printf("���� ������ ���� ���Դϴ�!\n");

            return 0;
        }

        printf("=======================�� ��=======================\n");

        if (NULL != f)
        {
            while (fgets(p2021[month - 1].content, Max, f) != NULL)
            {
                number++;
                printf("[%d]��° ���� : %s\n", number, p2021[month - 1].content);
            }
        }

        fclose(f);


    }

    else if (year == 2020)
    {
        int i = 0;
        f = fopen(days, "r");

        if (f == NULL)
        {
            printf("���� ������ ���� ���Դϴ�!\n");

            return 0;
        }

        if (NULL != f)
        {
            printf("���� ���� ����\n");
            while (fgets(p2020[month - 1].content, Max, f) != NULL)
            {
                printf("%s\n", p2020[month - 1].content);
            }
        }

        fclose(f);
    }

    else if (year == 2022)
    {
        int i = 0;
        f = fopen(days, "r");

        if (f == NULL)
        {
            printf("���� ������ ���� ���Դϴ�!\n");

            return 0;
        }

        if (NULL != f)
        {
            printf("���� ���� ����\n");
            while (fgets(p2022[month - 1].content, Max, f) != NULL)
            {
                printf("%s\n", p2022[month - 1].content);
            }
        }

        fclose(f);
    }

    else
    {
        printf("�� ��ȹǥ���� �������� �ʴ� �⵵�Դϴ�!!");
    }
}

void scheduleAppend()
{
    FILE* f;

    char days[20] = { 0x00, };

    int again;

    sprintf(days, "%d %d.txt", year, month);

    scheduleRead();

    f = fopen(days, "a");

    printf("�߰��� ��ȹ�� ��������(�ѹ��� �ѹ��� �߰��ϼ���)\n");
    fgets(p2021[month - 1].content, Max, stdin);

    fputs(p2021[month - 1].content, f);

    fclose(f);

    printf("������ �߰��߽��ϴ�!\n\n�޴��� �����ðڽ��ϱ�? 1���� �����ø� �����ϴ�. 2���� ������ �� �ۼ��ƴ��� Ȯ���մϴ�. : ");
    scanf("%d", &again);

    if (again == 1)
    {
        "���� �޴��� �����ϴ�.\n";
    }

    else if (again == 2)
    {
        scheduleRead();
        printf("���� �޴��� �����ϴ�!\n");
    }
}

void scheduleWrite()
{
    FILE* f;

    char days[20] = { 0x00, };

    int again;

    sprintf(days, "%d %d.txt", year, month);

    f = fopen(days, "w");

    printf("��ȹ�� ��������(�ѹ��� �ѹ��� �߰��ϼ���)\n");
    fgets(p2021[month - 1].content, Max, stdin);

    fputs(p2021[month - 1].content, f);

    fclose(f);

    printf("������ �߰��߽��ϴ�!\n\n�޴��� �����ðڽ��ϱ�? 1���� �����ø� �����ϴ�. 2���� ������ �� �ۼ��ƴ��� Ȯ���մϴ�. : ");
    scanf("%d", &again);

    if (again == 1)
    {
        "���� �޴��� �����ϴ�.\n";
    }
    
    else if (again == 2)
    {
        scheduleRead();
        printf("���� �޴��� �����ϴ�!\n");
    }
}

int Menu()
{
    int num;

    while (1)
    {
        printf("\n---------------------���� ��ȹǥ---------------------\n");
        printf("1. �޷¸� ����\n");
        printf("2. ���� ����\n");
        printf("3. ���� �̾ �ۼ��ϱ�\n");
        printf("4. ���� ������� ���ξ���\n");
        printf("5. ���� �޴��� ������\n\n");

        printf("�޴����� ���ϴ� ����� �������ּ��� : ");
        scanf("%d", &num);
        system("cls");

        switch (num)
        {
        case 1:
            calender();
            break;

        case 2:
            printf("���� �ִ� ���� ����� �ҷ��ɴϴ�.\n");
            calender();
            scheduleRead();
            break;

        case 3:
            calender();
            printf("������ �߰��մϴ�.\n");
            scheduleAppend();
            break;

        case 4:
            calender();
            printf("������ �� ����ϴ�! �ٽ� �ۼ��� �ּ���.\n");
            scheduleWrite();
            break;

        case 5:
            printf("���� �޴��� �����ϴ�.\n");
            system("cls");
            return 0;
            break;
        }
    }
}
//--------------------------------------------------------------------------------------------���޾�ü 

#define Max2 100
#define MAX2 500

struct store
{
	char name[20];
	char address[30];
	char benefit[50];
    char content[MAX2];
};
struct store add[Max2], area1, area2, area3;

int i = 0;
int num;

void storeWrite()
{
    FILE* f;

    char select[20];

    printf("ü�޾�ü ������ �߰��ϰ� ���� ��Ҹ� ������. (����Ʈ�� �ִ� ��� �̸��� �Ȱ��� ��������)\n1.������ ������\n2.�Žð���\n3.�� �� ���\n���ϴ� ��� : ");
    gets(select); // gets�� ���� ���� ���ڿ� �Է�

    char names[20] = { 0x00, };
    sprintf(names, "%s.txt", select);  //sprintf(���� ���ڿ�, ������ ���ڿ� ����, print���� ���� ���� ����� ����)

    f = fopen(names, "a");

    if (f == NULL)
    {
        printf("���� ���� ������ ���� ���Դϴ�. ���� ������ �ۼ��մϴ�!\n");
    }

    printf("�߰��� ������ ��ȣ���� �����ּ��� : ");
    scanf("%[^\n]%*c", add[i].name);                                // %*c�� �־�� scanf�� �а� ���ۿ� ���� \n�� ���༭ �ڿ� �� gets�� \n�� �ö����� 
                                                                    // ���ڿ��� �����ϴ� �ڵ��ε� ���ۿ��� \n�� �Ȼ��ָ� gets���� �ٷ� �Ѿ�� ������ �� �־���Ѵ�.
    printf("������ ��ġ�� �����ּ��� : ");
    scanf("%[^\n]%*c", add[i].address);

    printf("������ ������ �����ּ��� : ");
    scanf("%[^\n]%*c", add[i].benefit);

    fprintf(f, "���� �̸� : %s      ��ġ : %s     ���� : %s\n", add[i].name, add[i].address, add[i].benefit);

    fclose(f);
}

void storeRead()
{
    FILE* f;

    char select[20];

    printf("���޾�ü ����Ʈ�� ������� ��Ҹ� ������. (����Ʈ�� �ִ� ��� �̸��� �Ȱ��� ��������)\n1.������ ������\n2.�Žð���\n3.�� �� ���\n���ϴ� ��� : ");
    gets(select);

    char names[20] = { 0x00, };
    sprintf(names, "%s.txt", select);

    if (strcmp(select, "������ ������") == 0)     //srtcmp = ���ڿ� ��
    {
        f = fopen(names, "r");
        int count = 1;

        if (f == NULL)
        {
            printf("���� ������ ���� ���Դϴ�. �ڷ� ���ϴ�.");
        }

        else if (f != NULL)
        {
            printf("�������� �������� �ִ� ���� ���� ��ü ����� �ҷ��ɴϴ�. \n");

            while (fgets(area1.content, Max2, f) != NULL)
            {

                printf("[%d]��° ���� : %s\n", count, area1.content);
                count++;
            }
            fclose(f);
        }

    }

    else if (strcmp(select, "�Žð���") == 0)
    {
        f = fopen(names, "r");
        int count = 1;

            if (f == NULL)
            {
                printf("���� ������ ���� ���Դϴ�. �޴��� ���ư��ϴ�.");
            }

            else if (f != NULL)
            {
                printf("�Žð����� �ִ� ���� ���� ��ü ����� �ҷ��ɴϴ�. \n");

                while (fgets(area1.content, Max2, f) != NULL)
                {

                    printf("[%d]��° ���� : %s\n", count, area1.content);
                    count++;
                }
                fclose(f);
            }
    }

    else if (strcmp(select, "�� �� ���") == 0)
    {
        f = fopen(names, "r");
        int count = 1;

        if (f == NULL)
        {
            printf("���� ������ ���� ���Դϴ�. �޴��� ���ư��ϴ�.");
        }

        else if (f != NULL)
        {
            printf("���� ���� ��ü ����� �ҷ��ɴϴ�. \n");

            while (fgets(area1.content, Max2, f) != NULL)
            {

                printf("[%d]��° ���� : %s\n", count, area1.content);
                count++;
            }
            fclose(f);
        }
    }
    
    else
    {
        printf("���� ������ ���� ���Դϴ�. �߰��ϼ���.");
    }
}

int storeMenu()
{
    int check = 0;

    while (check == 0)
    {
        printf("\n---------------------(2017�� ����)���� ��ó ���� ��ü---------------------\n");
        printf("(���� �л��� ���� �� ��!)\n");
        printf("1. ���� ��ü ��� ����\n");
        printf("2. ���� ��ü �߰��ϱ�\n");
        printf("3. ���� �޴��� ������\n\n");

        printf("�޴����� ���ϴ� ����� �������ּ��� : ");
        scanf("%d%*c", &num);

        switch (num)
        {
        case 1:
            storeRead();
            break;

        case 2:
            storeWrite();
            break;

        case 3:
            printf("���� �޴��� �����ϴ�.\n");
            check = 1;
            break;
        }
    }
}

//=========================================================================================================================================���� ��Ʈ
//���� ���� ����
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
        printf("\n���� ������ �˻��Ͻðڽ��ϱ�? (Yes: 1, No: 2): ");
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
                printf("<!>�������� �ʴ� �����Դϴ�.( %s )\n",Nam);
            }
        }
        else if(check==2){
            system("cls");
            //printf("<�˻��� �����մϴ�.>\n");
            break;
        }
    }
}
void input_Data(){
    printf("\n================���� �Է�================\n");
    
    while (1)
    {
        int check;
        printf("\n���� ������ �߰��Ͻðڽ��ϱ�? (Yes: 1, No: 2): ");
        scanf("%d",&check);
        if(check==1){
            FILE* fp = fopen("ProfessorData.txt", "a");
            printf("�̸�: ");
            getc(stdin);
            fgets(Professor[count].name, sizeof(Professor[count].name), stdin);
            fputs(Professor[count].name, fp);
            Professor[count].name[strlen(Professor[count].name) - 1] = '\0';
            
            printf("������: ");
            fgets(Professor[count].lab, sizeof(Professor[count].lab), stdin);
            fputs(Professor[count].lab, fp);
            Professor[count].lab[strlen(Professor[count].lab) - 1] = '\0';

            printf("��ȭ��ȣ: ");
            fgets(Professor[count].call, sizeof(Professor[count].call), stdin);
            fputs(Professor[count].call, fp);
            Professor[count].call[strlen(Professor[count].call) - 1] = '\0';

            printf("�̸���: ");
            fgets(Professor[count].Email, sizeof(Professor[count].Email), stdin);
            fputs(Professor[count].Email, fp);
            Professor[count].Email[strlen(Professor[count].Email) - 1] = '\0';

            printf("����: ");
            fgets(Professor[count].classes, sizeof(Professor[count].classes), stdin);
            fputs(Professor[count].classes, fp);
            Professor[count].classes[strlen(Professor[count].classes) - 1] = '\0';

            printf("�޸����: ");
            fgets(Professor[count].memo, sizeof(Professor[count].memo), stdin);
            fputs(Professor[count].memo, fp);
            Professor[count].memo[strlen(Professor[count].memo) - 1] = '\0';

            count++;
            printf("<�Է� �Ϸ�!>\n");
            fclose(fp);
        }
        else if(check==2){
            system("cls");
            //printf("<�Է��� �����մϴ�.>\n");
            
            break;
        }
    }
}
void Professor_code(){
    //
    FILE* ff = fopen("ProfessorData.txt", "r");
    load_txt(ff);
    while (1){
        //
        int choise;
        printf("\n================ [���� ���� ����] ================\n");
        printf("\n [ ���� ��� ���: (1) ]\n [ ���� ���� �Է�: (2) ]\n [ ���� ���� �˻�: (3) ]\n [     ������ : (4)    ]\n\n - ������ �Ͻðڽ��ϱ�? : ");
        scanf("%d",&choise);
        system("cls");
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
        else if (choise==4){
            printf("<�����մϴ�.>\n");
            system("cls");
            break;
        }
    }
}

//========================================================================================================================================�ƿ� ��Ʈ
//���� ��ûȮ��
#define MAX_STR_LEN 200

struct _sugang
{
	char name[MAX_STR_LEN];
	int name_num;
};
typedef struct _sugang sugang;

int class_check(){
	sugang dic[MAX_STR_LEN];
	int choice;


	while (1)
	{
		printf("1. ���� ��� �Է�\n");
		printf("2. �⼮ ��� ����\n");
		printf("3. ���⼮ ��� Ȯ��\n");
		printf("4. ����\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			system("cls");
			printf("���� ��� �Է� ����!\n");
			FILE* stri;
			FILE* re_endsub;

			int sugang_num;
			printf("�������� ������ ������ �Է��Ͻÿ�.:");
			scanf("%d", &sugang_num);

			stri = fopen("striming.txt", "w+");
			printf("\n�������� ������ ���پ� �Է��ϼ���.\n ex.1 ����\n    2 ����\n");
			for (int i = 0; i < sugang_num; i++) {

				scanf("%d %s", &dic[i].name_num, dic[i].name);
				fprintf(stri, "%s \n", dic[i].name);
			}

			fclose(stri);
			printf("\n������ ����Ǿ����ϴ�.\n\n\n");
			break;

		case 2:
			system("cls");
			printf("�⼮ ��� ���� ����!!\n\n");
			printf("���� ����ڰ� �����ϴ� ������\n");
			for (int i = 0; i < sugang_num; i++) {
				printf("%d %s \n", dic[i].name_num, dic[i].name);
			}
			printf("�Դϴ�.\n\n\n");

			int end_sub = 0;
			printf("�� �� ������ ������ ��ȣ�� �Է��ϼ���.(�Է¿Ϸ�� 0�� �Է�):");
			scanf("%d", &end_sub);

			for (int i = 0; i < sugang_num; i++) {
				if (dic[i].name_num == end_sub) {
					for (int j = i; j < sugang_num ; j++) {
						dic[j] = dic[j + 1];

						dic[j].name_num = j + 1;
					}
				}
			}
			printf("���� ������\n");
			re_endsub = fopen("re.txt", "w+");
			for (int k = 0; k < sugang_num; k++) {
				printf("%d %s\n", dic[k].name_num, dic[k].name);
				fprintf(re_endsub, "%s\n", dic[k].name);

			}

			fclose(re_endsub);
			break;

		case 3:
			system("cls");
			printf("���⼮ ��� Ȯ�μ���!!\n");
			re_endsub = fopen("re.txt", "r");

			char re_sub[MAX_STR_LEN] = { 0, };

			fread(re_sub, 1, MAX_STR_LEN, re_endsub);
			printf("%s\n", re_sub);

			fclose(re_endsub);
			break;

		case 4:
			printf("�����ϰ� ���ἱ��!!\n");
			return 0;
		}

	}
}
//====================================================================================================================���� ��Ʈ
//���� �޸���
#define MAX 100

void save_file();
int read_file();

struct memo {
	int date;       // �޸� ��¥ 
	char title[10]; // �޸� ����
	char memo[100]; // �޸� ���� 
};

struct memo MEMO[100];
int number = 0;


int Notepad(){
	int select, i;

	
	while(1)
	{
		int num;
		printf("1. �޸� �Է�   2. �޸� ���   3. ������\n");
		
		printf("��ȣ�� �������� : ");
		scanf("%d", &select);
		fflush(stdin);
		
		switch(select)
		{
			case 1: 
				save_file();
				break;
				
			case 2:
				read_file();
				break;
				
			case 3: 
                return 0;
                system("cls");
				break;     
		} 
	}
}

void save_file()
{
	if (number < MAX)
	{
		
		printf("�޸� ��¥ �Է�(MMDD) : ");
		scanf("%d", &MEMO[number].date);
		printf("�޸� ���� �Է�(���� ����) : ");
		scanf("%s", MEMO[number].title);
		printf("�޸� ���� �Է�(���� ����) : ");
		scanf("%s", MEMO[number].memo);
					
		number++;
		fflush(stdin);
	}
				
				else
				{
					printf("�迭�� �� ���� �Է� �Ұ�!\n");
				}
    int i;
	FILE *fp;
	fp = fopen("test.txt", "a");
	if (fp == NULL) {
		printf("���Ͽ��� ����\n");
		return;
	}
	for(i = 0; i < number; i++) // �迭 �󿡼� �̵�
		fprintf(fp,"%d %s %s\n", MEMO[i].date, MEMO[i].title, MEMO[i].memo);
	fclose(fp);
}

int read_file()
{
	int i = 0, num = 0;
	FILE *fp;
	fp = fopen("test.txt", "r");

	if (fp == NULL) 
	{
		printf("���Ͽ��� ����\n");
		return 0;
	}
	
	while(EOF != fscanf(fp,"%d %s %s\n", &MEMO[i].date, MEMO[i].title, MEMO[i].memo))
	{
		
		printf("%d��° �޸�\n ��¥ : %d\n ���� : %s\n ���� : %s\n", i+1, MEMO[i].date, MEMO[i].title, MEMO[i].memo);
		i = i + 1;
	}
	
	fclose(fp);
}

//==================================================================================================================����

int main(){
    while (1){
        //
        int main_choice;
        printf("\n----------------------------------------");
        printf("\n|     ����ο� ���� ��Ȱ ���α׷�      |");
        printf("\n----------------------------------------\n\n");
        printf(" -> ���� ��ȹǥ: (1)\n");
        printf(" -> ������ ���� ����: (2)\n");
        printf(" -> ���� ��û Ȯ��: (3)\n");
        printf(" -> �޸���: (4)\n");
        printf(" -> ���ִ� ���޾�ü: (5)\n");
        printf(" -> ����: (6)\n");
        printf("\n������ �Ͻðڽ��ϱ�? : ");
        scanf("%d",&main_choice);
        if(main_choice==1){
            system("cls");
            Menu();
        }
        else if (main_choice==2)
        {
            system("cls");
            Professor_code();
        }
        else if (main_choice==3)
        {
            system("cls");
            class_check();
        }
        else if (main_choice==4)
        {
            system("cls");
            Notepad();
        }
        else if (main_choice==5){
            system("cls");
            storeMenu();
        }
        else if (main_choice==6){
            printf("<�����մϴ�.>\n");
            break;
        }
    }


    return 0;
}