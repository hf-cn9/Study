#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<ctime>
#include<queue>
#include<stack>
#include<string>

using namespace std;

//ð������
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
//ѡ������
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
//��������
static void insertsort(int a[], int length) {
	for (int i = 1;i < length;i++) {
		int temp = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j];
			j--;
		}
		// �� temp ���뵽��ȷ��λ��
		a[j + 1] = temp;
	}
}
//ϣ������
static void shellsort(int a[], int length) {
	int gap = length;
	while (gap > 0) {
		gap = gap / 2;
		//Hibbard �������� g(k) = 2^k - 1 ���� k �� 1 ��ʼ����
		//Sedgewick �������� 1, 5, 19, 41, 109, ��
		//����ĳЩָ�� k��ʹ�ù�ʽ��g(2k) = 94^k - 92^k + 1**
		//������һЩָ����ʹ�ù�ʽ��g(2k + 1) = 4 ^ (k + 1) - 32 ^ (k + 1) + 1 *
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
//��������
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
		// �ֱ�����ߵݹ�����
		quicksort(a, start, middle - 1);
		quicksort(a, middle + 1, end);
	}
}
//�鲢����
// ��arr[left..mid]��arr[mid+1..right]�鲢��temp�У��ٸ��ƻ�arr
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
	// �������Ľ�����ƻ�ԭ����
	for (i = left; i <= right; i++) {
		arr[i] = temp[i]; 
	}
}
// �鲢����ĵݹ�ʵ�֣��ȶ����������������ٹ鲢
void mergeSortRecursive(int arr[], int temp[], int left, int right) {
	// �������Сʱ�����ò�������
	if (right == left) {
		return;
	}
	int mid = left + (right - left) / 2;
	mergeSortRecursive(arr, temp, left, mid);
	mergeSortRecursive(arr, temp, mid + 1, right);
	// �Ż���������Ҳ����Ѿ�������ֱ�ӷ���
	if (arr[mid] <= arr[mid + 1])
		return;
	merge(arr, temp, left, mid, right);
}
// �ⲿ�ӿڣ�һ�������븨�����飬�����õݹ����
void mergeSort(int arr[], int n) {
	int* temp = (int*)malloc(n * sizeof(int));
	if (temp == NULL) {
		fprintf(stderr, "�ڴ����ʧ��\n");
		exit(EXIT_FAILURE);
	}
	mergeSortRecursive(arr, temp, 0, n - 1);
	free(temp);
}
//������
//�ѵ���
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
		heapify(arr, n, greater);//�������µ��������ݹ鼴��
	}
}
void heapSort(vector<int>& arr) {
	int n = arr.size();
	for (int i = n / 2 - 1;i >= 0;i--) {//��������
		heapify(arr, n, i);
	}
	for (int i = n-1;i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);//�������µ��������ݹ鼴��
	}
}
//��������
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
//Ͱ����
void bucketSort(vector<int>& arr) {
	int maxval = *max_element(arr.begin(), arr.end());
	int minval = *min_element(arr.begin(), arr.end());
	//����Ͱ
	int bucketcount = arr.size();
	vector<vector<int>> bucket(bucketcount);
	//����Ͱ�ĸ������䣻+1ȷ��Ͱ�Ĵ�С��Ϊ0��
	int bucketsize = (maxval - minval) / bucketcount + 1;
	for (int num : arr) {
		int index = (num - minval) / bucketsize + 1;
		if (bucketcount <= index) index = bucketcount;
		bucket[index].push_back(num);
	}
	//һ��ѡ�������㷨��Ͱ�����ݽ�������(Ҳ����ʹ��Ͱ������������
	for (int i = 0; i < bucketcount; i++) {
		sort(bucket[i].begin(), bucket[i].end());
	}
	//������õ�Ͱ������ӵ������У�
	int index = 0;
	for (int i = 0; i < bucketcount; i++) {
		for (int num : bucket[i]) {
			arr[index++] = num;
		}
	}
}
//��������
void countingSort(vector<int>& arr, int exp) {//��������
	int n = arr.size();
	vector<int>output(n,0);	     // ������飬���ڴ洢����������
	vector<int>counts(10, 0); // �������飬ͳ�� 0~9 ���ֵĴ���
	// ͳ��ÿ�������ڵ�ǰλ�ϳ��ֵĴ���
	for(int num : arr){  
		int digit = (num / exp) % 10;
		counts[digit]++;
	}
	// �����ۼӼ���������ȷ��ÿ����������������е�λ��
	for (int i = 1;i < 10;i++) {
		counts[i] += counts[i - 1];
	}
	// Ϊ�����ȶ��ԣ��Ӻ���ǰ����ԭ���飬��Ԫ�طŵ�����������ȷλ��
	for (int i = n - 1;i >= 0;i--) {
		int digit = (arr[i] / exp) % 10;
		output[counts[digit] - 1] = arr[i];
		counts[digit]--;
	}
	// ���������������ƻ� arr
	arr = output;
}

// ����������
void radixSort(vector<int>& arr) {
	if (arr.empty()) return;
	// �ҵ������е����ֵ��ȷ�����λ��
	int maxval = *max_element(arr.begin(), arr.end());
	// ��ÿ��λ���м������򣬴Ӹ�λ��ʼ�����δ���ʮλ����λ����ֱ�����ֵ��λ��
	for (int exp = 1;0 < maxval/exp;exp *= 10) {
		countingSort(arr, exp);
	}
}