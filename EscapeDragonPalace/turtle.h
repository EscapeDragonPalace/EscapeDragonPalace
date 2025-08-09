#pragma once
#include "monster.h"

#define TURTLE_HEIGHT 6     // �ڶ� ����
#define TURTLE_WIDTH 24     // �ڶ� �ʺ�
#define TURTLE_HP 80        // �ڶ� ü��

// ���� Ƚ��
#define TURTLE_RUSH_COUNT  3
// ���� Y��ǥ
#define TURTLE_IDLE_Y      18

// ����� ���� ���� (500~700ms)
#define WATER_DROP_INTERVAL_MIN_MS 500
#define WATER_DROP_INTERVAL_MAX_MS 700
#define MAX_WATER_DROPS 64
#define WATER_DROP_MOVE_MS 150

// ����� ���ӽð� (3~5��)
#define WATER_WAVE_DURATION_MIN_MS 3000
#define WATER_WAVE_DURATION_MAX_MS 5000

// ����� ��Ÿ�� (8~12��)
#define WATER_WAVE_COOLDOWN_MIN_MS 8000
#define WATER_WAVE_COOLDOWN_MAX_MS 12000

// �ڶ� �Ӹ� ���� �¿� ������
#define TURTLE_ATTACK_RANGE 7

// ��Ÿ ��Ÿ�� (5��)
#define TURTLE_ATTACK_COOLDOWN_MS 5000

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

// �ڶ� ��ų
typedef enum TurtleSkill
{
	E_Basic,		// ��Ÿ
	E_Rush,			// ����
	E_WaterCannon,	// ������
	E_SkillCnt,		// ��ų ����
} TurtleSkill;

// �ڶ� ����ü
typedef struct Turtle
{
	Monster mon;	// ���� ����ü ��ø
	MyPoint pos;	// ��ġ
	float speed;	// �̵� �ӵ�
	int attack;		// ���ݷ�
	bool isDamaged;	// �ǰ� ���� (���� ����)
	Direction dir;	// �ٶ󺸴� ����
} Turtle;

// �ڶ� ����ü
//typedef struct {
//	MyPoint pos;
//	float speed;
//	int dir;
//	int hp;
//	int attack;
//	bool alive;
//	bool isDamaged;
//	unsigned int lastHitTime;
//} Turtle;

typedef enum TurtleState {
	TURTLE_STATE_IDLE,          // ���� �ڶ�
	TURTLE_STATE_PREPARE_RUSH,  // ���� �غ�
	TURTLE_STATE_RUSHING,       // ���� ��
	TURTLE_STATE_ATTACK
} TurtleState;

extern Turtle g_Turtle;

// ���� ����(��Ÿ)
extern int g_NormalJumpY;

// ���� �ö� �� / ������ �� �ܰ� ��, ������(ms)
extern int g_TurtleAscentSteps;
extern int g_TurtleDescentSteps;
extern unsigned int g_TurtleAscentFrameMs;
extern unsigned int g_TurtleDescentFrameMs;

// ��Ÿ �� ���߿��� ���ߴ� �ð�
extern unsigned int g_TurtlePeakHoldMs;

void SetTurtleJumpY(int y);
void SetTurtleAscentSteps(int steps);
void SetTurtleDescentSteps(int steps);
void SetTurtleAscentFrameMs(unsigned int ms);
void SetTurtleDescentFrameMs(unsigned int ms);
void SetTurtlePeakHoldMs(unsigned int ms);

void InitTurtle(unsigned int now);
void UpdateTurtle(unsigned int now);
void DrawTurtle(void);
void TurtleHitP(int posX, int posY);