#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int s) :seed(s) 
{
	if (seed==0){
		std::random_device rd;
		seed=rd();
	}
	rng = std::mt19937(seed);
}

void RandomNumbers::normal(std::vector<double>&norm_double, double mean, double sd){
	std::normal_distribution<> norm_dist(mean, sd);
    for (auto I = norm_double.begin(); I != norm_double.end(); I++) *I = norm_dist(rng);
	
}
double RandomNumbers::normal(double mean, double sd){
	std::normal_distribution<>norm_dist(mean,sd);
	return norm_dist(rng);
}
	
void RandomNumbers::poisson(std::vector<int>& pois_int, double mean){
	std::poisson_distribution<>pois_dist(mean);
	 for (auto I = pois_int.begin(); I != pois_int.end(); I++) *I = pois_dist(rng);
}

int RandomNumbers::poisson (double mean){
	std::poisson_distribution<>pois_dist(mean);
	return pois_dist(rng);
}
	
void RandomNumbers::uniform_double(std::vector<double>& uni_double, double lower, double upper){
    std::uniform_real_distribution<> unif(lower, upper);
    for (auto I = uni_double.begin(); I != uni_double.end(); I++) {
		*I = unif(rng);
	}
}


double RandomNumbers::uniform_double(double lower, double upper){
	std::uniform_real_distribution <> unif_dist(lower,upper);
	return unif_dist(rng);
}




