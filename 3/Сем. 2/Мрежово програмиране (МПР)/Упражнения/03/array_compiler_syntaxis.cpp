#include <iostream>
#include <bitset>
void add(
    const float(&a)[2],
    const float(&b)[2],
    float(&res)[2]) {
    for (size_t i = 0; i < 2; ++i)
        res[i] = a[i] * b[i];
}



void summ(const int(&a)[5]) {
    int sum = 0;
    for (int i = 0; i < 5; ++i)
        sum += a[i];

    std::cout << std::endl;

    std::cout << sum << std::endl;
}





int main()
{
    float a[2] = { 5.4f,0.1f }, b[2] = { 7.8f,7.5f }, c[2] = { 0.0f,0.0f };
    add(*reinterpret_cast<float(*)[2]>(&a), *reinterpret_cast<float(*)[2]>(&b), *reinterpret_cast<float(*)[2]>(&c));
    std::cout << "c[0]=" << *c << '\n' << "c[1]=" << *(c + 1) << '\n';


    int arr[]{ 3,6,9,12 };
    int(*p)[4] = &arr;
    for (unsigned i(0); i < 4; i++)
        std::cout << (*p)[i] << '\n';


    int value = 0x01020304;
    char(*pp)[4] = reinterpret_cast<char(*)[4]>(&value);
    

    for (unsigned i(0); i < 4; i++)
        std::cout << (int)(*pp)[i];
    std::cout << '\n';
    int ab = 4;

      *(double*)&ab = 7.5;
   

    std::cout << ab << std::endl;

    return 0;
}