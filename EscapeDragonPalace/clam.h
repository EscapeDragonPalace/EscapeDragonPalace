#pragma once

// ��ũ��
#define CLAM_WIDTH 8
#define CLAM_HEIGHT 1
#define CLAM_HP 1

// ��������
static const char g_ClamGraphic[CLAM_WIDTH] = "(\\ /)";

//���� �Լ�
void TriggerClam();
void UpdateClam(MyPoint pos, bool alive);
void DrawClam(int posX, int posY);