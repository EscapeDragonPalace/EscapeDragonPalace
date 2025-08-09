#include "init.h"
#include "map.h"
#include "screens.h"
#include "weapon.h"

bool GameStart = false; // ���� ���� ����
bool GameStartText = true; // ���� ���� ���� �ؽ�Ʈ
bool IsGameOver = false; // ���� ���� ����
bool GameOverText = true;


// ���ӿ��� ȭ�� ��� �Լ�
void GameOverScreen() {
	_DrawText(20, 5, "�����   ���   ��   ��  �����");
	_DrawText(20, 6, "��     ��  ��  ��� ���  ��      ");
	_DrawText(20, 7, "�� ���  �����  �� �� ��  �����");
	_DrawText(20, 8, "��  ��  ��  ��  ��   ��  ��      ");
	_DrawText(20, 9, "�����  ��  ��  ��   ��  �����   ");

	_DrawText(20, 11, "�����  ��   ��  �����  �����");
	_DrawText(20, 12, "��  ��  ��   ��  ��     ��  ��");
	_DrawText(20, 13, "��  ��  ��   ��  �����  �����");
	_DrawText(20, 14, "��  ��   �� ��   ��     ��  ��");
	_DrawText(20, 15, "�����    ��    �����  ��   ��");

	_DrawText(28, 17, " (\\(\\ ");
	_DrawText(28, 18, " (x-x)");
	_DrawText(28, 19, "o(   )");
}

// ���ӽ��� ȭ�� ��� �Լ�
void GameStartScreen()
{

	_DrawText(20, 1, "�����  �����  �����   ���   �����  �����");
	_DrawText(20, 2, "��     ��     ��     ��  ��  ��  ��  ��");
	_DrawText(20, 3, "�����  �����  ��     �����  �����  �����");
	_DrawText(20, 4, "��        ��  ��     ��  ��  ��     ��");
	_DrawText(20, 5, "�����  �����  �����  ��  ��  ��     �����");

	_DrawText(20, 7, "����   �����   ���   �����  �����  ��  ��");
	_DrawText(20, 8, "��  ��  ��  ��  ��  ��  ��     ��  ��  ��� ��");
	_DrawText(20, 9, "��  ��  �����  �����  �� ���  ��  ��  �� ���");
	_DrawText(20, 10, "��  ��  �� ��   ��  ��  ��  ��  ��  ��  ��  ��");
	_DrawText(20, 11, "����   ��  ��  ��  ��  �����  �����  ��  ��");

	_DrawText(20, 13, "�����   ���   ��      ���   �����  �����");
	_DrawText(20, 14, "��  ��  ��  ��  ��     ��  ��  ��     ��");
	_DrawText(20, 15, "�����  �����  ��     �����  ��     �����");
	_DrawText(20, 16, "��     ��  ��  ��     ��  ��  ��     ��");
	_DrawText(20, 17, "��     ��  ��  �����  ��  ��  �����  �����");
}

void DrawStartScreen() {
	// ���� ���� ���� ��
	while (!GameStart) {
		// Ű �Է��� ������
		if (_kbhit()) {
			GameStart = true;   // ���� ����
			_getch();   // �Է� ���� ����
		}
		// ���� ����Ʈ ȿ��
		GameStartText = !GameStartText;
		_Invalidate();
		Sleep(500);
	}
}

void ReturnStartScreen() {

	// ���� ������ ��
	while (IsGameOver) {
		// Ű �Է��� ������
		if (_kbhit()) {
			IsGameOver = false; // ���ӿ��� ���� false ����
			GameStart = false;  // ���ӽ��� ���� false ����
			SetWeaponChosen(false); // ���� ���ÿ��� false�� ����
			SetMapSetting(false);	// ������ ���� �ʱ�ȭ
			SetMapStatus(E_Jail);	// ���� ������ �̵�
			SetPlusX(0);	// X ��ǥ ������ 0���� ����
			_getch();	// �Է� ���� ����
		}
		// ���� ����Ʈ ȿ��
		GameOverText = !GameOverText;
		_Invalidate();
		Sleep(500);
	}

}

// ���� ���� ���� ��������
bool GetGameStart()
{
	return GameStart;
}

// ���� ���� ���� �ؽ�Ʈ ��������
bool GetGameStartText()
{
	return GameStartText;
}

bool GetIsGameOver()
{
	return IsGameOver;
}

void SetIsGameOver(int src)
{
	IsGameOver = src;
}

bool GetGameOverText()
{
	return GameOverText;
}

void SetIsGameOverText(int src)
{
	GameOverText = src;
}