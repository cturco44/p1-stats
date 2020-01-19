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
    vector<vector<double> > outer(0);
    
    int total = 0;
    double smallest = v[0];
    double largest = v[0];
    const double epsilon = 0.00001;
    int count_of_value = 0;
    
    //finds the smallest value in the vector v.
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < smallest) {
            smallest = v[i];
        }
    }
    //finds the largest value in the vector v.
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > largest) {
            largest = v[i];
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
        total += count_of_value;
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
        if (total == v.size()) {
            return outer;
        }
        
    }
   
    
    return outer;
}

int count(vector<double> v) {
    int size = static_cast<int>(v.size());
    return size;
}

double sum(vector<double> v) {
    double sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    return sum;
}


double mean(vector<double> v) {
    double mean;
    mean = sum(v)/(v.size());
    return mean;
    
}

double median(vector<double> v) {
    int size = static_cast<int>(v.size());
    
    if ((size % 2) == 0) {
        //even
        int numbers_in_front = ((size - 2)/2);
        
        double value1 = v[numbers_in_front];
        double value2 = v[numbers_in_front + 1];
        
        vector<double> median_values(2);
        median_values[0] = value1;
        median_values[1] = value2;
        
        return mean(median_values);
    }
    else {
        //odd
        int numbers_in_front = ((size - 1)/2);
        
        return v[numbers_in_front];
    }
   
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
