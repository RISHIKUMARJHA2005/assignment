#include <iostream>

class DynamicArray {
private:
    int* array;
    int size;
    int capacity;

public:
    DynamicArray(int initialSize) {
        size = initialSize;
        capacity = initialSize;
        array = new int[capacity];
    }

    
    ~DynamicArray() {
        delete[] array;
    }

   
    void add(int element) {
       
        if (size >= capacity) {
           
            capacity *= 2;
           
            int* newArray = new int[capacity];
           
            for (int i = 0; i < size; ++i) {
                newArray[i] = array[i];
            }
         
            delete[] array;
            
            array = newArray;
        }
       
        array[size++] = element;
    }

   
    void print() {
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    
    DynamicArray dynArray(5);

 
    dynArray.add(1);
    dynArray.add(2);
    dynArray.add(3);
    dynArray.add(4);
    dynArray.add(5);
    dynArray.add(6);

   
    dynArray.print();

    return 0;
}

