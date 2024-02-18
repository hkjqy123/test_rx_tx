#include <Arduino.h>
#include "yqj_lei_da.h"




yqj_lei_da::yqj_lei_da(/* args */)
{
    Serial1.begin(256000, SERIAL_8N1, 16, 17);
}

yqj_lei_da::~yqj_lei_da()
{
}
void yqj_lei_da::serial_red()
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
                        // Serial.printf ("数据帧长度 = %u\n", yqj_l);
                        yqj_s.length = yqj_l;
                        if (yqj_l = 13)
                        {                          
                        for (size_t i = 0; i < yqj_l; i++)
                        {
                            yqj_s.l1[i] = (unsigned char)Serial1.read();// 循环存储数据帧
                        }
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

void yqj_lei_da::setup_lei_da ()
{
    //目标状态
    switch (yqj_s.l1[2])
    {
    case 0X00:
        yqj_s.mu_biao_zhuang_tai ="无人";
        break;
    case 0X01:
        yqj_s.mu_biao_zhuang_tai ="运动";
        break;
    case 0X02:
        yqj_s.mu_biao_zhuang_tai ="静止";
        break;
    case 0X03:
        yqj_s.mu_biao_zhuang_tai ="运动&静止";
        break;
    default:
        break;
    }
    yqj_s.yun_dong_mu_biao_ju_li = yqj_s.l1[4]<<8 |yqj_s.l1[3];
    yqj_s.yun_dong_mu_biao_neng_liang = yqj_s.l1[5];
    yqj_s.jin_zhi_mu_biao_ju_li = yqj_s.l1[7]<<8 | yqj_s.l1[6];
    yqj_s.jin_zhi_mu_biao_neng_liang = yqj_s.l1[8];
    yqj_s.tan_ce_ju_li = yqj_s.l1[10]<<8 | yqj_s.l1[9];
 
}