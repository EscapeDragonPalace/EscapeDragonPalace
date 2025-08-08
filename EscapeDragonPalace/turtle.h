#pragma once
#include "monster.h"

#define TURTLE_HEIGHT 6     // 자라 높이
#define TURTLE_WIDTH 24     // 자라 너비
#define TURTLE_HP 80        // 자라 체력

// 자라 스킬
typedef enum TurtleSkill
{
	E_Basic,		// 평타
	E_Rush,			// 돌진
	E_WaterCannon,	// 물대포
	E_SkillCnt,		// 스킬 갯수
} TurtleSkill;

// 자라
typedef struct BossTurtle
{
	Monster mon;				// 몬스터 구조체 중첩
	Skill skill[E_SkillCnt];	// 스킬 구조체 중첩 (스킬 3개)
	float speed;				// 이동 속도
	bool isDamaged;				// 피격 상태 (무적 여부)
	Direction dir;				// 바라보는 방향
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