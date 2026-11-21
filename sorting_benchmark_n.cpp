#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>
using namespace std;
using namespace std::chrono;
// 1. Bubble Sort (from scratch with early-exit optimization)
void bubbleSort(vector<int> &arr)
{
  int n = static_cast<int>(arr.size());
  for (int i = 0; i < n - 1; ++i)
  {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; ++j)
    {
      if (arr[j] > arr[j + 1])
      {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}
// 2. Selection Sort (from scratch)
void selectionSort(vector<int> &arr)
{
  int n = static_cast<int>(arr.size());
  for (int i = 0; i < n - 1; ++i)
  {
    int minIdx = i;
    for (int j = i + 1; j < n; ++j)
    {
      if (arr[j] < arr[minIdx])
      {
        minIdx = j;
      }
    }
    if (minIdx != i)
    {
      int tmp = arr[i];
      arr[i] = arr[minIdx];
      arr[minIdx] = tmp;
    }
  }
}
// 3. Insertion Sort (from scratch)
void insertionSort(vector<int> &arr)
{
  int n = static_cast<int>(arr.size());
  for (int i = 1; i < n; ++i)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}
// 4. Merge Sort (from scratch)
void mergeArrays(vector<int> &arr, int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;
  vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; ++i)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; ++j)
    R[j] = arr[mid + 1 + j];
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}
void mergeSortHelper(vector<int> &arr, int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;
    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);
    mergeArrays(arr, left, mid, right);
  }
}
void mergeSort(vector<int> &arr)
{
  if (!arr.empty())
  {
    mergeSortHelper(arr, 0, static_cast<int>(arr.size()) - 1);
  }
}
// Generate array of size n (ascending given arrays or descending worst-case)
vector<int> makeSequence(int n, bool reverseOrder)
{
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
  {
    v[i] = reverseOrder ? (n - i) : (i + 1);
  }
  return v;
}
// Measure average time across 10 runs per input size
void benchmarkAlgo(const string &name, void (*fn)(vector<int> &), bool reverseOrder, int runs = 10)
{
  vector<int> sizes = {5, 10, 50, 100};
  for (int n : sizes)
  {
    vector<int> base = makeSequence(n, reverseOrder);
    double sumUs = 0.0;
    // Warmup pass
    {
      vector<int> w = base;
      fn(w);
    }
    for (int r = 0; r < runs; ++r)
    {
      vector<int> copyArr = base;
      auto t1 = high_resolution_clock::now();
      fn(copyArr);
      auto t2 = high_resolution_clock::now();
      sumUs += duration<double, micro>(t2 - t1).count();
    }
    double avgUs = sumUs / runs;
    cout << name << "|" << (reverseOrder ? "Reverse" : "Given")
         << "|" << n << "|" << fixed << setprecision(3) << avgUs << "\n";
  }
}
int main()
{
  // Explicit arrays Arr1..Arr4 from assignment specification
  vector<int> Arr1 = {1, 2, 3, 4, 5};
  vector<int> Arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> Arr3 = makeSequence(50, false);  // {1, 2, ..., 50}
  vector<int> Arr4 = makeSequence(100, false); // {1, 2, ..., 100}
  vector<pair<string, void (*)(vector<int> &)>> algos = {
      {"Bubble Sort", bubbleSort}, {"Selection Sort", selectionSort}, {"Insertion Sort", insertionSort}, {"Merge Sort", mergeSort}};
  for (auto &a : algos)
  {
    benchmarkAlgo(a.first, a.second, false, 10);
    benchmarkAlgo(a.first, a.second, true, 10);
  }
  return 0;
}