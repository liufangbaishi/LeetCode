// 变态跳台阶 青蛙可以一次跳1层，也可以一次跳2层，，，可以一次跳n层
#if 0
int jumpFloorII(int number)  //数学归纳法可得f(n)=2^(n-1)
{
	return pow(2, (number - 1));
}
//#else
int jumpFloorII(int number)//当n=1时，只有一种跳法，即1阶跳：Fib(1) = 1;
                           //当n=2时，有两种跳的方式，一阶跳和二阶跳：Fib(2) = Fib(1) + Fib(0) = 2;
                           //当n=3时，有三种跳的方式，第一次跳出一阶后，后面还有Fib(3-1)中跳法；
						                            //第一次跳出二阶后，后面还有Fib(3-2)中跳法；
													//第一次跳出三阶后，后面还有Fib(3-3)中跳法
                                                    //Fib(3) = Fib(2) + Fib(1) + Fib(0) = 4;
//Fib(n)=Fib(n-1)+Fib(n-2)+Fib(n-3)+...+Fib(n-n)
//Fib(n-1)=Fib(0)+Fib(1)+Fib(2)+...+Fib(n-2)
//两式相减得：Fib(n)-Fib(n-1)=Fib(n-1) ===> Fib(n)=2*Fib(n-1) n >= 2
{
	if (number < 0)
		return 0;
	if (number == 0 || number == 1)
		return 1;
	return 2 * jumpFloorII(number - 1);
}

int main()
{
	jumpFloorII(5);
	return 0;
}