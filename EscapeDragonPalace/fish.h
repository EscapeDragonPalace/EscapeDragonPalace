#pragma once

#define FISH_WIDTH 15
#define FISH_HEIGHT 3
#define FISH_HP 3

// ���� ����
static char g_FishGraphic[2][FISH_HEIGHT][FISH_WIDTH] = {
	{
		"    _______  ",
		" (\\/��((��o\\",
		" (/\\_______/ "
	},// ������ �׸� 0
		{
		"  _______   ",
		" /o��))��\\/)",
		" \\_______/\\)"
	}, // ���� �׸� 1
};

// ����� �Լ�
void UpdateFish(unsigned int now);	// ����� ������Ʈ
void DrawFish(int dir, int posX, int posY);	// ����� �׸���
//void HitFish(unsigned int now, int damage);	// ����� ������ ������