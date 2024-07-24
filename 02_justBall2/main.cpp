#include "raylib.h"

int main() {
    // Ekran boyutlarını belirleyin
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    int score = 0;

    // Ekranı başlatın
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    // Topun başlangıç pozisyonu
    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };


    // FPS'i ayarlayın
    SetTargetFPS(60);

    // Oyun döngüsü
    while (!WindowShouldClose()) {
        // Topun hareketi
        if (IsKeyDown(KEY_RIGHT) && ballPosition.x < screenWidth - 50) { ballPosition.x += 2.0f; score++; }
        if (IsKeyDown(KEY_LEFT) && ballPosition.x > 50) { ballPosition.x -= 2.0f; score++; }
        if (IsKeyDown(KEY_UP) && ballPosition.y > 50) { ballPosition.y -= 2.0f; score++; } 
        if (IsKeyDown(KEY_DOWN) && ballPosition.y < screenHeight - 50) {ballPosition.y += 2.0f; score++; }

        // Çizim
        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        DrawText(TextFormat("Score: %i", score), 10, 40, 20, DARKGRAY);
        DrawText("Move the ball with arrow keys", 10, 10, 20, DARKGRAY);
        DrawCircleV(ballPosition, 50, MAROON);
        
        // Engel pozisyonu
        Vector2 obstaclePosition = { screenWidth / 4, screenHeight / 4 };
        float obstacleRadius = 30.0f;

        // Topun engele çarpma kontrolü
        if (CheckCollisionCircles(ballPosition, 50, obstaclePosition, obstacleRadius)) {
            score -= 5; // Çarptığında skoru azalt
        }

        DrawCircleV(obstaclePosition, obstacleRadius, DARKBLUE);



        EndDrawing();
    }

    // Pencereyi kapat
    CloseWindow();

    return 0;
}

/*

    Vector2, raylib kütüphanesinde tanımlı bir veri yapısıdır. Bu yapı, iki boyutlu (x ve y koordinatları) bir vektörü temsil eder. Yani, iki adet float (ondalık sayı) değeri içerir ve bu değerler genellikle iki boyutlu grafiklerde pozisyon veya yön belirtmek için kullanılır.


    
    BeginDrawing();
       yeni bir çerçeve çizim döngüsünü başlatır. Bu fonksiyon çağrıldıktan sonra yapılan tüm çizim işlemleri, bu çerçeveye dahil edilir
       

    ClearBackground(RAYWHITE);
        arka planı beyaz (RAYWHITE) renk ile temizler. Her yeni çerçeve için arka planın temizlenmesi, önceki çerçeveden kalan çizimlerin üzerine yazılmasını engeller
        

    EndDrawing();
        mevcut çerçeve çizim döngüsünü sonlandırır ve ekranda yapılan tüm çizim işlemlerini günceller ve görüntüler

*/