#include "raylib.h"

int main() {
    //Set screen dimensions
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    int score = 0;

    // initialize screen
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    // Starting position of the ball
    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };


    // Adjust FPS

    SetTargetFPS(60);

    // Game Loop
    while (!WindowShouldClose()) {
        // Movements of the ball
        if (IsKeyDown(KEY_RIGHT) && ballPosition.x < screenWidth - 50) { ballPosition.x += 2.0f; score++; }
        if (IsKeyDown(KEY_LEFT) && ballPosition.x > 50) { ballPosition.x -= 2.0f; score++; }
        if (IsKeyDown(KEY_UP) && ballPosition.y > 50) { ballPosition.y -= 2.0f; score++; } 
        if (IsKeyDown(KEY_DOWN) && ballPosition.y < screenHeight - 50) {ballPosition.y += 2.0f; score++; }

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        DrawText(TextFormat("Score: %i", score), 10, 40, 20, DARKGRAY);
        DrawText("Move the ball with arrow keys", 10, 10, 20, DARKGRAY);
        DrawCircleV(ballPosition, 50, MAROON);
        
        // Obstacle position
        Vector2 obstaclePosition = { screenWidth / 4, screenHeight / 4 };
        float obstacleRadius = 30.0f;

        // Checking the ball hitting the obstacle
        if (CheckCollisionCircles(ballPosition, 50, obstaclePosition, obstacleRadius)) {
            score -= 5; // Decrease score when you crash
        }

        DrawCircleV(obstaclePosition, obstacleRadius, DARKBLUE);



        EndDrawing();
    }

    // Close the window

    CloseWindow();

    return 0;
}

/*

    Vector2 is a data structure defined in the raylib library. This structure represents a two-dimensional (x and y coordinates) vector. That is, it contains two float (decimal) values, and these values ​​are often used to indicate position or direction in two-dimensional charts.


    
    BeginDrawing();
       Starts a new frame drawing cycle. All drawing operations performed after this function is called are included in this frame
       

    ClearBackground(RAYWHITE);
        clears the background with white (RAYWHITE) color. Clearing the background for each new frame prevents any remaining artwork from the previous frame from being overwritten
        

    EndDrawing();
        ends the current frame drawing cycle and updates and displays all drawing operations performed on the screen
*/