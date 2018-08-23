#pragma once
#include "object.h"

SphereObject object[] = {
	SphereObject(Vector(WIDTH/2,DEPTH/2,HEIGHT+80),100,LAMBERT,Color(),Color(3e6,3e6,3e6)),//照明
	SphereObject(Vector(WIDTH/3,DEPTH/3,HEIGHT/3),50,LAMBERT,Color(0.25,0.75,0.25)),//球
	SphereObject(Vector(-1e5,DEPTH/2,HEIGHT/2),1e5,LAMBERT,Color(0.25,0.25,0.75)),//左
	SphereObject(Vector(WIDTH+1e5,DEPTH/2,HEIGHT/2),1e5,LAMBERT,Color(0.75,0.25,0.25)),//右
	SphereObject(Vector(WIDTH/2,DEPTH/2,-1e5),1e5,LAMBERT,Color(0.75,0.75,0.75)),//床
	SphereObject(Vector(WIDTH/2,DEPTH/2,HEIGHT+1e5),1e5,LAMBERT,Color(0.75,0.75,0.75)),//天井
	SphereObject(Vector(WIDTH/2,DEPTH+1e5,HEIGHT/2),1e5,LAMBERT,Color(0.75,0.25,0.75))//奥
};