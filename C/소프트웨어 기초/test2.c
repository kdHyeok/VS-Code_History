#include "pch.h"
#include "tipsware.h"

struct AppData  // ���α׷����� ����� ���� ������
{
	TargetData *p_target;  // ��ũ�� ����� ����
};

// ��Ʈ���� �������� �� ȣ���� �Լ� �����
// ��Ʈ���� ���̵�(a_ctrl_id), ��Ʈ���� ���� ����(a_notify_code), ������ ��Ʈ�� ��ü(ap_ctrl)
void OnCommand(INT32 a_ctrl_id, INT32 a_notify_code, void *ap_ctrl)
{
	AppData *p_data = (AppData *)GetAppData();  // ���� ���α׷��� ���� ������ �ּҸ� �����´�.

	if (a_ctrl_id == 1000) {
		// �޸��� ���α׷��� 'Window Class' ��Ī�� 'notepad' �Դϴ�. ����
		// 'notepad' �̸����� ����� �˻��մϴ�. ����� ã�Ҵٸ� NULL �ƴ� ���� ����˴ϴ�.
		p_data->p_target = FindTargetImage(0, "notepad", NULL);
	} else if (a_ctrl_id == 1001) {
		if (p_data->p_target != NULL) {
			int x, y;
			// �޸����� Ŭ���̾�Ʈ �������� (10, 10) ������ ȭ�� ��ǥ�� ��ȯ�մϴ�.
			GetMousePosFromTarget(p_data->p_target, &x, &y, 10, 10);
			// �޸��忡 ���� ���� ���ؼ� (x, y)�� ���콺�� Ŭ���ؼ� �޸����� �����մϴ�.
			MouseClickWrite(x, y); 
			// �ѱ� ����� �����ϰ� ���� ���ϴ�. ��, �޸����� �Է� ���°�
			// �ѱ۷� �����Ǿ� �־�� �մϴ�.
			InputNormalString("�ȳ��ϼ���~ �輺���Դϴ�!!\nMacro ����� �׽�Ʈ�ϰ� �ֽ��ϴ�~ :)", 1);
		}
	}
}

// ��Ʈ���� ������ �� ȣ���� �Լ��� �����Ѵ�.
CMD_MESSAGE(OnCommand)

int main()
{
	int width = 600, height = 400;
	ChangeWorkSize(width, height); // �۾� ������ �����Ѵ�.

	AppData data = { NULL };  // ���α׷��� ���������� ����� �޸𸮸� �����Ѵ�.
	SetAppData(&data, sizeof(data));  // ������ ������ ���� �����ͷ� �����Ѵ�.
	  
   // ���α׷����� ����� ��ư�� �����մϴ�.
	CreateButton("�޸��� ã��", 10, 10, 105, 28, 1000);
	CreateButton("�޸��忡 �۾���", 120, 10, 105, 28, 1001);
	ShowDisplay(); // ������ �����쿡 ����Ѵ�.
	return 0;
}