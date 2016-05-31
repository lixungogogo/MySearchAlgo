实现二分查找

1.mid值的求解

mid = (left + right)/2;
//如果left和right足够大，可能会导致溢出，所以这样算mid值是有风险的
