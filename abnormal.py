class Solution:
 """
 当我们认为某些代码可能会出错时，就可以用try来运行这段代码，
 如果执行出错，则后续代码不会继续执行，而是直接跳转至错误处理代码，即except语句块，执行完except后，
 如果有finally语句块，则执行finally语句块。
 简单总结：
  1、当执行try…except之间的语句序列没有发生异常时，则忽略异常处理部分(except)的语句。
  2、Except括起来的语句，则只有在产生异常的情况下会被执行，其他情况一概不执行的。
  3、Finally括起来的语句是铁定会被执行的，无论是否有异常产生；
 """
    def evalRPN(self, tokens: List[str]) -> int:
        op_to_binary_fn = {
            "+": add,
            "-": sub,
            "*": mul,
            "/": lambda x, y: int(x / y),   # 需要注意 python 中负数除法的表现与题目不一致
        }

        stack = list()
        for token in tokens:
            try:
                num = int(token)
            except ValueError:
                num2 = stack.pop()
                num1 = stack.pop()
                num = op_to_binary_fn[token](num1, num2)
            finally:
                stack.append(num)
            
        return stack[0]
