#include "init.h"
#include "item.h"
#include "map.h"

typedef char SpriteType[2][ITEM_SPRITE_ROWS][ITEM_SPRITE_COLS];

// ���� sprite
static const char g_SeaweedSprite[2][ITEM_SPRITE_ROWS][ITEM_SPRITE_COLS] = {
	{
		" )) (( ((",
		"((   )) ))",
		" )) (( (("
	},
	{
		"((  )) ))",
		" ))(( ((",
		"((  )) ))"
	}
};

// ������ sprite
static const char g_BubblesSprite[2][ITEM_SPRITE_ROWS][ITEM_SPRITE_COLS] = {
	{
		"o .o",
		".o o"
	},
	{
		".o o",
		"o .o"
	}
};

// ���� sprite
static const char g_ClamSprite[CLAM_WIDTH] = "(\\ /)";

Item g_ItemList[MAX_ITEM_COUNT];	// ������ �迭 ����
int g_ItemIdx = 0;		// ������ ���� �ʱ�ȭ
int g_Frame = 0;		// ������ ���ȿ���� frame �ʱ�ȭ

clock_t g_LastFrameTime = 0;
const int g_FrameDelay = 400;  // 400ms���� ������ ��ȯ

// ������ ���ȿ�� frame ��� �Լ�
void ItemFrameDelay() {
	clock_t now = clock();
	int elapsed = (now - g_LastFrameTime) * 1000 / CLOCKS_PER_SEC;

	if (elapsed >= g_FrameDelay) {
		g_Frame = (g_Frame + 1) % 2;
		g_LastFrameTime = now;
	}

	_Invalidate();  // �� ������ �׸���� ���!
}

// ������ �׸��� �Լ�
void DrawItem() {

	for (int i = 0; i < g_ItemIdx; i++)
	{
		if (!g_ItemList[i].isHeld) {

			SpriteType* sprite = 0;

			// ������ Ÿ�Կ� ���� ���� or ������ sprite ����
			switch (g_ItemList[i].type) {
			case E_ITEM_LIFE:	// ü������(����)�� ��
				sprite = &g_SeaweedSprite;
				_SetColor(E_Green);
				break;
			case E_ITEM_SPEED:	// �ӵ�����(������)�� ��
				sprite = &g_BubblesSprite;
				_SetColor(E_BrightTeal);
				break;
			case E_ITEM_DEBUFF:
				_SetColor(E_White);
				break;
			}


			int tempX = g_ItemList[i].x - GetPlusX();

			switch (g_ItemList[i].type)
			{
			case E_ITEM_LIFE: case E_ITEM_SPEED:
				for (int row = 0; row < g_ItemList[i].height; row++) {
					if ((*sprite)[g_Frame][row] == '\0') break;  // ���� ���̸� �ߴ�

					for (int col = 0; col < g_ItemList[i].width; col++)
					{
						// ������ ��ġ�� ȭ�� ���� ���� ���� ���
						if (0 <= tempX + col && SCREEN_WIDTH >= tempX + col)
						{
							_DrawText(tempX + col, g_ItemList[i].y + row, (char[]) { (*sprite)[g_Frame][row][col], 0 });
						}
					}
				}
				break;
			case E_ITEM_DEBUFF:
				// ������ ��� ������ ���� ���
				for(int col = 0; col < g_ItemList[i].width; col++)
					if (0 <= tempX + col && SCREEN_WIDTH >= tempX + col)
					{
						_DrawText(tempX + col, g_ItemList[i].y, (char[]) { g_ClamSprite[col], 0 });
					}
				break;
			}
		}
	}
}



void InitItem() {

	// ������ ===============================================

	// ����
	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_LIFE,		// ������ ����
		.x = 353, .y = 14,			// ��ġ
		.isHeld = false,			// �÷��̾� ���� ����
		.width = SEAWEED_WIDTH,		// �ʺ�
		.height = SEAWEED_HEIGHT,	// ����
		.mapStatus = E_Jail			// ��
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_LIFE,
		.x = 530, .y = 12,
		.isHeld = false,
		.width = SEAWEED_WIDTH,
		.height = SEAWEED_HEIGHT,
		.mapStatus = E_Jail
	};

	// ������
	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_SPEED,
		.x = 160, .y = 22,
		.isHeld = false,
		.width = BUBBLES_WIDTH,
		.height = BUBBLES_HEIGHT,
		.mapStatus = E_Jail
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_SPEED,
		.x = 570, .y = 22,
		.isHeld = false,
		.width = BUBBLES_WIDTH,
		.height = BUBBLES_HEIGHT,
		.mapStatus = E_Jail
	};

	// ����
	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_DEBUFF,
		.x = 119, .y = 13,
		.isHeld = false,
		.width = CLAM_WIDTH,
		.height = CLAM_HEIGHT,
		.mapStatus = E_Jail
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_DEBUFF,
		.x = 251, .y = 18,
		.isHeld = false,
		.width = CLAM_WIDTH,
		.height = CLAM_HEIGHT,
		.mapStatus = E_Jail
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_DEBUFF,
		.x = 400, .y = 23,
		.isHeld = false,
		.width = CLAM_WIDTH,
		.height = CLAM_HEIGHT,
		.mapStatus = E_Jail
	};

	// ======================================================

	// ��ø� ================================================

	// ����
	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_LIFE,
		.x = 206, .y = 9,
		.isHeld = false,
		.width = SEAWEED_WIDTH,
		.height = SEAWEED_HEIGHT,
		.mapStatus = E_DragonPalace
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_LIFE,
		.x = 288, .y = 6,
		.isHeld = false,
		.width = SEAWEED_WIDTH,
		.height = SEAWEED_HEIGHT,
		.mapStatus = E_DragonPalace
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_LIFE,
		.x = 467, .y = 1,
		.isHeld = false,
		.width = SEAWEED_WIDTH,
		.height = SEAWEED_HEIGHT,
		.mapStatus = E_DragonPalace
	};

	// ������
	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_SPEED,
		.x = 190, .y = 22,
		.isHeld = true,
		.width = BUBBLES_WIDTH,
		.height = BUBBLES_HEIGHT,
		.mapStatus = E_DragonPalace
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_SPEED,
		.x = 340, .y = 22,
		.isHeld = true,
		.width = BUBBLES_WIDTH,
		.height = BUBBLES_HEIGHT,
		.mapStatus = E_DragonPalace
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_SPEED,
		.x = 484, .y = 22,
		.isHeld = true,
		.width = BUBBLES_WIDTH,
		.height = BUBBLES_HEIGHT,
		.mapStatus = E_DragonPalace
	};

	// ����
	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_DEBUFF,
		.x = 145, .y = 19,
		.isHeld = true,
		.width = CLAM_WIDTH,
		.height = CLAM_HEIGHT,
		.mapStatus = E_DragonPalace
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_DEBUFF,
		.x = 308, .y = 13,
		.isHeld = false,
		.width = CLAM_WIDTH,
		.height = CLAM_HEIGHT,
		.mapStatus = E_DragonPalace
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_DEBUFF,
		.x = 413, .y = 23,
		.isHeld = false,
		.width = CLAM_WIDTH,
		.height = CLAM_HEIGHT,
		.mapStatus = E_DragonPalace
	};

	// ======================================================


	// �ٴٸ� 1 ==============================================

	// ����
	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_LIFE,
		.x = 99, .y = 21,
		.isHeld = false,
		.width = SEAWEED_WIDTH,
		.height = SEAWEED_HEIGHT,
		.mapStatus = E_Sea1
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_LIFE,
		.x = 429, .y = 21,
		.isHeld = false,
		.width = SEAWEED_WIDTH,
		.height = SEAWEED_HEIGHT,
		.mapStatus = E_Sea1
	};

	// ������
	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_SPEED,
		.x = 131, .y = 9,
		.isHeld = true,
		.width = BUBBLES_WIDTH,
		.height = BUBBLES_HEIGHT,
		.mapStatus = E_Sea1
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_SPEED,
		.x = 282, .y = 8,
		.isHeld = true,
		.width = BUBBLES_WIDTH,
		.height = BUBBLES_HEIGHT,
		.mapStatus = E_Sea1
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_SPEED,
		.x = 386, .y = 14,
		.isHeld = true,
		.width = BUBBLES_WIDTH,
		.height = BUBBLES_HEIGHT,
		.mapStatus = E_Sea1
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_SPEED,
		.x = 563, .y = 13,
		.isHeld = true,
		.width = BUBBLES_WIDTH,
		.height = BUBBLES_HEIGHT,
		.mapStatus = E_Sea1
	};

	// ����
	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_DEBUFF,
		.x = 140, .y = 23,
		.isHeld = false,
		.width = CLAM_WIDTH,
		.height = CLAM_HEIGHT,
		.mapStatus = E_Sea1
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_DEBUFF,
		.x = 226, .y = 23,
		.isHeld = false,
		.width = CLAM_WIDTH,
		.height = CLAM_HEIGHT,
		.mapStatus = E_Sea1
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_DEBUFF,
		.x = 404, .y = 23,
		.isHeld = false,
		.width = CLAM_WIDTH,
		.height = CLAM_HEIGHT,
		.mapStatus = E_Sea1
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_DEBUFF,
		.x = 532, .y = 23,
		.isHeld = false,
		.width = CLAM_WIDTH,
		.height = CLAM_HEIGHT,
		.mapStatus = E_Sea1
	};

	// ======================================================


	// �ٴٸ� 2 ==============================================

	// ����
	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_LIFE,
		.x = 100, .y = 21,
		.isHeld = false,
		.width = SEAWEED_WIDTH,
		.height = SEAWEED_HEIGHT,
		.mapStatus = E_Sea2
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_LIFE,
		.x = 210, .y = 5,
		.isHeld = false,
		.width = SEAWEED_WIDTH,
		.height = SEAWEED_HEIGHT,
		.mapStatus = E_Sea2
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_LIFE,
		.x = 471, .y = 21,
		.isHeld = false,
		.width = SEAWEED_WIDTH,
		.height = SEAWEED_HEIGHT,
		.mapStatus = E_Sea2
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_LIFE,
		.x = 542, .y = 11,
		.isHeld = false,
		.width = SEAWEED_WIDTH,
		.height = SEAWEED_HEIGHT,
		.mapStatus = E_Sea2
	};

	// ������
	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_SPEED,
		.x = 138, .y = 11,
		.isHeld = true,
		.width = BUBBLES_WIDTH,
		.height = BUBBLES_HEIGHT,
		.mapStatus = E_Sea2
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_SPEED,
		.x = 440, .y = 17,
		.isHeld = true,
		.width = BUBBLES_WIDTH,
		.height = BUBBLES_HEIGHT,
		.mapStatus = E_Sea2
	};

	// ����
	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_DEBUFF,
		.x = 62, .y = 23,
		.isHeld = false,
		.width = CLAM_WIDTH,
		.height = CLAM_HEIGHT,
		.mapStatus = E_Sea2
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_DEBUFF,
		.x = 167, .y = 23,
		.isHeld = false,
		.width = CLAM_WIDTH,
		.height = CLAM_HEIGHT,
		.mapStatus = E_Sea2
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_DEBUFF,
		.x = 247, .y = 23,
		.isHeld = false,
		.width = CLAM_WIDTH,
		.height = CLAM_HEIGHT,
		.mapStatus = E_Sea2
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_DEBUFF,
		.x = 335, .y = 23,
		.isHeld = false,
		.width = CLAM_WIDTH,
		.height = CLAM_HEIGHT,
		.mapStatus = E_Sea2
	};

	g_ItemList[g_ItemIdx++] = (Item){
		.type = E_ITEM_DEBUFF,
		.x = 374, .y = 18,
		.isHeld = false,
		.width = CLAM_WIDTH,
		.height = CLAM_HEIGHT,
		.mapStatus = E_Sea2
	};

	// ======================================================
}
