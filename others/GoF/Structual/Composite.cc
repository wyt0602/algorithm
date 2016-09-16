/********************************************************************************
 *组合模式：将对象组合成树形结构以表示‘部分-整体’的层次结构。组合模式使得用户对
 *          单个对象和组合对象的使用具有一致性。
 *
 *（1）需求中是体现部分与整体层次的结构时，以及希望用户可以忽略组合对象与单个对象
 *的不同，统一地使用组合结构中所有对象时，就考虑用组合模式。
 *（2）基本对象可以被组合成更复杂的组合对象，而这个组合对象又可以被组合，这样不断
 *地递归下去，客户代码中，任何用到基本对象的地方都可以使用组合对象了。
 *
 * ******************************************************************************
 */

class Component{
    public:
	virtual void Add(Component c);
	virtual void Remove(Component c);
	virtual void Display();
};

class Leaf : public Component{
    public:
	void Add(Component c) override {}
	void Remove(Component c) override {}
	void Display() override {do something;}
};

class Composite : public Component{
    private:
	list<Comonent> children;
    public:
	void Add(Component c) override {children.push_back(c);}
	void Remove(Component c) override {children.erase(c);}
	void Display() override
	{
	    for (auto i : children){
		i.Display();
	    }
	}
};
