#pragma once

void GameStartScreen();
void GameOverScreen();
void DrawStartScreen();
void ReturnStartScreen();
bool GetGameStart(); // ���� ���� ���� �������� �Լ�
bool GetGameStartText();

static bool IsGameOver = false; // ���� ���� ����
static bool GameOverText = true;
