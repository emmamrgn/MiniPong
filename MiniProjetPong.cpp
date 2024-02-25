/* 
PING PONG à 2 joueurs, un joueur a gauche l'autre a droite
*/

#include <iostream>
#include <Grapic.h>
using namespace grapic;
using namespace std;

const int DIMWX = 700;      //largeur fenetre -
const int DIMWY = 550;      //longueur fenetre |

const float raquetteV = 0.55f;     //vitesse de deplacement de la raquette
const int raquetteT=50;

const int balleT = 4;
const float balleV = 0.5f;



struct Vec2
{
    float x,y;
};

Vec2 make_vec2(float x, float y)
{
    Vec2 v;
    v.x = x;
    v.y = y;
    return v;
}

Vec2 operator+(const Vec2& a, const Vec2& b)
{
    Vec2 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}

Vec2 operator+(const Vec2& a, float b)
{
    Vec2 r;
    r.x = a.x + b;
    r.y = a.y + b;
    return r;
}

Vec2 operator-(const Vec2& a, const Vec2& b)
{
    Vec2 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    return r;
}

Vec2 operator+=(Vec2& a, const Vec2& b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vec2 operator*(float a, const Vec2& b)
{
    Vec2 r;
    r.x = a * b.x;
    r.y = a * b.y;
    return r;
}

Vec2 operator*(const Vec2& b, float a)
{
    Vec2 r;
    r.x = a * b.x;
    r.y = a * b.y;
    return r;
}

Vec2 operator/(const Vec2& a, float b)
{
    Vec2 r;
    r.x = a.x / b;
    r.y = a.y / b;
    return r;
}


struct Balle
{
    Vec2 pos;   
    Vec2 v;
};

struct Raquette
{
    Vec2 pos;
};

struct Monde
{
    Raquette r1,r2;
    Balle b;
    int score1,score2;
};


void initRaquette (Monde &m)
{
    m.r1.pos=make_vec2(15,DIMWY/2);
    m.r2.pos=make_vec2(DIMWX-15,DIMWY/2);
}

void initBalle(Monde &m)
{
    m.b.pos=make_vec2(DIMWX/2, DIMWY/2);
    m.b.v=make_vec2(0,0);    
}

void initMonde(Monde &m)
{
    initBalle(m);
    initRaquette(m);
    m.score1=0;
    m.score2=0;
}

void updateRaquette1(Monde &m)         
{
    bool repeat=true;
    setKeyRepeatMode(repeat);

    if(isKeyPressed(SDLK_z) && (m.r1.pos.y<DIMWY-raquetteT))
    {
        m.r1.pos.y= m.r1.pos.y+raquetteV;
    }

     if(isKeyPressed(SDLK_s) && (m.r1.pos.y>raquetteT))
    {
        m.r1.pos.y= m.r1.pos.y-raquetteV;
    }
}

void updateRaquette2(Monde &m)          
{
    bool repeat=true;
    setKeyRepeatMode(repeat);

    if(isKeyPressed(SDLK_UP) && (m.r2.pos.y<DIMWY-raquetteT))
    {
        m.r2.pos.y= m.r2.pos.y+raquetteV;
    }

     if(isKeyPressed(SDLK_DOWN) && (m.r2.pos.y>raquetteT))
    {
        m.r2.pos.y= m.r2.pos.y-raquetteV;
    }
}

void drawRaquette(Raquette r,int taille)
{
    color(255,165,0);
    rectangleFill(r.pos.x-2,r.pos.y-taille,r.pos.x+2,r.pos.y+taille);
}

void drawMonde (Monde m)
{
    color(255,255,255);
    line(DIMWX/2,0,DIMWX/2,DIMWY);   

    //bordure 
    color(170,170,170);
    rectangleFill(DIMWX-DIMWX,0,5,DIMWY);
    rectangleFill(DIMWX-5,0,DIMWX,DIMWY);
    rectangleFill(0,0,DIMWX,5);
    rectangleFill(0,DIMWY-5,DIMWX,DIMWY);
    
    //raquettes
    drawRaquette(m.r1,raquetteT);
    drawRaquette(m.r2,raquetteT);

    //balle
    color(255,10,10);
    rectangleFill(m.b.pos.x-balleT,m.b.pos.y-balleT,m.b.pos.x+balleT,m.b.pos.y+balleT);  
}


void updateJeu(Monde &m)
{

    //raquette gauche
    if((m.b.pos.x>=m.r1.pos.x-2) && (m.b.pos.x<= m.r1.pos.x+2) && (m.b.pos.y>=m.r1.pos.y-raquetteT) && (m.b.pos.y<=m.r1.pos.y+raquetteT))
    {
        m.b.v.x = -m.b.v.x;
        m.b.v=make_vec2(m.b.v.x*1.25,m.b.v.y*1.25);
    }

    if (m.b.pos.x < 0)   //gauche 
    {
        m.b.pos=make_vec2(DIMWX/2, DIMWY/2);
        m.b.v=make_vec2(0,0);
        m.score2 = m.score2+1;
    }

    //raquette droite
    if((m.b.pos.x>=m.r2.pos.x-2) && (m.b.pos.x<=m.r2.pos.x+2) && (m.b.pos.y>=m.r2.pos.y-raquetteT) && (m.b.pos.y<=m.r2.pos.y+raquetteT))
    {
        m.b.v.x= -m.b.v.x;
        m.b.v=make_vec2(m.b.v.x*1.25,m.b.v.y*1.25);
    }

    if(m.b.pos.x > DIMWX)  //droite
    {
        m.b.pos=make_vec2(DIMWX/2, DIMWY/2);
        m.b.v=make_vec2(0,0);
        m.score1 = m.score1+1;
    }

    if (m.b.pos.y < 0)   //bas
    {
        //m.b.pos.y = -m.b.pos.y;
        m.b.v.y = -m.b.v.y;
    }

    if(m.b.pos.y > DIMWY)        //haut
    {
        //m.b.pos.y = DIMWY-(m.b.pos.y-DIMWY);
        m.b.v.y = -m.b.v.y;
    }
}

int random()
{
    int i,booleen;
    for (i=0;i<20;i++)
        {
            booleen=irand(0,1);
        }
    return booleen;
}

void updateBalle(Monde &m)
{
    m.b.pos = m.b.pos + m.b.v*balleV;
    updateJeu(m);
}

void updateMonde(Monde &m)
{
    bool repeat=true;
    setKeyRepeatMode(repeat);

    random();

    if(isKeyPressed(SDLK_SPACE) && (m.b.pos.x==DIMWX/2) && (m.b.pos.y==DIMWY/2))
    {

        float x=frand(-balleV,-0.2);
        float y=frand(0.2,balleV);

        if((m.score1>m.score2) && (random()==1))
        {
            m.b.v = make_vec2(balleV,y);
        }
        if((m.score1>m.score2) && (random()==0))
        {
            m.b.v = make_vec2(balleV,-y);
        }
        if((m.score1<m.score2) && (random()==1))
        {
            m.b.v = make_vec2(-balleV,-y);
        }
        if((m.score1<m.score2) && (random()==0))
        {
            m.b.v = make_vec2(-balleV,y);
        }
        if((m.score1==m.score2) && (random()==1))
        {
            m.b.v.x= x;
            m.b.v.y= y;
        }
        if((m.score1==m.score2) && (random()==0))
        {
            m.b.v.x= -x;
            m.b.v.y= -y;
        }
    }
    
    updateRaquette1(m);
    updateRaquette2(m);
    updateBalle(m);

    color(10,10,10);

    print(50,DIMWY-50,m.score1);
    print(DIMWX-50,DIMWY-50,m.score2);
}

void reset(Monde &m)
{
    if (isKeyPressed(SDLK_p))
    {
        initMonde(m);
    }
}

void infos(Monde &m)
{
    if((m.b.v.x==0) && (m.b.v.y==0) && (m.b.pos.x==DIMWX/2) && (m.b.pos.y==DIMWY/2))
    {
        color(170,170,170);
        fontSize(18);
        print(DIMWX/2+70,50,"SPACE = relancer la balle");
        print(DIMWX/2-225,50,"P = autre partie");
    }
}

int main(int , char** )
{
    bool stop=false;
	winInit("PING-PONG", DIMWX, DIMWY);
    
    backgroundColor(30, 102, 168);
    Monde m;

    initMonde(m);
	while(!stop)
    {
        winClear();

        drawMonde(m);        
        updateMonde(m);
        infos(m);
        reset(m);

        stop = winDisplay();
    }
    winQuit();
	return 0;
}

