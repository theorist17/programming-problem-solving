  /**
   *  @brief  Read a line from stream into a string.
   *  @param __is  Input stream.
   *  @param __str  Buffer to store into.
   *  @return  Reference to the input stream.
   *
   *  Stores characters from is into @a __str until &apos;\n&apos; is
   *  found, the end of the stream is encountered, or str.max_size()
   *  is reached.  Any previous contents of @a __str are erased.  If
   *  end of line is encountered, it is extracted but not stored into
   *  @a __str.
   */

      /**
       *  @brief  Get a substring.
       *  @param __pos  Index of first character (default 0).
       *  @param __n  Number of characters in substring (default remainder).
       *  @return  The new string.
       *  @throw  std::out_of_range  If __pos > size().
       *
       *  Construct and return a new string using the @a __n
       *  characters starting at @a __pos.  If the string is too
       *  short, use the remainder of the characters.  If @a __pos is
       *  beyond the end of the string, out_of_range is thrown.
      */

//   inline int
//   stoi(const string& __str, size_t* __idx = 0, int __base = 10)
//   { return __gnu_cxx::__stoa<long, int>(&std::strtol, "stoi", __str.c_str(),
// 					__idx, __base); }

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	cin.ignore();
	while(T--)
	{
		string line;
		getline(cin, line);
		cout << stoi(line.substr(0, 1)) + stoi(line.substr(2,1)) << '\n';
	}
	return 0;
}