## Задача. Частично дефинирани функции и композиция на функции

Да се реализира програма на C++ за представяне и композиране на реални функции върху една променлива (реално число).

Всички функции приемат аргумент от тип `double` и като резултат връщат `std::optional<double>`, който има стойност, ако функцията е дефинирана за подадената стойност.

Някои функции са дефинирани за всяко реално число, а други могат да бъдат недефинирани за определени стойности.

### `Function`

Реализирайте абстрактен клас `Function`.

Всеки обект от йерархията трябва да може да бъде извикан чрез синтаксис, подобен на обикновена функция:

```cpp
std::optional<double> result = func(3.5);
```

Резултатът съдържа изчислената стойност, само ако функцията е дефинирана за подадената стойност.

### `LinearFunction` - линейна функция

Представя функцията:

```text
f(x) = ax + b
```

Тя е дефинирана за всяко реално число.

Пример:

```cpp
LinearFunction f1(2, 1);

auto result = f1(3);
// result съдържа 7
```

### `QuadraticFunction` - квадратна функция

Представя функцията:

```text
f(x) = ax² + bx + c
```

Тя е дефинирана за всяко реално число.

```cpp
QuadraticFunction f2(1, 0, 0);

auto result = f2(4);
// result съдържа 16
```

### `IntervalRestrictedFunction`

Обхваща друга функция, ограничено до затворен интервал `[left, right]`.

Извън интервала функцията е недефинирана. Вътре в интервала се използва поведението на вложената функция.

При невалидно зададен интервал трябва да се хвърли подходящо изключение.

```cpp
QuadraticFunction func(1, 0, 0);

IntervalRestrictedFunction restricted(func, -2, 2);

restricted(2);  // 4
restricted(3);  // empty
```

### `PuncturedFunction`

Обхваща друга функция, която допълнително е недефинирана в зададен набор от точки.

```cpp
LinearFunction linearFunc(2, 1);

PuncturedFunction punctured(
    linearFunc, {1, 3, 5}
);

punctured(2);  // 5
punctured(3);  // empty
```

### `PiecewiseFunction`

Представя функция, дефинирана чрез две други функции и гранична точка p.

Нека `leftFunction` и `rightFunction` са две функции. Тогава:

```
f(x) = leftFunction(x),  ако x < p
f(x) е недефинирана,    ако x = p
f(x) = rightFunction(x), ако x > p
```
Функциите от двете страни на границата могат да бъдат от произволен конкретен вид, наследяващ `Function`.

`PiecewiseFunction` трябва да съхранява независими полиморфни копия на двете подадени функции. Последващи промени или унищожаване на оригиналните обекти не трябва да влияят върху нея.

Пример:
```cpp
LinearFunction left(1, 0);
// left(x) = x

QuadraticFunction right(1, 0, 0);
// right(x) = x²

PiecewiseFunction piecewise(
    left,
    right,
    3
);

piecewise(2);  // left(2) = 2
piecewise(3);  // undefined at this point
piecewise(4);  // right(4) = 16
```

Отделните функции също могат да бъдат частично дефинирани:

```cpp
LinearFunction linear(2, 1);

PuncturedFunction punctured(
    linear,
    {1, 2}
);

QuadraticFunction quadratic(1, 0, 0);

PiecewiseFunction another(
    punctured,
    quadratic,
    5
);

another(2);  // std::nullopt
another(4);  // punctured(4) = 9
another(5);  // std::nullopt
another(6);  // quadratic(6) = 36
```

### `ComposedFunction` - композиция на функции

Реализирайте клас `ComposedFunction`, който също е вид `Function` и представя композиция на произволен брой функции.

Функциите трябва да могат да се добавят последователно чрез `then()`:

```cpp
ComposedFunction composition;

composition
    .then(first)
    .then(second)
    .then(third);
```

Ако функциите са добавени в реда `f`, `g`, `h`, резултатът е:

```text
h(g(f(x)))
```

Тоест резултатът от всяка функция се подава като аргумент на следващата.

Ако някоя функция е недефинирана за получения междинен аргумент, то останалите композирани функции не се изчисляват и броим цялата композиция за недефинирана в тази точка.

Празната композиция трябва да се държи като тъждествената функция (идентитет):

```text
f(x) = x
```

Композицията трябва да позволява:

- добавяне на функция
- премахване на функция по индекс
- достъп до функция по индекс
- получаване на броя функции
- проверка дали е празна
- независимо копиране

Тъй като `ComposedFunction` също е функция, една композиция трябва да може да участва като елемент в друга композиция.

### Примерна употреба

```cpp
LinearFunction linear(1, 1);
// linear(x) = x + 1

LinearFunction leftBranch(0, 0);
// leftBranch(x) = 0

LinearFunction rightBranch(0, 10);
// rightBranch(x) = 10

PiecewiseFunction piecewise(
    leftBranch,
    rightBranch,
    3
);

QuadraticFunction quadratic(1, 0, 0);
// quadratic(x) = x²

ComposedFunction composition;

composition
    .then(linear)
    .then(piecewise)
    .then(quadratic);

auto first = composition(1);
// linear(1) = 2
// piecewise(2) = leftBranch(2) = 0
// quadratic(0) = 0

auto second = composition(2);
// linear(2) = 3
// piecewise(3) е недефинирана
// second -> std::nullopt

auto third = composition(4);
// linear(4) = 5
// piecewise(5) = rightBranch(5) = 10
// quadratic(10) = 100
```
