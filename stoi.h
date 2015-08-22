#ifndef __STOI_H__
#define __STOI_H__
#include<string>

#define _0 48
#define _9 57
#define _A 65
#define _Z 90
#define _a 97
#define _z 122

int ctoi(int c)
{
	if( c >= int(_a) && c <= int(_z) ) return c - (_a) + 10;
	else if( c >= int(_A) && c <= int(_Z) ) return c - (_A) + 10;
	else if( c >= int(_0) && c <= int(_9) ) return c - (_0);
	else return -1;
}

int stoi(std::string const & s, int base)
{
	int value = 0;
	for(int i = 0; i < s.size(); ++i)
		value = value * base + ctoi( s[i] );
	return value;
}

#endif//__STOI_H__
