//
//  BGTWorld.h
//  BGT
//
//  Created by John Running on 15/3/3.
//
//

#ifndef __BGT__BGTWorld__
#define __BGT__BGTWorld__

#include "cocos2d.h"
#include "WaveManager.h"
#include "QTEMonster.h"
#include "QTELayer.h"



class MessageDispatcher;
class BGTWall;
class Character;
class GameEntityManager;
class Weapon;
class Knife;
class Pistol;
#include <spine/spine-cocos2dx.h>
USING_NS_CC;
using namespace spine;

class GameScene;

class BGTWorld : public Node
{
private:
    int currentLevelIndex,currentWaveIndex;
    Sprite *gameBgSprite;
    Sprite *frontbgSprite;
    Label *waveTip;
    Layer *uiLayer;
    LevelData *currentLevelData;
    GameScene *gameScene;
    Layer *bgLayer;
    Layer *monsterLayer;
    Layer *shadowLayer;
    Layer *battlefieldLayer;
    Layer *frontBgLayer;
    Layer *weaponLayer;
    Vector<Weapon*> weapons;
    Weapon *currentWeapon;
    WaveManager *waveManager;
    Wave *currentWave;
    //road2 是wall的y
    float road0Y,road1Y,road2Y,road3Y,road4Y;
    Vector<Character*> monsterPool;
    float *roads;
    unsigned int waveEnemyNumLeftToBeOut;//这一波还剩多少怪要出击
    unsigned int totalKilledNum,waveKilledNum;
    float nextWaveOutTimeLeft;
    BGTWall *wall;
    Knife *knife;
    Pistol *pistol;
    
    MessageDispatcher *dispatcher;
    GameEntityManager *entityManager;
    
    Character* getIdleEnemyByTypeFromPoolForInit(int type);
    Character* getIdleEnemyByTypeFromPool(int type);
    //这一波过去的时间
    float timePast;
    
    float bottomPositionYForMonster;
    bool showedNextWaveUI;
    bool inQTEMode;
    QTELayer *qteLayer;
    
    Character *qteCharacter;
    float enegy;
    float maxEnegy;
    bool isPlaySkill;
    Character *skillCharacter;
    
    Vector<Sprite*> shadowsPool;
public:
    void enterQTEMode(Character* monster);
    void exitQTEMode(bool playerWin);
    bool isQTEMode();
    
    void resumeSkill(float dt);
    
    float getEnegy();
    
    void launchCurrentSkill();
    
    void reset();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool initWithGameScene(GameScene *gs);
    BGTWorld();
    ~BGTWorld();
    // implement the "static create()" method manually
    void createWorld(int level);
    
    void update(float dt);
    
    void toggleWeapon();
    Weapon* getCurrentWeapon();
    bool isUseKnife();
    
    void showNextWaveUI();
    void resumeGame();
    void pauseGame();
    
    void toggleToGun();
    void toggleToKnife();
    
    //当一个怪物死亡时，这个函数会被怪物对象调用
    void monsterDied(Character* monster);
    
    void nextWave();
    
    void monsterDiedHandler(EventCustom* event);
    void monsterSkilledHandler(EventCustom* event);
    
    void startGame();
    void endGame(bool isWin);
    
    void shake( float d, float strength );
    
    Sprite* getIdleShadowFromPool();
    
    Sprite* getShadowByMonster(Character* monster);
    
    Vector<Character*> getMonsters();
    
    BGTWall* getWall();
    
    void onEnter();
    void onEnterTransitionDidFinish();
    void onExit();
    void onExitTransitionDidStart();
    
//    bool onTouchBegan(Touch* touch, Event* event);
//    void onTouchMoved(Touch* touch, Event* event);
//    void onTouchEnded(Touch* touch, Event* event);
//    void onTouchCancelled(Touch *touch, Event *unused_event);
    
    
    void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
    
    void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
    
    void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);
    
    void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);
};

#endif /* defined(__BGT__BGTWorld__) */
