#include <Arduino.h>
#include <yqj_lei_da.h>
yqj_lei_da lei_da;
void setup()
{
 Serial.begin(115200);
}




void loop()
{
lei_da.serial_red();
lei_da.setup_lei_da ();
// Serial.println();
Serial.printf("人员状态=%s\n 运动目标距离%dCM 运动目标能量%d 静止目标距离%dCM 静止目标能量%d  距离%d厘米\n",lei_da.yqj_s.mu_biao_zhuang_tai,lei_da.yqj_s.yun_dong_mu_biao_ju_li,lei_da.yqj_s.yun_dong_mu_biao_neng_liang,lei_da.yqj_s.jin_zhi_mu_biao_ju_li,lei_da.yqj_s.jin_zhi_mu_biao_neng_liang,lei_da.yqj_s.tan_ce_ju_li);
delay(1000);
}
