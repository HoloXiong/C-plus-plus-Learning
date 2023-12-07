#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    unordered_map<string, int> map;
    map["key1"] = 1;
    map.insert(make_pair("key2", 2));
    if(map.find("key2") != map.end()){
        cout << "True" << endl;
    }
    map.insert(make_pair("key3", 3));
    // c++11支持，这里不支持
    // auto：升级编译器为c++ 11
    // for(const auto& pair : map){
    //     cout << pair.first << "," << pair.second << endl;
    // }

    for(unordered_map<string, int>::iterator it = map.begin(); it != map.end(); it++){
        cout << it->first << "," << it->second << endl;
    }

    auto it = map.find("key2");  // 返回查找到的键值对
    cout << it->first << " " <<it->second <<endl;
    cout << double(5)/6 << endl;
    return 0;
}