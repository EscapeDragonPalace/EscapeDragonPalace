#include "init.h"
#include "crab.h"
#include "fish_big.h"
#include "fish_small.h"

// ���� ����
unsigned long now;

// ���� �ʱ�ȭ
void InitMonster()
{
	now = _GetTickCount();
	InitBigFish();		// ū ����� �ʱ�ȭ
	InitSmallFish();	// ���� ����� �ʱ�ȭ
	InitCrab();			// �ɰ� �ʱ�ȭ
}

// ���� ������Ʈ
void UpdateMonster()
{
	UpdateBigFish(now);	// ū ����� ������Ʈ
	UpdateSmallFish(now);	// ���� ����� ������Ʈ
	UpdateCrab(now);		// �ɰ� ������Ʈ
}

// ���� �׸��� �Լ�
void DrawMonster() {
	DrawBigFish();		// ū ����� �׸���
	DrawSmallFish();	// ���� ����� �׸���
	DrawCrab();			// �ɰ� �׸���
}

// ���� �ǰ� ó�� �Լ�
void HitMonster() {
}