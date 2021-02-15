#include <iostream>
#include <vector>
#include <numeric>

std::vector<float> multiply(std::vector<float>& a, std::vector<float>& b);

int main()
{
	std::vector<float> x{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<float> y{1, 3, 2, 5, 7, 8, 8, 9, 10, 12};

	int n = x.size();
	if (n != y.size())
		throw "x.size() != y.size()";

	std::vector<float> x2 = multiply(x, x);
	std::vector<float> xy = multiply(x, y);

	float sum_x = std::accumulate(x.begin(), x.end(), 0.0f);
	float sum_x2 = std::accumulate(x2.begin(), x2.end(), 0.0f);
	float sum_y = std::accumulate(y.begin(), y.end(), 0.0f);
	float sum_xy = std::accumulate(xy.begin(), xy.end(), 0.0f);

	float b = (n*sum_xy - sum_x*sum_y) / (n*sum_x2 - sum_x*sum_x);
	float a = (sum_y - b*sum_x) / n;

	std::cout << "y = " << a << " + " << b << "x" << std::endl;

	return 0;
}

std::vector<float> multiply(std::vector<float>& a, std::vector<float>& b)
{
	int n = a.size(); std::vector<float> r(n);
	for (int i = 0; i < n; i++)
		r[i] = a[i] * b[i];
	return r;
}
