#include "init.h"
#include "crab.h"

Monster g_CrabMon;	// 꽃게 몬스터 구조체 공통 설정
Skill g_CrabSkill;	// 꽃게 스킬 구조체 공통 설정
Crab g_CrabList[STAGE_CNT][CRAB_CNT];	// 꽃게 포인트 배열
int g_CrabListIdx[STAGE_CNT - 1] = { 0, };	// 보스맵 제외

// 꽃게 업데이트
void UpdateCrab(unsigned long now)
{
	// 현재 맵의 몬스터 데이터 불러오기
	Crab* tempCrab = g_CrabList[GetMapStatus()];

	// 현재 맵에 있는 몬스터 수만큼 반복하기
	for (int idx = 0; idx < g_CrabListIdx[GetMapStatus()]; idx++)
	{
		// 몬스터가 죽었을 경우 넘어가기
		if (!tempCrab[idx].mon.alive) continue;

		// 무적시간 지나면 피격 상태 해제
		if (tempCrab[idx].isDamaged && now - tempCrab[idx].mon.lastHitTime >= INVINCIBLE_TIME)
		{
			tempCrab[idx].isDamaged = false;
		}

		// 몬스터 이동
		tempCrab[idx].pos.x += (tempCrab[idx].dir == E_Right) ? 1 : -1;

		// 정해진 범위 안에서 이동
		if (tempCrab[idx].pos.x <= tempCrab[idx].startPosX)
		{
			tempCrab[idx].dir = E_Right;
		}
		else if (tempCrab[idx].pos.x + CRAB_WIDTH >= tempCrab[idx].startPosX + tempCrab[idx].moveNum)
		{
			tempCrab[idx].dir = E_Left;
		}
	}
}
// 꽃게 공격 체크, 공격 애니메이션 처리
void CheckAttacking()
{
	for (int i = 0; i < g_CrabListIdx[GetMapStatus()]; i++)
	{
		// 죽은 몬스터일 경우 넘어가기
		if (!g_CrabList[GetMapStatus()][i].mon.alive) continue;
	}
}

// 꽃게 피격 처리

// 꽃게 그리기
void DrawCrab()
{
	// 현재 맵 데이터 임시로 불러오기
	Crab* tempCrab = g_CrabList[GetMapStatus()];
	for (int idx = 0; idx < g_CrabListIdx[GetMapStatus()]; idx++)
	{
		// 피격 시 노란색, 평시 빨간색
		_SetColor(g_CrabList[GetMapStatus()][idx].isDamaged ? E_Yellow : E_BrightRed);

		int posX = tempCrab[idx].pos.x - GetPlusX();
		for (int y = 0; y < CRAB_HEIGHT; y++)
		{
			for (int x = 0; x < CRAB_WIDTH; x++)
			{
				if (g_CrabGraphic[tempCrab[idx].dir][y][x] != ' ')
				{
					// 화면 범위 내에 있을 경우 그리기
					if (0 <= posX + x && SCREEN_WIDTH > posX + x)
					{
						_DrawText(posX + x, tempCrab[idx].pos.y + y, 
							(char[]) { g_CrabGraphic[tempCrab[idx].dir][y][x], 0 });
					}
				}
			}
		}
	}
}

// 꽃게 초기화
void InitCrab()
{
	// 꽃게 공통된 속성 설정
	g_CrabMon = (Monster)
	{
		.alive = true,		// 생존 여부
		.hp = 5,			// 체력
		.lastHitTime = 0,	// 마지막 피격 시간
		.speed = 1.5,		// 이동 속도
	};
	g_CrabSkill = (Skill)
	{
		.isAttack = false,	// 스킬 사용 여부
		.attack = 1,		// 공격력 (반 칸)
		.attackCnt = 3,		// 공격 횟수
		.coolTime = 4000,	// 쿨타임 (2초)
	};

	// 감옥
	g_CrabList[E_Jail][g_CrabListIdx[E_Jail]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 100,		// X 좌표
		.pos.y = 21,		// Y 좌표
		.startPosX = 100,	// 초기 X 좌표
		.moveNum = 30,		// 이동 범위
		.isDamaged = false,	// 피격 상태 (무적 여부)
		.dir = E_Right,
	};

	g_CrabList[E_Jail][g_CrabListIdx[E_Jail]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 170,
		.pos.y = 21,
		.startPosX = 170,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Jail][g_CrabListIdx[E_Jail]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 285,
		.pos.y = 21,
		.startPosX = 285,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	// 용궁
	g_CrabList[E_DragonPalace][g_CrabListIdx[E_Jail]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 70,
		.pos.y = 21,
		.startPosX = 70,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_DragonPalace][g_CrabListIdx[E_DragonPalace]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 170,
		.pos.y = 21,
		.startPosX = 170,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_DragonPalace][g_CrabListIdx[E_DragonPalace]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 280,
		.pos.y = 21,
		.startPosX = 280,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_DragonPalace][g_CrabListIdx[E_DragonPalace]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 440,
		.pos.y = 21,
		.startPosX = 440,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	// 바다1
	g_CrabList[E_Sea1][g_CrabListIdx[E_Sea1]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 120,
		.pos.y = 13,
		.startPosX = 120,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea1][g_CrabListIdx[E_Sea1]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 190,
		.pos.y = 21,
		.startPosX = 190,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea1][g_CrabListIdx[E_Sea1]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 400,
		.pos.y = 21,
		.startPosX = 400,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea1][g_CrabListIdx[E_Sea1]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 575,
		.pos.y = 17,
		.startPosX = 575,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea1][g_CrabListIdx[E_Sea1]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 580,
		.pos.y = 7,
		.startPosX = 580,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	// 바다2
	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 95,
		.pos.y = 10,
		.startPosX = 95,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 150,
		.pos.y = 21,
		.startPosX = 150,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 410,
		.pos.y = 21,
		.startPosX = 410,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 500,
		.pos.y = 21,
		.startPosX = 500,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};

	g_CrabList[E_Sea2][g_CrabListIdx[E_Sea2]++] = (Crab)
	{
		.mon = g_CrabMon,
		.skill = g_CrabSkill,
		.pos.x = 610,
		.pos.y = 21,
		.startPosX = 610,
		.moveNum = 30,
		.isDamaged = false,
		.dir = E_Right,
	};
}