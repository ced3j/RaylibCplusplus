#include <iostream>
#include <raylib.h>

using namespace std;


// Score
int player_score = 0;
int cpu_score = 0;



class Ball{
public:
        float x, y;
        int speedX;
        int speedY;
        int radius;

        void Draw(){
            DrawCircle(x, y, radius, WHITE);
        }

        void Update(){
            x += speedX;
            y += speedY;

            if(y + radius >= GetScreenHeight() || y - radius <= 0){
                speedY *= -1;
            }

            if(x + radius >= GetScreenWidth()){
                cpu_score++;
                ResetBall();
            }
            if(x - radius <= 0){
                player_score++;
                ResetBall();
            }
        }
        void ResetBall(){
            x = GetScreenWidth()/2;
            y = GetScreenHeight()/2;

            int speed_choices[2] = {-1, 1};
            speedX *= speed_choices[GetRandomValue(0,1)];
            speedY *= speed_choices[GetRandomValue(0,1)];
        }
};



class Paddle{
protected:
    void LimitMovement(){
        if(y <= 0){
            y = 0;
        }
        if(y + height >= GetScreenHeight()){
            y = GetScreenHeight() - height;
        }
    }
public:
    float x, y;
    float width, height;
    int speed;

    void Draw(){
        DrawRectangle(x, y, width, height, WHITE);
    }

    void Update(){
        if(IsKeyDown(KEY_UP)){
            y = y - speed;
        }

        if(IsKeyDown(KEY_DOWN)){
            y = y + speed;
        }

        LimitMovement();
    }

};



// We're going to create a CpuPaddle class that inherits from the Paddle class
class CpuPaddle: public Paddle{
public:
    void Update(int ball_y){

        if(y + height/2 > ball_y){
            y = y - speed;
        }

        if(y + height/2 <= ball_y){
            y = y + speed;
        }

        LimitMovement();
    }
};



Ball ball;
Paddle player;
CpuPaddle cpu;



int main () {
    const int screen_width = 1200;
    const int screen_height = 500;
    cout << "Start " << endl;


    // Initialize Ball object
    ball.radius = 20;
    ball.x = screen_width/2;
    ball.y = screen_height/2;
    ball.speedX = 6;
    ball.speedY = 6;


    // player
    player.width = 25;
    player.height = 125;
    player.x = screen_width - player.width - 10;
    player.y = screen_height/2 - player.height/2;
    player.speed = 6;


    // cpu
    cpu.height = 120;
    cpu.width = 25;
    cpu.x = 10;
    cpu.y = screen_height/2 - cpu.height/2;
    cpu.speed = 6;



    InitWindow(screen_width, screen_height, "Pong Game");
    SetTargetFPS(60);



    while(WindowShouldClose() == false){
        BeginDrawing();

        // Updating

        ball.Update();
        player.Update();
        cpu.Update(ball.y);

        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height})){
            ball.speedX *= -1;
        }

        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height})){
            ball.speedX *= -1;
        }


        // Drawing----------
        ClearBackground(BLACK);// We are clearing the background every tour
        // Drawing a line
        DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);

        ball.Draw();
        player.Draw();
        cpu.Draw();

        DrawText(TextFormat("%i", cpu_score), screen_width/4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", player_score), 3*screen_width/4 - 20, 20, 80, WHITE);


        EndDrawing();
    }


    CloseWindow();
    return 0;
}





