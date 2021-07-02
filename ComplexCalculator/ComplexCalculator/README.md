## Реализация классов  
Ниже будут представлены описания классов (их свойств и методов).  
  
<a name="ClassComplexNumber"><h5>Класс: ComplexNumber</h5></a>
*Свойства:*  
* (-) double RealPart – действительная часть комплексного числа;
* (-) double ImaginaryPart – мнимая часть комплексного числа.  

*Методы:*  
* (+) ComplexNumber() – конструктор по умолчанию. Устанавливает значения свойств как ноль;
* (+) ComplexNumber(double Part1, double Part2) – конструктор с параметрами. Присваивает свойствам значения параметров. Используется в методах для перегрузок операторов;
* (+) double GetRealPart() – возвращает действительную часть объекта комплексного числа;
* (+) double GetImaginaryPart() – возвращает мнимую часть объекта комплексного числа;
* (+) void SetRealPart(double Part1) – устанавливает действительную часть объекту комплексного числа;
* (+) void SetImaginaryPart(double Part2) – устанавливает мнимую часть объекту комплексного числа;
* (+) string ConvertComplexNumberToString() – конвертер объекта класса (комплексного числа) в строковую переменную;
* (+) ComplexNumber operator+(const ComplexNumber Num) – перегрузка оператора ‘+’ для сложения комплексных чисел;
* (+) ComplexNumber operator-(const ComplexNumber Num) - перегрузка оператора ‘-’ для вычитания комплексных чисел;
* (+) ComplexNumber operator*(const ComplexNumber Num) - перегрузка оператора ‘*’ для умножения комплексных чисел;
* (+) ComplexNumber operator/(const ComplexNumber Num) - перегрузка оператора ‘/’ для деления комплексных чисел.  
  
<a name="ClassArOperation"><h5>Класс: ArOperation</h5></a>
*Свойства:*  
* (#) ComplexNumber Num1 – комплексное число №1;
* (#) ComplexNumber Num2 – комплексное число №2.  
  
*Методы:*  
* (+) void SetNum1(ComplexNumber Num) – устанавливает комплексное число 1 для левого операнда выражения;
* (+) void SetNum1(ComplexNumber Num) – устанавливает комплексное число 2 для правого операнда выражения.  
  
<a name="ClassAddOperation"><h5>Класс: AddOperation</h5></a>
*Родительский класс:* (+) [ArOperation](#ClassArOperation)  
*Методы:*  
* (+) ComplexNumber AddResult() – выполняет сложение двух комплексных чисел. Возвращает результирующее комплексное число.  
  
<a name="ClassSubOperation"><h5>Класс: SubOperation</h5></a>
*Родительский класс:* (+) [ArOperation](#ClassArOperation)  
*Методы:*  
* (+) ComplexNumber SubResult() – выполняет вычитание двух комплексных чисел. Возвращает результирующее комплексное число.  
  
<a name="ClassMultOperation"><h5>Класс: MultOperation</h5></a>
*Родительский класс:* (+) [ArOperation](#ClassArOperation)  
*Методы:*  
* (+) ComplexNumber MultResult() – выполняет умножение двух комплексных чисел. Возвращает результирующее комплексное число.  
  
<a name="ClassDivOperation"><h5>Класс: DivOperation</h5></a>
*Родительский класс:* (+) [ArOperation](#ClassArOperation)  
*Методы:*  
* (+) ComplexNumber DivResult() – выполняет деление двух комплексных чисел. Возвращает результирующее комплексное число.  
  
<a name="ClassComparisonOperation"><h5>Класс: ComparisonOperation</h5></a>
*Родительский класс:* (+) [ArOperation](#ClassArOperation)  
*Методы:*  
* (+) string ComparisonResult(double ResultNum1, double Result Num2) – возвращает строковый результат сравнения двух чисел (>, < или ==). Если конкретно, употребляя для данной работы, то результаты сравнения модулей или аргументов комплексных чисел.  
  
<a name="ClassModulForComparison"><h5>Класс: ModulForComparison</h5></a>
*Родительский класс:* (+) [ComparisonOperation](#ClassComparisonOperation)  
*Методы:*  
* (+) double GetModul(ComplexNumber Num) – вычисляет и возвращает модуль комплексного числа.  
  
<a name="ClassArgForComparison"><h5>Класс: ArgForComparison</h5></a>
*Родительский класс:* (+) [ComparisonOperation](#ClassComparisonOperation)  
Методы:  
* (+) double GetArg(ComplexNumber Num) – вычисляет и возвращает аргумент комплексного числа.  
  
<a name="ClassCalculator"><h5>Класс: Calculator</h5></a>
*Свойства:*  
* (-) string Result – результат выполнения арифметической операции между комплексными числами;
* (-) string Expression – содержит строку из двух комплексных чисел и операцию между ними.  
  
*Методы:*  
* (+) Calculator() – конструктор по умолчанию. Устанавливает значения Result = “0”, Expression = “???”;
* (+) void SetResult(string Res) – устанавливает значение Result;
* (+) void SetExpression(string Expr) – устанавливает значение Expression;
* (+) string GetResult() – возвращает значение Result;
* (+) string GetExpression() – возвращает значение Expression;
* (+) char GetOperationFromExpression() – возвращает операцию между двумя комплексными числами из поля Expression. Метод заключается в поиске первой скобки ‘)’ и, тогда следующий символ будет являться искомой операцией;
* (+) vector<ComplexNumber> GetComplexNumbersFromExpression() – вытаскивает два комплексных числа из строки Expression и возвращает вектор полученных данных.  
  
<a name="ClassStore"><h5>Класс: Store</h5></a>
*Свойства:*   
* (-) list<Calculator> ResultTable – включает в себя список из данных класса Calculator (Выражения и их результат);  
*Методы:*  
* (+) Store() – конструктор по умолчанию. Содержит в себе стартовое значение класса Calculator;
* (+) list<Calculator> GetResultTable() – возвращает список из выражений и их результатов;
* (+) void AddInTable(Calculator Note) – добавляет полученное выражение и его результат в хранилище. Добавление осуществляется в начало через метод this->ResultTable.push_front(Note);
* (+) void ClearTable() – осуществляет удаление всех данных из таблицы через метод this->ResultTable.clear().  
  

  














