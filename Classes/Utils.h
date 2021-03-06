//
//  Utils.h
//  BGT
//
//  Created by John Running on 15/3/3.
//
//

#ifndef BGT_Utils_h
#define BGT_Utils_h

#include "cocos2d.h"
#include "Telegram.h"

USING_NS_CC;


#define gravity -80

#define shotAngle 45 * A_T_R

#define constValue gv/sinf(2*shotAngle)

#define DEGRAD M_PI/180

//for isomatric
#define Y_CORRECT cosf(-M_PI/6)*M_SQRT2

//(180/M_PI)
#define R_T_A 57.29577951308232

#define A_T_R M_PI/180
//(2*M_PI)
#define double_PI 6.283185307179586
//(M_PI*3/2)
#define triD_PI 4.71238898038469

#define TOO_CLOSE 5

#define TURN_SPEED 0.08

#define TileSize 100

#define barTotalWidth 171

#define maxFury 100

#define fieldWidth 1000

#define fieldHeight 520

#define lifeBarWidthOfUI 180

#define manaBarWidthOfUI 180

#define expBarWidthOfUI 180

#define  COMBO_HIT_DURATION 1.0

//第一波出完后（waveGapTime秒后出怪，如果最后一个怪被打死还没出，马上出）
#define waveGapTime 15

#define StandAnimationName "wait"
#define HurtAnimationName "hurt"
#define AttackAnimationName "attack"
#define Attack2AnimationName "attack_02"
#define ChargeAnimationName "charge"
#define ChargeEndAnimationName "charge_end"
#define DieAnimationName "die"
#define Die2AnimationName "die_02"
#define DizzyAnimationName "dizzy"
#define FloatAnimationName "floating"
#define FloatHurtAnimationName "floating_hurt"
#define PourAnimationName "pour"
#define PourHurtAnimationName "pour_hurt"
#define PourUpAnimationName "pour_up"
#define RepelAnimationName "repel"
#define ChargeStartAnimationName "charge_start"
#define ChargeAnimationName "charge"
#define ChargeEndAnimationName "charge_end"
#define SkillAnimationName "skill"
#define SkillAnimationName "skill"
#define SkillAnimationName "skill"
#define WalkAnimationName "walk"
#define StatusAnimationName "status"
#define DefenseAnimationName "defense"
#define DefenseEndAnimationName "defense_end"

#define GESTURE_SCORE_THRESHOLD 0.7f


typedef enum {
    GoodsPropertiesType_XiXue = 0,//吸血
    GoodsPropertiesType_JiaXue = 1,//加血
    GoodsPropertiesType_JiaNengLiang = 2,//加能量
    GoodsPropertiesType_JiaGongJi = 3,//加攻击
    GoodsPropertiesType_JiaShanBi = 4,//加闪避
    GoodsPropertiesType_JiaMingZhong = 5,//加命中
    GoodsPropertiesType_JiaJinYan = 6,//加经验
    GoodsPropertiesType_JiaFangYu = 7,//加防御
    GoodsPropertiesType_JiaBaoJiLv = 8,//加暴击几率
    GoodsPropertiesType_JiaBaoShang = 9,//加爆伤
    GoodsPropertiesType_JiaDanYao = 10,//加弹药
    GoodsPropertiesType_JianCD = 11,//减CD
    GoodsPropertiesType_JiaNaiJiu = 12,//加耐久
    GoodsPropertiesType_JianSu = 13,//减速
    GoodsPropertiesType_JiaJiYunLv = 14,//加击晕几率
    GoodsPropertiesType_JiaShangHaiHuo = 15,//加火伤害
    GoodsPropertiesType_JiaShangHaiDu = 16,//加毒伤害
    GoodsPropertiesType_JiaJinBiChanChu = 17,//加金币产出
    GoodsPropertiesType_JiaXingYun = 18,//加幸运
    GoodsPropertiesType_JiaLianJi = 19,//加连击
    GoodsPropertiesType_JiangXiaoHao = 20,//降低能量消耗
    GoodsPropertiesType_Kong = 21,//孔
} GoodsPropertiesType;



//物品属性
struct GoodsProperty {
    GoodsPropertiesType type;
    float value;
};


struct CustomerUserData {
    void* monster;
    float damage;
};

typedef enum {
    TROOP_TIME_MODE_FIXED = 0,
    TROOP_TIME_MODE_RANDOM = 1,
    TROOP_TIME_MODE_LINEAR = 2,
} TroopTimeMode;

typedef enum {
    TROOP_MONSTER_TYPE_MODE_FIXED = 0,
    TROOP_MONSTER_TYPE_MODE_RANDOM = 1,
} TroopMonsterMode;

typedef enum {
    TROOP_POSITION_MODE_FIXED = 0,
    TROOP_POSITION_MODE_RANDOM = 1,
} TroopPositionMode;

typedef enum {
    Msg_WallDamaged,
    Msg_WallBaoDamaged,
    Msg_QTEDamaged,
    Msg_AttackedByXuLiWeapon,
    Msg_AttackedByWeapon,
    Msg_MoveToPosition,
    Msg_MoveToWall,
    Msg_Chase,
    Msg_MoveToShopping,
    Msg_Combat,
    Msg_CombatWall,
} MessageType;

typedef enum {
    CharacterTypeSmallZombie=0,//小僵尸
    CharacterTypeSmallGhost=1,//小幽灵
    CharacterTypeSmallWuTouYong=2,//无头俑
    CharacterTypeBigZombie=3,//大僵尸
} CharacterType;

typedef enum {
    //	kUp,
    //	kDown,
    CharacterDirectionLeft,
    CharacterDirectionRight,
} CharacterDirection;

typedef enum {
    CharacterStateStandby,
    CharacterStateAttack,
    CharacterStateMoveTo,
    CharacterStateDied,
} CharacterState;

typedef enum {
    GameStateReady,
    GameStateGaming,
    GameStatePaused,
    GameStateEnded,
} GameState;

typedef enum {
    WeaponTypeKnife,
    WeaponTypePistol,
} WeaponType;

typedef enum {
    KnifeAttackDirectionLeft,
    KnifeAttackDirectionRight,
    KnifeAttackDirectionUp,
    KnifeAttackDirectionDown,
    KnifeAttackDirectionUnkown,
} KnifeAttackDirection;


struct AttackInfo {
    KnifeAttackDirection direction;
    float x;
    float y;
};


typedef enum {
    Goods_Weapon_KNIFE = 0,//刀
    Goods_Weapon_GUN = 1,//枪
    Goods_Weapon_PET = 2,//宠物
    
    Goods_Armor_RING = 100,//戒指
    Goods_Armor_NECKLACE = 101,//项链
    
    Goods_Stuff = 200,//材料
    
    Goods_Consume_LIFE = 300,//血
    Goods_Consume_ENERGY = 301,//能量
    Goods_Consume_BULLET = 302,//子弹
    Goods_Consume_MONEY = 303,//钱
    Goods_Consume_EXP_PLAYER = 304,//经验
    Goods_Consume_RESET_SKILL = 305,//技能重置
    Goods_Consume_EXP_PET = 306,//经验
    Goods_Consume_RESET_WEAPON_ONE_PROPERTY = 307,//一条武器属性重置
    Goods_Consume_RESET_WEAPON_ALL_PROPERTY = 308,//所有武器属性重置
    Goods_Consume_WEAPON_UPGRED = 309,//武器进阶
    Goods_Consume_PET_UPGRED = 310,//宠物进阶
    Goods_Consume_DRILL_HOLE = 311,//打洞
    Goods_Consume_RESET_TIANFU = 312,//天赋重置
 
    Goods_Buff_GEM = 400,//宝石
    
    Goods_Skill_FULLHIT = 500,//全屏攻击
    Goods_Skill_RECOVERYLIFE = 501,//复活
    Goods_Skill_ENERGYSHIELD = 502//能量盾
}GoodsType;


struct CGLine {
    Vec2 pointA;
    Vec2 pointB;
};
typedef struct CGLine CGLine;

static inline CGLine
CGLineMake(float x1, float y1, float x2, float y2)
{
    CGLine l; l.pointA.x = x1; l.pointA.y = y1; l.pointB.x = x2; l.pointB.y = y2; return l;
}


static inline Vec2
isoToScreen(float x, float y, float z)
{
    Vec2 p; p.x = x; p.y = y + z; return p;
}

static inline Vec3
screenToIso(float x, float y,float h)
{
    Vec3 p; p.x = x; p.y = h; p.z = y; return p;
}

// Keith Hair's line intersection function
static inline Vec2
intersectlineLine(const Vec2 pointA, const Vec2 pointB, const Vec2 pointE, const Vec2 pointF) {
    float a1= pointB.y-pointA.y;
    float a2= pointF.y-pointE.y;
    float b1= pointA.x-pointB.x;
    float b2= pointE.x-pointF.x;
    float c1= pointB.x*pointA.y - pointA.x*pointB.y;
    float c2= pointF.x*pointE.y - pointE.x*pointF.y;
    
    float denom=a1*b2 - a2*b1;
    //    if (denom == 0) {
    //        //平行
    //    }
    return Vec2((b1*c2 - b2*c1)/denom,(a2*c1 - a1*c2)/denom);
}

/*****
 *
 *   intersectCircleLine
 *
 *****/
static inline bool
intersectCircleLine(const Vec2 c, const float r, const Vec2 a1, const Vec2 a2) {

    float a  = (a2.x - a1.x) * (a2.x - a1.x) +
    (a2.y - a1.y) * (a2.y - a1.y);
    float b  = 2 * ( (a2.x - a1.x) * (a1.x - c.x) +
                  (a2.y - a1.y) * (a1.y - c.y)   );
    float cc = c.x*c.x + c.y*c.y + a1.x*a1.x + a1.y*a1.y -
    2 * (c.x * a1.x + c.y * a1.y) - r*r;
    float deter = b*b - 4*a*cc;
    
    if ( deter < 0 ) {
        //result = new Intersection("Outside");
        return false;
    } else if ( deter == 0 ) {
        //result = new Intersection("Tangent");
        // NOTE: should calculate this point
        return true;
    } else {
        float e  =sqrt(deter);
        float u1 = ( -b + e ) / ( 2*a );
        float u2 = ( -b - e ) / ( 2*a );
        
        if ( (u1 < 0 || u1 > 1) && (u2 < 0 || u2 > 1) ) {
            if ( (u1 < 0 && u2 < 0) || (u1 > 1 && u2 > 1) ) {
                //result = new Intersection("Outside");
                return false;
            } else {
                //result = new Intersection("Inside");
                return true;
            }
        } else {
            //result = new Intersection("Intersection");
//            
//            if ( 0 <= u1 && u1 <= 1)
//                result.points.push( a1.lerp(a2, u1) );
//            
//            if ( 0 <= u2 && u2 <= 1)
//                result.points.push( a1.lerp(a2, u2) );
            return true;
        }
    }
    
    return false;
}

/*****
 *
 *   intersectLineLine
 *
 *****/
static inline bool
intersectLineLine(const Vec2 a1, const Vec2 a2, const Vec2 b1, const Vec2 b2) {
    float ua_t = (b2.x - b1.x) * (a1.y - b1.y) - (b2.y - b1.y) * (a1.x - b1.x);
    float ub_t = (a2.x - a1.x) * (a1.y - b1.y) - (a2.y - a1.y) * (a1.x - b1.x);
    float u_b  = (b2.y - b1.y) * (a2.x - a1.x) - (b2.x - b1.x) * (a2.y - a1.y);
    
    if ( u_b != 0 ) {
        float ua = ua_t / u_b;
        float ub = ub_t / u_b;
        
        if ( 0 <= ua && ua <= 1 && 0 <= ub && ub <= 1 ) {
            return true;
//            result = new Intersection("Intersection");
//            result.points.push(
//                               new Point2D(
//                                           a1.x + ua * (a2.x - a1.x),
//                                           a1.y + ua * (a2.y - a1.y)
//                                           )
//                               );
        } else {
//            result = new Intersection("No Intersection");
            return false;
        }
    } else {
        if ( ua_t == 0 || ub_t == 0 ) {
//            result = new Intersection("Coincident");//重合
            return false;
        } else {
//            result = new Intersection("Parallel");
            return false;
        }
    }
    
    return false;
}

static inline bool
pointInPolygon (Vec2 p, float* ptPolygon, int nCount)
{
    int nCross = 0;
    for (int i = 0; i < nCount-1; i+=2){
        Vec2 p1 = Vec2(ptPolygon[i],ptPolygon[i+1]);
        Vec2 p2 = Vec2(ptPolygon[(i+2) % nCount],ptPolygon[(i+3) % nCount]);
//        Vec2 p2 = ptPolygon[(i + 1) % nCount];
        // 求解 y=p.y 与 p1p2 的交点
        if ( p1.y == p2.y ) // p1p2 与 y=p0.y平行
            continue;
        if ( p.y < fminf(p1.y, p2.y) ) // 交点在p1p2延长线上
            continue;
        if ( p.y >= fmaxf(p1.y, p2.y) ) // 交点在p1p2延长线上
            continue;
        // 求交点的 X 坐标 --------------------------------------------------------------
        double x = (double)(p.y - p1.y) * (double)(p2.x - p1.x) / (double)(p2.y - p1.y) + p1.x;
        if ( x > p.x )
            nCross++; // 只统计单边交点
    }
    // 单边交点为偶数，点在多边形之外 ---
    return (nCross % 2 == 1);
}

/*****
 *
 *   intersectLineRectangle,r1=bottomLeft,r2=topRight
 *
 *****/
static inline bool
intersectLineRectangle(const Vec2 a1, const Vec2 a2,const Vec2 r1,const Vec2 r2) {
    Vec2 min        = Vec2(MIN(r1.x,r2.x),MIN(r1.y,r2.y));
    Vec2 max        = Vec2(MAX(r1.x,r2.x),MAX(r1.y,r2.y));
    Vec2 bottomRight   = Vec2( max.x, min.y );
    Vec2 topLeft = Vec2( min.x, max.y );
    
    bool inter1 = intersectLineLine(min, bottomRight, a1, a2);
    bool inter2 = intersectLineLine(bottomRight, max, a1, a2);
    bool inter3 = intersectLineLine(max, topLeft, a1, a2);
    bool inter4 = intersectLineLine(topLeft, min, a1, a2);

    return (inter1 || inter2 || inter3 || inter4);
}

/*****
 *
 *   intersectLinePolygon
 *
 *****/
static inline bool
intersectLinePolygon(const Vec2 a1, const Vec2 a2, Vec2* points,int pointsCount) {
    int result = 0;
    
    for ( int i = 0; i < pointsCount; i++ ) {
        Vec2 b1 = points[i];
        Vec2 b2 = points[(i+1) % pointsCount];
        bool inter = intersectLineLine(a1, a2, b1, b2);
        if(inter){
            result++;
        }
    }
    return result > 0;
};


// THIS IS THE FUNCTION THAT WORKS WITH KEITH'S FUNCTION TO CALCULATE THE DISTANCE OFF OF A LINE
// returns an object containing the distance point c is from line ab (obj.dist), and the point of intersection (obj.poi)
// obj.dist will be -1 if the perpendicular line to ab that passes through line ab would not intersect ab
static inline float
getDistanceFromLine(const Vec2 a, const Vec2 b, const Vec2 c) {
    //    float m = (a.y-b.y)/(a.x-b.x);
    //    float B = (1/m)*c.x - c.y;
    //    CGPoint d = CGPointMake(b.x,b.x*(-1/m)+B);
    //    CGPoint e = CGPointMake(a.x,a.x*(-1/m)+B);
    float m = (a.x-b.x)/(a.y-b.y);
    float B = m*c.x + c.y;
    Vec2 d = Vec2(b.x,b.x*(-m)+B);
    Vec2 e = Vec2(a.x,a.x*(-m)+B);
    Vec2 p = intersectlineLine(a,b,d,e); // use Keith's function to check for an intersection
    float dx = p.x - c.x;
    float dy = p.y - c.y;
    return sqrt(dx*dx + dy*dy);
}

static inline double millisecondNow()//long
{
    struct timeval now;
    gettimeofday(&now, NULL);
    return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

static inline double timersubCocos2d(struct timeval *start, struct timeval *end)
{
    if (! start || ! end)
    {
        return 0;
    }
    return ((end->tv_sec*1000.0+end->tv_usec/1000.0) - (start->tv_sec*1000.0+start->tv_usec/1000.0));
}

#define fieldRect CGRectMake(0,126,fieldWidth,fieldHeight)

#define wallLine CGLineMake(0,0,36,fieldHeight)

#define boundForSoldiers CGRectMake(0, 0, fieldRect.size.width-1, fieldRect.size.height-1)

#define boundForHeros CGRectMake(0, 0, fieldRect.size.width-40, fieldRect.size.height-1)


#endif
