#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<ctime>
#include<queue>
#include<stack>
#include<string>

using namespace std;

//冒泡排序
static void bubbersort(int a[], int length) {
	for (int i = 0; i < length - 1;i++) {
		int swaped = 0;
		for (int j = 0;j < length - i - 1;j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				swaped = 1;
			}
		}
		if (!swaped) {
			break;
		}
	}
}
//选择排序
static void selectsort(int a[], int length) {
	for (int i = 0; i < length - 1; i++) {
		int minindex = i;
		for (int j = i + 1;j < length;j++) {
			if (a[minindex] > a[j]) {
				minindex = j;
			}
		}
		int temp = a[i];
		a[i] = a[minindex];
		a[minindex] = temp;
	}
}
//插入排序
static void insertsort(int a[], int length) {
	for (int i = 1;i < length;i++) {
		int temp = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j];
			j--;
		}
		// 将 temp 插入到正确的位置
		a[j + 1] = temp;
	}
}
//希尔排序
static void shellsort(int a[], int length) {
	int gap = length;
	while (gap > 0) {
		gap = gap / 2;
		//Hibbard 增量序列 g(k) = 2^k - 1 其中 k 从 1 开始递增
		//Sedgewick 增量序列 1, 5, 19, 41, 109, …
		//对于某些指数 k，使用公式：g(2k) = 94^k - 92^k + 1**
		//对于另一些指数，使用公式：g(2k + 1) = 4 ^ (k + 1) - 32 ^ (k + 1) + 1 *
		for (int i = gap;i < length;i++) {
			int currentvalue = a[i];
			int preindex = i - gap;
			while (preindex >= 0 && a[preindex] > currentvalue) {
				a[preindex + gap] = a[preindex];
				preindex -= gap;
			}
			a[preindex + gap] = currentvalue;
		}
	}
}
//快速排序
int partition(int a[], int start, int end) {
	//hoare
	/*int hoare = a[start];
	int i = start - 1;
	int j = end + 1;
	while (1) {
		do {
			i++;
		} while (a[i] < hoare);
		do {
			j--;
		} while (a[j] > hoare);
		if (i >= j) {
			return j;
		}
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}*/
	//lumuto
	int lumuto = a[end];
	int i = start - 1;
	for (int j = start; j < end;j++) {
		if (a[j] <= lumuto) {
			i++;
			if (i < j) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	i++;
	int temp = a[i];
	a[i] = a[end];
	a[end] = temp;
	return i;
}
static void quicksort(int a[], int start, int end) {
	if (start < end) {
		int middle = partition(a, start, end);
		// 分别对两边递归排序
		quicksort(a, start, middle - 1);
		quicksort(a, middle + 1, end);
	}
}
//归并排序
// 将arr[left..mid]和arr[mid+1..right]归并到temp中，再复制回arr
void merge(int arr[], int temp[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	// 将排序后的结果复制回原数组
	for (i = left; i <= right; i++) {
		arr[i] = temp[i]; 
	}
}
// 归并排序的递归实现：先对左右两部分排序，再归并
void mergeSortRecursive(int arr[], int temp[], int left, int right) {
	// 当区间较小时，采用插入排序
	if (right == left) {
		return;
	}
	int mid = left + (right - left) / 2;
	mergeSortRecursive(arr, temp, left, mid);
	mergeSortRecursive(arr, temp, mid + 1, right);
	// 优化：如果左右部分已经有序，则直接返回
	if (arr[mid] <= arr[mid + 1])
		return;
	merge(arr, temp, left, mid, right);
}
// 外部接口：一次性申请辅助数组，并调用递归过程
void mergeSort(int arr[], int n) {
	int* temp = (int*)malloc(n * sizeof(int));
	if (temp == NULL) {
		fprintf(stderr, "内存分配失败\n");
		exit(EXIT_FAILURE);
	}
	mergeSortRecursive(arr, temp, 0, n - 1);
	free(temp);
}
//堆排序
//堆调整
void heapify(vector<int>& arr, int n, int i) {
	int greater = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left< n && arr[left] > arr[greater]) {
		greater = left;
	}
	if (right< n && arr[right] > arr[greater]) {
		greater = right;
	}
	if (greater != i) {
		swap(arr[greater], arr[i]);
		heapify(arr, n, greater);//仅需向下调整，即递归即可
	}
}
void heapSort(vector<int>& arr) {
	int n = arr.size();
	for (int i = n / 2 - 1;i >= 0;i--) {//构建最大堆
		heapify(arr, n, i);
	}
	for (int i = n-1;i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);//仅需向下调整，即递归即可
	}
}
//计数排序
void countingSort(vector<int>& arr) {
	int maxvalue = arr[0], minvalue = arr[0];
	for (vector<int>::iterator it = arr.begin();it < arr.end();it++) {
		if (*it < minvalue) minvalue = *it;
		if (*it > maxvalue) maxvalue = *it;
	}
	int range = maxvalue - minvalue + 1;
	vector<int>countarr(range, 0);
	for (int num : arr) {
		countarr[num - minvalue]++;
	}
	int index = 0;
	for (int i = 0;i < range;i++) {
		while (countarr[i] > 0) {
			arr[index++] = i + minvalue;
			countarr[i]--;
		}
	}
}
//桶排序
void bucketSort(vector<int>& arr) {
	int maxval = *max_element(arr.begin(), arr.end());
	int minval = *min_element(arr.begin(), arr.end());
	//构造桶
	int bucketcount = arr.size();
	vector<vector<int>> bucket(bucketcount);
	//计算桶的覆盖区间；+1确保桶的大小不为0；
	int bucketsize = (maxval - minval) / bucketcount + 1;
	for (int num : arr) {
		int index = (num - minval) / bucketsize + 1;
		if (bucketcount <= index) index = bucketcount;
		bucket[index].push_back(num);
	}
	//一般选择其他算法对桶内数据进行排序(也可以使用桶排序来迭代）
	for (int i = 0; i < bucketcount; i++) {
		sort(bucket[i].begin(), bucket[i].end());
	}
	//将排序好的桶重新添加到数组中；
	int index = 0;
	for (int i = 0; i < bucketcount; i++) {
		for (int num : bucket[i]) {
			arr[index++] = num;
		}
	}
}
//基数排序
void countingSort(vector<int>& arr, int exp) {//计数排序
	int n = arr.size();
	vector<int>output(n,0);	     // 输出数组，用于存储本趟排序结果
	vector<int>counts(10, 0); // 计数数组，统计 0~9 出现的次数
	// 统计每个数字在当前位上出现的次数
	for(int num : arr){  
		int digit = (num / exp) % 10;
		counts[digit]++;
	}
	// 计算累加计数，用于确定每个数字在输出数组中的位置
	for (int i = 1;i < 10;i++) {
		counts[i] += counts[i - 1];
	}
	// 为保持稳定性，从后向前遍历原数组，将元素放到输出数组的正确位置
	for (int i = n - 1;i >= 0;i--) {
		int digit = (arr[i] / exp) % 10;
		output[counts[digit] - 1] = arr[i];
		counts[digit]--;
	}
	// 将本趟排序结果复制回 arr
	arr = output;
}

// 基数排序函数
void radixSort(vector<int>& arr) {
	if (arr.empty()) return;
	// 找到数组中的最大值，确定最大位数
	int maxval = *max_element(arr.begin(), arr.end());
	// 对每个位进行计数排序，从个位开始，依次处理十位、百位……直至最大值的位数
	for (int exp = 1;0 < maxval/exp;exp *= 10) {
		countingSort(arr, exp);
	}
}