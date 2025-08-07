#pragma once

#define SMALLFISH_WIDTH 8
#define SMALLFISH_HEIGHT 1
#define SMALLFISH_HP 2

// ���� ����
static char g_SmallFishGraphic[2][SMALLFISH_HEIGHT][SMALLFISH_WIDTH] = {
	{
		"><((('>"
	},// ������ �׸� 0
	{
		"<')))><"
	}, // ���� �׸� 1
};

// ����� �Լ�
void DrawSmallFish(int dir, int posX, int posY);	// ����� �׸���
bool GetSmallFishAlive();	// ����� �������� ��ȯ
bool GetSmallFishIsDamaged();	// ����� ������ ���� ��ȯ
void SmallFishHitP();	// ����Ⱑ �÷��̾� ����