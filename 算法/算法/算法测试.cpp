#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<ctime>
#include<queue>
#include<stack>
#include<string>

using namespace std;
void Print(int v)
{
	cout << v << " ";
}
//分糖果问题：

//一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
//个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所
//有孩子至少要有一个糖果。求解最少需要多少个糖果
//思考:
//对于某个孩子，先仅考虑左边孩子的糖果数量与自身对比满足要求
//再考虑右边孩子的糖果数量与自身对比满足要求
//即，只考虑更新一侧的大小关系
size_t candy(vector<int>& v)
{
  
	size_t size = v.size();
  if(size <2)
  {
		return size;
	}
	vector<int> num(size, 1);//每个孩子需要的糖果
	for (int i = 0;i < size - 1;i++)
	{
		if (v[i] < v[i + 1])
		{
			num[i + 1] = num[i] + 1;
		}
	}
	for (size_t i = size - 1;i > 0;i--)
	{
		if (v[i] < v[i - 1])
		{
			num[i - 1] = num[i] + 1;
		}
	}
	return accumulate(num.begin(), num.end(), 0);
}
void candy_test()
{
	vector<int> v;
	for (int i = 0; i < 5;i++)
	{
		v.push_back(rand() % 10+1);
	}
	for_each(v.begin(), v.end(), Print);
	cout <<"\n"<< candy(v) << endl;
}

//广度优先测试
template <size_t rows, size_t cols>
int static friend_test(int (&a)[rows][cols]) {
	vector<bool> visited( rows ,false );
	queue<int> q;
	int times = 0;
	for (int i = 0;i < rows;i++) {
		if (!visited[i]) {
			visited[i] = true;
			q.push(i);
			while (!q.empty()) {
				int k = q.front();
				q.pop();
				for (int j = 0; j < cols; j++) {
					if (a[k][j] == 1 && !visited[j]) {
						visited[j] = true;
						q.push(j);
					}
				}
			}
			times++;
		}
	}
	return times;

}

//最优选择问题
static int maxScore(int a[], int l, int r) {
	//递归
	/*if (l == r) {
		return a[l];
	}
	else if (r - l <= 1) {
		return max(a[l], a[r]);
	}
	else if (l > r) {
		return 0;
	}
	int leftmath = 0, rightmath = 0;
	leftmath = a[l] + min(maxScore(a, l + 2, r), maxScore(a, l + 1, r - 1));
	rightmath = a[r] + min(maxScore(a, l + 1, r-1), maxScore(a, l, r - 2));
	return max(leftmath, rightmath);*/

	//动态规划
	vector<vector<int>> dp(r+1,vector<int>(r+1,0));
	for (int i = 0;i <= r;i++) {
		dp[i][i] = a[i];
	}
	for (int j = 1; j <= r;j++) {
		for (int i = j-1; i >= 0;i--) {
			if (j - i == 1) {
				dp[i][j] = max(a[i], a[j]);
			}
			else {
				dp[i][j] = max(a[i] + min(dp[i + 2][j], dp[i + 1][j-1]),
							   a[j] + min(dp[i+1][j-1], dp[i][j-2]));
			}
		}
	}
	return dp[0][r];
}

//KMP字符串搜索
static void getnext(int* pattern, int* next, int m) {
	int i = 0, j = -1;
	next[0] = -1;
	while (i < m - 1) {
		if (j == -1 || pattern[i] == pattern[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}

static int search_KMP(int args[], int length1, int pattern[], int length2) {
	if (length1 < length2 || length1 == 0) {
		return -1;
	}
	int* next = (int*)malloc(length2 * sizeof(int));
	getnext(pattern, next, length2);
	int i = 0, j = 0;
	while (i < length1 && j < length2) {
		if (j == -1 || args[i] == pattern[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j == length2)
		return i - j;  // 返回模式在原数组中的起始下标
	return -1;        // 没有匹配成功返回 -1
}
//KMP测试
void test_kmp() {
	// 测试案例1：简单匹配
	int args1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int pattern1[] = { 4, 5, 6 };
	int idx1 = search_KMP(args1, sizeof(args1) / sizeof(args1[0]),
		pattern1, sizeof(pattern1) / sizeof(pattern1[0]));
	// 预期匹配起始下标为 3（下标从 0 开始）
	printf("测试案例1：匹配下标为 %d\n", idx1);

	// 测试案例2：模式在序列前端匹配
	int args2[] = { 1, 2, 1, 2, 1, 2, 1, 2, 1 };
	int pattern2[] = { 1, 2, 1, 2, 1 };
	int idx2 = search_KMP(args2, sizeof(args2) / sizeof(args2[0]),
		pattern2, sizeof(pattern2) / sizeof(pattern2[0]));
	// 预期匹配下标为 0
	printf("测试案例2：匹配下标为 %d\n", idx2);

	// 测试案例3：匹配失败，返回 -1
	int args3[] = { 1, 2, 3, 4, 5 };
	int pattern3[] = { 2, 4 };
	int idx3 = search_KMP(args3, sizeof(args3) / sizeof(args3[0]),
		pattern3, sizeof(pattern3) / sizeof(pattern3[0]));
	// 预期没有匹配成功，应返回 -1
	printf("测试案例3：匹配下标为 %d\n", idx3);
	// 测试案例4：复杂重复案例
	// 原始数组中包含多个重复子序列，模式本身具有重复结构，匹配成功的位置位于数组的中间部分
	// 原始数组说明：
	// 前面有一些干扰数据 {10, 20, 30}，接下来连续 12 个数字构成重复结构，
	// 最后紧跟一些尾部数据 {40, 50}。
	// 模式就是这 12 个重复结构数字，预期应从下标 3 开始匹配成功。
	int args4[] = { 1, 2, 3,
				   1, 2, 1, 2, 1, 2, 3, 1, 2, 1, 2, 3,
				   4, 5 };
	int pattern4[] = { 1, 2, 1, 2, 1, 2, 3, 1, 2, 1, 2, 3 };
	int idx4 = search_KMP(args4, sizeof(args4) / sizeof(args4[0]),
		pattern4, sizeof(pattern4) / sizeof(pattern4[0]));
	// 预期匹配起始下标为 3
	printf("测试案例4：匹配下标为 %d\n", idx4);
}

//字符串解码(394)
static string decodestring_394_useStack(string s) {
	stack<int> nums;
	stack<string>reStack;
	string res = "";
	int index = 0 ,num = 0;
	
	while(index < s.length()) {
		if(isdigit(s[index])){
			num = 10 * num + (s[index++] - '0');
		}
		else if (s[index] == '[') {
			reStack.push(res);
			nums.push(num);
			num = 0;
			res = "";
			index++;
		}
		else if (s[index] == ']') {
			int counts = nums.top();nums.pop();
			string temp = "";
			for (int i = 0;i < counts;i++) {
				temp += res;
			}
			res = reStack.top() + temp;
			reStack.pop();
			index++;
		}
		else {
			res += s[index++];
		}
	}
	return res;
}
int main()
{
	//广度优先：
	/*int a[4][4] = {
	{1, 1, 0, 0},
	{1, 1, 1, 0},
	{0, 1, 1, 1},
	{0, 0, 1, 1}
	};
	int b = friend_test(a);
	cout << b << endl;*/
	//随机种子
	srand((unsigned int)time(NULL));
	//糖果问题测试
	//Candy_test();

	//最优选择问题测试
	/*int a[] = { 5,200,2,3 };
	int l = 0;
	int r = sizeof(a) / sizeof(a[0]) - 1;
	int b = maxScore(a, l, r);
	cout << b << endl;*/

	//KMP字符串选择测试
	test_kmp();

	system("pause");
	return 0;
}
