#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>

using namespace std;

//Create a function that takes two list of numbers and returns a new list that only consists those
//numbers that are in the first array but not in the second

void fill_two_vector_with_random_integers(vector<int> &vect);

void fill_two_vector_with_integers(vector<int> &vect_1, vector<int> &vect_2);

void print_vector_to_console(vector<int> vect);

void sort_vector_elements(vector<int> &vect);

vector<int> subtract_list_two_from_list_one(vector<int> l_one, vector<int> l_two);

vector<int> subtract_version_two(vector<int> l_one, vector<int> l_two);

int main(int argc, char* argv[]) {
  
  srand(time(0));

  vector<int> list_one;
  vector<int> list_two;
  vector<int> subtracted_one;
  vector<int> subtracted_two;

  //fill_two_vector_with_integers(list_one, list_two);
  fill_two_vector_with_random_integers(list_one);
  fill_two_vector_with_random_integers(list_two);

  print_vector_to_console(list_one);
  
  cout << endl;
  print_vector_to_console(list_two);

  subtracted_one = subtract_list_two_from_list_one(list_one, list_two);
  subtracted_two = subtract_version_two(list_one, list_two);
  
  cout << endl;
  print_vector_to_console(subtracted_one);
  
  cout << endl;
  print_vector_to_console(subtracted_two);

  return 0;
}

void fill_two_vector_with_random_integers(vector<int> &vect) {
  for (int i = 0; i < 20; i++) {
    vect.push_back(rand() % 20);
  }
}

void fill_two_vector_with_integers(vector<int> &vect_1, vector<int> &vect_2) {
  for (int i = 0; i < 20; i++) {
    vect_1.push_back(i);
    if (i % 2 == 0) {
      vect_2.push_back(i);
    }
  }
}

void print_vector_to_console(vector<int> vect) {
  for (int i = 0; i < vect.size(); i++) {
    cout << vect[i] << " ";
  }
}

void sort_vector_elements(vector<int> &vect) {
  sort(vect.begin(), vect.end());
}

vector<int> subtract_list_two_from_list_one(vector<int> l_one, vector<int> l_two) {
  vector<int> subtracted_vector;
  bool is_element_in_both_vector = false;
  sort_vector_elements(l_one);
  sort_vector_elements(l_two);
  for (int i = 0; i < l_one.size(); i++) {
    for (int j = 0; j < l_two.size(); j++) {
      if (l_one[i] == l_two[j]) {
        is_element_in_both_vector = true;
      }
    }
    if (is_element_in_both_vector == false) {
      subtracted_vector.push_back(l_one[i]);
    }
    else {
      is_element_in_both_vector = false;
    }
  }
  return subtracted_vector;
}

vector<int> subtract_version_two(vector<int> l_one, vector<int> l_two) {
  vector<int> subtracted_vector;
  sort_vector_elements(l_one);
  sort_vector_elements(l_two);
  set_difference(l_one.begin(), l_one.end(),
    l_two.begin(), l_two.end(),
    back_inserter(subtracted_vector));
  return subtracted_vector;
}