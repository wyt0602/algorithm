/********************************************************
 * 题目：
 * 有家动物收容所只收容狗与猫，且严格遵守“先进先出”的原则。
 * 在收养该收容所的动物时，收养人只能收养所有动物中“最老”
 * （根据进入收容所的时间长短）的动物，或者，可以挑选猫或狗
 * （同时必须收养此类动物中“最老”的）。换言之，收养人不能
 * 自由挑选想收养的对象。请创建适用于这个系统的数据结构，
 * 实现各种操作方法，比如enqueue、dequeueAny、dequeueDog和
 * dequeueCat等。
 *
 * 分析：
 * （1）可以创建三个链表：分别代表猫队列，狗队列，综合队列
 * （2）每个列表都将新节点插入到链表尾部
 * （3）猫狗队列严格按照先进先出
 * （4）综合队列按照猫狗队列的变化进行修改，同时如果自己要
 *      出队列，也必须严格按照先进先出
 *
 ********************************************************/ 

typedef enum {
    cat,
    dog
}Animal;

typedef struct Attribute{
    Animal type;
    int number;
    struct Attribute *next;
    struct Attribute *pre;
}Attribute;

typedef struct List{
    Attribute *value;
    struct List next;
}List;

typedef struct System{
    Attribute *any;
    Attribute *any_rear;
    List *cat;
    List *cat_rear;
    List *dog;
    List *dog_rear;
}System;

void system_init(System *system)
{
    if (system == NULL)
	return;
    system->any = NULL;
    system->ana_rear = NULL;
    system->cat = NULL;
    system->cat_rear = NULL;
    system->dog = NULL;
    system->dog_rear = NULL;
}

int enqueue(System *system, Animal type, int number)
{
    if (system == NULL)
	return -1;
    
    Attribute *attr = (Attribute*)malloc(sizeof(Attribute));
    if (attr == NULL)
	return -1;
    attr->type = type;
    attr->number = number;
    attr->next = NULL;
    attr->pre = NULL;

    //insert into any list
    if (system->any_rear != NULL){
	system->any_rear->next = attr;
	attr->pre = system->any_rear;
    }else 
	system->any = attr;
    system->any_rear = attr;

    //insert into cat list
    if (type == cat){
	List *node = (List*)malloc(sizeof(List));
	if (node == NULL)
	    return -1;
	node->value = attr;
	node->next = NULL;

	if (system->cat_rear != NULL)
	    system->cat_rear->next = node;
	else
	    system->cat = node;
	system->cat_rear = node;
    }

    //insert into dog list
    if (type == dog){
	List *node = (List*)malloc(sizeof(List));
	if (node == NULL)
	    return -1;
	node->value = attr;
	node->next = NULL;

	if (system->dog_rear != NULL)
	    system->dog_rear->next = node;
	else
	    system->dog = node;
	system->dog_rear = node;
    }

    return 0;
}

int dequeue_any(System *system, Attribut **attr)
{
    if (!(system && attr))
	return -1;
    *attr = NULL;

    //delete a node from any
    if (system->any != NULL){
	*attr = system->any;
	if (system->any == system->any_rear)
	    system->any_rear = NULL;
	system->any = (*attr)->next;
    }

    //delete a node from cat
    if ((*attr)->type == cat){
	List *temp = system->cat;
	if (system->cat == system->cat_rear)
	    system->cat_rear = NULL;
	system->cat = temp->next;
	free(temp);
    }

    //delete a node from dog
    if ((*attr)->type == dog){
	List *temp = system->dog;
	if (system->dog == system->dog_rear)
	    system->dog_rear = NULL;
	system->dog = temp->next;
	free(temp);
    }

    return 0;
}

int dequeue_dog(System *system, Attribute **attr)
{
}
