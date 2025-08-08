#pragma once
#include "monster.h"

#define TURTLE_HEIGHT 6     // �ڶ� ����
#define TURTLE_WIDTH 24     // �ڶ� �ʺ�
#define TURTLE_HP 80        // �ڶ� ü��

// �ڶ� ��ų
typedef enum TurtleSkill
{
	E_Basic,		// ��Ÿ
	E_Rush,			// ����
	E_WaterCannon,	// ������
	E_SkillCnt,		// ��ų ����
} TurtleSkill;

// �ڶ�
typedef struct BossTurtle
{
	Monster mon;				// ���� ����ü ��ø
	Skill skill[E_SkillCnt];	// ��ų ����ü ��ø (��ų 3��)
	float speed;				// �̵� �ӵ�
	bool isDamaged;				// �ǰ� ���� (���� ����)
	Direction dir;				// �ٶ󺸴� ����
} BossTurtle;

static const char turtleGraphic[2][TURTLE_HEIGHT][TURTLE_WIDTH] =
{
	{
		"        ________",
		"  ___ _/ \\__/ \\_   /|",
		" (_o / \\ /  \\ / \\_/ |",
		"  \\__ -----------__/",
		"      \\_|_|_|_|_/ ",
		"     /_|_|  /_|_|"
	},
	{
		"        ________",
		"|\\   _/ \\__/ \\_ ___",
		"| \\_/ \\ /  \\ / \\ o_)",
		" \\__----------- __/",
		"    \\_|_|_|_|_/",
		"    |_|_\\  |_|_\\ ",
	}
};