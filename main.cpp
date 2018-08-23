#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

int n;

#include "raytrace.h"
#include "pathtrace.h"
#include "ppm.h"

Color image[SCREEN_HEIGHT][SCREEN_WIDTH];

int main(){
	Vector camera(WIDTH/2,-1000,HEIGHT/2);
	int dx=(SCREEN_WIDTH-WIDTH)/2,dy=(SCREEN_HEIGHT-HEIGHT)/2;
	n=sizeof(object)/sizeof(SphereObject);
	#pragma omp parallel for num_threads(4)
	rep(i,SCREEN_HEIGHT){
		cout<<i<<endl;
		rep(j,SCREEN_WIDTH){
			rep(sx,SUPER_SAMPLES)rep(sy,SUPER_SAMPLES){
				rep(k,SAMPLES){
					double t=1./SUPER_SAMPLES;
					Vector s(j-dx+sx*t,0,i-dy+sy*t);
					image[SCREEN_HEIGHT-i-1][j]=image[SCREEN_HEIGHT-i-1][j]+raytrace(Ray(s,s-camera),0)/SAMPLES/(SUPER_SAMPLES*SUPER_SAMPLES);
				}
			}
		}
	}
	save_ppm_file(image);
}