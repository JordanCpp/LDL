#ifndef LDL_Low_Mat4_hpp
#define LDL_Low_Mat4_hpp

class LDL_Mat4f
{
public:
	LDL_Mat4f()
	{
		Identity();
	}

	float* Values()
	{
		return _Values;
	}

	void Identity()
	{
		_Values[0]  = 1;
		_Values[1]  = 0;
		_Values[2]  = 0;
		_Values[3]  = 0;
		_Values[4]  = 0;
		_Values[5]  = 1;
		_Values[6]  = 0;
		_Values[7]  = 0;
		_Values[8]  = 0;
		_Values[9]  = 0;
		_Values[10] = 1;
		_Values[11] = 0;
		_Values[12] = 0;
		_Values[13] = 0;
		_Values[14] = 0;
		_Values[15] = 1;
	}

	float _Values[16];
};

LDL_Mat4f LDL_Orthof(float left, float right, float bottom, float top, float farv, float nearv);

#endif
