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
};

typedef Vector Color;

struct Sphere{
	Vector p;
	double r;
	Sphere(){}
	Sphere(Vector p,double r):p(p),r(r){}
};

struct Ray{
	Vector p,d;
	Ray(Vector p,Vector d):p(p),d(d){}
	double intersect(Sphere c){
		d.normalize();
		double B=d.dot(p-c.p);
		double C=(p-c.p).norm()-c.r*c.r;
		double D=B*B-C;
		if(D<0)return -1;
		double E=sqrt(D);
		if(-B+E<EPS)return -1;
		if(-B-E>EPS)return -B-E;
		return -B+E;
	}
};

enum type{
	LAMBERT,
	SPECULAR
};

struct SphereObject:public Sphere{
	type t;
	Color c,l;
	SphereObject(Vector p,double r,type t,Color c=Color(),Color l=Color()):
		Sphere(p,r),t(t),c(c),l(l){}
};