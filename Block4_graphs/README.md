# Block 4. Graphs
## [1080. Map Coloring](https://acm.timus.ru/problem.aspx?space=1&num=1080&locale=en)

#### Explanation (in Russian):

Решение - обход графа в ширину:
* Первую вершину красим в нулевой цвет, соседей в единичный, и так чередуем.
* Если вершина уже покрашена, и цвет равен цвету соседа, то граф недвудольный, и его нельзя раскрасить два цвета (печатаем `-1` и выходим)
* Повторяем, пока все вершины не окажутся окрашенными (так как граф может иметь не 1 компоненту связанности - это надо учесть).

Сложность: `O(n+m)`.

## [1160. Network](https://acm.timus.ru/problem.aspx?space=1&num=1160&locale=en)
  
#### Explanation (in Russian):
  
  
  
## [1162. Currency Exchange](https://acm.timus.ru/problem.aspx?space=1&num=1162&locale=en)

#### Explanation (in Russian):



## [1450. Russian Pipelines](https://acm.timus.ru/problem.aspx?space=1&num=1450&locale=en)

#### Explanation (in Russian):
Решение с использованием алгоритма Форда-Беллмана, в котором ищется максимальный (в оригинальном алгоритме - минимальный) путь от данной вершины ко всем.

* `distance` - максимальная цена газопроводности на текущую итерацию
* на каждой итерации будем рассматривать всевозможные пути из каждой посещенной вершины. Если находим новое максимальное значение, то обновляем.
* и так, пока цены изменяются

В итоге, `distance` хранит максимальные расстояния от `start` до всех, если расстояние равно `-inf`, то пути не существует.


## [1806. Mobile Telegraphs](https://acm.timus.ru/problem.aspx?space=1&num=1806&locale=en)

#### Explanation (in Russian):


