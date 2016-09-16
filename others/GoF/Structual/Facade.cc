/***************************************************************************************
 *外观模式：位子系统中的一组接口提供一个一致的界面，此模式定义了一个高层接口，这个接口
 *          使得这一子系统更加容易使用。
 *（1）首先，在设计初期阶段，应该要有意识地将不同的两个层分离，层与层之间建立外观模式。
 *（2）其次，在开发阶段，子系统往往因为不断地重构演化而变得越来越复杂，增加facade可以
 *     提供一个简单的接口，减少它们之间的依赖。
 *（3）在维护一个遗留的大型系统时，可能这个系统已经非常难以维护和扩展了，为新的系统开发
 *     一个外观类，来提供设计粗糙或高度复杂的遗留代码的比较清晰简单的接口，让新系统与
 *     facade对象交互，Facade与遗留代码交互所有复杂的工作。
 *
 * *************************************************************************************
 */
