// If you change anything in this file, your changes will be ignored 
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include <gtest/gtest.h>
#include "../code/Sorting.h"

#include <fstream>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class test_Sorting : public ::testing::Test {
protected:
	static void SetUpTestCase(){
	}

	// This function runs only once before any TEST_F function
	static void TearDownTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open())
		outgrade.clear();

		max_grade = 23;

		outgrade << (int)std::ceil(100*total_grade/max_grade);
		outgrade.close();

		std::cout << "Total Grade is : " << (int)std::ceil(100*total_grade/max_grade) << std::endl;
	}

	// This function runs after all TEST_F functions have been executed
	void add_points_to_grade(int points){
		max_grade += points;
		if(!::testing::Test::HasFailure()){
			total_grade += points;
		}
	}

	// this function runs before every TEST_F function
	void SetUp() override {}

	// this function runs after ever TEST_F function
	void TearDown() override {}
	
	static int total_grade;
	static int max_grade;
};

int test_Sorting::total_grade = 0;
int test_Sorting::max_grade = 0;


TEST_F(test_Sorting, TestConstructor){
	Sorting mysorting;

	add_points_to_grade(2);
}
