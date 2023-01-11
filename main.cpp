#include <iostream>

using namespace std;


template<class T>
class bheap{
    T *arr;
    int arrSize{16};
    int arrSizeMultipl{2};
    int usedSize{0};
public:
    bheap(){
        arr = new T[arrSize];
    }
    ~bheap(){
        delete[]arr;
    }
private:
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

    void heapify(int siz, int index){
        int temp = index;

        int l = getLChild(index);
        int r = getRChild(index);

        if(l < siz && arr[l] > arr[temp])
            temp = l;
        if(r < siz && arr[r] > arr[temp])
            temp = r;
        if(temp != index){
            swapPtr(&arr[index], &arr[temp]);
            heapify(siz, temp);
        }
    }
public:
    void add(T data){
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

    void heapSort(){
        for(int i = usedSize / 2 - 1; i >= 0; i--){
            heapify(usedSize, i);
        }
        for(int i = usedSize - 1; i > 0; i--){
            swapPtr(&arr[0], &arr[i]);
            heapify(i, 0);
        }
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

    test.heapSort();

    test.print();

    return 0;
}
