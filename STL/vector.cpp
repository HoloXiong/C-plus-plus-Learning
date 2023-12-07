#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a[] = {0, 1, 2, 3, 4}; 
    vector<int> vecA(a, a+5);
    vector<int> vecB(vecA.begin(), vecA.end());
    vector<int> vecC(vecA.begin(), vecA.begin()+3);
    vector<int> vecD(6, 9);
    vector<int> vecE;
    vecE.assign(vecD.begin(), vecD.end());
    for(int i = 0; i < 6; i++){
        cout << vecE[i] << " ";
    } 
    cout << endl;

    cout << vecA.front() << endl;
    cout << vecA.back() << endl;

    vecA.push_back(99999);
    for(int i = 0; i < 6; i++){
        cout << vecA[i] << " ";
    } 
    cout << endl;

    vecA.insert(vecA.begin()+2, 898988);
    for(int i = 0; i < 7; i++){
        cout << vecA[i] << " ";
    } 
    cout << endl;

    int b[] = {66, 77, 88, 99, 1010};
    for(vector<int>::iterator it = vecA.begin(); it != vecA.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    cout << "****************************" << endl;

    vector<int> vecF(a, a+5);
    vector<int>::iterator it = vecF.begin()+3;
    it = vecF.insert(vecF.begin()+3, 999);  // 这里插入会导致接下来访问迭代器失效，因为内存已经发生变化，it可视为野指针
    cout << *it << endl;

    int d[] = {1, 2, 3, 3, 3, 3, 4, 5, 6};
    vector<int> vec(d, d+9);
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ){
        if(*it == 3){
            it = vec.erase(it);  // 这样只能删一半，因为删完第一个3后迭代器失效 解决：it = erase(it);
        }
        else{
            it++;
        }
    }
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    sort(vecA.begin(), vecA.end());

    vector< vector<int> > matrix(4, vector<int>(5, 0));
    cout << matrix[0].size() << endl;
    return 0;
}