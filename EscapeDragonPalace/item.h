#pragma once

#include "map.h"

#define ITEM_SPRITE_ROWS 10
#define ITEM_SPRITE_COLS 20
#define ITEMNUM 2            // ������ ���� ��
#define MAX_ITEM_COUNT 100   // �ʿ� ������ �� �ִ� ������ �ν��Ͻ� ��
#define SPEEDUP 0.5     // �ӵ� ������
#define LIFEUP 2        // ���� ������

typedef enum {
    E_ITEM_SPEED,
    E_ITEM_LIFE
} ItemType;

typedef struct Item {
    ItemType type;
    float x, y;
    bool isHeld;    // 0: �ٴڿ� ����, 1: �÷��̾ ����
    float width, height;
    MapStatus mapStatus;
} Item;

typedef char SpriteType[2][ITEM_SPRITE_ROWS][ITEM_SPRITE_COLS];

extern SpriteType seaweedSprite;
extern SpriteType bubblesSprite;

extern Item itemList[MAX_ITEM_COUNT];
extern int numItem;

void InitItem();
void DrawItem();
void ItemFrameDelay();
