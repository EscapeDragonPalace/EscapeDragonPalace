#include "init.h"
#include "fish_small.h"
#include "Rabbit.h"

Monster g_SmallFishMon;	// ���� ����� ���� ����ü ���� ����
SmallFish g_SmallFishList[STAGE_CNT][SMALLFISH_CNT];	// ���� ����� ����Ʈ �迭
int g_SmallFishListIdx[STAGE_CNT] = { 0, };

// ���� ����� ������Ʈ
void UpdateSmallFish(unsigned long now)
{
	// ���� ���� ���� ������ �ҷ�����
	SmallFish* tempSmallFish = g_SmallFishList[GetMapStatus()];
	for (int idx = 0; idx < g_SmallFishListIdx[GetMapStatus()]; idx++)
	{
		// ���Ͱ� �׾��� ��� �Ѿ��
		if (!tempSmallFish[idx].mon.alive) continue;

		// ���Ͱ� ȭ�� �ȿ� ���� ���
		if (tempSmallFish[idx].pos.x - GetPlusX() > 0 && tempSmallFish[idx].pos.x - GetPlusX() < SCREEN_WIDTH) {
			// �÷��̾�� ������ Y ��ǥ�� ���� ��
			if (tempSmallFish[idx].pos.y == player.Pos.y + 2) {
				tempSmallFish[idx].isRush = true;	// ���� ���·� ����
			}
			
		}
		if (tempSmallFish[idx].isRush) {
			// ���� �̵�
			tempSmallFish[idx].pos.x -= g_SmallFishMon.speed;

			// ���Ͱ� ���� ȭ�� ������ �Ѿ�� ��� ���� ó��
			if (tempSmallFish[idx].pos.x <= 0)
			{
				tempSmallFish[idx].mon.alive = false;
			}
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

		// ���Ͱ� �׾��� ��� �Ѿ��
		if (!tempSmallFish[idx].mon.alive) continue;

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

// ���� ����� �ǰ� ó��
//void HitMonster(Weapon* weapon, unsigned int now) {
//	if (g_SmallFishList[GetMapStatus()]) return;
//
//	monster->hp -= weapon->attack;
//	monster->isDamaged = true;	// ���� ���� ����
//	monster->lastHitTime = now;	// �ǰ� �ð� ���
//
//	if (monster->hp <= 0) {
//		monster->alive = false;         // ü���� 0 ���ϰ� �Ǹ� ��� ó��
//	}
//}

void InitSmallFish()
{
	// ���� ����� ����� �Ӽ� ����
	g_SmallFishMon = (Monster)
	{
		.alive = true,		// ���� ����
		.hp = 1,			// ü��
		.isDamaged = false,	// �ǰ� ���� (���� ����)
		.lastHitTime = 0,	// ������ �ǰ� �ð�
		.speed = 1.66,		// �̵� �ӵ�
	};

	// ����
	g_SmallFishList[E_Jail][g_SmallFishListIdx[E_Jail]++] = (SmallFish)
	{
		.mon = g_SmallFishMon,
		.pos.x = 450,	// X ��ǥ
		.pos.y = 18,	// Y ��ǥ
		.attack = SMALLFISH_ATTACK,	// ���ݷ�
		.isRush = false
	};

	// ���
	g_SmallFishList[E_DragonPalace][g_SmallFishListIdx[E_DragonPalace]++] = (SmallFish)
	{
		.mon = g_SmallFishMon,
		.pos.x = 360,
		.pos.y = 23,
		.attack = SMALLFISH_ATTACK,
		.isRush = false
	};

	g_SmallFishList[E_DragonPalace][g_SmallFishListIdx[E_DragonPalace]++] = (SmallFish)
	{
		.mon = g_SmallFishMon,
		.pos.x = 445,
		.pos.y = 7,
		.attack = SMALLFISH_ATTACK,
		.isRush = false
	};

	// �ٴ�1
	g_SmallFishList[E_Sea1][g_SmallFishListIdx[E_Sea1]++] = (SmallFish)
	{
		.mon = g_SmallFishMon,
		.pos.x = 310,
		.pos.y = 14,
		.attack = SMALLFISH_ATTACK,
		.isRush = false
	};
	
	g_SmallFishList[E_Sea1][g_SmallFishListIdx[E_Sea1]++] = (SmallFish)
	{
		.mon = g_SmallFishMon,
		.pos.x = 600,
		.pos.y = 23,
		.attack = SMALLFISH_ATTACK,
		.isRush = false
	};

	// �ٴ�2
	g_SmallFishList[E_Sea2][g_SmallFishListIdx[E_Sea2]++] = (SmallFish)
	{
		.mon = g_SmallFishMon,
		.pos.x = 233,
		.pos.y = 12,
		.attack = SMALLFISH_ATTACK,
		.isRush = false
	};

	g_SmallFishList[E_Sea2][g_SmallFishListIdx[E_Sea2]++] = (SmallFish)
	{
		.mon = g_SmallFishMon,
		.pos.x = 413,
		.pos.y = 13,
		.attack = SMALLFISH_ATTACK,
		.isRush = false
	};

	g_SmallFishList[E_Sea2][g_SmallFishListIdx[E_Sea2]++] = (SmallFish)
	{
		.mon = g_SmallFishMon,
		.pos.x = 570,
		.pos.y = 15,
		.attack = SMALLFISH_ATTACK,
		.isRush = false
	};
}