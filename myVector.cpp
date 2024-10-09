#include <iostream>
using namespace std;
template<typename T>
class myVector {
    private:
        T* data;
        int length;
        int capacity;
        void resize(int newSize){
            T* newData = new T[newSize];
            for(int i =0;i<length;i++){
                newData[i] = data[i];
            }
            capacity = newSize;
            delete[] data;
            data = newData;
        };

    public:
        myVector():data(new T[1]),length(0),capacity(1){};
        ~myVector(){delete[] data;};
        T operator[](int index){
            if(index>=length) throw("Index out of range");
            return data[index];
        };
        void push_back(T val){
            if(length==capacity){
                resize(capacity*2);
            }
            data[length++] = val;
        };
        void pop_back(){
            if(length>0)length--;
        };
        int size(){
            return length;
        };
        int empty(){
            return length==0;
        };
        void erase(int index) {
            if (index < 0 || index >= length) {
                throw("Index out of range");
            }
            for (int i = index; i < length - 1; i++) {
                data[i] = data[i + 1];
            }
            length--;
        }

        void erase(int start, int end) {
            if (start < 0 || end > length || start >= end) {
                throw("Invalid range");
            }
            int numToRemove = end - start;
            for (int i = start; i < length - numToRemove; i++) {
                data[i] = data[i + numToRemove];
            }
            length -= numToRemove;
        }

        void clear() {
            delete[] data;
            data = new T[1];  // Reset with initial capacity
            capacity = 1;
            length = 0;
        }

};
int main(){
    myVector<int> custom;
    cout<<"MyVector is "<<(custom.empty()?"empty":"full")<<endl;
    custom.push_back(1);
    custom.push_back(2);
    custom.push_back(3);
    custom.push_back(4);
    custom.push_back(5);
    cout<<"MyVector:"<<endl;
    for(int i =0;i<custom.size();i++){
        cout<<custom[i]<<", ";
    }
    cout<<"MyVector is "<<(custom.empty()?"empty":"full")<<endl;
    cout<<"MyVector has length "<<custom.size()<<endl;
    custom.erase(2,4);
    cout<<"MyVector:"<<endl;
    for(int i =0;i<custom.size();i++){
        cout<<custom[i]<<", ";
    }
    cout<<"MyVector is "<<(custom.empty()?"empty":"full")<<endl;
    cout<<"MyVector has length "<<custom.size()<<endl;
    custom.clear();
    cout<<"MyVector:"<<endl;
    for(int i =0;i<custom.size();i++){
        cout<<custom[i]<<", ";
    }
    cout<<"MyVector is "<<(custom.empty()?"empty":"full")<<endl;
    cout<<"MyVector has length "<<custom.size()<<endl;
    cout<<endl;
}