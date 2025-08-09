#include "init.h"
#include "crab.h"

Monster g_CrabMon;	// �ɰ� ���� ����ü ���� ����
Skill g_CrabSkill;	// �ɰ� ��ų ����ü ���� ����
Crab g_CrabList[STAGE_CNT][CRAB_CNT];	// �ɰ� ����Ʈ �迭
int g_CrabListIdx[STAGE_CNT] = { 0, };

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
		if (tempCrab[idx].mon.isDamaged && now - tempCrab[idx].mon.lastHitTime >= INVINCIBLE_TIME)
		{
			tempCrab[idx].mon.isDamaged = false;
		}

		// ���� �̵�
		tempCrab[idx].pos.x += (tempCrab[idx].dir == E_Right) ? g_CrabMon.speed : -g_CrabMon.speed;

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
void HitCrab(Weapon* weapon, unsigned int now) {
	for (int idx = 0; idx < g_CrabListIdx[GetMapStatus()]; idx++)
	{
		Crab tempCrab = g_CrabList[GetMapStatus()][idx];
		if (tempCrab.mon.alive) return;

		tempCrab.mon.hp -= weapon->attack;
		tempCrab.mon.isDamaged = true;	// ���� ���� ����
		tempCrab.mon.lastHitTime = now;	// �ǰ� �ð� ���

		if (tempCrab.mon.hp <= 0) {
			tempCrab.mon.alive = false;	// ü���� 0 ���ϰ� �Ǹ� ��� ó��
		}
	}
}

// �ɰ� �׸���
void DrawCrab()
{
	// ���� �� ������ �ӽ÷� �ҷ�����
	Crab* tempCrab = g_CrabList[GetMapStatus()];
	for (int idx = 0; idx < g_CrabListIdx[GetMapStatus()]; idx++)
	{
		// �ǰ� �� �����, ��� ������
		_SetColor(g_CrabList[GetMapStatus()][idx].mon.isDamaged ? E_Yellow : E_BrightRed);

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
		.isDamaged = false,	// �ǰ� ���� (���� ����)
		.lastHitTime = 0,	// ������ �ǰ� �ð�
		.speed = 0.8,		// �̵� �ӵ�
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
		.pos.x = 95,		// X ��ǥ
		.pos.y = 21,		// Y ��ǥ
		.startPosX = 95,	// �ʱ� X ��ǥ
		.moveNum = 64,		// �̵� ����
		.dir = E_Right,
	};

	g_CrabList[E_Jail][g_CrabListIdx[E_Jail]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 170,
		.pos.y = 21,
		.startPosX = 170,
		.moveNum = 64,
		.dir = E_Right,
	};

	g_CrabList[E_Jail][g_CrabListIdx[E_Jail]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 277,
		.pos.y = 21,
		.startPosX = 277,
		.moveNum = 92,
		.dir = E_Right,
	};

	// ���
	g_CrabList[E_DragonPalace][g_CrabListIdx[E_DragonPalace]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 72,
		.pos.y = 21,
		.startPosX = 72,
		.moveNum = 60,
		.dir = E_Right,
	};

	g_CrabList[E_DragonPalace][g_CrabListIdx[E_DragonPalace]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 170,
		.pos.y = 21,
		.startPosX = 170,
		.moveNum = 61,
		.dir = E_Right,
	};

	g_CrabList[E_DragonPalace][g_CrabListIdx[E_DragonPalace]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 246,
		.pos.y = 21,
		.startPosX = 246,
		.moveNum = 86,
		.dir = E_Right,
	};

	g_CrabList[E_DragonPalace][g_CrabListIdx[E_DragonPalace]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 440,
		.pos.y = 21,
		.startPosX = 440,
		.moveNum = 125,
		.dir = E_Right,
	};

	// �ٴ�1
	g_CrabList[E_Sea1][g_CrabListIdx[E_Sea1]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 80,
		.pos.y = 13,
		.startPosX = 80,
		.moveNum = 96,
		.dir = E_Right,
	};

	g_CrabList[E_Sea1][g_CrabListIdx[E_Sea1]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 187,
		.pos.y = 21,
		.startPosX = 187,
		.moveNum = 75,
		.dir = E_Right,
	};

	g_CrabList[E_Sea1][g_CrabListIdx[E_Sea1]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 373,
		.pos.y = 21,
		.startPosX = 373,
		.moveNum = 73,
		.dir = E_Right,
	};

	g_CrabList[E_Sea1][g_CrabListIdx[E_Sea1]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 574,
		.pos.y = 17,
		.startPosX = 574,
		.moveNum = 60,
		.dir = E_Right,
	};

	g_CrabList[E_Sea1][g_CrabListIdx[E_Sea1]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 580,
		.pos.y = 7,
		.startPosX = 580,
		.moveNum = 47,
		.dir = E_Right,
	};

	// �ٴ�2
	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 76,
		.pos.y = 10,
		.startPosX = 76,
		.moveNum = 76,
		.dir = E_Right,
	};

	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 150,
		.pos.y = 21,
		.startPosX = 150,
		.moveNum = 41,
		.dir = E_Right,
	};

	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 404,
		.pos.y = 21,
		.startPosX = 404,
		.moveNum = 50,
		.dir = E_Right,
	};

	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 546,
		.pos.y = 21,
		.startPosX = 491,
		.moveNum = 55,
		.dir = E_Right,
	};

	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 491,
		.pos.y = 16,
		.startPosX = 491,
		.moveNum = 55,
		.dir = E_Right,
	};

	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 610,
		.pos.y = 21,
		.startPosX = 610,
		.moveNum = 62,
		.dir = E_Right,
	};
}