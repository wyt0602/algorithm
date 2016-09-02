/**
 * @file Simple_factory.cc
 * @Brief  
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-09-02
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Operation{
    public:
	virtual int getResult(int op1, int op2) = 0;
};

class OperationAdd : public Operation{
    public:
	virtual int getResult(int op1, int op2) override;
};

int OperationAdd::getResult(int op1, int op2)
{
    return op1 + op2;
}

class OperationSub : public Operation{
    public:
	virtual int getResult(int op1, int op2) override;
};

int OperationSub::getResult(int op1, int op2)
{
    return op1 - op2;
}

class OperationMul : public Operation{
    public:
	virtual int getResult(int op1, int op2) override;
};

int OperationMul::getResult(int op1, int op2)
{
    return op1 * op2;
}

class OperationDiv : public Operation{
    public:
	virtual int getResult(int op1, int op2) override;
};

int OperationDiv::getResult(int op1, int op2)
{
    if (op2 == 0)
	return 0;
    return op1 / op2;
}

class OperationFactory{
    public:
	Operation& getOperator(string op);
};

Operation& getOperator(string op)
{
    if (op == "+")
	return *(new OperationAdd());
    if (op == "-")
	return *(new OperationSub());
    if (op == "*")
	return *(new OperationMul());
    if (op == "/")
	return *(new OperationDiv());

}


int main()
{
    Operation& oper1 = getOperator("+");
    cout << "Add:" << oper1.getResult(2, 1) << endl;
    Operation& oper2 = getOperator("-");
    cout << "Sub:" << oper2.getResult(2, 1) << endl;
    Operation& oper3 = getOperator("*");
    cout << "Mul:" << oper3.getResult(2, 1) << endl;
    Operation& oper4 = getOperator("/");
    cout << "Div:" << oper4.getResult(2, 1) << endl;

    return 0;
}
