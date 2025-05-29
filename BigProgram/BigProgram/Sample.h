#pragma once
#include <random>
#include "Distribution.h"

/// Хранения и моделирование выборки.
/** Sample --- виртуальный класс, в котором хранится и моделируется целочисленная выборка. Выборка хранится в сгруппированном виде.
  * Метод моделированния определяется в наследнике.
  */
class Sample {
public:
	Sample() : sample(nullptr), nstates(0) {}
	virtual ~Sample() { delete[] sample; }
	virtual void simulate(const Distribution& distr, int sz, std::mt19937& gen) = 0; 
	/**< Функция Sample::simulate моделирует выборку размера sz с распределением описанным в distr, используя генератор случайных чисел gen. */
	int at(int i) const { if (i >= 0 && i < nstates) return sample[i]; return 0; } 
	/**< Функция Sample::at даёт безопасный доступ к элементам сгруппированной выборки. Sample::at(i) возвращает количество значений в выборке равных i. */
	int size() const;
	/**< Функция Sample::size возвращает размер выборки. */
	int getNstates() const { return nstates; }
	/**< Функция Sample::getNstates() возвращает число возможных состояний: гарантируется, что все значения в выборке лежат в пределах от 0 до Sample::getNstates()-1. */

protected:
	int* sample;
	int nstates;
};
