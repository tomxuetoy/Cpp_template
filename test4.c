#include <iostream>
 
template <typename T>
inline const T& maximum(const T& x,const T& y)
{
   if(y > x)
      return y;
   else
      return x;
}
 
int main(void)
{
   using namespace std;
   //Calling template function
   std::cout << maximum<int>(3,7) << std::endl;         //输出 7
   std::cout << maximum(3, 7) << std::endl;             //和上面相同
   std::cout << maximum<double>(3.0,7.0) << std::endl;  //输出 7
   return 0;
}
