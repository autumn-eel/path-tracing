#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

int n;
#include "raytrace.h"
#include "pathtrace.h"
#include "load.h"
#include "ppm.h"

Color image[SCREEN_HEIGHT][SCREEN_WIDTH];

int main(){
	load_model();
	object_init();
	n=object.size();
	Vector camera(WIDTH/2,HEIGHT/3*2,-1000);
	int dx=(SCREEN_WIDTH-WIDTH)/2,dy=(SCREEN_HEIGHT-HEIGHT)/2;
	#pragma omp parallel for schedule(dynamic, 1) num_threads(4)
	rep(i,SCREEN_HEIGHT){
		cout<<i<<endl;
		rep(j,SCREEN_WIDTH){
			rep(sx,SUPER_SAMPLES)rep(sy,SUPER_SAMPLES){
				rep(k,SAMPLES){
					double t=1./(SUPER_SAMPLES);
					Vector s(j-dx+sx*t+rand_01()*t,i-dy+sy*t+rand_01()*t,0);
					Color res=raytrace(Ray(s,s-camera),0);
					res=Color(min(1.,res.x),min(1.,res.y),min(1.,res.z));
					image[SCREEN_HEIGHT-i-1][j]=image[SCREEN_HEIGHT-i-1][j]+res/SAMPLES/(SUPER_SAMPLES*SUPER_SAMPLES);
				}
			}
		}
		
	}
	save_ppm_file(image);
}