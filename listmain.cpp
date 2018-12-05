#include "list.h"


int main ()
{
  FILE *baza = fopen ("baza.txt", "r");
  int size = CalculateSize (baza);
  fclose (baza);
  char *buf = new char[size];
  ReadData (buf, size);
  int counter = CountAndChange (buf, size);
  char **text = new char* [counter + 1];
  Texting (buf, text, counter, size);
  HashTable hash;
  List lists[SIZE] = {};
  hash.lists = lists;

  for (int i = 0; i < counter; i++)
  {
    long long int a = HashFunct1(&text[i]);
    Registr(&text[i], lists, a);
  }
  FILE *gr1 = fopen ("graf1.ods", "w");
  WriteData (gr1, lists);
  fclose (gr1);

  for (int i = 0; i < counter; i++)
  {
    long long int a = HashFunct2(&text[i]);
    Registr(&text[i], lists, a);
  }
  FILE *gr2 = fopen ("graf2.ods", "w");
  WriteData (gr2, lists);
  fclose (gr2);

  for (int i = 0; i < counter; i++)
  {
    long long int a = HashFunct3(&text[i]);
    Registr(&text[i], lists, a);
  }
  FILE *gr3 = fopen ("graf3.ods", "w");
  WriteData (gr3, lists);
  fclose (gr3);

  return 0;
}
