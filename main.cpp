#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

int cnt=0;
#include "pathtrace.h"
#include "load.h"
#include "ppm.h"

Color image[SCREEN_HEIGHT][SCREEN_WIDTH];

int main(){
	auto start=chrono::system_clock::now();
	load_model("object.obj",Color(0.75,0.25,0.25));
	object_init();
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
					Color res=pathtrace(Ray(s,s-camera),0);
					image[SCREEN_HEIGHT-i-1][j]=image[SCREEN_HEIGHT-i-1][j]+res/SAMPLES/(SUPER_SAMPLES*SUPER_SAMPLES);
				}
			}
		}
	}
	save_ppm_file(image);
	auto end=chrono::system_clock::now();
	double tim=chrono::duration_cast<chrono::milliseconds>(end-start).count();
	printf("time = %.3lf sec",tim/1000);
}