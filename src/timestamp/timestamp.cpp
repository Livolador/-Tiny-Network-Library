#include "timestamp.hpp"

using std::string;
using std::time_t;

Timestamp::Timestamp() : microSecondsSinceEpoch(0) {

}
Timestamp::Timestamp(int64_t _microSecondsSinceEpoch) 
    : microSecondsSinceEpoch(_microSecondsSinceEpoch) {

}
Timestamp Timestamp::now() {
    return Timestamp(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
}
string Timestamp::toString() const {
    char timeBuffer[20];
    // 获取当前时间按ms
    tm* localTime = localtime(&microSecondsSinceEpoch);
    snprintf(timeBuffer, 20, "%4d/%02d/%02d %02d:%02d:%02d",// %02不足两位的时候前面加0
        localTime -> tm_year + 1900, // 1900年开始计数的所以需要加1900
        localTime -> tm_mon + 1, // 0代表一月 
        localTime -> tm_mday,
        localTime -> tm_hour,
        localTime -> tm_min,
        localTime -> tm_sec);

    return timeBuffer;
}


// struct tm{
//    int tm_sec;       /* 秒 – 取值区间为[0,59] 
//    int tm_min;       /* 分 - 取值区间为[0,59] 
//    int tm_hour;      /* 时 - 取值区间为[0,23] 
//    int tm_mday;     /* 一个月中的日期 - 取值区间为[1,31] 
//    int tm_mon;     /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] 
//    int tm_year;     /* 年份，其值等于实际年份减去1900 
//    int tm_wday;    /* 星期 – 取值区间为[0,6]，其中0代表星期天，1代表星期一 
//    int tm_yday;    /* 从每年1月1日开始的天数– 取值区间[0,365]，其中0代表1月1日 
//    int tm_isdst;    /* 夏令时标识符，夏令时tm_isdst为正；不实行夏令时tm_isdst为0 */  
// };
