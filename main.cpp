#include <iostream>

using namespace std;


template<class T>
class bheap{
public:
    T *arr;
    int arrSize{1024};
    int arrSizeMultipl{2};
    int usedSize{0};

    bheap(){
        arr = new T[arrSize];
    }
    ~bheap(){
        delete[]arr;
    }

    void expand(){
        arrSize *= arrSizeMultipl;
        T* temp = new T[arrSize];
        for(int i = 0; i < usedSize; i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

    int getParent(int index){
        return (index - 1) / 2;
    }

    int getLChild(int index){
        return 2*index + 1;
    }

    int getRChild(int index){
        return 2*index + 2;
    }

    void swapPtr(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void add(int data){
        if(usedSize >= arrSize){
            expand();
            add(data);
        }

        int temp = usedSize;

        arr[usedSize] = data;
        usedSize++;

        while(temp != 0 && arr[getParent(temp)] < arr[temp]){
            swapPtr(&arr[getParent(temp)], &arr[temp]);
            temp = getParent(temp);
        }

    }

    void print(){
        for(int i = 0; i < usedSize; i++){
            cout<<arr[i]<< " ";
        }
        cout<<endl;
    }
};

int main()
{
    bheap<int> test;

    test.add(10);
    test.add(5);
    test.add(8);
    test.add(12);
    test.add(9);
    test.add(9);
    test.print();
    return 0;
}
