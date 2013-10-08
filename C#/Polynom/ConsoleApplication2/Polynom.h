#pragma once
#include <vector>

class CPolynom
{
private: 
	int m_Degree;
	//typedef double ValueType;
	
	std::vector<double> m_Coefs;

	static CPolynom raw_Add(const CPolynom&, const CPolynom&);
	static CPolynom raw_Sub(const CPolynom&, const CPolynom&);
	static CPolynom raw_Mul(const CPolynom&, const CPolynom&);
	static CPolynom raw_Mul(const CPolynom&, const double&);
	static void raw_Div(const CPolynom&, const CPolynom&, CPolynom&, CPolynom&);

	void Shift(size_t);
	void CheckNulls();
	void PrintNoNewLine();

	static bool IsNull(double a)
	{
		return fabs(a) < 1e-12;
	}

public:
	CPolynom(void);
	CPolynom(double[], int);
	~CPolynom(void);


// ���������
	CPolynom operator+(const CPolynom&) const;
	CPolynom operator-(const CPolynom&) const;
	CPolynom operator*(const CPolynom&) const;
	CPolynom operator*(const double&) const;
	void operator*=(const CPolynom&);
	void operator*=(const double&);
	CPolynom operator/(const CPolynom&) const;
	CPolynom operator%(const CPolynom&) const;
	double& operator[](const size_t);
	double operator[](const size_t) const;

// ��������
	void Divide(const CPolynom&, const CPolynom&, CPolynom&, CPolynom&);
	CPolynom Derivative() const;	// �����������
	double ValueAt(double) const;	// �������� � �����
	int CheckRoot(double) const;	// �������� ����� �� ���������
	bool IsConstant() const;		// ��������?
	void Decomposition() const;

// ���������� ����� ��������
	static CPolynom NOD(const CPolynom&, const CPolynom&);

// ������
	void Print();

// ������?
	bool isEmpty();
};