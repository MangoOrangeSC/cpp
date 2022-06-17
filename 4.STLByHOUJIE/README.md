# STL by HOUJIE

C++ Standard Library -- architecure & sources



- 泛型编程Generic Programming 就是使用模板为主要工具



## 1 基础

![image1](pic/pic5.png)

- 标准库>STL
- C++标准库的头文件不加.h



## 2 STL六大部件

![image1](pic/pic12.png)

- 容器(Container)；解决内存的问题
- 分配器(Allocators)；支持容器
- 算法(Algorithms)；有一部分功能在容器里面做，还有一部分被独立出来
- 迭代器(Iterators)；算法与容器的桥梁，迭代器可以理解为泛化的指针
- 适配器(Adapters)；变压器。转换。容器、仿函数、迭代器  。stack与queue
- 仿函式(Functors)；

![image1](pic/pic13.png)

- 容器的第二个参数是分配器，每个容器要有分配器来负责内存管理，默认值，可以不写；分配器也是一个模板，要<>类型，类型要与容器保持一致。
- count_if ：就是算法
- less<int>是仿函数，bind2nd是函数适配器，绑定第二个参数，即只接收第一个参数，not1是一个函数适配器，反义，大于等于40

![image1](pic/pic14.png)

- 复杂度 big-oh。n是一个很大的数量，百万级别

![image1](pic/pic15.png)

- 前闭后开区间：begin--指向第一个元素    end--指向最后一个元素的下一个。
- end迭代器不能解引用

![image1](pic/pic16.png)

- 范围for来遍历，这种形式更好
- 第一种for只取值，第二种for可以进行修改，auto&

![image1](pic/pic17.png)

auto





### 容器的结构与分类

内存中的样子。



![image1](pic/pic18.png)

>  注意：红色是C++11新增的

- 分类：
	- 1 序列式sequence container；
		- array 数组。连续空间，指定数组的大小，无法扩充
		- vector。头部不能动，分配器自动扩充内存
		- deque。前后均可扩充。
		- list 链表。双向链表（可环状）
		- forward-list。单向链表
	- 2 关联式associative container，便于查找，用key
		- set/multiset。底层是红黑树，左右高度平衡二分树，标准库没有规定必须是红黑树，但是因为红黑树的性质很好。key=value
		- multiset:可以重复
		- map/multimap。key-value
		- multimap:key可以重复
	- unordered container 包含于第二种之中。不定序
		- 上图右侧的小图代表着hashtable，separate chaining，左侧的每一个方框代表一个“篮子”，里面存放了一个指针，或者链表，注意某个链表不可以太长；



![image1](pic/pic19.png)

- 辅助函数



### 容器array




![image1](pic/pic20.png)

- array<long,size> 必须指定类型与数组大小
- .data() 起始元素地址
- clock() 得到目前的程序运行时间



### 容器Vector

![image1](pic/pic21.png)

![image1](pic/pic22.png)

- vector可以扩展，并且扩展的方式是两倍扩展。在另外的地方找一个两倍大的地方，然后拷贝过去
- push_back();
- .size() 实际个数
- .capacity() 容量，也就是第一条说的空间
- find() 算法，是一个全局模板函数
- ::sort()



### 容器list



![image1](pic/pic23.png)

- 双向链表
- list<string>  
- .push_back()
- .max_size()  这个很大
- .front()
- .back()
- .sort()  这个不是全局的sort



### 容器forward_list

![image1](pic/pic24.png)

- forward_list<string>
- .push_front() 只有这个，如上图所示
- .front() 只有这个
- .sort()



### 容器slist（非标准库）



![image1](pic/pic25.png)

- #include <ext/slist>
- 与forward_list 用法相同



### 容器deque

![image1](pic/pic26.png)
![image1](pic/pic27.png)

- 双向开口可进可出
- 两边可扩充。分段连续，但使用者用起来是连续的
- 与vector相比，空间利用率更高
- deque<string>
- ::sort()  全局



### 容器适配器stack



![image1](pic/pic28.png)

- deque 包含了stack
- .push()
- .pop()
- 不提供iterator



### 容器适配器queue

![image1](pic/pic29.png)

- deque包含了queue
- .push()
- .pop()
- 不提供iterator



### 关联式容器multiset



![image1](pic/pic30.png)

- multiset<string>
- .insert() 既不是插头，也不是插尾，而是按照一定的规则
- 插入之后会排序，所以插入比较慢
- 没有push类的操作
- ::find()
- .find() 这个快，并且非常快



### 容器multimap

红黑树

![image1](pic/pic31.png)



- multimap<long,string> 
- .insert(pair<long,string>(,))
- multimap不可以用{}做insert
- .find()  -----找到的iterator

### 容器unordered_multiset

hash table

![image1](pic/pic32.png)
![image1](pic/pic33.png)

- unordered_multiset<string>
- .insert()
- .bucket_count() 篮子一定比元素多
- 单个篮子上的元素=总元素，那么就增加篮子，然后打散重新放
- .find()

### unordered_multimap

![image1](pic/pic34.png)

### set



![image1](pic/pic35.png)

- 不可以重复，key即value



### map

![image1](pic/pic36.png)

- 红黑树
- map<long,string> c
- c[i]=string;
- key不会重复，但value会重复



### 容器unordered_set



![image1](pic/pic37.png)
![image1](pic/pic38.png)
![image1](pic/pic39.png)
![image1](pic/pic40.png)

- 现在改名了，现在叫unordered_XX





## 3 分配器

![image1](pic/pic41.png)

- 每一个容器的声明都是模板，第二个参数是分配器

![image1](pic/pic42.png)
![image1](pic/pic43.png)

- 不要直接用这玩意，直接用容器就可以
- 小内存，用new与delete即可



## OOP GP

（1）标准库中很少有继承关系，因此虚函数很少，关系比较简单；


![image1](pic/pic52.png)

- OOP=数据+操作，OOP是想要把data和method关联在一起打包；
- 为什么list不能用::sort()？
	- RandomAccessIterator 随机访问迭代器。标准库中的::sort()需要随机访问迭代器，而list没有，即list不能随机访问元素

![image1](pic/pic53.png)

- GP是将data和method分开来；
- 表现在标准库中：左侧是容器，即数据，右侧为算法algorithm，即全局函数，method
- 上面两者借助iterator

![image1](pic/pic54.png)

GP？

- Containers和Alogorithm可以各自闭门造车，然后以iterator联通既可；
	- 在右侧图中，对于具体的大于号 小于号，由class自己决定，算法不管
- Alogorithm通过Iterator确定操作范围，并通过Iterators取用Continer元素；

![image1](pic/pic55.png)

- **所有Algorithms，其内最终设计元素本身的操作，无非就是比大小；**



## 源码研究基础

### 1 操作符重载

![image1](pic/pic56.png)
![image1](pic/pic57.png)
![image1](pic/pic58.png)

- 有4个操作符不能被重载

![image1](pic/pic59.png)

- 例子



### 2 模板

泛化、全特化、偏特化



#### 泛化

![image1](pic/pic60.png)

- 类模板
- 类模板必须显示 指定类型。这一点与函数模板不同。因为如果不显示指定，编译器没有任何信息来推导

![image1](pic/pic61.png)

- 函数模板

- typename 与 class 都行

- 不需要显示指定类型，这点与类模板不一样，编译器会做实参推导。

  

![image1](pic/pic62.png)

- 成员模板



#### 全特化

![image1](pic/pic63.png)



![image1](pic/pic64.png)

- 如果符合特化的类型，那么进入特化的函数中
- 出现template <> ，就要特化了

![image1](pic/pic65.png)


#### 偏特化

![image1](pic/pic66.png)

- 两个模板参数，绑定一个，另一个仍是模板参数
- **个数的偏。**上面左侧的例子。vector针对传入的bool类型，就行偏特化设计
- **范围的偏。**单一参数，针对参数的范围进行偏特化，上面右侧的例子，还是一个模板参数，但是针对指针与const指针进行偏特化设计



## 分配器

![image1](pic/pic67.png)

- 右侧的图是malloc分配的内存
- 小内存，附加内存占比就大；大内存，附加内存占比小

![image1](pic/pic68.png)

![image1](pic/pic69.png)

![image1](pic/pic70.png)

![image1](pic/pic71.png)
![image1](pic/pic72.png)

![image1](pic/pic73.png)
![image1](pic/pic74.png)

![image1](pic/pic75.png)
![image1](pic/pic76.png)

![image1](pic/pic77.png)

![image1](pic/pic78.png)

## 容器



### 结构与分类

![image1](pic/pic79.png)

![image1](pic/pic80.png)

- 基础与衍生的关系,标准库中很少有继承，这里并不是继承，而是复合/包含（拥有），has-a关系；
- rb_tree 红黑树，set map 有红黑树，这里不是继承
- slist --> forward_list
- 容器大小，是本身控制的信息占存，与控制的数据多少无关


![image1](pic/pic81.png)

### list

![image1](pic/pic82.png)

* data -- node -- 指针  --list_node
* 因为指针，所以4字节
* 迭代器不能是指针，指针++会连续找内存，但因为在list中内存并不连续，迭代器++就应该指向下一块结点内存
* 容器的iterator迭代器都必须是一个class类（除了vector array），才能成为一个智能指针；所有的容器中都应该有一个typedef将迭代器重名为iterator;
* 因为容器是前闭后开区间，所以最后一个指向一个空的，即灰色的，这个灰色的也是end迭代器指向的

![image1](pic/pic83.png)

- 几乎都有5个typedef
- 所有容器的iterator都有一大堆typedef与操作符重载

![image1](pic/pic84.png)

- 分析iterator++
- 因为前置与后置++都只有一个参数，所以无法区分。c++这样规定，后置加一个参数符号，这样来区分
- 先分析前置++，是将node解引用的next赋给本身，并返回；返回引用
- 在执行后置++时，分为记住原值，进行操作，返回原值，其中进行操作就调用的后置++实现；返回值（致敬整数int型的后置++）
- c++ 不允许后置++两次



![image1](pic/pic85.png)

- 重载*号，取出data

![image1](pic/pic86.png)

- 新版本只传一个参数了
- 新版本



![image1](pic/pic87.png)

- 新版本，更复杂的实现
- 老版本是4字节，新版本是8字节



### Iterator设计原则与Iterator traits

traits特征，特性；

![image1](pic/pic88.png)

- iterator是容器与算法之间的桥梁；算法提问题，迭代器回答；
- iterator_category()是看++，--，能不能跳来跳去，随机访问；
- iterator_difference_type:两个迭代器的距离，表示类型；（unsigned int）
- value_type:iterator所指的元素类型
- 算法提问的问题一共有5种分类，5种typename;另外两种reference和pointer从来没有在C++标准库中使用过，但要写出来；迭代器需要定义的5个类型，以便回答算法提问。
- 这5中type叫做associated type

![image1](pic/pic89.png)

- 必须提供5种
- 看似问题已经解决问题了，为什么要有traits？？
- 但如果iterator并不是一个class，而是一个指针，即一种退化的iterator，指针并不能回答问题，所以需要traits

![image1](pic/pic90.png)

- 加一个中间层

![image1](pic/pic91.png)

- 算法问i，因为不确定i是否是class，所以不能直接问，需要间接问，将i放入iterator_traits中，将iterator_traits作为中间层，
- 如果是class，进入第一个
- 利用traits的偏特化，区分指针与类，如果是指针，进入2或3
- 加上const之后value_type就不能被赋值，就没有什么用，因此为T

![image1](pic/pic92.png)

- 完整版本

![image1](pic/pic93.png)

- 标准库中的其他traits

### vector


![image1](pic/pic94.png)

- 动态增长数组
- 没有东西可以原地扩充内存。都是重新找地方。
- vector的做法：重新找一个**两倍大**的地方
- 3个指针。sizeof(vector) = 3个指针=12字节。
	- begin() ：start
	- start()：finish，指向最后一个数据的下一个
	- size()
	- capacity()
- [] ：类数组，重载该符号
- 

![image1](pic/pic95.png)

- 

![image1](pic/pic96.png)

- 两倍内存增长的问题
- 原大小为0，赋值1，不为0，赋值2倍。
-  vector每次生长都会大量调用元素的拷贝构造和析构函数（原数据删除），要注意！

![image1](pic/pic97.png)

- iterator:链表节点分离，需要两个指针指来指去，所以iterator是一个class，但vector连续内存空间，iterator只要一个指针就可以
- trait 调用偏特化的部分

![image1](pic/pic98.png)

- 新版本
- 没有data，但有父类，所以父类大小就是它的大小
- public继承代表着is a，该处的public继承合理性打个问号

![image1](pic/pic99.png)



![image1](pic/pic100.png)

- 4.9版本，iterator变成了class





### array

就是数组

- 为什么将本来的数组变为容器array?
- 因为要提供迭代器，迭代器就要提供相应的5种类型，以便于连接算法与容器；

![image1](pic/pic101.png)

- TR1版本
- array<int,10> myArray;必须指定大小，不可扩充
- array大小为0，size赋值1
- 没有ctor，dtor
- 连续空间容器，迭代器就可以用指针来表示，array的iterator就是指针

![image1](pic/pic102.png)

- 49版本

### forward_list

![image1](pic/pic103.png)

- 单向链表，结合双向链表



### deque

![image1](pic/pic104.png)

- 双向进出
- 分段连续，串接
- 里面存了很多的指针，如果空间不够需要扩充，就让指针指向一个新的区域
- 迭代器是一个class。分4部分。node指向控制中心，一个buffer。first/last指的是某一个buffer的头与尾，迭代器每一次移动都要判断是否到达边界，如果达到下一个区域，要通过node回到控制中心指向下一个buffer，维持连续的假象。cur指向元素
- 所有容器都有两个迭代器start与finish，begin与end指向他们俩
- map类型T* ，map_size是控制器链表的数量，cur是指向任意一个元素的指针；看起来好像连续，实际上是分段的，每个buffer有一定长度，容器需要头和超尾迭代器即start和finish;

![image1](pic/pic105.png)

- map是一个vector
- deque容器本身的大小有两个iterator+map+map_size=16+16+4+4=40字节
- buffer size是指每个buffer容纳的元素个数

![image1](pic/pic106.png)

- 定义5个associated type

![image1](pic/pic107.png)

![image1](pic/pic108.png)

- 在position安插元素
-  首先判断是否为头尾插入，直接调用push_front()和push_back(),然后根据离哪一端比较近，开始复制挪位置

![image1](pic/pic109.png)

![image1](pic/pic110.png)

![image1](pic/pic111.png)

![image1](pic/pic112.png)

![image1](pic/pic113.png)

![image1](pic/pic114.png)

![image1](pic/pic115.png)

### queue

![image1](pic/pic116.png)

### stack

![image1](pic/pic117.png)

![image1](pic/pic118.png)

![image1](pic/pic119.png)

![image1](pic/pic120.png)

### rb_tree

![image1](pic/pic121.png)

![image1](pic/pic122.png)