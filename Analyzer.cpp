#include <iostream>
#include <string>
#include <vector>
#include <chrono>

inline long long systemTimeNanoseconds() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::time_point_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now()  ).time_since_epoch()
    ).count();
}
inline std::vector<std::string>& getStringData() {
    static std::vector<std::string> stringDataSet;
    if (stringDataSet.size() == 0)    {
        char tempSet[6] = "     ";
        for (tempSet[0] = 'a'; tempSet[0] <= 'z'; tempSet[0]++)
            for (tempSet[1] = 'a'; tempSet[1] <= 'z'; tempSet[1]++)
                for (tempSet[2] = 'a'; tempSet[2] <= 'z'; tempSet[2]++)
                    for (tempSet[3] = 'a'; tempSet[3] <= 'z'; tempSet[3]++)
                        for (tempSet[4] = 'a'; tempSet[4] <= 'z'; tempSet[4]++)
                            stringDataSet.push_back(std::string(tempSet));
    }
    return stringDataSet;
}

int linearSearch(std::vector<std::string> dataSet,std::string element) {
    int elementIndex=-1;
    int index=0;
    for(std::string value: dataSet) {
        if(value.compare(element)==0)
            elementIndex=index;
        else
            index++;
    }
    return elementIndex;
}
int binarySearch(std::vector<std::string> dataSet, std::string element) {
    int elementIndex=-1;
    int max, min, mid;
    min=0;
    max=dataSet.size()-1;
    mid= min+ (max)/2;
    while (mid!=min) {
        if(dataSet[mid]==element) {
            elementIndex=mid;
            return elementIndex;
        }
        int compareS=element.compare(dataSet[mid]);
        if (compareS<0) {
            max=mid-1;
        }
        else {
            min=mid+1;
        }
        mid=min+(max-min)/2;
    }
    if(dataSet[mid]==element) {
        elementIndex=mid;
    }
    return elementIndex;
}
int main() {
    int testResult;
    std::vector<std::string> data= getStringData();
    std::string test;
    std::cout << "Enter string to test: ";
    std::cin >> test;

    std::cout<<"Linear search:\n";
    std::cout<<systemTimeNanoseconds()<<"\n";
    testResult=linearSearch(data,test);
    std::cout<<systemTimeNanoseconds()<<"\n";
    std::cout << "Result:" << testResult << "\n";

    std::cout<<"\nBinary Search:\n";
    std::cout<<systemTimeNanoseconds()<<"\n";
    testResult=binarySearch(data,test);
    std::cout<<systemTimeNanoseconds()<<"\n";
    std::cout << "Result: " << testResult << "\n";
    return 0;
}

