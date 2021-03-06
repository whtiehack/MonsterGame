//
//  UILayer.h
//  BGT
//
//  Created by John Running on 15/3/3.
//
//

#ifndef __BGT__UILayer__
#define __BGT__UILayer__

#include "cocos2d.h"
#include "GameManager.h"
#include "cocos2dFilters.h"
#include "GameEndUpgradeLayer.h"
#include "GameEndRateLayer.h"
#include "PauseLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;

//class ComboLabel : public Node{
//    
//};

class GameScene;

class UILayer : public cocos2d::Layer
{
private:
    Filters one;
    
    GameScene *gameScene;
    Sprite *knifeIcon;
    Sprite *gunIcon;
    Layer *tipLayer;
    Layer *hudLayer;
    Sprite *failedTip;
    Sprite *failedTipBg;
    
    Sprite *winTip;
    Sprite *winTipBg;
    
    GameEndRateLayer *rateLayer;
    GameEndUpgradeLayer *upgredLayer;
    
    LayerColor *winLayer;
    LayerColor *failedLayer;
    PauseLayer *pausedLayer;
    FilteredSprite* blursprite;
    //Label *scorelabel;
    Sprite *comboLayer;
    Sprite *comboRateSprite;
    Label *playerLevelLabel;
    Label *coinLabel;
    Label *comboLabel;
    Sprite *comboBar;
    ProgressTimer *comboProgressBar;
    
    GameManager *gameManager;
    Hero *player;
    Sprite *enegyBar;
    ProgressTimer *enegyProgressBar;
    
    Sprite *lifeBar;
    ProgressTimer *lifeProgressBar;
    Menu *pauseMenu;
    

    void pauseCallback(Ref* sender);
    void skillCallback(Ref* sender);
    
    bool needEatTouch;
    
    Vec2 frontIconPosition,backIconPosition;
    float frontScale,backScale;
    Color3B frontTint,backTint;
    
    void monsterHittedHandler(EventCustom* event);
    void monsterShanbiHandler(EventCustom* event);
    void monsterParryHandler(EventCustom* event);
    void monsterDamagedHandler(EventCustom* event);
    void monsterBaoDamagedHandler(EventCustom* event);
    void pauseLayerResumeHandler(EventCustom* event);
    void toggleToGun();
    void toggleToKnife();
    
    unsigned int  hitCount;
    float leftTime;
    
    void hideComboUI();
    void showComboUI();
    
    unsigned int mostHitRecord;
    
    float currentLifeValue;
    float currentEnegyValue;
    Sprite *lifeBarHead;
    Sprite *enegyBarHead;
    
    Vector<Sprite*> shanbiIconsPool;
    Vector<Sprite*> missIconsPool;
    Vector<Sprite*> yunIconsPool;
    Vector<Sprite*> daodiIconsPool;
    Vector<Sprite*> flowIconsPool;
    Vector<Sprite*> gedangIconsPool;
    Vector<Sprite*> jiTuiIconsPool;
    Vector<Sprite*> mianyiIconsPool;
    Vector<Label*> damageLabels;
    Vector<Label*> baoDamageLabels;
    
    void showEndResult(float t);
    
    
    Label* getDamageLabelFromPool();
    Label* getBaoDamageLabelFromPool();
    
    Sprite *getShanbiIconFromPool();
    Sprite *getMissIconFromPool();
    Sprite *getYunIconFromPool();
    Sprite *getDaoDiIconFromPool();
    Sprite *getFlowIconFromPool();
    Sprite *getGeDangIconFromPool();
    Sprite *getJiTuiIconFromPool();
    Sprite *getMianyiIconFromPool();
public:
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool initWithGameScene(GameScene *gs);
    UILayer();
    ~UILayer();
//    // implement the "static create()" method manually
//    CREATE_FUNC(UILayer);
    
    void hideHUD();
    void showHUD();
    
    void gameEnd(bool isWin);
    void gameStart();
    void update(float dt);
    
    bool onTouchBegan(Touch* touch, Event* event);
//    void onTouchMoved(Touch* touch, Event* event);
//    void onTouchEnded(Touch* touch, Event* event);
//    void onTouchCancelled(Touch *touch, Event *unused_event);
    void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
    
    void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
    
    void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);
    
    void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);
};

#endif /* defined(__BGT__UILayer__) */
