# CarYon：一款基于C++的OI/ACM 比赛测试数据生成器

![img](https://img.shields.io/badge/Avatar-luosw-red.svg) ![img](https://img.shields.io/github/package-json/v/luosiwei-cmd/caryon) ![img](https://img.shields.io/npm/dm/datamaker-caryon) ![img](https://img.shields.io/npm/dt/datamaker-caryon) ![](https://img.shields.io/npm/l/datamaker-caryon) ![img](https://img.shields.io/npm/v/datamaker-caryon)

**<img src="https://s.oier.in/cn.png" width="16" alt="CN" /> 大陆简体** [<img src="https://s.oier.in/us.png" width="16" alt="US" /> English](README.en-us.md) [<img src="https://s.oier.in/ru.png" width="16" alt="RU" /> Русский](README.ru.md)

# 前言

## 这是干什么用的？

在举办自己的OI比赛的时候，你有没有遇到过以下问题

- 想快速生成一段文字？
- 想快速进行数学运算来生成数据？
- 想不用freopen等时间一个一个的生成测试数据？
- 希望生成一组随机数据或者数列？
- 快速生成数据来和两个程序对拍？

那么，你可以借助CarYon和C++，来快速生成数据。目前支持的特性有：

- 随机生成一段文章，一些单词，一些字母
- 脱离RAND_MAX的限制，自由拟定随机数
- 正在开发的数学库，支持多种特性
- 建一些圆形，正多边形和分数，用它来进行运算

------

**执行test.cpp在真正1分钟内生成有强度的数据**

希望各位大佬一起来协助改进这个项目。希望这个项目可以帮助大家节省时间！

## 有问题？

欢迎去Github仓库发issue来提问，也欢迎在此文章跟帖。

我的洛谷号：luosw

# 使用说明

## 如何安装？

### npm安装（稳定版本）

可以去GitHub仓库下载最新版，链接在下一个标题那里，还可以在安装了node-js的前提下使用：

```shell
$ npm install datamaker-caryon --save
```

安装这个数据生成器的稳定版本。

### GitHub仓库（最新版本）

https://github.com/luosiwei-cmd/caryon

大家记得star一下哦~

### exe安装（稳定版本）


访问 http://luosw.fun/caryon/caryon-setup.exe 下载安装包，运行安装包，在安装目录（默认为 C://Program Files(x86)/CarYon）就可以找到对应的 `caryon.h` 文件。

## 数据生成

下面的基本操作都是要包含头文件 `caryon.h`，注意，在程序的目录文件夹必须包含头文件经过编译后产生的 `caryon.h.gch` 文件，才能使用数据生成器。

```cpp
makein(1,10){
    csh();
	xxxxx;
}
```

这个操作是用来生成文件：`1.in-10.in`的，可以自由更改`makein`的两个参数进行替换。例如`makein(3,5)`就是生成`3.in-5.in`。

当我们执行完`test.cpp`后就会发现根目录多出来了一个文件夹，里面有`1.in~10.in`的文件，这就是制造的结果。

`csh();`命令绝对不可更改或者替换！

下面这个：

```cpp
dataname="";
```

这个是填写前缀的，例如下面的程序：

```cpp
#include"caryon.h"
using namespace std;
using namespace ca;
int main(){
	dataname="chen_zhe-ak-ioi";
	makein(1,10){
		csh();
		xxx;
	}
}
```

就会在根目录里面的文件夹`data-chen_zhe-ak-ioi`中生成`chen_zhe-ak-ioi1.in~chen_zhe-ak-ioi10.in`了。

**注意，由于新版本原因，`dataname`字段内不可以出现空格！！！**

在我们的所有东西搞完后，记得使用

```cpp
closefile();
```

函数来释放内存空间。（效果类似于fclose，可以不写）

我们已经学会去制造in文件了，怎么创造对应的out文件呢？我们把之前的样例丰富一下：

```cpp
#include"caryon.h"
using namespace std;
using namespace ca;
int main(){
	dataname="chen_zhe-ak-ioi";
	makein(1,10){
		csh();
		xxx;
	}
    makeout(1,10);
}
```

此时，在`test.cpp`所在的目录里面必须有`std.exe`文件，也就是俗称的标准程序。注意一定是标准程序经过编译后的 `std.exe`文件，才能制造出对应的out文件。

下面我们就来制造一个随机数：

```cpp
cyrand(a,b);
```

他的功能是返回一个在`a`到`b`之间的随机数。

这个随机数使用的MT19337(或梅森旋转法)突破了C++自带的RAND_MAX的限制。

(如果要产生一个`long long`范围内的随机数,用cyrand_ll())。

我们再看看怎么把整型的变量存储到输入文件里面去：

```cpp
inint(a);
instring(b);
```

这两个函数都是把东西输入`in`文件的作用，如果我们要输入一个随机数，我们这么写：

```cpp
inint(cyrand());
```

就可以了。

例如下面的程序：

```cpp
#include"caryon.h"
using namespace std;
using namespace ca;
int main(){
    dataname="test";
    makein(1,10){
        csh();
        inint(cyrand(0,100));
    }
}
```

就会发现目录中`data-test`文件夹里面出现了 `test1.in-test10.in`文件，用记事本打开这些文件，就会发现每一个文件里面都有一个随机数。

如果你不知道如何利用记事本打开`in`文件和`out`文件，请右击文件，点击打开方式，找到你的记事本。或者你可以使用 Dev-C++，打开软件，将`in`文件拖进去即可。

对于这个程序，我们如果这样编写 `std.cpp`：

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    cout<<a+10;
    return 0;
}
```

编译后把`test.cpp`改为：

```cpp
#include"caryon.h"
using namespace std;
using namespace ca;
int main(){
    dataname="test";
    makein(1,10){
        csh();
        inint(cyrand(0,100));
    }
    makeout(1,10);
}
```

再用记事本分别打开 `in`和`out` 文件，就可以发现是每个`in`文件的数加 $10$ 的结果了。

由于新版本的功能特性支持，在生成文件的时候会有提示，再也不用担心哪个黑框框一直跳呀跳的啦！

这就是整个数据生成器的工作原理。

我们还可以生成很多随机的东西，例如：

```cpp
cyrand_bool();	//随机布尔类型的值
cyrand_engs(); //随机英文小写字母
cyrand_engb(); //随机英文大写字母
cyrand_formatc(); //随机转义字符
cyrand_word(a);//长度为a的随机词汇
cyrand_article(a); //有a个词汇的随机段落
cyrand_letter(); //随机字符
```

这些东西可以发挥想象自己去DIY，达成想要的效果。

这里还有数学库：

|                         函数/类名称                          |                             作用                             |              参数/类中函数               |
| :----------------------------------------------------------: | :----------------------------------------------------------: | :--------------------------------------: |
| `cabs(T a)`，	`cmin(a,b)`，	`cmax(a,b)`，`cgcd(a,b)`，`lcm(a,b)` |  依次返回 $|a|,a,b$的最小值、最大值、最大公因数和最小公倍数  |                  $a,b$                   |
|                           `cpi()`                            |                        返回 $π$ 的值                         |                    无                    |
|                     stpolyon 正多边形类                      |               flag 作用和 circle 类的东西一样                |    `length,perimeter,edge,oprc(flag)`    |
|                         circle 圆类                          |        支持计算周长面积，`flag==true`时赋值到成员函数        |     `r,c,area,oprc(flag),opra(flag)`     |
|                     `cdistance(a,b,x,y)`                     | 返回在平面直角坐标系中坐标为 $(a,b)$ 的点和坐标 $(x,y)$ 的点的距离 |                 表示坐标                 |
|                         `isprime(a)`                         |                   判断 $a$ 的值是不是质数                    |                   $a$                    |
|                  `crprimenum(int a,int b)`                   |         返回已经制作的序号在 $[a,b]$ 的一个随机质数          |                  $a,b$                   |
|                  `cmakeprime(int a, int b)`                  |        生成在 $[a,b]$ 的质数，储存在集合 $cprime$ 中         |                  $a,b$                   |
|                     quadtri 二次三项式类                     | `s` 就是二次三项式的字母，`make` 制作一个普通的二次三项式，返回值为 `quadtri` 型，`makecanfac` 制作一个可以被因式分解的二次三项式，返回值为 `quadtri` 型 |  `a,b,c,s,make(char),makecanfac(char)`   |
|                         frac 分数类                          | `son,mom` 分别是分子和分母，`value()` 返回分数的值，`take(flag)`返回约分后的分数，`flag==true`的时候有分数线，`fracr()` 返回分数 `string` 型， `flag` 作用同上；另外重载了运算符 `+,-,*,/,>,>=,<,<=,!=,==` | `son,mom,value(),take(flag),fracr(flag)` |
|                         kucan 矩阵类                         | `p,q,dlt[][]`是长，宽和矩阵，`kucan(),in(),out()`是矩阵的生成输入和输出,`+,-,*`重载运算符 |                  见左栏                  |

## 程序对拍

在比赛的过程中，为了检验自己复杂度低的算法是否正确，通常使用再编一个低等算法解决同样问题，然后同时使用大样例对拍这两个程序的生成结果。

现在 CarYon 终于支持对拍功能了！！！

程序的对拍可以大体分为下面几步：

1. 在当前目录编写 `myprogram.cpp` 并且编译成 `myprogram.exe` 文件；
2. 按照数据生成模块写 `test.cpp` 和`std.cpp`；
3. 在`test.cpp`后加一行：

```cpp
debug(/*开始*/,/*结束*/);
```

例如，你正信心满满地提交自己的高精度 a+b，这个时候你就需要用低精的数值和你的程序对拍。

首先，把下面的高精度版a+b放到你的`myprogram.cpp`里面，编译成`myprogram.exe`：

```cpp
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string a,b;
	int xa[500]={},xb[500]={},tot[500]={};
	cin>>a>>b;
	for(int i=0;i<a.length();i++)
		xa[i]=a[a.length()-i-1]-'0';
	for(int i=0;i<b.length();i++)
		xb[i]=b[b.length()-i-1]-'0';
	int len=max(a.length(),b.length());
	for(int i=0;i<len;i++)
		tot[i]=xa[i]+xb[i];
	for(int i=0;i<len;i++)
	{
		tot[i+1]+=tot[i]/10;
		tot[i]%=10;
	}
	if(tot[len]) cout<<tot[len];
	for(int i=len-1;i>=0;i--)
		cout<<tot[i];
	cout<<endl;
}

```

然后在 `std.cpp` 中填写最简单的 `a+b`；

并且这样编写 `test.cpp`：

```cpp
#include"caryon.h"
//已经包含万能头文件
using namespace std;
using namespace ca;	//命名空间


int main(){
	dataname="a+btest";	//这里写自己的前缀
	makein(1,10){
		csh();
		/*这里请自行看使用文档和两个测试范例填写*/
	} 
	makeout(/*起始*/,/*次数*/);
    debug(/*起始*/,/*次数*/);//程序对拍命令，可以不写
	//makeout的值必须小于等于makein 
	//请把std编译好放到本文件夹，一定要有exe文件 
	//感谢您的支持
	return 0;
}
```

**注意，由于新版本原因，`dataname`字段内不可以出现空格！！！**

运行后可以发现不仅有`data-a+btest`文件夹，里面有`a+btest1.in/out-a+btest10.in/out`，还出现了一个新的文件夹`debug-a+btest`文件夹，里面是`myprogram.exe`输出的`a+btest1.ans-a+b10.ans`，然后自己可以运用 `cmd`里面的`comp`函数比较这两个文件的大小吧！

## `test.cpp`使用说明

在**根目录**的`test.cpp`的原来的信息如下：

```cpp
#include"caryon.h"
//已经包含万能头文件
using namespace std;
using namespace ca;	//命名空间


int main(){
	dataname="";	//这里写自己的前缀
	makein(/*起始*/,/*次数*/){
		csh();
		/*这里请自行看使用文档和两个测试范例填写*/
	} 
	makeout(/*起始*/,/*次数*/);
    debug(/*起始*/,/*次数*/);//程序对拍命令，可以不写
	//makeout的值必须小于等于makein 
	//请把std编译好放到本文件夹，一定要有exe文件 
	//感谢您的支持
	return 0;
}
```

切记不可更改程序的整体框架，否则你的执行结果会出现问题

1. `dataname`是输入输出文件的前缀，不填则没有前缀；
2. `makein()`中的次数是生成in文件的数量；
3. `makein`中的`csh;`切记不可更改，更改会出现未知错误；
4. `makeout`中的次数必须小于`makein`中的，且默认是从`前缀1.in`开始形成`out`文件，可以续传。

在运行程序之前，一定要把std的exe文件放置在同样的文件夹下。

### 生成 a+b problem数据 `test.cpp`编写示范

```cpp
#include"caryon.h"
//已经包含万能头文件
using namespace std;
using namespace ca;	//命名空间


int main(){
	dataname="a+b test";	//这里写自己的前缀
	makein(1,10){
		csh();
		inint(cyrand(-1000,1000));
        instring(" ");
        inint(cyrand(-1000,1000));
	} 
	makeout(1,10);
	//makeout的值必须小于等于makein 
	//请把std编译好放到本文件夹，一定要有exe文件 
	//感谢您的支持
	return 0;
}
```

解释：a+b的数据是两个随机数（中间有空格），所以需要使用`instring(" ");`函数加入空格，同样的，如果需要换行就需要使用`instring("\n");`，然后就是两个随机数的问题了。

对于高精度数据，可以按照下面的循环生成：

```cpp
inint(cyrand(1,9));
for(int i=0;i<高精度数据的长度-1;i++){
    inint(cyrand(0,9));
}
```

上述的程序仅仅可以生成一个高精度数据。

上述内容已经可以足够对noip选手的数据生成了，故之后不讲，等待用户自行探寻。如果有问题请在本界面留言，谢谢！

# 更新公告

## CarYon 1.0

- 发布于2020.4.14
- 最先版本，对标crayon

## CarYon 1.1

- 发布于2020.4.15
- 支持分数类的重载运算符+,-,*,/,>,>=,<,<=,!=,==
- 支持矩阵和矩阵的重载运算符

## CarYon 1.2

- 发布于2020.4.16
- 支持生成随机字母，字符，文章，单词，转义字符
- 新增了正多边形类
- 支持自定义数据起始和终止

### CarYon 1.2.1

隐式更新，没有实际功能更新

### CarYon 1.2.2

- 发布于2020.4.17
- 增加了一个灰度功能（就不告诉你是哪个）

## CarYon 1.3

- 发布于2020.4.18
- 新增了二次三项式类

### CarYon1.3.1

修复了一个重大bug

## CarYon 1.4

- 发布于2020.4.22
- 新增二次三项式的加减运算。

## CarYon 2.0

CarYon 2.0发布啦惹惹惹。

- 文档有重大更新。
- in/out 文件的生成增加了提示。
- in/out 文件生成放在同一个子文件夹中。
- 增加对拍功能，同时生成`myprogram.cpp`的`ans`文件和`std.cpp`的`out`文件，这样就可以自行比较辣！
- 将`csh()`命令替换成函数，所以一定要记得加括号哦。

------

谢谢您的兹磁！
