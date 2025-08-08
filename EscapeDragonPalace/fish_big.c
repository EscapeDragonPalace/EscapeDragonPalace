#include "init.h"
#include "fish_big.h"

Monster g_BigFishMon;	// 큰 물고기 몬스터 구조체 공통 설정
BigFish g_BigFishList[STAGE_CNT][BIGFISH_CNT];	// 큰 물고기 포인트 배열
int g_BigFishListIdx = 0;

// 큰 물고기 업데이트
void UpdateBigFish(unsigned long now)
{
	// 현재 맵의 몬스터 데이터 불러오기
	BigFish* tempBigFish = g_BigFishList[GetMapStatus()];
	for(int idx = 0; idx < g_BigFishListIdx; idx++)
	{
		// 피격 시 빨간색, 평시 파란색
		_SetColor(g_BigFishList[GetMapStatus()][g_BigFishListIdx].isDamaged ? E_BrightRed : E_BrightBlue);

		// 몬스터가 죽었을 경우 넘어가기
		if (!tempBigFish[idx].mon.alive) continue;

		// 무적시간 지나면 피격 상태 해제
		if (tempBigFish[idx].isDamaged && now - tempBigFish[idx].mon.lastHitTime >= INVINCIBLE_TIME)
		{
			tempBigFish[idx].isDamaged = false;
		}

		// 몬스터 이동
		tempBigFish[idx].pos.x += (tempBigFish[idx].dir == E_Right) ? 1 : -1;

		// 정해진 범위 안에서 이동
		if (tempBigFish[idx].pos.x <= tempBigFish[idx].startPosX)
		{
			tempBigFish[idx].dir = E_Right;
		}
		else if (tempBigFish[idx].pos.x + BIGFISH_WIDTH >= tempBigFish[idx].startPosX + tempBigFish[idx].moveNum)
		{
			tempBigFish[idx].dir = E_Left;
		}
	}
}

// 큰 물고기 그리기
void DrawBigFish()
{
	// 현재 맵 데이터 임시로 불러오기
	BigFish* tempBigFish = g_BigFishList[GetMapStatus()];
	for (int idx = 0; idx < g_BigFishListIdx; idx++)
	{
		int tempX = tempBigFish[idx].pos.x + GetPlusX();
		for(int y = 0; y < BIGFISH_HEIGHT; y++)
		{
			for (int x = 0; x < BIGFISH_WIDTH; x++)
			{
				if (g_BigFishGraphic[x] != ' ')
				{
					// 화면 범위 내에 있을 경우 그리기
					if (0 <= tempX + x && SCREEN_WIDTH > tempX + x)
					{
						_DrawText(tempX + x, tempBigFish[idx].pos.y + y, (char[]) { g_BigFishGraphic[x], 0 });
					}
				}
			}
		}
	}
}

// 큰 물고기 초기화
void InitBigFish()
{
	// 큰 물고기 공통된 속성 설정
	g_BigFishMon = (Monster)
	{
		.alive = true,		// 생존 여부
		.hp = 4,			// 체력
		.lastHitTime = 0,	// 마지막 피격 시간
		.speed = 1.5,		// 이동 속도
	};

	// 감옥
	g_BigFishList[E_Jail][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 100,		// X 좌표
		.pos.y = 11,		// Y 좌표
		.startPosX = 100,	// 초기 X 좌표
		.attack = BIGFISH_ATTACK,	// 공격력
		.moveNum = 30,		// 이동 범위
		.isDamaged = false,	// 피격 상태 (무적 여부)
		.dir = E_Right,		// 바라보는 방향
	};

	g_BigFishList[E_Jail][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 170,
		.pos.y = 11,
		.startPosX = 170,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Jail][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 300,
		.pos.y = 11,
		.startPosX = 300,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Jail][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 500,
		.pos.y = 12,
		.startPosX = 500,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Jail][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 500,
		.pos.y = 21,
		.startPosX = 500,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	// 용궁
	g_BigFishList[E_DragonPalace][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 70,
		.pos.y = 14,
		.startPosX = 70,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_DragonPalace][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 170,
		.pos.y = 14,
		.startPosX = 170,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_DragonPalace][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 280,
		.pos.y = 11,
		.startPosX = 280,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_DragonPalace][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 520,
		.pos.y = 11,
		.startPosX = 520,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	// 바다1
	g_BigFishList[E_Sea1][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 120,
		.pos.y = 21,
		.startPosX = 120,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Sea1][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 190,
		.pos.y = 12,
		.startPosX = 190,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Sea1][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 300,
		.pos.y = 21,
		.startPosX = 300,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Sea1][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 400,
		.pos.y = 13,
		.startPosX = 400,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Sea1][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 480,
		.pos.y = 21,
		.startPosX = 480,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	// 바다2
	g_BigFishList[E_Sea2][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 260,
		.pos.y = 21,
		.startPosX = 260,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Sea2][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 320,
		.pos.y = 16,
		.startPosX = 320,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_BigFishList[E_Sea2][g_BigFishListIdx++] = (BigFish)
	{
		.pos.x = 410,
		.pos.y = 16,
		.startPosX = 410,
		.attack = BIGFISH_ATTACK,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};
}