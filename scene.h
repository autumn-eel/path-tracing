#pragma once
#include "object.h"

vector<Object*>object;

//~ vector<Sphere>sphere{
	//~ Sphere(Vector(WIDTH/2,HEIGHT+80,DEPTH/2),100,LAMBERT,Color(),Color(3,3,3),Vector(0,-1,0)),
	//~ Sphere(Vector(50,50,DEPTH-50)			,50	,LAMBERT,Color(0.25,0.75,0.25)),
	//~ Sphere(Vector(WIDTH-50,50,DEPTH-50)		,50	,LAMBERT,Color(0.25,0.75,0.75)),
	//~ Sphere(Vector(WIDTH-50,50,50)			,50	,LAMBERT,Color(0.25,0.25,0.75)),
	//~ Sphere(Vector(50,50,50)					,50	,LAMBERT,Color(0.75,0.25,0.25)),
//~ };
vector<Plane>plane{
	//~ Plane(Vector(0,0,0)		,Vector(1,0,0)	,LAMBERT,Color(0.25,0.25,0.75)),	//左
	//~ Plane(Vector(WIDTH,0,0)	,Vector(-1,0,0)	,LAMBERT,Color(0.75,0.25,0.25)),	//右
	//~ Plane(Vector(0,0,0)		,Vector(0,1,0)	,LAMBERT,Color(0.75,0.75,0.75)),	//床
	//~ Plane(Vector(0,HEIGHT,0),Vector(0,-1,0)	,LAMBERT,Color(0.75,0.75,0.75)),	//天井
	//~ Plane(Vector(0,0,DEPTH)	,Vector(0,0,-1)	,LAMBERT,Color(0.75,0.25,0.75)),	//奥
};
vector<Triangle>triangle{
	//~ Triangle(Vector(WIDTH/2,1,DEPTH),Vector(WIDTH,1,DEPTH/2),Vector(0,1,DEPTH/2)	,LAMBERT,Color(0.7,0.4,0)),
	//~ Triangle(Vector(WIDTH/2,1,0)	,Vector(0,1,DEPTH/2)	,Vector(WIDTH,1,DEPTH/2),LAMBERT,Color(0.7,0.4,0)),
};
vector<Sphere>sphere{
	Sphere(Vector(WIDTH/2,HEIGHT+80,DEPTH/2),100,LAMBERT,Color(0.75,0.75,0.25),Color(16,16,16)),//照明
	Sphere(Vector(WIDTH/3,HEIGHT/3,DEPTH/3),50,LAMBERT,Color(0.25,0.75,0.25)),//球1
	Sphere(Vector(-1e5,HEIGHT/2,DEPTH/2),1e5,LAMBERT,Color(0.25,0.25,0.75)),//左
	Sphere(Vector(WIDTH+1e5,HEIGHT/2,DEPTH/2),1e5,LAMBERT,Color(0.75,0.25,0.25)),//右
	Sphere(Vector(WIDTH/2,-1e5,DEPTH/2),1e5,LAMBERT,Color(0.75,0.75,0.75)),//床
	Sphere(Vector(WIDTH/2,HEIGHT+1e5,DEPTH/2),1e5,LAMBERT,Color(0.75,0.75,0.75)),//天井
	Sphere(Vector(WIDTH/2,HEIGHT/2,DEPTH+1e5),1e5,LAMBERT,Color(0.75,0.25,0.75))//奥
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