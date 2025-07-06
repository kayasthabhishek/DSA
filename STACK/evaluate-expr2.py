operators = "+-/*^"

def switch(operator, op1, op2):
    switch_dict = {
        '-': lambda: op1 - op2,
        '+': lambda: op1 + op2,
        '*': lambda: op1 * op2,
        '/': lambda: op1 / op2 if op2 != 0 else "DIVISION BY ZERO",
        '^': lambda: op1 ** op2
    }
    return switch_dict.get(operator, lambda: "INVALID OPERATOR!")()

def EvalPostfix(expr):
    stack = []

    for token in expr.split():
        if token.replace('.', '', 1).isdigit():  # allows floats
            stack.append(float(token))
        elif token in operators:
            if len(stack) < 2:
                raise ValueError("INSUFFICIENT OPERANDS IN EXPRESSION!")

            op1 = stack.pop()
            op2 = stack.pop()
            result = switch(token, op2, op1)

            if isinstance(result, str):
                raise ValueError(result)  # Handle division by zero 

            stack.append(result)
        else:
            raise ValueError(f"INVALID TOKEN {token}")

    if len(stack) != 1:
        raise ValueError("INVALID POSTFIX EXPRESSION. (MISSING AN OPERATOR)")

    return stack[0]


def EvalPrefix(expr):
    stack = []

    for token in reversed(expr.split()):
        if token.replace('.', '', 1).isdigit():
            stack.append(float(token))
        elif token in operators:
            if len(stack) < 2:
                raise ValueError("INSUFFICIENT OPERANDS IN EXPRESSION!")

            op1 = stack.pop()
            op2 = stack.pop()
            result = switch(token, op1, op2)

            if isinstance(result, str):
                raise ValueError(result)  # Handle division by zero 

            stack.append(result)
        else:
            raise ValueError(f"INVALID TOKEN {token}")

    if len(stack) != 1:
        raise ValueError("INVALID PREFIX EXPRESSION. (MISSING AN OPERATOR)")

    return stack[0]


if __name__ == "__main__":
    expr = input("ENTER AN EXPRESSION: ").strip()
    tokens = expr.split()
    try:
        print("RESULT:", EvalPrefix(expr) if tokens[0] in operators else EvalPostfix(expr))
    except ValueError as e:
        print("ERROR:", e)
