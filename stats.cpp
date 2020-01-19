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
    vector<vector<double> > outer;
    
    double smallest = v[0];
    const double epsilon = 0.00001;
    int count_of_value = 0;
    
    //finds the smallest value in the vector v.
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < smallest) {
            smallest = v[i];
        }
    }
    
    for (int j = 0; j < v.size(); ++j) {
        
        for (int i = 0; i < v.size(); ++i) {
               
               /* checks if values are equal (must use epsilon
                because double comparison */
               if (abs(smallest - v[i]) < epsilon) {
                   ++count_of_value;
               }
               
               
           }
        /* creates inner vector and vills with with
         (value, frequency) pairs. */
        vector<double> inner(2);
        inner[0] = smallest;
        inner[1] = static_cast<double>(count_of_value);
        
        outer.push_back(inner);
        
        double old_smallest = smallest;
        count_of_value = 0;
        
        //finds any value in v that is larger than the last smallest value
        for (int k = 0; k < v.size(); k++) {
            if ((abs(v[k] - old_smallest) > epsilon) && (v[k] > old_smallest)) {
                smallest = v[k];
            }
            
        }
        /* This for loop finds the next smallest value by making sure v[m]
         satisfies the following 3 conditions:
            1. v[k] is a different number than the old_smallest
            2. v[k] is greater than the old_smallest
            3. v[k] is less than smallest
         */
        for (int m = 0; m < v.size(); ++m) {
            if (abs(v[m] - old_smallest) > epsilon) {
                if (v[m] > old_smallest) {
                    if (v[m] < smallest) {
                        smallest = v[m];
                    }
                }
            }
        }
        
    }
   
    
    return outer;
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
