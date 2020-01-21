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
    vector<vector<double> > outer(0);
    int size = count(v);
    int total = 0;
    double smallest = v[0];
    double largest = v[0];
    const double epsilon = 0.00001;
    int count_of_value = 0;
    
    //finds the smallest value in the vector v.
    for (int i = 0; i < size; ++i) {
        if (v[i] < smallest) {
            smallest = v[i];
        }
    }
    //finds the largest value in the vector v.
    for (int i = 0; i < size; ++i) {
        if (v[i] > largest) {
            largest = v[i];
        }
    }
    
    
    for (int j = 0; j < size; ++j) {
        
        for (int i = 0; i < size; ++i) {
               
               /* checks if values are equal (must use epsilon
                * because double comparison. If they are equal
                * count (frequency) increases by one.
                */
               if (abs(smallest - v[i]) < epsilon) {
                   ++count_of_value;
               }
               
               
           }
        /* creates inner vector and fills it with
         * (value, frequency) pairs. */
        vector<double> inner(2);
        inner[0] = smallest;
        inner[1] = static_cast<double>(count_of_value);
        
        outer.push_back(inner);
        
        /* old_smallest value is set to equal the smallest value
         * before smallest is changed. Total is updated so that the
         * function will know when to terminate
         */
        double old_smallest = smallest;
        total += count_of_value;
        count_of_value = 0;
        
        //finds any value in v that is larger than the last smallest value
        for (int k = 0; k < size; k++) {
            if ((abs(v[k] - old_smallest) > epsilon) && (v[k] > old_smallest)) {
                smallest = v[k];
            }
            
        }
        /* This for loop finds the next smallest value by making sure v[m]
         * satisfies the following 3 conditions:
            1. v[k] is a different number than the old_smallest
            2. v[k] is greater than the old_smallest
            3. v[k] is less than smallest
         */
        for (int m = 0; m < size; ++m) {
            if (abs(v[m] - old_smallest) > epsilon) {
                if (v[m] > old_smallest) {
                    if (v[m] < smallest) {
                        smallest = v[m];
                    }
                }
            }
        }
        /* If total is equal to the size of the vector, the function is done,
         * so it returns the vector outer.
         */
        if (total == size) {
            return outer;
        }
        
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
    double size = count(v);
    
    /* A for loop is used to iterate over vector and increase sum by each value
     * in the vector
     */
    for (int i = 0; i < size; ++i) {
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
    int holder_size = static_cast<int>(holder.size());
    
    for (int i = 0; i < holder_size; ++i) {
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
    int holder_size = static_cast<int>(holder.size());
    
    /* For loop iterates over frequency values in holder to find which one is
     * the largest. This value is saved to highest_amount.
     */
    for (int i = 0; i < holder_size; ++i) {
        vector<double> temp = holder[i];
        int number_of_value = static_cast<int>(temp[1]);
        
        if (number_of_value > old_number) {
            highest_amount = number_of_value;
            old_number = number_of_value;
        }
        
    }
    // Finds the smallest value with a frequency of highest_amount
    for (int j = 0; j < holder_size; ++j) {
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
    int size_v = count(v);
    /* Difference between each value and mean is squared and added to
     * sum_of_squares
     */
    for (int i = 0; i < size_v; ++i) {
        double square1 = pow((v[i] - average), 2);
        sum_of_squares += square1;
    }
    //Standard deviation is calculated using sum_of_squares and degrees_freedom
    std_dev = sqrt(sum_of_squares / degrees_freedom);
    
    return std_dev;
    
}

double percentile(vector<double> v, double p) {
    // Vector is sorted and n, k, and d are calculated
    const double epsilon = 0.00001;

    if (abs(p - 1.0) < epsilon) {
        return max(v);
    }
    sort(v);
    int size = count(v);
    double n = (p * (size - 1)) + 1;
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
