# CarYon An OI/ACM Contest Test Data Generator based on C++



![img](https://img.shields.io/badge/Avatar-luosw-red.svg) ![img](https://img.shields.io/github/package-json/v/luosiwei-cmd/caryon) ![](https://img.shields.io/npm/dm/datamaker-caryon) ![](https://img.shields.io/npm/dt/datamaker-caryon) ![](https://img.shields.io/npm/l/datamaker-caryon) ![](https://img.shields.io/npm/v/datamaker-caryon)

# Front

Have you ever encountered the following problems when holding a self-contained OI match:

- Want to quickly produce a paragraph of text?
- Want to quickly perform mathematical operations to generate data?
- Want to generate test data one by one without using freopen?
- Want to generate a set of random data or series?
- Quickly generate data to match the two programs?

Then, you can use CarYon and C++ to quickly generate data. Previously supported features are:

- Randomly generate a chapter, some words, some words
- Get out of the limitation of RAND_MAX, freely draft random numbers
- Mathematics library under development, supporting multiple features
- Create some circles, regular polygons and fractions, and use it to perform calculations

------

Perform **test.cpp** in real **1** within minutes to have the intensity data

Hope you guys can help improve this project. Hope this item can help everyone save time!

## Something wrong?

You are welcome to send an issue to the Github repository to ask questions, and you are also welcome to post in this chapter.

# Instructions for use

## How to install?

### **npm** installation (stable version)

You can go to the GitHub repository to download the latest version, the link is in the next title, and it can also be used with node-js installed：

```shell
$ npm install datamaker-caryon --save
```

nstall the stable version of this data generator.

### **GitHub** repository (latest version)

https://github.com/luosiwei-cmd/caryon

Everyone, remember to star~

### **exe** installation (stable version)

Visit **[http://luosw.fun/caryon/caryon-setup.exe to](https://translate.google.com/translate?hl=zh-CN&prev=_t&sl=auto&tl=en&u=http://luosw.fun/caryon/caryon-setup.exe)** download the installation package, run the installation package, in the installation directory (the default isC://Program Files(x86)/CarYon) can find the corresponding `caryon.h` file.

## Data generation

The basic operations below are to include the header file `caryon.h` . Note that the header file must be included in the program’s directory folder after being compiled

Only the `caryon.h.gch` file produced later can the data generator be used.

```cpp
makein(1,10){
    csh();
	xxxxx;
}
```

This operation is used to create files: `1. In-10.in` , you can freely change the two parameters of `makein` for replacement. E.g`makein(3,5)` is to produce `3.in-5.in` .When we finish `test.cpp` , we will find that there is an extra folder in the root directory. There are files from `1.in to 10.in`. This isIs the result of manufacturing

`csh();`The command must not be changed or replaced!

Here:

```cpp
dataname="";
```

This is to fill in the prefix, such as the following program:

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

It will be created in the folder `data-chen_zhe-ak- ioi` of the root directory into `chen_zhe-ak-ioi1.in~chen_zhe-ak-ioi10.in` .

Note that due to the new version, no spaces can appear in the dataname field! ! !

After all our things are done, remember to us

```cpp
closefile();
```

Function to free up memory space. (The effect is similar to fclose, you don’t need to write it)

We have learned to create` in` files, how to create corresponding` out `files? Let's enrich the previous examples:

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

At this time, there must be a `std.exe` file in the directory where `test.cpp` is located , which is commonly known as a standard program. Note that it must be the standard.

After the program is compiled, the `std.exe` file can produce the corresponding out file.

Let's create a random number below:

```cpp
cyrand(a,b);
```

Its function is to return a random number between `a` and `b` .

The MT19337 (or Mason rotation method) used by this random number breaks through the limitation of C++'s native RAND_MAX.

(If you want to generate a random number in the `long long` range, use `cyrand_ll()`).

Let's take a look at how to store integer variables in the input file:

```cpp
inint(a);
instring(b);
```

Both of these functions are used to input things into the `in` file. If we want to input a random number, we write:

```cpp
inint(cyrand());
```

That's it.

For Example:

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

Of Contents will find in the data-test folder in the display will appear `test1.in-test10.in` files, Using Notepad to open these files,

You will find that every file has a random number.

If you don’t know how to use Notepad to open `in` files and `out` files, please right-click the file, click Open Mode, and find your note

this. Or you can use Dev-C++, open the software, and drag the `in` file into it.

For this program, if we write `std.cpp` like this :

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

After compiling, change `test.cpp` to:

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

Then use Notepad to open the `in` and `out` files separately , you can find that the number of each in file is added $10$ the result is out.

Due to the support of the new version's features and features, there will be a prompt when the file is created, so you don't have to worry about which frame is jumping and jumping!

This is the working principle of the entire data generator.

We can also generate many random things, such as:

```cpp
cyrand_bool (); //Random Boolean type value
cyrand_engs (); //Random English lowercase letters
cyrand_engb (); //Random English uppercase letters
cyrand_formatc (); //random escape character
cyrand_word ( a ); //A random word of length a
cyrand_article ( a ); //A random paragraph with a vocabulary
cyrand_letter (); //random character
```

These things can be used to DIY and achieve the desired effect.

There is also a math library.

## Program match

In the course of the competition, in order to check whether the algorithm with low complexity is correct, it is usually used to compile a low-level algorithm to solve the same problem.

Then use a large sample at the same time to shoot the results of these two programs.

Now CarYon finally supports the camera-matching function! ! !

The matching of the program can be divided into the following steps:

1. Write `myprogram.cpp` in the current directory and compile it into a `myprogram.exe` file;
2. Write `test.cpp `and `std.cpp` according to the data generation module ;
3. Add a line after`test.cpp`：

```cpp
debug(/*start*/,/*end*/);
```

For example, if you are confidently submitting the high-precision a+b, you need to use low-precision values to match your program.

First, put the following high-precision version a+b into your `myprogram.cpp` and compile it into `myprogram.exe` :

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

Then fill in the simplest a+b in `std.cpp` ;

And write `test.cpp` like this 

```cpp
#include"caryon.h"//Already include universal header files
using namespace std ;
using namespace ca ; //Namespace
int main (){
    dataname = "a+btest" ; //Write your own prefix here
    makein ( 1 , 10 ){
        csh ();/*Please look at the use document and two test examples by yourself here*/
    }
    makeout ( /*start*/ , /*number of times*/ );
    debug ( /*start*/ , /*number of times*/ );
    //program matching command, you don’t need to write
    //The value of makeout must be less than or equal to makein
    //Please compile std and put it in this folder, there must be an exe file
    //thank you for your support
    return 0 ;
}
```

Note that due to the new version, no spaces can appear in the dataname field! ! !

After the operation, you can find that not only the `data-a+btest` folder, but also `a+btest1.in/out-a+btest10.in/out` , but also A new folder `debug-a+btest` appears , the folder is `a+btest1.ans- a+btest10.ans`output by `myprogram.exe` , and then you can use `cmd` 's `comp` function to compare these two files!

## Instructions for use of` test.cpp`

The original information of `test.cpp` in the root directory is as follows:

```cpp
#include"caryon.h"//Already include universal header files
using namespace std ;
using namespace ca ; //Namespace
int main (){
    dataname = "a+btest" ; //Write your own prefix here
    makein ( 1 , 10 ){
        csh ();/*Please look at the use document and two test examples by yourself here*/
    }
    makeout ( /*start*/ , /*number of times*/ );
    debug ( /*start*/ , /*number of times*/ );
    //program matching command, you don’t need to write
    //The value of makeout must be less than or equal to makein
    //Please compile std and put it in this folder, there must be an exe file
    //thank you for your support
    return 0 ;
}
```

Remember not to change the overall framework of the program, otherwise there will be problems with your execution results

1. dataname is the prefix of the input and output files, if you leave it blank , there will be no prefix;

2. The number of times in makein() is the number of in files generated;

3. Csh in makein ; remember that it cannot be changed, there will be an unknown error when changing;

4. The number of times in makeout must be smaller than that in makein , and the default is to form out files starting from the prefix 1.in , which can be continued

### **a + b problem** data `test.cpp` preparing model

```cpp
#include"caryon.h"
using namespace std;
using namespace ca;	


int main(){
	dataname="a+b test";	
	makein(1,10){
		csh();
		inint(cyrand(-1000,1000));
        instring(" ");
        inint(cyrand(-1000,1000));
	} 
	makeout(1,10);
	return 0;
}
```

Explanation: The data of a+b are two random numbers (with spaces in between), so you need to use the `instring(" ")`; function to add spaces, if you need to change the line, you need to use `instring("\n");`, and then there is a problem of two random numbers.

For high-precision data, it can be generated in the following cycle:

```cpp
inint(cyrand(1,9));
for(int i=0;i<高精度数据的长度-1;i++){
    inint(cyrand(0,9));
}
```

The above program can only generate a high-precision data.

The above content is enough to generate the data selected by noip, so I won't talk about it later, and wait for the user to explore it myself. If you have any questions, please comments, thank you!

------

谢谢您的兹磁！
