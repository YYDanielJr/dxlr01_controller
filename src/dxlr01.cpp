/*
 * @Author: Y.Y. Daniel 626986815@qq.com
 * @Date: 2024-07-17 16:50:36
 * @LastEditors: Y.Y. Daniel 626986815@qq.com
 * @LastEditTime: 2024-07-20 15:09:18
 * @FilePath: /dxlr01_controller/src/dxlr01.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "dxlr01.h"

/**
 * @brief 串口测试函数。内部函数，不可被外部调用。
 */
bool DX_LR01::serialTest() {
    writeSerial("+++\r\n", 5);
    char buffer[10] = {0};
    readSerial(buffer, 7);
    if(strcmp(buffer, "Entry AT") == 0) {
        writeSerial("+++\r\n", 5);
        return true;
    }
    return false;
}

/**
 * @brief 构造DX_LR01对象
 * 请在构造对象时使用try...catch环绕，构造函数会在构造不成功时丢出int类型错误信息。
 * 传入的四个回调函数返回值详见对应回调函数的注释。
 * @param serialPath 串口文件路径，例如/dev/ttyUSB0
 * @param serialSpeed 波特率
 * @param openSerialCallback 打开串口的回调函数，传入串口文件路径和波特率
 * @param closeSerialCallback 关闭串口的回调函数
 * @param readSerialCallback 读取串口的回调函数，传入缓冲区和读取字符数
 * @param writeSerialCallback 写入串口的回调函数，传入缓冲区和写入字符数
 * @retval -1 无法打开串口
 * @retval -2 串口成功打开，但无法进行通信。有可能是串口设置问题，或者没有连接正确的模块。
 */
DX_LR01::DX_LR01(char *serialPath, int serialSpeed) {
    if(openSerial(serialPath, serialSpeed) == 0) {
        if(!serialTest()) {
            throw -2;
        }
    } else {
        throw -1;
    }
    isSerialOpen = true;
}

/**
 * @brief 析构DX_LR01对象。
 * 请在析构对象时使用try...catch环绕，析构函数会在析构不成功时丢出int类型错误信息。
 * @retval -1 串口已经被关闭
 * @retval -2 串口因其他原因无法关闭
 */
DX_LR01::~DX_LR01() {
    if(!isSerialOpen) {
        throw -1;
    }
    if(closeSerial() != 0) {
        throw -2;
    }
}

bool DX_LR01::isOpen() {
    return isSerialOpen & serialTest();
}
