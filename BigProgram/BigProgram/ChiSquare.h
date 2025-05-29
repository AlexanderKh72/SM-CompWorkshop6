#pragma once
#include "Sample.h"
#include "Distribution.h"

/// Критерий хи-квадрат.
/**
* На вход (в конструкторе или функции ChiSquare::set) подаётся выборка (указатель на Sample) и распределение (объект типа Distribution), на согласие с которым проверяется выборка.
* 
* После задания выборки и распределения вычисляется значение статистики критерия, число степеней свободы и значаение p-value.
* При вычислении происходит группировка состояний, для удовлетворения условиям применимости критерия хи-квадрат, а именно: все эмпирические частоты сгруппированных состояний должны быть не меньше 5.
* 
* Важно: изменение выборки не повлияет на содержимое объекта класса ChiSquare.
*/
class ChiSquare{
public:
	ChiSquare() : emp_freq(nullptr), theor_freq(nullptr), t(0), pvalue(0), df(0), nstates(0) {}
	ChiSquare(Sample* sample, Distribution& distr);
	/**< На вход конструктора ChiSquare::ChiSquare(sample, distr) подаётся указатель sample (типа Sample*) на выборку, а также распределение distr типа Distribution, на согласие с которым проверяется выборка.
	* После, вычисляется статистика критерия, число степеней свободы, и значение p-value.
	*/
	~ChiSquare();
	void set(Sample* sample, Distribution& distr);
	void histogram(CDC* pDC, int W, int H) const;
	double get_pvalue() const { return pvalue; }
	double get_statistic() const { return t; }
	int get_df() const { return df; }

protected:
	void calculate();
	int* emp_freq;
	double* theor_freq;
	double t;
	double pvalue;
	int df;
	int nstates;
};

