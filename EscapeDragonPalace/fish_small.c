#include "init.h"
#include "fish_small.h"

Monster g_SmallFishMon;	// 작은 물고기 몬스터 구조체 공통 설정
SmallFish g_SmallFishList[STAGE_CNT][SMALLFISH_CNT];	// 작은 물고기 포인트 배열
int g_SmallFishListIdx[STAGE_CNT - 1] = { 0, };	// 보스맵 제외

// 작은 물고기 업데이트
void UpdateSmallFish(unsigned long now)
{
	// 현재 맵의 몬스터 데이터 불러오기
	SmallFish* tempSmallFish = g_SmallFishList[GetMapStatus()];
	for (int idx = 0; idx < g_SmallFishListIdx[GetMapStatus()]; idx++)
	{
		// 몬스터가 죽었을 경우 넘어가기
		if (!tempSmallFish[idx].mon.alive) continue;

		// 몬스터 이동
		--tempSmallFish[idx].pos.x;

		// 몬스터가 왼쪽 화면 밖으로 넘어갔을 경우 죽음 처리
		if (tempSmallFish[idx].pos.x <= 0)
		{
			tempSmallFish[idx].mon.alive = false;
		}
	}
}

// 작은 물고기 그리기
void DrawSmallFish()
{
	_SetColor(E_Teal);	// 항상 파란색

	// 현재 맵 데이터 임시로 불러오기
	SmallFish* tempSmallFish = g_SmallFishList[GetMapStatus()];
	for (int idx = 0; idx < g_SmallFishListIdx[GetMapStatus()]; idx++)
	{
		int tempX = tempSmallFish[idx].pos.x - GetPlusX();
		for (int x = 0; x < SMALLFISH_WIDTH; x++)
		{
			if (g_SmallFishGraphic[x] != ' ')
			{
				// 화면 범위 내에 있을 경우 그리기
				if (0 <= tempX + x && SCREEN_WIDTH > tempX + x)
				{
					_DrawText(tempX + x, tempSmallFish[idx].pos.y, (char[]) { g_SmallFishGraphic[x], 0 });
				}
			}
		}
	}
}

void InitSmallFish()
{
	// 작은 물고기 공통된 속성 설정
	g_SmallFishMon = (Monster)
	{
		.alive = true,		// 생존 여부
		.hp = 1,
		.lastHitTime = 0,
		.speed = 1.5,
	};

	// 감옥
	g_SmallFishList[E_Jail][g_SmallFishListIdx[E_Jail]++] = (SmallFish)
	{
		.pos.x = 450,	// X 좌표
		.pos.y = 18,	// Y 좌표
		.attack = SMALLFISH_ATTACK,	// 공격력
	};

	// 용궁
	g_SmallFishList[E_DragonPalace][g_SmallFishListIdx[E_DragonPalace]++] = (SmallFish)
	{
		.pos.x = 360,
		.pos.y = 23,
		.attack = SMALLFISH_ATTACK,
	};

	g_SmallFishList[E_DragonPalace][g_SmallFishListIdx[E_DragonPalace]++] = (SmallFish)
	{
		.pos.x = 445,
		.pos.y = 7,
		.attack = SMALLFISH_ATTACK,
	};

	// 바다1
	g_SmallFishList[E_Sea1][g_SmallFishListIdx[E_Sea1]++] = (SmallFish)
	{
		.pos.x = 310,
		.pos.y = 14,
		.attack = SMALLFISH_ATTACK,
	};
	
	g_SmallFishList[E_Sea1][g_SmallFishListIdx[E_Sea1]++] = (SmallFish)
	{
		.pos.x = 600,
		.pos.y = 23,
		.attack = SMALLFISH_ATTACK,
	};

	// 바다2
	g_SmallFishList[E_Sea2][g_SmallFishListIdx[E_Sea2]++] = (SmallFish)
	{
		.pos.x = 233,
		.pos.y = 12,
		.attack = SMALLFISH_ATTACK,
	};

	g_SmallFishList[E_Sea2][g_SmallFishListIdx[E_Sea2]++] = (SmallFish)
	{
		.pos.x = 413,
		.pos.y = 13,
		.attack = SMALLFISH_ATTACK,
	};

	g_SmallFishList[E_Sea2][g_SmallFishListIdx[E_Sea2]++] = (SmallFish)
	{
		.pos.x = 570,
		.pos.y = 15,
		.attack = SMALLFISH_ATTACK,
	};
}