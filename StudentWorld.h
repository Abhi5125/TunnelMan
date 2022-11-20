//#ifndef STUDENTWORLD_H_
//#define STUDENTWORLD_H_
//
//#include "GameWorld.h"
//#include "GameConstants.h"
//#include <string>
//#include "Actor.h"
//#include <vector>
//#include <stdlib.h>
//#include <time.h>
//#include <cmath>
//// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
//
//class GameObject;
//class TunnelMan;
//class Boulder;
//class Protester;
//class StudentWorld : public GameWorld
//{
//public:
//    StudentWorld(std::string assetDir)
//    : GameWorld(assetDir)
//    {
//    }
//    virtual ~StudentWorld();
//
//    virtual int init();
//
//    virtual int move();
//
//    GameObject* setEarth(int x, int y);
//
//    void insertObject(GameObject* actor);
//
//    bool hasBoulder(int x,int y);
//
//    virtual void cleanUp();
//
//    bool hasEarth(int x, int y);
//
//    void checkCollision();
//
//    std::string formatText(int level, int lives, int health, int squirts, int gold, int barrelsLeft, int sonar, int score);
//
//    void setDisplayText();
//
//    void animateSquirt(GameObject* ptr);
//
//    bool withinSix(int x, int y);
//
//    bool boulderNearSquirtOrPlayer(int x, int y);
//
//    bool playerWithinFour(int x, int y);
//
//    bool playerWithinThree(int x, int y);
//
//    int barrelsLeft();
//
//    void gotGold();
//
//    void gotSonar();
//
//    void gotWater();
//
//    bool earthlessFourByFour(int x, int y);
//
//    void useSonar();
//
//    void regProtesterAnnoy();
//
//    int getPlayerX();
//
//    int getPlayerY();
//
//    int getProtesters();
//
//    bool hasWaterPool(int x, int y);
//
//    bool didBribe(int x, int y);
//
//private:
//    GameObject* earth[64][60]; //2d array to keep track of earth objects, since there is earth from x = 0 to x = 63 and earth from y = 0 to y = 59
//    std::vector <GameObject*> actors; //vector to keep track of actor objects
//    TunnelMan* TM; //pointer to tunnel man object
//    int m_ticks;//ticks that have gone by
//    int numBarrels; //number of oil barrels
//};
//
//#endif // STUDENTWORLD_H_
#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include <string>
#include "Actor.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cmath>
// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class GameObject;
class TunnelMan;
class Boulder;
class Protester;
class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetDir)
    : GameWorld(assetDir)
    {
    }
    virtual ~StudentWorld();
    
    virtual int init();
    
    virtual int move();
    
    GameObject* setEarth(int x, int y);
    
    void insertObject(GameObject* actor);
    
    bool hasBoulder(int x,int y);
    
    virtual void cleanUp();
    
    bool hasEarth(int x, int y);
    
    void checkCollision();
    
    std::string formatText(int level, int lives, int health, int squirts, int gold, int barrelsLeft, int sonar, int score);
    
    void setDisplayText();
    
    void animateSquirt(GameObject* ptr);
    
    bool withinSix(int x, int y);
    
    bool boulderNearSquirtOrPlayer(int x, int y);
    
    bool playerWithinFour(int x, int y);
    
    bool playerWithinThree(int x, int y);
    
    int barrelsLeft();
    
    void gotGold();
    
    void gotSonar();
    
    void gotWater();
    
    bool earthlessFourByFour(int x, int y);
    
    void useSonar();
    
    void regProtesterAnnoy();
    
    int getPlayerX();
    
    int getPlayerY();
    
    int getProtesters();
    
    bool hasWaterPool(int x, int y);
    
    bool didBribe(int x, int y);
    
private:
    GameObject* earth[64][60]; //2d array to keep track of earth objects, since there is earth from x = 0 to x = 63 and earth from y = 0 to y = 59
    std::vector <GameObject*> actors; //vector to keep track of actor objects
    TunnelMan* TM; //pointer to tunnel man object
    int m_ticks;//ticks that have gone by
    int numBarrels; //number of oil barrels
};

#endif // STUDENTWORLD_H_
