Template Test
===============

C++的模板有一个较大的缺陷，模板的实现是不能放到独立的cpp文件中的，因为模板函数的特点，必须要类型确定时才能泛化。

例如下面的例子：

```cpp
// CObject.h
template<class T>
class CObject
{
public:
	CObject(T k) {obj = k;}
	~CObject() {}
	T getObj();
private:
	T obj;
};
```


```cpp
// CObject.cpp
#include "CObject.h"

template<class T>
T CObject<T>::getObj(){
	return this->obj;
}
```


```cpp
#include <cstdio>
#include "CObject.h"

using namespace std;

int main(){
	CObject<int> Obj(10);
	int k = Obj.getObj();
	printf("%d\n", k);
    return 0;
}

```

这样分三个文件编写，是无法通过编译的，因为`getObj`这个函数，是模板函数，没有对应的实例泛化是不会生成代码的。

于是编译时报错，找不到`getObj`

解决的方法一般有，直接将模板代码放置到.h中，或者在引用时换成：

```cpp
#include "CObject.cpp"
```

但这样都造成了一个问题，如果模板类在开发中，经常需要修改，那么所有引用它的cpp都需要重复编译，比较耗时。

为解决这一问题，我们可以采取模板的分离编译方式，在另外一个文件中，声明所有需要用到的模板，这样就可以避免其他文件中的模板函数引入。

```cpp
// CObjectExpand.cpp

#include "CObject.cpp"

template class CObject<int>;
```
