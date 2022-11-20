//#ifndef ACTOR_H_
//#define ACTOR_H_
//
//#include "GraphObject.h"
//#include "StudentWorld.h"
//#include <stack>
//#include <queue>
//#include <utility>
//// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
//class StudentWorld;
//class GameObject: public GraphObject {
//public:
//    GameObject(int imageID, int startX, int startY, Direction dir, double size, unsigned int depth, StudentWorld* sw);
//    virtual ~GameObject() {
//    }
//    virtual void doSomething() = 0;
//    virtual StudentWorld* getWorld();
//    virtual bool isAlive() const;
//    virtual void setDead();
//    int getTicks() const;
//    void incTick();
//    void resetTicks();
//    std::string getType() const;
//    void setType(std::string type);
//private:
//    bool m_alive;
//    StudentWorld* m_StudentWorld;
//    int m_ticks;
//    std::string m_type;
//};
//class Earth: public GameObject {
//public:
//    Earth(StudentWorld* sw, int startX, int startY);
//    virtual ~Earth() {
//        setVisible(false);
//    }
//    virtual void doSomething() {
//    }
//private:
//
//};
//class TunnelMan: public GameObject {
//public:
//    TunnelMan(StudentWorld* sw);
//    virtual ~TunnelMan() {
//        setVisible(false);
//    }
//    virtual void doSomething();
//    int getHealth() const;
//    int getSquirts() const;
//    int getSonar() const;
//    int getGold() const;
//    void incGold();
//    void incSonar();
//    void incWater();
//    void decSonar();
//    void decHealth(int x);
//    bool boulderNearby(int x, int y);
//private:
//    int m_hitpoints;
//    int m_water;
//    int m_sonar;
//    int m_gnugget;
//};
//
//class Boulder: public GameObject {
//public:
//    Boulder(StudentWorld* sw, int startX, int startY);
//    virtual ~Boulder() {
//        setVisible(false);
//    }
//    virtual void doSomething();
//private:
//    std::string m_state;
//};
//
//class Squirt: public GameObject {
//public:
//    Squirt(StudentWorld* sw, int startX, int startY, Direction dir);
//    virtual ~Squirt() {
//        setVisible(false);
//    }
//    bool earthNearby(int x, int y);
//    bool boulderNearby(int x, int y);
//    virtual void doSomething();
//private:
//    int initialTravelDistance;
//};
//
//class Barrel: public GameObject {
//public:
//    Barrel(StudentWorld* sw, int startX, int startY);
//    virtual ~Barrel() {
//        setVisible(false);
//    }
//    virtual void doSomething();
//private:
//
//};
//
//class Goodie: public GameObject {
//public:
//    Goodie(StudentWorld* sw, int startX, int startY, bool protesterOrPlayer, bool isPermanent, int imageID);
//    bool getProtesterOrPlayer();
//    bool getPermanent();
//    virtual ~Goodie() = 0;
//private:
//    bool m_permanent;
//    bool m_protesterOrPlayer;
//};
//
//class Gold: public Goodie {
//public:
//    Gold(StudentWorld* sw, int startX, int startY, bool isVisible, bool protesterOrPlayer, bool isPermanent);
//    virtual ~Gold() {
//        setVisible(false);
//    }
//    virtual void doSomething();
//private:
//};
//
//class Sonar: public Goodie {
//public:
//    Sonar(StudentWorld* sw, int startX, int startY, bool protesterOrPlayer, bool isPermanent, int imageID);
//    virtual ~Sonar() {
//        setVisible(false);
//    }
//    virtual void doSomething();
//    int getLifetime() {
//        return m_lifetime;
//    }
//private:
//    int m_lifetime;
//};
//class WaterPool: public Sonar {
//public:
//    WaterPool(StudentWorld* sw, int startX, int startY, int imageID);
//    virtual ~WaterPool() {
//        setVisible(false);
//    }
//    virtual void doSomething();
//private:
//
//};
//class Protester: public GameObject {
//public:
//    Protester(StudentWorld* sw, int startX, int startY, int numSquaresToMoveInCurrentDirection, int ticksToWait, int imageID);
//    virtual ~Protester() {
//        setVisible(false);
//    }
//    virtual void doSomething();
//    void setHP(int x);
//    int getHP();
//    void setRandDir();
//    void setLeaveField();
//    void annoy(int x);
//    bool moveInPerp(Direction &d);
//    bool isValidPos(int x, int y);
//    void BFS(std::stack <Direction> &p, int startX, int startY, int endX, int endY);
//    bool getLeaveField();
//    void decNumSquares();
//    int getNumSquares();
//    void setNumSquares(int x);
//    void setTurnWithinTrue();
//    int getStunnedTicks();
//    int getNonRestingTicks();
//    void incNonRestingTicks();
//    void setShoutedFalse();
//    int getWaitingTicks();
//    void setTurnWithinFalse();
//private:
//    int m_numSquaresToMoveInCurrentDirection;
//    bool m_leaveTheField;
//    int m_ticksToWait;
//    int m_nonRestingTicks;
//    int m_hp;
//    bool shoutedWithin15;
//    bool turnWithin200;
//    int stunnedTicks;
//    std::stack <Direction> path;
//};
//class HardcoreProtester: public Protester {
//public:
//    HardcoreProtester(StudentWorld* sw, int startX, int startY, int numSquaresToMoveInCurrentDirection, int ticksToWait);
//    virtual ~HardcoreProtester() {
//        setVisible(false);
//    }
//    bool DFS(std::stack <Direction> &p, int startX, int startY, int endX, int endY);
//    void setTicksToStare(int x);
//    int getTicksToStare();
//    virtual void doSomething();
//private:
//    int ticksToStare;
//};
//#endif // ACTOR_H_
#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "StudentWorld.h"
#include <stack>
#include <queue>
#include <utility>
// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class StudentWorld;
class GameObject: public GraphObject {
public:
    GameObject(int imageID, int startX, int startY, Direction dir, double size, unsigned int depth, StudentWorld* sw);
    virtual ~GameObject() {
    }
    virtual void doSomething() = 0;
    virtual StudentWorld* getWorld();
    virtual bool isAlive() const;
    virtual void setDead();
    int getTicks() const;
    void incTick();
    void resetTicks();
    std::string getType() const;
    void setType(std::string type);
private:
    bool m_alive;
    StudentWorld* m_StudentWorld;
    int m_ticks;
    std::string m_type;
};
class Earth: public GameObject {
public:
    Earth(StudentWorld* sw, int startX, int startY);
    virtual ~Earth() {
        setVisible(false);
    }
    virtual void doSomething() {
    }
private:
    
};
class TunnelMan: public GameObject {
public:
    TunnelMan(StudentWorld* sw);
    virtual ~TunnelMan() {
        setVisible(false);
    }
    virtual void doSomething();
    int getHealth() const;
    int getSquirts() const;
    int getSonar() const;
    int getGold() const;
    void incGold();
    void incSonar();
    void incWater();
    void decSonar();
    void decHealth(int x);
    bool boulderNearby(int x, int y);
private:
    int m_hitpoints;
    int m_water;
    int m_sonar;
    int m_gnugget;
};

class Boulder: public GameObject {
public:
    Boulder(StudentWorld* sw, int startX, int startY);
    virtual ~Boulder() {
        setVisible(false);
    }
    virtual void doSomething();
private:
    std::string m_state;
};

class Squirt: public GameObject {
public:
    Squirt(StudentWorld* sw, int startX, int startY, Direction dir);
    virtual ~Squirt() {
        setVisible(false);
    }
    bool earthNearby(int x, int y);
    bool boulderNearby(int x, int y);
    virtual void doSomething();
private:
    int initialTravelDistance;
};

class Barrel: public GameObject {
public:
    Barrel(StudentWorld* sw, int startX, int startY);
    virtual ~Barrel() {
        setVisible(false);
    }
    virtual void doSomething();
private:
    
};

class Goodie: public GameObject {
public:
    Goodie(StudentWorld* sw, int startX, int startY, bool protesterOrPlayer, bool isPermanent, int imageID);
    bool getProtesterOrPlayer();
    bool getPermanent();
    virtual ~Goodie() = 0;
private:
    bool m_permanent;
    bool m_protesterOrPlayer;
};

class Gold: public Goodie {
public:
    Gold(StudentWorld* sw, int startX, int startY, bool isVisible, bool protesterOrPlayer, bool isPermanent);
    virtual ~Gold() {
        setVisible(false);
    }
    virtual void doSomething();
private:
};

class Sonar: public Goodie {
public:
    Sonar(StudentWorld* sw, int startX, int startY, bool protesterOrPlayer, bool isPermanent, int imageID);
    virtual ~Sonar() {
        setVisible(false);
    }
    virtual void doSomething();
    int getLifetime() {
        return m_lifetime;
    }
private:
    int m_lifetime;
};
class WaterPool: public Sonar {
public:
    WaterPool(StudentWorld* sw, int startX, int startY, int imageID);
    virtual ~WaterPool() {
        setVisible(false);
    }
    virtual void doSomething();
private:
    
};
class Protester: public GameObject {
public:
    Protester(StudentWorld* sw, int startX, int startY, int numSquaresToMoveInCurrentDirection, int ticksToWait, int imageID);
    virtual ~Protester() {
        setVisible(false);
    }
    virtual void doSomething();
    void setHP(int x);
    int getHP();
    void setRandDir();
    void setLeaveField();
    void annoy(int x);
    bool moveInPerp(Direction &d);
    bool isValidPos(int x, int y);
    void BFS(std::stack <Direction> &p, int startX, int startY, int endX, int endY);
    bool getLeaveField();
    void decNumSquares();
    int getNumSquares();
    void setNumSquares(int x);
    void setTurnWithinTrue();
    int getStunnedTicks();
    int getNonRestingTicks();
    void incNonRestingTicks();
    void setShoutedFalse();
    int getWaitingTicks();
    void setTurnWithinFalse();
private:
    int m_numSquaresToMoveInCurrentDirection;
    bool m_leaveTheField;
    int m_ticksToWait;
    int m_nonRestingTicks;
    int m_hp;
    bool shoutedWithin15;
    bool turnWithin200;
    int stunnedTicks;
    std::stack <Direction> path;
};
class HardcoreProtester: public Protester {
public:
    HardcoreProtester(StudentWorld* sw, int startX, int startY, int numSquaresToMoveInCurrentDirection, int ticksToWait);
    virtual ~HardcoreProtester() {
        setVisible(false);
    }
    bool DFS(std::stack <Direction> &p, int startX, int startY, int endX, int endY);
    void setTicksToStare(int x);
    int getTicksToStare();
    virtual void doSomething();
private:
    int ticksToStare;
};
#endif // ACTOR_H_
