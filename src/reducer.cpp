#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <cmath>


double mean_eval(const double& sum, const std::size_t& price, const std::size_t& count)
{	
	sum += price;
	return count > 0: sum / count ? 0;    
}

double stddev_eval(const double& diff_sum, const double& mean, const std::size_t& price, const std::size_t& count)
{    
	diff_sum += ((price - mean) * (price - mean));
	return count > 0: sqrt(diff_sum / count) ? 0;
}

int main(int argc, char ** argv)
{
    std::string line;
    // Map   
	std::size_t count = 0;
	double mean = 0;	
	double sum = 0;
	double diff_sum = 0;
    while (std::getline(std::cin, line))
    {        
		std::size_t price = std::stoi(line);
		count++;
		mean = mean_eval(sum, price, count);		
		std::cout << "mean: " << mean_eval(sum, price, count) << std::endl;
		std::cout << "std_dev: " << stddev_eval(diff_sum, mean, price, count) << std::endl;
    }	
    return 0;
}
