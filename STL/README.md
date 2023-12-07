

# C++ STL

## 基本概念

六大组件：容器（Container）、迭代器（Iterator）、算法（Algorithm）、仿函数（Functor）、适配器（Adaptor）、分配器（allocator）

广义上分为3类：容器（Container）、迭代器（Iterator）、算法（Algorithm）

## 容器

### 序列式容器

每个元素都有固定的位置，取决于插入的时机和地点，和元素值无关

vector、deque、list、stack、queue

### 关联式容器

元素位置取决于特定的排序准则，和插入顺序无关

set、multiset、map、multimap

|         数据结构         |                             描述                             |  头文件   |
| :----------------------: | :----------------------------------------------------------: | :-------: |
|        向量vector        |                        连续存储的元素                        | \<vector> |
|         列表list         |                     由节点组成的双向链表                     |  \<list>  |
|       双队列deque        |           连续存储的指向不同元素的指针所组成的数组           | \<deque>  |
|         集合set          | 由节点组成的红黑树，每个节点包含一个元素，内部的元素依据其值自动排序，没有两个不同的元素能够拥有相同的次序（Set内的相同数值的元素只能出现一次） |  \<set>   |
|     多重集合multiset     |              Multiset内可包含多个数值相同的元素              |  \<set>   |
|         栈stack          |                        后进先出的排列                        | \<stack>  |
|        队列queue         |                        先进先出的排列                        | \<queue>  |
| 优先级队列priority_queue | 其中每个元素都关联有一个优先级。不同于普通队列，元素在出队时不是按照它们进入队列的顺序被移除，而是根据其优先级的高低被选择。 | \<queue>  |
|         映射map          | Map的元素是成对的键值/实值，内部的元素依据其值自动排序，Map内的相同数值的元素只能出现一次，内部由二叉树实现，便于查找 |  \<map>   |
|     多重映射multimap     |             Multimaps内可包含多个数值相同的元素              |  \<map>   |

做题出现的一些数据结构：

|   数据结构    |                             描述                             |      头文件      |
| :-----------: | :----------------------------------------------------------: | :--------------: |
| unordered_map | 使用哈希表实现，因此元素的插入和查找效率非常高，平均情况下是常数时间复杂度。但是它不保证元素的顺序，元素的排列顺序与插入顺序无关 | \<unordered_map> |

```c++
// 定义
unordered_map<string, int> map;
// 插入
map['key1'] = 1;
map.insert(make_pair("key2", 2));
// 访问元素
int value = map["key1"];
// 查找元素
if(map.find("key2") != map.end()){
  // 表示元素存在 find
}
// 删除元素
map.erase("key1");
// 遍历
for (const auto& pair : myMap) {
    cout << pair.first << ": " << pair.second << std::endl;
}
```



### 向量vector

动态数组，随机存取（直接索引值存取）元素，数组尾部添加或移除元素非常快速，但是在中部或头部安插元素比较费时。

#### 1-构造方法

无参构造方式：vector\<T> vecName;  // T可以是int，float，string，对象，对象指针

带参构造：

- vector(begin, end)：构造函数将 \[beg, end) 区间的元素拷贝给本身（左闭右开）
- vector(n, value)：构造函数将n个elem拷贝给本身
- vector(const vector &vec)：拷贝构造函数

```c++ 
int a[] = {0, 1, 2, 3, 4}; 
vector<int> vecA(a, a+5);
vector<int> vecB(vecA.begin(), vecA.end());
vector<int> vecC(vecA.begin(), vecA.begin()+3);
vector<int> vecD(6, 9);  // 6个9
vector<int> vecE = vecD; // 拷贝构造函数 等价于 vector<int> vecE(vecD);
```

#### 2-赋值

```c++
vector.assign(begin, end);
vector.assign(n, value);  // 拷贝n个value
vector1 = vector2;
vector1.swap(vector2); // 交换两个向量中的元素

vector<int> vector1(10, 10);
int a = [0, 1, 2, 3, 4];
vector1.assign(a, a+5);  // 这会清除原来vector的中数据
```

#### 3-大小

```c++
vector.size();
vector.empty();  // 0非空 1空
vector.capacity();  // 返回向量的当前容量
vector.resize(num);  // 重新指定容器长度，变长则以默认值0填充新位置，变短则末尾元素被删除
vector.resize(num, value);  // 重新指定容器长度, 变长则以值value填充新位置，变短则末尾元素被删除
```

#### 4-末尾操作

```c++
vector.push_back();  // 将元素添加到向量的末尾
vector.pop_back();  // 用于移除向量的最后一个元素
vector.emplace_back();  // 允许你通过构造函数参数直接在向量的末尾构造对象

vector.front();  // 返回第 1 个元素
vector.back();  // 返回末尾元素
```

#### 5-元素访问方式

```c++
vector.at(index);  // 如果越界会提示报错
```

#### 6-插入元素

```c++
vector.insert(pos, value);  // pos处插入元素value的拷贝，返回新数据的位置
vector.insert(vector.begin()+3, 10);

vector.insert(pos, n, value); // 在pos处插入n个元素value，无返回值
vector.insert(pos, begin, end);  // 在pos位置插入[begin, end)区间的数据，无返回值
int a[] = {1, 2, 3, 4};
vector.insert(vector.begin()+3, a+1, a+3);  // 将a中的2, 3插入vector的索引3位置
```

#### 7- 删除元素

```c++ 
vector.clear();  // 清空所有元素
vector.erase(pos); // 删除指定位置或者范围的元素, 后面的元素全部前移
```

#### 8-逆转向量

```c++
#include <algorithm> // 包含 reverse 函数
reverse(vec.begin(), vec.end());
```

### 迭代器

#### 1- 基本使用

 检查容器内元素并且遍历容器内元素的数据类型，提供了对容器中对象的访问方法，并且定义了容器中对象的范围。

迭代器统一了对所有容器的访问方式，是为了提高编程效率而开发的。

 ```c++
 vector<int>::iterator it;  // vector的迭代器属于随机访问迭代器，迭代器一次可以移动更多个位置
 ```

| 成员函数  |                             功能                             |
| :-------: | :----------------------------------------------------------: |
|  begin()  | 返回指向容器中**第一个元素**的正向迭代器如果是 const 类型容器，在该函数返回的是常量正向返回指向容器 |
|   end()   | 返回指向容器**最后一个元素之后一个位置**正向迭代器;如果是 const 类型容器，在该函数返回是常量正向迭代器。此函数通常和 begin()搭配使用。 |
| rbegin()  | 返回指向**最后一个元素**的反向迭代器，如是 const 类型容器，在该函数返回的是常量反向迭代器。 |
|  rend()   | 返回指向**第一个元素之前一个位置**的反向迭代器。如果是const类型，在该函数返回的是常量反向迭代器。此函数通常和rbegin()搭配使用。 |
| cbegin()  | 和begin()功能类似，只不过其返回的迭代器类型为常量正向迭代器，不能用于修改元素。 |
|  cend()   | 和end()功能相同，只不过其返回的迭代器类型为常量正向迭代器，不能用于修改元素。 |
| crbegin() | 和rbegin()功能类似，只不过其返回的迭代器类型为常量反向迭代器，不能用于修改元素。 |
|  crend()  | 和rend()功能相同，只不过其返回的迭代器类型为常量反向迭代器，不能用于修改元素。 |

#### 2-迭代器失效

插入元素

```c++
vector<int> vec(a, a+5);
vector<int>::iterator it = vec.begin()+3;
vecF.insert(vec.begin()+3, 999);  // 这里插入会导致接下来访问迭代器失效，因为内存已经发生变化，it可视为野指针
cout << *it << endl;

// 解决办法：重新赋值it
it = vecF.insert(vecF.begin()+3, 999);
```

删除元素：

```c++
vector<int> vec = {1, 2, 3, 3, 3, 3, 4, 5, 6};
for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
  if(*it == 3){
    vec.erase(it);  // 这样只能删一半，因为删完第一个3后迭代器失效 
  }
}

// 解决
for(vector<int>::iterator it = vec.begin(); it != vec.end(); ){
  if(*it == 3){
    it = vec.erase(it);  
  }
  else{
    it++;
  }
}
```

### deque容器

#### 1-简介

- double-ended queue双端数组，vector是单端数组。

- **deque在接口上和vector非常相似，在许多操作上可以直接替换**，初始化有区别。
- 随机存取元素，按索引值直接存取，[]或at。
- 头部和尾部添加或移除元素都非常快速，但是在中间插入或移除非常缓慢。
- **vector是连续存储的，deque不是连续存储的**，在扩容的时候deque会随机找一块可用的内存地址进行扩容。

#### 2-插入删除元素

```c++
// 头部插入和删除
deque.push_front(elem);
deque.pop_front();
// 尾部插入和删除
deque.push_back(elem);
deque.pop_back();
```

### list容器

- 双向链表容器，可以搞笑进行插入和删除元素。

- 查找中间节点的时间复杂度是O(n)，但是插入和删除操作不需要移动大量的元素，效率比较高，在需要频繁插入和删除元素的时候使用比较合适。
- 不能随机存取元素，不能通过at或[]访问

#### 1-默认构造

```c++
list<int> lstInt;
list<float> lstFloat;
list<string> lstString;
```

#### 2-插入删除元素

```c++
// 尾插
lst.push_back(1);
// 头插
lst.push_front(2);
// 头删尾删
lst.pop_front();
lst.pop_back();
```

#### 3-返回/修改头尾结点

```c++
// 返回头尾结点
cout << lst.front() << endl;
cout << lst.back() << endl;

// 返回的是对象，也可以进行赋值
lst.front() = 9999;
lst.back() = 8888;
```

#### 4-list容器的迭代器

list的迭代器是双向迭代器，可以进行前向或后向操作。

#### 5-带参数构造方法

```c++
lst = list(n, elem);  // 将n个elem拷贝给本身
lst = list(begin, end);  // 将另一个容器 [begin, end) 区间的元素拷贝给本身
lst = list(const list &lst);  // 拷贝构造函数
```

#### 6-赋值

```c++
list.assign(begin, end);  // 将另一个容器的 [begin, end) 区间的元素拷贝给本身
list.assign(n, elem);  // 将n个elem拷贝赋值给本身
list& operator=(const list &lst);  // 重载等号运算符
list.swap(lst);  // 将lst与本身的元素互换
```

#### 7-大小

```c++
list.size();  // 大小
list.empty();  // 判空
list.resize(num);  // 重新指定容器长度为num，变长则以默认值填充新的位置，变短则超出部分被删除
list.resize(num, elem);  // 同上，但是填充时以elem填充新的位置
```

#### 8-插入

```c++
list.insert(pos, elem);  // pos 位置插入elem
list.insert(pos, n, elem);
list.insert(pos, begin, end);
```



## 函数

### sort-排序

sort用法

```c++
#include <algorithm>
template< class RandomIt > void sort( RandomIt first, RandomIt last );
template< class RandomIt, class Compare > void sort( RandomIt first, RandomIt last, Compare comp );
// first和last分别是数组的起始位置和终止位置。
// cmp属于扩展用法：你可以传入一个返回值为bool类型的函数，如果结果为true那么比较的两个数就不交换否则交换位置。
```

sort 源码

```c++
template <class _RandomAccessIterator, class _Comp>
inline _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
void sort(_RandomAccessIterator __first, _RandomAccessIterator __last, _Comp __comp) {
  std::__sort_impl<_ClassicAlgPolicy>(std::move(__first), std::move(__last), __comp);
}

template <class _RandomAccessIterator>
inline _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20
void sort(_RandomAccessIterator __first, _RandomAccessIterator __last) {
  // less是一种比较机制，用于实现升序（左>右）或降序（右>左）
  // std:sort调用_Sort_unchecked
  std::sort(__first, __last, __less<typename iterator_traits<_RandomAccessIterator>::value_type>());
}
```

```c++
template <class _RanIt, class _Pr>
_CONSTEXPR20 void sort(const _RanIt _First, const _RanIt _Last, _Pr _Pred) { // order [_First, _Last) 
    _Adl_verify_range(_First, _Last);
    const auto _UFirst = _Get_unwrapped(_First);
    const auto _ULast  = _Get_unwrapped(_Last);
  // 调用
    _Sort_unchecked(_UFirst, _ULast, _ULast - _UFirst, _Pass_fn(_Pred));
}
```

```c++
// 调用_Sort_unchecked1
void _Sort_unchecked(_RanIt _First, _RanIt _Last, _Pr& _Pred)
	{	// order [_First, _Last), using _Pred
	_Sort_unchecked1(_First, _Last, _Last - _First, _Pred);
	}
```

\_Diff是两个迭代器相减的结果（可以认为是排序内容的长度），STL的sort中有一个变量\_Ideal，每递归深入一次，_Ideal就会减小

1.当长度n小于**32**的时候，直接调用**插入排序**

2.当长度n大于**32**时，先用快排处理**$1.5*log_2(n)$**次，如果长度还是大于32——说明这个数组不太适合用快排，所以调用**堆排序**来处理

3.处理**$1.5*log_2(n)$**次后如果长度小于32，调用**插入排序**

4.处理快排用到下一个的函数_Partition_by_median_guess_unchecked

```c++
	void _Sort_unchecked1(_RanIt _First, _RanIt _Last, _Diff _Ideal, _Pr& _Pred)
	{	// 区间为 [_First, _Last)
	_Diff _Count;//排序内容的长度
	while (_ISORT_MAX < (_Count = _Last - _First) && 0 < _Ideal)
		//const int _ISORT_MAX = 32;//大于32才开始快排，否则直接插入排序...
		//当数组首尾的长度大于32的时候才开始愉快地快排，并且排的区间长度>0
		{	// divide and conquer by quicksort
		pair<_RanIt, _RanIt> _Mid =
			_Partition_by_median_guess_unchecked(_First, _Last, _Pred);
		_Ideal /= 2, _Ideal += _Ideal / 2;	// allow 1.5 log2(N) divisions
 
		if (_Mid.first - _First < _Last - _Mid.second)//少的那部分接着迭代…
			{	// loop on second half
			_Sort_unchecked1(_First, _Mid.first, _Ideal, _Pred);//迭代少的那一半
			_First = _Mid.second;
			}
		else
			{	// loop on first half
			_Sort_unchecked1(_Mid.second, _Last, _Ideal, _Pred);
			_Last = _Mid.first;
			}
		}
 
  // 堆排序
	if (_ISORT_MAX < _Count)
		{	// heap sort if too many divisions
		_Make_heap_unchecked(_First, _Last, _Pred);
		_Sort_heap_unchecked(_First, _Last, _Pred);
		}
  // 插入排序
	else if (2 <= _Count)
		_Insertion_sort_unchecked(_First, _Last, _Pred);	// small
	}
```

_Partition_by_median_guess_unchecked  

```c++
	void _Guess_median_unchecked(_RanIt _First, _RanIt _Mid, _RanIt _Last, _Pr& _Pred)
	{	// sort median element to middle
	if (40 < _Last - _First)
		{	// median of nine
		size_t _Step = (_Last - _First + 1) / 8;
		_Med3_unchecked(_First, _First + _Step, _First + 2 * _Step, _Pred);
		_Med3_unchecked(_Mid - _Step, _Mid, _Mid + _Step, _Pred);
		_Med3_unchecked(_Last - 2 * _Step, _Last - _Step, _Last, _Pred);
		_Med3_unchecked(_First + _Step, _Mid, _Last - _Step, _Pred);
		}
	else
		_Med3_unchecked(_First, _Mid, _Last, _Pred);
	}
```

快排部分对基准值做了优化，如果基准值恰好是最大或者最小值那么快排的复杂度会达到$O(n^2)$，因此需要选择一个适中的基准值。它将每一段排序的数组分成八段，九个位置，每三个进行一次冒泡排序，再对这三组的中间值进行一次冒泡，得到mid。sort中的快排是一半进入递归另一半继续for循环，效率更高。

### lower_bound-二分查找

`std::lower_bound` 的实现会利用有序序列的特性，结合二分查找的思想来快速确定第一个**大于或等于**某个给定值的**元素位置**。它在给定范围内迭代地进行比较，并根据比较结果调整搜索的范围，直到找到符合条件的元素或者搜索范围缩小至空。

```c++
// first 和 last 是指定范围的迭代器，代表了要搜索的序列范围。这个范围必须是已排序的。
// value 是要查找的值。
template< class ForwardIt, class T >
ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value);
```

