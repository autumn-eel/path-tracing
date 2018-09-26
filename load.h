#pragma once
#include "define.h"
#include "object.h"

void load_model(string path,Color c){
	ifstream file(path.c_str());
	string s;
	vector<Vector>v;
	while(getline(file,s)){
		if(s==""||s[0]=='#')continue;
		stringstream ss(s);
		if(s[0]=='v'){
			string a;double x,y,z;ss>>a>>x>>y>>z;
			v.push_back(Vector(x,y,z));
		}
		if(s[0]=='f'){
			string a;int x,y,z;ss>>a>>x>>y>>z;x--;y--;z--;
			triangle.push_back(Triangle(v[x],v[y],v[z],SPECULAR,c));
		}
	}
}