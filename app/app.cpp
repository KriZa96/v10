#include "app.h"
#include <algorithm>
#include<cmath>
#include <numeric>
#include <limits>
#include <unordered_set>


void vector_from_input(std::istream& ss, std::vector<int>& numbers) {
	int input;
	int index{ 0 };

	while (ss >> input) numbers.push_back(input);
}

void vector_increment(std::vector<int>& numbers, int step) {
	int start = 1;
	std::for_each(
		numbers.begin(),
		numbers.end(),
		[&start, step](int& num) {
			num = start;
			start += step;
		}
	);
}

void cube_vector_values(std::vector<int>& numbers) {
	std::for_each(
		numbers.begin(),
		numbers.end(),
		[](int& num) {
			num = num * num * num;
		}
	);
}

void calculate_distances_from_origin(std::vector<double>& distances, const int* x, const int x_size, const std::vector<int> y) {
	for (int i = 0; i < y.size() && i < x_size; ++i) {
		distances.push_back(sqrt(x[i]*x[i] + y[i]*y[i]));
	};
}

double sum_input_stream(std::istream& ss) {
	double sum;
	double result{ 0 };

	while (ss >> sum) result += sum;

	return result;
}

std::string concatenate_strings(const std::vector<std::string>& _string) {
	std::string result = "GO ";

	std::for_each(
		_string.begin(),
		_string.end(),
		[&result](std::string _string) {
			result += _string;
		}
	);

	return result;
}

int sum_ages(const std::vector<person>& persons) {
	int age_sum{0};

	std::for_each(
		persons.begin(),
		persons.end(),
		[&age_sum](person _person) {
			age_sum += _person.age;
		}
	);

	return age_sum;
}

long long count_negative_values(const std::vector<int>& numbers) {
	return std::count_if(
		numbers.begin(),
		numbers.end(),
		[](int num) {
			return num < 0;
		}
	);
}

long long count_invalid_values(const std::vector<double>& numbers){
	return std::count_if(
		numbers.begin(),
		numbers.end(),
		[](double num) {
			return num >= 1e10;
		}
	);
}

long long points_in_first_quadrant(const std::vector<point>& points) {
	return std::count_if(
		points.begin(),
		points.end(),
		[](point _point) {
			return _point.x >= 0 && _point.y >= 0;
		}
	);
}

int find_first_prime(const std::vector<int>& numbers) {
	auto first_prime = std::find_if(
		numbers.begin(),
		numbers.end(),
		[](int num) {
			if (num <= 0) {
				return false;
			}

			for (int i = 2; i < sqrt(num)+1; ++i) {
				if (num % i == 0) {
					return false;
				}
			}

			return true;
		}
	);

	return *first_prime;
}

void change_invalid_values(std::vector<double>& numbers) {
	std::for_each(
		numbers.begin(),
		numbers.end(),
		[](double& num) {
			if (num >= 1e10) {
				num = -1;
			}
		}
	);
}

void change_vowels_with_x(std::string& _string) {
	const std::unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

	std::replace_if(
		_string.begin(),
		_string.end(),
		[&vowels](char _char) {
			return vowels.find(_char) != vowels.end();
		},
		'x'
	);
}

void delete_invalid_values(std::vector<double>& numbers) {
	numbers.erase(
		std::remove_if(
			numbers.begin(),
			numbers.end(),
			[](double num) {
				return num >= 1e10;
			}),
		numbers.end()
	);
}

void delete_all_vowels(std::string& _string) {
	const std::unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
	_string.erase(
		std::remove_if(
			_string.begin(),
			_string.end(),
			[vowels](char _char) {
				return vowels.find(_char) != vowels.end();
			}
		),
		_string.end()
	);
}

void sort_exam_vector(std::vector<exam>& exams) {
	std::sort(
		exams.begin(),
		exams.end(),
		[](const exam& a, const exam& b) {
			if (a.grade != b.grade) {
				return a.grade > b.grade;
			}
			return a.points > b.points;
		}
	);
}

void set_median_to_middle_of_vector(std::vector<double>& numbers) {
	std::nth_element(
		numbers.begin(),
		numbers.begin() + numbers.size() / 2,
		numbers.end());
}

double find_smallest(const std::vector<double>& numbers) {
	return *std::min_element(
		numbers.begin(),
		numbers.end()
	);
}

double find_largest(const std::vector<double>& numbers) {
	return *std::max_element(
		numbers.begin(),
		numbers.end()
	);
}

int smallest_difference(const std::vector<int>& numbers) {
	int smallest{ std::numeric_limits<int>::max() };

	int diff;
	for (int i = 0; i < numbers.size(); ++i) {
		for (int j = i + 1; j < numbers.size(); ++j) {
			diff = std::abs(numbers[i] - numbers[j]);
			if (diff < smallest) {
				smallest = diff;
			}
		}
	}

	return smallest;
}