### 构造函数在private

![image1](pic/pic24.png)





![image1](pic/pic25.png)



### 常量成员函数

![image1](pic/pic26.png)



- const 修饰函数

- const 修饰变量





### 参数传递

![image1](pic/pic27.png)



传value，根据不同系统跟数据会消耗不同byte，速度慢

传引用，速度快，const引用，不能修改，并且要尽量传引用






### 返回值传递

![image1](pic/pic28.png)

### 友元

![image1](pic/pic29.png)

### 同一个class的各个object互为friend

![image1](pic/pic30.png)

### 引用的传递和返回的情况

函数的操作结果放置：

- 某个已经有的变量位置

- 必须在函数里面创建的local变量：不可以返回引用

![image1](pic/pic31.png)


### 操作符重载-1,成员函数

![image1](pic/pic32.png)

### return by reference

![image1](pic/pic33.png)

![image1](pic/pic34.png)

### 操作符重载-2，非成员函数

![image1](pic/pic35.png)

不可以返回reference，这是一个临时量

typename() 创建临时变量

![image1](pic/pic36.png)

![image1](pic/pic37.png)
![image1](pic/pic38.png)
![image1](pic/pic39.png)
![image1](pic/pic40.png)

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


### string class
![image1](pic/pic48.png)
to do:

s3=s2; //赋值



### big three



- data 是动态的，提前不能指定大小

- 函数2：拷贝构造
- 函数3：操作符重载：拷贝赋值
- 函数4：析构函数
- 函数5：inline

![image1](pic/pic49.png)

### ctor dtor

strlen

strcpy

![image1](pic/pic50.png)

### class with pointer member必须有copy ctor  copy op=

浅拷贝与深拷贝

![image1](pic/pic51.png)

深拷贝
![image1](pic/pic52.png)

### 拷贝赋值

- 检测自我赋值（效率与安全）

- 清空
- 创建同样大小
- 拷贝

自我赋值：自己赋给自己。

![image1](pic/pic53.png)

第一个动作：将自己kill
![image1](pic/pic54.png)
第二个动作 分配空间
![image1](pic/pic55.png)
第三个动作 深拷贝
![image1](pic/pic56.png)

但是，如果是自己，直接就把唯一存在的杀掉了
![image1](pic/pic57.png)

### output
![image1](pic/pic58.png)

### 所谓stack 所谓heap
![image1](pic/pic59.png)

### stack objects的生命期
![image1](pic/pic60.png)
### static local objects的生命期
![image1](pic/pic61.png)

### global objects的生命期

![image1](pic/pic62.png)

### heap objects的生命期

![image1](pic/pic63.png)
![image1](pic/pic64.png)
![image1](pic/pic65.png)
![image1](pic/pic66.png)
![image1](pic/pic67.png)
![image1](pic/pic68.png)
![image1](pic/pic69.png)
![image1](pic/pic70.png)
![image1](pic/pic.png)
