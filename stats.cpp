// stats.cpp
#include "stats.h"
#include <cassert>
#include <vector>

//added
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

vector<vector<double> > summarize(vector<double> v) {
    //outer vector that will be returned by the function
    vector<double> outer;
    
    double smallest = v[0];
    const double epsilon = 0.00001;
    int count_of_value = 0;
    
    //finds the smallest value in the vector v.
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < smallest) {
            smallest = v[i];
        }
    }
    
    
    for (int i = 0; i < v.size(); ++i) {
        
        /* if values are equal (must use epsilon because double comparison */
        if (abs(smallest - v[i]) < epsilon) {
            ++count_of_value;
        }
        
        
    }
    
    assert(false);
}

int count(vector<double> v) {
  assert(false);
}

double sum(vector<double> v) {
  assert(false);
}

double mean(vector<double> v) {
  assert(false);
}

double median(vector<double> v) {
  assert(false);
}

double mode(vector<double> v) {
  assert(false);
}

double min(vector<double> v) {
  assert(false);
}

double max(vector<double> v) {
  assert(false);
}

double stdev(vector<double> v) {
  assert(false);
}

double percentile(vector<double> v, double p) {
  assert(false);
}
