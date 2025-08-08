#pragma once
#include "monster.h"

// ��ũ��
#define CRAB_WIDTH 13   // �ɰ� �ʺ�
#define CRAB_HEIGHT 3   // �ɰ� ����
#define CRAB_HP 5		// �ɰ� ü��
#define CRAB_ATTACK 1   // �ɰ� ���ݷ�
#define CRAB_CNT 17     // �ɰ� �迭 ��

// �ɰ�
typedef struct Crab
{
    Monster mon;		// ���� ����ü ��ø
    Skill skill;		// ��ų ����ü ��ø
    MyPoint pos;		// ��ġ
    float startPosX;	// ���� x ��ġ
    int moveNum;		// �̵� ����
    bool isDamaged;	    // �ǰ� ���� (���� ����)
    Direction dir;      // ���� ����
} Crab;

// ���� ����
const static char g_CrabGraphic[2][CRAB_HEIGHT][CRAB_WIDTH] = {
    {
        "(\\/) (\\/)",
         "  \\o_o/ ",
         " =(___)= "
    }, // �⺻

    {
        "(|)  (|)",
         " \\o_o/ ",
         "=(___)= "
    } // ����
};

// �Լ�
void InitCrab();    // �ʱ�ȭ
void DrawCrab();    // �׸���
void UpdateCrab();  // ������Ʈ