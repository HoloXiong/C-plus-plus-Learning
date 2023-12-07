#include <iostream>
#include <deque>

using namespace std;

void print(deque<int> d){
    for(deque<int>::iterator it = d.begin(); it != d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    // c++ 11才支持这种初始化方式
    // deque<int> a = {1, 2, 3, 4};
    deque<int> d;
    // 尾插
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    // 头插
    d.push_front(9);
    print(d);

    // 尾删
    d.pop_back();
    // 头删
    d.pop_front();
    print(d);

    // 任意位置删
    d.erase(d.begin() + 1);
    print(d);
    return 0;
}