import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
from io import StringIO
import re

# ====================== ДАННЫЕ ======================
md = """
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
"""

# ====================== ПАРСИНГ ======================
def parse_md(md_text: str) -> pd.DataFrame:
    columns = [
        'OS', 'Compiler', 'Config', 'Algorithm',
        'N10_time', 'N10_mem', 'N500_time', 'N500_mem',
        'N1000_time', 'N1000_mem', 'N50000_time', 'N50000_mem',
        'N1M_time', 'N1M_mem'
    ]
    
    rows = []
    for line in md_text.strip().splitlines():
        line = line.strip()
        if not line or re.match(r'^\|[-:| ]+\|$', line) or 'Алгоритм' in line:
            continue
        if line.startswith('|'):
            line = line[1:]
        if line.endswith('|'):
            line = line[:-1]
        parts = [p.strip() for p in line.split('|')]
        if len(parts) >= 4:
            rows.append(parts[:len(columns)])
    
    df = pd.DataFrame(rows, columns=columns[:len(rows[0])] if rows else columns)
    
    # Дополняем недостающие столбцы
    for col in columns:
        if col not in df.columns:
            df[col] = np.nan
    
    df = df[columns]
    df = df.replace(['-', '', '||', 'nan', 'None'], np.nan)
    
    for col in df.columns:
        if 'time' in col or 'mem' in col:
            df[col] = pd.to_numeric(df[col], errors='coerce')
    
    df = df.drop_duplicates(subset=['Config', 'Algorithm'], keep='first')
    return df

df = parse_md(md)

# Приводим к длинному формату (удобно для графиков)
time_cols = {
    'N10_time': 10,
    'N500_time': 500,
    'N1000_time': 1000,
    'N50000_time': 50000,
    'N1M_time': 1000000
}

long_df = df.melt(
    id_vars=['Config', 'Algorithm'],
    value_vars=list(time_cols.keys()),
    var_name='N_col',
    value_name='Time'
)
long_df['N'] = long_df['N_col'].map(time_cols)
long_df = long_df.dropna(subset=['Time'])

# ====================== ГРАФИКИ ======================
sns.set_theme(style="whitegrid", font_scale=1.15)
configs = df['Config'].unique()

# -------------------------------------------------------
# 1. Зависимость времени от N (отдельный график на каждый конфиг)
# -------------------------------------------------------
for cfg in configs:
    data = long_df[long_df['Config'] == cfg]
    if data.empty:
        continue
    
    plt.figure(figsize=(11, 6))
    
    for alg in data['Algorithm'].unique():
        subset = data[data['Algorithm'] == alg].sort_values('N')
        # Чтобы логарифм не ломался на нулях
        y = subset['Time'].replace(0, 0.05)
        plt.plot(subset['N'], y, marker='o', linewidth=2.2, label=alg)
    
    plt.xscale('log')
    plt.yscale('log')
    plt.title(f'Время сортировки vs размер массива\nКонфиг: {cfg}', fontsize=15)
    plt.xlabel('Количество элементов (N)')
    plt.ylabel('Время, мс')
    plt.legend(bbox_to_anchor=(1.02, 1), loc='upper left', fontsize=9)
    plt.grid(True, which='both', ls='--', alpha=0.4)
    plt.tight_layout()
    plt.show()

# -------------------------------------------------------
# 2. Зависимость времени от конфига (для разных N)
# -------------------------------------------------------
interesting_N = [1000, 50000]  # самые показательные

for n in interesting_N:
    data = long_df[long_df['N'] == n]
    if data.empty:
        continue
    
    plt.figure(figsize=(13, 6))
    sns.barplot(
        data=data,
        x='Algorithm',
        y='Time',
        hue='Config',
        palette='tab10'
    )
    plt.title(f'Время сортировки при N = {n:,}', fontsize=15)
    plt.ylabel('Время, мс')
    plt.xlabel('')
    plt.xticks(rotation=40, ha='right')
    plt.legend(title='Конфиг', bbox_to_anchor=(1.02, 1), loc='upper left')
    plt.tight_layout()
    plt.show()

# -------------------------------------------------------
# 3. Дополнительно: все конфиги на одном графике (N=50000)
# -------------------------------------------------------
data = long_df[long_df['N'] == 50000]
if not data.empty:
    plt.figure(figsize=(12, 6))
    sns.barplot(data=data, x='Config', y='Time', hue='Algorithm', palette='deep')
    plt.title('Время при N = 50 000 — все сортировки и конфиги', fontsize=15)
    plt.ylabel('Время, мс')
    plt.xlabel('Конфигурация компилятора')
    plt.xticks(rotation=25, ha='right')
    plt.legend(bbox_to_anchor=(1.02, 1), loc='upper left', fontsize=9)
    plt.tight_layout()
    plt.show()