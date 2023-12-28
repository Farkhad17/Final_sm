#include <iostream>
#include <vector>
#include <math.h>
#include <gtest/gtest.h>

#include "shoot.cpp"
#include "f.cpp"

std::vector <double> u;

TEST(matrixTests,values){
	std::vector<double> testVec = {{2.0}, {2.02657}, {2.05253}, {2.07671}, {2.09741}, {2.11241}, {2.11906}, {2.11437}, {2.09516}, {2.05811}, {2.0}};
	
	for(int i = 0; i < 11; i++){
		ASSERT_LT(fabs(u[i] - testVec[i]), 1e-2);
	}
}

int main(int argc, char* argv[]){
	
	int i, n, default_value = 0;
	double ksi1, ksi2, h;
	
	try{
		ksi1 = std::stod(argv[1]);
		ksi2 = std::stod(argv[2]);
		h = std::stod(argv[3]);
		n = std::stod(argv[4]);;
	}
	catch(...){
		std::cout << "Not able to parse arguments" << std::endl;
	}
	std::vector <double> x(n, default_value);
	std::vector <double> y(n, default_value);
	
	
	double ksi, min_ksi, min_shoot;
	
	min_ksi = ksi1;	
	min_shoot = shoot(min_ksi, x, y, n);
	
	for(ksi = ksi1; ksi < ksi2; ksi +=h){
		if(fabs(min_shoot) > fabs(shoot(ksi, x, y, n))){
			min_shoot = shoot(ksi, x, y, n);
			min_ksi = ksi;
		}
		//std::cout << "ksi = " << ksi << " shoot = " << shoot(ksi) << std::endl;
	}
	std::cout << std::endl;
	
	if(min_shoot > 1){
		std::cout << "plohiye nachalniye usloviya" << std::endl;
		return 0;
	}
	
	shoot(min_ksi, x, y, n);
	
	std::cout << "ksi = " << min_ksi << " pogreshnost = " << fabs(min_shoot) << std::endl << std::endl;
	
	for(i = 0; i < n; i++){
		std::cout << "x[" << i << "] = " << x[i] << " y[" << i << "] = " << y[i] <<std::endl;
	}
	
	u = y; 
	::testing::InitGoogleTest();
	
	return RUN_ALL_TESTS();
}


