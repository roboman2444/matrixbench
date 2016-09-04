#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "globaldefs.h"
#include <math.h>

#include "matrixlib.h"
#include "mathlib.h"



int main(void){
	vec3_t a = {100.0, 200.0, 20.0};
	vec3_t b = {200.0, 300.0, 10.0};
	vec3_t c;
	vec4_t la = {100.0, 200.0, 20.0, 2.1};
	vec4_t lb = {200.0, 300.0, 10.0, 1.2};
	vec4_t lc;
	matrix4x4_t m1,m2,m3;
	Matrix4x4_CreateTranslate(&m1, 100.0, 200.0, 20.0);
	Matrix4x4_CreateRotate(&m2, 100.0, 100.0, 200.0, 20.0);
	vec_t res, prevres;
	struct timespec tstart={0,0}, tend = {0,0};
	unsigned int i;
	double time;
	prevres = vec3distvec(a,b);
	//get processor warmed up
	for(i = 0; i< 100000;i++){
		res = vec3distvec(a,b);
	}




	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(i = 0; i< 10000000;i++){
		res = vec3distvec(a,b);
		if(prevres != res){
			printf("ERRRRRRRR\n");
		}
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	time = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec)-((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	printf("vec3distvec time = %.5f, result = %f\n\n", time, res);




	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(i = 0; i< 10000000;i++){
		res = vec3distveci(a,b);
		if(prevres != res){
			printf("ERRRRRRRR\n");
		}
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	time = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec)-((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	printf("vec3distveci time = %.5f, result = %f\n\n", time, res);





	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(i = 0; i< 10000000;i++){
		Matrix4x4_Concat(&m3, &m1, &m2);
		Matrix4x4_Concat(&m3, &m2, &m1);
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	time = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec)-((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	printf("Matrix4x4_Concat time = %.5f\n", time);
	for(i = 0; i < 4; i++){
		printf("%f %f %f %f\n", m3.m[i][0],m3.m[i][1],m3.m[i][2],m3.m[i][3]);
	}
	printf("\n");

	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(i = 0; i< 10000000;i++){
		Matrix4x4_Concatsimd(&m3, &m1, &m2);
		Matrix4x4_Concatsimd(&m3, &m2, &m1);
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	time = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec)-((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	printf("Matrix4x4_Concatsimd time = %.5f\n", time);
	for(i = 0; i < 4; i++){
		printf("%f %f %f %f\n", m3.m[i][0],m3.m[i][1],m3.m[i][2],m3.m[i][3]);
	}
	printf("\n");




	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(i = 0; i< 10000000;i++){
		Matrix4x4_Concatsimdu(&m3, &m1, &m2);
		Matrix4x4_Concatsimdu(&m3, &m2, &m1);
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	time = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec)-((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	printf("Matrix4x4_Concatsimdu time = %.5f\n", time);
	for(i = 0; i < 4; i++){
		printf("%f %f %f %f\n", m3.m[i][0],m3.m[i][1],m3.m[i][2],m3.m[i][3]);
	}
	printf("\n");





	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(i = 0; i< 10000000;i++){
		Matrix4x4_Transform(&m3, a, c);
		Matrix4x4_Transform(&m3, b, c);
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	time = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec)-((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	printf("Matrix4x4_Transform time = %.5f\n", time);
	printf("%f %f %f\n\n", c[0], c[1], c[2]);



	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(i = 0; i< 10000000;i++){
		Matrix4x4_Transformsimd(&m3, a, c);
		Matrix4x4_Transformsimd(&m3, b, c);
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	time = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec)-((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	printf("Matrix4x4_Transformsimd time = %.5f\n", time);
	printf("%f %f %f\n\n", c[0], c[1], c[2]);

	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(i = 0; i< 10000000;i++){
		Matrix4x4_Transformsimdu(&m3, a, c);
		Matrix4x4_Transformsimdu(&m3, b, c);
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	time = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec)-((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	printf("Matrix4x4_Transformsimdu time = %.5f\n", time);
	printf("%f %f %f\n\n", c[0], c[1], c[2]);








	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(i = 0; i< 10000000;i++){
		Matrix4x4_Transform4(&m3, la, lc);
		Matrix4x4_Transform4(&m3, lb, lc);
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	time = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec)-((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	printf("Matrix4x4_Transform4 time = %.5f\n", time);
	printf("%f %f %f %f\n\n", lc[0], lc[1], lc[2], lc[3]);



	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(i = 0; i< 10000000;i++){
		Matrix4x4_Transform4simd(&m3, la, lc);
		Matrix4x4_Transform4simd(&m3, lb, lc);
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	time = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec)-((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	printf("Matrix4x4_Transform4simd time = %.5f\n", time);
	printf("%f %f %f %f\n\n", lc[0], lc[1], lc[2], lc[3]);

	clock_gettime(CLOCK_MONOTONIC, &tstart);
	for(i = 0; i< 10000000;i++){
		Matrix4x4_Transform4simdu(&m3, la, lc);
		Matrix4x4_Transform4simdu(&m3, lb, lc);
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	time = ((double)tend.tv_sec + 1.0e-9 * tend.tv_nsec)-((double)tstart.tv_sec + 1.0e-9 * tstart.tv_nsec);
	printf("Matrix4x4_Transform4simdu time = %.5f\n", time);
	printf("%f %f %f %f\n\n", lc[0], lc[1], lc[2], lc[3]);

	return 0;
}
