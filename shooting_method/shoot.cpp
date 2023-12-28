#include <iostream>
#include <vector>
#include <math.h>
#include <string>

double shoot(double ksi, std::vector<double> &x_n, std::vector<double> &y_n, int n){
	int i, default_value = 0;	
	double h, z_1, y_1;

	h = 1.0/(n - 1);
	std::vector <double> x(n, default_value);
	std::vector <double> y(n, default_value);
	std::vector <double> z(n, default_value);
	
	y[0] = 2;
	z[0] = ksi;
		
	for(i = 0; i < n; i++){
		x[i] = i*h;
	}	
		
	for(i = 0; i < n - 1; i++){
		y_1 = y[i] + 0.5*h*z[i];
		z_1 = z[i] + 0.5*h*(-z[i]*sin(x[i]) - x[i]*x[i]*y[i] - x[i]*x[i]);
		y[i+1] = y[i] + h*z_1;
		z[i+1] = z[i] + h*(-z_1*sin(x[i] + 0.5*h) - (x[i] + 0.5*h)*(x[i] + 0.5*h)*y_1 - (x[i] + 0.5*h)*(x[i] + 0.5*h));
	}
	//printf("%.8lf\n",y[n-1]);
	//std::cout << std::setprecision(5) << y[n - 1] << std::endl; 
	
	for(i = 0; i < n; i++){
		x_n[i] = x[i];
		y_n[i] = y[i];
	}
	
	return y[n-1] - 2.0;
}

