#include "Trojkat.h"

double Trojkat::polePow() const {
	double s = (m_s1 + m_s2 + m_s3)/2;
	return sqrt(s*(s-m_s1)*(s-m_s2)*(s-m_s3));
}
