#include <iostream>
#include <vector>

int compareTimes = 0, divideTimes = 0;

void merge(std::vector<float>& floats, std::vector<float>leftFloats, std::vector<float>rightFloats, int left) {
    int i = 0, j = 0;
    while (i < leftFloats.size() && j < rightFloats.size()) {
        compareTimes++;
        if (leftFloats[i] <= rightFloats[j]) {
            floats[left] = leftFloats[i];
            i++;
        }
        else {
            floats[left] = rightFloats[j];
            j++;
        }
        left++;
    }

    while (i != leftFloats.size()) {
        floats[left] = leftFloats[i];
        i++;
        left++;
    }

    while (j != rightFloats.size()) {
        floats[left] = rightFloats[j];
        j++;
        left++;
    }

    return;
}

void mergeSort(std::vector<float>& floats,int left, int right) {
    if (left < right) {
        int mid = (left + right - 1) / 2;
        
        divideTimes++;
        mergeSort(floats, left, mid);
        mergeSort(floats, mid + 1, right);

        std::vector<float> leftFloats(floats.begin() + left, floats.begin() + mid + 1);
        std::vector<float> rightFloats(floats.begin() + mid + 1, floats.begin() + right + 1);

        merge(floats, leftFloats, rightFloats, left);
        return;
    }
    else return;

}

int main()
{
    int length;
    float number;
    std::vector<float> floats;
    std::cin >> length;
    for (int i = 0; i < length; i++) {
        std::cin >> number;
        floats.push_back(number);
    }

    mergeSort(floats, 0, length - 1);

    std::cout << floats[0];
    for (int i = 1; i < length; i++) {
        std::cout << " " << floats[i];
    }
    std::cout << std::endl << divideTimes << std::endl << compareTimes;
    
    return 0;
}
