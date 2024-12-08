#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <cmath>


double mean_eval(const std::vector<int>& m_out) {
    return std::accumulate(m_out.begin(), m_out.end(), 0.0) / m_out.size();
}

double stddev_eval(const std::vector<int>& m_out) {
    double diff_sum = 0;
    double m = mean_eval(m_out);
    for (auto it = m_out.begin(); it != m_out.end(); ++it)
        diff_sum += ((*it - m) * (*it - m));

    return sqrt(diff_sum / m_out.size());
}

int main(int argc, char ** argv)
{
    std::string line;
    // Map
    std::vector<int> map_output;
    while (std::getline(std::cin, line))
    {
        map_output.emplace_back(std::stoi(line));
    }

    // Calculate mean value
    std::cout << "mean: " << mean_eval(map_output) << std::endl;

    // Calculate standard deviation
    std::cout << "std_dev: " << stddev_eval(map_output) << std::endl;

    return 0;
}
