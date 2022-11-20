//#include "StudentWorld.h"
//#include <string>
//#include <algorithm>
//using namespace std;
//
//GameWorld* createStudentWorld(string assetDir)
//{
//    return new StudentWorld(assetDir);
//}
//
//StudentWorld::~StudentWorld() {
//}
//
//int StudentWorld::init()
//{
//    TM = new TunnelMan(this);
//
//    int lvl = getLevel() / 4;
//    srand(time(NULL));
//    int lvl2 = getLevel();
//    lvl2 *= 10;
//    lvl2 += 30;
//    int probabilityOfHardcore = std::min(90, lvl2);
//    int rNum = rand() % 53 + 8;
//    int restTick = std::max(0, 3 - lvl);
//    int hardcoreOrPro = rand() % 100 + 1;
//    if (hardcoreOrPro <= probabilityOfHardcore) {
//        actors.push_back(new HardcoreProtester(this, 60, 60, rNum, restTick));
//    }
//    else if (hardcoreOrPro > probabilityOfHardcore){
//        actors.push_back(new Protester(this, 60, 60, rNum, restTick,TID_PROTESTER));
//    }
//
//    for (int i = 0; i < 64; i++) {
//        for (int k = 0; k < 60; k++) {
//            earth[i][k] = nullptr;
//        }
//    }
//
//    for (int i = 0; i < 30; i++) {
//        for (int k = 0; k < 60; k++) {
//            earth[i][k] = new Earth(this, i, k);
//        }
//    }
//
//    for (int i = 34; i < 64; i++) {
//        for (int k = 0; k < 60; k++) {
//            earth[i][k] = new Earth(this, i, k);
//        }
//    }
//
//    for (int i = 30; i < 34; i++) {
//        for (int k = 0; k < 4; k++ ) {
//            earth[i][k] = new Earth(this, i, k);
//        }
//    }
//
//    int gL = getLevel()/2;
//    int numBoulders = std::min(gL + 2, 9);
//
//    int numGold = std::max(5- gL, 2);
//
//    int numBarrel = std::min(2 + gL*2, 21);
//
//    numBarrels = numBarrel;
//
//    int randX = 0;
//    int randY = 0;
//
//    srand(time(NULL));
//
//    for (int i = 0; i < numBoulders; i++) {
//        randX = rand() % 61;
//        randY = rand() % 37 + 20;
//        while ((randX >= 26 && randX <= 34) || withinSix(randX, randY) || randY >= 55 || randX == 0 || randX == 60) {
//            randX = rand() % 61;
//            randY = rand() % 37 + 20;
//        }
//        actors.push_back(new Boulder(this, randX, randY));
//    }
//
//    for (int i = 0; i < numBarrel; i++) {
//        randX = rand() % 61;
//        randY = rand() % 57;
//
//        while (withinSix(randX, randY) ||(randX >= 26 && randX <= 34)) {
//            randX = rand() % 61;
//            randY = rand() % 57;
//        }
//        actors.push_back(new Barrel(this, randX, randY));
//    }
//
//    for (int i = 0; i < numGold; i++) {
//        randX = rand() % 61;
//        randY = rand() % 57;
//
//        while (withinSix(randX, randY)) {
//            randX = rand() % 61;
//            randY = rand() % 57;
//        }
//        actors.push_back(new Gold(this, randX, randY, false, false, true));
//    }
//
//
//    for (int i = 0; i < 64; i++) {
//        for (int k = 0; k < 60; k++) {
//            if (hasBoulder(i, k)) {
//                delete earth[i][k];
//                earth[i][k] = nullptr;
//            }
//        }
//    }
//    return GWSTATUS_CONTINUE_GAME;
//}
//
//std::string StudentWorld::formatText(int level, int lives, int health, int squirts, int gold, int barrelsLeft, int sonar, int score) {
//    int percent = health*10;
//
//    return ("Lvl: " + to_string(level) + " Lives: " + to_string(lives) + " Hlth: " + to_string(percent) + "% Wtr: " + to_string(squirts) + " Gld: " + to_string(gold) + " Oil Left: " + to_string(barrelsLeft) + " Sonar: " + to_string(sonar) + " Scr: " + to_string(score));
//
//}
//
//void StudentWorld::setDisplayText() {
//    int level = getLevel();
//    int lives = getLives();
//    int health = TM->getHealth();
//    int squirts = TM->getSquirts();
//    int gold = TM->getGold();
//    int barrelsLeft = numBarrels;
//    int sonar = TM->getSonar();
//    int score = getScore();
//    // Next, create a string from your statistics, of the form: // Lvl: 52 Lives: 3 Hlth: 80% Wtr: 20 Gld: 3 Oil Left: 2 Sonar: 1 Scr: 321000
//    string s = formatText(level, lives, health, squirts, gold, barrelsLeft, sonar, score);
//    // Finally, update the display text at the top of the screen with your // newly created stats
//    setGameStatText(s); // calls our provided GameWorld::setGameStatText
//}
//
//int StudentWorld::move()
//{
//    if (!TM->isAlive()) {
//        decLives();
//        return GWSTATUS_PLAYER_DIED;
//    }
//    numBarrels = barrelsLeft();
//    int lvl = getLevel();
//    int T = std::max(25, 200 - lvl);
//    lvl *= 1.5;
//    int P = std::min(15, 2 + lvl);
//    m_ticks++;
//    if (m_ticks >= T) {
//        int lvl2 = getLevel();
//        lvl2 *= 10;
//        lvl2 += 30;
//        int probabilityOfHardcore = std::min(90, lvl2);
//        int lvl = getLevel() / 4;
//        srand(time(NULL));
//        int hardcoreOrPro = rand() % 100 + 1;
//        int rNum = rand() % 53 + 8;
//        int restTick = std::max(0, 3 - lvl);
//        if (hardcoreOrPro <= probabilityOfHardcore) {
//            if (getProtesters() < P) {
//                actors.push_back(new HardcoreProtester(this, 60, 60, rNum, restTick));
//            }
//        }
//        else {
//            if (getProtesters() < P) {
//                actors.push_back(new Protester(this, 60, 60, rNum, restTick,TID_PROTESTER));
//            }
//        }
//        m_ticks = 0;
//    }
//    if (!barrelsLeft()) {
//        return GWSTATUS_FINISHED_LEVEL;
//    }
//    if (m_ticks >= 1000){
//        m_ticks = 0;
//    }
//    setDisplayText();
//
//    int G = getLevel()*25 + 300;
//    int randG = rand() % G;
//    if (randG == 1) {
//        int SK = rand() % 5;
//        if (SK == 1) {
//            if (!withinSix(0, 60)) {
//                actors.push_back(new Sonar(this, 0, 60, false, false, TID_SONAR));
//            }
//        }
//        else {
//            int randX = rand() % 61;
//            int randY = rand() % 61;
//            while (!earthlessFourByFour(randX, randY)) {
//                randX = rand() % 61;
//                randY = rand() % 61;
//            }
//            if (!hasWaterPool(randX, randY) && !hasBoulder(randX, randY) && !withinSix(randX, randY)) {
//                actors.push_back(new WaterPool(this, randX, randY,TID_WATER_POOL));
//            }
//        }
//    }
//
//    TM->doSomething();
//    auto it = actors.begin();
//
//    while (it != actors.end()) {
//        (*it)->doSomething();
//        it++;
//    }
//
//    it = actors.begin();
//
//    while (it != actors.end()) {
//        if (!(*it)->isAlive()) {
//            delete *it;
//            actors.erase(it);
//            it = actors.begin();
//            continue;
//        }
//        it++;
//    }
//
//
//    // This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
//    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
//    //    decLives();
//    if (getLives() > 0) {
//        return GWSTATUS_CONTINUE_GAME;
//    }
//    return GWSTATUS_PLAYER_DIED;
//}
//
//void StudentWorld::checkCollision() {
//    int x = TM->getX();
//    int y = TM->getY();
//    bool playedSound = false;
//    for (int i = x; i < x + 4; i++) {
//        for (int k = y; k < y + 4; k++) {
//            if (i >= 0 && i < 64 && k >= 0 && k < 60) {
//                if (hasEarth(i,k)) {
//                    if (!playedSound) {
//                        playSound(SOUND_DIG);
//                        playedSound = true;
//                    }
//                    earth[i][k]->setVisible(false);
//                }
//            }
//        }
//    }
//}
//
//void StudentWorld::cleanUp()
//{
//    delete TM;
//    for (int i = 0; i < 64; i++) {
//        for (int k = 0; k < 60; k++) {
//            if (earth[i][k] != nullptr) {
//                delete earth[i][k];
//                earth[i][k] = nullptr;
//            }
//        }
//    }
//    auto it = actors.begin();
//    while (it != actors.end()) {
//        delete *it;
//        actors.erase(it);
//        it = actors.begin();
//    }
//}
//
//bool StudentWorld::hasEarth(int x, int y) {
//    if (x > 63 || x < 0 || y > 59 || y < 0) {
//        return false;
//    }
//    if (earth[x][y] == nullptr) {
//        return false;
//    }
//    return earth[x][y]->isVisible();
//}
//
//bool StudentWorld::hasBoulder(int x, int y) {
//    auto it = actors.begin();
//    while (it != actors.end()) {
//        for (int xi = x; xi > x - 4; xi--) {
//            for (int yi = y; yi > y - 4; yi--) {
//                if ((*it)->getX() == xi && (*it)->getY() == yi) {
//                    if ((*it)->isAlive()) {
//                        if ((*it)->getType() == "Boulder") {
//                            return true;
//                        }
//                    }
//                }
//            }
//        }
//        it++;
//    }
//    return false;
//}
//
//void StudentWorld::animateSquirt(GameObject* ptr) {
//    if (hasBoulder(ptr->getX(), ptr->getY()) || boulderNearSquirtOrPlayer(ptr->getX(), ptr->getY())) {
//        ptr->setDead();
//        return;
//    }
//    int x = ptr->getX();
//    int y = ptr->getY();
//    auto it = actors.begin();
//    while (it != actors.end()) {
//        if ((*it)->getID() == TID_PROTESTER || (*it)->getID() == TID_HARD_CORE_PROTESTER) {
//            int x2 = (*it)->getX();
//            int y2 = (*it)->getY();
//            if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) <= 3) {
//                if ((*it)->getID() == TID_PROTESTER) {
//                    Protester* p = dynamic_cast<Protester*>(*it);
//                    if (p->getStunnedTicks() > 0) {//already stunned so should immediately return
//                        ptr->setDead();
//                        return;
//                    }
//                    p->annoy(2);
//                    ptr->setDead();
//                    return;
//                }
//                else if((*it)->getID() == TID_HARD_CORE_PROTESTER) {
//                    HardcoreProtester* hp = dynamic_cast<HardcoreProtester*>(*it);
//                    if (hp->getStunnedTicks() > 0 || hp->getTicksToStare() > 0) {//already stunned or bribed so return
//                        ptr->setDead();
//                        return;
//                    }
//                    hp->annoy(2);
//                    ptr->setDead();
//                    return;
//                }
//            }
//        }
//        it++;
//    }
//}
//
//bool StudentWorld::withinSix(int x, int y) {
//    auto it = actors.begin();
//    while (it != actors.end()) {
//        int x2 = (*it)->getX();
//        int y2 = (*it)->getY();
//        if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) <= 6) {
//            return true;
//        }
//        it++;
//    }
//    return false;
//}
//
//bool StudentWorld::boulderNearSquirtOrPlayer(int x, int y) {
//    auto it = actors.begin();
//    while (it != actors.end()) {
//        int x2 = (*it)->getX();
//        int y2 = (*it)->getY();
//        if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) <= 3) {
//            if ((*it)->getType() == "Boulder") {
//                return true;
//            }
//        }
//        it++;
//    }
//    return false;
//}
//
//bool StudentWorld::playerWithinFour(int x, int y) {
//    int x2 = TM->getX();
//    int y2 = TM->getY();
//    if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) <= 4) {
//        return true;
//    }
//    return false;
//}
//
//bool StudentWorld::playerWithinThree(int x, int y) {
//    int x2 = TM->getX();
//    int y2 = TM->getY();
//    if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) <= 3) {
//        return true;
//    }
//    return false;
//}
//
//int StudentWorld::barrelsLeft() {
//    auto it = actors.begin();
//    int out = 0;
//    while (it != actors.end()) {
//        if ((*it)->getType() == "Barrel") {
//            out++;
//        }
//        it++;
//    }
//    return out;
//}
//void StudentWorld::gotGold() {
//    TM->incGold();
//}
//
//void StudentWorld::gotSonar() {
//    TM->incSonar();
//}
//
//void StudentWorld::gotWater() {
//    TM->incWater();
//}
//
//bool StudentWorld::earthlessFourByFour(int x, int y) {
//    for (int i = x; i < x + 4; i++) {
//        for (int k = y; k < y + 4; k++) {
//            if (k != 60) {
//                if (hasEarth(i, k)) {
//                    return false;
//                }
//            }
//        }
//    }
//    return true;
//}
//
//void StudentWorld::useSonar() {
//    int x = TM->getX();
//    int y = TM->getY();
//    auto it = actors.begin();
//    while (it != actors.end()) {
//        int x2 = (*it)->getX();
//        int y2 = (*it)->getY();
//        if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) <= 12) {
//            (*it)->setVisible(true);
//        }
//        it++;
//    }
//    TM->decSonar();
//}
//
//void StudentWorld::regProtesterAnnoy() {
//    TM->decHealth(2);
//}
//
//int StudentWorld::getPlayerX() {
//    return TM->getX();
//}
//
//int StudentWorld::getPlayerY() {
//    return TM->getY();
//}
//
//int StudentWorld::getProtesters() {
//    auto it = actors.begin();
//    int out = 0;
//    while (it != actors.end()) {
//        if ((*it)->getType() == "Protester") {
//            if ((*it)->isAlive()) {
//                out += 1;
//            }
//        }
//        it++;
//    }
//    return out;
//}
//
//bool StudentWorld::hasWaterPool(int x, int y) {
//    auto it = actors.begin();
//    while (it != actors.end()) {
//        if ((*it)->getType() == "WaterPool") {
//            return true;
//        }
//        it++;
//    }
//    return false;
//}
//
//GameObject* StudentWorld::setEarth(int x, int y) {
//    return earth[x][y];
//}
//
//void StudentWorld::insertObject(GameObject *actor) {
//    actors.push_back(actor);
//}
//bool StudentWorld::didBribe(int x, int y) {
//    auto it = actors.begin();
//    while (it != actors.end()) {
//        if ((*it)->getID() == TID_PROTESTER || (*it)->getID() == TID_HARD_CORE_PROTESTER) {
//            int x2 = (*it)->getX();
//            int y2 = (*it)->getY();
//            if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) <= 3) {
//                if ((*it)->getID() == TID_PROTESTER) {
//                    Protester* p = dynamic_cast<Protester*>(*it);
//                    p->setLeaveField();
//                    increaseScore(25);
//                    return true;
//                }
//                if ((*it)->getID() == TID_HARD_CORE_PROTESTER) {
//                    HardcoreProtester* h = dynamic_cast<HardcoreProtester*>(*it);
//                    int lvl = getLevel();
//                    lvl *= 10;
//                    h->setTicksToStare(std::max(50,100 - lvl));
//                    increaseScore(50);
//                    return true;
//                }
//            }
//        }
//        it++;
//    }
//    return false;
//}
//// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp
#include "StudentWorld.h"
#include <string>
#include <algorithm>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
    return new StudentWorld(assetDir);
}

StudentWorld::~StudentWorld() {
}

int StudentWorld::init()
{
    TM = new TunnelMan(this);
    
    int lvl = getLevel() / 4;
    srand(time(NULL));
    int lvl2 = getLevel();
    lvl2 *= 10;
    lvl2 += 30;
    int probabilityOfHardcore = std::min(90, lvl2);
    int rNum = rand() % 53 + 8;
    int restTick = std::max(0, 3 - lvl);
    int hardcoreOrPro = rand() % 100 + 1;
    if (hardcoreOrPro <= probabilityOfHardcore) {
        actors.push_back(new HardcoreProtester(this, 60, 60, rNum, restTick));
    }
    else if (hardcoreOrPro > probabilityOfHardcore){
        actors.push_back(new Protester(this, 60, 60, rNum, restTick,TID_PROTESTER));
    }
    
    for (int i = 0; i < 64; i++) {
        for (int k = 0; k < 60; k++) {
            earth[i][k] = nullptr;
        }
    }
    
    for (int i = 0; i < 30; i++) {
        for (int k = 0; k < 60; k++) {
            earth[i][k] = new Earth(this, i, k);
        }
    }
    
    for (int i = 34; i < 64; i++) {
        for (int k = 0; k < 60; k++) {
            earth[i][k] = new Earth(this, i, k);
        }
    }
    
    for (int i = 30; i < 34; i++) {
        for (int k = 0; k < 4; k++ ) {
            earth[i][k] = new Earth(this, i, k);
        }
    }
    
    int gL = getLevel()/2;
    int numBoulders = std::min(gL + 2, 9);
    
    int numGold = std::max(5- gL, 2);
    
    int numBarrel = std::min(2 + gL*2, 21);
    
    numBarrels = numBarrel;
    
    int randX = 0;
    int randY = 0;
    
    srand(time(NULL));
    
    for (int i = 0; i < numBoulders; i++) {
        randX = rand() % 61;
        randY = rand() % 37 + 20;
        while ((randX >= 26 && randX <= 34) || withinSix(randX, randY) || randY >= 55 || randX == 0 || randX == 60) {
            randX = rand() % 61;
            randY = rand() % 37 + 20;
        }
        actors.push_back(new Boulder(this, randX, randY));
    }
    
    for (int i = 0; i < numBarrel; i++) {
        randX = rand() % 61;
        randY = rand() % 57;
        
        while (withinSix(randX, randY) ||(randX >= 26 && randX <= 34)) {
            randX = rand() % 61;
            randY = rand() % 57;
        }
        actors.push_back(new Barrel(this, randX, randY));
    }
    
    for (int i = 0; i < numGold; i++) {
        randX = rand() % 61;
        randY = rand() % 57;
        
        while (withinSix(randX, randY)) {
            randX = rand() % 61;
            randY = rand() % 57;
        }
        actors.push_back(new Gold(this, randX, randY, false, false, true));
    }
    
    
    for (int i = 0; i < 64; i++) {
        for (int k = 0; k < 60; k++) {
            if (hasBoulder(i, k)) {
                delete earth[i][k];
                earth[i][k] = nullptr;
            }
        }
    }
    return GWSTATUS_CONTINUE_GAME;
}

std::string StudentWorld::formatText(int level, int lives, int health, int squirts, int gold, int barrelsLeft, int sonar, int score) {
    int percent = health*10;
    
    return ("Lvl: " + to_string(level) + " Lives: " + to_string(lives) + " Hlth: " + to_string(percent) + "% Wtr: " + to_string(squirts) + " Gld: " + to_string(gold) + " Oil Left: " + to_string(barrelsLeft) + " Sonar: " + to_string(sonar) + " Scr: " + to_string(score));
    
}

void StudentWorld::setDisplayText() {
    int level = getLevel();
    int lives = getLives();
    int health = TM->getHealth();
    int squirts = TM->getSquirts();
    int gold = TM->getGold();
    int barrelsLeft = numBarrels;
    int sonar = TM->getSonar();
    int score = getScore();
    // Next, create a string from your statistics, of the form: // Lvl: 52 Lives: 3 Hlth: 80% Wtr: 20 Gld: 3 Oil Left: 2 Sonar: 1 Scr: 321000
    string s = formatText(level, lives, health, squirts, gold, barrelsLeft, sonar, score);
    // Finally, update the display text at the top of the screen with your // newly created stats
    setGameStatText(s); // calls our provided GameWorld::setGameStatText
}

int StudentWorld::move()
{
    if (!TM->isAlive()) {
        decLives();
        return GWSTATUS_PLAYER_DIED;
    }
    numBarrels = barrelsLeft();
    int lvl = getLevel();
    int T = std::max(25, 200 - lvl);
    lvl *= 1.5;
    int P = std::min(15, 2 + lvl);
    m_ticks++;
    if (m_ticks >= T) {
        int lvl2 = getLevel();
        lvl2 *= 10;
        lvl2 += 30;
        int probabilityOfHardcore = std::min(90, lvl2);
        int lvl = getLevel() / 4;
        srand(time(NULL));
        int hardcoreOrPro = rand() % 100 + 1;
        int rNum = rand() % 53 + 8;
        int restTick = std::max(0, 3 - lvl);
        if (hardcoreOrPro <= probabilityOfHardcore) {
            if (getProtesters() < P) {
                actors.push_back(new HardcoreProtester(this, 60, 60, rNum, restTick));
            }
        }
        else {
            if (getProtesters() < P) {
                actors.push_back(new Protester(this, 60, 60, rNum, restTick,TID_PROTESTER));
            }
        }
        m_ticks = 0;
    }
    if (!barrelsLeft()) {
        return GWSTATUS_FINISHED_LEVEL;
    }
    if (m_ticks >= 1000){
        m_ticks = 0;
    }
    setDisplayText();
    
    int G = getLevel()*25 + 300;
    int randG = rand() % G;
    if (randG == 1) {
        int SK = rand() % 5;
        if (SK == 1) {
            if (!withinSix(0, 60)) {
                actors.push_back(new Sonar(this, 0, 60, false, false, TID_SONAR));
            }
        }
        else {
            int randX = rand() % 61;
            int randY = rand() % 61;
            while (!earthlessFourByFour(randX, randY)) {
                randX = rand() % 61;
                randY = rand() % 61;
            }
            if (!hasWaterPool(randX, randY) && !hasBoulder(randX, randY) && !withinSix(randX, randY)) {
                actors.push_back(new WaterPool(this, randX, randY,TID_WATER_POOL));
            }
        }
    }
    
    TM->doSomething();
    auto it = actors.begin();
    
    while (it != actors.end()) {
        (*it)->doSomething();
        it++;
    }
    
    it = actors.begin();
    
    while (it != actors.end()) {
        if (!(*it)->isAlive()) {
            delete *it;
            actors.erase(it);
            it = actors.begin();
            continue;
        }
        it++;
    }
    
    
    // This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    //    decLives();
    if (getLives() > 0) {
        return GWSTATUS_CONTINUE_GAME;
    }
    return GWSTATUS_PLAYER_DIED;
}

void StudentWorld::checkCollision() {
    int x = TM->getX();
    int y = TM->getY();
    bool playedSound = false;
    for (int i = x; i < x + 4; i++) {
        for (int k = y; k < y + 4; k++) {
            if (i >= 0 && i < 64 && k >= 0 && k < 60) {
                if (hasEarth(i,k)) {
                    if (!playedSound) {
                        playSound(SOUND_DIG);
                        playedSound = true;
                    }
                    earth[i][k]->setVisible(false);
                }
            }
        }
    }
}

void StudentWorld::cleanUp()
{
    delete TM;
    for (int i = 0; i < 64; i++) {
        for (int k = 0; k < 60; k++) {
            if (earth[i][k] != nullptr) {
                delete earth[i][k];
                earth[i][k] = nullptr;
            }
        }
    }
    auto it = actors.begin();
    while (it != actors.end()) {
        delete *it;
        actors.erase(it);
        it = actors.begin();
    }
}

bool StudentWorld::hasEarth(int x, int y) {
    if (x > 63 || x < 0 || y > 59 || y < 0) {
        return false;
    }
    if (earth[x][y] == nullptr) {
        return false;
    }
    return earth[x][y]->isVisible();
}

bool StudentWorld::hasBoulder(int x, int y) {
    auto it = actors.begin();
    while (it != actors.end()) {
        for (int xi = x; xi > x - 4; xi--) {
            for (int yi = y; yi > y - 4; yi--) {
                if ((*it)->getX() == xi && (*it)->getY() == yi) {
                    if ((*it)->isAlive()) {
                        if ((*it)->getType() == "Boulder") {
                            return true;
                        }
                    }
                }
            }
        }
        it++;
    }
    return false;
}

void StudentWorld::animateSquirt(GameObject* ptr) {
    if (hasBoulder(ptr->getX(), ptr->getY()) || boulderNearSquirtOrPlayer(ptr->getX(), ptr->getY())) {
        ptr->setDead();
        return;
    }
    int x = ptr->getX();
    int y = ptr->getY();
    auto it = actors.begin();
    while (it != actors.end()) {
        if ((*it)->getID() == TID_PROTESTER || (*it)->getID() == TID_HARD_CORE_PROTESTER) {
            int x2 = (*it)->getX();
            int y2 = (*it)->getY();
            if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) <= 3) {
                if ((*it)->getID() == TID_PROTESTER) {
                    Protester* p = dynamic_cast<Protester*>(*it);
                    if (p->getStunnedTicks() > 0) {//already stunned so should immediately return
                        ptr->setDead();
                        return;
                    }
                    p->annoy(2);
                    ptr->setDead();
                    return;
                }
                else if((*it)->getID() == TID_HARD_CORE_PROTESTER) {
                    HardcoreProtester* hp = dynamic_cast<HardcoreProtester*>(*it);
                    if (hp->getStunnedTicks() > 0 || hp->getTicksToStare() > 0) {//already stunned or bribed so return
                        ptr->setDead();
                        return;
                    }
                    hp->annoy(2);
                    ptr->setDead();
                    return;
                }
            }
        }
        it++;
    }
}

bool StudentWorld::withinSix(int x, int y) {
    auto it = actors.begin();
    while (it != actors.end()) {
        int x2 = (*it)->getX();
        int y2 = (*it)->getY();
        if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) <= 6) {
            return true;
        }
        it++;
    }
    return false;
}

bool StudentWorld::boulderNearSquirtOrPlayer(int x, int y) {
    auto it = actors.begin();
    while (it != actors.end()) {
        int x2 = (*it)->getX();
        int y2 = (*it)->getY();
        if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) <= 3) {
            if ((*it)->getType() == "Boulder") {
                return true;
            }
        }
        it++;
    }
    return false;
}

bool StudentWorld::playerWithinFour(int x, int y) {
    int x2 = TM->getX();
    int y2 = TM->getY();
    if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) <= 4) {
        return true;
    }
    return false;
}

bool StudentWorld::playerWithinThree(int x, int y) {
    int x2 = TM->getX();
    int y2 = TM->getY();
    if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) <= 3) {
        return true;
    }
    return false;
}

int StudentWorld::barrelsLeft() {
    auto it = actors.begin();
    int out = 0;
    while (it != actors.end()) {
        if ((*it)->getType() == "Barrel") {
            out++;
        }
        it++;
    }
    return out;
}
void StudentWorld::gotGold() {
    TM->incGold();
}

void StudentWorld::gotSonar() {
    TM->incSonar();
}

void StudentWorld::gotWater() {
    TM->incWater();
}

bool StudentWorld::earthlessFourByFour(int x, int y) {
    for (int i = x; i < x + 4; i++) {
        for (int k = y; k < y + 4; k++) {
            if (k != 60) {
                if (hasEarth(i, k)) {
                    return false;
                }
            }
        }
    }
    return true;
}

void StudentWorld::useSonar() {
    int x = TM->getX();
    int y = TM->getY();
    auto it = actors.begin();
    while (it != actors.end()) {
        int x2 = (*it)->getX();
        int y2 = (*it)->getY();
        if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) <= 12) {
            (*it)->setVisible(true);
        }
        it++;
    }
    TM->decSonar();
}

void StudentWorld::regProtesterAnnoy() {
    TM->decHealth(2);
}

int StudentWorld::getPlayerX() {
    return TM->getX();
}

int StudentWorld::getPlayerY() {
    return TM->getY();
}

int StudentWorld::getProtesters() {
    auto it = actors.begin();
    int out = 0;
    while (it != actors.end()) {
        if ((*it)->getType() == "Protester") {
            if ((*it)->isAlive()) {
                out += 1;
            }
        }
        it++;
    }
    return out;
}

bool StudentWorld::hasWaterPool(int x, int y) {
    auto it = actors.begin();
    while (it != actors.end()) {
        if ((*it)->getType() == "WaterPool") {
            return true;
        }
        it++;
    }
    return false;
}

GameObject* StudentWorld::setEarth(int x, int y) {
    return earth[x][y];
}

void StudentWorld::insertObject(GameObject *actor) {
    actors.push_back(actor);
}
bool StudentWorld::didBribe(int x, int y) {
    auto it = actors.begin();
    while (it != actors.end()) {
        if ((*it)->getID() == TID_PROTESTER || (*it)->getID() == TID_HARD_CORE_PROTESTER) {
            int x2 = (*it)->getX();
            int y2 = (*it)->getY();
            if (sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y)) <= 3) {
                if ((*it)->getID() == TID_PROTESTER) {
                    Protester* p = dynamic_cast<Protester*>(*it);
                    p->setLeaveField();
                    increaseScore(25);
                    return true;
                }
                if ((*it)->getID() == TID_HARD_CORE_PROTESTER) {
                    HardcoreProtester* h = dynamic_cast<HardcoreProtester*>(*it);
                    int lvl = getLevel();
                    lvl *= 10;
                    h->setTicksToStare(std::max(50,100 - lvl));
                    increaseScore(50);
                    return true;
                }
            }
        }
        it++;
    }
    return false;
}
// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp
