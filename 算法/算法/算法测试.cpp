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
//���ǹ����⣺

//һȺ����վ��һ�ţ�ÿһ���������Լ������֡�������Ҫ����Щ���ӷ��ǹ������������һ
//�����ӵ����ֱ��Լ����Ե�һ������Ҫ�ߣ���ô������Ӿͱ���õ������Ժ��Ӹ�����ǹ�����
//�к�������Ҫ��һ���ǹ������������Ҫ���ٸ��ǹ�
//˼��:
//����ĳ�����ӣ��Ƚ�������ߺ��ӵ��ǹ�����������Ա�����Ҫ��
//�ٿ����ұߺ��ӵ��ǹ�����������Ա�����Ҫ��
//����ֻ���Ǹ���һ��Ĵ�С��ϵ
size_t candy(vector<int>& v)
{
  
	size_t size = v.size();
  if(size <2)
  {
		return size;
	}
	vector<int> num(size, 1);//ÿ��������Ҫ���ǹ�
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

//������Ȳ���
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

//����ѡ������
static int maxScore(int a[], int l, int r) {
	//�ݹ�
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

	//��̬�滮
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

//KMP�ַ�������
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
		return i - j;  // ����ģʽ��ԭ�����е���ʼ�±�
	return -1;        // û��ƥ��ɹ����� -1
}
//KMP����
void test_kmp() {
	// ���԰���1����ƥ��
	int args1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int pattern1[] = { 4, 5, 6 };
	int idx1 = search_KMP(args1, sizeof(args1) / sizeof(args1[0]),
		pattern1, sizeof(pattern1) / sizeof(pattern1[0]));
	// Ԥ��ƥ����ʼ�±�Ϊ 3���±�� 0 ��ʼ��
	printf("���԰���1��ƥ���±�Ϊ %d\n", idx1);

	// ���԰���2��ģʽ������ǰ��ƥ��
	int args2[] = { 1, 2, 1, 2, 1, 2, 1, 2, 1 };
	int pattern2[] = { 1, 2, 1, 2, 1 };
	int idx2 = search_KMP(args2, sizeof(args2) / sizeof(args2[0]),
		pattern2, sizeof(pattern2) / sizeof(pattern2[0]));
	// Ԥ��ƥ���±�Ϊ 0
	printf("���԰���2��ƥ���±�Ϊ %d\n", idx2);

	// ���԰���3��ƥ��ʧ�ܣ����� -1
	int args3[] = { 1, 2, 3, 4, 5 };
	int pattern3[] = { 2, 4 };
	int idx3 = search_KMP(args3, sizeof(args3) / sizeof(args3[0]),
		pattern3, sizeof(pattern3) / sizeof(pattern3[0]));
	// Ԥ��û��ƥ��ɹ���Ӧ���� -1
	printf("���԰���3��ƥ���±�Ϊ %d\n", idx3);
	// ���԰���4�������ظ�����
	// ԭʼ�����а�������ظ������У�ģʽ��������ظ��ṹ��ƥ��ɹ���λ��λ��������м䲿��
	// ԭʼ����˵����
	// ǰ����һЩ�������� {10, 20, 30}������������ 12 �����ֹ����ظ��ṹ��
	// ������һЩβ������ {40, 50}��
	// ģʽ������ 12 ���ظ��ṹ���֣�Ԥ��Ӧ���±� 3 ��ʼƥ��ɹ���
	int args4[] = { 1, 2, 3,
				   1, 2, 1, 2, 1, 2, 3, 1, 2, 1, 2, 3,
				   4, 5 };
	int pattern4[] = { 1, 2, 1, 2, 1, 2, 3, 1, 2, 1, 2, 3 };
	int idx4 = search_KMP(args4, sizeof(args4) / sizeof(args4[0]),
		pattern4, sizeof(pattern4) / sizeof(pattern4[0]));
	// Ԥ��ƥ����ʼ�±�Ϊ 3
	printf("���԰���4��ƥ���±�Ϊ %d\n", idx4);
}

//�ַ�������(394)
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
	//������ȣ�
	/*int a[4][4] = {
	{1, 1, 0, 0},
	{1, 1, 1, 0},
	{0, 1, 1, 1},
	{0, 0, 1, 1}
	};
	int b = friend_test(a);
	cout << b << endl;*/
	//�������
	srand((unsigned int)time(NULL));
	//�ǹ��������
	//Candy_test();

	//����ѡ���������
	/*int a[] = { 5,200,2,3 };
	int l = 0;
	int r = sizeof(a) / sizeof(a[0]) - 1;
	int b = maxScore(a, l, r);
	cout << b << endl;*/

	//KMP�ַ���ѡ�����
	test_kmp();

	system("pause");
	return 0;
}
