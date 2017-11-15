//获取三轴加速度值，默认的范围±1.5g

#include <MMA7660.h>

MMA7660 accelemeter;

void setup()
{
    Serial.begin(115200);
    accelemeter.init();   // 初始化
}
void loop()
{
    int8_t x;
    int8_t y;
    int8_t z;
    float ax,ay,az;
    accelemeter.getXYZ(&x,&y,&z);        // 得到未处理的三轴值

    Serial.print("x = ");
    Serial.println(x);
    Serial.print("y = ");
    Serial.println(y);
    Serial.print("z = ");
    Serial.println(z);

    accelemeter.getAcceleration(&ax,&ay,&az);    // 转化为单位g的加速度值
    Serial.println("accleration of X/Y/Z: ");
    Serial.print(ax);
    Serial.println(" g");
    Serial.print(ay);
    Serial.println(" g");
    Serial.print(az);
    Serial.println(" g");
    Serial.println("*************");
    delay(500);
}
