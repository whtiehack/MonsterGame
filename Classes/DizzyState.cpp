//
//  DizzyState.cpp
//  BGT
//
//  Created by John Running on 15/3/7.
//
//

#include "DizzyState.h"
#include "Character.h"
#include "GameEntityManager.h"
#include "Weapon.h"
#include "Knife.h"

void DizzyState::enter(Character* agent)
{
    spTrackEntry* entry = agent->getSkeletonNode()->setAnimation(0, DizzyAnimationName, true);
    agent->getSkeletonNode()->setTrackCompleteListener(entry, [] (int trackIndex,int loopCount) {
        //log("attack complete!");

    });
    startTime = millisecondNow();
}

void DizzyState::execute(Character* agent,float dt)
{
    if (millisecondNow() - startTime >= 2000) {
        agent->move();
    }
}

void DizzyState::exit(Character* agent)
{
    
}

bool DizzyState::onMessage(Character* agent, const Telegram& msg)
{
    if(msg.msg == Msg_AttackedByXuLiWeapon || msg.msg == Msg_AttackedByWeapon){
        AttackInfo info = *(AttackInfo*)msg.extraInfo;
        Weapon *weapon = (Weapon*)GameEntityManager::getInstance()->getEntityFromID(msg.sender);

        //蓄力攻击没有攻击力
        if (msg.msg == Msg_AttackedByWeapon){
            agent->takeDamage(weapon->getDamage(),Vec2(info.x,info.y));
            if (agent->getLife() <= 0) {
                agent->die();
                return false;
            }
        }
        agent->hitted();
        switch (weapon->getType()) { 
            case WeaponTypeKnife:{
                //Knife *knife = (Knife*)weapon;

                if (msg.msg == Msg_AttackedByXuLiWeapon) {
                    if (info.direction == KnifeAttackDirectionUp) {
                        agent->flowup();
                    }else if (info.direction == KnifeAttackDirectionDown) {
                        agent->falldown();
                    }else if (info.direction == KnifeAttackDirectionRight) {
                        agent->rollback();
                    }else{
                        agent->stiff();
                    }
                }else{
                    agent->stiff();
                }
                
            }
                break;
            case WeaponTypePistol:
                agent->stiff();
                break;
            default:
                break;
        }
    }
    return false;
}
