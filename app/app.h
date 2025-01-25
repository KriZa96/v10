#include <string>
#include <vector>
#include <iostream>

#pragma once

struct person { 
	std::string name;
	int age;
};

struct point {
	int x;
	int y;
};

struct exam { 
	std::string name;
	int points, grade;
};

void vector_from_input(std::istream& ss, std::vector<int>& numbers);

void vector_increment(std::vector<int>& numbers);

void vector_increment_by_2(std::vector<int>& numbers);

void cube_vector_values(std::vector<int>& numbers);

void calculate_distances_from_origin(std::vector<double>& distances, const int* x, const int x_size, std::vector<int> y);

double sum_input_stream(std::istream& ss);

std::string concatenate_strings(const std::vector<std::string>& _string);

int sum_ages(const std::vector<person>& persons);

long long count_negative_values(const std::vector<int>& numbers);

long long count_invalid_values(const std::vector<double>& numbers);

long long points_in_first_quadrant(const std::vector<point>& points);

int find_first_prime(const std::vector<int>& numbers);

void change_invalid_values(std::vector<double>& numbers);

void change_vowels_with_x(std::string& _string);

void delete_invalid_values(std::vector<double>& numbers);

void delete_all_vowels(std::string& _string);

void sort_exam_vector(std::vector<exam>& exams);

void set_median_to_middle_of_vector(std::vector<double>& numbers);

double find_smallest(const std::vector<double>& numbers);

double find_largest(const std::vector<double>& numbers);

int smallest_difference(std::vector<int> numbers);