#pragma once
#include "Sample.h"

/// Хранение и моделирование выборки методом дихотомии.
class DichotomySample : public Sample {
public:
	void simulate(const Distribution& distr, int sz, std::mt19937& gen) override;
	/**< См. Sample::simulate. Для моделирования распределения distr используется метод дихотомии. */
};

