#include <iostream>
#include <list>

using namespace std;

// 打印
void print(list<int> lst){
    for(list<int>::iterator it = lst.begin(); it != lst.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    list<int> lst;

    // 尾插
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);

    // 头插
    lst.push_front(2);
    print(lst);

    // 头删尾删
    lst.pop_front();
    lst.pop_back();
    print(lst);

    // 返回头尾结点
    cout << lst.front() << endl;
    cout << lst.back() << endl;

    lst.front() = 9999;
    lst.back() = 8888;
    print(lst);

    lst.push_back(777);
    lst.push_back(666);

    // list的反向迭代器
    for(list<int>::reverse_iterator it = lst.rbegin(); it != lst.rend(); it++){
        cout << *it << " ";
    }
    cout << endl;

    // 带参数构造方法
    list<int> lst1(3, 5);
    print(lst1);

    list<int> lst2(lst.begin(), lst.end());  // list不支持这种写法lst.begin()+n, 只能it++
    print(lst2);

    list<int> lst3(lst);
    print(lst3);

    // list 赋值 assign是覆盖式的，会覆盖原有的值
    list<int> lst4, lst5, lst6;
    lst4.assign(lst.begin(), --lst.end());
    print(lst4);

    lst5.assign(6, 6);
    print(lst5);

    // 大小，判空
    if(lst6.empty()){
        cout << "list为空！" << endl;
    }
    lst5.resize(lst5.size()+4, 999);
    print(lst5);
    return 0;
}