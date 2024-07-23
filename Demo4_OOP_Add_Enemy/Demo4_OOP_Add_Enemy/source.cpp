#include <graphics.h>
#include <iostream>

#include "Animation.h";
#include "Player.h";

const int PLAYER_SPEED = 5;
const double SQUARE_ROOT2 = sqrt(2);
int main() {

    initgraph(1280, 720);

    bool running = true;

    ExMessage msg;

    IMAGE img_background;
    loadimage(&img_background, _T("twt/img/background.png"));

    IMAGE player_shadow;
    loadimage(&player_shadow, _T("twt/img/shadow_player.png"));

    bool is_move_up = false;
    bool is_move_down = false;
    bool is_move_left = false;
    bool is_move_right = false;

    int pi_dir = 0;

    Animation anim_left_player(_T("twt/img/player_left_%d.png"), 6, 45);
    Animation anim_right_player(_T("twt/img/player_right_%d.png"), 6, 45);
    Animation anim_left_enemy(_T("twt/img/enemy_left_%d.png"), 6, 45);
    Animation anim_right_enemy(_T("twt/img/enemy_right_%d.png"), 6, 45);
    
    Player piMeng("PaiMeng",500,500);
    Player enemy1("enemy1", 100, 100);

    BeginBatchDraw();

    while (running) {

        DWORD start_time = GetTickCount();

        while (peekmessage(&msg)) {

            if (msg.message == WM_KEYDOWN) {

                switch (msg.vkcode) {
                case VK_UP:
                    is_move_up = true;
                    break;
                case VK_DOWN:
                    is_move_down = true;
                    break;
                case VK_LEFT:
                    is_move_left = true;
                    break;
                case VK_RIGHT:
                    is_move_right = true;
                    break;
                }
            }
            else if (msg.message == WM_KEYUP) {

                switch (msg.vkcode) {
                case VK_UP:
                    is_move_up = false;
                    break;
                case VK_DOWN:
                    is_move_down = false;
                    break;
                case VK_LEFT:
                    is_move_left = false;
                    break;
                case VK_RIGHT:
                    is_move_right = false;
                    break;
                }
            }
        }
      
        if (is_move_left) {
            pi_dir = -1;
            if (is_move_up) {
                piMeng.position_x -= PLAYER_SPEED / SQUARE_ROOT2;
                piMeng.position_y -= PLAYER_SPEED / SQUARE_ROOT2;
            }
            else if (is_move_down) {
                piMeng.position_x -= PLAYER_SPEED / SQUARE_ROOT2;
                piMeng.position_y += PLAYER_SPEED / SQUARE_ROOT2;
            }
            else {
                piMeng.position_x -= PLAYER_SPEED;
            }
        }
        else if (is_move_right) {
            pi_dir = 1;
            if (is_move_up) {
                piMeng.position_x += PLAYER_SPEED / SQUARE_ROOT2;
                piMeng.position_y -= PLAYER_SPEED / SQUARE_ROOT2;
            }
            else if (is_move_down) {
                piMeng.position_x += PLAYER_SPEED / SQUARE_ROOT2;
                piMeng.position_y += PLAYER_SPEED / SQUARE_ROOT2;
            }
            else {
                piMeng.position_x += PLAYER_SPEED;
            }
        }
        else {
            if (is_move_up) piMeng.position_y -= PLAYER_SPEED;
            if (is_move_down) piMeng.position_y += PLAYER_SPEED;
        }
        // 记录当前动画帧一共播放了几个游戏帧数
        putimage(0, 0, &img_background);
        piMeng.setShadow(player_shadow);
        piMeng.drawPlayer(1, pi_dir, anim_left_player, anim_right_player);
        piMeng.drawShadow();

        enemy1.setShadow(player_shadow);
        enemy1.drawPlayer(1, enemy1.chase(1, piMeng.position_x, piMeng.position_y) , anim_left_enemy, anim_right_enemy);
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






