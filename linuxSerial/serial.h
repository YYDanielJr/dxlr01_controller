/*
 * @Author: Y.Y. Daniel 626986815@qq.com
 * @Date: 2024-07-17 16:47:52
 * @LastEditors: Y.Y. Daniel 626986815@qq.com
 * @LastEditTime: 2024-07-18 10:43:35
 * @FilePath: /dxlr01_controller/linuxSerial/serial.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _SERIAL_H_
#define _SERIAL_H_

#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

int server_init(int fd);
int setserial(int fd,int nspeed,int nbits,char nevent,int nstop);
void *camera_pthread(void* arg);
int server_socket(unsigned short port,char *ip);

#define SERV_PORT 6666


#endif
