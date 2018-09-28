#pragma once

#include "scene.h"
#include "object.h"
#include "xorshift.h"

Color pathtrace(Ray l,int depth){
	double Min=INF;int id=-1;
	rep(i,n){
		double p=object[i]->intersect(l);
		if(p>EPS&&Min>p)Min=p,id=i;
	}
	if(id==-1)return Color();
	if(object[id]->l!=Color()){
		return object[id]->l;
	}
	Color res;
	Vector point=l.p+l.d*Min;
	Vector normal=object[id]->get_normal(point);
	double q=min(1.,max({object[id]->c.x,object[id]->c.y,object[id]->c.z}));
	if(depth>DEPTH_MAX){
		q*=pow(0.5,depth-DEPTH_MAX);
	}
	if(depth>DEPTH_MIN){
		if(rand_01()>=q){
			return Color();
		}
	}
	else q=1;
	if(object[id]->t==SPECULAR){
		Vector w=l.d*-1;
		Vector w_=normal*2*w.dot(normal)-w;
		Ray s(point,w_);
		res=object[id]->c*pathtrace(s,depth+1);
	}
	if(object[id]->t==LAMBERT){
		Vector w,u,v;
		w=normal;
		if(abs(w.x)>EPS){
			u=Vector(0,1,0).det(w).normalize();
		}
		else{
			u=Vector(1,0,0).det(w).normalize();
		}
		v=w.det(u).normalize();
		double r1=2*M_PI*rand_01();
		double r2=rand_01(),r2s=sqrt(r2);
		Vector dir=(u*cos(r1)*r2s+v*sin(r1)*r2s+w*sqrt(1-r2)).normalize();
		res=object[id]->c*pathtrace(Ray(point,dir),depth+1);
	}
	if(object[id]->t==REFRACTION){
		
	}
	return res/q;
}