#pragma once
#include "init.h"
#include "map.h"

// ��ũ��
#define MONSTER_CNT 3	// �󽺴� ���� ��
#define INVINCIBLE_TIME 1000  // �����ð� (1��)

// ���� ����ü
typedef struct Monster
{
	bool alive;					// ���� ����
	int hp;						// ���� ü��
	float speed;				// �̵� �ӵ�
	unsigned long lastHitTime;	// ������ �ǰ� �ð�
} Monster;

// ��ų ����ü
typedef struct Skill
{
	bool isAttack;		// ��ų ��� ������ ����
	int attackCnt;		// ��ų ���� Ƚ��
	int attack;			// ��ų ���ݷ�
	long coolTime;		// ��ų ��Ÿ�� (ms)
} Skill;

// ���� Ÿ�� ������
typedef enum MonsterType
{
	E_MONSTER_FISH,
	E_MONSTER_CRAB,
	E_MONSTER_CLAM,
	E_MONSTER_TURTLE,
	E_MONSTER_SMALLFISH,
	E_MONSTER_TYPE_COUNT
} MonsterType;

// �Լ�
void InitMonster();		// �ʱ�ȭ
void UpdateMonster();	// ������Ʈ
void DrawMonster();		// �׸���