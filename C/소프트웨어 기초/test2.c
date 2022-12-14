#include "pch.h"
#include "tipsware.h"

struct AppData  // 프로그램에서 사용할 내부 데이터
{
	TargetData *p_target;  // 매크로 대상의 정보
};

// 컨트롤을 조작했을 때 호출할 함수 만들기
// 컨트롤의 아이디(a_ctrl_id), 컨트롤의 조작 상태(a_notify_code), 선택한 컨트롤 객체(ap_ctrl)
void OnCommand(INT32 a_ctrl_id, INT32 a_notify_code, void *ap_ctrl)
{
	AppData *p_data = (AppData *)GetAppData();  // 응용 프로그램의 내부 데이터 주소를 가져온다.

	if (a_ctrl_id == 1000) {
		// 메모장 프로그램의 'Window Class' 명칭이 'notepad' 입니다. 따라서
		// 'notepad' 이름으로 대상을 검색합니다. 대상을 찾았다면 NULL 아닌 값이 저장됩니다.
		p_data->p_target = FindTargetImage(0, "notepad", NULL);
	} else if (a_ctrl_id == 1001) {
		if (p_data->p_target != NULL) {
			int x, y;
			// 메모장의 클라이언트 영역에서 (10, 10) 지점을 화면 좌표로 변환합니다.
			GetMousePosFromTarget(p_data->p_target, &x, &y, 10, 10);
			// 메모장에 글을 쓰기 위해서 (x, y)에 마우스를 클릭해서 메모장을 선택합니다.
			MouseClickWrite(x, y); 
			// 한글 모드라고 가정하고 글을 씁니다. 즉, 메모장의 입력 상태가
			// 한글로 설정되어 있어야 합니다.
			InputNormalString("안녕하세요~ 김성엽입니다!!\nMacro 기능을 테스트하고 있습니다~ :)", 1);
		}
	}
}

// 컨트롤을 조작할 때 호출할 함수를 설정한다.
CMD_MESSAGE(OnCommand)

int main()
{
	int width = 600, height = 400;
	ChangeWorkSize(width, height); // 작업 영역을 설정한다.

	AppData data = { NULL };  // 프로그램이 내부적으로 사용할 메모리를 선언한다.
	SetAppData(&data, sizeof(data));  // 지정한 변수를 내부 데이터로 저장한다.
	  
   // 프로그램에서 사용할 버튼을 생성합니다.
	CreateButton("메모장 찾기", 10, 10, 105, 28, 1000);
	CreateButton("메모장에 글쓰기", 120, 10, 105, 28, 1001);
	ShowDisplay(); // 정보를 윈도우에 출력한다.
	return 0;
}