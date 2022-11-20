//#include "Actor.h"
//#include <algorithm>
//
//// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp
//Earth::Earth(StudentWorld* sw, int startX, int startY):
//GameObject(TID_EARTH,startX,startY, right, 0.25, 3, sw) {
//    GameObject* g = getWorld()->setEarth(startX, startY);
//    g = this;
//    setType("Earth");
//}
//
//TunnelMan::TunnelMan(StudentWorld* sw): GameObject(TID_PLAYER, 30, 60, right, 1.0, 0, sw) {
//    m_hitpoints = 10;
//    m_water = 5;
//    m_sonar = 1;
//    m_gnugget = 0;
//    setType("TunnelMan");
//}
//
//void TunnelMan::doSomething() {
//    if (m_hitpoints <= 0) {
//        setDead();
//        getWorld()->playSound(SOUND_PLAYER_GIVE_UP);
//        return;
//    }
//    if (getWorld()->boulderNearSquirtOrPlayer(getX(), getY())) {
//        setDead();
//        getWorld()->playSound(SOUND_PLAYER_GIVE_UP);
//        return;
//    }
//    int ch;
//    if (getWorld()->getKey(ch) == true) {
//        switch(ch) {
//            case KEY_PRESS_LEFT:
//                if (getDirection() != left) {
//                    setDirection(left);
//                }
//                else if (getX() - 1 < 0) {
//                    break;
//                }
//                else if (boulderNearby(getX() -1 , getY())) {
//                    break;
//                }
//                else {
//                    moveTo(getX() - 1, getY());
//                    getWorld()->checkCollision();
//                }
//                break;
//            case KEY_PRESS_RIGHT:
//                if (getDirection() != right) {
//                    setDirection(right);
//                }
//                else if (getX() +  1 > 60) {
//                    break;
//                }
//                else if (boulderNearby(getX() +1 , getY())) {
//                    break;
//                }
//                else {
//                    moveTo(getX() + 1, getY());
//                    getWorld()->checkCollision();
//                }
//                break;
//            case KEY_PRESS_UP:
//                if (getDirection() != up) {
//                    setDirection(up);
//                }
//                else if(getY() + 1 > 60) {
//                    break;
//                }
//                else if (boulderNearby(getX() , getY() + 1)) {
//                    break;
//                }
//                else {
//                    moveTo(getX(), getY() + 1);
//                    getWorld()->checkCollision();
//                }
//                break;
//            case KEY_PRESS_DOWN:
//                if (getDirection() != down) {
//                    setDirection(down);
//                }
//                else if(getY() -1 < 0) {
//                    break;
//                }
//                else if (boulderNearby(getX() , getY() - 1)) {
//                    break;
//                }
//                else {
//                    moveTo(getX(), getY() - 1);
//                    getWorld()->checkCollision();
//                }
//                break;
//            case KEY_PRESS_ESCAPE:
//                setDead();
//                break;
//            case KEY_PRESS_SPACE:
//                if (getSquirts() <= 0)
//                    break;
//                getWorld()->playSound(SOUND_PLAYER_SQUIRT);
//                m_water--;
//                if (getDirection() == up) {
//                    new Squirt(getWorld(), getX(), getY() + 4, up);
//                }
//                else if(getDirection() == down) {
//                    new Squirt(getWorld(), getX(), getY() - 4, down);
//                }
//                else if (getDirection() == right) {
//                    new Squirt(getWorld(), getX() + 4, getY(), right);
//                }
//                else {
//                    new Squirt(getWorld(), getX() - 4, getY(), left);
//                }
//                break;
//            case 'Z':
//                if (getSonar() > 0) {
//                    getWorld()->useSonar();
//                    getWorld()->playSound(SOUND_SONAR);
//                }
//                break;
//            case 'z':
//                if (getSonar() > 0) {
//                    getWorld()->useSonar();
//                    getWorld()->playSound(SOUND_SONAR);
//                }
//                break;
//            case KEY_PRESS_TAB:
//                if (m_gnugget >= 1) {
//                    getWorld()->insertObject(new Gold(getWorld(), getX(), getY(), true, true, false));
//                    m_gnugget--;
//                }
//                break;
//            default:
//                break;
//        }
//    }
//}
//
//Boulder::Boulder(StudentWorld* sw, int startX, int startY): GameObject(TID_BOULDER, startX, startY, down, 1.0, 1, sw) {
//    m_state = "stable";
//    setType("Boulder");
//}
//
//void Boulder::doSomething() {
//    if (!isAlive()) {
//        setVisible(false);
//        return;
//    }
//    if (m_state == "stable") {
//        if (getWorld()->hasEarth(getX(), getY() - 1) || getWorld()->hasEarth(getX() +1 , getY() - 1) || getWorld()->hasEarth(getX() +2, getY() - 1) || getWorld()->hasEarth(getX() + 3, getY() - 1)) {
//            return;
//        }
//        m_state = "waiting";
//    }
//    else if (m_state == "waiting") {
//        incTick();
//        if (getTicks() == 30) {
//            m_state = "falling";
//            getWorld()->playSound(SOUND_FALLING_ROCK);
//        }
//    }
//    else {
//        if (getWorld()->hasEarth(getX() + 1, getY()) ||getWorld()->hasEarth(getX() + 2, getY()) || getWorld()->hasEarth(getX() + 3, getY()) || getY() - 1 < 0 || getWorld()->hasEarth(getX(), getY() - 1) || getWorld()->hasBoulder(getX(), getY() - 5)) { // make sure boulders spawn greater than 4 tiles above/below other boulders
//            setDead();
//            return;
//        }
//        else {
//            moveTo(getX(), getY() - 1);
//        }
//    }
//}
//
//bool TunnelMan::boulderNearby(int x, int y) {
//    for (int xi = x; xi < x + 4; xi++) {
//        for (int yi = y; yi < y + 4; yi++) {
//            if (getWorld()->hasBoulder(xi, yi)) {
//                return true;
//            }
//        }
//    }
//    return false;
//}
//Squirt::Squirt(StudentWorld* sw, int startX, int startY, Direction dir): GameObject(TID_WATER_SPURT, startX, startY, dir, 1.0, 1, sw) {
//    initialTravelDistance = 4;
//    getWorld()->insertObject(this); // everything is automaticlly inserted in the init but this is not, so we need to manually insert
//    setType("Squirt");
//}
//
//void Squirt::doSomething() {
//
//    getWorld()->animateSquirt(this);
//
//    if (getX() > 60 || getX() < 0 || getY() > 60 || getY() < 0) {
//        setDead();
//    }
//
//    if (!isAlive()) {
//        return;
//    }
//
//    if (initialTravelDistance == 0) {
//        setDead();
//        return;
//    }
//    switch(getDirection()) {
//        case left:
//            if (getY() != 60) {
//                if (earthNearby(getX() - 1, getY())) {
//                    setDead();
//                    break;
//                }
//            }
//            moveTo(getX() - 1, getY());
//            initialTravelDistance--;
//            return;
//        case right:
//            if (getY() != 60) {
//                if (earthNearby(getX() + 1, getY())) {
//                    setDead();
//                    break;
//                }
//            }
//            moveTo(getX() + 1, getY());
//            initialTravelDistance--;
//            return;
//        case up:
//            if (earthNearby(getX(), getY() + 1)) {
//                setDead();
//                break;
//            }
//            moveTo(getX(), getY() + 1);
//            initialTravelDistance--;
//            return;
//        case down:
//            if (earthNearby(getX(), getY() - 1) ) {
//                setDead();
//                break;
//            }
//            moveTo(getX(), getY() - 1);
//            initialTravelDistance--;
//            return;
//        default:
//            break;
//    }
//}
//
//bool Squirt::earthNearby(int x, int y) {
//
//    for (int i = x; i < x + 4; i++) {
//        for (int k = y; k < y + 4; k++) {
//            if (i > 63 || k > 59 || i < 0 || k < 0) {
//                continue;
//            }
//            if (getWorld()->hasEarth(i, k)) {
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//bool Squirt::boulderNearby(int x, int y) {
//    return getWorld()->boulderNearSquirtOrPlayer(x, y);
//}
//
//Barrel::Barrel(StudentWorld* sw, int startX, int startY): GameObject(TID_BARREL, startX, startY, right, 1.0, 2, sw) {
//    setType("Barrel");
//    setVisible(false);
//}
//
//void Barrel::doSomething() {
//    if (!isAlive()) {
//        return;
//    }
//    if (getWorld()->playerWithinFour(getX(), getY()) && !isVisible()) {
//        setVisible(true);
//        return;
//    }
//
//    if (getWorld()->playerWithinThree(getX(), getY())) {
//        setDead();
//        getWorld()->playSound(SOUND_FOUND_OIL);
//        getWorld()->increaseScore(1000);
//    }
//
//}
//
//Gold::Gold(StudentWorld* sw, int startX, int startY, bool isVisible,bool protesterOrPlayer, bool isPermanent): Goodie(sw, startX, startY,  protesterOrPlayer, isPermanent, TID_GOLD) {
//    setVisible(false);
//    if (isVisible) {
//        setVisible(true);
//    }
//    setType("Gold");
//}
//
//void Gold::doSomething() {
//    if (!isAlive()) {
//        return;
//    }
//    if (!getPermanent()) {
//        incTick();
//        if (getTicks() == 100) {
//            setDead();
//            return;
//        }
//    }
//    if (!isVisible() && getWorld()->playerWithinFour(getX(), getY())) {
//        setVisible(true);
//        return;
//    }
//    if (!getProtesterOrPlayer() && getWorld()->playerWithinThree(getX(), getY())) {
//        setDead();
//        getWorld()->playSound(SOUND_GOT_GOODIE);
//        getWorld()->increaseScore(10);
//        getWorld()->gotGold();
//        return;
//    }
//    if (getProtesterOrPlayer()) {
//        if (getWorld()->didBribe(getX(), getY())) {
//            setDead();
//            getWorld()->playSound(SOUND_PROTESTER_FOUND_GOLD);
//        }
//    }
//}
//
//Sonar::Sonar(StudentWorld* sw, int startX, int startY, bool protesterOrPlayer, bool isPermanent, int imageID): Goodie(sw, startX, startY, false, false, imageID) {
//    setVisible(true);
//    setType("Sonar");
//    int lvl = 10*getWorld()->getLevel();
//    m_lifetime = std::max(100, 300 - lvl);
//}
//
//void Sonar::doSomething() {
//    if (!isAlive()) {
//        return;
//    }
//    if (m_lifetime == getTicks()) {
//        setDead();
//        return;
//    }
//    if (getWorld()->playerWithinThree(getX(), getY())) {
//        setDead();
//        getWorld()->playSound(SOUND_GOT_GOODIE);
//        getWorld()->increaseScore(75);
//        getWorld()->gotSonar();
//        return;
//    }
//    incTick();
//}
//
//WaterPool::WaterPool(StudentWorld* sw, int startX, int startY, int imageID): Sonar(sw, startX, startY, false, false, imageID) {
//    setType("WaterPool");
//}
//
//void WaterPool::doSomething() {
//    if (!isAlive()) {
//        return;
//    }
//    if (getTicks() == getLifetime()) {
//        setDead();
//        return;
//    }
//    if (getWorld()->playerWithinThree(getX(), getY())) {
//        setDead();
//        getWorld()->playSound(SOUND_GOT_GOODIE);
//        getWorld()->gotWater();
//        getWorld()->increaseScore(100);
//        return;
//    }
//    incTick();
//}
//
//Goodie::~Goodie() {
//}
//
//Protester::Protester(StudentWorld* sw, int startX, int startY, int numSquaresToMoveInCurrentDirection, int ticksToWait, int imageID): GameObject(imageID, startX, startY, left, 1.0, 0, sw) {
//    setVisible(true);
//    m_numSquaresToMoveInCurrentDirection = numSquaresToMoveInCurrentDirection;
//    m_leaveTheField = false;
//    m_ticksToWait = ticksToWait;
//    m_nonRestingTicks = 0;
//    m_hp = 5;
//    shoutedWithin15 = false;
//    turnWithin200 = false;
//    setType("Protester");
//    stunnedTicks = 0;
//}
//void Protester::setHP(int x) {
//    m_hp = x;
//}
//int Protester::getStunnedTicks() {
//    return stunnedTicks;
//}
//HardcoreProtester::HardcoreProtester(StudentWorld* sw, int startX, int startY, int numSquaresToMoveInCurrentDirection, int ticksToWait):Protester(sw, startX, startY, numSquaresToMoveInCurrentDirection, ticksToWait, TID_HARD_CORE_PROTESTER) {
//    setHP(20);
//    setVisible(true);
//    ticksToStare = 0;
//}
//
//void Protester::setRandDir() {
//    Direction cur = getDirection();
//    srand(time(NULL));
//    while (getDirection() == cur) {
//        int rNum = rand() % 4;
//        switch (rNum) {
//            case 0: // up
//                if (isValidPos(getX(), getY() + 1)) {
//                    setDirection(up);
//                }
//                break;
//            case 1: //down
//                if (isValidPos(getX(), getY() - 1)) {
//                    setDirection(down);
//                }
//                break;
//            case 2: // right
//                if (isValidPos(getX() + 1, getY())) {
//                    setDirection(right);
//                }
//                break;
//            case 3: // left
//                if (isValidPos(getX() - 1, getY())) {
//                    setDirection(left);
//                }
//                break;
//            default:
//                break;
//        }
//    }
//}
//
//bool Protester::moveInPerp(Direction& d) {
//    if (turnWithin200) {// did a perp turn within last 200 ticks
//        return false;
//    }
//    if (getDirection() == right || getDirection() == left) {// check up and down
//        if (isValidPos(getX(), getY() + 1)) {//checking up
//            d = up;
//            return true;
//        }
//        if (isValidPos(getX(), getY() - 1)) {//checking down
//            d = down;
//            return true;
//        }
//    }
//    if (getDirection() == down || getDirection() == up) {//check right and left
//        if (isValidPos(getX() + 1, getY())) {//checking right
//            d = right;
//            return true;
//        }
//        if (isValidPos(getX() - 1, getY())) {//checking left
//            d = left;
//            return true;
//        }
//    }
//    return false;
//}
//int Protester::getHP() {
//    return m_hp;
//}
//bool Protester::getLeaveField() {
//    return m_leaveTheField;
//}
//
//int Protester::getNonRestingTicks() {
//    return m_nonRestingTicks;
//}
//void Protester::incNonRestingTicks() {
//    m_nonRestingTicks++;
//}
//void Protester::setShoutedFalse() {
//    shoutedWithin15 = false;
//}
//int Protester::getWaitingTicks() {
//    return m_ticksToWait;
//}
//void Protester::setTurnWithinFalse() {
//    turnWithin200 = false;
//}
//
//void HardcoreProtester::doSomething() {
//    if (!isAlive()) {
//        return;
//    }
//    if (ticksToStare > 0) {
//        ticksToStare--;
//        return;
//    }
//    Protester::doSomething();
//}
//void Protester::setTurnWithinTrue() {
//    turnWithin200 = true;
//}
//void Protester::setNumSquares(int x) {
//    m_numSquaresToMoveInCurrentDirection = x;
//}
//int Protester::getNumSquares() {
//    return m_numSquaresToMoveInCurrentDirection;
//}
//void Protester::decNumSquares() {
//    m_numSquaresToMoveInCurrentDirection--;
//}
//void Protester::doSomething() {
//    if (!isAlive()) {
//        return;
//    }
//    if (stunnedTicks > 0) {
//        stunnedTicks--;
//        return;
//    }
//    if (m_hp > 0 && !m_leaveTheField) {
//        for (int i = getX(); i < getX() + 4; i++) {
//            for (int k =getY(); k< getY() + 4; k++) {
//                if (getWorld()->hasBoulder(i, k)) {
//                    m_hp = 0;
//                    getWorld()->playSound(SOUND_PROTESTER_GIVE_UP);
//                    getWorld()->increaseScore(500);
//                    return;
//                }
//            }
//        }
//    }
//    if (m_hp <= 0) {
//        m_leaveTheField = true;
//    }
//    if (m_nonRestingTicks % 20 == 0) {
//        shoutedWithin15 = false;
//    }
//    if (m_nonRestingTicks % 200 == 0) {
//        turnWithin200 = false;
//    }
//    if (getTicks() != m_ticksToWait) { //in resting state
//        incTick();
//        return;
//    }
//    resetTicks();
//    m_nonRestingTicks++;
//
//    // everything from here on means protester is not in resting state and thus we reset the ticks
//    if (m_leaveTheField) {
//        if (getX() == 60 && getY() == 60) {
//            setDead();
//            return;
//        }
//        if(path.empty()) {
//            BFS(path, getX(), getY(), 60, 60);
//        }
//        if (path.empty()) {
//            return;
//        }
//        Direction d = path.top();
//        path.pop();
//        switch(d) {
//            case up:
//                setDirection(up);
//                moveTo(getX(), getY() + 1);
//                break;
//            case right:
//                setDirection(right);
//                moveTo(getX() + 1, getY());
//                break;
//            case left:
//                setDirection(left);
//                moveTo(getX() - 1, getY());
//                break;
//            case down:
//                setDirection(down);
//                moveTo(getX(), getY() - 1);
//                break;
//            default:
//                break;
//        }
//        return;
//    }
//    if (getWorld()->playerWithinFour(getX(), getY())) {
//        switch(getDirection()) {
//            case up:
//                if (getWorld()->getPlayerY() > getY() && !shoutedWithin15) {
//                    getWorld()->playSound(SOUND_PROTESTER_YELL);
//                    getWorld()->regProtesterAnnoy();
//                    shoutedWithin15 = true;
//                    return;
//                }
//                break;
//            case left:
//                if (getWorld()->getPlayerX() < getX() && !shoutedWithin15) {
//                    getWorld()->playSound(SOUND_PROTESTER_YELL);
//                    getWorld()->regProtesterAnnoy();
//                    shoutedWithin15 = true;
//                    return;
//                }
//                break;
//            case down:
//                if (getWorld()->getPlayerY() < getY() && !shoutedWithin15) {
//                    getWorld()->playSound(SOUND_PROTESTER_YELL);
//                    getWorld()->regProtesterAnnoy();
//                    shoutedWithin15 = true;
//                    return;
//                }
//                break;
//            case right:
//                if (getWorld()->getPlayerX() > getX() && !shoutedWithin15) {
//                    getWorld()->playSound(SOUND_PROTESTER_YELL);
//                    getWorld()->regProtesterAnnoy();
//                    shoutedWithin15 = true;
//                    return;
//                }
//                break;
//            default:
//                break;
//        }
//    }
//
//    if (getID() == TID_HARD_CORE_PROTESTER) {
//        HardcoreProtester* hp = dynamic_cast<HardcoreProtester*>(this);
//        std::stack <Direction> s;
//        if (hp->DFS(s, getX(), getY(), getWorld()->getPlayerX(), getWorld()->getPlayerY())) {
//            setDirection(s.top());
//            switch(getDirection()) {
//                case up:
//                    moveTo(getX(), getY() + 1);
//                    break;
//                case down:
//                    moveTo(getX(), getY() - 1);
//                    break;
//                case right:
//                    moveTo(getX() + 1, getY());
//                    break;
//                case left:
//                    moveTo(getX() - 1, getY());
//                    break;
//                default:
//                    break;
//            }
//            return;
//        }
//    }
//
//    if (getX() == getWorld()->getPlayerX() || getY() == getWorld()->getPlayerY()) {//either vertical or horizontal line of sight
//
//        if (!getWorld()->playerWithinFour(getX(), getY())) {//Tunnelman is not within 4 units of protester
//
//            if (getX() == getWorld()->getPlayerX()) {// in the case of vertical line of sight, we just keep walking either up or down
//
//                if (getY() < getWorld()->getPlayerY()) {// must walk up
//
//                    bool canWalkUp = true;
//                    for (int i = getX(); i < getX() + 4; i++) {
//
//                        for (int k = getY(); k < getWorld()->getPlayerY(); k++) {
//
//                            if (getWorld()->hasEarth(i, k) || getWorld()->boulderNearSquirtOrPlayer(getX(), k))  {//if there is earth or boulder within radius of 3
//                                canWalkUp = false;
//                            }
//                        }
//                    }
//
//                    if (canWalkUp) {
//
//                        setDirection(up);
//
//                        moveTo(getX(), getY() + 1);
//
//                        m_numSquaresToMoveInCurrentDirection = 0;
//
//                        return;
//                    }
//                }
//                else {//must walk down
//
//                    bool canWalkDown = true;
//                    for (int i = getX(); i < getX() + 4; i++) {
//                        for (int k = getY(); k > getWorld()->getPlayerY(); k--) {
//                            if (getWorld()->hasEarth(i, k) || getWorld()->boulderNearSquirtOrPlayer(getX(), k))  {//if there is earth or boulder within radius of 3
//                                canWalkDown = false;
//                            }
//                        }
//                    }
//                    if (canWalkDown) {
//                        setDirection(down);
//                        moveTo(getX(), getY() - 1);
//                        m_numSquaresToMoveInCurrentDirection = 0;
//                        return;
//                    }
//                }
//            }
//            else {//in the case of horizontal line of sight, we just keep walking either left or right
//                if (getX() < getWorld()->getPlayerX()) {//we must walk right
//                    bool canWalkRight = true;
//                    for (int i = getX(); i < getWorld()->getPlayerX(); i++) {
//                        for (int k = getY(); k < getY() + 4; k++) {
//                            if (getWorld()->hasEarth(i, k) || getWorld()->boulderNearSquirtOrPlayer(i, getY()))  {//if there is earth or boulder within radius of 3
//                                canWalkRight = false;
//                            }
//                        }
//                    }
//                    if (canWalkRight) {
//                        setDirection(right);
//                        moveTo(getX() + 1, getY());
//                        m_numSquaresToMoveInCurrentDirection = 0;
//                        return;
//                    }
//                }
//                else {// we must walk left
//                    bool canWalkLeft = true;
//                    for (int i = getX(); i > getWorld()->getPlayerX(); i--) {
//                        for (int k = getY(); k < getY() + 4; k++) {
//                            if (getWorld()->hasEarth(i, k) || getWorld()->boulderNearSquirtOrPlayer(i, getY()))  {//if there is earth or boulder within radius of 3
//                                canWalkLeft = false;
//                            }
//                        }
//                    }
//                    if (canWalkLeft) {
//                        setDirection(left);
//                        moveTo(getX() - 1, getY());
//                        m_numSquaresToMoveInCurrentDirection = 0;
//                        return;
//                    }
//                }
//            }
//        }
//    }
//    m_numSquaresToMoveInCurrentDirection--;
//    if (m_numSquaresToMoveInCurrentDirection <= 0) {
//        setRandDir();
//        srand(time(NULL));
//        int randNum = rand() % 53 + 8;
//        m_numSquaresToMoveInCurrentDirection = randNum; // choose random num squares to move in after choosing a random direction
//    }
//    else {
//        Direction d;
//        if (moveInPerp(d)) {
//            srand(time(NULL));
//            int randNum = rand() % 53 + 8;
//            m_numSquaresToMoveInCurrentDirection = randNum;
//            turnWithin200 = true;
//            setDirection(d);
//        }
//    }
//    switch(getDirection()) { //move in the direction if possible, otherwise set numsquares to zero and do nothing
//        case up:
//            if(isValidPos(getX(), getY() + 1)) {
//                moveTo(getX(), getY() + 1);
//                return;
//            }
//            break;
//        case down:
//            if(isValidPos(getX(), getY() - 1)) {
//                moveTo(getX(), getY() - 1);
//                return;
//            }
//            break;
//        case left:
//            if (isValidPos(getX() - 1, getY())) {
//                moveTo(getX() - 1, getY());
//                return;
//            }
//            break;
//        case right:
//            if (isValidPos(getX() + 1, getY())) {
//                moveTo(getX() + 1, getY());
//                return;
//            }
//            break;
//        default:
//            break;
//    }
//    m_numSquaresToMoveInCurrentDirection = 0;
//}
//
//bool Protester::isValidPos(int x, int y) {
//    for (int i = x; i < x + 4; i++) {
//        for (int k = y; k < y + 4; k++)  {
//            if (i > 63 || k > 63 || i < 0 || k < 0) {
//                return false;
//            }
//            if (getWorld()->hasEarth(i, k) || getWorld()->hasBoulder(i, k)) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//bool Goodie::getProtesterOrPlayer() {
//    return m_protesterOrPlayer;
//}
//bool Goodie::getPermanent() {
//    return m_permanent;
//}
//int TunnelMan::getHealth() const {
//    return m_hitpoints;
//}
//int TunnelMan::getSquirts() const {
//    return m_water;
//}
//int TunnelMan::getSonar() const {
//    return m_sonar;
//}
//int TunnelMan::getGold() const {
//    return m_gnugget;
//}
//void TunnelMan::incGold() {
//    m_gnugget += 1;
//}
//void TunnelMan::incSonar() {
//    m_sonar += 2;
//}
//void TunnelMan::incWater() {
//    m_water += 5;
//}
//void TunnelMan::decSonar() {
//    m_sonar -= 1;
//}
//void TunnelMan::decHealth(int x) {
//    m_hitpoints -= x;
//}
//StudentWorld* GameObject::getWorld() {
//    return m_StudentWorld;
//}
//bool GameObject:: isAlive() const {
//    return m_alive;
//}
//void GameObject::setDead() {
//    m_alive = false;
//}
//int GameObject::getTicks() const {
//    return m_ticks;
//}
//void GameObject::incTick() {
//    m_ticks++;
//}
//void GameObject::resetTicks() {
//    m_ticks = 0;
//}
//std::string GameObject::getType() const {
//    return m_type;
//}
//void GameObject::setType(std::string type) {
//    m_type = type;
//}
//GameObject::GameObject(int imageID, int startX, int startY, Direction dir, double size, unsigned int depth, StudentWorld* sw):GraphObject(imageID, startX, startY, dir, size, depth) {
//    m_StudentWorld = sw;
//    m_alive = true;
//    m_ticks = 0;
//    setVisible(true);
//}
//Goodie::Goodie(StudentWorld* sw, int startX, int startY, bool protesterOrPlayer, bool isPermanent, int imageID):  GameObject(imageID, startX, startY, right, 1, 2,sw) {
//    m_permanent = isPermanent;
//    m_protesterOrPlayer = protesterOrPlayer;// if true then pickupable by protester, if false, pickupable by player
//}
//
//bool HardcoreProtester::DFS(std::stack<Direction> &p, int startX, int startY, int endX, int endY) {
//    if (startX == endX && startY == endY) {
//        return false;
//    }
//    int lvl = getWorld()->getLevel();
//    lvl*=2;
//    int M = 16 + lvl;
//    if (sqrt((endX - startX)*(endX - startX) + (endY - startY)*(endY - startY)) > M) {
//        return false;
//    }
//    std::stack <int> curx;
//    std::stack <int> cury;
//    curx.push(startX);
//    cury.push(startY);
//    bool discovered[64][64];
//    for (int i = 0; i < 64; i++) {
//        for (int k = 0; k < 64; k++) {
//            discovered[i][k] = false;
//        }
//    }
//    discovered[startX][startY] = true;
//    while (curx.top() != endX || cury.top() != endY) {
//        if (isValidPos(curx.top(), cury.top() + 1) && discovered[curx.top()][cury.top() + 1] == false) { // check up
//            curx.push(curx.top());
//            cury.push(cury.top() + 1);
//            discovered[curx.top()][cury.top()] = true;
//            continue;
//        }
//        if (isValidPos(curx.top() + 1, cury.top()) && discovered[curx.top() + 1][cury.top()] == false) { // check right
//            curx.push(curx.top() + 1);
//            cury.push(cury.top());
//            discovered[curx.top()][cury.top()] = true;
//            continue;
//        }
//        if (isValidPos(curx.top() - 1, cury.top()) && discovered[curx.top() - 1][cury.top()] == false) { // check left
//            curx.push(curx.top() - 1);
//            cury.push(cury.top());
//            discovered[curx.top()][cury.top()] = true;
//            continue;
//        }
//        if (isValidPos(curx.top(), cury.top() - 1) && discovered[curx.top()][cury.top() - 1] == false) { // check down
//            curx.push(curx.top());
//            cury.push(cury.top() - 1);
//            discovered[curx.top()][cury.top()] = true;
//            continue;
//        }
//        //otherwise we hit a dead end, so pop off most recent point to backtrack
//        curx.pop();
//        cury.pop();
//        if (curx.empty() || cury.empty()) {
//            return false;
//        }
//    }
//    //now we must decode stack into directions and push onto our directional stack
//    while (curx.size() >= 2) {
//        int x2 = curx.top();
//        int y2 = cury.top();
//        curx.pop();
//        cury.pop();
//        int x = curx.top();
//        int y = cury.top();
//        if (x2 == x) {//we either moved up or down
//            if (y2 > y) {// we moved up
//                p.push(up);
//                continue;
//            }// otherwise we moved down
//            p.push(down);
//            continue;
//        }
//        //otherwise we either moved right or left
//        if (x2 > x) {//we moved right
//            p.push(right);
//            continue;
//        }//otherwise we moved left
//        p.push(left);
//    }
//    if (p.size() <= M) {
//        return true;
//    }
//    return false;
//}
//
//void Protester::BFS(std::stack<Direction> &p, int startX, int startY, int endX, int endY) {
//    if (startX == endX && startY == endY) {
//        return;
//    }
//    std::queue<int> curx;
//    std::queue<int> cury;
//
//    curx.push(startX);
//    cury.push(startY);
//
//    bool discovered[64][64];
//    for (int i = 0; i < 64; i++) {
//        for (int k = 0; k < 64; k++) {
//            discovered[i][k] = false;
//        }
//    }
//    discovered[startX][startY] = true;
//    std::pair<int, int> path[64][64];
//    int currentX = startX;
//    int currentY = startY;
//    path[currentX][currentY].first = -99;
//    path[currentX][currentY].second = -99;
//    while (!curx.empty())
//    {
//        currentX = curx.front();
//        currentY = cury.front();
//        if (currentX == endX && currentY == endY) {
//            break;
//        }
//        curx.pop();
//        cury.pop();
//        if (isValidPos(currentX, currentY + 1) && !discovered[currentX][currentY + 1]) // check up
//        {
//            discovered[currentX][currentY] = true;
//            curx.push(currentX);
//            cury.push(currentY + 1);
//            path[currentX][currentY + 1].first = currentX;
//            path[currentX][currentY + 1].second = currentY;
//        }
//        if (isValidPos(currentX + 1, currentY) && !discovered[currentX + 1][currentY]) // check right
//        {
//            discovered[currentX][currentY] = true;
//            curx.push(currentX + 1);
//            cury.push(currentY);
//            path[currentX + 1][currentY].first = currentX;
//            path[currentX + 1][currentY].second = currentY;
//        }
//        if (isValidPos(currentX, currentY - 1) && !discovered[currentX][currentY - 1]) // check down
//        {
//            discovered[currentX][currentY] = true;
//            curx.push(currentX);
//            cury.push(currentY - 1);
//            path[currentX][currentY - 1].first = currentX;
//            path[currentX][currentY - 1].second = currentY;
//        }
//        if (isValidPos(currentX - 1, currentY) && !discovered[currentX - 1][currentY]) // check left
//        {
//            discovered[currentX][currentY] = true;
//            curx.push(currentX - 1);
//            cury.push(currentY);
//            path[currentX - 1][currentY].first = currentX;
//            path[currentX - 1][currentY].second = currentY;
//        }
//    }
//    int i = currentX;
//    int j = currentY;
//    while (path[i][j].first != -99) {
//        int x = path[i][j].first;
//        int y = path[i][j].second;
//        if (i == x) {//we either moved up or down
//            if (j > y) {// we moved up
//                p.push(up);
//                j -= 1;
//                continue;
//            }// otherwise we moved down
//            p.push(down);
//            j += 1;
//            continue;
//        }
//        //otherwise we either moved right or left
//        if (i > x) {//we moved right
//            p.push(right);
//            i -= 1;
//            continue;
//        }//otherwise we moved left
//        i += 1;
//        p.push(left);
//    }
//}
//
//void Protester::setLeaveField() {
//    m_leaveTheField = true;
//}
//
//void Protester::annoy(int x) {
//    if (m_hp <= 0) {
//        return;
//    }
//    m_hp -= x;
//    if (m_hp > 0) {
//        getWorld()->playSound(SOUND_PROTESTER_ANNOYED);
//        int level = getWorld()->getLevel();
//        int rightHand = 100 - level* 10;
//        stunnedTicks = std::max(50, rightHand);
//    }
//    if (m_hp <= 0) {
//        getWorld()->playSound(SOUND_PROTESTER_GIVE_UP);
//        if (getID() == TID_PROTESTER) {
//            getWorld()->increaseScore(100);
//        }
//        if (getID() == TID_HARD_CORE_PROTESTER) {
//            getWorld()->increaseScore(250);
//        }
//        stunnedTicks = 0;
//        setLeaveField();
//    }
//}
//
//void HardcoreProtester::setTicksToStare(int x) {
//    ticksToStare = x;
//}
//int HardcoreProtester::getTicksToStare() {
//    return ticksToStare;
//}
#include "Actor.h"
#include <algorithm>

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp
Earth::Earth(StudentWorld* sw, int startX, int startY):
GameObject(TID_EARTH,startX,startY, right, 0.25, 3, sw) {
    GameObject* g = getWorld()->setEarth(startX, startY);
    g = this;
    setType("Earth");
}

TunnelMan::TunnelMan(StudentWorld* sw): GameObject(TID_PLAYER, 30, 60, right, 1.0, 0, sw) {
    m_hitpoints = 10;
    m_water = 5;
    m_sonar = 1;
    m_gnugget = 0;
    setType("TunnelMan");
}

void TunnelMan::doSomething() {
    if (m_hitpoints <= 0) {
        setDead();
        getWorld()->playSound(SOUND_PLAYER_GIVE_UP);
        return;
    }
    if (getWorld()->boulderNearSquirtOrPlayer(getX(), getY())) {
        setDead();
        getWorld()->playSound(SOUND_PLAYER_GIVE_UP);
        return;
    }
    int ch;
    if (getWorld()->getKey(ch) == true) {
        switch(ch) {
            case KEY_PRESS_LEFT:
                if (getDirection() != left) {
                    setDirection(left);
                }
                else if (getX() - 1 < 0) {
                    break;
                }
                else if (boulderNearby(getX() -1 , getY())) {
                    break;
                }
                else {
                    moveTo(getX() - 1, getY());
                    getWorld()->checkCollision();
                }
                break;
            case KEY_PRESS_RIGHT:
                if (getDirection() != right) {
                    setDirection(right);
                }
                else if (getX() +  1 > 60) {
                    break;
                }
                else if (boulderNearby(getX() +1 , getY())) {
                    break;
                }
                else {
                    moveTo(getX() + 1, getY());
                    getWorld()->checkCollision();
                }
                break;
            case KEY_PRESS_UP:
                if (getDirection() != up) {
                    setDirection(up);
                }
                else if(getY() + 1 > 60) {
                    break;
                }
                else if (boulderNearby(getX() , getY() + 1)) {
                    break;
                }
                else {
                    moveTo(getX(), getY() + 1);
                    getWorld()->checkCollision();
                }
                break;
            case KEY_PRESS_DOWN:
                if (getDirection() != down) {
                    setDirection(down);
                }
                else if(getY() -1 < 0) {
                    break;
                }
                else if (boulderNearby(getX() , getY() - 1)) {
                    break;
                }
                else {
                    moveTo(getX(), getY() - 1);
                    getWorld()->checkCollision();
                }
                break;
            case KEY_PRESS_ESCAPE:
                setDead();
                break;
            case KEY_PRESS_SPACE:
                if (getSquirts() <= 0)
                    break;
                getWorld()->playSound(SOUND_PLAYER_SQUIRT);
                m_water--;
                if (getDirection() == up) {
                    new Squirt(getWorld(), getX(), getY() + 4, up);
                }
                else if(getDirection() == down) {
                    new Squirt(getWorld(), getX(), getY() - 4, down);
                }
                else if (getDirection() == right) {
                    new Squirt(getWorld(), getX() + 4, getY(), right);
                }
                else {
                    new Squirt(getWorld(), getX() - 4, getY(), left);
                }
                break;
            case 'Z':
                if (getSonar() > 0) {
                    getWorld()->useSonar();
                    getWorld()->playSound(SOUND_SONAR);
                }
                break;
            case 'z':
                if (getSonar() > 0) {
                    getWorld()->useSonar();
                    getWorld()->playSound(SOUND_SONAR);
                }
                break;
            case KEY_PRESS_TAB:
                if (m_gnugget >= 1) {
                    getWorld()->insertObject(new Gold(getWorld(), getX(), getY(), true, true, false));
                    m_gnugget--;
                }
                break;
            default:
                break;
        }
    }
}

Boulder::Boulder(StudentWorld* sw, int startX, int startY): GameObject(TID_BOULDER, startX, startY, down, 1.0, 1, sw) {
    m_state = "stable";
    setType("Boulder");
}

void Boulder::doSomething() {
    if (!isAlive()) {
        setVisible(false);
        return;
    }
    if (m_state == "stable") {
        if (getWorld()->hasEarth(getX(), getY() - 1) || getWorld()->hasEarth(getX() +1 , getY() - 1) || getWorld()->hasEarth(getX() +2, getY() - 1) || getWorld()->hasEarth(getX() + 3, getY() - 1)) {
            return;
        }
        m_state = "waiting";
    }
    else if (m_state == "waiting") {
        incTick();
        if (getTicks() == 30) {
            m_state = "falling";
            getWorld()->playSound(SOUND_FALLING_ROCK);
        }
    }
    else {
        if (getWorld()->hasEarth(getX() + 1, getY()) ||getWorld()->hasEarth(getX() + 2, getY()) || getWorld()->hasEarth(getX() + 3, getY()) || getY() - 1 < 0 || getWorld()->hasEarth(getX(), getY() - 1) || getWorld()->hasBoulder(getX(), getY() - 5)) { // make sure boulders spawn greater than 4 tiles above/below other boulders
            setDead();
            return;
        }
        else {
            moveTo(getX(), getY() - 1);
        }
    }
}

bool TunnelMan::boulderNearby(int x, int y) {
    for (int xi = x; xi < x + 4; xi++) {
        for (int yi = y; yi < y + 4; yi++) {
            if (getWorld()->hasBoulder(xi, yi)) {
                return true;
            }
        }
    }
    return false;
}
Squirt::Squirt(StudentWorld* sw, int startX, int startY, Direction dir): GameObject(TID_WATER_SPURT, startX, startY, dir, 1.0, 1, sw) {
    initialTravelDistance = 4;
    getWorld()->insertObject(this); // everything is automaticlly inserted in the init but this is not, so we need to manually insert
    setType("Squirt");
}

void Squirt::doSomething() {
    
    getWorld()->animateSquirt(this);
    
    if (getX() > 60 || getX() < 0 || getY() > 60 || getY() < 0) {
        setDead();
    }
    
    if (!isAlive()) {
        return;
    }
    
    if (initialTravelDistance == 0) {
        setDead();
        return;
    }
    switch(getDirection()) {
        case left:
            if (getY() != 60) {
                if (earthNearby(getX() - 1, getY())) {
                    setDead();
                    break;
                }
            }
            moveTo(getX() - 1, getY());
            initialTravelDistance--;
            return;
        case right:
            if (getY() != 60) {
                if (earthNearby(getX() + 1, getY())) {
                    setDead();
                    break;
                }
            }
            moveTo(getX() + 1, getY());
            initialTravelDistance--;
            return;
        case up:
            if (earthNearby(getX(), getY() + 1)) {
                setDead();
                break;
            }
            moveTo(getX(), getY() + 1);
            initialTravelDistance--;
            return;
        case down:
            if (earthNearby(getX(), getY() - 1) ) {
                setDead();
                break;
            }
            moveTo(getX(), getY() - 1);
            initialTravelDistance--;
            return;
        default:
            break;
    }
}

bool Squirt::earthNearby(int x, int y) {
    
    for (int i = x; i < x + 4; i++) {
        for (int k = y; k < y + 4; k++) {
            if (i > 63 || k > 59 || i < 0 || k < 0) {
                continue;
            }
            if (getWorld()->hasEarth(i, k)) {
                return true;
            }
        }
    }
    return false;
}

bool Squirt::boulderNearby(int x, int y) {
    return getWorld()->boulderNearSquirtOrPlayer(x, y);
}

Barrel::Barrel(StudentWorld* sw, int startX, int startY): GameObject(TID_BARREL, startX, startY, right, 1.0, 2, sw) {
    setType("Barrel");
    setVisible(false);
}

void Barrel::doSomething() {
    if (!isAlive()) {
        return;
    }
    if (getWorld()->playerWithinFour(getX(), getY()) && !isVisible()) {
        setVisible(true);
        return;
    }
    
    if (getWorld()->playerWithinThree(getX(), getY())) {
        setDead();
        getWorld()->playSound(SOUND_FOUND_OIL);
        getWorld()->increaseScore(1000);
    }
    
}

Gold::Gold(StudentWorld* sw, int startX, int startY, bool isVisible,bool protesterOrPlayer, bool isPermanent): Goodie(sw, startX, startY,  protesterOrPlayer, isPermanent, TID_GOLD) {
    setVisible(false);
    if (isVisible) {
        setVisible(true);
    }
    setType("Gold");
}

void Gold::doSomething() {
    if (!isAlive()) {
        return;
    }
    if (!getPermanent()) {
        incTick();
        if (getTicks() == 100) {
            setDead();
            return;
        }
    }
    if (!isVisible() && getWorld()->playerWithinFour(getX(), getY())) {
        setVisible(true);
        return;
    }
    if (!getProtesterOrPlayer() && getWorld()->playerWithinThree(getX(), getY())) {
        setDead();
        getWorld()->playSound(SOUND_GOT_GOODIE);
        getWorld()->increaseScore(10);
        getWorld()->gotGold();
        return;
    }
    if (getProtesterOrPlayer()) {
        if (getWorld()->didBribe(getX(), getY())) {
            setDead();
            getWorld()->playSound(SOUND_PROTESTER_FOUND_GOLD);
        }
    }
}

Sonar::Sonar(StudentWorld* sw, int startX, int startY, bool protesterOrPlayer, bool isPermanent, int imageID): Goodie(sw, startX, startY, false, false, imageID) {
    setVisible(true);
    setType("Sonar");
    int lvl = 10*getWorld()->getLevel();
    m_lifetime = std::max(100, 300 - lvl);
}

void Sonar::doSomething() {
    if (!isAlive()) {
        return;
    }
    if (m_lifetime == getTicks()) {
        setDead();
        return;
    }
    if (getWorld()->playerWithinThree(getX(), getY())) {
        setDead();
        getWorld()->playSound(SOUND_GOT_GOODIE);
        getWorld()->increaseScore(75);
        getWorld()->gotSonar();
        return;
    }
    incTick();
}

WaterPool::WaterPool(StudentWorld* sw, int startX, int startY, int imageID): Sonar(sw, startX, startY, false, false, imageID) {
    setType("WaterPool");
}

void WaterPool::doSomething() {
    if (!isAlive()) {
        return;
    }
    if (getTicks() == getLifetime()) {
        setDead();
        return;
    }
    if (getWorld()->playerWithinThree(getX(), getY())) {
        setDead();
        getWorld()->playSound(SOUND_GOT_GOODIE);
        getWorld()->gotWater();
        getWorld()->increaseScore(100);
        return;
    }
    incTick();
}

Goodie::~Goodie() {
}

Protester::Protester(StudentWorld* sw, int startX, int startY, int numSquaresToMoveInCurrentDirection, int ticksToWait, int imageID): GameObject(imageID, startX, startY, left, 1.0, 0, sw) {
    setVisible(true);
    m_numSquaresToMoveInCurrentDirection = numSquaresToMoveInCurrentDirection;
    m_leaveTheField = false;
    m_ticksToWait = ticksToWait;
    m_nonRestingTicks = 0;
    m_hp = 5;
    shoutedWithin15 = false;
    turnWithin200 = false;
    setType("Protester");
    stunnedTicks = 0;
}
void Protester::setHP(int x) {
    m_hp = x;
}
int Protester::getStunnedTicks() {
    return stunnedTicks;
}
HardcoreProtester::HardcoreProtester(StudentWorld* sw, int startX, int startY, int numSquaresToMoveInCurrentDirection, int ticksToWait):Protester(sw, startX, startY, numSquaresToMoveInCurrentDirection, ticksToWait, TID_HARD_CORE_PROTESTER) {
    setHP(20);
    setVisible(true);
    ticksToStare = 0;
}

void Protester::setRandDir() {
    Direction cur = getDirection();
    srand(time(NULL));
    while (getDirection() == cur) {
        int rNum = rand() % 4;
        switch (rNum) {
            case 0: // up
                if (isValidPos(getX(), getY() + 1)) {
                    setDirection(up);
                }
                break;
            case 1: //down
                if (isValidPos(getX(), getY() - 1)) {
                    setDirection(down);
                }
                break;
            case 2: // right
                if (isValidPos(getX() + 1, getY())) {
                    setDirection(right);
                }
                break;
            case 3: // left
                if (isValidPos(getX() - 1, getY())) {
                    setDirection(left);
                }
                break;
            default:
                break;
        }
    }
}

bool Protester::moveInPerp(Direction& d) {
    if (turnWithin200) {// did a perp turn within last 200 ticks
        return false;
    }
    if (getDirection() == right || getDirection() == left) {// check up and down
        if (isValidPos(getX(), getY() + 1)) {//checking up
            d = up;
            return true;
        }
        if (isValidPos(getX(), getY() - 1)) {//checking down
            d = down;
            return true;
        }
    }
    if (getDirection() == down || getDirection() == up) {//check right and left
        if (isValidPos(getX() + 1, getY())) {//checking right
            d = right;
            return true;
        }
        if (isValidPos(getX() - 1, getY())) {//checking left
            d = left;
            return true;
        }
    }
    return false;
}
int Protester::getHP() {
    return m_hp;
}
bool Protester::getLeaveField() {
    return m_leaveTheField;
}

int Protester::getNonRestingTicks() {
    return m_nonRestingTicks;
}
void Protester::incNonRestingTicks() {
    m_nonRestingTicks++;
}
void Protester::setShoutedFalse() {
    shoutedWithin15 = false;
}
int Protester::getWaitingTicks() {
    return m_ticksToWait;
}
void Protester::setTurnWithinFalse() {
    turnWithin200 = false;
}

void HardcoreProtester::doSomething() {
    if (!isAlive()) {
        return;
    }
    if (ticksToStare > 0) {
        ticksToStare--;
        return;
    }
    Protester::doSomething();
}
void Protester::setTurnWithinTrue() {
    turnWithin200 = true;
}
void Protester::setNumSquares(int x) {
    m_numSquaresToMoveInCurrentDirection = x;
}
int Protester::getNumSquares() {
    return m_numSquaresToMoveInCurrentDirection;
}
void Protester::decNumSquares() {
    m_numSquaresToMoveInCurrentDirection--;
}
void Protester::doSomething() {
    if (!isAlive()) {
        return;
    }
    if (stunnedTicks > 0) {
        stunnedTicks--;
        return;
    }
    if (m_hp > 0 && !m_leaveTheField) {
        for (int i = getX(); i < getX() + 4; i++) {
            for (int k =getY(); k< getY() + 4; k++) {
                if (getWorld()->hasBoulder(i, k)) {
                    m_hp = 0;
                    getWorld()->playSound(SOUND_PROTESTER_GIVE_UP);
                    getWorld()->increaseScore(500);
                    return;
                }
            }
        }
    }
    if (m_hp <= 0) {
        m_leaveTheField = true;
    }
    if (m_nonRestingTicks % 20 == 0) {
        shoutedWithin15 = false;
    }
    if (m_nonRestingTicks % 200 == 0) {
        turnWithin200 = false;
    }
    if (getTicks() != m_ticksToWait) { //in resting state
        incTick();
        return;
    }
    resetTicks();
    m_nonRestingTicks++;
    
    // everything from here on means protester is not in resting state and thus we reset the ticks
    if (m_leaveTheField) {
        if (getX() == 60 && getY() == 60) {
            setDead();
            return;
        }
        if(path.empty()) {
            BFS(path, getX(), getY(), 60, 60);
        }
        if (path.empty()) {
            return;
        }
        Direction d = path.top();
        path.pop();
        switch(d) {
            case up:
                setDirection(up);
                moveTo(getX(), getY() + 1);
                break;
            case right:
                setDirection(right);
                moveTo(getX() + 1, getY());
                break;
            case left:
                setDirection(left);
                moveTo(getX() - 1, getY());
                break;
            case down:
                setDirection(down);
                moveTo(getX(), getY() - 1);
                break;
            default:
                break;
        }
        return;
    }
    if (getWorld()->playerWithinFour(getX(), getY())) {
        switch(getDirection()) {
            case up:
                if (getWorld()->getPlayerY() > getY() && !shoutedWithin15) {
                    getWorld()->playSound(SOUND_PROTESTER_YELL);
                    getWorld()->regProtesterAnnoy();
                    shoutedWithin15 = true;
                    return;
                }
                break;
            case left:
                if (getWorld()->getPlayerX() < getX() && !shoutedWithin15) {
                    getWorld()->playSound(SOUND_PROTESTER_YELL);
                    getWorld()->regProtesterAnnoy();
                    shoutedWithin15 = true;
                    return;
                }
                break;
            case down:
                if (getWorld()->getPlayerY() < getY() && !shoutedWithin15) {
                    getWorld()->playSound(SOUND_PROTESTER_YELL);
                    getWorld()->regProtesterAnnoy();
                    shoutedWithin15 = true;
                    return;
                }
                break;
            case right:
                if (getWorld()->getPlayerX() > getX() && !shoutedWithin15) {
                    getWorld()->playSound(SOUND_PROTESTER_YELL);
                    getWorld()->regProtesterAnnoy();
                    shoutedWithin15 = true;
                    return;
                }
                break;
            default:
                break;
        }
    }
    
    if (getID() == TID_HARD_CORE_PROTESTER) {
        HardcoreProtester* hp = dynamic_cast<HardcoreProtester*>(this);
        std::stack <Direction> s;
        if (hp->DFS(s, getX(), getY(), getWorld()->getPlayerX(), getWorld()->getPlayerY())) {
            setDirection(s.top());
            switch(getDirection()) {
                case up:
                    moveTo(getX(), getY() + 1);
                    break;
                case down:
                    moveTo(getX(), getY() - 1);
                    break;
                case right:
                    moveTo(getX() + 1, getY());
                    break;
                case left:
                    moveTo(getX() - 1, getY());
                    break;
                default:
                    break;
            }
            return;
        }
    }
    
    if (getX() == getWorld()->getPlayerX() || getY() == getWorld()->getPlayerY()) {//either vertical or horizontal line of sight
        
        if (!getWorld()->playerWithinFour(getX(), getY())) {//Tunnelman is not within 4 units of protester
            
            if (getX() == getWorld()->getPlayerX()) {// in the case of vertical line of sight, we just keep walking either up or down
                
                if (getY() < getWorld()->getPlayerY()) {// must walk up
                    
                    bool canWalkUp = true;
                    for (int i = getX(); i < getX() + 4; i++) {
                        
                        for (int k = getY(); k < getWorld()->getPlayerY(); k++) {
                            
                            if (getWorld()->hasEarth(i, k) || getWorld()->boulderNearSquirtOrPlayer(getX(), k))  {//if there is earth or boulder within radius of 3
                                canWalkUp = false;
                            }
                        }
                    }
                    
                    if (canWalkUp) {
                        
                        setDirection(up);
                        
                        moveTo(getX(), getY() + 1);
                        
                        m_numSquaresToMoveInCurrentDirection = 0;
                        
                        return;
                    }
                }
                else {//must walk down
                    
                    bool canWalkDown = true;
                    for (int i = getX(); i < getX() + 4; i++) {
                        for (int k = getY(); k > getWorld()->getPlayerY(); k--) {
                            if (getWorld()->hasEarth(i, k) || getWorld()->boulderNearSquirtOrPlayer(getX(), k))  {//if there is earth or boulder within radius of 3
                                canWalkDown = false;
                            }
                        }
                    }
                    if (canWalkDown) {
                        setDirection(down);
                        moveTo(getX(), getY() - 1);
                        m_numSquaresToMoveInCurrentDirection = 0;
                        return;
                    }
                }
            }
            else {//in the case of horizontal line of sight, we just keep walking either left or right
                if (getX() < getWorld()->getPlayerX()) {//we must walk right
                    bool canWalkRight = true;
                    for (int i = getX(); i < getWorld()->getPlayerX(); i++) {
                        for (int k = getY(); k < getY() + 4; k++) {
                            if (getWorld()->hasEarth(i, k) || getWorld()->boulderNearSquirtOrPlayer(i, getY()))  {//if there is earth or boulder within radius of 3
                                canWalkRight = false;
                            }
                        }
                    }
                    if (canWalkRight) {
                        setDirection(right);
                        moveTo(getX() + 1, getY());
                        m_numSquaresToMoveInCurrentDirection = 0;
                        return;
                    }
                }
                else {// we must walk left
                    bool canWalkLeft = true;
                    for (int i = getX(); i > getWorld()->getPlayerX(); i--) {
                        for (int k = getY(); k < getY() + 4; k++) {
                            if (getWorld()->hasEarth(i, k) || getWorld()->boulderNearSquirtOrPlayer(i, getY()))  {//if there is earth or boulder within radius of 3
                                canWalkLeft = false;
                            }
                        }
                    }
                    if (canWalkLeft) {
                        setDirection(left);
                        moveTo(getX() - 1, getY());
                        m_numSquaresToMoveInCurrentDirection = 0;
                        return;
                    }
                }
            }
        }
    }
    m_numSquaresToMoveInCurrentDirection--;
    if (m_numSquaresToMoveInCurrentDirection <= 0) {
        setRandDir();
        srand(time(NULL));
        int randNum = rand() % 53 + 8;
        m_numSquaresToMoveInCurrentDirection = randNum; // choose random num squares to move in after choosing a random direction
    }
    else {
        Direction d;
        if (moveInPerp(d)) {
            srand(time(NULL));
            int randNum = rand() % 53 + 8;
            m_numSquaresToMoveInCurrentDirection = randNum;
            turnWithin200 = true;
            setDirection(d);
        }
    }
    switch(getDirection()) { //move in the direction if possible, otherwise set numsquares to zero and do nothing
        case up:
            if(isValidPos(getX(), getY() + 1)) {
                moveTo(getX(), getY() + 1);
                return;
            }
            break;
        case down:
            if(isValidPos(getX(), getY() - 1)) {
                moveTo(getX(), getY() - 1);
                return;
            }
            break;
        case left:
            if (isValidPos(getX() - 1, getY())) {
                moveTo(getX() - 1, getY());
                return;
            }
            break;
        case right:
            if (isValidPos(getX() + 1, getY())) {
                moveTo(getX() + 1, getY());
                return;
            }
            break;
        default:
            break;
    }
    m_numSquaresToMoveInCurrentDirection = 0;
}

bool Protester::isValidPos(int x, int y) {
    for (int i = x; i < x + 4; i++) {
        for (int k = y; k < y + 4; k++)  {
            if (i > 63 || k > 63 || i < 0 || k < 0) {
                return false;
            }
            if (getWorld()->hasEarth(i, k) || getWorld()->hasBoulder(i, k)) {
                return false;
            }
        }
    }
    return true;
}

bool Goodie::getProtesterOrPlayer() {
    return m_protesterOrPlayer;
}
bool Goodie::getPermanent() {
    return m_permanent;
}
int TunnelMan::getHealth() const {
    return m_hitpoints;
}
int TunnelMan::getSquirts() const {
    return m_water;
}
int TunnelMan::getSonar() const {
    return m_sonar;
}
int TunnelMan::getGold() const {
    return m_gnugget;
}
void TunnelMan::incGold() {
    m_gnugget += 1;
}
void TunnelMan::incSonar() {
    m_sonar += 2;
}
void TunnelMan::incWater() {
    m_water += 5;
}
void TunnelMan::decSonar() {
    m_sonar -= 1;
}
void TunnelMan::decHealth(int x) {
    m_hitpoints -= x;
}
StudentWorld* GameObject::getWorld() {
    return m_StudentWorld;
}
bool GameObject:: isAlive() const {
    return m_alive;
}
void GameObject::setDead() {
    m_alive = false;
}
int GameObject::getTicks() const {
    return m_ticks;
}
void GameObject::incTick() {
    m_ticks++;
}
void GameObject::resetTicks() {
    m_ticks = 0;
}
std::string GameObject::getType() const {
    return m_type;
}
void GameObject::setType(std::string type) {
    m_type = type;
}
GameObject::GameObject(int imageID, int startX, int startY, Direction dir, double size, unsigned int depth, StudentWorld* sw):GraphObject(imageID, startX, startY, dir, size, depth) {
    m_StudentWorld = sw;
    m_alive = true;
    m_ticks = 0;
    setVisible(true);
}
Goodie::Goodie(StudentWorld* sw, int startX, int startY, bool protesterOrPlayer, bool isPermanent, int imageID):  GameObject(imageID, startX, startY, right, 1, 2,sw) {
    m_permanent = isPermanent;
    m_protesterOrPlayer = protesterOrPlayer;// if true then pickupable by protester, if false, pickupable by player
}

bool HardcoreProtester::DFS(std::stack<Direction> &p, int startX, int startY, int endX, int endY) {
    if (startX == endX && startY == endY) {
        return false;
    }
    int lvl = getWorld()->getLevel();
    lvl*=2;
    int M = 16 + lvl;
    if (sqrt((endX - startX)*(endX - startX) + (endY - startY)*(endY - startY)) > M) {
        return false;
    }
    std::stack <int> curx;
    std::stack <int> cury;
    curx.push(startX);
    cury.push(startY);
    bool discovered[64][64];
    for (int i = 0; i < 64; i++) {
        for (int k = 0; k < 64; k++) {
            discovered[i][k] = false;
        }
    }
    discovered[startX][startY] = true;
    while (curx.top() != endX || cury.top() != endY) {
        if (isValidPos(curx.top(), cury.top() + 1) && discovered[curx.top()][cury.top() + 1] == false) { // check up
            curx.push(curx.top());
            cury.push(cury.top() + 1);
            discovered[curx.top()][cury.top()] = true;
            continue;
        }
        if (isValidPos(curx.top() + 1, cury.top()) && discovered[curx.top() + 1][cury.top()] == false) { // check right
            curx.push(curx.top() + 1);
            cury.push(cury.top());
            discovered[curx.top()][cury.top()] = true;
            continue;
        }
        if (isValidPos(curx.top() - 1, cury.top()) && discovered[curx.top() - 1][cury.top()] == false) { // check left
            curx.push(curx.top() - 1);
            cury.push(cury.top());
            discovered[curx.top()][cury.top()] = true;
            continue;
        }
        if (isValidPos(curx.top(), cury.top() - 1) && discovered[curx.top()][cury.top() - 1] == false) { // check down
            curx.push(curx.top());
            cury.push(cury.top() - 1);
            discovered[curx.top()][cury.top()] = true;
            continue;
        }
        //otherwise we hit a dead end, so pop off most recent point to backtrack
        curx.pop();
        cury.pop();
        if (curx.empty() || cury.empty()) {
            return false;
        }
    }
    //now we must decode stack into directions and push onto our directional stack
    while (curx.size() >= 2) {
        int x2 = curx.top();
        int y2 = cury.top();
        curx.pop();
        cury.pop();
        int x = curx.top();
        int y = cury.top();
        if (x2 == x) {//we either moved up or down
            if (y2 > y) {// we moved up
                p.push(up);
                continue;
            }// otherwise we moved down
            p.push(down);
            continue;
        }
        //otherwise we either moved right or left
        if (x2 > x) {//we moved right
            p.push(right);
            continue;
        }//otherwise we moved left
        p.push(left);
    }
    if (p.size() <= M) {
        return true;
    }
    return false;
}

void Protester::BFS(std::stack<Direction> &p, int startX, int startY, int endX, int endY) {
    if (startX == endX && startY == endY) {
        return;
    }
    std::queue<int> curx;
    std::queue<int> cury;
    
    curx.push(startX);
    cury.push(startY);
    
    bool discovered[64][64];
    for (int i = 0; i < 64; i++) {
        for (int k = 0; k < 64; k++) {
            discovered[i][k] = false;
        }
    }
    discovered[startX][startY] = true;
    std::pair<int, int> path[64][64];
    int currentX = startX;
    int currentY = startY;
    path[currentX][currentY].first = -99;
    path[currentX][currentY].second = -99;
    while (!curx.empty())
    {
        currentX = curx.front();
        currentY = cury.front();
        if (currentX == endX && currentY == endY) {
            break;
        }
        curx.pop();
        cury.pop();
        if (isValidPos(currentX, currentY + 1) && !discovered[currentX][currentY + 1]) // check up
        {
            discovered[currentX][currentY] = true;
            curx.push(currentX);
            cury.push(currentY + 1);
            path[currentX][currentY + 1].first = currentX;
            path[currentX][currentY + 1].second = currentY;
        }
        if (isValidPos(currentX + 1, currentY) && !discovered[currentX + 1][currentY]) // check right
        {
            discovered[currentX][currentY] = true;
            curx.push(currentX + 1);
            cury.push(currentY);
            path[currentX + 1][currentY].first = currentX;
            path[currentX + 1][currentY].second = currentY;
        }
        if (isValidPos(currentX, currentY - 1) && !discovered[currentX][currentY - 1]) // check down
        {
            discovered[currentX][currentY] = true;
            curx.push(currentX);
            cury.push(currentY - 1);
            path[currentX][currentY - 1].first = currentX;
            path[currentX][currentY - 1].second = currentY;
        }
        if (isValidPos(currentX - 1, currentY) && !discovered[currentX - 1][currentY]) // check left
        {
            discovered[currentX][currentY] = true;
            curx.push(currentX - 1);
            cury.push(currentY);
            path[currentX - 1][currentY].first = currentX;
            path[currentX - 1][currentY].second = currentY;
        }
    }
    int i = currentX;
    int j = currentY;
    while (path[i][j].first != -99) {
        int x = path[i][j].first;
        int y = path[i][j].second;
        if (i == x) {//we either moved up or down
            if (j > y) {// we moved up
                p.push(up);
                j -= 1;
                continue;
            }// otherwise we moved down
            p.push(down);
            j += 1;
            continue;
        }
        //otherwise we either moved right or left
        if (i > x) {//we moved right
            p.push(right);
            i -= 1;
            continue;
        }//otherwise we moved left
        i += 1;
        p.push(left);
    }
}

void Protester::setLeaveField() {
    m_leaveTheField = true;
}

void Protester::annoy(int x) {
    if (m_hp <= 0) {
        return;
    }
    m_hp -= x;
    if (m_hp > 0) {
        getWorld()->playSound(SOUND_PROTESTER_ANNOYED);
        int level = getWorld()->getLevel();
        int rightHand = 100 - level* 10;
        stunnedTicks = std::max(50, rightHand);
    }
    if (m_hp <= 0) {
        getWorld()->playSound(SOUND_PROTESTER_GIVE_UP);
        if (getID() == TID_PROTESTER) {
            getWorld()->increaseScore(100);
        }
        if (getID() == TID_HARD_CORE_PROTESTER) {
            getWorld()->increaseScore(250);
        }
        stunnedTicks = 0;
        setLeaveField();
    }
}

void HardcoreProtester::setTicksToStare(int x) {
    ticksToStare = x;
}
int HardcoreProtester::getTicksToStare() {
    return ticksToStare;
}
