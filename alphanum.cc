#include <iostream>
#include <string>
#include <regex>
#include <set>

// Zeit: 30min !!!

void split(std::map<std::string, std::set<std::string>>& output, const std::string& input)
{
  std::smatch sm;
  std::regex e("([^0-9]*)(.*)");
  std::regex_match(input,sm,e);
  output[sm[1]].insert(sm[2]);
}

int main()
{
  std::map<std::string, std::set<std::string>> sorted;
  split(sorted, "B 567");
  split(sorted, "AB 780");
  split(sorted, "C 666");
  split(sorted, "A 235");
  split(sorted, "543");
  split(sorted, "A");
  split(sorted, "A 123");
  for( auto& pair : sorted ){
    for(auto& value : pair.second)
    {
      std::cout << pair.first << value << std::endl;
    }
  }
}
