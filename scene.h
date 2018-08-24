#pragma once
#include "object.h"

vector<Object*>object;

vector<Sphere>sphere{
	Sphere(Vector(WIDTH/2,HEIGHT+80,DEPTH/2),100,LAMBERT,Color(),Color(1e6,1e6,1e6),Vector(0,-1,0)),	//照明(天井)
	Sphere(Vector(WIDTH/2,-80,DEPTH/2)		,100,LAMBERT,Color(),Color(1e6,1e6,1e6),Vector(0,1,0)),		//照明(床)
	Sphere(Vector(WIDTH/2,HEIGHT/2,-200)	,100,LAMBERT,Color(),Color(1e6,1e6,1e6),Vector(0,0,1)),		//照明(手前)
	Sphere(Vector(-80,HEIGHT/2,DEPTH/2)		,100,LAMBERT,Color(),Color(1e6,1e6,1e6),Vector(1,0,0)),   	//照明(左)
	Sphere(Vector(WIDTH+80,HEIGHT/2,DEPTH/2),100,LAMBERT,Color(),Color(1e6,1e6,1e6),Vector(-1,0,0)),	//照明(右)
	Sphere(Vector(WIDTH/3,HEIGHT/3,DEPTH/3)	,50	,LAMBERT,Color(0.25,0.75,0.25)),						//球
};
vector<Plane>plane{
	Plane(Vector(0,0,0)		,Vector(1,0,0)	,LAMBERT,Color(0.25,0.25,0.75)),	//左
	Plane(Vector(WIDTH,0,0)	,Vector(-1,0,0)	,LAMBERT,Color(0.75,0.25,0.25)),	//右
	Plane(Vector(0,0,0)		,Vector(0,1,0)	,LAMBERT,Color(0.75,0.75,0.75)),	//床
	Plane(Vector(0,HEIGHT,0),Vector(0,-1,0)	,LAMBERT,Color(0.75,0.75,0.75)),	//天井
	Plane(Vector(0,0,DEPTH)	,Vector(0,0,-1)	,LAMBERT,Color(0.75,0.25,0.75)),	//奥
};
vector<Triangle>triangle{
	
};

void object_init(){
	rep(i,(int)sphere.size()){
		object.push_back(&sphere[i]);
	}
	rep(i,(int)plane.size()){
		object.push_back(&plane[i]);
	}
	rep(i,(int)triangle.size()){
		object.push_back(&triangle[i]);
	}
}