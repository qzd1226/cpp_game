#include <graphics.h>
#include <iostream>
#include <random>

#include "Animation.h";
#include "Player.h";
#include "Enemy.h";

const int PLAYER_SPEED = 8;
const double SQUARE_ROOT2 = sqrt(2);
int BACKGROUND_WIDTH = 0;
int BACKGROUND_HEIGHT = 0;

void TryGenerateEnemy(std::vector<Enemy*>& enemy_list, IMAGE enemy_image, IMAGE enemy_shadow, Anim* enemy_anim_left, Anim* enemy_anim_right) {
    const int INTERVAL = 100;
    static int counter = 0;

    // random number
    std::random_device rd;  // random seed
    std::mt19937 gen(rd()); //
    std::uniform_int_distribution<> dis(1, 4);
    int random_speed = dis(gen);
    if ((++counter) % INTERVAL == 0) {
        Enemy* new_enemy = new Enemy("pig", 150, 150, random_speed, enemy_image, enemy_shadow, enemy_anim_left, enemy_anim_right);
        new_enemy->Spawn(BACKGROUND_WIDTH, BACKGROUND_HEIGHT);
        enemy_list.push_back(new_enemy);
    }
}
int main() {

    initgraph(1280, 720);

    bool running = true;

    ExMessage msg;

    IMAGE img_background;
    loadimage(&img_background, _T("twt/img/background.png"));

    BACKGROUND_WIDTH = img_background.getwidth();
    BACKGROUND_HEIGHT = img_background.getheight();

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

    //Anim::set_animation(LPCTSTR path, int frame_num)
    
    Anim player_anim_left(_T("twt/img/player_left_%d.png"), 6);
    Anim player_anim_right(_T("twt/img/player_right_%d.png"), 6);

    Player piMeng("PaiMeng", 500, 500, 7, player_image, player_shadow, &player_anim_left, &player_anim_right);

    Anim enemy_anim_left(_T("twt/img/enemy_left_%d.png"), 6);
    Anim enemy_anim_right(_T("twt/img/enemy_right_%d.png"), 6);

    
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

        TryGenerateEnemy(enemy_list, enemy_image, enemy_shadow, &enemy_anim_left, &enemy_anim_right);
        for (auto it = enemy_list.begin(); it != enemy_list.end();) {
            Enemy* enemy = *it;
            enemy->Chase(piMeng);
            enemy->Draw(5);
            for (Bullet* bullet : piMeng.bullet_list) {
                if (enemy->CheckBullectCollision(*bullet)) {
                    it = enemy_list.erase(it);
                    delete enemy;
                    break;
                }
                else {
                    ++it;
                }
            }
        }
       
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






