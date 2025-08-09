#include "init.h"
#include "item.h"
#include "Rabbit.h"
#include "map.h"
#include "weapon.h"
#include "monster.h"
#include "screens.h"

// ===============================================================

void Draw() // ȭ�� �׸���
{
    // ���� ���� ��
    if (!GetGameStart()) {
        _SetColor(E_White); // ���� �� ����
        GameStartScreen();  // ���ӽ��� ȭ�� ���
        // ���� ����Ʈ ȿ��
        if (GetGameStartText()) 
            _SetColor(E_White); // ���� �� ����
        else 
            _SetColor(E_Gray); // ���� �� ����
        _DrawText(23, 21, "�ƹ� Ű�� ���� ���� �����ϱ�");

    }
    // ���� ���� ��
    else {
        // ���ӿ������� ��
        if (GetIsGameOver())
        {
            _SetColor(E_White); // ���� �� ����
            GameOverScreen();   // ���ӿ��� ȭ�� ���
            // ���� ����Ʈ ȿ��
            if (GetGameOverText())
                _SetColor(E_White); // ���� �� ����
            else
                _SetColor(E_Gray); // ���� �� ����
            _DrawText(14, 21, "�ƹ� Ű�� ���� ����ȭ������ ���ư���");

        }
        // �������� Ŭ����
        else if (StageClear())
        {
            RabbitCAnim();  // �������� Ŭ���� ȭ�� ���
            _Delay(45);
            // ���� �ִ� �� Rabbit.c�� ISOnGoal()�� �Ű��� _ ����
        }
        // �÷��� ���� ��
        else {

            // ���� ���� �� ���� ��
            if (!GetWeaponChosen())
            {
                for (int i = 0; i < NUMWEAPON; i++)
                {
                    int isSelected = (i == GetSelectedIndex()); // ���� �������� ����
                    DrawWeapon(&weaponList[i], i, isSelected);  // ���� ���� ���, �������� ����� �����
                }
            }
            else
            {
                DrawMapBG(); // �� ��� �׸���

                // �������� ������ ������ ������ �� �Ǿ����� ��
                if (!GetMapSetting()) {
                    FMapSetting();
                }
                
                // ������ ���
                DrawItem();
                _SetColor(E_White); // ������ �� ���� �ʱ�ȭ


                // ���� ���  
                DrawMonster();
                _SetColor(E_White); // ���� �� ���� �ʱ�ȭ

                // �÷��̾� �ֺ��� �������� ���� �� �˸����� ���
                if (IsNearItem())
                {
                    _DrawText(player.Pos.x, player.Pos.y - 3.f, "e�� ���� ������ �Ա�");
                }
            }

            // �÷��̾� ���
            DrawPlayer();
            _SetColor(E_White);

            _DrawText(3, 3, player.HeldWeapon->sprite); // ���� �׸��׸���
            DrawHealth();   // ü�¹� �׸���
            DrawBuffNDebuff();

            // �� Ʋ �׸���
            DrawMap();
        }
    }
}
// ===========================================================

// ������Ʈ ����
void Update()
{
    UpdateMapPos();
    
    UpdatePlayer();

	SetIsNearItem(false); // �÷��̾ ������ ��ó�� �ִ��� ���� �ʱ�ȭ

    CheckItemPickup();  // ������ �Ծ����� üũ
    UpdateBuffs(); // �ӵ� ���� ���ӽð� üũ �� ���� ó��
    

    UpdateMonster();

    //HitPlayer();  // �÷��̾� �ǰ� ó�� �Լ�

}

// Ű �Է�
void Input()
{
    g_Key = _GetKey();
}

void main()
{
    // �ʱ�ȭ
    _BeginWindow();
    InitMonster();  // ���� �ʱ�ȭ
    InitWeapon(weaponList); // ���� �ʱ�ȭ
    InitItem();  // ������ �ʱ�ȭ
    while(true)
    {
        InitPlayer();

        SetConsoleTitle("���Ż��");

        DrawStartScreen();  // ����ȭ�� �۵� �Լ� ���
        SelectWeapon(); // ���� ����
        player.HeldWeapon = &weaponList[GetSelectedIndex()];    // �÷��̾� ���� ����

        //����
        while (true)
        {
            GetInput();
            ItemFrameDelay();   // ������ ��� ȿ��
            Input(); // Ű �Է�

            Update(); // ������Ʈ

            _Invalidate(); // ȭ�� �׸��� (Draw() �Լ� �ڵ� ����)
            _Delay(30);


            if (GetIsGameOver())
            {
                system("cls"); // ȭ�� �����

                ReturnStartScreen();    // ���ӿ��� ȭ�� ���
                break;
            }
        }


        _EndWindow();
    }
}