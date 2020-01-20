//main.cpp
#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    string filename;
    string column_name;
    vector<double> v;
    
    cout << "enter a filename" << endl;
    cin >> filename;
    
    cout << "enter a column name" << endl;
    cin >> column_name;
    
    cout << "reading column " << column_name << " from ";
    cout << filename << endl;
    
    v = extract_column(filename, column_name);
    
    vector<vector<double> > summary = summarize(v);
    cout << "Summary (value: frequency)" << endl;
    
    for (int i = 0; i < summary.size(); ++i) {
        vector<double> holder = summary[i];
        cout << holder[0] << ": " << holder[1] << endl;
        
    }
    
    cout << endl << "count = " << v.size() << endl;
    cout << "sum = " << sum(v) << endl;
    cout << "mean = " << mean(v) << endl;
    cout << "stdev = " << stdev(v) << endl;
    cout << "median = " << median(v) << endl;
    cout << "mode = " << mode(v) << endl;
    cout << "min = " << min(v) << endl;
    cout << "max = " << max(v) << endl;
    
    //percentiles
    cout << "  0th percentile = " << percentile(v, 0) << endl;
    cout << " 25th percentile = " << percentile(v, 0.25) << endl;
    cout << " 50th percentile = " << percentile(v, 0.5) << endl;
    cout << " 75th percentile = " << percentile(v, 0.75) << endl;
    cout << "100th percentile = " << percentile(v, 1) << endl;
    
    
    
    
    
    
    
    
    
}
