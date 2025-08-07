#pragma once

#define NUMWEAPON 3
#define WEAPON_SPRITE_LENGTH  21

typedef struct Weapon {
    char name[30];
    char sprite[WEAPON_SPRITE_LENGTH];
    int attack;    // ���ݷ�
    int attackSpeed;    // ���ݼӵ�
} Weapon;

typedef struct WeaponInstance {
    Weapon* weapon;// ���� ����
    int x, y;      // �� ��ġ
    int isHeld;    // 0: �ٴڿ� ����, 1: �÷��̾ ����
} WeaponInstance;

Weapon weaponList[NUMWEAPON];
char buffer[50];

extern void InitWeapon(Weapon* weapons);
extern void DrawWeapon(const Weapon* w, int i, int isSelected);
extern void SelectWeapon();

int GetSelectedIndex();