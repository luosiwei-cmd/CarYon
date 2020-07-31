# CarYon: генератор тестовых данных OI / ACM на основе C ++

![img](https://img.shields.io/badge/Avatar-luosw-red.svg) ![img](https://img.shields.io/github/package-json/v/luosiwei-cmd/caryon) ![](https://img.shields.io/npm/dm/datamaker-caryon) ![](https://img.shields.io/npm/dt/datamaker-caryon) ![ ](https://img.shields.io/npm/l/datamaker-caryon) ![](https://img.shields.io/npm/v/datamaker-caryon)

[<img src="https://s.oier.in/cn.png" width="16" alt="CN" /> 大陆简体](README.md) [<img src="https://s.oier.in/us.png" width="16" alt="US" /> English](README.en-us.md) **<img src="https://s.oier.in/ru.png" width="16" alt="RU" /> Русский**

# Предисловие

## Для чего это?

При проведении своего собственного конкурса OI, вы столкнулись со следующими проблемами

- Хотите быстро сгенерировать абзац текста?
- Хотите быстро выполнить математические операции для генерации данных?
- Хотите генерировать тестовые данные по очереди, не дожидаясь freopen?
- Хотите сгенерировать набор случайных данных или рядов?
- Быстро генерировать данные для соответствия двум программам?

Затем вы можете использовать CarYon и C ++ для быстрой генерации данных. В настоящее время поддерживаются следующие функции:

- Случайно генерировать абзац, несколько слов, несколько букв
- Без ограничений RAND_MAX, свободно составлять случайные числа
Разрабатываемая математическая библиотека поддерживает несколько функций
- Создайте несколько кругов, правильных многоугольников и дробей и используйте их для расчетов

------

**Выполните test.cpp для создания надежных данных в течение 1 минуты**

Я надеюсь, что вы все можете помочь улучшить этот проект. Надеюсь, что этот проект поможет всем сэкономить время!

## что-то не так?

Перейдите в репозиторий Github, чтобы опубликовать вопрос, чтобы задать вопросы, и вы можете опубликовать эту статью.

Мой номер Луогу: luosw

# Инструкции по использованию

## Как установить?

### установка npm (стабильная версия)

Вы можете перейти в репозиторий GitHub, чтобы загрузить последнюю версию, ссылка находится в следующем заголовке, и ее также можно использовать с установленным node-js:

```sh
$ npm install datamaker-caryon --save
```

Установите стабильную версию этого генератора данных.

### GitHub репозиторий (последняя версия)

https://github.com/luosiwei-cmd/caryon

Пожалуйста, не забудьте пометить ~

### exe установка (стабильная версия)


Посетите http://luosw.fun/caryon/caryon-setup.exe, чтобы загрузить установочный пакет, запустить установочный пакет, в установочном каталоге (по умолчанию C: // Program Files (x86) / CarYon) вы можете найти соответствующий `caryon.h` файл.

## Генерация данных

Следующие основные операции должны включать файл заголовка `caryon.h`. Обратите внимание, что папка каталога программы должна содержать файл` caryon.h.gch`, сгенерированный после того, как файл заголовка скомпилирован перед использованием генератора данных.

```cpp
makein (1,10) {
    csh();
ххххх;
}
```

Эта операция используется для генерации файла: `1.in-10.in`, вы можете свободно изменять два параметра` makein` для замены. Например, `makein (3,5)` сгенерирует `3.in-5.in`.

Когда мы выполним `test.cpp`, мы обнаружим, что в корневом каталоге есть дополнительная папка, которая содержит файлы из` 1.in ~ 10.in`, что является результатом изготовления.

`csh();` Команда не должна быть изменена или заменена!

Последующий:

```cpp
dataname = "";
```

Это необходимо для заполнения префикса, такого как следующая программа:

```cpp
#include "caryon.h"
using namespace  std;
using namespace ca;
int main () {
  dataname = "chen_zhe-ак-ioi";
  makein (1,10) {
    csh();
    ххх;
  }
}
```

Он сгенерирует `chen_zhe-ak-ioi1.in ~ chen_zhe-ak-ioi10.in` в папке` data-chen_zhe-ak-ioi` в корневом каталоге.

**Обратите внимание, что из-за новой версии пробелы не могут появляться в поле `dataname`! !  **

После того, как все наши вещи сделаны, не забудьте использовать

```cpp
closefile ();
```

Функция для освобождения места в памяти. (Эффект похож на fclose, вам не нужно его писать)

Мы научились создавать в файлах, как создавать соответствующие файлы? Давайте обогатим предыдущий пример:

```cpp
#include "caryon.h"
using namespace std;
using namespace ca;
int main () {
  dataname = "chen_zhe-ак-ioi";
  makein (1,10) {
        csh();
        ххх;
     }
  makeout (1,10);
}
```

В это время в каталоге, где находится `test.cpp`, должен быть файл` std.exe`, который обычно называют стандартной программой. Обратите внимание, что стандартной программой должен быть скомпилированный файл `std.exe`, прежде чем можно будет создать соответствующий файл out.

Давайте создадим случайное число ниже:

```cpp
cyrand (а, b);
```

Его функция - возвращать случайное число между `a` и` b`.

MT19337 (или метод вращения Мейсона), используемый этим случайным числом, преодолевает ограничение RAND_MAX, которое поставляется с C ++.

(Если вы хотите сгенерировать случайное число в диапазоне «long long», используйте `cyrand_ll ()`).

Давайте посмотрим, как хранить целочисленные переменные во входном файле:

```cpp
inint ();
instring ("");
```

Обе эти функции используются для ввода данных в файл `in`. Если мы хотим ввести случайное число, мы пишем:

```cpp
inint (cyrand ());
```

Вот и все.

Например, следующая программа:

```cpp
#include "caryon.h"
using namespace std;
using namespace ca;
int main () {
    dataname = "test";
    makein (1,10) {
        csh();
        inint (cyrand (0100));
    }
}
```

Вы найдете файл test1.in-test10.in в папке data-test в каталоге. Откройте эти файлы с помощью Блокнота, и вы найдете случайное число в каждом файле.

Если вы не знаете, как открыть файл `in` и файл` out` с помощью Блокнота, щелкните правой кнопкой мыши файл и выберите Открыть метод, чтобы найти свой Блокнот. Или вы можете использовать Dev-C ++, открыть программное обеспечение и перетащить в него файл `in`.

Для этой программы, если мы напишем `std.cpp` так:

```cpp
#include <bits/stdc++.h>
using namespace std;
int main () {
    int a;
    cin >> а;
    cout << а + 10;
    return 0;
}
```

После компиляции измените `test.cpp` на:

```cpp
#include "caryon.h"
using namespace std;
using namespace ca;
int main () {
    dataname = "test";
    makein (1,10) {
        csh();
        inint (cyrand (0100));
    }
    makeout (1,10);
}
```

Затем используйте Блокнот, чтобы открыть файлы `in` и` out` соответственно, и вы можете обнаружить, что это результат добавления $ 10 $ к числу каждого файла `in`.

Благодаря поддержке функций новой версии, при создании файла будет отображаться подсказка, поэтому вам не нужно беспокоиться о том, какой черный ящик продолжает прыгать и прыгать!

Так работает весь генератор данных.

Мы также можем генерировать много случайных вещей, таких как:

```cpp
cyrand_bool (); // Случайное логическое значение
cyrand_engs (); // Случайные английские строчные буквы
cyrand_engb (); // Случайные английские заглавные буквы
cyrand_formatc (); // случайный escape-символ
cyrand_word (a); // Случайное слово длины a
cyrand_article (a); // Случайный абзац со словарем
cyrand_letter (); // Случайные символы
```

Эти вещи можно использовать, чтобы представить себе DIY и достичь желаемого эффекта.

## Соответствие программы

В ходе конкурса для проверки правильности алгоритма низкой сложности мы обычно используем другой алгоритм низкого уровня для решения той же проблемы, а затем используем большую выборку для сравнения сгенерированных результатов двух программ.

Теперь CarYon наконец-то поддерживает функцию съемки! ! !

Соответствие программы можно условно разделить на следующие этапы:

1.  Напишите `myprogram.cpp` в текущем каталоге и скомпилируйте его в файл` myprogram.exe`;
2.  Напишите `test.cpp` и` std.cpp` в соответствии с модулем генерации данных;
3.  Добавьте строку после `test.cpp`:

```cpp
debug(/ * начало * /, / * конец * /);
```

Например, вы уверенно отправляете свои высокоточные a + b. В настоящее время вам необходимо сопоставить вашу программу с низкими значениями точности.

Сначала поместите следующую высокоточную версию a + b в ваш `myprogram.cpp` и скомпилируйте ее в `myprogram.exe`:

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

Затем заполните простейшие `a + b` в` std.cpp`;

И напишите `test.cpp` так:

```cpp
#include "caryon.h"
// Уже включаем универсальные заголовочные файлы
using namespace  std;
using namespace имен ca; // Namespace


int main () {
  dataname = "a+btest"; // Напишите здесь свой префикс
  makein (1,10) {
    csh ();
    / * Пожалуйста, посмотрите здесь документ на использование и два тестовых примера самостоятельно * /
  }
  makeout(/ * начало * /, / * количество раз * /);
   debug (/ * start * /, / * количество раз * /); // команда соответствия программы, вам не нужно писать
// Значение makeout должно быть меньше или равно makein
// Пожалуйста, скомпилируйте std и поместите его в эту папку, там должен быть exe-файл
	//Спасибо за Вашу поддержку
  return 0;
}
```

**Обратите внимание, что из-за новой версии пробелы не могут появляться в поле `dataname`! ! !**

После запуска можно обнаружить не только папку `data-a + btest`, но также` a+btest1.in / out-a + btest10.in / out`, но и новую папку `debug-a + btest` folder, inside - это вывод` a + btest1.ans-a + b10.ans` с помощью `myprogram.exe`, и затем вы можете использовать функцию `comp` в `cmd`, чтобы сравнить размер этих двух файлов!

## `test.cpp` Инструкция по применению

Исходная информация `test.cpp` в **корневой директории** выглядит следующим образом:

```cpp
#include "caryon.h"
// Уже включаем универсальные заголовочные файлы
using namespace  std;
using namespace имен ca; // Namespace

int main () {
  dataname = ""; // Напишите здесь свой префикс
  makein (1,10) {
    csh();
    / * Пожалуйста, посмотрите здесь документ на использование и два тестовых примера самостоятельно * /
  }
  makeout(/ * начало * /, / * количество раз * /);
  debug (/ * start * /, / * количество раз * /); // команда соответствия программы, вам не нужно писать
// Значение makeout должно быть меньше или равно makein
// Пожалуйста, скомпилируйте std и поместите его в эту папку, там должен быть exe-фай
//Спасибо за Вашу поддержку
  return 0;
}
```

Помните, что не следует менять общую структуру программы, иначе у ваших результатов выполнения будут проблемы

1. `dataname` - это префикс входных и выходных файлов, если вы оставите это поле пустым, префикса не будет;
2. Число раз в `makein ()` - количество сгенерированных файлов;
3. `csh;` в `makein` не должен быть изменен. При изменении произойдут неизвестные ошибки;
4. Количество раз в `makeout` должно быть меньше, чем в` makein`, и по умолчанию формируются файлы `out`, начиная с` prefix 1.in`, что можно продолжить.

Перед запуском программы обязательно поместите файл std exe в ту же папку.

### Генерируем a + b проблемные данные `test.cpp` пишем демонстрацию

```cpp
#include "caryon.h"
// Уже включаем универсальные заголовочные файлы
using namespace std;
using namespace ca; // Namespace


int main () {
  dataname = "a+b test"; // Напишите здесь свой префикс
  makein (1,10) {
    csh();
    inint (cyrand (-1000,1000));
    instring ("");
    inint (cyrand (-1000,1000));
  }
  makeout (1,10);
  return 0;
}
```

Объяснение: Данные a + b представляют собой два случайных числа (с пробелами между ними), поэтому для добавления пробелов вам необходимо использовать функцию `instring (" ");` а затем есть два случайных числа.

Для высокоточных данных их можно сгенерировать в следующем цикле:

```cpp
inint (cyrand (1,9));
for (int i = 0; i <длина высокоточных данных-1; i ++) {
    inint (cyrand (0,9));
}
```

Вышеуказанная программа может генерировать только высокоточные данные.

Вышеуказанного контента достаточно для генерации данных noip-плееров, поэтому я не буду говорить об этом позже и подожду, пока пользователи сами исследуют. Если у вас есть какие-либо вопросы, пожалуйста, оставьте сообщение на этом интерфейсе, спасибо!