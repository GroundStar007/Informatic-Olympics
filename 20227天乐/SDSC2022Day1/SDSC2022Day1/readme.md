# A
## Read Time

### 题面翻译

题意：给你 $n$ 个探头，$m$ 个要读的轨道，$n$ 个探头的初始位置是 $h_1,h_2,\cdots h_n$（从小到大），$m$ 个轨道的位置为 $p_1,p_2,\cdots p_n$（也是从小到大），探头可以左移或右移，这些探头可以一起动，每移动一格的时间为 $1$，探头读轨道不计时间，如果要读的轨道上就有探头那么就不需要时间，找最小的时间来读完这些轨道。

### 题目描述

Mad scientist Mike does not use slow hard disks. His modification of a hard drive has not one, but $ n $ different heads that can read data in parallel.

When viewed from the side, Mike's hard drive is an endless array of tracks. The tracks of the array are numbered from left to right with integers, starting with 1. In the initial state the $ i $ -th reading head is above the track number $ h_{i} $ . For each of the reading heads, the hard drive's firmware can move the head exactly one track to the right or to the left, or leave it on the current track. During the operation each head's movement does not affect the movement of the other heads: the heads can change their relative order; there can be multiple reading heads above any of the tracks. A track is considered read if at least one head has visited this track. In particular, all of the tracks numbered $ h_{1} $ , $ h_{2} $ , $ ... $ , $ h_{n} $ have been read at the beginning of the operation.

 ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF343C/477411d635199d18d36c6b93ba130f0f6f88e682.png)Mike needs to read the data on $ m $ distinct tracks with numbers $ p_{1} $ , $ p_{2} $ , $ ... $ , $ p_{m} $ . Determine the minimum time the hard drive firmware needs to move the heads and read all the given tracks. Note that an arbitrary number of other tracks can also be read.

### 输入格式

The first line of the input contains two space-separated integers $ n $ , $ m $ ( $ 1<=n,m<=10^{5} $ ) — the number of disk heads and the number of tracks to read, accordingly. The second line contains $ n $ distinct integers $ h_{i} $ in ascending order ( $ 1<=h_{i}<=10^{10} $ , $ h_{i}&lt;h_{i+1} $ ) — the initial positions of the heads. The third line contains $ m $ distinct integers $ p_{i} $ in ascending order ( $ 1<=p_{i}<=10^{10} $ , $ p_{i}&lt;p_{i+1} $ ) - the numbers of tracks to read.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is recommended to use the cin, cout streams or the %I64d specifier.

### 输出格式

Print a single number — the minimum time required, in seconds, to read all the needed tracks.

### 样例 #1

#### 样例输入 #1

```
3 4
2 5 6
1 3 6 8
```

#### 样例输出 #1

```
2
```

### 样例 #2

#### 样例输入 #2

```
3 3
1 2 3
1 2 3
```

#### 样例输出 #2

```
0
```

### 样例 #3

#### 样例输入 #3

```
1 2
165
142 200
```

#### 样例输出 #3

```
81
```

### 提示

The first test coincides with the figure. In this case the given tracks can be read in 2 seconds in the following way:

1. during the first second move the 1-st head to the left and let it stay there;
2. move the second head to the left twice;
3. move the third head to the right twice (note that the 6-th track has already been read at the beginning).

One cannot read the tracks in 1 second as the 3-rd head is at distance 2 from the 8-th track.