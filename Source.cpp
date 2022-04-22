#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>



// Task 1

void __fastcall insert_sorted(std::vector<int>& vec, int& a)
{
	vec.push_back(a);
	std::sort(vec.begin(), vec.end());
}

template<class T>
void __fastcall insert_sorted2(std::vector<T>& vec, T& a)
{
	vec.push_back(a);
	std::sort(vec.begin(), vec.end());
}


template<class T>
void __fastcall print_vector(std::vector<T>& vec)
{
	for (auto& v : vec) std::cout << v << " ";
	std::cout << "\n";
}


int main()
{

	std::vector<int> intVec{ 1, 2, 4, 5 };
	std::vector<double> dblVec{ 1.3, 2.5, 4.3, 5.42 };
	int number{ 3 };
	double num{ 4.2 };

	insert_sorted(intVec, number);

	print_vector(intVec);

	insert_sorted2(dblVec, num);

	print_vector(dblVec);

// Task 2

	std::vector<double> a(100);
	std::generate(a.begin(), a.end(), [a = 0.0]() mutable{ return a += 0.5; });

	std::vector<int> b(100);
	copy(a.begin(), a.end(), b.begin());

	print_vector(a);
	print_vector(b);

	std::vector<float> signal(100);

	transform(a.begin(), a.end(), signal.begin(), [](float a) {return pow((a - floor(a)), 2); });

	float result = accumulate(signal.begin(), signal.end(), 0.0);

	std::cout << "The digital signal error is: " << result << "\n";

	return 0;
}