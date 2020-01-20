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
#include "p1_library.h"

using namespace std;

vector<vector<double> > summarize(vector<double> v) {
    //outer vector that will be returned by the function
    vector<vector<double> > outer;
    
    double maximum = max(v);
    const double epsilon = 0.00001;
    int frequency = 0;
    int total_frequency = 0;
    int size = count(v);
    sort(v);
    
    
    double num_holder = v[0];
    int i = 0;
    
    for (int j = 0; j < size; ++j) {
        vector<double> holder(2);
        while(abs(v[i] - num_holder) < epsilon) {
              ++frequency;
              ++i;
        }
        holder[0] = num_holder;
        holder[1] = frequency;
        frequency = 0;
        total_frequency += frequency;
        outer.push_back(holder);
        if (abs(holder[0] - maximum) < epsilon) {
            return outer;
        }
        
        vector<double> unused;
        for (int k = 0; k < size; ++k) {
            
            if ((abs(v[k] - num_holder) > epsilon) && v[k] > num_holder) {
                unused.push_back(v[k]);
            }
        }
        
        num_holder = min(unused);
        
        
    }
    
    return outer;
}

int count(vector<double> v) {
    
    // v.size is casted to an int and returned.
    int size = static_cast<int>(v.size());
    return size;
}

double sum(vector<double> v) {
    double sum = 0;
    
    /* A for loop is used to iterate over vector and increase sum by each value
     * in the vector
     */
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    return sum;
}


double mean(vector<double> v) {
    double mean;
    
    // The mean is the sum of the vector is divided by the size of the vector.
    mean = sum(v)/(v.size());
    return mean;
    
}

double median(vector<double> v) {
    int size = static_cast<int>(v.size());
    vector<double>sorted;
    
    //Vector returned from summarize is saved into holder.
    vector<vector<double> > holder = summarize(v);
    
    
    for (int i = 0; i < holder.size(); ++i) {
        //The vector at [i] is saved into temp
        vector<double> temp = holder[i];
        int number_of_value = static_cast<int>(temp[1]);
        
        /* The double at temp[0] is added to the back of the vector how ever
         * many times it occured (its frequency. (This method was used because
         * I did not yet realize there was a sort function).
         */
        for (int j = 0; j < number_of_value; ++j) {
            sorted.push_back(temp[0]);
            
        }
    }
    /* If there is an even count, the median will be the mean of the two middle
     * values.
     */
    if ((size % 2) == 0) {
        
        int numbers_in_front = ((size - 2)/2);
        
        // The two middle values are stored in a vector
        double value1 = sorted[numbers_in_front];
        double value2 = sorted[numbers_in_front + 1];
        
        vector<double> median_values(2);
        median_values[0] = value1;
        median_values[1] = value2;
        
        // The mean of the two middle values is calculated using mean function.
        return mean(median_values);
    }
    // If the count is odd, the middle value is returned
    else {
        int numbers_in_front = ((size - 1)/2);
        
        return sorted[numbers_in_front];
    }

    
}

double mode(vector<double> v) {
    int old_number = 0;
    int highest_amount = 0;
    vector<vector<double> > holder = summarize(v);
    
    /* For loop iterates over frequency values in holder to find which one is
     * the largest. This value is saved to highest_amount.
     */
    for (int i = 0; i < holder.size(); ++i) {
        vector<double> temp = holder[i];
        int number_of_value = static_cast<int>(temp[1]);
        
        if (number_of_value > old_number) {
            highest_amount = number_of_value;
            old_number = number_of_value;
        }
        
    }
    // Finds the smallest value with a frequency of highest_amount
    for (int j = 0; j < holder.size(); ++j) {
        vector<double> temp2 = holder[j];
        if (temp2[1] == highest_amount) {
            return temp2[0];
        }
        
    }
    // Should never assert if function implements correctly.
    assert(false);
}

double min(vector<double> v) {
    sort(v);
    // The min of v is stored at v[0] if v is sorted.
    return v[0];
}

double max(vector<double> v) {
    sort(v);
    int size = static_cast<int>(v.size());
    
    // The max of v is stored at v[size - 1] if v is sorted.
    return v[size - 1];
    
}

double stdev(vector<double> v) {
    double average = mean(v);
    int degrees_freedom = static_cast<int>(v.size()) - 1;
    double sum_of_squares = 0;
    double std_dev = 0;
    
    /* Difference between each value and mean is squared and added to
     * sum_of_squares
     */
    for (int i = 0; i < v.size(); ++i) {
        double square1 = pow((v[i] - average), 2);
        sum_of_squares += square1;
    }
    //Standard deviation is calculated using sum_of_squares and degrees_freedom
    std_dev = sqrt(sum_of_squares / degrees_freedom);
    
    return std_dev;
    
}

double percentile(vector<double> v, double p) {
    // Vector is sorted and n, k, and d are calculated
    sort(v);
    double n = (p * (v.size() - 1)) + 1;
    double k = floor(n);
    double d = n - k;
    
    /* vk and v(k+1) is found in v. Index [k-1] is used to adjust for different
     * indexing methods between excel method and c++ indexing
     */
    double vk = v[k - 1];
    double vk1 = v[k];
    
    // Percentile is calculated and returned
    double answer = vk + (d * (vk1 - vk));
    
    return answer;
}
