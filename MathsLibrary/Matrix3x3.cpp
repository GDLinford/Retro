#include <cmath>
#include "Matrix3x3.h"
#include "Vector3D.h"

Matrix3x3::Matrix3x3()
{
	m_matrixValues[0] = 0.0f;
	m_matrixValues[1] = 0.0f;
	m_matrixValues[2] = 0.0f;

	m_matrixValues[3] = 0.0f;
	m_matrixValues[4] = 0.0f;
	m_matrixValues[5] = 0.0f;

	m_matrixValues[6] = 0.0f;
	m_matrixValues[7] = 0.0f;
	m_matrixValues[8] = 0.0f;
}


Matrix3x3::Matrix3x3(const float a_fm11, const float a_fm12, const float a_fm13,
	const float a_fm21, const float a_fm22, const float a_fm23,
	const float a_fm31, const float a_fm32, const float a_fm33)
{
	    m_matrixValues[0] = a_fm11, m_matrixValues[1] = a_fm12, m_matrixValues[2] = a_fm13,
		m_matrixValues[3] = a_fm21, m_matrixValues[4] = a_fm22, m_matrixValues[5] = a_fm23,
		m_matrixValues[6] = a_fm31, m_matrixValues[7] = a_fm32, m_matrixValues[8] = a_fm33;
}

Matrix3x3::Matrix3x3(const float* a_fpm33Values)
{
	for (int t = 0; t < 9; ++t) {
		m_matrixValues[t] = a_fpm33Values[t];
	}
}

//static functions
const Matrix3x3 Matrix3x3::Identity() 
{

	Matrix3x3 newMatrixIdentity;

	newMatrixIdentity.m_matrixValues[0] = 1;
	newMatrixIdentity.m_matrixValues[1] = 0;
	newMatrixIdentity.m_matrixValues[2] = 0;
	newMatrixIdentity.m_matrixValues[3] = 0;
	newMatrixIdentity.m_matrixValues[4] = 1;
	newMatrixIdentity.m_matrixValues[5] = 0;
	newMatrixIdentity.m_matrixValues[6] = 0;
	newMatrixIdentity.m_matrixValues[7] = 0;
	newMatrixIdentity.m_matrixValues[8] = 1;
	
	return newMatrixIdentity;

}

//Getters and Setters
const Vector3D Matrix3x3::GetRow(const int a_irowNumber) const
{
	if (a_irowNumber == 0) 
	{
		return Vector3D(m_matrixValues[0], m_matrixValues[1], m_matrixValues[2]);
	}

	else if (a_irowNumber == 1) 
	{
		return Vector3D(m_matrixValues[3], m_matrixValues[4], m_matrixValues[5]);
	}

	else if (a_irowNumber == 2) 
	{
		return Vector3D(m_matrixValues[6], m_matrixValues[7], m_matrixValues[8]);
	}

	return Vector3D();

	
}

void Matrix3x3::SetRow(const int a_irowNumber, const Vector3D & a_rowvalues) 
{

	//doing something like above is tough/impossible due to this not using vector at the void
	//meaning an error will appear if i try to use vector 3
	//perhaps a switch statement?



	switch (a_irowNumber) 
	{
	case 0:
		m_matrixValues[0] = a_rowvalues[0], m_matrixValues[1] = a_rowvalues[1], m_matrixValues[2] = a_rowvalues[2];
		break;

	case 1:
		m_matrixValues[3] = a_rowvalues[0], m_matrixValues[4] = a_rowvalues[1], m_matrixValues[5] = a_rowvalues[2];
		break;

	case 2:
		m_matrixValues[6] = a_rowvalues[0], m_matrixValues[7] = a_rowvalues[1], m_matrixValues[8] = a_rowvalues[2];
		break;

	}
	
	
}

//Rotations
const Matrix3x3 Matrix3x3::RotateX(const float a_ftheta) const 
{
	//Top row of Matrix is X 
	//would the code here be something like
	//m_matrixValues[0] = a_ftheta
	//taking the three top row values [0], [1], [2]
	//and putting them in a list or Array using a_ftheta
	
	//[1, 0, 0] 
	//[0, cos(a_ftheta), -sin(a_ftheta)]
	//[0, sin(a_ftheta), cos(a_ftheta)] ;

	const float co = cos(a_ftheta);
	const float si = sin(a_ftheta);

	return *this * Matrix3x3(
		1.0f, 0.0f, 0.0f,
		0.0f, co, -si,
		0.0f, si, co
	);
}
const Matrix3x3 Matrix3x3::RotateY(const float a_ftheta) const
{
	//Middle Row is Y


	//[cos(a_ftheta), 0, sin(a_ftheta)]
	//[0, 1, 0]
	//[-sin(a_ftheta), 0, cos(a_ftheta)];

	const float co = cos(a_ftheta);
	const float si = sin(a_ftheta);

	return *this * Matrix3x3(
		co, 0.0f, si,
		0.0f, 1.0f, 0.0f,
		-si, 0.0f, co
	);

}
const Matrix3x3 Matrix3x3::RotateZ(const float a_ftheta) const
{
	

	//[cos(a_ftheta), -sin(a_ftheta), 0]
	//[sin(a_ftheta), cos(a_ftheta), 0]
	//[0, 0, 1] ;

	const float co = cos(a_ftheta);
	const float si = sin(a_ftheta);

	return *this * Matrix3x3(
		co, -si, 0.0f,
		si, co, 0.0f,
		0.0f, 0.0f, 1.0f
	);
}

//Overloaded Operators

const Matrix3x3 Matrix3x3::operator+(const Matrix3x3& a_other) const 
{
	Matrix3x3 newMatrixAdding;

	(newMatrixAdding.m_matrixValues[0] + a_other[0]);
	(newMatrixAdding.m_matrixValues[1] + a_other[1]);
	(newMatrixAdding.m_matrixValues[2] + a_other[2]);
	(newMatrixAdding.m_matrixValues[3] + a_other[3]);
	(newMatrixAdding.m_matrixValues[4] + a_other[4]);
	(newMatrixAdding.m_matrixValues[5] + a_other[5]);
	(newMatrixAdding.m_matrixValues[6] + a_other[6]);
	(newMatrixAdding.m_matrixValues[7] + a_other[7]);
	(newMatrixAdding.m_matrixValues[8] + a_other[8]);

	return newMatrixAdding;
}
void Matrix3x3::operator+=(const Matrix3x3& a_other) 
{
	m_matrixValues[0] += a_other.m_matrixValues[0];
	m_matrixValues[1] += a_other.m_matrixValues[1];
	m_matrixValues[2] += a_other.m_matrixValues[2];
	m_matrixValues[3] += a_other.m_matrixValues[3];
	m_matrixValues[4] += a_other.m_matrixValues[4];
	m_matrixValues[5] += a_other.m_matrixValues[5];
	m_matrixValues[6] += a_other.m_matrixValues[6];
	m_matrixValues[7] += a_other.m_matrixValues[7];
	m_matrixValues[8] += a_other.m_matrixValues[8];
}
const Matrix3x3 Matrix3x3::operator-(const Matrix3x3& a_other) const
{
	Matrix3x3 newMatrixSub;

	newMatrixSub.m_matrixValues[0] - a_other.m_matrixValues[0],
	newMatrixSub.m_matrixValues[1] - a_other.m_matrixValues[1],
	newMatrixSub.m_matrixValues[2] - a_other.m_matrixValues[2],
	newMatrixSub.m_matrixValues[3] - a_other.m_matrixValues[3],
	newMatrixSub.m_matrixValues[4] - a_other.m_matrixValues[4],
	newMatrixSub.m_matrixValues[5] - a_other.m_matrixValues[5],
	newMatrixSub.m_matrixValues[6] - a_other.m_matrixValues[6],
	newMatrixSub.m_matrixValues[7] - a_other.m_matrixValues[7],
	newMatrixSub.m_matrixValues[8] - a_other.m_matrixValues[8];

	return newMatrixSub;
}
void Matrix3x3::operator-=(const Matrix3x3& a_other)
{
	m_matrixValues[0] -= a_other.m_matrixValues[0];
	m_matrixValues[1] -= a_other.m_matrixValues[1];
	m_matrixValues[2] -= a_other.m_matrixValues[2];
	m_matrixValues[3] -= a_other.m_matrixValues[3];
	m_matrixValues[4] -= a_other.m_matrixValues[4];
	m_matrixValues[5] -= a_other.m_matrixValues[5];
	m_matrixValues[6] -= a_other.m_matrixValues[6];
	m_matrixValues[7] -= a_other.m_matrixValues[7];
	m_matrixValues[8] -= a_other.m_matrixValues[8];

	
}
const Matrix3x3 Matrix3x3::operator*(const Matrix3x3& a_other) const
{
	Matrix3x3 newMatrixTimes;
	//Top Left
	newMatrixTimes.m_matrixValues[0] * a_other[0] + newMatrixTimes.m_matrixValues[1] * a_other[3] + newMatrixTimes.m_matrixValues[2] * a_other[6],
	//Top Middle																																 
	newMatrixTimes.m_matrixValues[0] * a_other[1] + newMatrixTimes.m_matrixValues[1] * a_other[4] + newMatrixTimes.m_matrixValues[2] * a_other[7],
	//Top Right																																	 
	newMatrixTimes.m_matrixValues[0] * a_other[2] + newMatrixTimes.m_matrixValues[1] * a_other[5] + newMatrixTimes.m_matrixValues[2] * a_other[8],
	//Middle Left																																 
	newMatrixTimes.m_matrixValues[3] * a_other[0] + newMatrixTimes.m_matrixValues[4] * a_other[3] + newMatrixTimes.m_matrixValues[5] * a_other[6],
	//Centre																																	 
	newMatrixTimes.m_matrixValues[3] * a_other[1] + newMatrixTimes.m_matrixValues[4] * a_other[4] + newMatrixTimes.m_matrixValues[5] * a_other[7],
	//middle Right																																 
	newMatrixTimes.m_matrixValues[3] * a_other[2] + newMatrixTimes.m_matrixValues[4] * a_other[5] + newMatrixTimes.m_matrixValues[5] * a_other[8],
	//Bottom Left																																 
	newMatrixTimes.m_matrixValues[6] * a_other[0] + newMatrixTimes.m_matrixValues[7] * a_other[3] + newMatrixTimes.m_matrixValues[8] * a_other[6],
	//Bottom Middle																																 
	newMatrixTimes.m_matrixValues[6] * a_other[1] + newMatrixTimes.m_matrixValues[7] * a_other[4] + newMatrixTimes.m_matrixValues[8] * a_other[7],
	//Bottom Right
	newMatrixTimes.m_matrixValues[6] * a_other[2] + newMatrixTimes.m_matrixValues[7] * a_other[5] + newMatrixTimes.m_matrixValues[8] * a_other[8];
	
	return newMatrixTimes;
}
void Matrix3x3::operator*=(const Matrix3x3& a_other)
{
	//Top Left			
	(m_matrixValues[0] *= a_other[0]) + (m_matrixValues[1] *= a_other[3]) + (m_matrixValues[2] *= a_other[6]),
	 //Top Middle																							 
	(m_matrixValues[0] *= a_other[1]) + (m_matrixValues[1] *= a_other[4]) + (m_matrixValues[2] *= a_other[7]),
	 //Top Right																							 
	(m_matrixValues[0] *= a_other[2]) + (m_matrixValues[1] *= a_other[5]) + (m_matrixValues[2] *= a_other[8]),
	 //Middle Left																							 
	(m_matrixValues[3] *= a_other[0]) + (m_matrixValues[4] *= a_other[3]) + (m_matrixValues[5] *= a_other[6]),
	 //Centre																								 
	(m_matrixValues[3] *= a_other[1]) + (m_matrixValues[4] *= a_other[4]) + (m_matrixValues[5] *= a_other[7]),
	 //middle Right																							 
	(m_matrixValues[3] *= a_other[2]) + (m_matrixValues[4] *= a_other[5]) + (m_matrixValues[5] *= a_other[8]),
	 //Bottom Left																							 
	(m_matrixValues[6] *= a_other[0]) + (m_matrixValues[7] *= a_other[3]) + (m_matrixValues[8] *= a_other[6]),
	 //Bottom Middle																						 
	(m_matrixValues[6] *= a_other[1]) + (m_matrixValues[7] *= a_other[4]) + (m_matrixValues[8] *= a_other[7]),
	 //Bottom Right	
	(m_matrixValues[6] *= a_other[2]) + (m_matrixValues[7] *= a_other[5]) + (m_matrixValues[8] *= a_other[8]);
}
const Matrix3x3 Matrix3x3::operator*(const float& a_other) const 
{

	return Matrix3x3
	(
		m_matrixValues[0] * a_other,
		m_matrixValues[1] * a_other,
		m_matrixValues[2] * a_other,

		m_matrixValues[3] * a_other,
		m_matrixValues[4] * a_other,
		m_matrixValues[5] * a_other,

		m_matrixValues[6] * a_other,
		m_matrixValues[7] * a_other,
		m_matrixValues[8] * a_other
	);
}

void Matrix3x3::operator*=(const float& a_other)
{
	m_matrixValues[0] *= a_other;
	m_matrixValues[1] *= a_other;
	m_matrixValues[2] *= a_other;
	m_matrixValues[3] *= a_other;
	m_matrixValues[4] *= a_other;
	m_matrixValues[5] *= a_other;
	m_matrixValues[6] *= a_other;
	m_matrixValues[7] *= a_other;
	m_matrixValues[8] *= a_other;

}

const bool Matrix3x3::operator==(const Matrix3x3& a_other) const 
{

	
	return 
	m_matrixValues[0] == a_other.m_matrixValues[0] && m_matrixValues[1] == a_other.m_matrixValues[1] && m_matrixValues[2] == a_other.m_matrixValues[2] &&
	m_matrixValues[3] == a_other.m_matrixValues[3] && m_matrixValues[4] == a_other.m_matrixValues[4] && m_matrixValues[5] == a_other.m_matrixValues[5] &&
	m_matrixValues[6] == a_other.m_matrixValues[6] && m_matrixValues[7] == a_other.m_matrixValues[7] && m_matrixValues[8] == a_other.m_matrixValues[8];

}

const bool Matrix3x3::operator!=(const Matrix3x3& a_other) const 
{
	return m_matrixValues[0] != a_other.m_matrixValues[0] && m_matrixValues[1] != a_other.m_matrixValues[1] && m_matrixValues[2] != a_other.m_matrixValues[2] &&
		m_matrixValues[3] != a_other.m_matrixValues[3] && m_matrixValues[4] != a_other.m_matrixValues[4] && m_matrixValues[5] != a_other.m_matrixValues[5] &&
		m_matrixValues[6] != a_other.m_matrixValues[6] && m_matrixValues[7] != a_other.m_matrixValues[7] && m_matrixValues[8] != a_other.m_matrixValues[8];
}

const float Matrix3x3::operator[](const int i) const 
{
	return m_matrixValues[i];
}

