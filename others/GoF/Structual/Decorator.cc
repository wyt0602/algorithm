/********************************************************************************
 *装饰模式：动态地给一个对象添加一些额外的职责，就增加功能来说，装饰模式比生成子
 *          类更为灵活。
 *（1）每个装饰对象的实现就和如何使用这个对象分离开了，每个装饰对象只关心自己的
 *功能，不需要关心如何被添加到对象链当中。
 *（2）当系统需要新功能的时候，是向旧的类中添加新的代码。这些新加的代码通常装饰
 *了原有类的核心职责或主要行为，在主类中加入了新的字段，新的方法和新的逻辑，从而
 *增加了主类的复杂度，而这些新加入的东西仅仅是为了满足一些只在某种特定情况下才会
 *执行的特殊行为的需要。装饰模式提供了一种非常好的解决方案，它把每个要装饰的功能
 *放在单独的类中，并让这个类包装它所要装饰的对象，因此，当需要执行特殊行为时，客
 *户代码就可以在运行时根据需要有选择地、按顺序的使用装饰功能包装的对象了。
 *
 * ******************************************************************************
 */
