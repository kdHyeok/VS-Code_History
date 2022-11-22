#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define _CRT_SECURE_NO_WARNINGS


//=======================================================================================================================================다솔 파트
//일정계획

#define Max 1000
#define Years 12

int year; // 사용자 입력 변수
int month; // 사용자 입력 변수

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
    printf("보고싶은 달력의 년,달을 입력해주세요.\nex)  2021 12 : ");
    scanf("%d %d%*c", &year, &month); 
    // %*c를 해야 뒤에 버퍼에 남은 엔터값을 지워 뒤에 나올 gets에서 엔터값을 안읽게 한다. 만약 안쓰면 gets문을 그냥 넘어가버림!

    // 윤달인지 확인
    if (leapYear(year)) 
    {
        check = 1;
        CalenderYear[1] = 29;
    }
    else
    {
        check = 0;
    }

    //0년부터 작년까지 몇일인지 센다.
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

    //입력한 달까지 며칠인지 
    for (int i = 0; i < month - 1; i++) 
    {
        sum += CalenderYear[i];
    }

    //입력한 달의 1일이 무슨 요일인지 계산
    k = sum % 7;

    //출력
    printf("\n\t\t  %d년\t%d월\n", year, month);
    printf("===================================================\n");
    printf("일\t월\t화\t수\t목\t금\t토\n");
    printf("===================================================\n");


    //시작 요일에 맞춰 정렬
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
            printf("아직 일정이 없는 달입니다!\n");

            return 0;
        }

        printf("=======================일 정=======================\n");

        if (NULL != f)
        {
            while (fgets(p2021[month - 1].content, Max, f) != NULL)
            {
                number++;
                printf("[%d]번째 일정 : %s\n", number, p2021[month - 1].content);
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
            printf("아직 일정이 없는 달입니다!\n");

            return 0;
        }

        if (NULL != f)
        {
            printf("파일 열기 성공\n");
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
            printf("아직 일정이 없는 달입니다!\n");

            return 0;
        }

        if (NULL != f)
        {
            printf("파일 열기 성공\n");
            while (fgets(p2022[month - 1].content, Max, f) != NULL)
            {
                printf("%s\n", p2022[month - 1].content);
            }
        }

        fclose(f);
    }

    else
    {
        printf("이 계획표에는 지원하지 않는 년도입니다!!");
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

    printf("추가할 계획을 적으세요(한번에 한번씩 추가하세요)\n");
    fgets(p2021[month - 1].content, Max, stdin);

    fputs(p2021[month - 1].content, f);

    fclose(f);

    printf("일정을 추가했습니다!\n\n메뉴로 나가시겠습니까? 1번을 누르시면 나갑니다. 2번을 누르면 잘 작성됐는지 확인합니다. : ");
    scanf("%d", &again);

    if (again == 1)
    {
        "메인 메뉴로 나갑니다.\n";
    }

    else if (again == 2)
    {
        scheduleRead();
        printf("이제 메뉴로 나갑니다!\n");
    }
}

void scheduleWrite()
{
    FILE* f;

    char days[20] = { 0x00, };

    int again;

    sprintf(days, "%d %d.txt", year, month);

    f = fopen(days, "w");

    printf("계획을 적으세요(한번에 한번씩 추가하세요)\n");
    fgets(p2021[month - 1].content, Max, stdin);

    fputs(p2021[month - 1].content, f);

    fclose(f);

    printf("일정을 추가했습니다!\n\n메뉴로 나가시겠습니까? 1번을 누르시면 나갑니다. 2번을 누르면 잘 작성됐는지 확인합니다. : ");
    scanf("%d", &again);

    if (again == 1)
    {
        "메인 메뉴로 나갑니다.\n";
    }
    
    else if (again == 2)
    {
        scheduleRead();
        printf("이제 메뉴로 나갑니다!\n");
    }
}

int Menu()
{
    int num;

    while (1)
    {
        printf("\n---------------------일정 계획표---------------------\n");
        printf("1. 달력만 보기\n");
        printf("2. 일정 보기\n");
        printf("3. 일정 이어서 작성하기\n");
        printf("4. 일정 다지우고 새로쓰기\n");
        printf("5. 메인 메뉴로 나가기\n\n");

        printf("메뉴에서 원하는 목록을 선택해주세요 : ");
        scanf("%d", &num);
        system("cls");

        switch (num)
        {
        case 1:
            calender();
            break;

        case 2:
            printf("지금 있는 일정 목록을 불러옵니다.\n");
            calender();
            scheduleRead();
            break;

        case 3:
            calender();
            printf("일정을 추가합니다.\n");
            scheduleAppend();
            break;

        case 4:
            calender();
            printf("일정을 다 지웁니다! 다시 작성해 주세요.\n");
            scheduleWrite();
            break;

        case 5:
            printf("메인 메뉴로 나갑니다.\n");
            system("cls");
            return 0;
            break;
        }
    }
}
//--------------------------------------------------------------------------------------------제휴업체 

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

    printf("체휴업체 정보를 추가하고 싶은 장소를 고르세요. (리스트에 있는 장소 이름을 똑같이 적으세요)\n1.신정문 구정문\n2.신시가지\n3.그 외 장소\n원하는 장소 : ");
    gets(select); // gets로 띄어쓰기 포함 문자열 입력

    char names[20] = { 0x00, };
    sprintf(names, "%s.txt", select);  //sprintf(받을 문자열, 저장할 문자열 내용, print문과 같이 넣을 상수들 나열)

    f = fopen(names, "a");

    if (f == NULL)
    {
        printf("아직 없는 정보가 없는 곳입니다. 새로 정보를 작성합니다!\n");
    }

    printf("추가할 가게의 상호명을 적어주세요 : ");
    scanf("%[^\n]%*c", add[i].name);                                // %*c를 넣어야 scanf에 읽고 버퍼에 남은 \n를 빼줘서 뒤에 올 gets가 \n가 올때까지 
                                                                    // 문자열을 저장하는 코드인데 버퍼에서 \n를 안빼주면 gets문이 바로 넘어가져 버려서 꼭 넣어야한다.
    printf("가게의 위치를 적어주세요 : ");
    scanf("%[^\n]%*c", add[i].address);

    printf("가게의 혜택을 적어주세요 : ");
    scanf("%[^\n]%*c", add[i].benefit);

    fprintf(f, "가게 이름 : %s      위치 : %s     혜택 : %s\n", add[i].name, add[i].address, add[i].benefit);

    fclose(f);
}

void storeRead()
{
    FILE* f;

    char select[20];

    printf("제휴업체 리스트를 보고싶은 장소를 고르세요. (리스트에 있는 장소 이름을 똑같이 적으세요)\n1.신정문 구정문\n2.신시가지\n3.그 외 장소\n원하는 장소 : ");
    gets(select);

    char names[20] = { 0x00, };
    sprintf(names, "%s.txt", select);

    if (strcmp(select, "신정문 구정문") == 0)     //srtcmp = 문자열 비교
    {
        f = fopen(names, "r");
        int count = 1;

        if (f == NULL)
        {
            printf("아직 정보가 없는 곳입니다. 뒤로 갑니다.");
        }

        else if (f != NULL)
        {
            printf("신정문과 구정문에 있는 대학 제휴 업체 목록을 불러옵니다. \n");

            while (fgets(area1.content, Max2, f) != NULL)
            {

                printf("[%d]번째 가게 : %s\n", count, area1.content);
                count++;
            }
            fclose(f);
        }

    }

    else if (strcmp(select, "신시가지") == 0)
    {
        f = fopen(names, "r");
        int count = 1;

            if (f == NULL)
            {
                printf("아직 정보가 없는 곳입니다. 메뉴로 돌아갑니다.");
            }

            else if (f != NULL)
            {
                printf("신시가지에 있는 대학 제휴 업체 목록을 불러옵니다. \n");

                while (fgets(area1.content, Max2, f) != NULL)
                {

                    printf("[%d]번째 가게 : %s\n", count, area1.content);
                    count++;
                }
                fclose(f);
            }
    }

    else if (strcmp(select, "그 외 장소") == 0)
    {
        f = fopen(names, "r");
        int count = 1;

        if (f == NULL)
        {
            printf("아직 정보가 없는 곳입니다. 메뉴로 돌아갑니다.");
        }

        else if (f != NULL)
        {
            printf("대학 제휴 업체 목록을 불러옵니다. \n");

            while (fgets(area1.content, Max2, f) != NULL)
            {

                printf("[%d]번째 가게 : %s\n", count, area1.content);
                count++;
            }
            fclose(f);
        }
    }
    
    else
    {
        printf("아직 정보가 없는 곳입니다. 추가하세요.");
    }
}

int storeMenu()
{
    int check = 0;

    while (check == 0)
    {
        printf("\n---------------------(2017년 정보)대학 근처 제휴 업체---------------------\n");
        printf("(필히 학생증 지참 할 것!)\n");
        printf("1. 제휴 업체 목록 보기\n");
        printf("2. 제휴 업체 추가하기\n");
        printf("3. 메인 메뉴로 나가기\n\n");

        printf("메뉴에서 원하는 목록을 선택해주세요 : ");
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
            printf("메인 메뉴로 나갑니다.\n");
            check = 1;
            break;
        }
    }
}

//=========================================================================================================================================동혁 파트
//교수 정보 관리
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
        printf("\n교수 정보를 검색하시겠습니까? (Yes: 1, No: 2): ");
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
                printf("<!>존재하지 않는 정보입니다.( %s )\n",Nam);
            }
        }
        else if(check==2){
            system("cls");
            //printf("<검색을 종료합니다.>\n");
            break;
        }
    }
}
void input_Data(){
    printf("\n================교수 입력================\n");
    
    while (1)
    {
        int check;
        printf("\n교수 정보를 추가하시겠습니까? (Yes: 1, No: 2): ");
        scanf("%d",&check);
        if(check==1){
            FILE* fp = fopen("ProfessorData.txt", "a");
            printf("이름: ");
            getc(stdin);
            fgets(Professor[count].name, sizeof(Professor[count].name), stdin);
            fputs(Professor[count].name, fp);
            Professor[count].name[strlen(Professor[count].name) - 1] = '\0';
            
            printf("연구실: ");
            fgets(Professor[count].lab, sizeof(Professor[count].lab), stdin);
            fputs(Professor[count].lab, fp);
            Professor[count].lab[strlen(Professor[count].lab) - 1] = '\0';

            printf("전화번호: ");
            fgets(Professor[count].call, sizeof(Professor[count].call), stdin);
            fputs(Professor[count].call, fp);
            Professor[count].call[strlen(Professor[count].call) - 1] = '\0';

            printf("이메일: ");
            fgets(Professor[count].Email, sizeof(Professor[count].Email), stdin);
            fputs(Professor[count].Email, fp);
            Professor[count].Email[strlen(Professor[count].Email) - 1] = '\0';

            printf("수업: ");
            fgets(Professor[count].classes, sizeof(Professor[count].classes), stdin);
            fputs(Professor[count].classes, fp);
            Professor[count].classes[strlen(Professor[count].classes) - 1] = '\0';

            printf("메모사항: ");
            fgets(Professor[count].memo, sizeof(Professor[count].memo), stdin);
            fputs(Professor[count].memo, fp);
            Professor[count].memo[strlen(Professor[count].memo) - 1] = '\0';

            count++;
            printf("<입력 완료!>\n");
            fclose(fp);
        }
        else if(check==2){
            system("cls");
            //printf("<입력을 종료합니다.>\n");
            
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
        printf("\n================ [교수 정보 관리] ================\n");
        printf("\n [ 교수 목록 출력: (1) ]\n [ 교수 정보 입력: (2) ]\n [ 교수 정보 검색: (3) ]\n [     나가기 : (4)    ]\n\n - 무엇을 하시겠습니까? : ");
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
            printf("<종료합니다.>\n");
            system("cls");
            break;
        }
    }
}

//========================================================================================================================================아영 파트
//강의 시청확인
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
		printf("1. 수강 목록 입력\n");
		printf("2. 출석 목록 삭제\n");
		printf("3. 미출석 목록 확인\n");
		printf("4. 종료\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			system("cls");
			printf("수강 목록 입력 선택!\n");
			FILE* stri;
			FILE* re_endsub;

			int sugang_num;
			printf("수강중인 과목의 개수를 입력하시오.:");
			scanf("%d", &sugang_num);

			stri = fopen("striming.txt", "w+");
			printf("\n수강중인 과목을 한줄씩 입력하세요.\n ex.1 과목\n    2 과목\n");
			for (int i = 0; i < sugang_num; i++) {

				scanf("%d %s", &dic[i].name_num, dic[i].name);
				fprintf(stri, "%s \n", dic[i].name);
			}

			fclose(stri);
			printf("\n과목이 저장되었습니다.\n\n\n");
			break;

		case 2:
			system("cls");
			printf("출석 목록 삭제 선택!!\n\n");
			printf("현재 사용자가 수강하는 과목은\n");
			for (int i = 0; i < sugang_num; i++) {
				printf("%d %s \n", dic[i].name_num, dic[i].name);
			}
			printf("입니다.\n\n\n");

			int end_sub = 0;
			printf("이 중 수강한 과목의 번호를 입력하세요.(입력완료시 0을 입력):");
			scanf("%d", &end_sub);

			for (int i = 0; i < sugang_num; i++) {
				if (dic[i].name_num == end_sub) {
					for (int j = i; j < sugang_num ; j++) {
						dic[j] = dic[j + 1];

						dic[j].name_num = j + 1;
					}
				}
			}
			printf("남은 과목은\n");
			re_endsub = fopen("re.txt", "w+");
			for (int k = 0; k < sugang_num; k++) {
				printf("%d %s\n", dic[k].name_num, dic[k].name);
				fprintf(re_endsub, "%s\n", dic[k].name);

			}

			fclose(re_endsub);
			break;

		case 3:
			system("cls");
			printf("미출석 목록 확인선택!!\n");
			re_endsub = fopen("re.txt", "r");

			char re_sub[MAX_STR_LEN] = { 0, };

			fread(re_sub, 1, MAX_STR_LEN, re_endsub);
			printf("%s\n", re_sub);

			fclose(re_endsub);
			break;

		case 4:
			printf("저장하고 종료선택!!\n");
			return 0;
		}

	}
}
//====================================================================================================================유승 파트
//개인 메모장
#define MAX 100

void save_file();
int read_file();

struct memo {
	int date;       // 메모 날짜 
	char title[10]; // 메모 제목
	char memo[100]; // 메모 내용 
};

struct memo MEMO[100];
int number = 0;


int Notepad(){
	int select, i;

	
	while(1)
	{
		int num;
		printf("1. 메모 입력   2. 메모 출력   3. 나가기\n");
		
		printf("번호를 누르세요 : ");
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
		
		printf("메모 날짜 입력(MMDD) : ");
		scanf("%d", &MEMO[number].date);
		printf("메모 제목 입력(띄어쓰기 금지) : ");
		scanf("%s", MEMO[number].title);
		printf("메모 내용 입력(띄어쓰기 금지) : ");
		scanf("%s", MEMO[number].memo);
					
		number++;
		fflush(stdin);
	}
				
				else
				{
					printf("배열이 꽉 차서 입력 불가!\n");
				}
    int i;
	FILE *fp;
	fp = fopen("test.txt", "a");
	if (fp == NULL) {
		printf("파일열기 실패\n");
		return;
	}
	for(i = 0; i < number; i++) // 배열 상에서 이동
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
		printf("파일열기 실패\n");
		return 0;
	}
	
	while(EOF != fscanf(fp,"%d %s %s\n", &MEMO[i].date, MEMO[i].title, MEMO[i].memo))
	{
		
		printf("%d번째 메모\n 날짜 : %d\n 제목 : %s\n 내용 : %s\n", i+1, MEMO[i].date, MEMO[i].title, MEMO[i].memo);
		i = i + 1;
	}
	
	fclose(fp);
}

//==================================================================================================================메인

int main(){
    while (1){
        //
        int main_choice;
        printf("\n----------------------------------------");
        printf("\n|     슬기로운 대학 생활 프로그램      |");
        printf("\n----------------------------------------\n\n");
        printf(" -> 일정 계획표: (1)\n");
        printf(" -> 교수님 정보 관리: (2)\n");
        printf(" -> 강의 시청 확인: (3)\n");
        printf(" -> 메모장: (4)\n");
        printf(" -> 전주대 제휴업체: (5)\n");
        printf(" -> 종료: (6)\n");
        printf("\n무엇을 하시겠습니까? : ");
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
            printf("<종료합니다.>\n");
            break;
        }
    }


    return 0;
}