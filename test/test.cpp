#include "CppUnitTest.h"

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <random>
#include "../app/app.h"

using namespace std::string_literals;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace all_tests
{
	TEST_CLASS(test_v10)
	{
	public:
		TEST_METHOD(test_01)
		{
			std::stringstream ss("14 -78 22");
			std::vector<int> v;
			vector_from_input(ss, v);
			Assert::AreEqual(3ull, v.size());
			Assert::AreEqual(14, v[0]);
			Assert::AreEqual(-78, v[1]);
			Assert::AreEqual(22, v[2]);

		}
		TEST_METHOD(test_02a)
		{
			std::vector<int> v(10);
			vector_increment(v);
			Assert::AreEqual(10ull, v.size());
			Assert::IsTrue(std::is_sorted(v.cbegin(), v.cend()));
			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(10, v[9]);
		}
		TEST_METHOD(test_02b)
		{
			std::vector<int> v(10);
			vector_increment(v, 2);
			Assert::IsTrue(std::is_sorted(v.cbegin(), v.cend()));
			Assert::IsTrue(v.cend() == std::adjacent_find(v.cbegin(), v.cend(), [](int a, int b) { return b - a != 2;  }));
			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(19, v[9]);
		}

		TEST_METHOD(test_03a)
		{
			std::vector<int> v = { 1, 5, 10 };
			cube_vector_values(v);
			Assert::AreEqual(3ull, v.size());
			Assert::AreEqual(1, v[0]);
			Assert::AreEqual(125, v[1]);
			Assert::AreEqual(1000, v[2]);
		}
		TEST_METHOD(test_03b)
		{
			int x[] = { 3, 5, 10 };
			std::vector<int> y = { 4, 12, 10 };
			std::vector<double> d;
			calculate_distances_from_origin(d, x, 3, y);
			Assert::AreEqual(3ull, d.size());
			Assert::AreEqual(5., d[0]);
			Assert::AreEqual(13., d[1]);
			Assert::AreEqual(sqrt(200), d[2]);
		}
		TEST_METHOD(test_04a)
		{
			std::stringstream ss("1.5 2.5 3.5");
			auto res = sum_input_stream(ss);
			Assert::AreEqual(7.5, res);
		}
		TEST_METHOD(test_04b)
		{
			std::vector<std::string> v{ "V", "S", "I", "T", "E", "!" };
			auto res = concatenate_strings(v);
			Assert::AreEqual("GO VSITE!"s, res);
		}
		TEST_METHOD(test_04c)
		{
			std::vector<person> v{ {"Pero", 33}, {"Iva", 25} };
			auto total_age = sum_ages(v);
			Assert::AreEqual(58, total_age);
		}

		TEST_METHOD(test_05a)
		{
			std::vector<int> v{ -5, 8, 11, 0, -9, 77, -4 };
			auto number_of_negative = count_negative_values(v);
			Assert::AreEqual(3ll, number_of_negative);
		}
		TEST_METHOD(test_05b)
		{
			std::vector<double> v{ 1.5, 8, -11.23, 0, 1e10, 1e10, 1e10, 0, 99 };
			auto number_of_invalid = count_invalid_values(v);
			Assert::AreEqual(3ll, number_of_invalid);
		}
		TEST_METHOD(test_05c)
		{
			std::vector<point> v{ {1,1}, {-5,3}, {2,2}, {-7,-6}, {9,-4} };
			auto number_in_first_quadrant = points_in_first_quadrant(v);
			Assert::AreEqual(2ll, number_in_first_quadrant);
		}

		TEST_METHOD(test_06)
		{
			std::vector<int> v{ 33, 16, 24, 41, 25, 19, 9 };
			auto first_prime = find_first_prime(v);
			Assert::AreEqual(41, first_prime);
		}
		TEST_METHOD(test_07a)
		{
			std::vector<double> v{ 1e10, 8, -11.23, 0, 1e10, 1e10, 1e10, 0, 99 };
			change_invalid_values(v);
			Assert::AreEqual(-1., v[0]);
			Assert::AreEqual(-1., v[4]);
			Assert::AreEqual(-1., v[6]);
		}
		TEST_METHOD(test_07b)
		{
			std::string s("neisporuka");
			change_vowels_with_x(s);
			Assert::AreEqual("nxxspxrxkx"s, s);
		}
		TEST_METHOD(test_08a)
		{
			std::vector<double> v{ 1e10, 8, -11.23, 0, 1e10, 1e10, 1e10, 0, 99 };
			delete_invalid_values(v);
			Assert::AreEqual(5ull, v.size());
			Assert::AreEqual(8., v[0]);
			Assert::AreEqual(99., v[4]);
		}

		TEST_METHOD(test_08b)
		{
			std::string s("poliuretan");
			delete_all_vowels(s);
			Assert::AreEqual("plrtn"s, s);
		}
		TEST_METHOD(test_09)
		{
			std::vector<exam> v{ {"Pero", 55, 2}, {"Iva", 93, 5}, {"Marko", 89, 5} };
			sort_exam_vector(v);
			Assert::AreEqual("Iva"s, v[0].name);
			Assert::AreEqual("Marko"s, v[1].name);
			Assert::AreEqual("Pero"s, v[2].name);

		}
		TEST_METHOD(test_10)
		{
			std::vector<double> v(2e7);
			std::generate(v.begin(), v.begin() + v.size() / 2, []() { return rand() % 1000; });
			std::generate(v.begin() + v.size() / 2, v.end(), []() { return 1001 + rand() % 1000; });
			v.push_back(1000);

			std::random_device rd;
			std::mt19937 g(rd());
			std::shuffle(v.begin(), v.end(), g);
			set_median_to_middle_of_vector(v);
			Assert::AreEqual(1000., v[v.size() / 2]);
		}
		TEST_METHOD(test_11)
		{
			std::vector<double> v{ 11, 0.5, -97.23, -23.11, 48.78, 22.96, -77 };
			auto smallest_value = find_smallest(v);
			Assert::AreEqual(-97.23, smallest_value);
			auto largest_value = find_largest(v);
			Assert::AreEqual(48.78, largest_value);
		}
		TEST_METHOD(test_12)
		{
			std::vector<int> atp_points{ 8445, 7480, 6220, 5300, 5285 };
			auto _smallest_difference = smallest_difference(atp_points);
			Assert::AreEqual(15, _smallest_difference);
		}
	};
}
