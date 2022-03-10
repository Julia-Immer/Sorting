#include "Sorting.h"

/*
  Please refer to sorting.h for documentation on each function.

-----------------------------\
   |                                                                    |
   |    We clearly can't use unit testing to ensure that you're         |
   |    actually implementing the correct algorithm. I suppose we could |
   |    write some complicated static analysis checker. But it is       |
   |    easier to just look at it with our eyeballs.                    |
   |                                                                    |
   |    After the assignment is due, we will look at the most recent    |
   |    version of your implementation that got the highest score and   |
   |    make sure you're not doing something sneaky like using a        |
   |    standard library call to sort a vector.                         |
   |                                                                    |
   |    Anyone caught doing this (even though it is kinda funny) will   |
   |    be given 0 points on the assignment.                            |
   |                                                                    |
   `--------------------------------------------------------------------/ 
*/

// constructor, initialize class variables and pointers here if you need.
Sorting::Sorting(){
  // Your code here
}

//deconstructor,
Sorting::~Sorting(){
}

void Sorting::quicksort(vector<int>& data, int low, int high){
  //if the list is larger than one element, partition and recurse left and right
  if (low < high) {
    int p = quicksort_partition(data, low, high); //find our partition
    quicksort(data, low, p-1); //sort left
    quicksort(data, p+1, high); //sort right
  }
}

int Sorting::quicksort_partition(vector<int>& data, int low, int high){
  int pivot = data[high]; //pick pivot
  int i = low;
  int temp;

  //loop through elements of data from low to high - 1. We don't include the pivot (high)
  for (int j = low; j < high; ++j) {
    //if current element is less than pivot, swap data[i] and data[j]
    if(data[j] < pivot) {
      temp = data[i];
      data[i] = data[j];
      data[j] = temp;
      ++i;
    }
  }

  //we must check data[i] against the pivot still
  if (pivot < data[i]) {
    temp = data[i];
    data[i] = data[high];
    data[high] = temp;
  }

  return i; //return the new partition index
}

//done
void Sorting::bubblesort(vector<int>& data){
  int swaps_left = data.size() - 1; //possible swaps left in each sorting iteration
  int temp;

  //Sort multiple times and decremint the terminating condition
  while (swaps_left > 0) {
    //Examine all pairs and swap if out of order
    //Largest value "bubbles" up to the end each time so we can stop sooner each round
    for (int i = 0; i < swaps_left; ++i) {
      if (data[i] > data[i+1]) {
        temp = data[i];
        data[i] = data[i+1];
        data[i+1] = temp;
      }
    }
    --swaps_left; //look at less values next time
  }
}

void Sorting::mergesort(vector<int>& data){
  int data_len = data.size();

  //If we have 2 or more elements in data, we can split it in half
  //If it's less than 2 elements, do nothing and return
  if (data_len > 1) {
    int mid = data_len/2; //find the middle of the vector

    //partition into left and right sides. Right includes mid element
    vector<int> left(data.begin(), data.begin() + mid);
    vector<int> right(data.begin() + mid, data.end());
    
    //Recursively sort the left and right sides
    mergesort(left);
    mergesort(right);

    //Now merge the two sides and sort them while merging
    vector<int> result;
    merge(left, right, result);

    //copy values into original vector
    for (int i = 0; i < data_len; ++i) {
      data[i] = result[i];
    }
  }
}

void Sorting::merge(vector<int>& left, vector<int>& right, vector<int>& result){
  //takes in two vectors, left and right and sorts them element by element into result vector

  int i = 0; //index variable for left vector
  int j = 0; //index variable for right vector
  int left_len = left.size();
  int right_len = right.size();

  //while we haven't reached the end of left or right vector
  //find the larger element and append it to the result vector
  while ((i < left_len) && (j < right_len)) {
      if (left[i] <= right[j]) {
        result.push_back(left[i]);
        ++i;
      }
      else {
        result.push_back(right[j]);
        ++j;
      }
  }

  //Copy any remaining elements into the result vector
  while (i < left_len) { //left remaining
    result.push_back(left[i]);
    ++i;
  }
  while (j < right_len) { //right remaining
    result.push_back(right[j]);
    ++j;
  }
}

//Selection Sort: choose the smallest element in list, and move them to the front one by one
void Sorting::mystery_sort(vector<int>& data){
  //selection sort
  vector<int> result;
  int data_len = data.size();
  int min_i, temp;

  //find minimum elements one by one and swap them with the current one
  for(int j = 0; j < data_len; ++j) {
    //Iterate through the remaining list to find the smallest element
    min_i = j;
    for (int i = j + 1; i < data_len; ++i) {
      if(data[i] < data[min_i]) {
        min_i = i;
      }
    }
    //swapping operation
    temp = data[min_i];
    data[min_i] = data[j];
    data[j] = temp;   
  }
}

//printing function for testing when debug console is too small to look at long lists
void Sorting::printVec(vector<int>& vec) {
  int vec_len = vec.size();

  for (int i = 0; i < vec_len; ++i) {
    cout << vec[i] << ", ";
  }
  cout << endl;
}