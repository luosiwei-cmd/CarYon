# caryon

caryon---C++方式测试数据生成利器。

---

支持命令：

```
随机数相关：
cyrand()	返回一个int类型的随机数
cyrand_ll()	返回一个long long型的随机数
cyrand(a,b)	返回一个在a，b之间的int随机数(a<b)
cyrand_ll(a,b)	返回一个在a，b之间的long long随机数(a<b)
cyrand_bool()	返回一个bool类型的随机数
cyrand_engs()	返回任意一个小写字母
cyrand_engb()	返回任意一个大写字母
数学相关：
stpolyon类：public成员：length,perimeter,edge
		函数:oprc(flag)  flag作用和⚪一样
circle类：public成员：r,c,area
		函数：oprc(flag),opra(flag)	支持计算周长面积，flag==true时赋值到成员函数。
cpi()	返回Π的值
cdistance(a,b,x,y)	返回在平面直角坐标系中坐标为(a,b)的点和坐标(x,y)的点的距离
cabs(T a)	返回a的绝对值
cmin(a,b)	返回a,b中的最小值
cmax(a,b)	返回a,b中的最大值
cgcd(a,b)	返回a,b的最大公因数
lcm(a,b)   	同理
isprime(a)	判断是不是质数
cmakeprime(int a, int b)	生成在[a,b]的质数，储存在数组cprime中
crprimenum(int a,int b)	返回已经制作的序号在[a,b]的一个随机质数
frac类：public成员：son,mom 分别是分子和分母
		函数：value()	返回分数的值
			take(flag)	返回约分后的分数，flag为真时有分数线'/'
			fracr(flag)	返回分数，flag作用同上
		重载运算符：+,-,*,/,>,>=,<,<=,!=,==
kucan矩阵类：public函数:p,q,dlt[][]
			函数：kucan()	初始化
				in(),out()	输入和输出
				+,-,*重载运算符
数据存储类
inint(int a)	在测试数据中输入一个a
instring(string s)	在测试数据中形成s
colsefile()     重定向到控制台
---
其他信息见使用说明和根目录的test.cpp
			
```

---

请查看3个样例了解程序使用，访问 http://luosw.fun/caryon  查看程序的完整使用说明