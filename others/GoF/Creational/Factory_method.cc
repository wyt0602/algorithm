/**
 * @file Factory_method.cc
 * @Brief  
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-09-02
 *
 * 工厂方法模式：定义一个用于创建对象的接口，让子类决定实例化哪一个类。工厂方法使一个类的实例化延迟到其子类。
 * （1）有多少个方法就得有多少个工厂。
 * （2）好处是满足了开放-封闭原则，因为工厂类不再有判断，则扩展可以，修改却不可以。
 * （3）但是客户端将会进行判断，可以用反射实现。
 */

