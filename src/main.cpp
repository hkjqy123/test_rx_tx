#include <Arduino.h>
void setup()
{
    Serial1.begin(256000, SERIAL_8N1, 16, 17);
    Serial.begin(115200);
}

// 定义数据结构用于保存数据
struct Student {
    u_int length;
    unsigned char l1[13]; 
} ;
Student yqj_s;

;
void loop()
{

    //   从串口缓冲读取数据拼接为字符串并清空串口缓冲
    while (Serial1.available())
    {
        unsigned char in = (unsigned char)Serial1.read(); // read读取
        switch (in)
        {
        case 0XF4:                              // 判断帧头第一字节数据
            in = (unsigned char)Serial1.read(); // 读取帧头第二字节数据
            if (in == 0xf3)
            {
                in = (unsigned char)Serial1.read(); // 读取帧头第三字节数据
                if (in == 0xf2)
                {
                    in = (unsigned char)Serial1.read(); // 读取帧头第四字节数据/
                    if (in == 0xf1)
                    {
                        unsigned char l1[1] = {0}; // 清空长度数组
                        l1[0] = (unsigned char)Serial1.read();
                        l1[1] = (unsigned char)Serial1.read();
                        u_int yqj_l = l1[1] << 8 | l1[0];
                        Serial.printf ("数据帧长度 = %u\n", yqj_l);
                        yqj_s.length = yqj_l;
                        for (size_t i = 0; i <  yqj_l; i++)
                        {
                            yqj_s.l1[i] = (unsigned char)Serial1.read();// 循环存储数据帧
                        }
                        
                    }
                }
            }

            break;

        default:
            break;
        }
    }
}