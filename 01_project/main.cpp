#include "raylib.h"

int main() {
    // Ekran boyutlarını belirleyin
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Ekranı başlatın
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    // Topun başlangıç pozisyonu
    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };

    // FPS'i ayarlayın
    SetTargetFPS(60);

    // Oyun döngüsü
    while (!WindowShouldClose()) {
        // Topun hareketi
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;

        // Çizim
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Move the ball with arrow keys", 10, 10, 20, DARKGRAY);
        DrawCircleV(ballPosition, 50, MAROON);

        EndDrawing();
    }

    // Pencereyi kapat
    CloseWindow();

    return 0;
}
