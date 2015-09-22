#ifndef __STOI_H__
#define __STOI_H__
#include<string>
//#include<cstring>

#define c_0 48
#define c_9 57
#define c_A 65
#define c_Z 90
#define c_a 97
#define c_z 122

int ctoi(int c)
{
	if( c >= int(c_a) && c <= int(c_z) ) return c - (c_a) + 10;
	else if( c >= int(c_A) && c <= int(c_Z) ) return c - (c_A) + 10;
	else if( c >= int(c_0) && c <= int(c_9) ) return c - (c_0);
	else return -1;
}

int stoi(char const * s, int size, int base = 10)
{
	int value = 0;
	for(int i = 0; i < size; ++i)
	{
		value *= base;
		value += ctoi( s[i] );
	}
	return value;
}

int parse_s(std::string const & s, int & pos, int & len, int base = 10);
int stoi(std::string const & s, int pos, int len, int base = 10);

int stoi(std::string const & s, int base = 10)
{
	int pos = 0, len = 0;
	if( parse_s(s, pos, len, base) )
		return -1;
	return stoi( s, pos, len, base );
}

//---------- parse 16 ----------//
int parse_16( std::string const & s, int & pos, int & len)
{
	if( s.size() > 2 )
	{
		if( s[0] == '0' && s[1] == 'x' );
		pos = 2; len = 2;
	}
	else
	{
		pos = 0;
		len = 0;
	}
	int v = 0;
	for(; len < s.size(); ++len)
	{
		v = ctoi( s[len] );
		if( v < 0 || v > 0xf )
			break;
	}
	len -= pos;
	return 0;
}

//--------- parse base ---------//
int parse_base(std::string const & s, int & pos, int & len, int base = 10 )
{
	pos = 0; len = 0;
	int v = 0;
	for(; len < s.size(); ++len)
	{
		v = ctoi( s[len] );
		if( v < 0 || v >= base )
			break;
	}
	return 0;
}


//---------- parse s ----------//
int parse_s(std::string const & s, int & pos, int & len, int base )
{
	if( base == 16 )
		return parse_16( s, pos, len );
	return parse_base( s, pos, len, base );
}

int stoi(std::string const & s, int pos, int len, int base )
{
	return stoi( &s[pos], len, base );
}

#endif//__STOI_H__
