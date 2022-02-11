stl：容器，算法，迭代器，仿函数，适配器，空间配置器
# 容器
STL容器主要分为
顺序容器   vector(向量容器) deque(双端队列容器) list(双向链表)
关联容器   set(单重集合)  multiset(双重集合)  map(单重映射表) multimap(多重映射表)
容器适配器 stack(栈) queue(队列) prority_queue(优先级队列)

所有容器都有以下两个成员函数：
    int size()：返回容器对象中元素的个数。
    bool empty()：判断容器对象是否为空。


## 1.顺序容器
序列容器（sequence container顺序容器）—— 将一组具有相同类型T的对象，以严格的线性形式组织在一起。序列容器可以视为数组和链表的推广。其中每个元素均有固定位置—取决于插入时机和地点，和元素值无关。如果你以追加方式对一个群集插入六个元素，它们的排列次序将和插入次序一致。
STL提供了三个序列式容器：向量（vector）、双端队列（deque）、列表（list），此外也可以把 string 和 array 当做一种序列式容器。
强调值的顺序，每个元素有固定的位置。
### 1. vector

1）构造
	
	(1) vector<int> v1;
	(2) vector<int> v2(10);//指定了刚开始的容量为10，默认值为0
	(3) vector<int> v3(n,num);//指定了开始的容量n和每个格子的默认值为num
	(4) vector(v.begin(),v.end());

2）遍历

	容器支持随机访问vec[n]
	可以用迭代器遍历

3）插入/删除

    .pushback()
    .popback()
    .pushfront()
    .popfront()
    .insert(iter,ele)

4）排序

    sort函数


### 2. deque

   deque(double-ended queue 双端队列)
   向两端插入元素效率较高！
   中间插入元素效率较低！

   1）构造

	(1) deque<int> d1;
	(2) deque<int> d2(10);
	(3) deque<int> d3(n,num);

   2）遍历

	容器支持随机访问d[n]
	可以用迭代器遍历

   3）插入/删除

    .pushback()
    .popback()
    .pushfront()
    .popfront()
    .insert(iter,ele)

   4）排序

    sort函数

### 3. list

   双向链表，底层是一个环状的循环链表，由于其链表节点具有pre和next域，所以list也支持push_back、push_front、pop_back、pop_front
   它的底层不是连续的 所以不能通过[]随机访问元素 但是可以双向遍历

   1）构造

	(1) list<int> l1;
	(2) list<int> l2(10);
	(3) list<int> l3(n,num);

   2）遍历

    迭代器不支持随机访问
    迭代器遍历

   3）插入/删除

    .pushback()
    .popback()
    .pushfront()
    .popfront()
    .insert(iter,ele)
    .erase(pos)

   4）排序

    不能用sort函数排序，所有不支持随机访问迭起器的容器，都不能用标准算法
    list.sort();//默认顺序从小到大
    list.reverse();//反转链表
    可通过函数或仿函数自定义排序

### 4. forward_list

### 5. array

### 6. string

   Notes: 对于char型赋值，如果不加''，赋的是ascii
   example:char i=1 and char i='1'，后者才是真正的字符1

   1）构造

    string s1();  // si = ""
    string s2("Hello");  // s2 = "Hello"
    string s3(4, 'K');  // s3 = "KKKK"
    string s4("12345", 1, 3);  //s4 = "234"，即 "12345" 的从下标 1 开始，长度为 3 的子串
   错误构造：
    string s1('K');
    string s2(123);

   2）遍历
   3）插入/删除
   4）排序
   5）求字串

    substr
    substr 成员函数可以用于求子串 (n, m)
```    
    string s1 = "this is ok";
    string s2 = s1.substr(2, 4);  // s2 = "is i"
    s2 = s1.substr(2);  // s2 = "is is ok"
```

6）string转换成int

atoi()的参数是 const char* ,
因此对于一个字符串str我们必须调用 
c_str()的方法把这个string转换成 const char*类型的,
```
1 std::string str = "123";
2 int n = atoi(str.c_str());
3 cout<<n; //123
```
而stoi()的参数是const string*,不需要转化为 const char*；
stoi(string)


## 2关联容器

1. 关联容器（associative container联合容器）—— 关联容器的特点是（键）有序的，即元素是按预定义的键顺序（如升序）插入的。关联容器具有从基于键的集合中快速提取对象的能力，其中集合的大小在运行时是可变的。关联容器可以视为关联数组、映射或字典的推广，它们保存的都是值的对偶，给定了其中的一个被称为键（key）的值，就可以快速访问与其对偶的另一个被称为映射值（mapped value）的值。

2. 元素位置取决于特定的排序准则以及元素值，和插入次序无关。如果你将六个元素置入这样的群集中，它们的位置取决于元素值，和插入次序无关。

3. 关联式容器都是有序的，升序排列，自动排序;实现的是一个平衡二叉树，每个元素都有一个父节点和两个子节点，左子树的所有元素都比自己小，右子树的所有元素都比自己大;



4. 二叉树结构，各元素之间没有严格的物理上的顺序关系


pair类模板

    主要作用是将两个数据组成一个数据，用来表示一个二元组或一个元素对，两个数据可以是同一个类型也可以是不同的类型。
    两种创建方式
    pair<type,type> p1(v1,v2);
    pair<type,type> p2=make_pair(v1,v2)

注意一下：make_pair()函数内调用的仍然是pair构造函数

### 1. map

去重类问题，可以打乱重新排列的问题，有清晰的一对一关系的问题

(1) map为单重映射、multimap为多重映射;
(2) 主要区别是map存储的是无重复键值的元素对，而multimap允许相同的键值重复出现，既一个键值可以对应多个值。
(3) map内部自建了一颗红黑二叉树，可以对数据进行自动排序，所以map里的数据都是有序的，这也是我们通过map简化代码的原因。
(4)自动建立key-value的对应关系，key和value可以是你需要的任何类型。
(5) key和value一一对应的关系可以去重。


1）构造

    map<T1,T2> mp;

2）遍历

    迭代器不支持随机访问
    iter->first;
    iter->second;

3）插入/删除

    .insert(elem)    //.insert(pair<int,int>(10,10))
    	 //.insert(make_pair(10,10))
    	 //.insert(map<int,int>::value_type(10,2)); 
    	 //m[key] = value;   //m只能是map容器，不适用于multimap
    .erase(elem)
    .erase(key) //删除key元素

4）排序

    默认规则为按照key值从小到大排列，即key-value中的前一个元素
    如果是map中由自定义类型，则必须指定排序规则

5) 查找与统计

    .find()//查找key是否存在，若存在，返回该键的元素的迭代器，若不存在，返回.end()
    .count()

### 2. set

构造set集合的主要目的是为了快速检索,去重与排序
set存储的是一组无重复的元素，而multiset允许存储有重复的元素;
如果要修改某一个元素值，必须先删除原有的元素，再插入新的元素。

1）构造

	(1) set<int> s1;
	(2) set<int,op> s2;  op为排序规则

2）遍历

    迭代器不支持随机访问

3）插入/删除

    .insert(elem)  set的insert返回值为一个pair<set<int>::iterator,bool>。
               bool标志着插入是否成功，而iterator代表插入的位置，
               若该键值已经在set中，则iterator表示已存在的该键值在set中的位置。插入数据后自动排序
    .erase(elem)
    .erase(pos)

4）排序

    set容器默认排序为从小到大
    通过函数或仿函数自定义排序,必须在创建容器时定义set<int,MyCompare>

定义比较函数（或比较类/结构体）
     set容器在判定已有元素a和新插入元素b是否相等时，是这么做的：
    （1）将a作为左操作数，b作为右操作数，调用比较函数，并返回比较值 ；
    （2）将b作为左操作数，a作为右操作数，再调用一次比较函数，并返回比较值。
     也就是说，假设有比较函数f(x,y)，要对已有元素a和新插入元素b进行比较时，会先进行f(a,b)操作，再进行f(b,a)操作，然后返回两个bool值。
    如果1、2两步的返回值都是false，则认为a、b是相等的，则b不会被插入set容器中；
    如果1返回true而2返回false，那么认为b要排在a的后面，反之则b要排在a的前面；
    如果1、2两步的返回值都是true，则可能发生未知行为。



5) 查找与统计

    find(key) //查找key是否存在，若存在，返回该键的元素的迭代器，若不存在，返回set.end();
    count(key) //统计key的元素个数


3. multimap

1）构造
2）遍历
3）插入/删除
4）排序

4. multiset

1）构造
2）遍历
3）插入/删除
4）排序

## 3.容器适配器

容器适配器（container adapter）—— 不是独立的容器，只是某种容器的变种，它提供原容器的一个专用的受限接口。特别是，容器适配器不提供迭代器。
为满足特殊需求，STL还提供了一些特别的（并且预先定义好的）容器配接器，根据基本容器类别实现而成。

### 1. stack

1）构造
2）遍历
3）插入/删除
.pop();
.top();
.push();

4）排序

### 2. queue

      front->  **---**---**---**---   <-back
        pop->                         <-push

1）构造
2）遍历
3）插入/删除

    .front();
    .back();
    .push;
    .pop;

4）排序

### 3. priority_queue

和queue不同的就在于我们可以自定义其中数据的优先级, 让优先级高的排在队列前面,优先出队
优先队列具有队列的所有特性，包括基本操作，只是在这基础上添加了内部的一个排序，它本质是一个堆实现的

1）构造

priority_queue<Type, Container, Functional>
	Type 就是数据类型，
	Container 就是容器类型。Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。STL里面默认用的是vector）
	Functional 就是比较的方式，当需要用自定义的数据类型时才需要传入这三个参数，使用基本数据类型时，只需要传入数据类型，默认是大顶堆

升序队列（小顶堆） priority_queue<int,vector<int>,greater<int>> q  
降序队列（大顶堆） priority_queue<int,vector<int>,less<int>> q   等价于默认  priority_queue<int> q

2）遍历
3）插入/删除
4）排序

```
#include<iostream>
#include <queue>
using namespace std;
int main()
{
    //对于基础类型 默认是大顶堆
    priority_queue<int> a;
    //等同于 priority_queue<int, vector<int>, less<int> > a;

    //      这里一定要有空格，不然成了右移运算符↓↓
    priority_queue<int, vector<int>, greater<int> > c;  //这样就是小顶堆
    priority_queue<string> b;

    for (int i = 0; i < 5; i++)
    {
        a.push(i);
        c.push(i);
    }
    while (!a.empty())
    {
        cout << a.top() << ' ';
        a.pop();
    }
    cout << endl;

    while (!c.empty())
    {
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;

    b.push("abc");
    b.push("abcd");
    b.push("cbd");
    while (!b.empty())
    {
        cout << b.top() << ' ';
        b.pop();
    }
    cout << endl;
    return 0;
}
```
结果
```
4 3 2 1 0
0 1 2 3 4
cbd abcd abc
```


##  4 无序集合

### 1. unordered_map
### 2. unordered_set
### 3. unordered_multimap
### 4. unordered_nultiset