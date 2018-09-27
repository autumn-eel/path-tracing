#pragma once

#include "scene.h"
#include "object.h"
#include "xorshift.h"

Color raytrace(Ray l,int depth){
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
	double q=max({object[id]->c.x,object[id]->c.y,object[id]->c.z});
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
		res=object[id]->c*raytrace(s,depth+1);
	}
	else{
		rep(i,n){
			if(object[i]->l==Color())continue;
			Ray s(point,((Sphere*)object[i])->p-point);
			double tim=object[i]->intersect(s);
			if(tim<EPS)continue;
			bool flag=true;
			rep(j,n){
				if(i==j)continue;
				double t=object[j]->intersect(s);
				if(t>EPS&&t+EPS<tim){
					flag=false;
				}
			}
			if(flag){
				res=res+(object[id]->c/M_PI)*(object[i]->l*s.d.dot(normal)/(4*M_PI)/(tim*tim));
			}
		}
	}
	return res/q;
}