#include <iostream> 
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

int xs, csx; //xs代表系数，csx代表常数
char x; //用x存储字母


int main() {
    char c;
    int f1 = 1, f2 = 1, tmp = 0;
    while (scanf("%c",&c) != EOF) {
        if (c >= '0'&&c <= '9') { //类似快读的读入方式
            tmp *= 10;
            tmp += c-'0';
        } else {
            if (c >= 'a' && c <= 'z') { //判断系数是否为1
                if (tmp == 0) xs += f2 * f1;
                else 
					xs += tmp * f2 * f1;
                x = c;
            }
			else //就算是=，也要做这个和temp=0 
				csx += tmp * (-f2) * f1;
            tmp = 0;
        }
        if (c == '+') {
            f1 = 1;
            continue;
        } else if (c == '-') {
            f1 = -1;
            continue;
        } else if (c == '=') {
            f2 = -1, f1 = 1;
            continue;
        }
    }
    if (tmp != 0) csx += tmp * (-f2) * f1;//全都输入结束，还要处理一下r 
    //在 while 循环结束后，如果 tmp 未被清零，则将 tmp 按照常数的方法移项。
	//也就是左边还有常数项 
    printf("%c=%0.3f", x, 1.0 * csx / xs == 0 ? abs(1.0 * csx / xs) : 1.0 * csx /xs);
    return 0;
}
