#include "init.h"
#include "fish_small.h"

Monster g_SmallFishMon;	// ���� ����� ���� ����ü ���� ����
SmallFish g_SmallFishList[STAGE_CNT][SMALLFISH_CNT];	// ���� ����� ����Ʈ �迭
int g_SmallFishListIdx[STAGE_CNT - 1] = { 0, };	// ������ ����

// ���� ����� ������Ʈ
void UpdateSmallFish(unsigned long now)
{
	// ���� ���� ���� ������ �ҷ�����
	SmallFish* tempSmallFish = g_SmallFishList[GetMapStatus()];
	for (int idx = 0; idx < g_SmallFishListIdx[GetMapStatus()]; idx++)
	{
		// ���Ͱ� �׾��� ��� �Ѿ��
		if (!tempSmallFish[idx].mon.alive) continue;

		// ���� �̵�
		--tempSmallFish[idx].pos.x;

		// ���Ͱ� ���� ȭ�� ������ �Ѿ�� ��� ���� ó��
		if (tempSmallFish[idx].pos.x <= 0)
		{
			tempSmallFish[idx].mon.alive = false;
		}
	}
}

// ���� ����� �׸���
void DrawSmallFish()
{
	_SetColor(E_Teal);	// �׻� �Ķ���

	// ���� �� ������ �ӽ÷� �ҷ�����
	SmallFish* tempSmallFish = g_SmallFishList[GetMapStatus()];
	for (int idx = 0; idx < g_SmallFishListIdx[GetMapStatus()]; idx++)
	{
		int tempX = tempSmallFish[idx].pos.x - GetPlusX();
		for (int x = 0; x < SMALLFISH_WIDTH; x++)
		{
			if (g_SmallFishGraphic[x] != ' ')
			{
				// ȭ�� ���� ���� ���� ��� �׸���
				if (0 <= tempX + x && SCREEN_WIDTH > tempX + x)
				{
					_DrawText(tempX + x, tempSmallFish[idx].pos.y, (char[]) { g_SmallFishGraphic[x], 0 });
				}
			}
		}
	}
}

void InitSmallFish()
{
	// ���� ����� ����� �Ӽ� ����
	g_SmallFishMon = (Monster)
	{
		.alive = true,		// ���� ����
		.hp = 1,
		.lastHitTime = 0,
		.speed = 1.5,
	};

	// ����
	g_SmallFishList[E_Jail][g_SmallFishListIdx[E_Jail]++] = (SmallFish)
	{
		.pos.x = 450,	// X ��ǥ
		.pos.y = 18,	// Y ��ǥ
		.attack = SMALLFISH_ATTACK,	// ���ݷ�
	};

	// ���
	g_SmallFishList[E_DragonPalace][g_SmallFishListIdx[E_DragonPalace]++] = (SmallFish)
	{
		.pos.x = 360,
		.pos.y = 23,
		.attack = SMALLFISH_ATTACK,
	};

	g_SmallFishList[E_DragonPalace][g_SmallFishListIdx[E_DragonPalace]++] = (SmallFish)
	{
		.pos.x = 445,
		.pos.y = 7,
		.attack = SMALLFISH_ATTACK,
	};

	// �ٴ�1
	g_SmallFishList[E_Sea1][g_SmallFishListIdx[E_Sea1]++] = (SmallFish)
	{
		.pos.x = 310,
		.pos.y = 14,
		.attack = SMALLFISH_ATTACK,
	};
	
	g_SmallFishList[E_Sea1][g_SmallFishListIdx[E_Sea1]++] = (SmallFish)
	{
		.pos.x = 600,
		.pos.y = 23,
		.attack = SMALLFISH_ATTACK,
	};

	// �ٴ�2
	g_SmallFishList[E_Sea2][g_SmallFishListIdx[E_Sea2]++] = (SmallFish)
	{
		.pos.x = 233,
		.pos.y = 12,
		.attack = SMALLFISH_ATTACK,
	};

	g_SmallFishList[E_Sea2][g_SmallFishListIdx[E_Sea2]++] = (SmallFish)
	{
		.pos.x = 413,
		.pos.y = 13,
		.attack = SMALLFISH_ATTACK,
	};

	g_SmallFishList[E_Sea2][g_SmallFishListIdx[E_Sea2]++] = (SmallFish)
	{
		.pos.x = 570,
		.pos.y = 15,
		.attack = SMALLFISH_ATTACK,
	};
}