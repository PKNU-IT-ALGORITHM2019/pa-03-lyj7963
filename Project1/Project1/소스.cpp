#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

void print_table();
void make_random(int data[], int N);
void make_reverse(int data[], int N);
void start_bubble_sort();
void start_selection_sort();
void start_insertion_sort();
void start_merge_sort();
void start_quick();
void bubble_sort(int data[], int N);
void selection_sort(int data[], int N);
void insertion_sort(int data[], int N);
void merge_sort(int data[], int p, int r);
void merge(int data[], int p, int q, int r);
void quick1(int data[], int p, int r);
void quick2(int data[], int p, int r);
void quick3(int data[], int p, int r);
void swap(int data[], int a, int b);
void copy_data(int data[], int N);

int partition_1(int data[], int p, int r);
int partition_2(int data[], int p, int r);
int partition_3(int data[], int p, int r);

int data_1[10][1000];
int data_2[10][10000];
int data_3[10][100000];

int redata_1[1000];
int redata_2[10000];
int redata_3[100000];

int subdata[100000];

int main() {
	print_table();
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++) {
		make_random(data_1[i], 1000);
		make_random(data_2[i], 10000);
		make_random(data_3[i], 100000);
	}
	make_reverse(redata_1, 1000);
	make_reverse(redata_2, 10000);
	make_reverse(redata_3, 100000);

	start_bubble_sort();
	start_selection_sort();
	start_insertion_sort();
	start_merge_sort();
	start_quick();

	return 0;
}



void start_bubble_sort() {
	printf("Bubble		");
	float start, end, timer = 0;
	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_1[j], 1000);
		bubble_sort(subdata, 1000);
		end = clock();
		timer += end - start;
	}
	printf("%.3f	", timer / 10000);

	timer = 0;
	start = clock();
	copy_data(redata_1, 1000);
	bubble_sort(subdata, 1000);
	end = clock();
	timer = end - start;
	printf("%.3f	", timer / 1000);

	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_2[j], 10000);
		bubble_sort(subdata, 10000);
		end = clock();
		timer += end - start;
	}
	printf("%.3f	", timer / 1000);

	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_3[j], 100000);
		bubble_sort(subdata, 100000);
		end = clock();
		timer += end - start;
	}
	printf("%.3f	", timer / 10000);
	
	timer = 0;
	start = clock();
	copy_data(redata_3, 100000);
	bubble_sort(subdata, 100000);
	end = clock();
	timer = end - start;
	printf("%.3f	", timer / 1000);
}
void bubble_sort(int data[], int N)
{
	for (int i = 0; i < N - 1; i++) {
		for (int j = 1; j < N - i; j++) {
			if (data[j - 1] > data[j]) {
				int tmp = data[j];
				data[j] = data[j - 1];;
				data[j - 1] = tmp;
			}
		}
	}
}
void make_reverse(int data[], int N)
{
	for(int i = 0; i < N; i++)
		data[i] = N - i;
}
void make_random(int data[], int N)
{
	for (int i = 0; i < N; i++) {
		data[i] - rand() % N + 1;
	}
}




void start_selection_sort()
{
	printf("\nSelection	");

	float start, end, timer = 0;
	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_1[j], 1000);
		selection_sort(subdata, 1000);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);

	timer = 0;
	start = clock();
	copy_data(redata_1, 1000);
	selection_sort(subdata, 1000);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);


	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_2[j], 10000);
		selection_sort(subdata, 10000);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);
	
	timer = 0;
	start = clock();
	copy_data(redata_2, 10000);
	selection_sort(subdata, 10000);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
	
	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_3[j], 100000);
		selection_sort(subdata, 100000);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);
	
	timer = 0;
	start = clock();
	copy_data(redata_3, 100000);
	selection_sort(subdata, 100000);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
}
void selection_sort(int data[], int N)
{
	int big = 0, index;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			if (data[j] > big) {
				big = data[j];
				index = j;
			}
		}
		int tmp = data[N - i - 1];
		data[N - i - 1] = data[index];
		data[index] = tmp;
	}
}
void start_insertion_sort()
{
	printf("\nInsertion 	");

	float start, end, timer = 0;

	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_1[j], 1000);
		insertion_sort(subdata, 1000);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);

	timer = 0;
	start = clock();
	copy_data(redata_1, 1000);
	insertion_sort(subdata, 1000);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
	
	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_2[j], 10000);
		insertion_sort(subdata, 10000);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);
	
	timer = 0;
	start = clock();
	copy_data(redata_2, 10000);
	insertion_sort(subdata, 10000);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
		
	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_3[j], 100000);
		insertion_sort(subdata, 100000);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);
	
	timer = 0;
	start = clock();
	copy_data(redata_3, 100000);
	insertion_sort(subdata, 100000);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
}
void insertion_sort(int data[], int N)
{
	for (int i = 1; i < N; i++) {
		int tmp = data[i];
		int j = i - 1;
		while (data[j] > tmp && j >= 0) {
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = tmp;
	}
}



void start_merge_sort()
{
	printf("\nMerge		");

	float start, end, timer = 0;
	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_1[j], 1000);
		merge_sort(subdata, 0, 1000 - 1);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);

	timer = 0;
	start = clock();
	copy_data(redata_1, 1000);
	merge_sort(subdata, 0, 1000 - 1);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
	
	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_2[j], 10000);
		merge_sort(subdata, 0, 10000 - 1);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);
	
	timer = 0;
	start = clock();
	copy_data(redata_2, 10000);
	merge_sort(subdata, 0, 10000 - 1);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
	
	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_3[j], 100000);
		merge_sort(subdata, 0, 100000 - 1);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);
	
	timer = 0;
	start = clock();
	copy_data(redata_3, 100000);
	merge_sort(subdata, 0, 100000 - 1);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
}
void merge_sort(int data[], int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(data, p, q);
		merge_sort(data, q + 1, r);
		merge(data, p, q, r);
	}
}
void merge(int data[], int p, int q, int r) {
	int j = p, k = q + 1;
	int B[MAX];
	for (int i = p; i <= r; i++)
	{
		if (j > q && k > r) break;
		else if (j > q) B[i] = data[k++];
		else if (k > r) B[i] = data[j++];
		else
		{
			if (data[k] > data[j]) B[i] = data[j++];
			else B[i] = data[k++];
		}
	}
	for (int i = p; i <= r; i++)
		data[i] = B[i];
}
void start_quick()
{
	float start, end, timer = 0;
	printf("\nquick1		");

	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_1[j], 1000);
		quick1(subdata, 0, 1000 - 1);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);

	timer = 0;
	start = clock();
	copy_data(redata_1, 1000);
	quick1(subdata, 0, 1000 - 1);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
	
	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_2[j], 10000);
		quick1(subdata, 0, 10000 - 1);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);

	timer = 0;
	start = clock();
	copy_data(redata_2, 10000);
	quick1(subdata, 0, 10000 - 1);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
	
	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_3[j], 100000);
		quick1(subdata, 0, 100000 - 1);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);
	
	timer = 0;
	start = clock();
	copy_data(redata_3, 100000);
	quick1(subdata, 0, 100000 - 1);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
	
	printf("\nquick2		");
	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_1[j], 1000);
		quick2(subdata, 0, 1000 - 1);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);

	timer = 0;
	start = clock();
	copy_data(redata_1, 1000);
	quick2(subdata, 0, 1000 - 1);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
	
	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_2[j], 10000);
		quick2(subdata, 0, 10000 - 1);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);
	
	timer = 0;
	start = clock();
	copy_data(redata_2, 10000);
	quick2(subdata, 0, 10000 - 1);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
	
	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_3[j], 100000);
		quick2(subdata, 0, 100000 - 1);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);
	
	timer = 0;
	start = clock();
	copy_data(redata_3, 100000);
	quick2(subdata, 0, 100000 - 1);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);

	printf("\nquick3		");

	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_1[j], 1000);
		quick3(subdata, 0, 1000 - 1);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);

	timer = 0;
	start = clock();
	copy_data(redata_1, 1000);
	quick3(subdata, 0, 1000 - 1);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
	
	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_2[j], 10000);
		quick3(subdata, 0, 10000 - 1);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);
	
	timer = 0;
	start = clock();
	copy_data(redata_2, 10000);
	quick3(subdata, 0, 10000 - 1);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
	
	timer = 0;
	for (int j = 0; j < 10; j++) {
		start = clock();
		copy_data(data_3[j], 100000);
		quick3(subdata, 0, 100000 - 1);
		end = clock();
		timer += end - start;
	}
	printf("%.3f		", timer / 10000);
	
	timer = 0;
	start = clock();
	copy_data(redata_3, 100000);
	quick3(subdata, 0, 100000 - 1);
	end = clock();
	timer = end - start;
	printf("%.3f		", timer / 1000);
}
void quick3(int data[], int p, int r)
{
	if (p < r) {
		int q = partition_3(data, p, r);
		quick3(data, p, q - 1);
		quick3(data, q + 1, r);
	}
}
int partition_3(int data[], int p, int r)
{
	int q = rand() % (r - p) + p;
	swap(data, q, r);
	int x = data[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (data[j] <= x) {
			i++;
			swap(data, i, j);
		}
	}
	swap(data, i + 1, r);
	return (i + 1);
}

void quick2(int data[], int p, int r)
{
	if (p < r) {
		int q = partition_2(data, p, r);
		quick2(data, p, q - 1);
		quick2(data, q + 1, r);
	}
}
int partition_2(int data[], int p, int r)
{
	int q = (p + r) / 2;
	swap(data, q, r);
	int x = data[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (data[j] <= x) {
			i++;
			swap(data, i, j);
		}
	}
	swap(data, i + 1, r);
	return (i + 1);
}
void quick1(int data[], int p, int r)
{
	r--;
	if (p < r) {
		int q = partition_1(data, p, r);
		quick1(data, p, q - 1);
		quick1(data, q + 1, r);
	}
}
int partition_1(int data[], int p, int r)
{
	int x = data[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (data[j] <= x) {
			i++;
			swap(data, i, j);
		}
	}
	swap(data, i + 1, r);
	return (data, i + 1);
}
void print_table()
{
	printf("     Random1000 Reverse1000 Random10000 Reverse10000 Random100000 Reverse100000\n");
}
void swap(int data[], int a, int b)
{
	int tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;
}
void copy_data(int data[], int N)
{
	for (int i = 0; i < N; i++)
		subdata[i] = data[i];
}
	