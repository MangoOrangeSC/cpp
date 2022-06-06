

## 构造函数

### 构造函数在private

![image1](pic/pic24.png)





![image1](pic/pic25.png)



## 参数传递与返回值

### 

![image1](pic/pic26.png)



- const 修饰函数。定义函数的时候，函数名后面➕const，**对于不会改变数据内容的函数，一定要加上const。**

- const 修饰变量。对于上面右侧调用方式，我们创建一个常量复数然后输出实部虚部，**如果上面real和img函数定义的时候，没有加const，那么这里函数默认的意思是可能会改变数据，与我们的常量复数就矛盾了。**编译器会报错。因此，对于不会改变数据内容的函数，一定一定要加const。







![image1](pic/pic27.png)


- 参数传递，传递value是把整个参数全传过去，double4字节。尽量不要直接value传递。
- 尽可能传递引用reference，传引用相当于传指针，很快，形式又很漂亮。
- 传引用过去，修改之后，都会改变；如果只是为了提升速度，不向改变数据，那么传const引用。这样传进去的东西，不能被修改。







### 

![image1](pic/pic28.png)

- 返回值的传递，也尽量返回引用。
- 1中操作符重载的声明中，没有写变量名，也可以写上。c++中，声明函数的时候，可以不写变量名，实现的时候必须写。

### 

![image1](pic/pic29.png)

- 友元：friend，修饰在函数定义之前，**表示这个函数可以直接拿该类对象的private数据。**
- 如上面所示，声明为friend之后，函数可以直接取到re和im，如果不被声明为friend，**只能通过调用real和imag函数来得到，效率较低。**

![image1](pic/pic30.png)

- 相同class的不同对象objects互为友元，即可以直接拿到另一个object的data。





![image1](pic/pic31.png)

引用的传递和返回的情况

函数的操作结果放置：

- 某个已经有的变量位置

- 必须在函数里面创建的local变量：不可以返回引用



## 操作符重载与临时对象

### 

![image1](pic/pic32.png)

- 第一种方式，写成成员函数。**所有的成员函数都带有一个隐藏的参数this（是一个指针），this表示（指向）调用这个函数的调用者。**
- 定义函数的时候，**在参数列中不能写出来this**，直接用即可。



![image1](pic/pic33.png)
- **传递者无需知道接受者是以引用形式接受。**
- 这里面虽然返回值需要的是引用，但是代码中写的返回值可以是value。
- +=操作符中，定义的参数是引用，但是传进去的c1也可以是value。
- 接收端使用什么形式接收与传递者无关。


![image1](pic/pic34.png)

### 

![image1](pic/pic35.png)



- 非成员函数的操作符重载。（没有this）
- 应对客户的三种方法，写出三种方式，使用时进行重载。
- 非成员函数是global函数。
- 这些函数不能返回引用，必须是一个local object。**因为这里面的操作符中二者不是一个加到另一个上，是两个对象相加，因此返回必须是一个对象，不是引用。**
- typename()，创建一个typename类型的临时对象。

![image1](pic/pic36.png)

![image1](pic/pic37.png)
![image1](pic/pic38.png)
![image1](pic/pic39.png)
![image1](pic/pic40.png)

- cout不认识新定义的这种复数，因此也需要对<<进行操作符重载。

cout << 只能全局函数重载

因为cout为标准库中的，不可能认识<<这个符号，所以只能写成全局函数重载

cout是一个object，type是ostream

重载时第一参数一定不能是const




### 编程示例

```
#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

class complex
{
public:
  complex (double r = 0, double i = 0): re (r), im (i) { }   //参数列表
  complex& operator += (const complex&);
  complex& operator -= (const complex&);
  complex& operator *= (const complex&);
  complex& operator /= (const complex&);
  double real () const { return re; }       // 考虑const的问题  //inline
  double imag () const { return im; }
private:
  double re, im;

  friend complex& __doapl (complex *, const complex&);
  friend complex& __doami (complex *, const complex&);
  friend complex& __doaml (complex *, const complex&);
};


#endif   //__MYCOMPLEX__

```

class 外
```

inline complex&
__doapl (complex* ths, const complex& r)
{
  ths->re += r.re;
  ths->im += r.im;
  return *ths;
}


inline complex&                          //reference
complex::operator += (const complex& r)  //const
{
  return __doapl (this, r);
}


//如果设计在class里，只能有这一种，后面两种没法重载
inline complex
operator + (const complex& x, const complex& y)
{
  return complex (real (x) + real (y), imag (x) + imag (y)); //临时对象
}

inline complex
operator + (const complex& x, double y)
{
  return complex (real (x) + y, imag (x));
}

inline complex
operator + (double x, const complex& y)
{
  return complex (x + real (y), imag (y));
}
```



![image1](pic/pic47.png)

## 三大函数

拷贝构造、拷贝赋值、析构

下面我们学习另一种类，带指针的类，string.h的实现。

### 

![image1](pic/pic48.png)
to do:

s3=s2; //赋值

- 同样进行防卫式的声明。
- string s3(s1)就是拷贝构造，s3=s2是拷贝赋值。
- 不写的话，会使用编译器默认的拷贝构造赋值（一个bit一个bit的复制）。针对带有指针的，编译器默认的只是拷贝了指针，而不是指针指向的数据。**因此，如果类中有指针，需要写这两个函数**

### 





![image1](pic/pic49.png)

big three
- data 是动态的，提前不能指定大小，不能直接设定一个xx长度的数组，这样会导致内存浪费。
- **因此数据应该是一个指向字符的指针，给出字符串之后，可以动态的调整占用内存。**
- 函数2：拷贝构造
- 函数3：操作符重载：拷贝赋值
- 函数4：析构函数
- 函数5：inline

### 

strlen

strcpy

![image1](pic/pic50.png)



strlen

strcpy

- 字符串是一个指针，最后有结束符号\0。

- 如果传入的是0，说明是空字符串，则只有一个结束符号。

- 析构函数，释放指针指向的内存。

类中有指针，必须写拷贝构造和拷贝赋值，不然会内存泄漏。

### 

![image1](pic/pic51.png)

- 浅拷贝与深拷贝

- 默认的是浅拷贝。


![image1](pic/pic52.png)



- 我们需要的是深拷贝。
- 拷贝另一个string指针指向的字符串内容。



![image1](pic/pic53.png)

- 拷贝赋值，两边目前都有东西。

- 检测自我赋值（效率与安全）
- 清空
- 创建同样大小
- 拷贝

自我赋值：自己赋给自己。




![image1](pic/pic54.png)



- 第一个动作：将自己kill


![image1](pic/pic55.png)

- 第二个动作 分配空间


![image1](pic/pic56.png)



- 第三个动作 深拷贝

![image1](pic/pic57.png)



- 但是，如果是自己，直接就把唯一存在的杀掉了

### 

![image1](pic/pic58.png)

## 堆、栈与内存管理
![image1](pic/pic59.png)



- 栈是存在于某作用域的一块内存空间。
- 堆是由操作系统提供的一块全局内存空间，用new来动态取得。**在栈中的，作用域结束，则释放了；在堆中的，需要手动释放。**

### 

![image1](pic/pic60.png)

- 结束之后，会自动调用析构函数。

![image1](pic/pic61.png)

- 加上static之后，会存在到整个程序结束。程序结束之后才会调用析构函数。

![image1](pic/pic62.png)

![image1](pic/pic63.png)

![image1](pic/pic64.png)



- 先分配了内存，将指针转型，通过指针调用构造函数。
- 内部使用malloc分配内存。



![image1](pic/pic65.png)

- 先调用析构函数，再释放内存。
- 内部使用free来释放。

![image1](pic/pic66.png)
![image1](pic/pic67.png)

### 
![image1](pic/pic68.png)

- **Vc调试模式下，前后都带着灰色的内存部分**（上面32，下面4），还有头尾的cookie（每个cookie4字节）。分配的内存都是16的倍数，因此填充到64字节。
- 执行模式下，没有灰色的，则占用16字节。
- cookie表示使用了多少字节，每一位是4位bit，因为内存必须是16的倍数，因此最后四位bit一定都是0，借用最后的一位1表示占用内存，0表示释放内存。







![image1](pic/pic69.png)

- 左边的，最后加的4字节，保存数组的长度。
- 右边的同理。

### 

![image1](pic/pic70.png)

- **array new一定要搭配array delete，否则会内存泄漏。因为普通的delete只调用一次析构函数。内存泄漏会发生在剩下两个，因为剩下两个没有调用析构函数。**
- 这种情况主要发生在有指针的类，因为如果没有指针的类（比如之前的复数），没有动态分配内存new，因此也就不需要调用自己写的析构函数来杀掉。

### 编程示例

存放一个指针，4byte，可以动态分配内存

class with pointer ：big3 不能加const

![image1](pic/pic71.png)
![image1](pic/pic72.png)
![image1](pic/pic73.png)

![image1](pic/pic74.png)

- new一个足够大的空间
  ![image1](pic/pic75.png)
  
- return 没有，在某些情况也可以，但不能连续赋值

- 关注是否是自我赋值！

![image1](pic/pic76.png)

## 类模板、函数模板以及补充

### static
![image1](pic/pic77.png)
- 在数据或函数前加static关键字，则变为静态函数/数据。
- 非静态数据成员：每个对象一份
- 一个成员函数complex::real(&c1)，要处理很多个数据，需要靠某个东西告诉他处理谁，就是this pointer。来告诉他处理从c1、c2、c3。成员函数有一个隐藏的this pointer参数。
- 加上static之后，这个数据就不属于这个对象了，跟这个对象脱离。例如银行账号没人不一样，但利率大家都一样，利率可以为static
- 加上static之后与之前，这个函数都不属于这个对象。
- **静态函数没有this pointer参数，因此不能直接处理普通的对象，只能处理静态数据。**

![image1](pic/pic78.png)
- 这个例子中，利率mrate是静态数据，set_rate是静态函数。
- 静态变量要在类外定义。
- 静态函数set_rate只能处理静态数据。
- 调用静态函数的方式有两种：静态函数可以通过对象object来调用，也可以通过class name来调用。

![image1](pic/pic79.png)
- singleton
- 构造函数放在private中，不想让外界创建。
- 设计一个静态函数，来返回唯一的那一份，这个静态函数是外界取得这一份的唯一方法。
- 调用这个静态函数之后，才开始创建这唯一的一份。
- 静态临时变量：离开函数，变量仍然存在

![image1](pic/pic80.png)

### cout
![image1](pic/pic81.png)

- cout是一种ostream。
- 设计了很多种<<的操作符重载。



### 模板

![image1](pic/pic82.png)

- 使用T来代替某种类型，类模板。
- 使用的时候，<>中写明类型，编译器就会把T全部替换为这种类型。


![image1](pic/pic83.png)
- 函数模板。function template
- **用的时候不需要用<>绑定类型，编译器会根据传进去的对象类型自动绑定T类型。**
- 这样比较的时候，小于号<符号就会使用T类型中重载的<符号来进行。


### namespace
![image1](pic/pic84.png)
- 名字被包在命名空间中
- 使用命名空间：三种方法


![image1](pic/pic85.png)

## oop ood
![image1](pic/pic86.png)

## 组合与继承
### 复合
![image1](pic/pic87.png)


![image1](pic/pic88.png)
- queue类里面，有一个sequence类东西。
- 这个sequence是deque<T>
- queue里面所有的功能，都是调用c的功能来完成的。
- deque功能强大，但用在queue中，只开放一部分功能，变成一个adapter

![image1](pic/pic89.png)

- 内存角度来看
- queue中有deque，deque的源代码中，还有另一个复合，Itr<T>。
- 从内存的角度看，queue占用40字节。

![image1](pic/pic90.png)
- 左边拥有右边
- 外部的构造函数先调用内部的构造函数；外部的析构函数先执行自己，然后调用内部析构
- **复合情况下的构造函数，由内而外，析构函数，由外而内。**代码中红色的部分，是编译器来完成的。**编译器会调用内部的默认的构造函数或析构函数。**如果不希望调用默认的，那么就需要自己写代码。

### 委托 delegation ： composition by reference
![image1](pic/pic91.png)
- 引用方式（即使传的指针，一般也称为by reference）的复合，即左边has a右边类的指针。
- pimpl pointer to implementation 通过指针把任务委托给右边的类
- reference couting ：内容一样，n用来计数，保存有几个人指过来了
- 复合中，内部和外部是一起出现的，即调用二者的构造函数；而委托的话，因为是指针，是不同步的，当需要右边的时候，才创建这个。
- 应用实例：右面的类为具体的实现，左边只是调用的接口。


### 继承 inheritance，表示is-a
![image1](pic/pic92.png)
- 继承，表示is-a，是一种（父类）。
- 父类的数据会被完整继承下来。
- 子类拥有自己的以及父类的数据。

![image1](pic/pic93.png)
- 子类的对象中有父类的成分。
- 构造时，类似于**复合**，先调用父类的构造函数，然后再调用自己的。
- 析构时，先析构自己，然后析构父类的。
- 父类的dtor必须是virtual

## 虚函数与多态
![image1](pic/pic94.png)
- 搭配虚函数来完成继承
- 在任何成员函数之前加上virtual关键字，即为虚函数。
- 子类可以调用父类的函数，即继承了函数（实际上是继承了函数的调用权）。
- 分类
	- 非虚函数，是不希望子类重新定义（override）的函数。
	- 虚函数，希望子类重新定义它，且已有默认定义。
	- 纯虚函数，希望子类重新定义它，且目前没有默认定义，一定要去定义。即函数定义后面直接=0。
- 上图中，定义了一个父类shape，其中定义了几种成员函数。objectID是非虚函数，不需要重新定义。error是虚函数，有默认定义，可以重新定义。draw函数是纯虚函数，没有默认定义，必须要子类来重新定义。


![image1](pic/pic95.png)
- 上图为一个例子

![image1](pic/pic96.png)
- 父类中其他可以通用，读文件这个函数Serialize设置为虚函数，需要override。
- 我们定义一个读文档的类，那么serialize函数就要override成读文档的函数。
- **调用serialize时，通过隐藏的this pointer来调用，因为myDoc.OnFileOpen，因此this就是myDoc，因此调用的是我们override之后的serialize函数。**
- 这就是设计模式，template method：一种函数

![image1](pic/pic97.png)

- 模拟

![image1](pic/pic98.png)
- 子类有父类的part，同时有component
- 构造函数如何调用？顺序？首先调用父类的构造函数，然后调用复合的构造函数，然后调用自己的构造函数。
- 子类有父类的part，父类有component
- 构造函数-先component 再base 再derived

![image1](pic/pic99.png)


### 委托+继承
![image1](pic/pic100.png)

- observer来观察subject的数据。一个subject数据可以有多个observer来观察。observer是一个父类，可以定义子类来继承，因此可以有不同的观察方法。
- 当数据改变的时候，observer也需要更新，即notify函数，来将目前所有的observer更新。

![image1](pic/pic101.png)


![image1](pic/pic102.png)

![image1](pic/pic103.png)

- 设计一种类似窗口的类，窗口中可以有其他窗口，窗口中有其他类对象。
- primitive是对象个体，composite是一种窗口容器，特殊点在于放的可能是其他对象，也可能是窗口。
- **因此把primitive和composite都继承自component，然后composite容器存放的是指向component对象的指针即可。这样composite中存放的可能是窗口，也可能是对象。**
- 这就是设计模式：composite。
- component中add是虚函数，不能是纯虚函数，因为primitive无法override add函数。composite需要override add函数，使得容器可以存放窗口，也可以存放对象。



![image1](pic/pic104.png)

-     想要创建未来才会出现的子类（下面是派生的子类）。
-     子类中，安排一个静态对象（_LAST）,然后把它放到父类之前开辟出的一个空间中，这样父类就可以看到新创建的子类。
-     这个静态对象创建的时候，调用自己私有的构造函数，调用addPrototype，这样就把自己放到了父类中。
-     子类中，还需要准备一个clone函数。这样父类就可以通过调用clone方法来创建这种子类的副本。


![image1](pic/pic105.png)

![image1](pic/pic106.png)
![image1](pic/pic107.png)
