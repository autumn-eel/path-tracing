#pragma once

int to_int(double x){
	return pow(max(0.,min(x,1.)),1/2.2)*255+0.5;
}

void save_ppm_file(Color image[][SCREEN_WIDTH]){
	FILE*file=fopen("image.ppm","w");
	fprintf(file,"P3\n%d %d\n255\n",SCREEN_WIDTH,SCREEN_HEIGHT);
	rep(i,SCREEN_HEIGHT)rep(j,SCREEN_WIDTH){
		fprintf(file,"%d %d %d ",to_int(image[i][j].x),to_int(image[i][j].y),to_int(image[i][j].z));
	}
	fclose(file);
}