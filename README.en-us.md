# CarYon



# Basic introduction of the project:



Project logo:



![CarYon](https://s1.ax1x.com/2020/04/17/JVvEWj.png)



Project developer: ![project](https://img.shields.io/badge/avatar-luosw-red.svg)



Latest project version: ![version](https://img.shields.io/badge/version-1.3.0-green.svg)



Visit: http://luosw.fun/caryon



View details.



Preface



## What is this for?



Have you ever had any of the following problems when organizing your own oi competition



- Want to quickly generate a paragraph of text?

- Want to do math quickly to generate data?

- Do you want to generate test data one by one without waiting for freeopen?

- Want to generate a set of random data or series?



So, you can use caryon and C + + to generate data quickly. Currently supported features are:



- Randomly generate a passage, some words, some letters

- Free formulation of random number without the limitation of rand_max

- Math library under development, supporting multiple features

- Build some circles, regular polygons and fractions, and use them to do operations



---



**Execute test.cpp to generate strong data in 1 minute**



I hope you guys will come together to help improve this project. Hope this project can help you save time!



## Basic rules for use



> No competition, no progress



There are already two test data generators, but as on earth, there must be competition, competition, and progress.



**So we launched caryon * * to get you used to it, our library is still named 'crayon. H'.



Now there are two ways to use it:



- Free version: big update every 2 weeks.

- Contact author Customization: see my post for details.



---



GitHub warehouse will be placed in this post this afternoon.



---



If you need an authorized version, please contact luosw



The above is the original post.



## Something wrong?



Welcome to GitHub warehouse to ask questions, and also welcome to post this article.



My Logue: luosw



# Instructions for use



## How to install?



You can go to GitHub warehouse to download the latest version, link to the next title, and use it on the premise of node JS installation:



```

$ npm install datamaker-caryon --save

```



Install a stable version of this data generator.



## GitHub warehouse address



https://github.com/luosiwei-cmd/caryon



Remember star~



## Basic operation



```cpp

makein(1,10){

CSH;

Xxxxx;

}

```



This operation is used to generate files: ` 1. In-10. In `. You can freely change the two parameters of' make in 'to replace them. After executing 'test. CPP', we will find that there are more '1. In ~ 10. In' files in the root directory, which is the result of manufacturing.



CSH is absolutely irreplaceable!



```cpp

Dataname= "";

```



This is prefixed, for example:



```cpp

#include"caryon.h"

using namespace std;

using namespace ca;

Int main () {

dataname="chen_zhe-ak-ioi";

makein(1,10){

CSH;

XXX;

}

}

```



It will generate 'ABCD ak-ioi1. In ~ ABCD ak-ioi10. In' in the root directory.



Remember to use it when we're done with everything



```cpp

Closefile ();

```



Function to free memory space.



We have learned to create in files. How to create out files? Let's enrich the previous examples:



```cpp

#include"caryon.h"

using namespace std;

using namespace ca;

Int main () {

dataname="chen_zhe-ak-ioi";

makein(1,10){

CSH;

XXX;

}

makeout(1,10);

}

```



At this time, there must be a 'std.exe' file in the directory where 'test. CPP' is located, which is also known as the standard program.



Let's make a random number:



```cpp

Cyrand(a, b);

```



His function is to return a random number between 'a' and 'B'.



This random number uses mt19337 (or Mason rotation method) which breaks through the limitation of rand_max in C + +.



(if you want to generate a random number in the range of 'long long long', use cyrand'll()).



Let's see how to store integer variables in the input file:



```cpp

Inint(a);

Instring(b);

```



These two functions are used to input things into the 'in' file. If we want to input a random number, we write as follows:



```cpp

inint(cyrand());

```



Just fine.



We can also generate many random things, such as:



```cpp

Cyrand_bool(); / / random Boolean value

Cyrand_engs(); / / random English small letters

Cyrand_engb(); / / random English capital letters

Cyrand_format(); / / random escape character

Cyrand_word(a); / / a random word of length a

Cyrand_article(a); / / random paragraph with a word

Cyrand_letter(); / / random characters

```



These things can be used to imagine yourself going to DIY to achieve the desired effect.



Here is the math library:

# 翻不动了
