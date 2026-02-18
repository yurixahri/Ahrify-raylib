#pragma once

#include "raylib.h"
#include "colors/colors.h"

Texture2D myImage;

struct MainScreen {
    RenderTexture2D canvas;

    void Init(int width, int height) {
        canvas = LoadRenderTexture(width, height);
        myImage = LoadTexture("C:/Users/Administrator/Pictures/niko_dream.jpg");
    }

    void Unload() {
        UnloadRenderTexture(canvas);
    }

    void Draw(Theme* theme) {
        Vector2 mouse_pos = GetMousePosition();
        float canvas_w = (float)canvas.texture.width;
        float canvas_h = (float)canvas.texture.height;
        Rectangle left_panel = { 0, 0, canvas_w / 2, canvas_h };
        Rectangle right_panel = { canvas_w / 2, 0, canvas_w / 2, canvas_h };
        Color bg = current_theme.background;
        bg.a = 150;
        
        BeginTextureMode(canvas);
            DrawRectangleRec(left_panel, bg);
            DrawText("LEFT SIDE", left_panel.x + 20, 20, 20, current_theme.text);

            // Draw Right Panel
            DrawRectangleRec(right_panel, bg);
            DrawText("RIGHT SIDE", right_panel.x + 20, 20, 20, current_theme.text);
            // Add more UI elements here
        EndTextureMode();
    }
};