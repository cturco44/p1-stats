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
        
        double potential = smallest;
        count_of_value = 0;
        
        //finds any value in v that is larger than the smallest value
        
        for (int g = 0; g < v.size(); ++g) {
            
            if (v[g] - smallest > epsilon) {
                potential = v[g];
            }
        }
        
        for (int k = 0; k < v.size(); ++k) {
            
            if ((abs(v[k] - potential) < epsilon) && ((potential - smallest) < epsilon)) {
                if (potential > smallest) {
                    potential = v[k];
                }
            }
        }
        smallest = potential;
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
