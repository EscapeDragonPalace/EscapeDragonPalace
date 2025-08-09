#pragma once

#include "init.h"
#include "weapon.h"
#include "item.h"
#include "monster.h"

// --------------------------------------------------

#define RabbitX 25 // Rabbit char ���� ũ��
#define RabbitY 3 // Rabbit char ���� ũ��
#define RABBIT_SPEED 1	// Rabbit �̵� �ӵ�

#define JUMP_POWER -2.5f // ���� ���� (������ �� ���� ���� ������)
#define GRAVITY 0.5f // �߷� ���ӵ�
#define MAX_FALL_SPEED 4.0f  // �ִ� ���� �ӵ�

#define RabbitXPos 7.0f
#define RabbitYPos 21.0f

#define DURATION 5000

#define SLOWDURATION 3000

// --------------------------------------------------

typedef struct Player
{
	MyPoint Pos; // �÷��̾� ��ġ
	float Speed; // �÷��̾� �̵� �ӵ�
	int Health; // �÷��̾� ü��

	Weapon* HeldWeapon; // ���� (0 = ���, 1 = �ܰ�, 2 = â)

	float VelY; // Y�� �ӵ� (����, ���� ��)
	bool IsJumping; // ���� ������ ����
	int Direction; // �÷��̾� ���� (0 = ������, 1 = ����)

	bool IsAttacking;      // ���� ������ ����
	DWORD attackStartTime; // ���� ���� �ð�
	int attackDuration; // ���� ���� �ð� (ms)

	int AttackFrame;       // ���� �ִϸ��̼� ������ ī����
	int AttackFrameMax;    // ���� ���⿡ �´� ���� �ִϸ��̼� ������ ����

	unsigned int lastHitTime; // ������ �ǰ� �ð�
}Player;
Player player;


typedef struct SpeedBuff {
	DWORD endTime;      // ���� �ð� (ms)
	bool active;
} SpeedBuff;

// --------------------------------------------------

bool SetMapEnd(bool src);
bool GetKeyW();
bool GetKeyA();
bool GetKeyD();
bool GetKeyS();
bool IsNearItem();
void SetIsNearItem(bool src);
bool StageClear();
bool IsOverlap(Rect player, Rect Obj);
Rect GetPlayerRect();
Rect GetItemRect(Item item);
Rect GetMonsterRect(Monster monster);
Rect GetWeaponRect();
void HitPlayer();
void CheckItemPickup();
void UpdateBuffs();
void ClearRabbitAt(int x, int y);
void DrawRabbitAt(int x, int y, int idx);
void RabbitCAnim();
void GetInput();
bool CheckGround();
void ApplyGravity();
int GetGroundY();
void JumpFN();
void AttackFN();
void moveFN();
void ISOnGoal();
void ClearInputBuffer();
void UpdatePlayer();
void DrawPlayer();
void DrawHealth();
void InitPlayer();
void ClimbLadder();
void DrawBuffNDebuff();





