#include "init.h"
#include "monster.h"

Monster monsterList[MAX_Monster_COUNT];	// ���� �迭 ����
int numMonster = 0;

// ���� ������Ʈ
void UpdateMonster()
{
	// ���� �迭 for��
	for (int i = 0; i < numMonster; i++) {
		// ������ ��
		if (monsterList[i].type == E_MONSTER_CLAM) {
			UpdateClam(monsterList[i].pos, monsterList[i].alive);
		}
		// �ڶ��� ��
		else if (monsterList[i].type == E_MONSTER_TURTLE) {
			// �ڶ� ������Ʈ �Լ� ����
		}
		// �� ��(ū�����, ���������, �ɰ�)
		else {
			// ȭ�鿡 ������ �ʴ� ����(�׾��ų� �ٸ� ��������)�� ��� �Ѿ��
			if (!monsterList[i].alive) continue;
			unsigned int now = _GetTickCount();

			// �����ð� ������ �ǰ� ���� ����
			if (monsterList[i].isDamaged && now - monsterList[i].lastHitTime >= INVINCIBLE_TIME) {
				monsterList[i].isDamaged = false;
			}

			// ���� �̵�
			monsterList[i].pos.x += (monsterList[i].dir == Right) ? 1 : -1;

			// ���� �� �浹 �� ���� ��ȯ
			/*if (monsterList[i].pos.x <= 0) {
				monsterList[i].pos.x = 0;
				monsterList[i].dir = Right;
			}*/

			// ���� Ÿ�Կ� ���� ������ �� �浹�� ������ȯ
			if (monsterList[i].type == E_MONSTER_FISH) {
				// �����
				if (monsterList[i].pos.x + FISH_WIDTH >= monsterList[i].pos.x + monsterList[i].moveNum + GetPlusX()) {
					monsterList[i].pos.x = monsterList[i].moveNum - FISH_WIDTH;
					monsterList[i].dir = Left;
				}
			}
			else if (monsterList[i].type == E_MONSTER_CRAB) {
				// �ɰ�
				if (monsterList[i].pos.x + CRAB_WIDTH >= monsterList[i].pos.x + monsterList[i].moveNum - GetPlusX()) {
					monsterList[i].pos.x = monsterList[i].moveNum - CRAB_WIDTH;
					monsterList[i].dir = Left;
				}
			}
			else if (monsterList[i].type == E_MONSTER_SMALLFISH) {
				// ���� �����
				if (monsterList[i].pos.x + SMALLFISH_WIDTH >= monsterList[i].pos.x + monsterList[i].moveNum + GetPlusX()) {
					monsterList[i].pos.x = monsterList[i].moveNum - SMALLFISH_WIDTH;
					monsterList[i].dir = Left;
				}
			}

		}

	}

}

// ���� �׸��� �Լ�
void DrawMonster() {

	for (int i = 0; i < numMonster; i++)
	{
		int tempX = monsterList[i].pos.x - GetPlusX();  // ī�޶� ���� ��ġ ����
		if (monsterList[i].alive) {

			switch (monsterList[i].type)
			{
			case E_MONSTER_FISH:
				_SetColor(monsterList[i].isDamaged ? 12 : 9);
				DrawFish(monsterList[i].dir, tempX, monsterList[i].pos.y);
				break;
			case E_MONSTER_CRAB:
				_SetColor(monsterList[i].isDamaged ? 6 : 12);  // �ǰ� �� �����, ��� ������
				DrawCrab(tempX, monsterList[i].pos.y);
				break;
			case E_MONSTER_CLAM:
				_SetColor(E_White);
				DrawClam(tempX, monsterList[i].pos.y);
				break;
			case E_MONSTER_TURTLE:
				break;
			case E_MONSTER_SMALLFISH:
				//_SetColor(monsterList[i].isDamaged ? 12 : 15);
				DrawSmallFish(monsterList[i].dir, tempX, monsterList[i].pos.y);
				break;
			}
		}
	}

}

// ���� �ǰ� ó�� �Լ�
void HitMonster(Monster* monster, Weapon* weapon, unsigned int now) {
	if (monster->isDamaged) return;

	monster->hp -= weapon->attack;
	monster->isDamaged = true;	// ���� ���� ����
	monster->lastHitTime = now;	// �ǰ� �ð� ���

	if (monster->hp <= 0) {
		monster->alive = false;         // ü���� 0 ���ϰ� �Ǹ� ��� ó��
	}
}


// ���� �ʱ�ȭ �Լ�
void InitMonster() {
	//����
	//�ɰ�
	monsterList[numMonster++] = (Monster){
		.pos.x = 100,
		.pos.y = 21,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 0
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 170,
		.pos.y = 21,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 0
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 285,
		.pos.y = 21,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 0
	};



	//�����
	monsterList[numMonster++] = (Monster){
		.pos.x = 100,
		.pos.y = 11,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_FISH,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 0
	};

	monsterList[numMonster++] = (Monster){
	.pos.x = 170,
	.pos.y = 11,
	.moveNum = 30,
	.dir = Right,
	.hp = 5,
	.alive = true,
	.type = E_MONSTER_FISH,
	.isDamaged = false,
	.lastHitTime = 0,
	.mapStatus = 0
	};

	monsterList[numMonster++] = (Monster){
	.pos.x = 300,
	.pos.y = 11,
	.moveNum = 30,
	.dir = Right,
	.hp = 5,
	.alive = true,
	.type = E_MONSTER_FISH,
	.isDamaged = false,
	.lastHitTime = 0,
	.mapStatus = 0
	};

	monsterList[numMonster++] = (Monster){
	.pos.x = 500,
	.pos.y = 12,
	.moveNum = 30,
	.dir = Right,
	.hp = 5,
	.alive = true,
	.type = E_MONSTER_FISH,
	.isDamaged = false,
	.lastHitTime = 0,
	.mapStatus = 0
	};

	monsterList[numMonster++] = (Monster){
	.pos.x = 500,
	.pos.y = 21,
	.moveNum = 30,
	.dir = Right,
	.hp = 5,
	.alive = true,
	.type = E_MONSTER_FISH,
	.isDamaged = false,
	.lastHitTime = 0,
	.mapStatus = 0
	};

	//����
	monsterList[numMonster++] = (Monster){
		.pos.x = 119,
		.pos.y = 13,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CLAM,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = E_Jail
	};

	monsterList[numMonster++] = (Monster){
	.pos.x = 251,
	.pos.y = 18,
	.moveNum = 30,
	.dir = Right,
	.hp = 5,
	.alive = true,
	.type = E_MONSTER_CLAM,
	.isDamaged = false,
	.lastHitTime = 0,
	.mapStatus = E_Jail
	};

	monsterList[numMonster++] = (Monster){
	.pos.x = 400,
	.pos.y = 23,
	.moveNum = 30,
	.dir = Right,
	.hp = 5,
	.alive = true,
	.type = E_MONSTER_CLAM,
	.isDamaged = false,
	.lastHitTime = 0,
	.mapStatus = E_Jail
	};

	//��ø�
	//�ɰ�
	monsterList[numMonster++] = (Monster){
		.pos.x = 70,
		.pos.y = 21,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 1
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 170,
		.pos.y = 21,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 1
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 280,
		.pos.y = 21,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 1
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 440,
		.pos.y = 21,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 1
	};


	//�����
	monsterList[numMonster++] = (Monster){
	.pos.x = 70,
	.pos.y = 14,
	.moveNum = 30,
	.dir = Right,
	.hp = 5,
	.alive = true,
	.type = E_MONSTER_FISH,
	.isDamaged = false,
	.lastHitTime = 0,
	.mapStatus = 1
	};

	monsterList[numMonster++] = (Monster){
	.pos.x = 170,
	.pos.y = 14,
	.moveNum = 30,
	.dir = Right,
	.hp = 5,
	.alive = true,
	.type = E_MONSTER_FISH,
	.isDamaged = false,
	.lastHitTime = 0,
	.mapStatus = 1
	};

	monsterList[numMonster++] = (Monster){
	.pos.x = 280,
	.pos.y = 11,
	.moveNum = 30,
	.dir = Right,
	.hp = 5,
	.alive = true,
	.type = E_MONSTER_FISH,
	.isDamaged = false,
	.lastHitTime = 0,
	.mapStatus = 1
	};

	monsterList[numMonster++] = (Monster){
	.pos.x = 520,
	.pos.y = 11,
	.moveNum = 30,
	.dir = Right,
	.hp = 5,
	.alive = true,
	.type = E_MONSTER_FISH,
	.isDamaged = false,
	.lastHitTime = 0,
	.mapStatus = 1
	};

	//����
	monsterList[numMonster++] = (Monster){
		.pos.x = 145,
		.pos.y = 19,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CLAM,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = E_DragonPalace
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 308,
		.pos.y = 13,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CLAM,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = E_DragonPalace
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 413,
		.pos.y = 23,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CLAM,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = E_DragonPalace
	};

	//�ٴ� 1��
	//�ɰ�
	monsterList[numMonster++] = (Monster){
		.pos.x = 120,
		.pos.y = 13,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 2
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 190,
		.pos.y = 21,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 2
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 400,
		.pos.y = 21,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 2
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 575,
		.pos.y = 17,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 2
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 580,
		.pos.y = 7,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 2
	};


	//�����
	monsterList[numMonster++] = (Monster){
	.pos.x = 120,
	.pos.y = 21,
	.moveNum = 30,
	.dir = Right,
	.hp = 5,
	.alive = true,
	.type = E_MONSTER_FISH,
	.isDamaged = false,
	.lastHitTime = 0,
	.mapStatus = 2
	};

	monsterList[numMonster++] = (Monster){
	.pos.x = 190,
	.pos.y = 12,
	.moveNum = 30,
	.dir = Right,
	.hp = 5,
	.alive = true,
	.type = E_MONSTER_FISH,
	.isDamaged = false,
	.lastHitTime = 0,
	.mapStatus = 2
	};

	monsterList[numMonster++] = (Monster){
	.pos.x = 300,
	.pos.y = 21,
	.moveNum = 30,
	.dir = Right,
	.hp = 5,
	.alive = true,
	.type = E_MONSTER_FISH,
	.isDamaged = false,
	.lastHitTime = 0,
	.mapStatus = 2
	};

	monsterList[numMonster++] = (Monster){
	.pos.x = 400,
	.pos.y = 13,
	.moveNum = 30,
	.dir = Right,
	.hp = 5,
	.alive = true,
	.type = E_MONSTER_FISH,
	.isDamaged = false,
	.lastHitTime = 0,
	.mapStatus = 2
	};

	monsterList[numMonster++] = (Monster){
	.pos.x = 480,
	.pos.y = 21,
	.moveNum = 30,
	.dir = Right,
	.hp = 5,
	.alive = true,
	.type = E_MONSTER_FISH,
	.isDamaged = false,
	.lastHitTime = 0,
	.mapStatus = 2
	};

	//����
	monsterList[numMonster++] = (Monster){
		.pos.x = 140,
		.pos.y = 23,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CLAM,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = E_Sea1
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 226,
		.pos.y = 23,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CLAM,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = E_Sea1
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 404,
		.pos.y = 23,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CLAM,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = E_Sea1
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 532,
		.pos.y = 23,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CLAM,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = E_Sea1
	};

	//�ٴٸ�2
	//�ɰ�
	monsterList[numMonster++] = (Monster){
		.pos.x = 95,
		.pos.y = 10,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 3
	};
	monsterList[numMonster++] = (Monster){
		.pos.x = 150,
		.pos.y = 21,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 3
	};
	monsterList[numMonster++] = (Monster){
		.pos.x = 410,
		.pos.y = 21,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 3
	};
	monsterList[numMonster++] = (Monster){
		.pos.x = 500,
		.pos.y = 21,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 3
	};
	monsterList[numMonster++] = (Monster){
		.pos.x = 500,
		.pos.y = 16,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 3
	};
	monsterList[numMonster++] = (Monster){
		.pos.x = 610,
		.pos.y = 21,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CRAB,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 3
	};

	//�����
	monsterList[numMonster++] = (Monster){
		.pos.x = 260,
		.pos.y = 21,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_FISH,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 3
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 320,
		.pos.y = 16,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_FISH,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 3
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 410,
		.pos.y = 16,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_FISH,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = 3
	};

	//����
	monsterList[numMonster++] = (Monster){
		.pos.x = 62,
		.pos.y = 23,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CLAM,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = E_Sea2
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 167,
		.pos.y = 23,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CLAM,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = E_Sea2
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 247,
		.pos.y = 23,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CLAM,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = E_Sea2
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 335,
		.pos.y = 23,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CLAM,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = E_Sea2
	};

	monsterList[numMonster++] = (Monster){
		.pos.x = 374,
		.pos.y = 18,
		.moveNum = 30,
		.dir = Right,
		.hp = 5,
		.alive = true,
		.type = E_MONSTER_CLAM,
		.isDamaged = false,
		.lastHitTime = 0,
		.mapStatus = E_Sea2
	};
}