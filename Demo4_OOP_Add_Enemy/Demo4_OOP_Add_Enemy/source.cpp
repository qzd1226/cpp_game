#include <graphics.h>
#include <iostream>
#include <random>

#include "Animation.h";
#include "Player.h";
#include "Enemy.h";

const int PLAYER_SPEED = 8;
const double SQUARE_ROOT2 = sqrt(2);

void TryGenerateEnemy(std::vector<Enemy*>& enemy_list, IMAGE enemy_image, IMAGE enemy_shadow ) {
    const int INTERVAL = 100;
    static int counter = 0;

    // random number
    std::random_device rd;  // random seed
    std::mt19937 gen(rd()); //
    std::uniform_int_distribution<> dis(1, 4);
    int random_speed = dis(gen);
    if ((++counter) % INTERVAL == 0)
        enemy_list.push_back(new Enemy("pig", 150, 150, random_speed, enemy_image, enemy_shadow));
}
int main() {

    initgraph(1280, 720);

    bool running = true;

    ExMessage msg;

    IMAGE img_background;
    loadimage(&img_background, _T("twt/img/background.png"));

    IMAGE player_shadow;
    loadimage(&player_shadow, _T("twt/img/shadow_player.png"));
    IMAGE player_image;
    loadimage(&player_image, _T("twt/img/player_left_0.png"));

    IMAGE enemy_shadow;
    loadimage(&enemy_shadow, _T("twt/img/shadow_enemy.png"));
    IMAGE enemy_image;
    loadimage(&enemy_image, _T("twt/img/enemy_left_0.png"));

    bool is_move_up = false;
    bool is_move_down = false;
    bool is_move_left = false;
    bool is_move_right = false;    

    Player piMeng("PaiMeng", 500, 500, 7, player_image, player_shadow);
    Enemy enemy1("pig1", 150, 150, 10, enemy_image, enemy_shadow);
    Enemy enemy2("pig2", 250, 250, 5, enemy_image, enemy_shadow);
    Enemy enemy3("pig3", 350, 350, 1, enemy_image, enemy_shadow);
    
    std::vector<Enemy*> enemy_list;
    BeginBatchDraw();

    while (running) {

        DWORD start_time = GetTickCount();
        putimage(0, 0, &img_background);

        while (peekmessage(&msg)) {
            if (msg.message == WM_KEYDOWN) {

                switch (msg.vkcode) {
                case VK_UP:
                    piMeng.is_move_up = true;
                    break;
                case VK_DOWN:
                    piMeng.is_move_down = true;
                    break;
                case VK_LEFT:
                    piMeng.is_move_left = true;
                    break;
                case VK_RIGHT:
                    piMeng.is_move_right = true;
                    break;
                }
            }
            else if (msg.message == WM_KEYUP) {

                switch (msg.vkcode) {
                case VK_UP:
                    piMeng.is_move_up = false;
                    break;
                case VK_DOWN:
                    piMeng.is_move_down = false;
                    break;
                case VK_LEFT:
                    piMeng.is_move_left = false;
                    break;
                case VK_RIGHT:
                    piMeng.is_move_right = false;
                    break;
                }
            }
        }
        piMeng.ProcessEvent(msg);
        piMeng.Draw(5);

        TryGenerateEnemy(enemy_list, enemy_image, enemy_shadow);
        for (Enemy* enemy : enemy_list)
            enemy->Chase(piMeng);
        //enemy1.Chase(piMeng);
        //enemy2.Chase(piMeng);
        //enemy3.Chase(piMeng);
        
        for (Enemy* enemy : enemy_list)
            enemy->Draw(5);
        //enemy1.Draw(3);
        //enemy2.Draw(3);
        //enemy3.Draw(3);

        FlushBatchDraw();

        DWORD end_time = GetTickCount();
        DWORD delta_time = end_time - start_time;
        if (delta_time < 1000 / 144) {
            Sleep(1000 / 144 - delta_time);
        }

    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}






