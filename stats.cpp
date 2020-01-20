// stats.cpp
#include "stats.h"
#include <cassert>
#include <vector>
#include <iostream>

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
    
    double smallest = v[0];
    const double epsilon = 0.00001;
    
    vector<double>sorted;
    
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < smallest) {
            smallest = v[i];
        }
    }
    
    sorted.push_back(smallest);
    double old_smallest = smallest;
    
    int count = 0;
    while(count < v.size()) {
        for (int k = 0; k < v.size(); k++) {
            if ((abs(v[k] - old_smallest) > epsilon) && (v[k] > old_smallest)) {
                smallest = v[k];
            }
            
        }
        
        for (int m = 0; m < v.size(); ++m) {
            if (abs(v[m] - old_smallest) > epsilon) {
                if (v[m] > old_smallest) {
                    if (v[m] < smallest) {
                        smallest = v[m];
                        
                        
                    }
                }
            }
        }
        sorted.push_back(smallest);
        old_smallest = smallest;
        ++count;
        
    }
    
    for (int j = 0; j < v.size(); ++j) {
        cout << sorted[j] << ", ";
    }
    
   
    
    return 5.0;
    
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
