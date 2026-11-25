#include <raylib.h>
#include "ball.h"
#include <string>


 
 const Color darkGreen = {20, 160, 133, 255};
 constexpr int screenWidth = 800;
 constexpr int screenHeight = 600;

int player_score = 0;
int cpu_score = 0;


struct platform
{
    int posX;
    int posY;
    int size;
    int width = 15;
    int height = 80;
    int speed = 10;
    void Draw()
    {
       DrawRectangleRounded({posX, posY, width, height}, 1.0f, 16, WHITE);
    }

    void move(KeyboardKey up , KeyboardKey down)
    {
         if (IsKeyDown(down))
        {
            posY += speed;
             if (posY > screenHeight)
            {
                posY = 0;
            }
        }
         if (IsKeyDown(up))
        {
            posY -= speed;
            if (posY + 80 < 0)
            {
                posY = screenHeight;
            }
            
        }
    }

    void pnc(ball b)
    {
         if (b.posX > screenWidth/2 + 100)
        {
             if (b.posY < this->posY)
             {
                 this->posY -= speed;
             }else if (b.posY > this->posY)
             {
                 this->posY += speed;
             }
        }
        
    }
};




int main() 
{
 

    ball myBall(screenWidth/2,screenHeight/2 , 10);
    
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);

    platform p1;
    platform p2;

    p1.posY = screenHeight/2;
    p1.posX = 10;

    p2.posY = screenHeight/2;
    p2.posX = screenWidth-25;
    



    while (!WindowShouldClose())
    {
        // event handling
        
    
        // Update position

        p1.move(KEY_W,KEY_S);
        p2.move(KEY_UP , KEY_DOWN);
        myBall.move();
        //p2.pnc(myBall);
        

        if (CheckCollisionCircleRec(Vector2{myBall.posX,myBall.posY},myBall.r , Rectangle{p1.posX,p1.posY,p1.width,p1.height}))
        {
            myBall.speedX *= -1;
        }

         if (CheckCollisionCircleRec(Vector2{myBall.posX,myBall.posY},myBall.r , Rectangle{p2.posX,p2.posY,p2.width,p2.height}))
        {
            myBall.speedX *= -1;
        }
        
        
        if (myBall.posX + myBall.r >= screenWidth)
        {
            player_score++;
            
        }else if(myBall.posX - myBall.r <= 0){
            cpu_score++;
           
        }
        
        
        // Drawing
        BeginDrawing();
        ClearBackground(GRAY);
        DrawLine(screenWidth/2,0,screenWidth/2,screenHeight, WHITE);
        myBall.Draw();
        p1.Draw();
        p2.Draw();

        
        DrawText( std::to_string(player_score).c_str(), screenWidth/2-20 , 10, 25 , BLACK);
        DrawText( std::to_string(cpu_score).c_str(), screenWidth/2 + 10 , 10, 25 , BLACK);

        EndDrawing();
    }
    
    CloseWindow();
}