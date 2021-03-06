// App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "../lib/public.h"
#include "../dll2/public.h"

typedef double(*MYPROC)(int);

void use_staticLib();
void use_dll1();
void use_dll2();

int main()
{
    use_staticLib();
    use_dll1();
    use_dll2();
}

//funkcije get_value iz static_library.lib (lib/public.h)
void use_staticLib()
{
  int n = 10;

  std::cout << static_lib::get_value(n) << std::endl;
}

//funkcije get_value iz dynamic_library.dll (potpis: double get_value(int))
void use_dll1()
{
  int n = 20;

  HINSTANCE hinst = LoadLibrary(TEXT("dynamic_library.dll"));
  if (hinst != NULL)
  {
    MYPROC procAdd = (MYPROC)GetProcAddress(hinst, "get_value");
    if (procAdd != NULL)
      std::cout << procAdd(n) << std::endl;
    
    FreeLibrary(hinst);
  }
}

//funkcije get_value iz dynamic_library_with_implib.dll (dll2/public.h)
void use_dll2()
{
  int i = 30;

  std::cout << get_value(i) << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
