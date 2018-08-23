#pragma once
#include "object.h"

vector<Object*>object;
Sphere sphere[]={
	Sphere(Vector(WIDTH/2,DEPTH/2,HEIGHT+80),100,LAMBERT,Color(),Color(3e6,3e6,3e6)),//照明
	Sphere(Vector(WIDTH/3,DEPTH/3,HEIGHT/3),50,LAMBERT,Color(0.25,0.75,0.25)),//球
	Sphere(Vector(-1e5,DEPTH/2,HEIGHT/2),1e5,LAMBERT,Color(0.25,0.25,0.75)),//左
	Sphere(Vector(WIDTH+1e5,DEPTH/2,HEIGHT/2),1e5,LAMBERT,Color(0.75,0.25,0.25)),//右
	Sphere(Vector(WIDTH/2,DEPTH/2,-1e5),1e5,LAMBERT,Color(0.75,0.75,0.75)),//床
	Sphere(Vector(WIDTH/2,DEPTH/2,HEIGHT+1e5),1e5,LAMBERT,Color(0.75,0.75,0.75)),//天井
	Sphere(Vector(WIDTH/2,DEPTH+1e5,HEIGHT/2),1e5,LAMBERT,Color(0.75,0.25,0.75))//奥
};
Plane plane[]={
	Plane(Vector(0,DEPTH,150),Vector(0,0,0),Vector(WIDTH,0,0),LAMBERT,Color(0.25,0.75,0.75))
};

void object_init(){
	int n1=sizeof(sphere)/sizeof(Sphere);
	int n2=sizeof(plane)/sizeof(Plane);
	rep(i,n1){
		object.push_back(&sphere[i]);
	}
	rep(i,n2){
		object.push_back(&plane[i]);
	}
}