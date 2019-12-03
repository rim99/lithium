#include <li/metamap/make.hh>
#include <li/metamap/algorithms/intersection.hh>
#include <cassert>
#include <string>

LI_SYMBOL(test1)
LI_SYMBOL(test2)
LI_SYMBOL(test3)
LI_SYMBOL(test4)
LI_SYMBOL(test5)

using namespace li;

int main()
{
  auto a = mmm(s::test1 = 12, s::test2 = 13, s::test4 = 14, s::test5 = std::string("test"));

  auto b = mmm(s::test2 = 12, s::test3 = 14, s::test5 = 16);
  auto c = intersection(a, b);

  assert(!has_key(c, s::test1));
  assert(has_key(c, s::test2));
  assert(!has_key(c, s::test3));
  assert(!has_key(c, s::test4));
  assert(has_key(c, s::test5));

  assert(c.test2 == 13);
  assert(c.test5 == "test");
}
