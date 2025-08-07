#include "map.h"
#include "Rabbit.h"
// ===============================================================

bool MapSetting = false;	// ������ ���ÿ��� ����

// �� ������, ���� ���� ���� ��������
bool GetMapSetting()
{
    return MapSetting;
}

// �� ������, ���� ���� ���� �����ϱ�
void SetMapSetting(bool src)
{
    MapSetting = src;
}

void FMapSetting() {
    for (int i = 0; i < numItem; i++)
    {
        // ���� ���������� ���� ������ ���̰� �ϱ�
        if (itemList[i].mapStatus == GetMapStatus()) {
            itemList[i].isHeld = false;
        }
        else {
            itemList[i].isHeld = true;
        }
    }
    for (int i = 0; i < numMonster; i++)
    {
        // ���� ���������� ���� ���� ���̰� �ϱ�
        if (monsterList[i].mapStatus == GetMapStatus()) {
            monsterList[i].alive = true;
        }
        else {
            monsterList[i].alive = false;
        }
    }
    // �������� ������ ���� �Ϸ�
    SetMapSetting(true);
}


// ===============================================================

void Draw() // ȭ�� �׸���
{
    // ���� ���� ��
    if (!GetGameStart()) {
        GameStartScreen();  // ���ӽ��� ȭ�� ���
        // ���� ����Ʈ ȿ��
        if (GetGameStartText()) 
            _DrawText(23, 21, "�ƹ� Ű�� ���� ���� �����ϱ�");
        else 
            _DrawText(21, 21, "                               ");
    }
    // ���� ���� ��
    else {
        // ���ӿ������� ��
        if (IsGameOver)
        {
            GameOverScreen();   // ���ӿ��� ȭ�� ���
            // ���� ����Ʈ ȿ��
            if (GameOverText)
                _DrawText(14, 21, "�ƹ� Ű�� ���� ����ȭ������ ���ư���");
            else
                _DrawText(14, 21, "                                     ");
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
                DrawMapBG(); // �� Ʋ �׸���
                _DrawText(3, 3, player.HeldWeapon->sprite); // ���� �׸��׸���
                DrawHealth();   // ü�¹� �׸���


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
    UpdateSpeedBuffs(); // �ӵ� ���� ���ӽð� üũ �� ���� ó��
    

    UpdateMonster();

    HitPlayer();

}

// Ű �Է�
void Input()
{
    g_Key = _GetKey();
}

void main()
{
    // init
    _BeginWindow();

    SetConsoleTitle("���Ż��");

    InitMonster();  // ���� �ʱ�ȭ
    InitItem();  // ������ �ʱ�ȭ
    InitWeapon(weaponList); // ���� �ʱ�ȭ
    InitPlayer();
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


        if (IsGameOver)
        {
            ReturnStartScreen();    // ���ӿ��� ȭ�� ���
            main(); // ���� ��ȣ��

        }
    }


    _EndWindow();
}