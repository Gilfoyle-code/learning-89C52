#ifndef __AT1402_H__
#define __AT1402_H__

void AT24C02_WriteByte(unsigned char WordAddress, unsigned char Data);
unsigned char AT24C02_ReadByte(unsigned char WordAddress);

#endif