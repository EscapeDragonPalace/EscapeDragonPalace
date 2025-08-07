#include "monster.h"

//1. �̵� 2. ��Ÿ 3. ���� 4. ������ �����ؾ���.

// ---------------- ������ ���� ���� ----------------
static bool isWaterCannonActive = false;
static unsigned int waterCannonStartTime = 0;
static unsigned int lastWaterDropTime = 0;
static unsigned int nextWaterCannonCooldown = 0;
static unsigned int waterCannonDuration = 0;
static unsigned int waterDropInterval = 0;
static Turtle g_Turtle;
//----------------------------------------------------


void DrawTurtle(int dir, int posX, int posY) {
    if (posX + TURTLE_WIDTH < 0 || posX >= SCREEN_WIDTH) return;

    for (int y = 0; y < TURTLE_HEIGHT; y++) {
        const char* line = turtleGraphic[dir][y];
        int len = strlen(line);

        for (int x = 0; x < len; x++) {
            char ch = line[x];
            if (ch != ' ') {
                int drawX = posX + x;
                int drawY = posY + y;
                
                if (0 <= drawX && drawX < SCREEN_WIDTH && 0 <= drawY && drawY < SCREEN_HEIGHT) {
                    char temp[2] = { ch, '\0' };
                    _DrawText(drawX, drawY, temp);
                }
            }
        }
    }
}

#define MAX_WATER_DROPS 10

// --------------------------------------------------

// �ʱ�ȭ �� ��Ÿ�� ����
void InitTurtle() {
        srand(time(NULL)); // ���� �ʱ�ȭ
    nextWaterCannonCooldown = rand() % 4001 + 8000; // 8000 ~ 12000
}

// ������ ������Ʈ �Լ�
void UpdateTurtleWaterCannon(unsigned int now) {
    if (!isWaterCannonActive) {
        if (now - g_Turtle.lastAttackTime >= nextWaterCannonCooldown) {
            isWaterCannonActive = true;
            waterCannonStartTime = now;
            g_Turtle.lastAttackTime = now;

            waterCannonDuration = rand() % 2001 + 3000;   // 3~5��
            waterDropInterval = rand() % 201 + 500;       // 500~700ms
            lastWaterDropTime = now;

            for (int i = 0; i < MAX_WATER_DROPS; i++)
                g_WaterDrops[i].active = false;
        }
        return;
    }

    // ���� ���� ���
    if (now - waterCannonStartTime >= waterCannonDuration) {
        isWaterCannonActive = false;
        nextWaterCannonCooldown = rand() % 4001 + 8000; // ���� ��Ÿ�� ����
        return;
    }

    // ����� ���� Ÿ�̹�
    if (now - lastWaterDropTime >= waterDropInterval) {
        lastWaterDropTime = now;
        // ����ִ� ����� ���Կ� �ϳ� ����
        for (int i = 0; i < MAX_WATER_DROPS; i++) {
            if (!g_WaterDrops[i].active) {
                g_WaterDrops[i].x = rand() % SCREEN_WIDTH;
                g_WaterDrops[i].y = 0;
                g_WaterDrops[i].active = true;
                break;
            }
        }
    }

    // ����� ����
    for (int i = 0; i < MAX_WATER_DROPS; i++) {
        if (g_WaterDrops[i].active) {
            g_WaterDrops[i].y += 1;
            if (g_WaterDrops[i].y >= SCREEN_HEIGHT) {
                g_WaterDrops[i].active = false;
            }
        }
    }
}

// ����� �׸���
void DrawWaterDrops() {
    for (int i = 0; i < MAX_WATER_DROPS; i++) {
        if (g_WaterDrops[i].active) {
            _DrawText(g_WaterDrops[i].x, g_WaterDrops[i].y, "o");  // �Ǵ� "o"�� "*"
        }
    }
}