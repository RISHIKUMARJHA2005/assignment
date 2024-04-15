#include <iostream>

class ArrayComparer {
private:
    int array1[5]; 
    int array2[5]; 

public:
   
    ArrayComparer(int arr1[], int arr2[]) {
        for (int i = 0; i < 5; ++i) {
            array1[i] = arr1[i];
            array2[i] = arr2[i];
        }
    }

  
    int findHigherSumArray() {
        int sum1 = 0, sum2 = 0;

       
        for (int i = 0; i < 5; ++i) {
            sum1 += array1[i];
        }

       
        for (int i = 0; i < 5; ++i) {
            sum2 += array2[i];
        }

        
        if (sum1 > sum2) {
            return 1; 
        } else if (sum2 > sum1) {
            return 2; 
        } else {
            return 0; 
        }
    }
};

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9, 10};

    ArrayComparer comparer(arr1, arr2);

    int result = comparer.findHigherSumArray();

    if (result == 1) {
        std::cout << "Array 1 has a higher sum of elements." << std::endl;
    } else if (result == 2) {
        std::cout << "Array 2 has a higher sum of elements." << std::endl;
    } else {
        std::cout << "Both arrays have the same sum of elements." << std::endl;
    }

    return 0;
}

