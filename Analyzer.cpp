#include <iostream>
#include <vector>
#include <string>
#include "StringData.h"
using namespace std;

int linearSearch(vector<string> stringDataSet, string element) {
    for(int i = 0; i < stringDataSet.capacity(); i++)
    {
        if(stringDataSet.at(i) == element)
        {
            return i;
        }
    }

    return -1;
}

int binarySearch(vector<string> stringDataSet, string element) {
    int high = stringDataSet.capacity() - 1;
    int low = 0;
    while(high >= low) {
        int mid = low + (high - low) / 2;
        if(stringDataSet[mid] == element)
        {
            return mid;
        }
        else if(element.compare(stringDataSet[mid]) > 0)
        {
            low = mid + 1;
        }
        else if(element.compare(stringDataSet[mid]) < 0)
        {
            high = mid - 1;
        }
    }

    return -1;
}

long long timeLinearSearch(vector<string> stringDataSet, string element) {
    long long startTime = systemTimeNanoseconds();
    linearSearch(stringDataSet, element);
    long long endTime = systemTimeNanoseconds();
    long long linearTime = endTime - startTime;

    return linearTime;
}

long long timeBinarySearch(vector<string> stringDataSet, string element) {
    long long startTime = systemTimeNanoseconds();
    binarySearch(stringDataSet, element);
    long long endTime = systemTimeNanoseconds();
    long long binaryTime = endTime - startTime;

    return binaryTime;
}

int main() {
    vector<string> data = getStringData();
    long long timeLinAAAAA = timeLinearSearch(data, "aaaaa");
    cout << timeLinAAAAA << endl;
    long long timeBinAAAAA = timeBinarySearch(data, "aaaaa");
    cout << timeBinAAAAA << endl;
    long long timeLinMZZZZ = timeLinearSearch(data, "mzzzz");
    cout << timeLinMZZZZ << endl;
    long long timeBinMZZZZ = timeBinarySearch(data, "mzzzz");
    cout << timeBinMZZZZ << endl;
    long long timeLinNotHere = timeLinearSearch(data, "not_here");
    cout << timeLinNotHere << endl;
    long long timeBinNotHere = timeBinarySearch(data, "not_here");
    cout << timeBinNotHere << endl;
    return 0;
};