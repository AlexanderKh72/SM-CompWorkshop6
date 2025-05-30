#pragma once

/// Дискретное распределение.
/**  
* Класс Distribution хранит произвольное дискретное распределение с конечным числом состояний. 
* На вход (в конструкторе или функции Distribution::set) подаётся массив с весами состояний и число состояний. 
* При помощи функции Distribution::get_p(n) можно получить вероятности с котороми случайная величина принимает заданное значение. 
*/
class Distribution
{
public:
	Distribution() : probs(nullptr), nstates(0) {}
	Distribution(const double* weights, int n);
	/**< На вход подаётся массив weights типа double и длины n, в котором находятся веса значений случайной величины. */
	~Distribution() { delete[] probs; }
	double get_p(int k) const
	/** Функция Distribution::get_p(k) возвращает вероятность \f$p_k\f$ того, что случайная величина с данным распределением примет значение k. 
		* Если \f$(w_0, \ldots, w_{n-1})\f$ --- веса, то \f$p_k = w_k / \sum_{i=0}^{n-1} w_i\f$.
		*/
	{
		if (k >= 0 && k < nstates)
			return probs[k];
		return 0;
	}
	void set(const double* weights, int n);
	int getNstates() const { return nstates; }
private: 
	int nstates;
	double* probs;
};

