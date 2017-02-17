#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Create a function that takes two list of numbers and returns a new list that only consists those
//numbers that are in the first array but not in the second

void fill_vectors(vector<int> &vect_1, vector<int> &vect_2) {
  for (int i = 0; i < 20; i++) {
    vect_1.push_back(i);
    if (i % 2 == 0) {
      vect_2.push_back(i);
    }
  }
}

void print_vector(vector<int> vect) {
  for (int i = 0; i < vect.size(); i++) {
    cout << vect[i] << " ";
  }
}

void sort_vector(vector<int> &vect) {
  sort(vect.begin(),vect.end());
}

vector<int> subtract_list_two_from_list_one(vector<int> l_one, vector<int> l_two) {
  vector<int> subtracted_vector;
  bool is_element_in_both_vector = false;
  for (int i = 0; i < l_one.size(); i++) {
    for (int j = 0; j < l_two.size(); j++) {
      if (l_one[i] == l_two[j]) {
        is_element_in_both_vector = true;
      }
    }
    if (is_element_in_both_vector == false) {
      subtracted_vector.push_back(i);
    }
    else {
      is_element_in_both_vector = false;
    }
  }
  return subtracted_vector;
}

int main(int argc, char* argv[]) {
  vector<int> list_one;
  vector<int> list_two;
  vector<int> subtracted;
  fill_vectors(list_one, list_two);

  print_vector(list_one);
  cout << endl;
  print_vector(list_two);

  subtracted = subtract_list_two_from_list_one(list_one, list_two);

  cout << endl;

  print_vector(subtracted);

  return 0;
}