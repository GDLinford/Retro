#include "Vector3D.h"
#include "Vector2D.h"
#include "Matrix3x3.h"
#include <cmath>

Vector3D::Vector3D(float a_x, float a_y, float a_z) {
	m_coordinates[0] = a_x;
	m_coordinates[1] = a_y;
	m_coordinates[2] = a_z;
}

Vector3D::Vector3D(Vector2D a_other) {

	m_coordinates[0] = a_other[0];
	m_coordinates[1] = a_other[1];
	m_coordinates[2] = 0.f;
}

Vector3D::Vector3D()
{
	m_coordinates[0] = 0.f;
	m_coordinates[1] = 0.f;
	m_coordinates[2] = 0.f;
}

const float Vector3D::operator[](const int a_i) const {
	return m_coordinates[a_i];
}

const Vector3D Vector3D::operator*(const float a_other) const {

	Vector3D newCVector3TimeF;

	newCVector3TimeF.m_coordinates[0] * a_other,
	newCVector3TimeF.m_coordinates[1] * a_other,
	newCVector3TimeF.m_coordinates[2] * a_other;

	return newCVector3TimeF;
}

void Vector3D::operator*=(const float a_other) {
	m_coordinates[0] *= a_other;
	m_coordinates[1] *= a_other;
	m_coordinates[2] *= a_other;
}

const Vector3D Vector3D::operator*(const Vector3D& a_other) const {

	Vector3D newCVector3Times;

	newCVector3Times.m_coordinates[0] = m_coordinates[0] * a_other.m_coordinates[0];
	newCVector3Times.m_coordinates[1] = m_coordinates[1] * a_other.m_coordinates[1];
	newCVector3Times.m_coordinates[2] = m_coordinates[2] * a_other.m_coordinates[2];

	return newCVector3Times;

}

void Vector3D::operator*=(const Vector3D& a_other) {

	m_coordinates[0] *= a_other.m_coordinates[0];
	m_coordinates[1] *= a_other.m_coordinates[1];
	m_coordinates[2] *= a_other.m_coordinates[2];

}

const Vector3D Vector3D::operator/(const Vector3D& a_other) const {

	Vector3D newCVector3Slash;

	newCVector3Slash.m_coordinates[0] = m_coordinates[0] / a_other.m_coordinates[0];
	newCVector3Slash.m_coordinates[1] = m_coordinates[1] / a_other.m_coordinates[1];
	newCVector3Slash.m_coordinates[2] = m_coordinates[2] / a_other.m_coordinates[2];

	return newCVector3Slash;
}

void Vector3D::operator/=(const Vector3D& a_other) {

	m_coordinates[0] /= a_other.m_coordinates[0];
	m_coordinates[1] /= a_other.m_coordinates[1];
	m_coordinates[2] /= a_other.m_coordinates[2];
}

const Vector3D Vector3D::operator/(const float a_other) const {

	Vector3D newCVector3SlashF;

	newCVector3SlashF.m_coordinates[0] = m_coordinates[0] / a_other;
	newCVector3SlashF.m_coordinates[1] = m_coordinates[1] / a_other;
	newCVector3SlashF.m_coordinates[2] = m_coordinates[2] / a_other;

	return newCVector3SlashF;
}

void Vector3D::operator/=(const float a_other) {
	m_coordinates[0] /= a_other;
	m_coordinates[1] /= a_other;
	m_coordinates[2] /= a_other;
}

const Vector3D Vector3D::operator*(const Matrix3x3& a_other) const {

	return Vector3D();

}

const Vector3D Vector3D::operator+(const Vector3D& a_other) const {

	Vector3D newCVector3Add;

	(newCVector3Add.m_coordinates[0] + a_other.m_coordinates[0]);
	(newCVector3Add.m_coordinates[1] + a_other.m_coordinates[1]);
	(newCVector3Add.m_coordinates[2] + a_other.m_coordinates[2]);

	return newCVector3Add;
}

void Vector3D::operator+=(const Vector3D& a_other) {
	m_coordinates[0] += a_other.m_coordinates[0];
	m_coordinates[1] += a_other.m_coordinates[1];
	m_coordinates[2] += a_other.m_coordinates[2];
}

const Vector3D Vector3D::operator-(const Vector3D& a_other) const {

	Vector3D newCVector3Minus;

	newCVector3Minus.m_coordinates[0] = m_coordinates[0] - a_other.m_coordinates[0];
	newCVector3Minus.m_coordinates[1] = m_coordinates[1] - a_other.m_coordinates[1];
	newCVector3Minus.m_coordinates[2] = m_coordinates[2] - a_other.m_coordinates[2];

	return newCVector3Minus;

}

void Vector3D::operator-=(const Vector3D& a_other) {
	m_coordinates[0] -= a_other.m_coordinates[0];
	m_coordinates[1] -= a_other.m_coordinates[1];
	m_coordinates[2] -= a_other.m_coordinates[2];
}

const float Vector3D::magnitude() const {
	return sqrtf(magnitudeSq());

}

const float Vector3D::magnitudeSq() const {
	return (Vector3D::m_coordinates[0] * Vector3D::m_coordinates[0]) * (Vector3D::m_coordinates[1] * Vector3D::m_coordinates[1]) * (Vector3D::m_coordinates[2] * Vector3D::m_coordinates[2]);
}

const float Vector3D::distance(const Vector3D& a_other) const {
	return sqrtf(distanceSq(a_other));
}
const float Vector3D::distanceSq(const Vector3D& a_other) const {
	return (Vector3D::m_coordinates[0] * Vector3D::m_coordinates[0]) - (Vector3D::m_coordinates[1] * Vector3D::m_coordinates[1]) - (Vector3D::m_coordinates[2] * Vector3D::m_coordinates[2]);
}

const float Vector3D::dotProduct(const Vector3D& a_other) const {
	return (m_coordinates[0] * a_other[0]) + (m_coordinates[1] * a_other[1]) + (m_coordinates[2] * a_other[2]);
}

const Vector3D Vector3D::crossProduct(const Vector3D& a_rv3a) const {

	return Vector3D ((m_coordinates[1] * a_rv3a[2]) - (m_coordinates[2] * a_rv3a[1]), 
					(m_coordinates[2] * a_rv3a[0]) - (m_coordinates[0] * a_rv3a[2]), 
					(m_coordinates[0] * a_rv3a[1]) - (m_coordinates[1] * a_rv3a[0]));

}

void Vector3D::normalise() {
	(m_coordinates[0] / magnitude());
	(m_coordinates[1] / magnitude());
	(m_coordinates[2] / magnitude());
}

const Vector3D Vector3D::normalised() const {

	Vector3D newNormalised3DVector = *this;

	return newNormalised3DVector / magnitude();
}
