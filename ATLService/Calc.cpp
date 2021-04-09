// Calc.cpp : Implementation of CCalc

#include "pch.h"
#include "Calc.h"


// CCalc



STDMETHODIMP CCalc::Add(LONG x, LONG y, LONG *z)
{
	*z = x + y;

	return S_OK;
}


STDMETHODIMP CCalc::Div(LONG x, LONG y, LONG *z)
{
	*z = x / y;

	return S_OK;
}
