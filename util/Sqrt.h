/**
 * @file Sqrt.h
 * @Brief  sqrt implementation (impressive)
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-07-01
 */

#ifndef INV_SQRT_H_
#define INV_SQRT_H_

float InvSqrt(float x)
{
    float xhalf = 0.5f*x;
    int i = *(int*)&x; // get bits for floating VALUE 
    i = 0x5f375a86- (i>>1); // gives initial guess y0
    x = *(float*)&i; // convert bits BACK to float
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy

    return 1/x;
}

#endif
