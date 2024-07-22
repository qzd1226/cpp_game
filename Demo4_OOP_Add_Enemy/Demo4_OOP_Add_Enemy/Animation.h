#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <graphics.h>
#include <tchar.h> // For TCHAR and _stprintf_s

class Animation {

private:

    // Helper function to draw image with alpha blending
    inline void putimage_alpha(int x, int y, IMAGE* img) {
        int w = img->getwidth();
        int h = img->getheight();
        AlphaBlend(GetImageHDC(NULL), x, y, w, h,
            GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
    }

public:

    int timer = 0; // Animation timer
    int idx_frame = 0; // Animation frame index
    int interval_ms = 0; // Interval between frames in milliseconds
    std::vector<IMAGE*> frame_list; // List of frames
    // Constructor
    Animation(LPCTSTR path, int num, int interval);

    // Destructor
    ~Animation();

    // Play animation
    void Play(int x, int y, int delta);
};

#endif // ANIMATION_H
