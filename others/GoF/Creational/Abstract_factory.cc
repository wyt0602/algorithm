/*************************************************************************
 *抽象工厂模式：提供一个创建一系列相关或相互依赖对象的接口，而无需指定
 *		他们具体的类。
 *（1）便于交换产品系类
 *（2）利用反射可以配置各种系列产品而不需要修改客户端
 *
 * ***********************************************************************
 */

class MethodA {};
class MethodA1 : public MethodA {};
class MethodA2 : public MethodA {};

class MethodB {};
class MethodB1 : public MethodB {};
class MethodB2 : public MethodB {};

...

class Factory {
    getMethodA();
    getMethodB();
    getMethodC();
};
class Factory1 : public Factory{
    getMethodA() {return new methodA1};
    getMethodB() {return new methodB1};
    getMethodC();
};

class Factory2 : public Factory{
    getMethodA() {return new methodA2};
    getMehtodB() {return new methodB2};
    getMethodC();
};


