//
//  enemy.cpp
//  ChamberCrawler3000
//
//  Created by Charles Nwodo on 2015-03-29.
//  Copyright (c) 2015 Reel. All rights reserved.
//

#include "enemy.h"
#include "player.h"
#include <cmath>

enemy::enemy(std::vector<int> p, char sym, char t, std::string i,int hp, int atk, int def,int max, bool h,treasure *gold):character(p,sym,t,i,hp,atk,def,max),ishostile(h),t(gold){}

enemy::~enemy(){}

void enemy::turnonhostility(){
    ishostile = true;
}

treasure *enemy::gettreasure(){
    return t;
}

void enemy::settreasure(treasure *gold){
    t = gold;
}

void enemy::attack(player *p){
    float num = this->getatk();
    int m = ceilf(100/(100 + p->getdef()) * num);
    p->mutatehp(-m);
}
