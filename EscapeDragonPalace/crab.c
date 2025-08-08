#include "init.h"
#include "crab.h"

Monster g_CrabMon;	// �ɰ� ���� ����ü ���� ����
Skill g_CrabSkill;	// �ɰ� ��ų ����ü ���� ����
Crab g_CrabList[STAGE_CNT][CRAB_CNT];	// �ɰ� ����Ʈ �迭
int g_CrabListIdx[STAGE_CNT - 1] = { 0, };	// ������ ����

// �ɰ� ������Ʈ
void UpdateCrab(unsigned long now)
{
	// ���� ���� ���� ������ �ҷ�����
	Crab* tempCrab = g_CrabList[GetMapStatus()];

	// ���� �ʿ� �ִ� ���� ����ŭ �ݺ��ϱ�
	for (int idx = 0; idx < g_CrabListIdx[GetMapStatus()]; idx++)
	{
		// ���Ͱ� �׾��� ��� �Ѿ��
		if (!tempCrab[idx].mon.alive) continue;

		// �����ð� ������ �ǰ� ���� ����
		if (tempCrab[idx].isDamaged && now - tempCrab[idx].mon.lastHitTime >= INVINCIBLE_TIME)
		{
			tempCrab[idx].isDamaged = false;
		}

		// ���� �̵�
		tempCrab[idx].pos.x += (tempCrab[idx].dir == E_Right) ? 1 : -1;

		// ������ ���� �ȿ��� �̵�
		if (tempCrab[idx].pos.x <= tempCrab[idx].startPosX)
		{
			tempCrab[idx].dir = E_Right;
		}
		else if (tempCrab[idx].pos.x + CRAB_WIDTH >= tempCrab[idx].startPosX + tempCrab[idx].moveNum)
		{
			tempCrab[idx].dir = E_Left;
		}
	}
}
// �ɰ� ���� üũ, ���� �ִϸ��̼� ó��
void CheckAttacking()
{
	for (int i = 0; i < g_CrabListIdx[GetMapStatus()]; i++)
	{
		// ���� ������ ��� �Ѿ��
		if (!g_CrabList[GetMapStatus()][i].mon.alive) continue;
	}
}

// �ɰ� �ǰ� ó��

// �ɰ� �׸���
void DrawCrab()
{
	// ���� �� ������ �ӽ÷� �ҷ�����
	Crab* tempCrab = g_CrabList[GetMapStatus()];
	for (int idx = 0; idx < g_CrabListIdx[GetMapStatus()]; idx++)
	{
		// �ǰ� �� �����, ��� ������
		_SetColor(g_CrabList[GetMapStatus()][idx].isDamaged ? E_Yellow : E_BrightRed);

		int posX = tempCrab[idx].pos.x - GetPlusX();
		for (int y = 0; y < CRAB_HEIGHT; y++)
		{
			for (int x = 0; x < CRAB_WIDTH; x++)
			{
				if (g_CrabGraphic[tempCrab[idx].dir][y][x] != ' ')
				{
					// ȭ�� ���� ���� ���� ��� �׸���
					if (0 <= posX + x && SCREEN_WIDTH > posX + x)
					{
						_DrawText(posX + x, tempCrab[idx].pos.y + y, 
							(char[]) { g_CrabGraphic[tempCrab[idx].dir][y][x], 0 });
					}
				}
			}
		}
	}
}

// �ɰ� �ʱ�ȭ
void InitCrab()
{
	// �ɰ� ����� �Ӽ� ����
	g_CrabMon = (Monster)
	{
		.alive = true,		// ���� ����
		.hp = 5,			// ü��
		.lastHitTime = 0,	// ������ �ǰ� �ð�
		.speed = 1.5,		// �̵� �ӵ�
	};
	g_CrabSkill = (Skill)
	{
		.isAttack = false,	// ��ų ��� ����
		.attack = 1,		// ���ݷ� (�� ĭ)
		.attackCnt = 3,		// ���� Ƚ��
		.coolTime = 4000,	// ��Ÿ�� (2��)
	};

	// ����
	g_CrabList[E_Jail][g_CrabListIdx[E_Jail]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 100,		// X ��ǥ
		.pos.y = 21,		// Y ��ǥ
		.startPosX = 100,	// �ʱ� X ��ǥ
		.moveNum = 30,		// �̵� ����
		.isDamaged = false,	// �ǰ� ���� (���� ����)
		.dir = E_Right,
	};

	g_CrabList[E_Jail][g_CrabListIdx[E_Jail]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 170,
		.pos.y = 21,
		.startPosX = 170,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Jail][g_CrabListIdx[E_Jail]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 285,
		.pos.y = 21,
		.startPosX = 285,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	// ���
	g_CrabList[E_DragonPalace][g_CrabListIdx[E_Jail]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 70,
		.pos.y = 21,
		.startPosX = 70,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_DragonPalace][g_CrabListIdx[E_DragonPalace]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 170,
		.pos.y = 21,
		.startPosX = 170,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_DragonPalace][g_CrabListIdx[E_DragonPalace]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 280,
		.pos.y = 21,
		.startPosX = 280,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_DragonPalace][g_CrabListIdx[E_DragonPalace]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 440,
		.pos.y = 21,
		.startPosX = 440,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	// �ٴ�1
	g_CrabList[E_Sea1][g_CrabListIdx[E_Sea1]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 120,
		.pos.y = 13,
		.startPosX = 120,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea1][g_CrabListIdx[E_Sea1]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 190,
		.pos.y = 21,
		.startPosX = 190,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea1][g_CrabListIdx[E_Sea1]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 400,
		.pos.y = 21,
		.startPosX = 400,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea1][g_CrabListIdx[E_Sea1]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 575,
		.pos.y = 17,
		.startPosX = 575,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea1][g_CrabListIdx[E_Sea1]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 580,
		.pos.y = 7,
		.startPosX = 580,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	// �ٴ�2
	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 95,
		.pos.y = 10,
		.startPosX = 95,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 150,
		.pos.y = 21,
		.startPosX = 150,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 410,
		.pos.y = 21,
		.startPosX = 410,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 500,
		.pos.y = 21,
		.startPosX = 500,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 610,
		.pos.y = 21,
		.startPosX = 610,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};
}