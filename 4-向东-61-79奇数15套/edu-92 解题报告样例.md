

# edu-92 解题报告

难度系数：$1950$

| 题号 |    题目    | 难度系数 |     备注     |
| :--: | :--------: | :------: | :----------: |
| 1    | 数组游走 | 1600 | 动态规划 |
| 2    | 好串 | 1500 | 字符串，想法 |
| 3    | 扩张线段 | 2100 | 枚举、分类讨论 |
| 4    | 二色线段 | 2600 | 二分图 |




<div STYLE="page-break-after: always;"></div> 

## 1 数组游走
难度系数-$1600$
### 解法分析 

这道题就是动态规划，但是状态比较多，如果设计的不太好的话就会和我赛场上一样设计出乱七八糟的状态转移。

我们设$f[i][j]$表示走到第$i$个点，向左走了$j$步的最大值，当然$i - 1 + 2 * j \le k$是必须要满足的，下面我们考虑转移。

$f[i][j]=\max \begin{cases}f[i - 1][j] + a[i]\\f[i][j - 1] + (a[i] + a[i + 1])&j > 0, i < n\\f[i][j - 1] + (a[i] + a[i + 1])&j > 0, i > 0\end{cases}$

其中第一行就是直接从前一个位置走过来；第二行是本来就在这个位置，然后向右走一步再向左走一步回来；第二行是本来就在这个位置，然后向左走一步再向右走一步回来。这里有的同学就要问了，这样做的话不是有可能本来就在这个位置向右走一步再向左走一步回来，再向左走一步再向右走一步回来这样就连续向左走两步了！对于这种在一个点上我们一共向左再向右$x$次，向右再向左$y$次，我们一定可以调整顺序，先向左再向右$x$次，再向右再向左$y$次，这样就不会有连续两步向左了。

这样我们就完成了这道题。


### 参考代码

```cpp
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int t, n, k, z;
long long ans = 0;
long long a[110000], f[110000][6];
int main() {
	scanf("%d%d%d", &n, &k, &z);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= z; j++) {
			f[i][j] = 0;
		}
	}
	
	ans = 0;
	
	for(int i = 1; i <= k + 1; i++) {
		for(int j = 0; j <= z; j++) {
			if((i - 1) + 2 * j > k) continue;
			f[i][j] = max(f[i][j], f[i - 1][j] + a[i]);
			if(j && i < n) f[i][j] = max(f[i][j], f[i][j - 1] + (a[i] + a[i + 1]));
			if(j && i > 0) f[i][j] = max(f[i][j], f[i][j - 1] + (a[i] + a[i + 1]));
			ans = max(ans, f[i][j]);//由于a[i][j]都是正数，走的步数越多肯定越大，不用走了k步再更新答案也可以 
		}
	}
	printf("%lld\n", ans);
	return 0;
} 
```



<div STYLE="page-break-after: always;"></div> 

## 2 好串
难度系数-$1500$
### 解法分析 

这题需要进行模型的转化。

由于字符串的左移和右移完全相同，所以我们知道我们的字符串有长度为$1$或者$2$的循环节，也就我们的字符串应该形如$AAAAAA……$或者$ABABAB……AB$，由于字符只有$10$种取值，我们直接枚举循环节取最后长度最大的作为我们最后保留答案就可以了。

假如原字符串长度为$n$,我们计算出最后长度为$1$或者$2$的循环节的子序列的最大长度为$ans$，那我们需要删掉字符的最小个数$ans' = n - ans$。这样就完成了这道题目。

### 参考代码

```cpp
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
char s[220000];
int a[2];
int t, n, now, len;
int num, ans;
int main() {
	scanf("%s", s + 1);
	len = strlen(s + 1); ans = 0;
		
	for(int i = 0; i <= 9; i++) {
		num = 0;
		for(int k = 1; k <= len; k++) {
			if(s[k] - '0' == i) num++;
		}
		ans = max(ans, num); 
	} 
	
	for(int i = 0; i <= 9; i++) {
		for(int j = 0; j <= 9; j++) {
			a[0] = i; a[1] = j; num = 0; now = 0;
			for(int k = 1; k <= len; k++) {
				if(s[k] - '0' == a[now]) {
					num++;
					now = 1 - now;
				}
			}
		}
		num = num / 2 * 2;
		ans = max(ans, num);
	}
	printf("%d\n", len - ans);
	return 0;
}
```




<div STYLE="page-break-after: always;"></div> 

## 3 扩张线段

难度系数-$2100$

### 解法分析 

这道题我们分两种情况来讨论，一种是$\left[l_{1}, r_{1}\right]$和$\left[l_{2}, r_{2}\right]$相交，一种是不相交。为了方便起见我们规定$l_1 < l_2$，我们先来看相交的情况。在相交的情况下，我们先计算当前的相交长度之和$temp = n * [(r_1 - l_1) + (r_1 - l_1) - (max(r_1, r_2) - min(l_1, l_2))]$，如果当前相交长度之和已经达到了题目要求的 $k$ ,我们就不需要操作，答案就是$0$了。如果现在的相交长度之和还达不到$k$，那我们接下来的线段拓展分为两部分进行，第一部分是通过蓝色线段向右拓展，红色线段向左拓展(如果红色线段被包含则向左向右拓展)使得两条线段区间变得一致，这一阶段我们每拓展一条线段让它变长 $1$ ,我们的相交长度之和就能变大$1$。如果这一阶段结束还不能满足，我们就要进行最后的一阶段，由于这时，全部线段区间都相同，我们想要相交长度之和就变大$1$，就需要一条蓝线往某一个方向变长 $1$ ,与之对应红线也往这个方向变长 $1$ ,一次操作总共需要代价 $2$。经过若干次后我们就一定能到达 $k$ 的限制。

接着是两条线段不相交的情况，这种情况比较有意思。我们先要枚举在最后有多少对线段会相交，我们就只去拓展这些对线段。假如我们现在枚举到到最后有 $i$ 对线段会相交，首先我们先让 $i$ t条蓝线向右拓展使其与对应的 $i$ 条红线刚好相交，代价就是 $i * (l_2 - r_1)$，接着我们就回归线段相交的情况了，用这 $i$ 对线段跑上面提到的相交情况得到一个答案 $now$ 去更新最终答案 $ans$。

这样我们就完成了这道题。

### 参考代码

```cpp
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int n, k, t, kk;
long long la, ra, lb, rb;
long long ans, temp, s, now;

int main() {
	scanf("%d%d", &n, &k);
	scanf("%lld%lld%lld%lld", &la, &ra, &lb, &rb);
	if(la > lb) {
		swap(la, lb);
		swap(ra, rb);
	} 
	ans = 0;
		
	if(ra >= lb) {
		temp = (ra - la) + (rb - lb) - (max(ra, rb) - min(la, lb));
		if(temp * n >= k) ans = 0;
		else {
			k -= temp * n;
			temp = (max(ra, rb) - min(la, lb)) - temp;
			if(k <= temp * n) ans += k;
			else {
				ans += temp * n;
				k -= temp * n;
				ans += 2 * k;
			}
		}
	}
	else {
		ans = 1e18; 
		for(int i = 1; i <= n; i++) {
			now = (lb - ra) * i; kk = k;
			temp = rb - la;
			if(kk <= temp * i) now += kk;
			else {
				now += temp * i;
				kk -= temp * i;
				now += 2 * kk;
			}
			ans = min(now, ans);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
```




<div STYLE="page-break-after: always;"></div> 

## 4 二色线段

难度系数-$2600$

### 解法分析 

题目给了我们黑白两种线段，我们把它们变成点，黑色的点放左边白色的点放右边，然后能产生不好的黑白线段对连一条边，这样我们就得到了一张二分图，我们的题目就是要求一个最大的独立集。

然后根据图论知识我们知道，`最大独立集 = 点数 - 最大匹配`，要求解最大独立集本质上就是要去求最大匹配，这时我们一看数据范围$n ~ (1 \le n \le 2 \cdot 10 ^ 5)$，不要说跑匈牙利了光建图时间就受不住了。所以我们需要挖掘一下这个二分图的性质。

我们首先先按每个线段的右端点为第一关键字排序，搞两个 multiset ，一个记录白线段，一个记录黑线段，用来记录我们选择了哪些区间。我们要求的是最大匹配，不失一般性我们考虑现在插入一条白色的线段，如果我们在黑色的 multiset 中，不存在与我们现在考虑的这个线段形成“不好线段对”的线段的话，我们就直接把这个白色线段的右端点加入到白色的 multiset 中，代表展示没有匹配。反之假若存在与我们现在考虑的这个白色线段形成“不好线段”的线段的话，我们就选择这两个点之间的这条边作为最大匹配中的一条边，然后再黑色multiset 中把那个黑色线段所代表的点给抹掉，并且现在的这个区间也不加入到白色 multiset 中，因为我们这两个点已经完成匹配了，不能再出现在最大匹配的边里了，这是最大匹配的定义要求的。下面我们考虑，如果我们的这条白色线段能与多条黑色线段匹配的话，我们应该匹配哪条呢？这很简单，贪心的想我们应该匹配右端点最小的那个，也就是右端点大于等于白色线段左端点的第一条黑色线段。这是因为我们尽可能消耗右端点小的线段，才能把更多右端点大的也就是更有机会在之后匹配的线段留给后面，这样才能产生最大匹配！对于插入黑色线段也同理。

### 参考代码

```cpp
#include <cmath>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
struct node {
	int l, r, color;
	//color = 1 -> white
	//color = 2 -> black
}a[220000];
int n, num, ans;

multiset<int>white, black;
bool comp(node x, node y) {
	if(x.r < y.r) return(true);
	if(x.r == y.r && x.l < y.l) return(true);
	return(false);
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].color);
	sort(a + 1, a + n + 1, comp);
	
	num = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i].color == 1) {
			multiset<int>::iterator it = black.lower_bound(a[i].l);
			if(it != black.end()) {
				num++;
				black.erase(it);
			}
			else white.insert(a[i].r);
		}
		else {
			multiset<int>::iterator it = white.lower_bound(a[i].l);
			if(it != white.end()) {
				num++;
				white.erase(it);
			}
			else black.insert(a[i].r);
		}	
	}
	ans = n - num;
	printf("%d", ans);
	return 0;
} 
```