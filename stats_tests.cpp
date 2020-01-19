/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();
void test_summarize();
bool check_vectors(vector<double> v1, vector<double> v2);

// Add prototypes for you test functions here.

int main()
{
  //test_sum_small_data_set();
  // Call your test functions here
    test_summarize();
    
    

  return 0;
}
bool check_vectors(vector<double> v1, vector<double> v2) {
    bool same = false;
    const double epsilon = 0.00001;
    
    if ((abs(v1[0]-v2[0]) < epsilon) && (abs(v1[1] - v2[1])) < epsilon) {
        same = true;
    }
    
    
    return same;
}

void test_summarize() {
    vector<double> test1;
    
    test1.push_back(5.3);
    test1.push_back(3);
    test1.push_back(8);
    test1.push_back(5.3);
    test1.push_back(5.47);
    test1.push_back(3.8);
    test1.push_back(8);
    
    vector<vector <double> > bigtest1;
    
    bigtest1 = summarize(test1);
    vector<double> vector_at_0(2);
    vector_at_0[0] = 3;
    vector_at_0[1] = 1;
    
    vector<double> vector_at_1(2);
    vector_at_1[0] = 3.8;
    vector_at_1[1] = 1;
        
    vector<double> vector_at_2(2);
    vector_at_2[0] = 5.3;
    vector_at_2[1] = 2;
    
    vector<double> vector_at_3(2);
    vector_at_3[0] = 5.47;
    vector_at_3[1] = 1;
    
    vector<double> vector_at_4(2);
    vector_at_4[0] = 8;
    vector_at_4[1] = 2;
    
    cout << "Checking vectors" << endl;
    assert(check_vectors(bigtest1[0], vector_at_0));
    assert(check_vectors(bigtest1[1], vector_at_1));
    assert(check_vectors(bigtest1[2], vector_at_2));
    assert(check_vectors(bigtest1[3], vector_at_3));
    assert(check_vectors(bigtest1[4], vector_at_4));
    
    cout << "All vector assert statements passed" << endl;
    
    
    
}

void test_sum_small_data_set()
{
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;
}

// Add the test function implementations here.
