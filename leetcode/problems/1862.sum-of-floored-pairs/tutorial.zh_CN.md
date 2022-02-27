我们要求：

$$
\sum_{i = 1}^n\sum_{j = 1}^n \lfloor \frac{nums_i}{nums_j} \rfloor
$$

其中，$1 \leq n, nums_i \leq 10^5$。

??? warning "复杂度不对的做法"
    - 考虑枚举 $1 \leq i \leq 10^n$，然后数论分块求和。
    - 时间复杂度 $\mathcal{O}(n\sqrt{n})$

我们考虑 $d = \lfloor \frac{x}{y} \rfloor$，那么我们枚举 $y$ 和 $d$，符合条件的 $x$ 的范围为：

$$
d \cdot y \leq x \lt (d + 1) \cdot y
$$

形式化的表达：

$$
ans = \sum_{y = 1}^{C}\sum_{d = 1}^{\lfloor \frac{C}{y} \rfloor } d \cdot cnt_y \cdot (sum_{[d \cdot y \cdots (d + 1) \cdot y)})
$$

所以时间复杂度是调和级数，为 $\mathcal{O}(n\log_n)$。
