# Block 3. Data Structures
## [1067. Disk Tree](https://acm.timus.ru/problem.aspx?space=1&num=1067&locale=en)

#### Explanation (in Russian):
Простая реализация дерева (структура с именем и мапой для хранения детей)ю
Вывод - обход в глубину.


## [1494. Monobilliards](https://acm.timus.ru/problem.aspx?space=1&num=1494&locale=en)

#### Explanation (in Russian):
Воспользуясь стеком, буду класть шары в лунку (стек), как это делал Чичиков - на вершине всегда будет последний забитый шар.
* если данный шар больше top на 1, то все хорошо, ревизор проверил его в предыдущий и в этот раз.
* если данный шар больше top на 2 и больше, то тоже все хорошо, просто ревизор не проверял какое-то время лунку. Тогда дополню лунку шарами от предыдущего проверенного, до текущего (не включительно)
* если данный шар меньше или равен, то проверим, является ли шар тем, который мы ожидаем в стеке, который сохранили в предыдущем пункте, или нет. Если не соответствует: Чичиков - жулик. 

Асимптотика: O(n)

## [1521. War Games 2](https://acm.timus.ru/problem.aspx?space=1&num=1521&locale=en)

#### Explanation (in Russian):


## [1628. White Streaks](https://acm.timus.ru/problem.aspx?space=1&num=1628&locale=en)

#### Explanation (in Russian):


## [1650. Billionaires](https://acm.timus.ru/problem.aspx?space=1&num=1650&locale=en)

#### Explanation (in Russian):


