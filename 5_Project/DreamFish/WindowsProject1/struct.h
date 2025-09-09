#pragma once

#include <assert.h>
#include <windows.h>
#include <math.h>

struct Vecor2
{
	float x;
	float y;

public:
	float Length()
	{
		return (float)(sqrt(x * x + y * y));
	}

	Vecor2& Normalize()
	{
		float fLen = Length();
		assert(fLen != 0.f);

		x /= fLen;
		y /= fLen;

		return *this;
	}

public:
	Vecor2& operator = (POINT _pt)
	{
		x = (float)_pt.x;
		y = (float)_pt.y;
	}

	void operator += (Vecor2 _vOther)
	{
		x += _vOther.x;
		y += _vOther.y;
	}

	Vecor2 operator + (Vecor2 _vOther)
	{
		return Vecor2(x + _vOther.x, y + _vOther.y);
	}
	
	Vecor2 operator - (Vecor2 _vOther)
	{
		return Vecor2(x - _vOther.x, y - _vOther.y);
	}
	
	Vecor2 operator * (int _i)
	{
		return Vecor2(x * _i, y * _i);
	}

	Vecor2 operator * (float _f)
	{
		return Vecor2(x * _f, y * _f);
	}
	
	Vecor2 operator / (Vecor2 _vOther)
	{
		assert(!(0.f == _vOther.x || 0.f == _vOther.y));
		return Vecor2(x / _vOther.x, y / _vOther.y);
	}
	Vecor2 operator / (float _f)
	{
		assert(!(0.f == _f));
		return Vecor2(x / _f, y / _f);
	}
	
	
	

public:
	Vecor2()
		: x(0.f), y(0.f)
	{}

	Vecor2(float _x, float _y)
		: x(_x), y(_y)
	{}

	Vecor2(int _x, int _y)
		: x((float)_x), y((float)_y)
	{}

	Vecor2(const POINT _pt)
		:x((float)_pt.x)
		, y((float)_pt.y)
	{}
};