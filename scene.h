#pragma once
#include "object.h"

vector<Object*>object;

vector<Sphere>sphere{
	Sphere(Vector(WIDTH/2,HEIGHT+80,DEPTH/2),100,LAMBERT,Color(),Color(10,10,10),Vector(0,-1,0)),
	Sphere(Vector(0,HEIGHT,0),50,LAMBERT,Color(),Color(2e6,2e6,2e6),Vector(1,-1,1)),
	Sphere(Vector(WIDTH,HEIGHT,0),50,LAMBERT,Color(),Color(2e6,2e6,2e6),Vector(-1,-1,1)),
	Sphere(Vector(0,HEIGHT,DEPTH),50,LAMBERT,Color(),Color(2e6,2e6,2e6),Vector(1,-1,-1)),
	Sphere(Vector(WIDTH,HEIGHT,DEPTH),50,LAMBERT,Color(),Color(2e6,2e6,2e6),Vector(-1,-1,-1)),
	Sphere(Vector(50,50,DEPTH-50),50,LAMBERT,Color(0.25,0.75,0.25)),
	Sphere(Vector(WIDTH-50,50,DEPTH-50),50,LAMBERT,Color(0.25,0.75,0.75)),
	Sphere(Vector(WIDTH-50,50,50),50,LAMBERT,Color(0.25,0.25,0.75)),
	Sphere(Vector(50,50,50),50,LAMBERT,Color(0.75,0.25,0.25)),
};
vector<Plane>plane{
	Plane(Vector(0,0,0)		,Vector(1,0,0)	,LAMBERT,Color(0.25,0.25,0.75)),	//左
	Plane(Vector(WIDTH,0,0)	,Vector(-1,0,0)	,LAMBERT,Color(0.75,0.25,0.25)),	//右
	Plane(Vector(0,0,0)		,Vector(0,1,0)	,LAMBERT,Color(0.75,0.75,0.75)),	//床
	Plane(Vector(0,HEIGHT,0),Vector(0,-1,0)	,LAMBERT,Color(0.75,0.75,0.75)),	//天井
	Plane(Vector(0,0,DEPTH)	,Vector(0,0,-1)	,LAMBERT,Color(0.75,0.25,0.75)),	//奥
};
vector<Triangle>triangle{
	Triangle(Vector(WIDTH/2,1,DEPTH),Vector(WIDTH,1,DEPTH/2),Vector(0,1,DEPTH/2),SPECULAR,Color(0.7,0.4,0)),
	Triangle(Vector(WIDTH/2,1,0),Vector(0,1,DEPTH/2),Vector(WIDTH,1,DEPTH/2),SPECULAR,Color(0.7,0.4,0)),
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