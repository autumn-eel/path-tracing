#pragma once
#include "define.h"
#include "object.h"

void load_model(){
	ifstream file("obj/object.obj");
	string s;
	vector<Vector>v,f;
	double Min=INF,Max=-INF;
	while(getline(file,s)){
		if(s==""||s[0]=='#')continue;
		stringstream ss(s);
		if(s[0]=='v'){
			string a;double x,y,z;ss>>a>>x>>y>>z;
			Min=min(Min,x);Min=min(Min,y);Min=min(Min,z);
			Max=max(Max,x);Max=max(Max,y);Max=max(Max,z);
			v.push_back(Vector(x,y,z));
		}
		if(s[0]=='f'){
			string a;int x,y,z;ss>>a>>x>>y>>z;x--;y--;z--;
			f.push_back(Vector(x,y,z));
		}
	}
	double W=min({WIDTH,HEIGHT,DEPTH})/4;
	double scale=W/Max;
	rep(i,(int)v.size()){
		v[i].x=(v[i].x-Min)*scale+W;
		v[i].y=(v[i].y-Min)*scale+W;
		v[i].z=(v[i].z-Min)*scale+W;
	}
	rep(i,(int)f.size()){
		triangle.push_back(Triangle(v[f[i].x],v[f[i].y],v[f[i].z],LAMBERT,Color(0.75,0.25,0.25)));
	}
}