实现二分查找

1.mid值的求解

mid = (left + right)/2;
//如果left和right足够大，可能会导致溢出，所以这样算mid值是有风险的

2.左右区间的选择

a.半开半闭区间

初始值：

left = 0；

right = size；

b.闭区间

初始值：

left = 0；

right = size - 1；

3.left = mid +1;

right = mid - 1;//闭区间

right = mid;//半开半闭
