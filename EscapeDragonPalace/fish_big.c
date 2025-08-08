#include "init.h"
#include "fish_big.h"

Monster g_BigFishMon;	// ū ����� ���� ����ü ���� ����
BigFish g_BigFishList[STAGE_CNT][BIGFISH_CNT];	// ū ����� ����Ʈ �迭
int g_BigFishListIdx = 0;

// ū ����� ������Ʈ
void UpdateBigFish(unsigned long now)
{
	// ���� ���� ���� ������ �ҷ�����
	BigFish* tempBigFish = g_BigFishList[GetMapStatus()];
	for(int idx = 0; idx < g_BigFishListIdx; idx++)
	{
		// �ǰ� �� ������, ��� �Ķ���
		_SetColor(g_BigFishList[GetMapStatus()][g_BigFishListIdx].isDamaged ? E_BrightRed : E_BrightBlue);

		// ���Ͱ� �׾��� ��� �Ѿ��
		if (!tempBigFish[idx].mon.alive) continue;

		// �����ð� ������ �ǰ� ���� ����
		if (tempBigFish[idx].isDamaged && now - tempBigFish[idx].mon.lastHitTime >= INVINCIBLE_TIME)
		{
			tempBigFish[idx].isDamaged = false;
		}

		// ���� �̵�
		tempBigFish[idx].pos.x += (tempBigFish[idx].dir == E_Right) ? 1 : -1;

		// ������ ���� �ȿ��� �̵�
		if (tempBigFish[idx].pos.x <= tempBigFish[idx].startPosX)
		{
			tempBigFish[idx].dir = E_Right;
		}
		else if (tempBigFish[idx].pos.x + BIGFISH_WIDTH >= tempBigFish[idx].startPosX + tempBigFish[idx].moveNum)
		{
			tempBigFish[idx].dir = E_Left;
		}
	}
}

// ū ����� �׸���
void DrawBigFish()
{
	// ���� �� ������ �ӽ÷� �ҷ�����
	BigFish* tempBigFish = g_BigFishList[GetMapStatus()];
	for (int idx = 0; idx < g_BigFishListIdx; idx++)
	{
		int tempX = tempBigFish[idx].pos.x + GetPlusX();
		for(int y = 0; y < BIGFISH_HEIGHT; y++)
		{
			for (int x = 0; x < BIGFISH_WIDTH; x++)
			{
				if (g_BigFishGraphic[x] != ' ')
				{
					// ȭ�� ���� ���� ���� ��� �׸���
					if (0 <= tempX + x && SCREEN_WIDTH > tempX + x)
					{
						_DrawText(tempX + x, tempBigFish[idx].pos.y + y, (char[]) { g_BigFishGraphic[x], 0 });
					}
				}
			}
		}
	}
}

// ū ����� �ʱ�ȭ
void InitBigFish()
{
	// ū ����� ����� �Ӽ� ����
	g_BigFishMon = (Monster)
	{
		.alive = true,		// ���� ����
		.hp = 4,			// ü��
		.lastHitTime = 0,	// ������ �ǰ� �ð�
		.speed = 1.5,		// �̵� �ӵ�
	};

	// ����
	g_BigFishList[E_Jail][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 100,		// X ��ǥ
		.pos.y = 11,		// Y ��ǥ
		.startPosX = 100,	// �ʱ� X ��ǥ
		.attack = BIGFISH_ATTACK,	// ���ݷ�
		.moveNum = 30,		// �̵� ����
		.isDamaged = false,	// �ǰ� ���� (���� ����)
		.dir = E_Right,		// �ٶ󺸴� ����
	};

	g_BigFishList[E_Jail][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 170,
		.pos.y = 11,
		.startPosX = 170,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Jail][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 300,
		.pos.y = 11,
		.startPosX = 300,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Jail][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 500,
		.pos.y = 12,
		.startPosX = 500,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Jail][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 500,
		.pos.y = 21,
		.startPosX = 500,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	// ���
	g_BigFishList[E_DragonPalace][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 70,
		.pos.y = 14,
		.startPosX = 70,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_DragonPalace][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 170,
		.pos.y = 14,
		.startPosX = 170,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_DragonPalace][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 280,
		.pos.y = 11,
		.startPosX = 280,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_DragonPalace][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 520,
		.pos.y = 11,
		.startPosX = 520,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	// �ٴ�1
	g_BigFishList[E_Sea1][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 120,
		.pos.y = 21,
		.startPosX = 120,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Sea1][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 190,
		.pos.y = 12,
		.startPosX = 190,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Sea1][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 300,
		.pos.y = 21,
		.startPosX = 300,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Sea1][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 400,
		.pos.y = 13,
		.startPosX = 400,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Sea1][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 480,
		.pos.y = 21,
		.startPosX = 480,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	// �ٴ�2
	g_BigFishList[E_Sea2][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 260,
		.pos.y = 21,
		.startPosX = 260,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Sea2][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 320,
		.pos.y = 16,
		.startPosX = 320,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Sea2][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 410,
		.pos.y = 16,
		.startPosX = 410,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};
}