#pragma once

void GameStartScreen();
void GameOverScreen();
void DrawStartScreen();
void ReturnStartScreen();
bool GetGameStart(); // ���� ���� ���� �������� �Լ�
bool GetGameStartText();
bool GetIsGameOver();	// ���� ���� ���� ��ȯ
void SetIsGameOver(int src);
bool GetGameOverText();	// ���� ���� �ؽ�Ʈ �׸��� ���� ��ȯ
void SetIsGameOverText(int src);