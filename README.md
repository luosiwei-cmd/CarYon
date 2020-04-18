# CarYon

# 项目基本简介：

项目logo：

![CarYon](https://s1.ax1x.com/2020/04/17/JVvEWj.png)

项目开发者：![](https://img.shields.io/badge/Avatar-luosw-red.svg)

项目最新版本：![](https://img.shields.io/badge/Version-1.3.0-green.svg)

访问：http://luosw.fun/caryon

查看详情。

# 前言

## 这是干什么用的？

在举办自己的OI比赛的时候，你有没有遇到过以下问题

- 想快速生成一段文字？
- 想快速进行数学运算来生成数据？
- 想不用freopen等时间一个一个的生成测试数据？
- 希望生成一组随机数据或者数列？

那么，你可以借助CarYon和C++，来快速生成数据。目前支持的特性有：

- 随机生成一段文章，一些单词，一些字母
- 脱离RAND_MAX的限制，自由拟定随机数
- 正在开发的数学库，支持多种特性
- 建一些圆形，正多边形和分数，用它来进行运算

---

**执行test.cpp在真正1分钟内生成有强度的数据**

希望各位大佬一起来协助改进这个项目。希望这个项目可以帮助大家节省时间！

## 使用基本条例

> 没有竞争就没有进步

已经有了两款测试数据生成器了，但是作为在地球上，必须有竞争，有对手，才有进步。

**因此我们推出了CarYon** 为了让大家习惯，这里我们的库仍然命名为`crayon.h`。

现在开放2种使用方式：

- 免费版本：每2个周的大更新。
- 联系作者定制：详情见我的帖子。

------

GitHub仓库将于今天下午在此帖放置。

------

需要授权版的请私信luosw

以上就是发布的原帖子。

## 有问题？

欢迎去Github仓库发issue来提问，也欢迎在此文章跟帖。

我的洛谷号：luosw

# 使用说明

## 如何安装？

可以去GitHub仓库下载最新版，链接在下一个标题那里，还可以在安装了node-js的前提下使用：

```
$ npm install datamaker-caryon --save
```

安装这个数据生成器的稳定版本。

## GitHub仓库地址

https://github.com/luosiwei-cmd/caryon

大家记得star一下哦~

## 基本操作

```cpp
makein(1,10){
    csh;
	xxxxx;
}
```

这个操作是用来生成文件：`1.in-10.in`的，可以自由更改`makein`的两个参数进行替换。当我们执行完`test.cpp`后就会发现根目录多出来了`1.in~10.in`的文件，这就是制造的结果。

csh绝对不可替换！

```cpp
dataname="";
```

这个是填写前缀的，例如：

```cpp
#include"caryon.h"
using namespace std;
using namespace ca;
int main(){
	dataname="chen_zhe-ak-ioi";
	makein(1,10){
		csh;
		xxx;
	}
}
```

就会在根目录生成`chen_zhe-ak-ioi1.in~chen_zhe-ak-ioi10.in`了。

在我们的所有东西搞完后，记得使用

```cpp
closefile();
```

函数来释放内存空间。

我们已经学会去制造in文件了，怎么创造对应的out文件呢？我们把之前的样例丰富一下：

```cpp
#include"caryon.h"
using namespace std;
using namespace ca;
int main(){
	dataname="chen_zhe-ak-ioi";
	makein(1,10){
		csh;
		xxx;
	}
    makeout(1,10);
}
```

此时，在`test.cpp`所在的目录里面必须有`std.exe`文件，也就是俗称的标准程序。

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

```cpp
stpolyon正多边形类：public成员：length,perimeter,edge
		函数:oprc(flag)  //flag作用和circle类的东西一样
circle圆类：public成员：r,c,area
		函数：oprc(flag),opra(flag)	//支持计算周长面积，flag==true时赋值到成员函数。
cpi()	//返回π的值
cdistance(a,b,x,y)	//返回在平面直角坐标系中坐标为(a,b)的点和坐标(x,y)的点的距离
cabs(T a)	//返回a的绝对值
cmin(a,b)	//返回a,b中的最小值
cmax(a,b)	//返回a,b中的最大值
cgcd(a,b)	//返回a,b的最大公因数
lcm(a,b)   	//同理
isprime(a)	//判断是不是质数
cmakeprime(int a, int b)	//生成在[a,b]的质数，储存在数组cprime中
crprimenum(int a,int b)	//返回已经制作的序号在[a,b]的一个随机质数
frac类：public成员：son,mom //分别是分子和分母
		函数：value()	//返回分数的值
			take(flag)	//返回约分后的分数，flag为真时有分数线'/'
			fracr(flag)	//返回分数，flag作用同上
		重载运算符：+,-,*,/,>,>=,<,<=,!=,==
kucan矩阵类：public函数:p,q,dlt[][]
			函数：kucan()	//初始化
				in(),out()	//输入和输出
				+,-,*//重载运算符
```

## test.cpp使用说明

在**根目录**的test.cpp的原来的信息如下：

```cpp
#include"crayon.h"
//已经包含万能头文件
using namespace std;
using namespace ca;	//命名空间


int main(){
	dataname="";	//这里写自己的前缀
	makein(/*起始*/,/*次数*/){
		csh;
		/*这里请自行看使用文档和两个测试范例填写*/
	} 
	makeout(/*起始*/,/*次数*/);
	//makeout的值必须小于等于makein 
	//请把std编译好放到本文件夹，一定要有exe文件 
	//感谢您的支持
	return 0;
} 
```

切记不可更改程序的整体框架，否则你的执行结果会出现问题

1. dataname是输入输出文件的前缀，不填则没有前缀；
2. makein()中的次数是生成in文件的数量；
3. makein中的`csh;`切记不可更改，更改会出现未知错误；
4. makeout中的次数必须小于makein中的，且默认是从`前缀1.in`开始形成out文件，可以续传。

在运行程序之前，一定要把std的exe文件放置在同样的文件夹下。

## 两个样例的使用说明

### a+b problem

这里是洛谷的P1001的使用，可以查看`test.cpp`了解程序的编写。

### 奖学金

洛谷P1093，可以仿照`a+b problem`查看程序的编写

### 神贴

这个可以自己看了。

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

---

谢谢您的兹磁！