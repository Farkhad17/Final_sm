# Метод стрельбы

Задача изначально имеет вид:

$$
\begin{equation*}
 \begin{cases}
   \frac{d^2y}{dx^2} + sin(x)\frac{dy}{dx} + x^2y + x^2 = 0
   \\
   0 \leq x \leq 1,
   \\
   y(0) = 2,
   \\
   y(1) = 1.
 \end{cases}
\end{equation*}
$$

делаем замену $z' = y$. Получаем краевую задачу вида:

$$
\begin{equation*}
 \begin{cases}
   z' + sin(x)z + x^2y + x^2 = 0
   \\
   0 \leq x \leq 1,
   \\
   y(0) = 2,
   \\
   y(1) = 1.
 \end{cases}
\end{equation*}
$$

Решаем эту краевую задачу для z(0) = $\xi$. Вместо $\xi$ подставялем точки из отрезка(границы отрезка с разбиением на его на точки мы задаем во входных данных). Сравниваем погрешности для всех $\xi$ и выбираем из них тот, при котором получаем наименьшую погрешность.
