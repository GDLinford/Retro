#include "Vector2D.h"

#include <cmath>

Vector2D::Vector2D()
{
	m_coordinates[0] = 0.f;
	m_coordinates[1] = 0.f;
}

Vector2D::Vector2D(float a_x, float a_y)
{
	m_coordinates[0] = a_x;
	m_coordinates[1] = a_y;
}

const float Vector2D::operator[](const int a_i) const {
	return m_coordinates[a_i];
}

const Vector2D Vector2D::operator*(const float a_other) const {

	Vector2D newCVectorTimeF;
	
	newCVectorTimeF.m_coordinates[0] = m_coordinates[0] * a_other;
	newCVectorTimeF.m_coordinates[1] = m_coordinates[1] * a_other;
	
	return newCVectorTimeF;

}

void Vector2D::operator*=(const float a_other) {

	m_coordinates[0] *= a_other;
	m_coordinates[1] *= a_other;

}

const Vector2D Vector2D::operator*(const Vector2D& a_other) const {

	Vector2D newCVectorTimes;
	
	newCVectorTimes.m_coordinates[0] = m_coordinates[0] * a_other.m_coordinates[0];
	newCVectorTimes.m_coordinates[1] = m_coordinates[1] * a_other.m_coordinates[1];
	
	return newCVectorTimes;

	
}


void Vector2D::operator*=(const Vector2D& a_other) {
	m_coordinates[0] *= a_other.m_coordinates[0];
	m_coordinates[1] *= a_other.m_coordinates[1];
}

const Vector2D Vector2D::operator/(const Vector2D& a_other) const {

	Vector2D newCVector2Slash;

	newCVector2Slash.m_coordinates[0] / a_other.m_coordinates[0],
	newCVector2Slash.m_coordinates[1] / a_other.m_coordinates[1];

	return newCVector2Slash;
}


void Vector2D::operator/=(const Vector2D& a_other) {
	m_coordinates[0] /= a_other.m_coordinates[0];
	m_coordinates[1] /= a_other.m_coordinates[1];
}

const Vector2D Vector2D::operator/(const float a_other) const {
	Vector2D newCVector2SlashF;

	newCVector2SlashF.m_coordinates[0] = m_coordinates[0] / a_other;
	newCVector2SlashF.m_coordinates[1] = m_coordinates[1] / a_other;

	return newCVector2SlashF;
}

void Vector2D::operator/=(const float a_other) {
	m_coordinates[0] /= a_other;
	m_coordinates[1] /= a_other;

}

const Vector2D Vector2D::operator+(const Vector2D& a_other) const {

	Vector2D newVector2D;

	newVector2D.m_coordinates[0] + a_other.m_coordinates[0],
	newVector2D.m_coordinates[1] + a_other.m_coordinates[1];

	return newVector2D;
}

void Vector2D::operator+=(const Vector2D& a_other) {
	m_coordinates[0] += a_other.m_coordinates[0];
	m_coordinates[1] += a_other.m_coordinates[1];
}

const Vector2D Vector2D::operator-(const Vector2D& a_other) const {
	Vector2D newCVector2Minus;

	newCVector2Minus.m_coordinates[0] - a_other.m_coordinates[0],
	newCVector2Minus.m_coordinates[1] - a_other.m_coordinates[1];

	return newCVector2Minus;
}

void Vector2D::operator-=(const Vector2D& a_other) {
	m_coordinates[0] -= a_other.m_coordinates[0];
	m_coordinates[1] -= a_other.m_coordinates[1];
}

const float Vector2D::magnitude() const {
	return sqrtf(magnitudeSq());
}

const float Vector2D::magnitudeSq() const {
	
	return (Vector2D::m_coordinates[0] * Vector2D::m_coordinates[0]) * (Vector2D::m_coordinates[1] * Vector2D::m_coordinates[1]);
}

const float Vector2D::distance(const Vector2D& a_other) const {

	return sqrtf(distanceSq(a_other));
	
}
const float Vector2D::distanceSq(const Vector2D& a_other) const {
	return (Vector2D::m_coordinates[0] * Vector2D::m_coordinates[0]) - (Vector2D::m_coordinates[1] * Vector2D::m_coordinates[1]);
}

const float Vector2D::dotProduct(const Vector2D& a_other) const {
	
	return (m_coordinates[0] * a_other.m_coordinates[0]) + (m_coordinates[1] * a_other.m_coordinates[1]);
} 

void Vector2D::normalise() {
	(m_coordinates[0] / magnitude());
	(m_coordinates[1] / magnitude());
}

const Vector2D Vector2D::normalised() const 
{
	Vector2D newNormalisedVector = *this;

	return newNormalisedVector / magnitude();

}

