#include <cstdio>
#include <cmath>

// g++ lib_math_test.cpp && ./a.out
int main()
{

    printf("数学运算:https://www.apiref.com/cpp-zh/cpp/numeric/math.html\n");

    // 基本的算术运算
    int a = 10, b = 3;
    int sum = a + b;               // 加法
    int diff = a - b;              // 减法
    int product = a * b;           // 乘法
    int quotient = a / b;          // 整数除法
    double result = (double)a / b; // 浮点数除法
    int remainder = a % b;         // 取余
    int absr = abs(a);             // 绝对值

    // 三角函数
    double x = 1.0;
    double r1 = sin(x); // 正弦函数
    double r2 = cos(x); // 余弦函数
    double r3 = tan(x); // 正切函数

    // 指数函数
    double r4 = exp(x);   // 指数函数
    double r5 = log(x);   // 自然对数函数
    double r6 = log10(x); // 以10为底的对数函数

    // 幂函数
    double r7 = pow(x, 10); // x^10
    double r8 = sqrt(x);    // 计算平方根
}