#include<raylib.h>



class ball
{
private:
   
public:
    int posX;
    int posY;
    int r;
    int speedX = 5;
    int speedY = 5;

    void Draw();
    void setPosX(int x);
    void setPosY(int y);
    void move();
    void reset();
    ball(int x , int y , int r);
};


ball::ball(int x , int y , int r)
{
    this->posX = x;
    this->posY = y;
    this->r = r;
}


void ball::setPosX(int x){
    this->posX = x;
}

void ball::setPosY(int y){
        this->posX = y;
}

void ball::Draw(){
        DrawCircle(this->posX , this->posY , this->r , RED);
}

void ball::reset(){
       this->posX = 600/2;
       this->posY = 800/2;

       
}

void ball::move(){

    this->posX -= speedX;
    this->posY += speedY;

    if ((this->posY - this->r) <= 0 || (this->posY + this->r) >= 600)
    {
            this->speedY *= -1;
    }

    if (this->posX- this->r <= 0 || this->posX+this->r >= 800)
    {
         this->speedX *= -1;
    }
    


}