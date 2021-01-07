#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Read words from cin into the given vector of strings.
void readWords( /* ... */ vector< string > &words)
{
  // ...
    
    string val;
    while (cin >> val)
        words.push_back(val);
    
    
//    cout << "First Word" << endl << words[0] << endl;
//    cout << "Size is: " << endl << words.size() << endl;
}

// Use the index operator ( you know, [] ) to print out the list
// of words in reverse.
void printBackward( /* ... */ const vector< string > &words)
{
  cout << "-- Backward --" << endl;
  // ...
    for (int i = words.size(); i > 0; i--)
        cout << words[i-1] << endl;
}

// Use iteratros to print the list forward.
void printForward( /* ... */ const vector< string > &words)
{
  cout << "-- Forward --" << endl;
  // ...
//    for ( auto p = words.begin(); p != words.end(); p++ )
//        cout << *p << endl;
    
    for (int i = 0; i < words.size(); i++)
        cout << words[i] << endl;
}

int main()
{
  // You can make a vector of strings.  Why not.
  vector< string > words;

  // Read a list of words.
  readWords( words );

  // Use a template algorithm to sort them.
  // ...
    
    sort(words.begin(), words.end());

  // Print the list backward.
  printBackward( words );

  // Then print it again, forward this time.
  printForward( words );
}
