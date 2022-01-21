//
//  main.cpp
//  test
//
//  Created by Jack DelVecchio on 1/15/22.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

template<typename T>
int binarySearch(std::vector<T> list, T value)
{
    int right = (int) list.size() - 1;
    int middle = floor(right / 2);
    int left = 0;
    
    if (list[middle] == value) return middle;
    
    while(left <= right)
    {
        if (list[middle] == value) return middle;
        if (list[middle] > value) {
            right = middle - 1;
            middle = floor((right - left) / 2) + left;
        } else if (list[middle] < value) {
            left = middle + 1;
            middle = floor((right - left) / 2) + left;
        }
    }
    return -1;
}

template<typename T>
std::vector<T> merge(std::vector<T> listA, std::vector<T> listB)
{
    std::vector<T> list;
    int i = 0, j = 0;
    
    while (i < listA.size() && j < listB.size())
    {
       if (listA[i] < listB[j])
       {
           list.push_back(listA[i]);
           i++;
       } else if (listA[i] > listB[j])
       {
           list.push_back(listB[j]);
           j++;
       } else
       {
           list.push_back(listA[i]);
           list.push_back(listB[j]);
           i++;
           j++;
       }
    }
    
    if (i == listA.size())
    {
        while (j < listB.size())
        {
            list.push_back(listB[j]);
            j++;
        }
    } else if (j == listB.size())
    {
        while (i < listA.size())
        {
            list.push_back(listA[i]);
            i++;
        }
    }
    
    return list;
}
template<typename T>
std::vector<T> mergeSort(std::vector<T> &list)
{
    if(list.size() == 1) return list;
    
    int right = (int) list.size();
    int middle = floor(right / 2);
   
    std::vector<T> bottom(list.begin(), list.begin() + middle);
    std::vector<T> top(list.begin() + middle, list.end());
    
    return merge(mergeSort(bottom), mergeSort(top));
}

template<typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
int partition(std::vector<T> &list, int left, int right)
{
    T partition = list[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (list[j] < partition)
        {
            i++;
            swap(list[i], list[j]);
        }
    }
    swap(list[i + 1], list[right]);
    return i + 1;
}

template<typename T>
void quickSort(std::vector<T> &list, const int &left, const int &right)
{
    if (left < right) {
        int part = partition(list, left, right);
        
        quickSort(list, left, part - 1);
        quickSort(list, part + 1, right);
    }
}

int main(int argc, const char * argv[]) {
    std::vector<int> testVector = {3, 1, 5, 4, 2, 9, 8, 6, 7, 0, 11, 21, 34, 10,
        30, 12, 23, 35, 13, 24, 36, 14, 25, 37, 15, 26, 32, 16, 27, 39, 17, 28, 33,
        18, 29, 32, 19, 22, 31, 20
    };
    std::vector<std::string> stringVector = {"alex", "Alex", "jack", "a" , "bad", "sheep", "kind", "winner", "xylophone", "James", "XXxxXX", "aaa", "AAA", "ZZZ", "zzz",};
//    std::vector<std::string> output = mergeSort(stringVector);
      quickSort(stringVector, 0,(int) stringVector.size() - 1);
//    std::ifstream unsorted("unsorted.txt");
//    std::ofstream sorted("sorted.txt");
//    std::vector<std::string> words;
//    std::string word;
//    while(getline(unsorted, word))
//        std::cout << word << std::endl;
//    std::vector<std::string> output = mergeSort(words);
//    std::cout << "Output sorted: ";
//    int i = 0;
    for (auto w : stringVector) // {
        std::cout << w << " ";
//        if (i % 23 == 0)
//            sorted << std::endl;
//        i++;
//    }
    std::cout << std::endl;
//    std::string searchWord = "AA";
//    int num = 16;
//    std::cout << "Binary Search: " << num << std::endl
//                << binarySearch<int>(output, num) << std::endl;
    return 0;
}


