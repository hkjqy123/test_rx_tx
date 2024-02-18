#include <Arduino.h>
class yqj_lei_da
{
private:
    // 定义数据结构用于保存数据
    struct Student
    {
        u_int length;
        unsigned char l1[13];
        String mu_biao_zhuang_tai;
        u_int yun_dong_mu_biao_ju_li;
        u_int yun_dong_mu_biao_neng_liang;
        u_int jin_zhi_mu_biao_ju_li;
        u_int jin_zhi_mu_biao_neng_liang;
        u_int tan_ce_ju_li;
    };
    

public:
    yqj_lei_da(/* args */);
    ~yqj_lei_da();
    void serial_red();
    void setup_lei_da();
    Student yqj_s;

};

