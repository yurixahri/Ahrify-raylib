#include "raylib.h"
#include "rlgl.h"
#include "colors/colors.h"
#include "draws/helper.h"
#include "screens/mainwindow.h"

Theme current_theme;
MainScreen main_screen;

Texture2D bg_image;

int main() {
    InitWindow(1280, 720, "Ahrify");
    SetTargetFPS(60);
    //LoadTheme(&current_theme);
    main_screen.Init(GetScreenWidth(), GetScreenHeight());
    bg_image = LoadTexture("c:/Users/Administrator/Pictures/bloom.png");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 0.0f, 10.0f }; // Look from 10 units away
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };   // Look at the center
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };       // "Up" is toward the sky
    camera.fovy = 40.0f;                             // Field of view
    camera.projection = CAMERA_PERSPECTIVE;
    float tiltIntensity = 1.0f; 
  
    while (!WindowShouldClose()) {
        main_screen.Draw(&current_theme);
        
        float mouseXRel = (GetMouseX() / (float)GetScreenWidth()) - 0.5f;
        float mouseYRel = (GetMouseY() / (float)GetScreenHeight()) - 0.5f;
        camera.position.x = mouseXRel * tiltIntensity;
        camera.position.y = -mouseYRel * tiltIntensity;
        camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };

        
        BeginDrawing();
            ClearBackground(TRANSPARENT);
            DrawTextureCover(bg_image, (Rectangle){ 0, 0, GetScreenWidth(), GetScreenHeight()});
            BeginMode3D(camera);
            // Draw the texture as a 3D plane
            // We flip the texture height here too!
                DrawCubeTexture(main_screen.canvas.texture, (Vector3){0, 0, 0}, GetScreenWidth()/100, GetScreenHeight()/100, 0.5f, WHITE);
            EndMode3D();
        EndDrawing();
    }

    main_screen.Unload();
    CloseWindow();
    return 0;
}

