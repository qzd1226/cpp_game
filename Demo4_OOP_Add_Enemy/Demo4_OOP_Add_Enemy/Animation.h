#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <graphics.h>
#include <tchar.h> // For TCHAR and _stprintf_s


class Anim
{
public:
    std::vector<IMAGE*> frame_list;
    int frame_num;
public:
    Anim(LPCTSTR path, int frame_num);
    ~Anim();

};

class Animation {
public:
    Animation() = default; // default constructor
    int timer = 1; // Animation timer
    int idx_frame = 0; // Animation frame index
    int interval_ms = 0; // Interval between frames in milliseconds
    // Constructor
    Animation(Anim* anim, int frame_num, int interval);

    // Destructor
    ~Animation();

    // Play animation
    void Play(int x, int y, int delta);

    // Draw image
    static void putimage_alpha(int x, int y, IMAGE* img);

private:
    Anim* enemy_anim;
};

#endif // ANIMATION_H
