#pragma once

uint xor128(){
	static uint x=123456789,y=362436069,z=521288629,w=88675123;
	uint t=x^(x<<11);
	x=y;y=z;z=w;
	return w=(w^(w>>19))^(t^(t>>8));
}

double rand_01(){
	return xor128()/(double)UINT_MAX;
}