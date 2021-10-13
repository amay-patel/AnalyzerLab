#include <iostream>
#include <string>
#include <chrono>

using namespace std;


int linearSearch(string[], string);

int binarySearch(string[], string);

string *getData();


int main() {
    string *dataSet = getData();

    linearSearch(dataSet, "not_here");
    binarySearch(dataSet, "not_here");

    linearSearch(dataSet, "mzzzz");
    binarySearch(dataSet, "mzzzz");

    linearSearch(dataSet, "aaaaa");
    binarySearch(dataSet, "aaaaa");
    
    return 0;
}

int linearSearch(string dataSet[], string element){
    auto s = chrono::system_clock::now().time_since_epoch().count();
    int position = -1;
    for (int i = 0; i < 26 * 26 * 26 * 26 * 26; i++) {
        if (dataSet[i] == element) {
            position = i;
            break;
        }
    }
    auto e = chrono::system_clock::now().time_since_epoch().count();
    cout << "The time for linear search with element: " << element << " is " << (e-s) << "\n";
    return position;
}

int binarySearch(string dataSet[], string element){
    auto s = chrono::system_clock::now().time_since_epoch().count();

    int result = -1;

    int min = 0;
    int max = 26 * 26 * 26 * 26 * 26;

    while (true){
        if (min > max){
            break;
        }

        int mid = (min+max)/2;

        string m = dataSet[mid];

        if (m == (element)) {
            result = mid;
            break;
        }
        if (m > (element)) {
            max = mid-1;
            continue;
        }
        if (m < (element)){
            min = mid+1;
            continue;
        }
    }

    auto e = chrono::system_clock::now().time_since_epoch().count();
    cout << "The time for binary search with element: " << element << " is " << (e-s) << "\n";

    return result;
}


string * stringDataSet = NULL;

string * getData(){
	if (stringDataSet == NULL)
	{
		stringDataSet = new string[26 * 26 * 26 * 26 * 26];
		char tempSet[5];
		int index = 0;

		for (tempSet[0] = 'a'; tempSet[0] <= 'z'; tempSet[0]++)
		{
			for (tempSet[1] = 'a'; tempSet[1] <= 'z'; tempSet[1]++)
			{
				for (tempSet[2] = 'a'; tempSet[2] <= 'z'; tempSet[2]++)
				{
					for (tempSet[3] = 'a'; tempSet[3] <= 'z'; tempSet[3]++)
					{
						for (tempSet[4] = 'a'; tempSet[4] <= 'z'; tempSet[4]++)
						{
							stringDataSet[index++] = string(tempSet);
						}
					}
				}
			}
		}
	}

	return stringDataSet;
}

