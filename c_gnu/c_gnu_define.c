#include <stdio.h>

#define MAX(x, y) ({   \
    int _x = x;        \
    int _y = y;        \
    _x > _y ? _x : _y; \
})

#define MAX_FROM_TYPE(type, x, y) ({ \
    type _x = x;                     \
    type _y = y;                     \
    _x > _y ? _x : _y;               \
})

#define MAX_AUTO(x, y) ({    \
    typeof(x) _x = (x); \
    typeof(y) _y = (y); \
    (void) (&_x == &_y);\
    _x > _y ? _x : _y; })

// gcc c_gnu_define.c && ./a.out
int main(void)
{
    printf("max=%d \n", MAX_AUTO(1 != 1, 1 != 2));
    printf("max=%d \n", 3 + MAX_AUTO(1, 2));
    int i = 2;
    int j = 6;
    printf("max=%d \n", MAX_AUTO(i++, j++));
    return 0;
}