## Навигация   
[1. Краткое описание](#Description)  
[2. Постановка задачи](#Task)  
[3. Проектирование классов](#ClassDesign)  
[3.1 Классы-сущностей](#EntityClass)  
[3.2 Управляющие классы](#ControlClass)  
[3.3 Интерфейсные классы](#InterfaceClass)  
[4. Описание интерфейса](#InterfaceDiscription)  
[5. Сборка и настройка](#Build)  
[6. Руководство пользователя](#UserGuide)  
[7. Пример](#Example)  
  
<a name="Description"><h2>Краткое описание</h2></a>
Приложение было разработано на языке C++ в среде Microsoft Visual Studio 2019 с использованием фреймворка QT(расширение для MSVS) для создания графического интерфейса.  
Приложение позволяет пользователю выполнить операцию сложения, вычитания, умножения, деления или сравнения (по модулю/аргументу) между двумя комплексными числами.  
<a name="Task"><h2>Постановка задачи</h2></a>
Необходимо разработать иерархию классов (не менее 10), реализующих комплексную арифметику.  
  
*Требования*:  
**1. Стандартная модель комплексных чисел**  
> [Комплексное число](https://ru.wikipedia.org/wiki/%D0%9A%D0%BE%D0%BC%D0%BF%D0%BB%D0%B5%D0%BA%D1%81%D0%BD%D0%BE%D0%B5_%D1%87%D0%B8%D1%81%D0%BB%D0%BE)(стандартная модель) — это выражение вида a+bi, где a, b — действительные числа, а i — так называемая мнимая единица, символ, квадрат которого равен –1, то есть ![equation](https://latex.codecogs.com/svg.image?i%5E2=-1). Число a называется действительной частью, а число b — мнимой частью комплексного числа z=a+bi.  
  
**2. Действия над комплексными числами – сложение, вычитание, умножение, деление и сравнение**  
*Сложение комплексных чисел*  
> Суммой двух комплексных чисел ![equation](https://latex.codecogs.com/svg.image?z_1=a&plus;bi) и ![equation](https://latex.codecogs.com/svg.image?z_2=c&plus;di) будет комплексное число вида ![equation](https://latex.codecogs.com/svg.image?z=z_1&plus;z_2=(a&plus;bi)&plus;(c&plus;di)=(a&plus;c)&plus;(b&plus;d)i)   
  
*Вычитание комплексных чисел*  
> Разностью двух комплексных чисел ![equation](https://latex.codecogs.com/svg.image?z_1=a&plus;bi) и ![equation](https://latex.codecogs.com/svg.image?z_2=c&plus;di) будет комплексное число вида ![equation](https://latex.codecogs.com/svg.image?z=z_1-z_2=(a&plus;bi)-(c&plus;di)=(a-c)&plus;(b-d)i)  
  
*Умножение комплексных чисел*  
> Умножением двух комплексных чисел ![equation](https://latex.codecogs.com/svg.image?z_1=a&plus;bi) и ![equation](https://latex.codecogs.com/svg.image?z_2=c&plus;di) будет комплексное число вида ![equation](https://latex.codecogs.com/svg.image?z=z_1*z_2=(a&plus;bi)*(c&plus;di)=(ac-bd)&plus;(ad&plus;bc)i)
  
*Деление комплексных чисел*  
> Частным двух комплексных чисел ![equation](https://latex.codecogs.com/svg.image?z_1=a&plus;bi) и ![equation](https://latex.codecogs.com/svg.image?z_2=c&plus;di) будет комплексное число вида ![equation](https://latex.codecogs.com/svg.image?z=%5Cfrac%7Bz_1%7D%7Bz_2%7D=%5Cfrac%7Ba&plus;bi%7D%7Bc&plus;di%7D=%5Cfrac%7Bac&plus;bd%7D%7Bc%5E2&plus;d%5E2%7D&plus;%5Cfrac%7Bbc-ad%7D%7Bc%5E2&plus;d%5E2%7D%20i)  
  
*Сравнение комплексных чисел*  
Сравнение двух комплексных чисел можно выполнить через расчет их *модулей* и *аргументов*.  
> *Модулем комплексного числа* z=a+bi называется выражение ![equation](https://latex.codecogs.com/svg.image?r=%7Cz%7C=%7Ca&plus;bi%7C=%5Csqrt%7Ba%5E2&plus;b%5E2%7D). Модуль комплексного числа является длиной [радиус-вектора](https://ru.wikipedia.org/wiki/%D0%A0%D0%B0%D0%B4%D0%B8%D1%83%D1%81-%D0%B2%D0%B5%D0%BA%D1%82%D0%BE%D1%80).  
  
> Угол ![variable](https://latex.codecogs.com/svg.image?\Phi) между положительным направлением действительной оси и радиус-вектора, соответствующим комплексному числу z=a+bi, называется *аргументом* этого числа.  
  
Формула для нахождения ϕ зависит от того, в какой координатной четверти лежит число z=a+bi.  
Тогда, если:  
* ![equation](https://latex.codecogs.com/svg.image?a%3E0,b%5Cgeq%200,%5CPhi%20%20=%20arctg%20(%5Cfrac%7Bb%7D%7Ba%7D))
* ![equation](https://latex.codecogs.com/svg.image?a%3C0,b%5Cgeq%200,%5CPhi%20%20=%20%5CPi%20-%20arctg%20(%7C%5Cfrac%7Bb%7D%7Ba%7D%7C))
* ![equation](https://latex.codecogs.com/svg.image?a%20%3C%200,%20b%20%3C%200,%20%5CPhi%20%20=%20%5CPi%20&plus;%20arctg%20(%7C%5Cfrac%7Bb%7D%7Ba%7D%7C))
* ![equation](https://latex.codecogs.com/svg.image?a%20%3E%200,%20b%20%3C%200,%20%5CPhi%20%20=%202%5CPi%20-%20arctg%20(%7C%5Cfrac%7Bb%7D%7Ba%7D%7C))
* ![equation](https://latex.codecogs.com/svg.image?a%20=%200,%20b%20%3E%200,%20%5CPhi%20%20=%20%5Cfrac%7B%5CPi%7D%7B2%7D)
* ![equation](https://latex.codecogs.com/svg.image?a%20=%200,%20b%20%3C%200,%20%5CPhi%20%20=%20%5Cfrac%7B3%5CPi%7D%7B2%7D)
* ![equation](https://latex.codecogs.com/svg.image?a%20=%200,%20b%20=%200,%20z%20=%200)  
  
Угол ![variable](https://latex.codecogs.com/svg.image?\Phi) выражается в радианах.  
> Таким образом, результатом сравнения двух комплексных чисел ![equation](https://latex.codecogs.com/svg.image?z_1=a&plus;bi) и ![equation](https://latex.codecogs.com/svg.image?z_2=c&plus;di) по модулю будет ![variable](https://latex.codecogs.com/svg.image?r_1) (>или<,или==)  ![variable](https://latex.codecogs.com/svg.image?r_2), а по аргументу - ![variable](https://latex.codecogs.com/svg.image?\Phi_1) (>или<,или==)  ![variable](https://latex.codecogs.com/svg.image?\Phi_2).  
  
**3. Отражение истории вычислений**  
В поле для отображения истории содержится информация о последних вычислениях (Само выражение и результат его вычисления).  

<a name="ClassDesign"><h2>Проектирование классов</h2></a>
<a name="ClassEntity"><h2>Классы-сущностей</h2></a>
* [*ComplexNumber*](https://github.com/1i10/Complex-number-calculator/tree/master/ComplexCalculator/ComplexCalculator#ClassComplexNumber). Содержит в свойствах действительную и мнимую части комплексного числа. Доступ к полям осуществляется посредством сеттеров и геттеров. Также имеется метод для конвертирования комплексного числа в строку для передачи результата управляющему классу Calculator. И, перегрузки операторов, выполняющих арифметические операции для использования в методах классов, использующие соответствующие операции (AddOperation, SubOperation, MultOperation, DivOperation);
* [*ArOperation*](https://github.com/1i10/Complex-number-calculator/tree/master/ComplexCalculator/ComplexCalculator#ClassArOperation). Базовый класс для совершения арифметической операции между двумя комплексными числами класса ComplexNumber;
* [*AddOperation*](https://github.com/1i10/Complex-number-calculator/tree/master/ComplexCalculator/ComplexCalculator#ClassAddOperation). Класс для совершения операции сложения комплексных чисел;
* [*SubOperation*](https://github.com/1i10/Complex-number-calculator/tree/master/ComplexCalculator/ComplexCalculator#ClassSubOperation). Класс для совершения операции вычитания комплексных чисел;
* [*MultOperation*](https://github.com/1i10/Complex-number-calculator/tree/master/ComplexCalculator/ComplexCalculator#ClassMultOperation). Класс для совершения операции умножения комплексных чисел;
* [*DivOperation*](https://github.com/1i10/Complex-number-calculator/tree/master/ComplexCalculator/ComplexCalculator#ClassDivOperation). Класс для совершения операции деления комплексных чисел;
* [*ComparisonOperation*](https://github.com/1i10/Complex-number-calculator/tree/master/ComplexCalculator/ComplexCalculator#ClassComparisonOperation). Класс, который формирует результат сравнения комплексных чисел по полученным результатам из своих дочерних классов [*ModulForComparison*](https://github.com/1i10/Complex-number-calculator/tree/master/ComplexCalculator/ComplexCalculator#ClassModulForComparison) и [*ArgForComparison*](https://github.com/1i10/Complex-number-calculator/tree/master/ComplexCalculator/ComplexCalculator#ClassArgForComparison).  
  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/ClassDiagrams/DiagramClassEntity.png "Диаграмма классов-сущностей")
  
Все полученные результаты вычислений будут занесены в поле Result управляющего класса Calculator. 

<a name="ControlClass"><h2>Управляющие классы</h2></a>
* [*Calculator*](https://github.com/1i10/Complex-number-calculator/tree/master/ComplexCalculator/ComplexCalculator#ClassCalculator). Пользовательский ввод попадает в поле Expression данного класса. Далее, осуществляется вытаскивание из полученной строки двух комплексных чисел и операции между ними. Полученная информация передается в другие классы для дальнейшей обработки. И, полученный результат данной обработки записывается в поле Result.  
  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/ClassDiagrams/ClassCalculator.png "Управляющий класс «Calculator»")  
  
* [*Store*](https://github.com/1i10/Complex-number-calculator/tree/master/ComplexCalculator/ComplexCalculator#ClassStore).В данный класс помещаются выражения и их результаты из класса Calculator. Полученная информация передается в диалоговое окно HistoryWindow, которое отражает историю операций.  
  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/ClassDiagrams/ClassStore.png "Управляющий класс «Store»")  
  
<a name="InterfaceClass"><h2>Интерфейсные классы</h2></a>
* [*QTCalculator*](https://github.com/1i10/Complex-number-calculator/tree/master/QTCalculator#ClassQTCalculator). Осуществляет взаимодействие с управляющим классом Calculator для передачи введенного пользователем выражения и получения его результата;
* [*HistoryWindow*](https://github.com/1i10/Complex-number-calculator/tree/master/QTCalculator#ClassHistoryWindow). Отображает список истории операции объекта класса Store;
* [*InfoWindow*](https://github.com/1i10/Complex-number-calculator/tree/master/QTCalculator#ClassInfoWindow). Отображает краткую информацию по работе в приложении.  
  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/ClassDiagrams/IntefaceClasses.png "Интерфейсные классы")  
  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/ClassDiagrams/FullDiagramClasses.png "Диаграмма классов для калькулятора комплексных чисел")

<a name="InterfaceDiscription"><h2>Описание интерфейса</h2></a>
В ходе выполнения проекта была сформирована следующая структура меню.  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/InterfaceItems/GeneralInterface.png "Интерфейс приложения «Калькулятор комплексных чисел»")  
  
*Объекты интерфейса приложения*
**Объект(ы)** | **Описание** | **Вид на форме** |
:------------ | :----------- | :--------------- |
PushButton_0, PushButton_1, PushButton_2, PushButton_3, PushButton_4, PushButton_5, PushButton_6, PushButton_7, PushButton_8, PushButton_9, PushButton_Dot, PushButton_i, PushButton_LeftBracket, PushButton_RightBracket, PushButton_Div, PushButton_Mult, PushButton_Minus, PushButton_Plus, PushButton_Compare | Кнопка, при нажатии на которую будет выводится соответствующий текстовый символ в объект InputLine (поле ввода). | ![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/InterfaceItems/Keyboard.png) |
PushButton_Del | Кнопка, при нажатии на которую будет очищаться поле ввода. | ![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/InterfaceItems/Clear.png) |
PushButton_BackSpace | Кнопка, при нажатии на которую будет удаляться последний символ из поля ввода. | ![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/InterfaceItems/Backspace.png) |
PushButton_Eq | Кнопка, при нажатии на которую происходит вычисление значения введенного выражения в поле ввода. Данная кнопка становится активной только тогда, когда в поле ввода (InputLine) будет содержаться выражение, которое является корректным. Результат вычисления будет передан в объект DisplayResult. | ![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/InterfaceItems/Equal.png) |
PushButton_History | Кнопка, при нажатии на которую открывается/закрывается окно, которое отражает историю всех последних операций. Содержит два объекта: HistoryList и Button_ClearHistory. | ![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/InterfaceItems/History.png) ![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/InterfaceItems/HistoryWindow.png) |
HistoryList | Поле, которое содержит список результатов вычисления выражений. Последний введенный результат будет отображаться на первой строчке. | ![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/InterfaceItems/HistoryList.png) |
Button_ClearHistory | Кнопка, при нажатии на которую очищается данные из объекта HistoryList. | ![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/InterfaceItems/ClearHistory.png) |
RadioButton_Modul | Радиокнопка, которая позволяет выбрать метод сравнения «по модулю» для соответствующей операции (‘?’ – сравнение). | ![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/InterfaceItems/RadioButtonModul.png) |
RadioButton_Arg | Радиокнопка, которая позволяет выбрать метод сравнения «по аргументу» для соответствующей операции (‘?’ – сравнение). | ![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/InterfaceItems/RadioButtonArgument.png) |
InputLine | Поле ввода. Пользовательский ввод может осуществляться посредством клавиатуры пк или же виртуальной клавиатуры приложения (Объекты PushButton). При неверном вводе рамка поля будет окрашиваться в красный цвет. Правило вода будет рассмотрено в разделе «Разработка тестового приложения». | ![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/InterfaceItems/InputLine.png) |
InfoIcon | Кнопка, при нажатии на которую открывается/закрывается окно, которое содержит краткую информацию по работе в программе. | ![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/InterfaceItems/InfoIcon.png) ![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/InterfaceItems/InfoWindow.png) |
DisplayResult | Поле для отображения результата вычисления выражения после нажатия на ‘=’ (Объект PushButton_Eq). Итоговое содержимое поля DisplayResult передается в объект HistoryList. | ![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/InterfaceItems/Display.png) |

<a name="Build"><h2>Сборка и настройка</h2></a>
1. Загрузить проект на локальную машину, воспользовавшись командой git clone
2. Открыть проект QTCalculator.sln в Microsoft Visual Studio
3. В обозревателе решений удалить проект ComplexCalculator, который загрузился с ошибкой <s>(Из-за моей криворукости при объединении двух проектов)</s>
4. В обозревателе решений нажать ПКМ по "Решение QTCalculator" → Добавить → Существующий проект → В папке решения перейти в каталог ComplexCalculator → Открыть ComplexCalculator.sln
5. Собрать проект ComplexCalculator в конфигурации Debug x64
6. В обозревателе решений нажать ПКМ по проекту QTCalculator и перейти в свойства → Компоновщик → Дополнительные каталоги библиотек → Указать путь до объектных файлов проекта ComplexCalculator
> Например, C:\Users\renne\Desktop\Complex-number-calculator\ComplexCalculator\ComplexCalculator\x64\Debug  
7. Собрать проект QTCalculator
8. Запустить приложение   
  
<a name="UserGuide"><h2>Руководство пользователя</h2></a>
* Ввод может осуществляться как с виртуальной клавиатуры, так и с клавиатуры пк;
* Допускается ввод целых и действительных чисел;
* Каждое комплексное число должно стоять в скобках;
* Между двумя комплексными числами должна располагаться одна из доступных операций;  
*Возможные операции:*  
* '+' - сложение;
* '-' - вычитание;
* '*' - умножение;
* '/' - деление;
* '?' - сравнение;  
Для сравнения необходимо выбрать один из вариантов: по модулю или по аргументу. Результат по аргументу (углы) указываются в радианах;
* Для активации кнопки '=' необходимо ввести корректное выражение.
> Пример корректного ввода: (1.5+3i)+(-2+2.3i)  
  

<a name="Example"><h2>Пример</h2></a>
Совершим ввод в соответствующее поле. При некорректном или частично верном вводе рамка поля становится красного цвета. Кнопка ‘=’ остается заблокированной.  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/Examples/IncorrectStringInput.png "Некорректный ввод строки")  
При правильном вводе выражения рамка перекрашивается в черный цвет, и кнопка ‘=’ становится доступной для нажатия.  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/Examples/CorrectStringInput.png "Корректный ввод строки")  
При нажатии на ‘=’ само выражение и его результат будут отображены на дисплее. Строка ввода будет очищена автоматически. Кнопка ‘=’ будет снова заблокирована.  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/Examples/ResultAdd.png "Результат сложения двух комплексных чисел")  
Теперь совершим остальные операции: ‘-‘, ‘*’, ‘/’.  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/Examples/ResultSub.png "Результат вычитания двух комплексных чисел")  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/Examples/ResultMult.png "Результат умножения двух комплексных чисел")  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/Examples/ResultDiv.png "Результат деления двух комплексных чисел")  
Пропишем выражение, при котором будет совершаться деление на ноль.  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/Examples/ResultDivOnZero.png "Результат деления на ноль")  
Теперь откроем окно с историей операций и убедимся, что все введенные ранее операции были сохранены.  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/Examples/ResultsInHistoryWindow.png "Окно с историей вычислений")  
Теперь выполним операцию сравнения по модулю.  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/Examples/CompareFromModul.png "Сравнение двух комплексных чисел по модулю")  
Закроем историю. И теперь сравним комплексные числа по аргументу.  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/Examples/CompareFromArgument.png "Сравнение двух комплексных чисел по аргументу")  
Далее, очистим историю операций.  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/Examples/ClearHistoryWindow.png "Очистка истории вычислений")  
Откроем окно с краткой информацией по программе.  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/Examples/OpenInfoWindow.png "Вывод окна с краткой информацией")  
Произведем сложение двух нулевых комплексных чисел.  
![image](https://github.com/1i10/Complex-number-calculator/blob/master/Images/Examples/ResultAddNullComplexNumbers.png "Сложение нулевых комплексных чисел")  



