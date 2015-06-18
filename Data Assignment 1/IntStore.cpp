// FILE: IntStore.cpp
//       Implementation file for the IntStore class
//       (See IntStore.h for documentation.)
// INVARIANT for the IntStore class:
// (1) Distinct values of the IntStore are stored in a 1-D,
//     compile-time array whose size is IntStore::MAX_SIZE;
//     the member variable data references the array.
// (2) The # of occurrences associated with each distinct value
//     (stored in data) is stored in the corresponding element
//     of a parallel 1-D, compile-time array whose size is also
//     IntStore::MAX_SIZE; the member variable freq references
//     the array.
// (3) The distinct value added the earliest is stored in data[0],
//     the distinct value that is added the 2nd-earliest is stored
//     in data[1], and so on.
// (4) The # of distinct values the IntStore currently contains is
//     stored in the member variable used.
// (5) Except when the IntStore is empty (used == 0), ALL elements
//     of data from data[0] until data[used - 1] contain relevant
//     distinct-value data and ALL elements of freq from freq[0]
//     until freq[used - 1] contain relevant occurrence data;
//     the # of occurrences of data[i] is stored in freq[i] (i.e.,
//     data and freq are parallel arrays).
// (6) We DON'T care what is stored in any of the array elements
//     from data[used] through data[IntStore::MAX_SIZE - 1], and
//     from freq[used] through freq[IntStore::MAX_SIZE - 1].

#include <iostream>
#include "IntStore.h"
// include any other relevant header files here
using namespace std;

IntStore::IntStore()
{
   data[MAX_SIZE] = 0;
   freq[MAX_SIZE] = 0;
   used = 0;
}

bool IntStore::empty() const
{
   return (used == 0);
}

int IntStore::countDistinct() const
{
   cout << "countDistinct() is not implemented yet..." << endl;
   return 0; // dummy value returned
}

int IntStore::countAll() const
{
      return (used + 1);
}

int IntStore::countTarget(int target) const
{
   int num = 0;
   for (int i = 0; i < used; ++i)
   {
       if (data [i] == target)
            ++num;
   }
   return num;
}

int IntStore::valAt(int pos) const
{
   return data[pos - 1];
}

int IntStore::freqAt(int pos) const
{
   cout << "freqAt(int) is not implemented yet..." << endl;
   return 0; // dummy value returned
}

double IntStore::avg() const
{
   cout << "avg() is not implemented yet..." << endl;
   return 0.0; // dummy value returned
}

void IntStore::reset()
{
   used = 0;
}

bool IntStore::add(int item, int copies)
{
   cout << "add(int, int) is not implemented yet..." << endl;
   return false; // dummy value returned
}

int IntStore::add(const IntStore& addend)
{
   cout << "add(const IntStore&) is not implemented yet..." << endl;
   return 0; // dummy value returned
}

bool IntStore::remOne(int target)
{
   cout << "remOne(int) is not implemented yet..." << endl;
   return false; // dummy value returned
}

int IntStore::remAll(int target)
{
   cout << "remAll(int) is not implemented yet..." << endl;
   return 0; // dummy value returned
}

bool similar(const IntStore& is1, const IntStore& is2)
{
   cout << "similar(const IntStore&, const IntStore&) "
        << "is not implemented yet..." << endl;
   return false; // dummy value returned
}
