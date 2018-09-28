#pragma once

#include "define.h"

struct Vector{
	double x,y,z;
	Vector():x(0),y(0),z(0){}
	Vector(double x,double y,double z):x(x),y(y),z(z){}
	double norm(){return x*x+y*y+z*z;}
	double abs(){return sqrt(norm());}
	Vector normalize(){
		double d=abs();
		return Vector(x/=d,y/=d,z/=d);
	}
	Vector operator+(const Vector&u)const{
		return Vector(x+u.x,y+u.y,z+u.z);
	}
	Vector operator-(const Vector&u)const{
		return Vector(x-u.x,y-u.y,z-u.z);
	}
	Vector operator*(const Vector&u)const{
		return Vector(x*u.x,y*u.y,z*u.z);
	}
	Vector operator/(const Vector&u)const{
		return Vector(x/u.x,y/u.y,z/u.z);
	}
	Vector operator*(double d){
		return Vector(x*d,y*d,z*d);
	}
	Vector operator/(double d){
		return Vector(x/d,y/d,z/d);
	}
	bool operator==(const Vector&u)const{
		return x==u.x&&y==u.y&&z==u.z;
	}
	bool operator!=(const Vector&u)const{
		return !operator==(u);
	}
	double dot(const Vector&u)const{
		return x*u.x+y*u.y+z*u.z;
	}
	Vector det(const Vector&u)const{
		return Vector(y*u.z-z*u.y,z*u.x-x*u.z,x*u.y-y*u.x);
	}
	double detxy(const Vector&u)const{
		return x*u.y-y*u.x;
	}
	double detxz(const Vector&u)const{
		return x*u.z-z*u.x;
	}
	double detyz(const Vector&u)const{
		return y*u.z-z*u.y;
	}
};

typedef Vector Color;


struct Ray{
	Vector p,d;
	Ray(Vector p,Vector d_):p(p){
		d=d_.normalize();
	}
};

enum Type{
	LAMBERT,
	SPECULAR,
	REFRACTION
};

struct Object{
	Type t;
	Color c;
	Color l;
	
	Object(){}
	Object(Type t,Color c=Color(),Color l=Color())
		:t(t),c(c),l(l){}

	virtual double intersect(Ray){return 0;}
	virtual Vector get_normal(Vector){return Vector();}
};

struct Sphere:public Object{
	Vector p;
	double r;
	Sphere(Vector p,double r,Type t,Color c=Color(),Color l=Color()):
		Object(t,c,l),p(p),r(r){}

	double intersect(Ray l){
		double B=l.d.dot(l.p-p);
		double C=(l.p-p).norm()-r*r;
		double D=B*B-C;
		if(D<0)return -1;
		double E=sqrt(D);
		if(-B+E<EPS)return -1;
		if(-B-E>EPS)return -B-E;
		return -B+E;
	}
	Vector get_normal(Vector point){
		return (point-p).normalize();
	}
};

struct Plane:public Object{
	Vector v1,v2,v3;
	Vector normal;
	double d;
	Plane(Vector v1,Vector v2,Vector v3,Type t,Color c=Color(),Color l=Color()):
		Object(t,c,l),v1(v1),v2(v2),v3(v3){
		normal=(v2-v1).det(v3-v1).normalize();
		d=v1.dot(normal);
	}
	Plane(Vector v1,Vector normal_,Type t,Color c=Color(),Color l=Color()):
		Object(t,c,l),v1(v1){
		normal=normal_.normalize();
		d=v1.dot(normal);
	}
	double intersect(Ray l){
		return (d-l.p.dot(normal))/l.d.dot(normal);
	}
	Vector get_normal(Vector point){
		return normal;
	}
};

struct Triangle:public Plane{
	Triangle(Vector v1,Vector v2,Vector v3,Type t,Color c=Color(),Color l=Color()):
		Plane(v1,v2,v3,t,c,l){}

	double intersect(Ray l){
		double t=Plane::intersect(l);
		if(t<EPS)return -1;
		Vector point=l.p+l.d*t;
		int cnt=0;
		if((v2-v1).detxy(v3-v1)){
			cnt=((v2-v1).detxy(point-v2)>0?1:-1)+
				((v3-v2).detxy(point-v3)>0?1:-1)+
				((v1-v3).detxy(point-v1)>0?1:-1);
		}
		else if((v2-v1).detxz(v3-v1)){
			cnt=((v2-v1).detxz(point-v2)>0?1:-1)+
				((v3-v2).detxz(point-v3)>0?1:-1)+
				((v1-v3).detxz(point-v1)>0?1:-1);
		}
		else{
			cnt=((v2-v1).detyz(point-v2)>0?1:-1)+
				((v3-v2).detyz(point-v3)>0?1:-1)+
				((v1-v3).detyz(point-v1)>0?1:-1);
		}
		return cnt==-3||cnt==3?t:-1;
	}
};