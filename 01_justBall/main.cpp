#include <raylib.h>


int main(){
    
    int ballX = 400;
    int ballY = 400;
    int ballRadius = 20;
    int screenWidth = 800;
    int screenHeight = 800;
    
    Color ballColor = {20, 160, 133, 255}; // create color
    
    
    InitWindow(screenWidth, screenHeight, "Game Screen");
    SetTargetFPS(60);
    
    // Game Loop
    while(WindowShouldClose() == false){
        
        // Event Handling
        if(IsKeyDown(KEY_RIGHT) && ballX < (screenWidth - ballRadius)) ballX += 5;
        if(IsKeyDown(KEY_LEFT) && ballX > ballRadius) ballX -= 5;
        if(IsKeyDown(KEY_UP) && ballY > ballRadius) ballY -= 5;
        if(IsKeyDown(KEY_DOWN) && ballY < (screenHeight - ballRadius)) ballY += 5;
        
        
        // Updating Positions


        // Drawing
        BeginDrawing();
        ClearBackground(ballColor);
        DrawCircle(ballX, ballY, ballRadius, WHITE); // x, y, radius, color
        
        EndDrawing();
            
    }
    
    
    
    CloseWindow();
    return 0;
}


/*

Game Parts:
    1- Event Handling
    2- Updating Positions
    3- Drawing Objects

*/