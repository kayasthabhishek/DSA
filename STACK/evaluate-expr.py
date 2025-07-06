operators = "+-*/^"

def EvalPostfix(expr):
    stack = []

    for token in expr.split():
        if token not in operators:
            stack.append(float(token))
        else:
            op1 = stack.pop()
            op2 = stack.pop()

            match token:
                case '+': result = op2 + op1
                case '-': result = op2 - op1
                case '*': result = op2 * op1
                case '/': result = op2 / op1
                case '^': result = op2 ** op1

            stack.append(result)

    return stack[0]

def EvalPrefix(expr):
    stack = []

    for token in reversed(expr.split()):
        if token.replace('.', '', 1).isdigit():
            stack.append(float(token))
        elif token in operators:
            op1 = stack.pop()
            op2 = stack.pop()

            match token:
                case '+': result = op1 + op2
                case '-': result = op1 - op2
                case '*': result = op1 * op2
                case '/': result = op1 / op2
                case '^': result = op1 ** op2

            stack.append(result)
        else:
            raise ValueError(f"INVALID TOKEN: '{token}'")

    if len(stack) != 1:
        raise ValueError("INVALID PREFIX EXPRESSION")

    return stack[0]

if __name__ == "__main__":
    expr = input("ENTER WELL SPACED EXPRESSION (e.g. 4 3 + 5 *): ").strip()
    tokens = expr.split()

    print(f'RESULT = {EvalPrefix(expr) if tokens[0] in operators else EvalPostfix(expr)}') 

