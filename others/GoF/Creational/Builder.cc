/****************************************************************************
 *建造者模式：将一个复杂对象的构建与他的表示分离，使得同样的构建过程可以创建
 *	      不同的表示。
 *（1）一个产品可能分为多个部分，可以设计builder类，然后有多个函数可以做这件事
 *（2）同一个类型的产品，可能有不同的表示，通过继承来解决
 *（3）产品的框架都是不变的，因此用一个director类来解决
 *
 *使用环境：建造者模式是在当创建复杂对象的算法应该独立于该对象的组成部分以及
 *          它们的装配方式时适用的模式。
 *
 * **************************************************************************
 */

class Builder{
    public:
	virtual buildPartA() = 0;
	virtual buildPartB() = 0;
	virtual buildPartC() = 0;
};

class ConcreteBuilder1 : public Builder{
    public:
	buildPartA() override;
	buildPartB() override;
	buildPartC() override;
};
class ConcreteBuilder2 : public Builder{
    public:
	buildPartA() override;
	buildPartB() override;
	buildPartC() override;
};


class Director{
    private:
	Builder *b;
    public:
	setBuilder(Builder *pb);
	construct(){
	    b->buildPartA();
	    b->buildPartB();
	    b->buildPartC();
	}
};
