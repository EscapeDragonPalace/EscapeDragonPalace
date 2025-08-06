#include "init.h"
#include "weapon.h"


int selectedIndex = 0;   // ���� ���� ���� ���� �ε���
bool weaponChosen = false;  // Enter�� �����ߴ��� ����


// ����迭 �ʱ�ȭ
void InitWeapon(Weapon* weapons) {

    // �ε��� 0��
    strcpy(weapons[0].name, "���");
    strcpy(weapons[0].sprite, "--|====>");
    weapons[0].attack = 2;
    weapons[0].attackSpeed = 2;

    // �ε��� 1��
    strcpy(weapons[1].name, "�ܰ�");
    strcpy(weapons[1].sprite, "-|=>");
    weapons[1].attack = 1;
    weapons[1].attackSpeed = 3;

    // �ε��� 2��
    strcpy(weapons[2].name, "â");
    strcpy(weapons[2].sprite, "------>");
    weapons[2].attack = 3;
    weapons[2].attackSpeed = 1;

}

// �������
void DrawWeapon(const Weapon* w, int i, int isSelected) {
    int baseX = 5 + (i * 28);

    if (isSelected)
        _SetColor(14); // ����� (���õ� ����)
    else
        _SetColor(7); // ��� (�⺻)

    _DrawText(baseX, 10, "����: ");
    _DrawText(baseX + 6, 10, w->name);


    sprintf(buffer, "���ݷ�: %d", w->attack);
    _DrawText(baseX, 11, buffer);

    sprintf(buffer, "���ݼӵ�: %d", w->attackSpeed);
    _DrawText(baseX, 12, buffer);

    _DrawText(baseX, 13, "����: ");
    _DrawText(baseX + 6, 13, w->sprite);

    _SetColor(7); // ���� �ʱ�ȭ
}

// ���� ���� �Լ�
void SelectWeapon() {

    // ���� ���� ������ ��
    while (!weaponChosen)
    {
        // Ű �Է� �ޱ�
        if (_kbhit()) {
            char key = _getch();

            if (key == 'a' || key == 'A') {
                selectedIndex = (selectedIndex - 1 + NUMWEAPON) % NUMWEAPON;
            }
            else if (key == 'd' || key == 'D') {
                selectedIndex = (selectedIndex + 1) % NUMWEAPON;
            }
            else if (key == '\r') { // Enter Ű (����)
                weaponChosen = true; // ���� ���� �� true�� ����
            }
        }

        _Invalidate();
    }
}

// ���� ���� ���� ��������
bool GetWeaponChosen()
{
    return weaponChosen;
}

// ���� ���� ���� ����
void SetWeaponChosen(bool src)
{
    weaponChosen = src;
}

// ���� �������� ���� �ε��� ��������
int GetSelectedIndex()
{
    return selectedIndex;
}
