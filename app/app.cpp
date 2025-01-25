#include "app.h"
#include <cmath>
#include <numeric>
#include <iterator>
#include <algorithm>

void vector_from_input(std::istream& ss, std::vector<int>& numbers) {
	std::istream_iterator<int> is(ss), end;
	copy(is, end, std::back_inserter(numbers));
}

void vector_increment(std::vector<int>& numbers) {
	std::iota(std::begin(numbers), std::end(numbers), 1);
}

void vector_increment_by_2(std::vector<int>& numbers) {
	std::generate(std::begin(numbers), std::end(numbers), [i = -1]() mutable { return i += 2; });
}

void cube_vector_values(std::vector<int>& numbers) {
	std::transform(
		std::begin(numbers),
		std::end(numbers),
		std::begin(numbers),
		[](int& x) { return x * x * x; }
	);
}

void calculate_distances_from_origin(std::vector<double>& distances, const int* x, const int x_size, std::vector<int> y) {
	std::transform(
		x,
		x + x_size,
		std::begin(y),
		std::back_inserter(distances),
		[](int a, int b) { return sqrt(a * a + b * b); }
	);
}

double sum_input_stream(std::istream& ss) {
	std::istream_iterator<double> it(ss), end;
	return std::accumulate(it, end, 0.);
}

std::string concatenate_strings(const std::vector<std::string>& _string) {
	return std::accumulate(
		std::begin(_string),
		std::end(_string),
		std::string("GO ")
	);
}

int sum_ages(const std::vector<person>& persons) {
	return std::accumulate(
		std::begin(persons),
		std::end(persons), 
		0, 
		[](int age, person const& p) { return age + p.age; }
	);
}

long long count_negative_values(const std::vector<int>& numbers) {
	return std::count_if(
		std::begin(numbers),
		std::end(numbers),
		[](int num) {
			return num < 0;
		}
	);
}

long long count_invalid_values(const std::vector<double>& numbers){
	return std::count_if(
		std::begin(numbers),
		std::end(numbers),
		[](double num) {
			return num >= 1e10;
		}
	);
}

long long points_in_first_quadrant(const std::vector<point>& points) {
	return std::count_if(
		std::begin(points),
		std::end(points),
		[](point _point) {
			return _point.x >= 0 && _point.y >= 0;
		}
	);
}

int find_first_prime(const std::vector<int>& numbers) {
	return *std::find_if(
		std::begin(numbers),
		std::end(numbers),
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
}

void change_invalid_values(std::vector<double>& numbers) {
	std::replace(
		std::begin(numbers),
		std::end(numbers),
		1e10, 
		-1.
	);
}

bool is_vowel(char _char) {
	std::string vowels = "aeiouAEIOU";
	return vowels.find(_char) != std::string::npos;
}

void change_vowels_with_x(std::string& _string) {
	std::replace_if(
		std::begin(_string),
		std::end(_string),
		is_vowel,
		'x'
	);
}

void delete_invalid_values(std::vector<double>& numbers) {
	numbers.erase(
		std::remove_if(
			std::begin(numbers),
			std::end(numbers),
			[](double num) {
				return num >= 1e10;
			}),
		std::end(numbers)
	);
}

void delete_all_vowels(std::string& _string) {
	_string.erase(
		std::remove_if(
			std::begin(_string),
			std::end(_string),
			is_vowel
		),
		std::end(_string)
	);
}

void sort_exam_vector(std::vector<exam>& exams) {
	std::sort(
		std::begin(exams),
		std::end(exams),
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
		std::begin(numbers),
		std::begin(numbers) + numbers.size() / 2,
		std::end(numbers));
}

double find_smallest(const std::vector<double>& numbers) {
	return *std::min_element(
		std::begin(numbers),
		std::end(numbers)
	);
}

double find_largest(const std::vector<double>& numbers) {
	return *std::max_element(
		std::begin(numbers),
		std::end(numbers)
	);
}

int smallest_difference(std::vector<int> numbers) {
	std::sort(std::begin(numbers), std::end(numbers));
	
	std::vector<int> differences(std::size(numbers));
	std::adjacent_difference(std::begin(numbers), std::end(numbers), std::begin(differences));

	return *std::min_element(std::begin(differences) + 1, std::end(differences));
}