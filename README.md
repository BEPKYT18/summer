| Компонент | Значение |
|-----------|----------|
| Модель ПК | HONOR Magicbook X14 |
| Процессор | Intel(R) Core(TM) i3-10110U |
| Ядра/потоки | 2 ядра / 4 потока |
| Оперативная память | 8 ГБ DDR4 |
| Накопитель | NVMe PCLe SSD 256GB |
| Версии компиляторов | GCC 6.3.0 |

| (~) ОС | Компилятор | Конфиг | Алгоритм |  N=10 (время, мс) | N=10 (память, КБ) | N=500 (время, мс) | N=500 (память, КБ) |  N=1000 (время, мс) | N=1000 (память, КБ) |  N=50000 (время, мс) | N=50000 (память, КБ) |  N=1000000 (время, мс) | N=1000000 (память, КБ) |
|--------|------------|--------|----------|-------------------|-|-|-|-|-|-|-|-|-|
| Win    | GCC        | -O0    | Bubble   |0                  |-|1|-|3|-|7388|-|-|-|
| Win    | GCC        | -O0    | Selection|0                  |-|0|-|3|-|4847|-|-|-|
| Win    | GCC        | -O0    | Insertion|0                  |-|0|-|0|-|1723|-|-|-|
| Win    | GCC        | -O0    | Quick    |0                  |-|0|-|3|-|53|-|-|-|
| Win    | GCC        | -O0    | Merge    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O0    | Heap     |0                  |-|0|-|0|-|1|-|-|-|
| Win    | GCC        | -O0    | Counting |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O0    | Radix    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O0    | Bucket   |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O0    | qsort    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O1    | Bubble   |0                  |-|0|-|2|-|2|-|-|-|
| Win    | GCC        | -O1    | Selection|0                  |-|0|-|0|-||-|-|-|
| Win    | GCC        | -O1    | Insertion|0                  |-|0|-|0|-||-|-|-|
| Win    | GCC        | -O1    | Quick    |0                  |-|0|-|0|-|6|-|-|-|
| Win    | GCC        | -O1    | Merge    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O1    | Heap     |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O1    | Counting |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O1    | Radix    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O1    | Bucket   |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O1    | qsort    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O2    | Bubble   |0                  |-|0|-|1|-|1|-|-|-|
| Win    | GCC        | -O2    | Selection|0                  |-|0|-|0|-|1|-|-|-|
| Win    | GCC        | -O2    | Insertion|0                  |-|0|-|0|-|1|-|-|-|
| Win    | GCC        | -O2    | Quick    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O2    | Merge    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O2    | Heap     |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O2    | Counting |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O2    | Radix    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O2    | Bucket   |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O2    | qsort    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O2    | Bubble   |0                  |-|0|-|1|-|1|-|-|-|
| Win    | GCC        | -O2    | Selection|0                  |-|0|-|0|-|1|-|-|-|
| Win    | GCC        | -O2    | Insertion|0                  |-|0|-|0|-|1|-|-|-|
| Win    | GCC        | -O2    | Quick    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O2    | Merge    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O2    | Heap     |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O2    | Counting |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O2    | Radix    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O2    | Bucket   |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -O2    | qsort    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -Ofast | Bubble   |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -Ofast | Selection|0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -Ofast | Insertion|0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -Ofast | Quick    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -Ofast | Merge    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -Ofast | Heap     |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -Ofast | Counting |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -Ofast | Radix    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -Ofast | Bucket   |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -Ofast | qsort    |0                  |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -march=native | Bubble   |0           |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -march=native | Selection|0           |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -march=native | Insertion|0           |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -march=native | Quick    |0           |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -march=native | Merge    |0           |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -march=native | Heap     |0           |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -march=native | Counting |0           |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -march=native | Radix    |0           |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -march=native | Bucket   |0           |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -march=native | qsort    |0           |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -flto | Bubble   |0                   |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -flto | Selection|0                   |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -flto | Insertion|0                   |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -flto | Quick    |0                   |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -flto | Merge    |0                   |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -flto | Heap     |0                   |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -flto | Counting |0                   |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -flto | Radix    |0                   |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -flto | Bucket   |0                   |-|0|-|0|-|0|-|-|-|
| Win    | GCC        | -flto | qsort    |0                   |-|0|-|0|-|0|-|-|-|



