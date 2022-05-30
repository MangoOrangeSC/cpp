# OOP by HOUJIE 

【前言】

C++程序设计（下）兼谈对象模型



## 1.  **转换函数conversion function**

![image1](pic/pic12.png)

- 转换函数，对象的类型之间进行转换。
- 黄色部分即为转换函数，**要以operator开头，函数名称为需要转成的类型，不可以有参数。前面不需要写返回类型，因为c++会自动返回函数名称这个类型。**
- 转换函数通常后面有const，即不需要改变数据则要加const。
- 写好之后，在将Fraction对象转成double的时候，会调用我们写好的转换函数。

## 2. **non-explicit-one-argument ctor**

one-argument表示只要一个实参就够了，当然两个实参也可以。（数学上3认为是3/1，1是默认值）

non-explicit

![image1](pic/pic13.png)

- 这里没有写转换函数，二是重载了+操作符。
- 重载之后的+是分数+分数，编译器处理d2 = f+4的时候，发现右边不是分数，则看4能否转换成分数。
- 因为是只需要一个实参的构造函数，因此4可以转为分数，则可以调用重载之后的+。
- 因此non-explicit-one-argument ctor可以把其他类型转换为该类型

![image1](pic/pic14.png)

- 如果这两个并存了，编译器就不知道该调用哪个了。（不知道把分数转为double还是把int转为分数）

![image1](pic/pic15.png)

- **构造函数加上explicit之后，表示这个构造函数只能在构造的时候使用，不会在转换类型时使用了。**
- 这个explicit关键字主要就出现在这里。

![image1](pic/pic16.png)

- 标准库里的转换函数

## 3. **pointer-like classes** 

关于智能指针

![image1](pic/pic17.png)

- 设计的class，像指针。智能指针，完成比指针更多的工作。一般都是包着一层普通指针。
- 指针允许的动作，这个类也需要允许操作。
- `*操作符和->操作符`都需要重载。
- 这样调用sp->的时候，实际上内部重载操作符，将内部的普通指针px返回出来，然后px可以继续使用->来完成。**相当于这个->符号用了两次。**



迭代器

![image1](pic/pic18.png)

- 迭代器也类似一种智能指针
- 迭代器这种智能指针还需要处理++，--等符号。

![image1](pic/pic19.png)

- 这里面node用 * 号，则是取得data。

## **4. function-like classes**

设计一个class，行为像一个函数，即仿函数。

![image1](pic/pic20.png)

- 即可以使用小括号来调用。
- 对小括号（）操作符进行重载。
- 灰色处有东西

![image1](pic/pic21.png)

![image1](pic/pic22.png)
![image1](pic/pic23.png)

## 5. namespace
![image1](pic/pic24.png)

- 使用namespace将不同的函数包在里面，这样可以避免混淆。

## **6. 类模板**

![image1](pic/pic25.png)

- **类模板**
- 设计class的时候，如果数据的类型可以指定，那么就可以使用类模板。

![image1](pic/pic26.png)

- **函数模板**
- 函数模板不必要指定参数类型。因为函数模板一定要传入参数，编译器自己推倒
- 与上面的类模板一致，在设计函数的时候，如果传入的参数可以指定，那么就使用模板。
- 在函数定义前面，写template<class T >
- 或者，template<typename T>

![image1](pic/pic27.png)

- 黄色部分是成员模板，它即是模板的一部分（在pair类中），自己又是模板，则称为成员模板。

![image1](pic/pic28.png)



- 右上角设计了四种class。
- 右下角的最后三行，设计了一个pair的构造函数，可以使用<U1,U2>这种pair对象p作为初值来构造一个pair，将p的first和second作为构造的pair的first和second。
- **例子就是，可以使用<鲫鱼，麻雀>对象来构造一个<鱼类，鸟类>的pair。如左下角所示。**

![image1](pic/pic29.png)

- new一个子类，这个指针类型是指向父类，是可以的，叫做up-cast。
- 智能指针也必须可以这样。并且智能指针的实现方式就是成员模板

## 7. specialization特化
![image1](pic/pic30.png)

- 特化是泛化模板的反面。
- 上图的上方是泛化，下方是特化
- 在使用模板之后，可以针对不同的类型，来设计不同的东西。
- 使用template<>，后面指定类型，比如struct hash<char>进行特定的设计。

![image1](pic/pic31.png)

- 偏特化，即局部特化。
- 第一种是个数的偏，比如上面的模板有两个，特化其中一个为bool类型。
- 从左向右绑定

![image1](pic/pic32.png)

- 第二种是范围的偏
- 可以把参数的范围缩小，比如上面，如果只要传进来的是指针，就使用下面这种。而指针指向的是什么，不需要考虑。



## **8. 模板模板参数**

模板中的一个模板参数也为模板。

![image1](pic/pic33.png)

- 只有模板的尖括号中<>，typename和class写哪个都行，互通。
- 要使用最后一行代码来使用，第一个参数为string，第二个模板参数本身为模板，引入Lst，来作为第二参数。
- 必须用第二个方框内的

![image1](pic/pic34.png)
![image1](pic/pic35.png)

- 第二个用法，第二个参数已经不是模板了，很清晰，没有灰色地带了





## 9. 关于C++标准库

![image1](pic/pic36.png)

- 容器、迭代器、算法。

![image1](pic/pic37.png)
![image1](pic/pic38.png)
![image1](pic/pic39.png)
![image1](pic/pic40.png)

- 可以看出版本

## **10. C++11新特性**

三个主题。

variadic templates 数量不定的模板参数

![image1](pic/pic41.png)

- 模板的参数可以变化，使用...即可，表示任意个数。个数...与类型...都任意，都可以...
- 示例中，将模板参数分为一个和一包参数，后面的一包参数数量任意。
- 这个示例中，使用了递归，不断地将一包参数里的每一个print...，直到最后一个，调用了没有参数的print，结束。
- 使用sizeof...(args)可以直到现在这个参数包中有多少个参数。

![image1](pic/pic42.png)

- auto：编译器自动匹配返回类型。

![image1](pic/pic43.png)

- 范围for
- 使用单冒号来进行for循环遍历。右边必须是容器
- **注意pass by reference**



## **11. reference引用**

![image1](pic/pic44.png)

- x是整数，p是指向x的指针，r是x的引用。
- x是整数，占4字节；p是指针，32位机器上占4字节；**r代表x，那么r也是整数，占4字节。**
- 逻辑上r是这样，但底部的实现也是指针，即r也是指向x的指针。（即使底部是这样，但是引用占用的大小也需要与代表的物体一样，这是编译器创建出的假象）
- 注意上方的“注意”！！！
- **引用与指针不同，不可以改变，代表一个变量之后，就不能改变。**所以第5句话是在赋值。

![image1](pic/pic45.png)

- 这里r和x都是8字节，且地址也相同，实际是假象。

![image1](pic/pic46.png)

- reference通常用在参数传递与返回上。
- reference通常不用于声明变量。
- 引用不能重载？两个函数的签名相同。
- const是函数签名的一部分，可以并存

![image1](pic/pic47.png)


## 复习
![image1](pic/pic48.png)
![image1](pic/pic49.png)

- 红色为编译器添加

![image1](pic/pic50.png)

## **12. vptr和vtbl**

![image1](pic/pic51.png)

- 三个类，B继承了A，C继承了B。因此三个类所占的内存如左边所示。
- 子类对象中，有父类的成分（part）。
- **当类中有虚函数的时候，对象就会多一个指针。（无论多少个虚函数，都是多一个指针，即vptr）**，因此占用的内存，会多一个指针的空间（4字节）。
- **继承的时候，会继承父类的函数的调用权，不会继承函数的大小。**
- vptr只会关联到虚函数上，与一般函数无关。**vptr指向一个表格vtbl，里面是虚函数的位置。**
- 调用函数则是动态绑定，通过指针p找到vptr，找到vtbl，再找到调用的函数。`(*p->vptr[n])(p)`，则调用第n个虚函数。



![image1](pic/pic52.png)

- 声明时指针要指向父类
- 调用哪个子类，就指向哪个子类即可：即**动态绑定**，也就是多态！！！
- C风格，则是需要if逐个判断，如果新增加了，就要增加判断，很不好！
- 动态绑定--多态--虚函数



汇编语言

![image1](pic/pic54.png)
![image1](pic/pic55.png)

## **13. 关于this pointer**

通过对象来调用函数，这个对象的地址即是this pointer

虚函数：多态以及这里

![image1](pic/pic53.png)

- 父类中其他可以通用，但读文件这个函数Serialize比较具体，需要后续实现，所以设置为虚函数，需要override。
- 我们定义一个读文档的类，那么serialize函数就要override成读文档的函数。
- **调用serialize时，通过隐藏的this  pointer来调用，因为myDoc.OnFileOpen，CDocument::OnFIleOpen(&myDoc)，因此this就是myDoc（这里就是上面说的动态绑定，this指向的serialize，是重载过的虚函数），此时在运行CDocument::OnFIleOpen函数时，虽然该函数没有显示的参数，但此时隐式包含了指向myDoc的this指针，此时在调用Serialize()函数，就是调用了myDoc的函数，如上图右上方所示，因此调用的是我们override之后的serialize函数。**
- 这就是设计模式，template method



## 14.浅谈const

![image1](pic/pic57.png)



![image1](pic/pic58.png)

- const放在成员函数定义小括号的后面，表示修饰这个**成员函数**。**表示我这个成员函数不准备改变class的data。**
- const可以进行函数重载。
- **当两个版本同时存在的时候，**const object只能调用const版本，non-const object只能调用non-const版本。注意与上面的表做区分，这是一个特殊的规定。
- 常量对象是不可以调用非常量函数的，非常量对象可以调用常量函数。



## **15. 关于new、delete**

![image1](pic/pic59.png)

- 这里面的new和delete是表达式，之后具体执行几步，调用的是operator new，完成操作（详细可见上门课程）。
- **这里面的new和delete表达式无法重载，但是分解，之后的几步操作是可以重载的。**

![image1](pic/pic60.png)

- 加::表示这是全局的
- 全局重载operator，new、delete、new[]、delete[]。
- 这几个函数我们不会调用，是编译器会调用，**我们new、delete的时候，编译器会找这几个操作符函数有没有重载。**
- 重载了之后，全局的new和delete都调用这个版本。

![image1](pic/pic61.png)

- 在class中成员重载new、delete
- 重载之后，new这个类的时候，使用重载之后的操作符函数。

![image1](pic/pic62.png)
![image1](pic/pic63.png)
![image1](pic/pic64.png)
![image1](pic/pic65.png)
![image1](pic/pic66.png)
![image1](pic/pic67.png)
![image1](pic/pic68.png)
![image1](pic/pic69.png)
