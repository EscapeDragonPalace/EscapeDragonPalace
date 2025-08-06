#pragma once

// inlcude
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>
#include "mtg.h" // mtg ���� �ҷ�����

// ��ũ��
#define SCREEN_WIDTH 80 // ȭ�� �ʺ�
#define SCREEN_HEIGHT 25 // ȭ�� ����
#define STR_MAX 256 // ���ڿ� �ִ� ũ��

// ����ü
typedef struct MyPoint
{
    float x;
    float y;
} MyPoint;

// ������
// ����
typedef enum {
    E_RIGHT,
    E_LEFT,
} Direction;

// CMD ����
typedef enum CMDColor
{
	E_Black,
	E_Blue,
	E_Green,
	E_Teal, // û�ϻ�
	E_Red,
	E_Purple,
	E_Yellow,
	E_White,
	E_Gray,
	E_BrightBlue,
	E_BrightGreen,
	E_BrightTeal,
	E_BrightRed,
	E_BrightPurple,
	E_BrightYellow,
	E_BrightWhite,
} CMDColor;

// ���� ����
int g_Key;