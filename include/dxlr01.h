/*
 * @Author: Y.Y. Daniel 626986815@qq.com
 * @Date: 2024-07-17 16:49:14
 * @LastEditors: Y.Y. Daniel 626986815@qq.com
 * @LastEditTime: 2024-07-18 16:23:08
 * @FilePath: /dxlr01_controller/include/dxlr01.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef DXLR01_H
#define DXLR01_H

#include <stdint.h>
#include <string.h>
#define DX_LR01_CONFIG_SERIAL_BAUD_1200 1
#define DX_LR01_CONFIG_SERIAL_BAUD_2400 2
#define DX_LR01_CONFIG_SERIAL_BAUD_4800 3
#define DX_LR01_CONFIG_SERIAL_BAUD_9600 4
#define DX_LR01_CONFIG_SERIAL_BAUD_19200 5
#define DX_LR01_CONFIG_SERIAL_BAUD_38400 6
#define DX_LR01_CONFIG_SERIAL_BAUD_57600 7
#define DX_LR01_CONFIG_SERIAL_BAUD_115200 8
#define DX_LR01_CONFIG_SERIAL_BAUD_128000 9
#define DX_LR01_CONFIG_SERIAL_STOP_1 0      // 1停止位
#define DX_LR01_CONFIG_SERIAL_STOP_2 1      // 2停止位
#define DX_LR01_CONFIG_SERIAL_PARI_NULL 0   // 无校验位
#define DX_LR01_CONFIG_SERIAL_PARI_ODD 1    // 奇校验位
#define DX_LR01_CONFIG_SERIAL_PARI_EVEN 2   // 偶校验位

#define DX_LR01_CONFIG_MODE_TRANSPARENT 0   // 透明传输
#define DX_LR01_CONFIG_MODE_FIXEDPOINT 1    // 定点传输
#define DX_LR01_CONFIG_MODE_BROADCAST 2     // 广播
#define DX_LR01_CONFIG_SLEEP_SLEEP 0        // 休眠模式
#define DX_LR01_CONFIG_SLEEP_AIRWAKE 1      // 空中唤醒模式
#define DX_LR01_CONFIG_SLEEP_ACTIVE 2       // 高时效模式

class DX_LR01 {
private:
    /**
     * @brief 打开串口的回调函数。请在回调函数内自行设置其他的错误调试信息处理或输出方式。
     * @param serialPath 串口文件位置，例如/dev/ttyUSB0。
     * @param speed 串口波特率
     * @retval 0 串口成功打开
     * @retval -1 串口无法打开
     */
    int (*openSerial)(char* serialPath, int speed);
    /**
     * @brief 关闭串口的回调函数。
     * @retval 0 成功关闭
     * @retval -1 串口已经被关闭
     */
    int (*closeSerial)();
    /**
     * @brief 从串口中读取特定数量的字符。
     * @param buffer 缓冲区，用于存储读取到的字符。
     * @param size 需要读取的字节数。
     * @retval >=0 实际读取到的字节数
     * @retval <0 读取失败
     */
    int (*readSerial)(char* buffer, uint32_t size);
    /**
     * @brief 向串口中写入特定数量的字符。
     * @param buffer 待写入的数据。
     * @param size 需要写入的字节数。
     * @retval >=0 实际写入的字节数
     * @retval <0 写入失败
     */
    int (*writeSerial)(char* buffer, uint32_t size);
    bool serialTest();
    uint8_t mode;
    bool isSerialOpen;
    
public:
    DX_LR01(char* serialPath, int serialSpeed, 
            int (*openSerialCallback)(char* serialPath, int speed), 
            int (*closeSerialCallback)(), 
            int (*readSerialCallback)(char* buffer, uint32_t size), 
            int (*writeSerialCallback)(char* buffer, uint32_t size)
    );
    ~DX_LR01();
    bool isOpen();

    int setMode(uint8_t mode);
    int setSleepOption(uint8_t sleep);
    int setLevel(uint8_t level);
    int setChannel(uint8_t channel);
    int setPower(uint8_t power);
    int setCodingRate(uint8_t cr);
    int setSpreadingFactor(uint8_t sf);
    int setCRC(bool isOn);
    int setIQ(bool isOn);

    int setSerialBaud(uint8_t baud);
    int setSerialStop(uint8_t stop);
    int setSerialPari(uint8_t pari);
};

#endif