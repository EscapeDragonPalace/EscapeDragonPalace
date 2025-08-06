#include "weapon.h"
#include "map.h"
#include "clam.h"
#include "crab.h"
#include "fish.h"
#include "small_fish.h"
#include "turtle.h"

#define MONSTER_H

#define INVINCIBLE_TIME 1000  // 1�� �����ð�

#define Right 0
#define Left 1

#define MONSTER_Y 21 // ���� Y��ǥ �ʱ� ��ġ

#define MAX_Monster_COUNT 100


typedef enum MonsterType 
{
    E_MONSTER_FISH,
    E_MONSTER_CRAB,
    E_MONSTER_CLAM,
    E_MONSTER_TURTLE,
    E_MONSTER_SMALLFISH,
    E_MONSTER_TYPE_COUNT
} MonsterType;

// ���� ���ݷ� ������
typedef enum MonsterAttack
{
    E_FISH_ATTACK = 2,          // �����: �� ĭ
    E_SMALL_FISH_ATTACK = 1,    // ���� �����: �� ĭ
    E_CRAB_ATTACK = 1,          // �ɰ�: �� ĭ �� 3��
    E_CLAM_ATTACK = 1,          // ����: �� ĭ
    E_TURTLE_ATTACK = 2,        // �ڶ� �Ϲ� ��ų: �� ĭ
    E_TURTLE_RUSH = 4,          // �ڶ� ���� ��ų: �� ĭ
    E_TURTLE_WATTER_CANNON = 1, // �ڶ� ������ ��ų: �� ĭ
} MonsterAttack;

typedef struct Monster {
    MyPoint pos;        // ��ġ
    int moveNum;        // �̵� ĭ ��
    int dir;            // ���� 
    int hp;             // ü��
    float speed;        // �̵� �ӵ�
    int attack;         // ���ݷ�
    bool alive;          // ��������
    MonsterType type;   // ���� ����
    bool isDamaged;      // �ǰ� ����(���� ����)
    unsigned int lastHitTime;  // ������ �ǰ� �ð�
    MapStatus mapStatus; // �� �����Ҷ� ���
} Monster;

extern Monster monsterList[MAX_Monster_COUNT];
extern int numMonster;

void UpdateMonster();
void HitMonster(Monster* monster, Weapon* weapon, unsigned int now);
void InitMonster();
void DrawMonster();

// (�ڶ� �Լ��� ���� �������� �߰�)